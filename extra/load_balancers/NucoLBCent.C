#include "NucoLBCent.h"

CreateLBFunc_Def(NucoLBCent, "Greedy algorithm which takes the communication graph and the NUCO factor into account. Tries to avoid too many migrations.")

void NucoLBCent::init (){
    topology_level = LEVELTYPE_NETWORK;
    NucoLB::init(XMLFILE, NODESIZE);
    
}

NucoLBCent::NucoLBCent(const CkLBOptions &opt): NucoLB(opt)
{
    init();
    if (CkMyPe() == 0)
        CkPrintf("[%d] NucoLB created\n",CkMyPe());
}

NucoLBCent::NucoLBCent(CkMigrateMessage *m):NucoLB(m) {
    init();
}

#include "NucoLBCent.def.h"
