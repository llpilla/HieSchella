#include "StatsLBNode.h"

CreateLBFunc_Def(StatsLBNode, "just gets the stats from the load balancing framework.")

void StatsLBNode::init(){
    StatsLB::init(NODEFILE, NODESIZE);
}

StatsLBNode::StatsLBNode(const CkLBOptions &opt): StatsLB(opt){
    init();
    if (CkMyPe() == 0)
        CkPrintf("[%d] StatsLBNode created\n",CkMyPe());
}

StatsLBNode::StatsLBNode(CkMigrateMessage *m):StatsLB(m) {
    init();
}

#include "StatsLBNode.def.h"

/*@}*/

