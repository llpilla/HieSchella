#include "time.h"
#include "defs.h"
#include "leanmd.decl.h"
#include "Cell.h"
#include "ckmulticast.h"

extern /* readonly */ CProxy_Main mainProxy;
extern /* readonly */ CProxy_Cell cellArray;
extern /* readonly */ CProxy_Compute computeArray;
extern /* readonly */ CkGroupID mCastGrpID;

extern /* readonly */ int cellArrayDimX;
extern /* readonly */ int cellArrayDimY;
extern /* readonly */ int cellArrayDimZ;
extern /* readonly */ int finalStepCount; 

//default constructor
Cell::Cell() {
  __sdag_init();
  int i;
  inbrs = NUM_NEIGHBORS;
  //total number of atoms in the system
  int numParts = PARTICLES_PER_CELL * cellArrayDimX * cellArrayDimY * cellArrayDimZ;
  //load balancing to be called when AtSync is called
  usesAtSync = CmiTrue;

  myNumParts = PARTICLES_PER_CELL;
  // starting random generator
  srand48(25763);

  // Particle initialization
  for(i=0; i < myNumParts; i++) {
    particles.push_back(Particle());
    particles[i].mass = HYDROGEN_MASS;

    //give random values for position and velocity
    particles[i].pos.x = drand48() * CELL_SIZE_X + thisIndex.x * CELL_SIZE_X;
    particles[i].pos.y = drand48() * CELL_SIZE_Y + thisIndex.y * CELL_SIZE_Y;
    particles[i].pos.z = drand48() * CELL_SIZE_Z + thisIndex.z * CELL_SIZE_Z;
    particles[i].vel.x = (drand48() - 0.5) * .2 * MAX_VELOCITY;
    particles[i].vel.y = (drand48() - 0.5) * .2 * MAX_VELOCITY;
    particles[i].vel.z = (drand48() - 0.5) * .2 * MAX_VELOCITY;
  }

  stepCount = 0;
  updateCount = 0;
  stepTime = 0;
}

//constructor for chare object migration
Cell::Cell(CkMigrateMessage *msg): CBase_Cell(msg) {
  __sdag_init();
  usesAtSync = CmiTrue;
  delete msg;
}  

Cell::~Cell() {}

//function to create my computes
void Cell::createComputes() {
  int num;  

  int x = thisIndex.x;
  int y = thisIndex.y;
  int z = thisIndex.z;
  int px1, py1, pz1, dx, dy, dz, px2, py2, pz2;

  // For Round Robin insertion
  int numPes = CkNumPes();
  int currPe = CkMyPe();

  computesList = new int*[inbrs];
  for (int i =0; i < inbrs; i++){
    computesList[i] = new int[6];
  }

  /*  The computes X are inserted by a given cell:
   *
   *	^  X  X  X
   *	|  0  X  X
   *	y  0  0  0
   *	   x ---->
   */

  for (num=0; num<inbrs; num++) {
    dx = num / (NBRS_Y * NBRS_Z)            - NBRS_X/2;
    dy = (num % (NBRS_Y * NBRS_Z)) / NBRS_Z   - NBRS_Y/2;
    dz = num % NBRS_Z                       - NBRS_Z/2;

    if (num >= inbrs/2){
      px1 = x + 2;
      px2 = x+dx+2;
      py1 = y + 2;
      py2 = y+dy+2;
      pz1 = z + 2;
      pz2 = z+dz+2;
      computeArray(px1, py1, pz1, px2, py2, pz2).insert((++currPe)%numPes);
      computesList[num][0] = px1; computesList[num][1] = py1; computesList[num][2] = pz1; 
      computesList[num][3] = px2; computesList[num][4] = py2; computesList[num][5] = pz2;
    }
    else {
      // these computes will be created by pairing celles
      px2 = WRAP_X(x+dx);
      py2 = WRAP_Y(y+dy);
      pz2 = WRAP_Z(z+dz);
      px1 = x;
      py1 = y;
      pz1 = z; 
      px1 = px2 - dx + 2;
      px2 = px2+2;
      py1 = py2 - dy + 2;
      py2 = py2+2;
      pz1 = pz2 - dz + 2;
      pz2 = pz2+2;
      computesList[num][0] = px2; computesList[num][1] = py2; computesList[num][2] = pz2; 
      computesList[num][3] = px1; computesList[num][4] = py1; computesList[num][5] = pz1;
    }
  } // end of for loop
  contribute(sizeof(int),&num,CkReduction::max_int,CkCallback(CkReductionTarget(Main,computesCreated),mainProxy));
}

//call multicast section creation
void Cell::createSection() {
  int num;
  localCreateSection();
  contribute(sizeof(int),&num,CkReduction::max_int,CkCallback(CkReductionTarget(Main,sectionsCreated),mainProxy));
}

//function to create the multicast section of computes
void Cell::localCreateSection() {
  CkVec<CkArrayIndex6D> elems;
  //create a vector list of my computes
  for (int num=0; num<inbrs; num++)
    elems.push_back(CkArrayIndex6D(computesList[num][0], computesList[num][1], computesList[num][2], computesList[num][3], computesList[num][4], computesList[num][5]));

  CkArrayID computeArrayID = computeArray.ckGetArrayID();
  //knit the computes into a section
  mCastSecProxy = CProxySection_Compute::ckNew(computeArrayID, elems.getVec(), elems.size()); 

  //delegate the communication responsibility for this section to multicast library
  CkMulticastMgr *mCastGrp = CProxy_CkMulticastMgr(mCastGrpID).ckLocalBranch();
  mCastSecProxy.ckSectionDelegate(mCastGrp);
  mCastGrp->setReductionClient(mCastSecProxy, new CkCallback(CkReductionTarget(Cell,reduceForces), thisProxy(thisIndex.x, thisIndex.y, thisIndex.z)));
}

// Function to start interaction among particles in neighboring cells as well as its own particles
void Cell::sendPositions() {
  int len = particles.length();

  //create the particle and control message to be sent to computes
  ParticleDataMsg* msg = new (len) ParticleDataMsg;
  msg->x = thisIndex.x;
  msg->y = thisIndex.y;
  msg->z = thisIndex.z;
  msg->lengthAll = len;

  for (int i = 0; i < len; i++)
    msg->part[i] = particles[i].pos;

  mCastSecProxy.calculateForces(msg);
}

//send the atoms that have moved beyond my cell to neighbors
void Cell::migrateParticles(){
  int i, x, y, z, x1, y1, z1;
  CkVec<Particle> *outgoing = new CkVec<Particle>[inbrs];

  // sending particles to neighboring cells
  x = thisIndex.x;
  y = thisIndex.y;
  z = thisIndex.z;

  for(i=0; i<particles.length(); i++) {
    migrateToCell(particles[i], x1, y1, z1);
    if(x1 !=0 || y1!=0 || z1 !=0) {
      outgoing[(x1+1)*NBRS_Y*NBRS_Z + (y1+1)*NBRS_Z + (z1+1)].push_back(wrapAround(particles[i]));
      particles.remove(i);
    }
  }

  for(int num=0; num<inbrs; num++) {
    x1 = num / (NBRS_Y * NBRS_Z)            - NBRS_X/2;
    y1 = (num % (NBRS_Y * NBRS_Z)) / NBRS_Z - NBRS_Y/2;
    z1 = num % NBRS_Z                       - NBRS_Z/2;

    cellArray(WRAP_X(x+x1), WRAP_Y(y+y1), WRAP_Z(z+z1)).receiveParticles(outgoing[num]);
  }

  delete [] outgoing;
}

//check if the particle is to be moved
void Cell::migrateToCell(Particle p, int &px, int &py, int &pz) {
  // currently this is assuming that particles are
  // migrating only to the immediate neighbors
  int x = thisIndex.x * CELL_SIZE_X + CELL_ORIGIN_X;
  int y = thisIndex.y * CELL_SIZE_Y + CELL_ORIGIN_Y;
  int z = thisIndex.z * CELL_SIZE_Z + CELL_ORIGIN_Z;

  if (p.pos.x < x) px = -1;
  else if (p.pos.x > x+CELL_SIZE_X) px = 1;
  else px = 0;

  if (p.pos.y < y) py = -1;
  else if (p.pos.y > y+CELL_SIZE_Y) py = 1;
  else py = 0;

  if (p.pos.z < z) pz = -1;
  else if (p.pos.z > z+CELL_SIZE_Z) pz = 1;
  else pz = 0;
}

//call nextStep if load balancing is done
void Cell::ResumeFromSync(){
  cellArray(thisIndex.x,thisIndex.y,thisIndex.z).resumeAfterLB(1);
}

// Function to update properties (i.e. acceleration, velocity and position) in particles
void Cell::updateProperties(vec3 *forces, int lengthUp) {
  int i;
  double energy = 0;
  double powTen, powFteen, realTimeDelta, invMassParticle;
  powTen = pow(10.0, -10);
  powFteen = pow(10.0, -15);
  realTimeDelta = DEFAULT_DELTA * powFteen;
  for(i = 0; i < particles.length(); i++) {
    //calculate energy only in begining and end
    if(stepCount == 0 || stepCount == (finalStepCount - 1)) 
      energy += (0.5 * particles[i].mass * dot(particles[i].vel, particles[i].vel));

    // applying kinetic equations
    invMassParticle = 1 / particles[i].mass;
    particles[i].acc = forces[i] * invMassParticle;
    particles[i].vel += particles[i].acc * realTimeDelta;

    limitVelocity(particles[i]);

    particles[i].pos += particles[i].vel * realTimeDelta;
  }
  //reduction on energy only in begining and end
  if(stepCount == 0 || stepCount == (finalStepCount - 1)) 
    contribute(sizeof(double),&energy,CkReduction::sum_double,CkCallback(CkReductionTarget(Main,energySumP),mainProxy));
}

void Cell::limitVelocity(Particle &p) {
  if( fabs( p.vel.x ) > MAX_VELOCITY ) {
    if( p.vel.x < 0.0 )
      p.vel.x = -MAX_VELOCITY;
    else
      p.vel.x = MAX_VELOCITY;
  }

  if( fabs(p.vel.y) > MAX_VELOCITY ) {
    if( p.vel.y < 0.0 )
      p.vel.y = -MAX_VELOCITY;
    else
      p.vel.y = MAX_VELOCITY;
  }

  if( fabs(p.vel.z) > MAX_VELOCITY ) {
    if( p.vel.z < 0.0 )
      p.vel.z = -MAX_VELOCITY;
    else
      p.vel.z = MAX_VELOCITY;
  }
}

Particle& Cell::wrapAround(Particle &p) {
  if(p.pos.x < CELL_ORIGIN_X) p.pos.x += CELL_SIZE_X*cellArrayDimX;
  if(p.pos.y < CELL_ORIGIN_Y) p.pos.y += CELL_SIZE_Y*cellArrayDimY;
  if(p.pos.z < CELL_ORIGIN_Z) p.pos.z += CELL_SIZE_Z*cellArrayDimZ;
  if(p.pos.x > CELL_ORIGIN_X + CELL_SIZE_X*cellArrayDimX) p.pos.x -= CELL_SIZE_X*cellArrayDimX;
  if(p.pos.y > CELL_ORIGIN_Y + CELL_SIZE_Y*cellArrayDimY) p.pos.y -= CELL_SIZE_Y*cellArrayDimY;
  if(p.pos.z > CELL_ORIGIN_Z + CELL_SIZE_Z*cellArrayDimZ) p.pos.z -= CELL_SIZE_Z*cellArrayDimZ;

  return p;
}

//pack important data when I move
void Cell::pup(PUP::er &p) {
  CBase_Cell::pup(p);
  __sdag_pup(p);
  p | particles;
  p | stepCount;
  p | myNumParts;
  p | updateCount;
  p | inbrs;
  p | stepTime;

  if (p.isUnpacking()){
    computesList = new int*[inbrs];
    for (int i = 0; i < inbrs; i++){
      computesList[i] = new int[6];
    }
  }

  for (int i = 0; i < inbrs; i++){
    PUParray(p, computesList[i], 6);
  }

  p | mCastSecProxy;
  //adjust the multicast tree to give best performance after moving
  if (p.isUnpacking()){
    CkMulticastMgr *mg = CProxy_CkMulticastMgr(mCastGrpID).ckLocalBranch();
    mg->resetSection(mCastSecProxy);
    mg->setReductionClient(mCastSecProxy, new CkCallback(CkReductionTarget(Cell,reduceForces), thisProxy(thisIndex.x, thisIndex.y, thisIndex.z)));
  }
}
