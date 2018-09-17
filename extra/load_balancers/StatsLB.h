/**
 * \addtogroup CkLdb
*/
/*@{*/

#ifndef _STATSLB_H_
#define _STATSLB_H_

#include "StatsLB.decl.h"
#include "TopologyAwareLB.h"

void CreateStatsLB();
BaseLB * AllocateStatsLB();

class StatsLB : public TopologyAwareLB {

public:
  StatsLB(const CkLBOptions &);
  StatsLB(CkMigrateMessage *m);
  void pup(PUP::er &p){ TopologyAwareLB::pup(p); }
  CmiBool QueryBalanceNow(int step);
  void work(LDStats* stats);

protected:
  void init ();
  void init (char* xmlfile, int nodesize);

};

#endif /* _STATSLB_H_ */

/*@}*/
