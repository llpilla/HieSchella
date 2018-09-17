#include "StatsLBCent.h"

CreateLBFunc_Def(StatsLBCent, "just gets the stats from the load balancing framework.")

void StatsLBCent::init(){
    StatsLB::init(XMLFILE, NODESIZE);
}

StatsLBCent::StatsLBCent(const CkLBOptions &opt): StatsLB(opt){
    init();
    if (CkMyPe() == 0)
        CkPrintf("[%d] StatsLBCent created\n",CkMyPe());
}

StatsLBCent::StatsLBCent(CkMigrateMessage *m):StatsLB(m) {
    init();
}

#include "StatsLBCent.def.h"

/*@}*/

