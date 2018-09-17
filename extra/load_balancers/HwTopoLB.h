/*****************************************************************************
 * $Source$
 * $Author$ Christiane Pousa, Laércio Pilla, François Broquedis, Pierre Coucheney
 * $Date$ 12-2012
 * $Revision$ 1.2
 *****************************************************************************/

#ifndef _HwTopoLB_H_
#define _HwTopoLB_H_

#include "HwTopoLB.decl.h"
#include "TopologyAwareLB.h"

void CreateHwTopoLB();
BaseLB * AllocateHwTopoLB();

class HwTopoLB : public TopologyAwareLB {
public:
    HwTopoLB(const CkLBOptions &);
    HwTopoLB(CkMigrateMessage *m);
    void pup(PUP::er &p){ TopologyAwareLB::pup(p); }
    CmiBool QueryBalanceNow(int step);
    void work(LDStats* stats);

protected:
    void init ();
    void init (char* xmlfile, int nodesize);
    double unif ();
    double alpha;
    double beta;
    double temperature;
    CommunicationCosts costs;

    /* Method to compute the makespan after one specific migration */
    double computeNewMaxProcLoad (int chareId, int newProc);
    double computeCurrentMaxProcLoad (int pSize);
    /* Method to compute the changes on processor load due to migrations,
     * returns the extra load of chareId */
    double changeLoads (int chareId, int newProc, double *loads);

    //int nextStep, countStep;

    double *NewLoadArray;                           // New loads for processors after migrations
    double *OriginalLoads;                          // Array with the original load of each chare

    /* HwTopoLB functions */
    std::vector<int>* preprocess (int cSize, int pSize);
    int choosePU (int pSize, std::vector<int> *CharesOnProcs);
    int chooseTask (int chosenProc, std::vector<int> *CharesOnProcs);
    int chooseMapping (int pSize, int chosenProc, int chosenChare);
    bool applyMapping (int pSize, int chosenProc, int newProc, int chosenChare, std::vector<int> *CharesOnProcs, LDStats* stats);

};

#endif
