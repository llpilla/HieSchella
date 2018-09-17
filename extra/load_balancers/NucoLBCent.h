#ifndef _NucoLBCent_H_
#define _NucoLBCent_H_

#include "NucoLBCent.decl.h"
#include "NucoLB.h"

void CreateNucoLBCent();
BaseLB * AllocateNucoLBCent();

class NucoLBCent : public NucoLB {
public:
    NucoLBCent(const CkLBOptions &);
    NucoLBCent(CkMigrateMessage *m);

private:
    void init();

};

#endif
