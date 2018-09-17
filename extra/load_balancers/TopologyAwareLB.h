/*****************************************************************************
 * $Source$
 * $Author$ Laércio Pilla
 * $Date$ 06-2013
 * $Revision$ 1.0
 *****************************************************************************/

#ifndef _TopologyAwareLB_H_
#define _TopologyAwareLB_H_

/* Includes */
#include "TopologyAwareLB.decl.h"
#include "CentralLB.h"
#include "ckgraph.h"

#include <algorithm>
#include <cfloat>
#include <cmath>
#include <cstdio>
#include <hwloc.h>
#include <sys/time.h>
#include <topology_model.h>

/* Definitions */
#ifndef LATFACTOR
#define LATFACTOR 1e-9
#endif
#ifndef BANDFACTOR
#define BANDFACTOR 1048576
#endif
#ifndef NODESIZE
#define NODESIZE 32
#endif

void CreateTopologyAwareLB();
BaseLB * AllocateTopologyAwareLB();

/* Base class */
class TopologyAwareLB : public CentralLB {
public:
    TopologyAwareLB (const CkLBOptions &);
    TopologyAwareLB (CkMigrateMessage *m);
    CmiBool QueryBalanceNow (int step);
    void work (LDStats* stats);
    void pup (PUP::er &p){ CentralLB::pup(p); }

protected:
    void init ();
    void init (char* xmlfile);

    hwloc_topology_t topology;          // hwloc machine topology
    std::vector< ProcInfo > pus;        // Processing Units vector (PEs)
    std::vector< Vertex > tasks;        // Tasks vector (chares)
    
    std::vector< ProcInfo > ParsePUs (LDStats *stats);  /* Parse the processing units array */
    std::vector< Vertex > ParseTasks (LDStats *stats);  /* Parse the tasks array */

    void ProfileData ();                            /* Call all profiling methods */
    std::vector<double> TasksPerPU ();              /* Number of chares per processor as vector */
    std::vector<double> TasksLoadVector ();         /* Chare load as vector */
    std::vector<double> TasksMessageVector ();      /* Chare messages as vector */
    std::vector<double> TasksBytesVector ();        /* Chare bytes as vector */
    std::vector<double> PULoadVector ();            /* Processor load as vector */
    std::vector<double> PUOverheadVector ();        /* Processor overhead as vector */
    std::vector<double> TasksMessageMatrix ();      /* Messages for each pair of processors */
    std::vector<double> TasksBytesMatrix ();        /* Bytes for each pair of processors */

    void PrintVector (std::vector<double> infoVector);   /* Prints vector data */
    void PrintTopologyVector (std::vector<double> infoVector);   /* Maps communication information to the topology */
    void PrintTopologyBpM (std::vector<double> messages, std::vector<double> bytes);   /* Maps communication information to the topology (bytes per message)*/
    
};

#define LEVELTYPE_COMPUTENODE 0
#define LEVELTYPE_NETWORK 1
#define LEVELTYPE_WHOLETOPOLOGY 2

class CommunicationCosts {
    public:
        CommunicationCosts (int level): _level(level) {};
        CommunicationCosts (): _level( LEVELTYPE_WHOLETOPOLOGY ){};
        struct comm_t getCommCost(hwloc_topology_t topo, int i, int j);

    private:
        int _level;
};

#endif
