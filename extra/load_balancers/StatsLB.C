/** \file StatsLB.C
 *
 */

/**
 * \addtogroup CkLdb
*/
/*@{*/

#include "StatsLB.h"

CreateLBFunc_Def(StatsLB, "just gets the stats from the load balancing framework.")

void StatsLB::init(){
    init(XMLFILE, -1);
}

void StatsLB::init(char *xmlfile, int nodesize){
    lbname = "StatsLB";

    if (nodesize == -1){
        if (CkMyPe()==0){
            CkPrintf("[%d] StatsLB starting\n",CkMyPe());
            TopologyAwareLB::init(xmlfile);
        }
    }
    else {
        if (CkMyPe()%nodesize == 0){   //Only one LB per compute node
            CkPrintf("[%d] StatsLB starting\n",CkMyPe());
            TopologyAwareLB::init(xmlfile);
        }
    }
}

StatsLB::StatsLB(const CkLBOptions &opt): TopologyAwareLB(opt){
    init();
    if (CkMyPe() == 0)
        CkPrintf("[%d] StatsLB created\n",CkMyPe());
}

StatsLB::StatsLB(CkMigrateMessage *m):TopologyAwareLB(m) {
    init();
}

CmiBool StatsLB::QueryBalanceNow(int _step)
{
  //  CkPrintf("[%d] Balancing on step %d\n",CkMyPe(),_step);
  return CmiTrue; 
}

void StatsLB::work(LDStats* stats) {
    int cSize, i;
    
    TopologyAwareLB::work(stats);

    cSize = tasks.size();

    for (i = 0; i < cSize; i++){
        stats->to_proc[i] = tasks[i].getCurrentPe();
    }
}

#include "StatsLB.def.h"

/*@}*/

