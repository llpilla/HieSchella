/*****************************************************************************
 * $Source$
 * $Author$
 * $Date$
 * $Revision$
 *****************************************************************************/

/**
 * \addtogroup CkLdb
*/
/*@{*/

#ifndef _NUCOLB_H_
#define _NUCOLB_H_

#include "NucoLB.decl.h"
#include "TopologyAwareLB.h"

void CreateNucoLB();
BaseLB * AllocateNucoLB();

class NucoLB : public TopologyAwareLB {
public:
    NucoLB(const CkLBOptions &);
    NucoLB(CkMigrateMessage *m);
    void pup(PUP::er &p){ TopologyAwareLB::pup(p); }
    CmiBool QueryBalanceNow(int step);
    void work(LDStats* stats);

protected:
    void init ();
    void init (char* xmlfile, int nodesize);
    void discoverTopology ();
    unsigned int getNode (unsigned int pu);
    float getLocalLatency (unsigned int node);
    float getRemoteLatency (unsigned int local_node, unsigned int remote_node);

    double alpha;
    unsigned int nuco_nodes;
    unsigned int nuco_depth;
    unsigned int local_depth;
    int topology_level;

//    double *node_weight;
//    int *node_computed;
};

#endif

/*@}*/

