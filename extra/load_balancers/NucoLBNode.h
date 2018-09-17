#ifndef _NucoLBNode_H_
#define _NucoLBNode_H_

#include "NucoLBNode.decl.h"
#include "NucoLB.h"

void CreateNucoLBNode();
BaseLB * AllocateNucoLBNode();

class NucoLBNode : public NucoLB {
public:
    NucoLBNode(const CkLBOptions &);
    NucoLBNode(CkMigrateMessage *m);

private:
    void init();

};

#endif
