/**
 * \addtogroup CkLdb
*/
/*@{*/

#ifndef HYBRIDLB_H
#define HYBRIDLB_H

#include "CentralLB.h"
#include "HybridBaseLB.h"
#include "HierarchicalLB.decl.h"

#include "topology.h"

void CreateHierarchicalLB();

class HierarchicalLB : public HybridBaseLB
{
public:
  HierarchicalLB(const CkLBOptions &);
  HierarchicalLB(CkMigrateMessage *m): HybridBaseLB(m) {}
  ~HierarchicalLB();

protected:
  CentralLB *node;
  CentralLB *refine;

  virtual bool QueryBalanceNow(int) { return true; };  
  virtual bool QueryMigrateStep(int) { return true; };  
  virtual void work(LDStats* stats);

};

#endif /* NBORBASELB_H */

/*@}*/
