#include "time.h"
#include "ckmulticast.h"

#include "defs.h"
#include "leanmd.decl.h"
#include "Main.h"
#include "Cell.h"
#include "Compute.h"

/* readonly */ CProxy_Main mainProxy;
/* readonly */ CProxy_Cell cellArray;
/* readonly */ CProxy_Compute computeArray;
/* readonly */ CkGroupID mCastGrpID;

/* readonly */ int cellArrayDimX;
/* readonly */ int cellArrayDimY;
/* readonly */ int cellArrayDimZ;
/* readonly */ int finalStepCount; 
/* readonly */ int firstLdbStep; 
/* readonly */ int ldbPeriod; 

// Entry point of Charm++ application
Main::Main(CkArgMsg* m) {
   __sdag_init();
  CkPrintf("\nLENNARD JONES MOLECULAR DYNAMICS START UP ...\n");

  //set variable values to a default set
  cellArrayDimX = CELLARRAY_DIM_X;
  cellArrayDimY = CELLARRAY_DIM_Y;
  cellArrayDimZ = CELLARRAY_DIM_Z;
  finalStepCount = DEFAULT_FINALSTEPCOUNT;
  firstLdbStep = DEFAULT_FIRST_LDB;
  ldbPeriod = DEFAULT_LDB_PERIOD;

  mainProxy = thisProxy;
  energy = prevEnergy = 0;
  testFailed = 0;

  //branch factor for spanning tree of multicast
  int bFactor = 4;
  //creating the multicast spanning tree
  mCastGrpID = CProxy_CkMulticastMgr::ckNew(bFactor);

  int numPes = CkNumPes();
  int currPe = -1, pe;
  int cur_arg = 1;

  CkPrintf("\nInput Parameters...\n");

  //read user parameters
  //number of celles/cells in each dimension
  if (m->argc > cur_arg) {
    cellArrayDimX=atoi(m->argv[cur_arg++]);
    cellArrayDimY=atoi(m->argv[cur_arg++]);
    cellArrayDimZ=atoi(m->argv[cur_arg++]);
    CkPrintf("Cell Array Dimension X:%d Y:%d Z:%d of size %d %d %d\n",cellArrayDimX,cellArrayDimY,cellArrayDimZ,CELL_SIZE_X,CELL_SIZE_Y,CELL_SIZE_Z);
  }

  //number of steps in simulation
  if (m->argc > cur_arg) {
    finalStepCount=atoi(m->argv[cur_arg++]);
    CkPrintf("Final Step Count:%d\n",finalStepCount);
  }

  //step after which load balancing starts
  if (m->argc > cur_arg) {
    firstLdbStep=atoi(m->argv[cur_arg++]);
    CkPrintf("First LB Step:%d\n",firstLdbStep);
  }

  //periodicity of load balancing
  if (m->argc > cur_arg) {
    ldbPeriod=atoi(m->argv[cur_arg++]);
    CkPrintf("LB Period:%d\n",ldbPeriod);
  }

  //initializing the 3D cell array
  cellArray = CProxy_Cell::ckNew();
  for (int x=0; x<cellArrayDimX; x++)
    for (int y=0; y<cellArrayDimY; y++)
      for (int z=0; z<cellArrayDimZ; z++) {
        pe = (++currPe) % numPes;
        cellArray(x, y, z).insert(pe);
      }
  cellArray.doneInserting();

  CkPrintf("\nCells: %d X %d X %d .... created\n", cellArrayDimX, cellArrayDimY, cellArrayDimZ);

  //initializing the 6D compute array
  computeArray = CProxy_Compute::ckNew();
  for (int x=0; x<cellArrayDimX; x++)
    for (int y=0; y<cellArrayDimY; y++)
      for (int z=0; z<cellArrayDimZ; z++)
        cellArray(x, y, z).createComputes();

  printf("reaches here\n");
  thisProxy.run();
  delete m;
}

//constructor for chare object migration
Main::Main(CkMigrateMessage* msg): CBase_Main(msg) { 
  __sdag_init();  
}

//pup routine incase the main chare moves, pack important information
void Main::pup(PUP::er &p) {
  CBase_Main::pup(p);
   __sdag_pup(p);
  p|energy;
  p|prevEnergy;
  p|testFailed;
}

#include "leanmd.def.h"
