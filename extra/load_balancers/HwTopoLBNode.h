#ifndef _HwTopoLBNode_H_
#define _HwTopoLBNode_H_

#include "HwTopoLBNode.decl.h"
#include "HwTopoLB.h"

void CreateHwTopoLBNode();
BaseLB * AllocateHwTopoLBNode();

class HwTopoLBNode : public HwTopoLB {
public:
    HwTopoLBNode(const CkLBOptions &);
    HwTopoLBNode(CkMigrateMessage *m);

private:
    void init();

};

#endif
