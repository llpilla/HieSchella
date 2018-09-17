#ifndef _StatsLBCent_H_
#define _StatsLBCent_H_

#include "StatsLBCent.decl.h"
#include "StatsLB.h"

void CreateStatsLBCent();
BaseLB * AllocateStatsLBCent();

class StatsLBCent : public StatsLB {

public:
  StatsLBCent(const CkLBOptions &);
  StatsLBCent(CkMigrateMessage *m);

protected:
  void init ();

};

#endif 

