#include "NucoLBNode.h"

CreateLBFunc_Def(NucoLBNode, "Greedy algorithm which takes the communication graph and the NUCO factor into account. Tries to avoid too many migrations.")

void NucoLBNode::init (){
    topology_level = LEVELTYPE_COMPUTENODE;
    NucoLB::init(NODEFILE, NODESIZE);
    
}

NucoLBNode::NucoLBNode(const CkLBOptions &opt): NucoLB(opt)
{
    init();
    if (CkMyPe() == 0)
        CkPrintf("[%d] NucoLB created\n",CkMyPe());
}

NucoLBNode::NucoLBNode(CkMigrateMessage *m):NucoLB(m) {
    init();
}

#include "NucoLBNode.def.h"
