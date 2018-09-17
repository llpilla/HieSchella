#include "HwTopoLBNode.h"

CreateLBFunc_Def(HwTopoLBNode, "Topology-aware load balancing algorithm. Takes into account the communication costs of the machine (as latency and bandwidth). Proved asymptotically optimal.")

void HwTopoLBNode::init (){
    costs = CommunicationCosts(LEVELTYPE_COMPUTENODE);
    HwTopoLB::init(NODEFILE, NODESIZE);
    
}

HwTopoLBNode::HwTopoLBNode(const CkLBOptions &opt): HwTopoLB(opt)
{
    init();
    if (CkMyPe() == 0)
        CkPrintf("[%d] HwTopoLB created\n",CkMyPe());
}

HwTopoLBNode::HwTopoLBNode(CkMigrateMessage *m):HwTopoLB(m) {
    init();
}

#include "HwTopoLBNode.def.h"
