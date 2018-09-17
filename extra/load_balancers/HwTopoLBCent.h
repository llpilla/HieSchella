#ifndef _HwTopoLBCent_H_
#define _HwTopoLBCent_H_

#include "HwTopoLBCent.decl.h"
#include "HwTopoLB.h"

void CreateHwTopoLBCent();
BaseLB * AllocateHwTopoLBCent();

class HwTopoLBCent : public HwTopoLB {
public:
    HwTopoLBCent(const CkLBOptions &);
    HwTopoLBCent(CkMigrateMessage *m);

private:
    void init();

};

#endif
