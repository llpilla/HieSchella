/** \file stencil4d.C
 *  Author: Abhinav S Bhatele
 *  Date Created: December 28th, 2010
 *
 *  This example is written to be used with periodic measurement-based load
 *  balancers at sync. The load of some chares changes across iterations and
 *  depends on the index of the chare.
 *
 *
 *
 *	      *****************
 *	   *		   *  *
 *   ^	*****************     *
 *   |	*		*     *
 *   |	*		*     *
 *   |	*		*     *
 *   Y	*		*     *
 *   |	*		*     *
 *   |	*		*     *
 *   |	*		*  * 
 *   ~	*****************    Z
 *	<------ X ------> 
 *
 *   X: left, right --> wrap_x
 *   Y: top, bottom --> wrap_y
 *   Z: front, back --> wrap_z
 */

#include "stencil4d.decl.h"
#include "TopoManager.h"

/*readonly*/ CProxy_Main mainProxy;
/*readonly*/ int arrayDimW;
/*readonly*/ int arrayDimX;
/*readonly*/ int arrayDimY;
/*readonly*/ int arrayDimZ;
/*readonly*/ int blockDimW;
/*readonly*/ int blockDimX;
/*readonly*/ int blockDimY;
/*readonly*/ int blockDimZ;

// specify the number of worker chares in each dimension
/*readonly*/ int num_chare_w;
/*readonly*/ int num_chare_x;
/*readonly*/ int num_chare_y;
/*readonly*/ int num_chare_z;

static unsigned long next = 1;

int myrand(int numpes) {
  next = next * 1103515245 + 12345;
  return((unsigned)(next/65536) % numpes);
}

// We want to wrap entries around, and because mod operator % 
// sometimes misbehaves on negative values. -1 maps to the highest value.
#define wrap_w(a)	(((a)+num_chare_w)%num_chare_w)
#define wrap_x(a)	(((a)+num_chare_x)%num_chare_x)
#define wrap_y(a)	(((a)+num_chare_y)%num_chare_y)
#define wrap_z(a)	(((a)+num_chare_z)%num_chare_z)

#define index(a,b,c,d)	((a)+(b)*(blockDimW+2)+(c)*(blockDimW+2)*(blockDimX+2) + (d)*(blockDimW+2)*(blockDimX+2)*(blockDimY+2))

#define LBPERIOD	10
#define CHANGELOAD	100
#define LEFT		1
#define RIGHT		2
#define TOP		3
#define BOTTOM		4
#define FRONT		5
#define BACK		6
#define FORWARD 7
#define BACKWARD 8
#define DIVIDEBY9      	0.11111111111111111111

/** \class Main
 *
 */
class Main : public CBase_Main {
  public:
    CProxy_Stencil array;
    int numChares;
    int currentStep;
    
    double gStarttime;
    int  MAX_ITER;

    Main(CkArgMsg* m) {
      if ( (m->argc != 4) && (m->argc != 10) ) {
        CkPrintf("%s [array_size] [block_size] MAXITER\n", m->argv[0]);
        CkPrintf("OR %s [array_size_W] [array_size_X] [array_size_Y] [array_size_Z] [block_size_W] [block_size_X] [block_size_Y] [block_size_Z]MAXITER \n", m->argv[0]);
        CkAbort("Abort");
      }

      // store the main proxy
      mainProxy = thisProxy;

      currentStep = 0;

      if(m->argc == 4) {
        arrayDimW = arrayDimX = arrayDimY = arrayDimZ = atoi(m->argv[1]);
        blockDimW = blockDimX = blockDimY = blockDimZ = atoi(m->argv[2]); 
        MAX_ITER = atoi(m->argv[3]);
      }
      else if (m->argc == 10) {
        arrayDimW = atoi(m->argv[1]);
        arrayDimX = atoi(m->argv[2]);
        arrayDimY = atoi(m->argv[3]);
        arrayDimZ = atoi(m->argv[4]);
        blockDimW = atoi(m->argv[5]); 
        blockDimX = atoi(m->argv[6]); 
        blockDimY = atoi(m->argv[7]); 
        blockDimZ = atoi(m->argv[8]);
        MAX_ITER = atoi(m->argv[9]);
      }

      if (arrayDimW < blockDimW || arrayDimW % blockDimW != 0)
        CkAbort("array_size_W % block_size_W != 0!");
      if (arrayDimX < blockDimX || arrayDimX % blockDimX != 0)
        CkAbort("array_size_X % block_size_X != 0!");
      if (arrayDimY < blockDimY || arrayDimY % blockDimY != 0)
        CkAbort("array_size_Y % block_size_Y != 0!");
      if (arrayDimZ < blockDimZ || arrayDimZ % blockDimZ != 0)
        CkAbort("array_size_Z % block_size_Z != 0!");

      num_chare_w = arrayDimW / blockDimW;
      num_chare_x = arrayDimX / blockDimX;
      num_chare_y = arrayDimY / blockDimY;
      num_chare_z = arrayDimZ / blockDimZ;

      numChares = num_chare_w * num_chare_x * num_chare_y * num_chare_z;

      // print info
      CkPrintf("\nSTENCIL COMPUTATION WITH BARRIERS\n");
      CkPrintf("Running Stencil on %d processors with (%d, %d, %d, %d) chares\n", CkNumPes(), num_chare_w, num_chare_x, num_chare_y, num_chare_z);
      CkPrintf("Array Dimensions: %d %d %d %d\n", arrayDimW, arrayDimX, arrayDimY, arrayDimZ);
      CkPrintf("Block Dimensions: %d %d %d %d\n", blockDimW, blockDimX, blockDimY, blockDimZ);

      array = CProxy_Stencil::ckNew();
      // Create new array of worker chares
      for (int z = 0; z < num_chare_z; z++) {
        for (int y = 0; y < num_chare_y; y++) {
          for (int x = 0; x < num_chare_x; x++) {
            for (int w = 0; w < num_chare_w; w++) {
              array(w, x, y, z).insert();
            }
          }
        }
      }  
      array.doneInserting();

      // Create new array of worker chares
      // array = CProxy_Stencil::ckNew(num_chare_x, num_chare_y, num_chare_z);

      //Start the computation
      beginIteration();
    }

    void beginIteration() {
      currentStep++;
      if (currentStep == MAX_ITER) {
        CkPrintf("Program finished!\n");
        terminate();
        return;
      }

      gStarttime = CmiWallTimer();
      if (currentStep != 0 && (currentStep % LBPERIOD == 0)) {
        array.pauseForLB();
        return;
      }
      
      array.doStep();
    }

    void nextStep(CkReductionMsg *msg) {
      double maxTime = *((double *)msg->getData());
      double wholeStepTime = CmiWallTimer() - gStarttime;
      delete msg;
      CkPrintf("Iteration[%d] time maxTime %lf whole time %lf\n",
          currentStep, maxTime, wholeStepTime);
      beginIteration();
    }

    void terminate() {
      CkExit();
    }
};

/** \class Stencil
 *
 */

class Stencil: public CBase_Stencil {
  Stencil_SDAG_CODE

  public:
    int iterations;
    int imsg;

    double startTime;
    double endTime;

    double *temperature;
    double *new_temperature;

    double work;

    // Constructor, initialize values
    Stencil() {
      __sdag_init();
      usesAtSync = CmiTrue;
      startTime = CmiWallTimer();

      int i, j, k, l;
      // allocate a three dimensional array
      temperature = new double[(blockDimW+2) * (blockDimX+2) * (blockDimY+2) * (blockDimZ+2)];
      new_temperature = new double[(blockDimW+2) * (blockDimX+2) * (blockDimY+2) * (blockDimZ+2)];

      for(l=0; l<blockDimZ+2; ++l)
      	for(k=0; k<blockDimY+2; ++k)
          for(j=0; j<blockDimX+2; ++j)
            for(i=0; i<blockDimW+2; ++i)
              temperature[index(i, j, k, l)] = 0.0;

      iterations = 0;
      imsg = 0;
      constrainBC();
      int index = thisIndex.w + thisIndex.x*num_chare_w + thisIndex.y*num_chare_w*num_chare_x + thisIndex.z*num_chare_w*num_chare_x*num_chare_y;
      srand(index);
      work = rand() % 5 + 1;
    }

    void pup(PUP::er &p)
    {
      CBase_Stencil::pup(p);
      __sdag_pup(p);
      p|iterations;
      p|imsg;
      p|startTime;
      p|endTime;
      p|work;

      size_t size = (blockDimW+2) * (blockDimX+2) * (blockDimY+2) * (blockDimZ+2);
      if (p.isUnpacking()) {
        temperature = new double[size];
        new_temperature = new double[size];
      }
      p(temperature, size);
      p(new_temperature, size);
    }

    Stencil(CkMigrateMessage* m) { __sdag_init(); }

    ~Stencil() { 
      delete [] temperature; 
      delete [] new_temperature; 
    }

    // Send ghost faces to the six neighbors
    void begin_iteration(void) {
      iterations++;
      startTime = CmiWallTimer();
    
      // Copy different 3D cubes into messages
      double *GhostXYZ1 =  new double[blockDimX*blockDimY*blockDimZ];
      double *GhostXYZ2 =  new double[blockDimX*blockDimY*blockDimZ];
      double *GhostWYZ1 =  new double[blockDimW*blockDimY*blockDimZ];
      double *GhostWYZ2 =  new double[blockDimW*blockDimY*blockDimZ];
      double *GhostWXZ1 =  new double[blockDimW*blockDimX*blockDimZ];
      double *GhostWXZ2 =  new double[blockDimW*blockDimX*blockDimZ];
      double *GhostWXY1 =  new double[blockDimW*blockDimX*blockDimY];
      double *GhostWXY2 =  new double[blockDimW*blockDimX*blockDimY];

      for(int l=0; l<blockDimZ; ++l)
        for(int k=0; k<blockDimY; ++k)
          for(int j=0; j<blockDimX; ++j) {
            GhostXYZ1[l*blockDimY*blockDimX + k*blockDimX+j] = temperature[index(1, j+1, k+1, l+1)];
            GhostXYZ2[l*blockDimY*blockDimX + k*blockDimX+j] = temperature[index(blockDimW, j+1, k+1, l+1)];
        }

      for(int l=0; l<blockDimZ; ++l)
        for(int k=0; k<blockDimY; ++k)
          for(int i=0; i<blockDimW; ++i) {
            GhostWYZ1[l*blockDimY*blockDimW+k*blockDimW+i] = temperature[index(i+1, 1, k+1, l+1)];
            GhostWYZ2[l*blockDimY*blockDimW+k*blockDimW+i] = temperature[index(i+1, blockDimX, k+1, l+1)];
        }

      for(int l=0; l<blockDimZ; ++l)
        for(int j=0; j<blockDimX; ++j)
          for(int i=0; i<blockDimW; ++i) {
            GhostWXZ1[l*blockDimX*blockDimW+j*blockDimW+i] = temperature[index(i+1, j+1, 1, l+1)];
            GhostWXZ2[l*blockDimX*blockDimW+j*blockDimW+i] = temperature[index(i+1, j+1, blockDimY, l+1)];
        }

      for(int k=0; k<blockDimY; ++k)
        for(int j=0; j<blockDimX; ++j)
          for(int i=0; i<blockDimW; ++i) {
            GhostWXY1[k*blockDimX*blockDimW+j*blockDimW+i] = temperature[index(i+1, j+1, k+1, 1)];
            GhostWXY2[k*blockDimX*blockDimW+j*blockDimW+i] = temperature[index(i+1, j+1, k+1, blockDimZ)];
        }

      // Send my XYZ left
      thisProxy(wrap_w(thisIndex.w-1), thisIndex.x, thisIndex.y, thisIndex.z)
        .receiveGhosts(iterations, RIGHT, blockDimX, blockDimY, blockDimZ, GhostXYZ1);

      // Send my XYZ right
      thisProxy(wrap_w(thisIndex.w+1), thisIndex.x, thisIndex.y, thisIndex.z)
        .receiveGhosts(iterations, LEFT, blockDimX, blockDimY, blockDimZ, GhostXYZ2);

      // Send my WYZ bottom
      thisProxy(thisIndex.w, wrap_x(thisIndex.x-1), thisIndex.y, thisIndex.z)
        .receiveGhosts(iterations, TOP, blockDimW, blockDimY, blockDimZ, GhostWYZ1);

      // Send my WYZ top
      thisProxy(thisIndex.w, wrap_x(thisIndex.x+1), thisIndex.y, thisIndex.z)
        .receiveGhosts(iterations, BOTTOM, blockDimW, blockDimY, blockDimZ, GhostWYZ2);

      // Send my WXZ front
      thisProxy(thisIndex.w, thisIndex.x, wrap_y(thisIndex.y-1), thisIndex.z)
        .receiveGhosts(iterations, BACK, blockDimW, blockDimX, blockDimZ, GhostWXZ1);

      // Send my WXZ back
      thisProxy(thisIndex.w, thisIndex.x, wrap_y(thisIndex.y+1), thisIndex.z)
        .receiveGhosts(iterations, FRONT, blockDimW, blockDimX, blockDimZ, GhostWXZ2);

      // Send my WXY forward
      thisProxy(thisIndex.w, thisIndex.x, thisIndex.y, wrap_z(thisIndex.z-1))
        .receiveGhosts(iterations, BACKWARD, blockDimW, blockDimY, blockDimZ, GhostWXY1);

      // Send my WXY backward
      thisProxy(thisIndex.w, thisIndex.x, thisIndex.y, wrap_z(thisIndex.z+1))
        .receiveGhosts(iterations, FORWARD, blockDimW, blockDimY, blockDimZ, GhostWXY2);

      /*// Send my right face
      thisProxy(wrap_x(thisIndex.x+1), thisIndex.y, thisIndex.z)
        .receiveGhosts(iterations, LEFT, blockDimY, blockDimZ, rightGhost);
      // Send my bottom face
      thisProxy(thisIndex.x, wrap_y(thisIndex.y-1), thisIndex.z)
        .receiveGhosts(iterations, TOP, blockDimX, blockDimZ, bottomGhost);
      // Send my top face
      thisProxy(thisIndex.x, wrap_y(thisIndex.y+1), thisIndex.z)
        .receiveGhosts(iterations, BOTTOM, blockDimX, blockDimZ, topGhost);
      // Send my front face
      thisProxy(thisIndex.x, thisIndex.y, wrap_z(thisIndex.z-1))
        .receiveGhosts(iterations, BACK, blockDimX, blockDimY, frontGhost);
      // Send my back face
      thisProxy(thisIndex.x, thisIndex.y, wrap_z(thisIndex.z+1))
        .receiveGhosts(iterations, FRONT, blockDimX, blockDimY, backGhost);
      */

      delete[] GhostWYZ1;
      delete[] GhostWYZ2;
      delete[] GhostWXY1;
      delete[] GhostWXY2;
      delete[] GhostWXZ2;
      delete[] GhostWXZ1;
      delete[] GhostXYZ1;
      delete[] GhostXYZ2;
    }

    void processGhosts(int dir, int length, int width, int height, double gh[]) {
//      CkPrintf("Process ghost at (%d, %d, %d, %d) dir: %d\n",thisIndex.w,
//      thisIndex.x, thisIndex.y, thisIndex.z, dir);
      switch(dir) {
        case LEFT:
          for(int l=0; l<width; ++l)
            for(int k=0; k<height; ++k) 
              for(int j=0; j<length; ++j) {
                temperature[index(0, j+1, k+1, l+1)] = gh[l*height*length+k*length+j];
              }
          break;
        case RIGHT:
          for(int l=0; l<width; ++l)
            for(int k=0; k<height; ++k) 
              for(int j=0; j<length; ++j) {
                temperature[index(blockDimW+1, j+1, k+1, l+1)] = gh[l*height*length+k*length+j];
              }
          break;
        case BOTTOM:

          for(int l=0; l<width; ++l)
            for(int k=0; k<height; ++k) 
              for(int i=0; i<length; ++i) {
                temperature[index(i, 0, k+1, l+1)] = gh[l*height*length+k*length+i];
              }
          break;
        case TOP:

          for(int l=0; l<width; ++l)
            for(int k=0; k<height; ++k) 
              for(int i=0; i<length; ++i) {
                temperature[index(i, blockDimX+1, k+1, l+1)] = gh[l*height*length+k*length+i];
              }
          break;
        case FRONT:

          for(int l=0; l<width; ++l)
            for(int j=0; j<height; ++j) 
              for(int i=0; i<length; ++i) {
                temperature[index(i+1, j+1, 0, l+1)] = gh[l*height*length+j*length+i];
              }
          break;
        case BACK:

          for(int l=0; l<width; ++l)
            for(int j=0; j<height; ++j) 
              for(int i=0; i<length; ++i) {
                temperature[index(i+1, j+1, blockDimY+1, l+1)] = gh[l*height*length+j*length+i];
              }
          break;
        case FORWARD:
          for(int k=0; k<width; ++k)
            for(int j=0; j<height; ++j) 
              for(int i=0; i<length; ++i) {
                temperature[index(i+1, j+1, k+1, 0)] = gh[k*height*length+j*length+i];
              }
          break;

        case BACKWARD:

          for(int k=0; k<width; ++k)
            for(int j=0; j<height; ++j) 
              for(int i=0; i<length; ++i) {
                temperature[index(i+1, j+1, k+1, blockDimZ+1)] = gh[k*height*length+j*length+i];
              }
          break;
        default:
          CkAbort("ERROR\n");
      }
    }


    void check_and_compute() {
      compute_kernel();

      // calculate error
      // not being done right now since we are doing a fixed no. of iterations

      double *tmp;
      tmp = temperature;
      temperature = new_temperature;
      new_temperature = tmp;

      constrainBC();

      endTime = CmiWallTimer();
      double iterationTime = endTime - startTime;
    //  if(thisIndex.x == 0 && thisIndex.y == 0 && thisIndex.z == 0) {
    //    CkPrintf("[%d:%d] Time per iteration: %f %f\n",
    //        (thisIndex.x*thisIndex.y*thisIndex.z), iterations, (endTime - startTime), endTime);
    //  }
      contribute(sizeof(double), &iterationTime, CkReduction::max_double,
          CkCallback(CkIndex_Main::nextStep(NULL), mainProxy));

    //  if(iterations == MAX_ITER)
    //    contribute(0, 0, CkReduction::concat, CkCallback(CkIndex_Main::report(), mainProxy));
    //  else {
    //    startTime = CmiWallTimer();
    //    if(iterations % LBPERIOD == 0)
    //    {
    //      // auto tune the LBPeriod to half as long as it takes to run the iters between LB steps
    //      LBSetPeriod((endTime-startTime)*LBPERIOD/2.0);
    //      AtSync();
    //    }
    //    else
    //      contribute(0, 0, CkReduction::concat, CkCallback(CkIndex_Stencil::doStep(), thisProxy));
    //  }
    }

    // Check to see if we have received all neighbor values yet
    // If all neighbor values have been received, we update our values and proceed
    void compute_kernel() {
      int itno = (int)ceil((double)iterations/(double)CHANGELOAD) * 5;
      int index = thisIndex.w + thisIndex.x*num_chare_w + thisIndex.y*num_chare_w*num_chare_x+thisIndex.z*num_chare_w*num_chare_x*num_chare_y;
      int numChares = num_chare_w * num_chare_x * num_chare_y * num_chare_z;
     // int work = 5.0;

     // if(index >= numChares*0.2 && index <=numChares*0.8) {
     //   //work = (((double) work * (double)index)/(double)numChares) + (double)itno;
     //   work = (((double) work * (double)index)/(double)numChares);
     // // CkPrintf("[%d][%d][%d] %d %d %f\n", thisIndex.x, thisIndex.y, thisIndex.z, index, itno, work);
     // } else
     //   work = 1.0;
     // work = 1.0;
       
#pragma unroll
      for(int w=0; w<work; w++) {
        for(int l=1; l<blockDimZ+1; ++l)
        for(int k=1; k<blockDimY+1; ++k)
          for(int j=1; j<blockDimX+1; ++j)
            for(int i=1; i<blockDimW+1; ++i) {
              // update my value based on the surrounding values
              new_temperature[index(i, j, k, l)] = (temperature[index(i-1, j, k, l)]
                  + temperature[index(i, j, k, l)])
                  +  temperature[index(i+1, j, k, l)]
                  +  temperature[index(i, j-1, k, l)]
                  +  temperature[index(i, j+1, k, l)]
                  +  temperature[index(i, j, k-1, l)]
                  +  temperature[index(i, j, k+1, l)]
                  +  temperature[index(i, j, k, l-1)]
                  + temperature[index(i, j, k, l+1)]
                *  DIVIDEBY9;
            } // end for
      }
    }

    // Enforce some boundary conditions
    void constrainBC() {
      // Heat left, top and front faces of each chare's block
      for(int l=1; l<blockDimZ+1; ++l)
        for(int k=1; k<blockDimY+1; ++k)
          for(int i=1; i<blockDimW+1; ++i)
            temperature[index(i, 1, k, l)] = 255.0;
      for(int l=1; l<blockDimZ+1; ++l)
        for(int k=1; k<blockDimY+1; ++k)
          for(int j=1; j<blockDimX+1; ++j)
            temperature[index(1, j, k, l)] = 255.0;
      for(int l=1; l<blockDimZ+1; ++l)
        for(int j=1; j<blockDimX+1; ++j)
          for(int i=1; i<blockDimW+1; ++i)
            temperature[index(i, j, 1, l)] = 255.0;
      for(int k=1; k<blockDimY+1; ++k)
        for(int j=1; j<blockDimX+1; ++j)
          for(int i=1; i<blockDimW+1; ++i)
            temperature[index(i, j, k, 1)] = 255.0;
    }

    void pauseForLB() {
      AtSync();
    }

    void ResumeFromSync() {
      CkCallback cb(CkIndex_Main::beginIteration(), mainProxy);
      contribute(0, NULL, CkReduction::sum_int, cb);
    }
};

#include "stencil4d.def.h"
