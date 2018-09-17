#ifndef _StatsLBNode_H_
#define _StatsLBNode_H_

#include "StatsLBNode.decl.h"
#include "StatsLB.h"

void CreateStatsLBNode();
BaseLB * AllocateStatsLBNode();

class StatsLBNode : public StatsLB {

public:
  StatsLBNode(const CkLBOptions &);
  StatsLBNode(CkMigrateMessage *m);

protected:
  void init ();

};

#endif 

