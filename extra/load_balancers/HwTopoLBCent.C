#include "HwTopoLBCent.h"

CreateLBFunc_Def(HwTopoLBCent, "Topology-aware load balancing algorithm. Takes into account the communication costs of the machine (as latency and bandwidth). Proved asymptotically optimal.")

void HwTopoLBCent::init (){
    costs = CommunicationCosts(LEVELTYPE_NETWORK);
    HwTopoLB::init(XMLFILE, NODESIZE);
    
}

HwTopoLBCent::HwTopoLBCent(const CkLBOptions &opt): HwTopoLB(opt)
{
    init();
    if (CkMyPe() == 0)
        CkPrintf("[%d] HwTopoLB created\n",CkMyPe());
}

HwTopoLBCent::HwTopoLBCent(CkMigrateMessage *m):HwTopoLB(m) {
    init();
}

#include "HwTopoLBCent.def.h"
