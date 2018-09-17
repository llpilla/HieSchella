/**
 * \addtogroup CkLdb
*/
/*@{*/

/*
  A Hybrid strategy that uses 3 level tree
  The top level applies refinement strategy
  The test applies greedy strategy
*/

#include "HierarchicalLB.h"
#include "LBDBManager.h"

#include "NucoLBCent.h"
#include "NucoLBNode.h"
#include "HwTopoLBCent.h"
#include "HwTopoLBNode.h"
#include "StatsLBNode.h"
#include "StatsLBCent.h"

#define  DEBUGF(x)      // CmiPrintf x;

CreateLBFunc_Def(HierarchicalLB, "Hierarchical load balancer")

HierarchicalLB::HierarchicalLB(const CkLBOptions &opt): HybridBaseLB(opt) {
	double alpha, beta;
	alpha = _lb_args.alpha();
	beta = _lb_args.beeta();
#if CMK_LBDB_ON
    lbname = (char *)"HierarchicalLB";
//	CkPrintf("Alpha\t%lf\tBeta\t%lf\n",alpha, beta);

    delete tree;
    tree = new ThreeLevelTree(32);

if (alpha < 1.9){
    refine = (CentralLB *)AllocateStatsLBCent();
} else if (alpha < 2.9){
    refine = (CentralLB *)AllocateNucoLBCent();
} else {
    refine = (CentralLB *)AllocateHwTopoLBCent();
}

if (beta < 1.9){
    node = (CentralLB *)AllocateStatsLBNode();
} else if (beta < 2.9){
    node = (CentralLB *)AllocateNucoLBNode();
} else {
    node = (CentralLB *)AllocateHwTopoLBNode();
}

    initTree();
#endif
}

HierarchicalLB::~HierarchicalLB()
{
  delete refine;
  delete node;
}

void HierarchicalLB::work(LDStats* stats) {
#if CMK_LBDB_ON
    //theLbdb->ResetAdaptive();
    LevelData *lData = levelData[currentLevel];

    if (currentLevel == 1) 
        node->work(stats);
    else
        refine->work(stats);
#endif
}
  
#include "HierarchicalLB.def.h"

/*@{*/

