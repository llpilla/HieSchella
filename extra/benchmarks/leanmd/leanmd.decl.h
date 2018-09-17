#ifndef _DECL_leanmd_H_
#define _DECL_leanmd_H_
#include "charm++.h"
/* DECLS: readonly CProxy_Main mainProxy;
 */

/* DECLS: readonly CProxy_Cell cellArray;
 */

/* DECLS: readonly CProxy_Compute computeArray;
 */

/* DECLS: readonly CkGroupID mCastGrpID;
 */

/* DECLS: readonly int cellArrayDimX;
 */

/* DECLS: readonly int cellArrayDimY;
 */

/* DECLS: readonly int cellArrayDimZ;
 */

/* DECLS: readonly int finalStepCount;
 */

/* DECLS: readonly int firstLdbStep;
 */

/* DECLS: readonly int ldbPeriod;
 */

/* DECLS: mainchare Main: Chare{
Main(CkMigrateMessage* impl_msg);
Main(CkArgMsg* impl_msg);
void allDone(int done);
void computesCreated(int proceed);
void sectionsCreated(int proceed);
void energySumP(double energyIn);
void energySumK(double energyIn);
void run(void);
};
 */
 class Main;
 class CkIndex_Main;
 class CProxy_Main;
/* --------------- index object ------------------ */
class CkIndex_Main:public CProxy_Chare{
  public:
    typedef Main local_t;
    typedef CkIndex_Main index_t;
    typedef CProxy_Main proxy_t;
    typedef CProxy_Main element_t;

    static int __idx;
    static void __register(const char *s, size_t size);
    /* DECLS: Main(CkMigrateMessage* impl_msg);
     */
    // Entry point registration at startup
    
    static int reg_Main_CkMigrateMessage();
    // Entry point index lookup
    
    inline static int idx_Main_CkMigrateMessage() {
      static int epidx = reg_Main_CkMigrateMessage();
      return epidx;
    }

    
    static int ckNew(CkMigrateMessage* impl_msg) { return idx_Main_CkMigrateMessage(); }
    
    static void _call_Main_CkMigrateMessage(void* impl_msg, void* impl_obj);
    /* DECLS: Main(CkArgMsg* impl_msg);
     */
    // Entry point registration at startup
    
    static int reg_Main_CkArgMsg();
    // Entry point index lookup
    
    inline static int idx_Main_CkArgMsg() {
      static int epidx = reg_Main_CkArgMsg();
      return epidx;
    }

    
    static int ckNew(CkArgMsg* impl_msg) { return idx_Main_CkArgMsg(); }
    
    static void _call_Main_CkArgMsg(void* impl_msg, void* impl_obj);
    /* DECLS: void allDone(int done);
     */
    // Entry point registration at startup
    
    static int reg_allDone_marshall2();
    // Entry point index lookup
    
    inline static int idx_allDone_marshall2() {
      static int epidx = reg_allDone_marshall2();
      return epidx;
    }

    
    inline static int idx_allDone(void (Main::*)(int done) ) {
      return idx_allDone_marshall2();
    }


    
    static int allDone(int done) { return idx_allDone_marshall2(); }
    // Entry point registration at startup
    
    static int reg_redn_wrapper_allDone_marshall2();
    // Entry point index lookup
    
    inline static int idx_redn_wrapper_allDone_marshall2() {
      static int epidx = reg_redn_wrapper_allDone_marshall2();
      return epidx;
    }
    
    static int redn_wrapper_allDone(CkReductionMsg* impl_msg) { return idx_redn_wrapper_allDone_marshall2(); }
    
    static void _call_redn_wrapper_allDone_marshall2(void* impl_msg, void* impl_obj_void);
    
    static void _call_allDone_marshall2(void* impl_msg, void* impl_obj);
    
    static int _callmarshall_allDone_marshall2(char* impl_buf, void* impl_obj_void);
    
    static void _marshallmessagepup_allDone_marshall2(PUP::er &p,void *msg);
    /* DECLS: void computesCreated(int proceed);
     */
    // Entry point registration at startup
    
    static int reg_computesCreated_marshall3();
    // Entry point index lookup
    
    inline static int idx_computesCreated_marshall3() {
      static int epidx = reg_computesCreated_marshall3();
      return epidx;
    }

    
    inline static int idx_computesCreated(void (Main::*)(int proceed) ) {
      return idx_computesCreated_marshall3();
    }


    
    static int computesCreated(int proceed) { return idx_computesCreated_marshall3(); }
    // Entry point registration at startup
    
    static int reg_redn_wrapper_computesCreated_marshall3();
    // Entry point index lookup
    
    inline static int idx_redn_wrapper_computesCreated_marshall3() {
      static int epidx = reg_redn_wrapper_computesCreated_marshall3();
      return epidx;
    }
    
    static int redn_wrapper_computesCreated(CkReductionMsg* impl_msg) { return idx_redn_wrapper_computesCreated_marshall3(); }
    
    static void _call_redn_wrapper_computesCreated_marshall3(void* impl_msg, void* impl_obj_void);
    
    static void _call_computesCreated_marshall3(void* impl_msg, void* impl_obj);
    
    static int _callmarshall_computesCreated_marshall3(char* impl_buf, void* impl_obj_void);
    
    static void _marshallmessagepup_computesCreated_marshall3(PUP::er &p,void *msg);
    /* DECLS: void sectionsCreated(int proceed);
     */
    // Entry point registration at startup
    
    static int reg_sectionsCreated_marshall4();
    // Entry point index lookup
    
    inline static int idx_sectionsCreated_marshall4() {
      static int epidx = reg_sectionsCreated_marshall4();
      return epidx;
    }

    
    inline static int idx_sectionsCreated(void (Main::*)(int proceed) ) {
      return idx_sectionsCreated_marshall4();
    }


    
    static int sectionsCreated(int proceed) { return idx_sectionsCreated_marshall4(); }
    // Entry point registration at startup
    
    static int reg_redn_wrapper_sectionsCreated_marshall4();
    // Entry point index lookup
    
    inline static int idx_redn_wrapper_sectionsCreated_marshall4() {
      static int epidx = reg_redn_wrapper_sectionsCreated_marshall4();
      return epidx;
    }
    
    static int redn_wrapper_sectionsCreated(CkReductionMsg* impl_msg) { return idx_redn_wrapper_sectionsCreated_marshall4(); }
    
    static void _call_redn_wrapper_sectionsCreated_marshall4(void* impl_msg, void* impl_obj_void);
    
    static void _call_sectionsCreated_marshall4(void* impl_msg, void* impl_obj);
    
    static int _callmarshall_sectionsCreated_marshall4(char* impl_buf, void* impl_obj_void);
    
    static void _marshallmessagepup_sectionsCreated_marshall4(PUP::er &p,void *msg);
    /* DECLS: void energySumP(double energyIn);
     */
    // Entry point registration at startup
    
    static int reg_energySumP_marshall5();
    // Entry point index lookup
    
    inline static int idx_energySumP_marshall5() {
      static int epidx = reg_energySumP_marshall5();
      return epidx;
    }

    
    inline static int idx_energySumP(void (Main::*)(double energyIn) ) {
      return idx_energySumP_marshall5();
    }


    
    static int energySumP(double energyIn) { return idx_energySumP_marshall5(); }
    // Entry point registration at startup
    
    static int reg_redn_wrapper_energySumP_marshall5();
    // Entry point index lookup
    
    inline static int idx_redn_wrapper_energySumP_marshall5() {
      static int epidx = reg_redn_wrapper_energySumP_marshall5();
      return epidx;
    }
    
    static int redn_wrapper_energySumP(CkReductionMsg* impl_msg) { return idx_redn_wrapper_energySumP_marshall5(); }
    
    static void _call_redn_wrapper_energySumP_marshall5(void* impl_msg, void* impl_obj_void);
    
    static void _call_energySumP_marshall5(void* impl_msg, void* impl_obj);
    
    static int _callmarshall_energySumP_marshall5(char* impl_buf, void* impl_obj_void);
    
    static void _marshallmessagepup_energySumP_marshall5(PUP::er &p,void *msg);
    /* DECLS: void energySumK(double energyIn);
     */
    // Entry point registration at startup
    
    static int reg_energySumK_marshall6();
    // Entry point index lookup
    
    inline static int idx_energySumK_marshall6() {
      static int epidx = reg_energySumK_marshall6();
      return epidx;
    }

    
    inline static int idx_energySumK(void (Main::*)(double energyIn) ) {
      return idx_energySumK_marshall6();
    }


    
    static int energySumK(double energyIn) { return idx_energySumK_marshall6(); }
    // Entry point registration at startup
    
    static int reg_redn_wrapper_energySumK_marshall6();
    // Entry point index lookup
    
    inline static int idx_redn_wrapper_energySumK_marshall6() {
      static int epidx = reg_redn_wrapper_energySumK_marshall6();
      return epidx;
    }
    
    static int redn_wrapper_energySumK(CkReductionMsg* impl_msg) { return idx_redn_wrapper_energySumK_marshall6(); }
    
    static void _call_redn_wrapper_energySumK_marshall6(void* impl_msg, void* impl_obj_void);
    
    static void _call_energySumK_marshall6(void* impl_msg, void* impl_obj);
    
    static int _callmarshall_energySumK_marshall6(char* impl_buf, void* impl_obj_void);
    
    static void _marshallmessagepup_energySumK_marshall6(PUP::er &p,void *msg);
    /* DECLS: void run(void);
     */
    // Entry point registration at startup
    
    static int reg_run_void();
    // Entry point index lookup
    
    inline static int idx_run_void() {
      static int epidx = reg_run_void();
      return epidx;
    }

    
    inline static int idx_run(void (Main::*)(void) ) {
      return idx_run_void();
    }


    
    static int run(void) { return idx_run_void(); }
    
    static void _call_run_void(void* impl_msg, void* impl_obj);
};
/* --------------- element proxy ------------------ */
class CProxy_Main:public CProxy_Chare{
  public:
    typedef Main local_t;
    typedef CkIndex_Main index_t;
    typedef CProxy_Main proxy_t;
    typedef CProxy_Main element_t;

    CProxy_Main(void) {};
    CProxy_Main(CkChareID __cid) : CProxy_Chare(__cid){  }
    CProxy_Main(const Chare *c) : CProxy_Chare(c){  }

    int ckIsDelegated(void) const
    { return CProxy_Chare::ckIsDelegated(); }
    inline CkDelegateMgr *ckDelegatedTo(void) const
    { return CProxy_Chare::ckDelegatedTo(); }
    inline CkDelegateData *ckDelegatedPtr(void) const
    { return CProxy_Chare::ckDelegatedPtr(); }
    CkGroupID ckDelegatedIdx(void) const
    { return CProxy_Chare::ckDelegatedIdx(); }

    inline void ckCheck(void) const
    { CProxy_Chare::ckCheck(); }
    const CkChareID &ckGetChareID(void) const
    { return CProxy_Chare::ckGetChareID(); }
    operator const CkChareID &(void) const
    { return ckGetChareID(); }

    void ckDelegate(CkDelegateMgr *dTo,CkDelegateData *dPtr=NULL)
    {       CProxy_Chare::ckDelegate(dTo,dPtr); }
    void ckUndelegate(void)
    {       CProxy_Chare::ckUndelegate(); }
    void pup(PUP::er &p)
    {       CProxy_Chare::pup(p); }

    void ckSetChareID(const CkChareID &c)
    {      CProxy_Chare::ckSetChareID(c); }
    Main *ckLocal(void) const
    { return (Main *)CkLocalChare(&ckGetChareID()); }
/* DECLS: Main(CkMigrateMessage* impl_msg);
 */

/* DECLS: Main(CkArgMsg* impl_msg);
 */
    static CkChareID ckNew(CkArgMsg* impl_msg, int onPE=CK_PE_ANY);
    static void ckNew(CkArgMsg* impl_msg, CkChareID* pcid, int onPE=CK_PE_ANY);
    CProxy_Main(CkArgMsg* impl_msg, int onPE=CK_PE_ANY);

/* DECLS: void allDone(int done);
 */
    
    void allDone(int done, const CkEntryOptions *impl_e_opts=NULL);

/* DECLS: void computesCreated(int proceed);
 */
    
    void computesCreated(int proceed, const CkEntryOptions *impl_e_opts=NULL);

/* DECLS: void sectionsCreated(int proceed);
 */
    
    void sectionsCreated(int proceed, const CkEntryOptions *impl_e_opts=NULL);

/* DECLS: void energySumP(double energyIn);
 */
    
    void energySumP(double energyIn, const CkEntryOptions *impl_e_opts=NULL);

/* DECLS: void energySumK(double energyIn);
 */
    
    void energySumK(double energyIn, const CkEntryOptions *impl_e_opts=NULL);

/* DECLS: void run(void);
 */
    
    void run(void);

};
PUPmarshall(CProxy_Main)
#define Main_SDAG_CODE                                                         \
public:                                                                        \
  void run();                                                                  \
private:                                                                       \
  void run_end();                                                              \
  void _slist_0();                                                             \
  void _slist_0_end();                                                         \
  int _when_0();                                                               \
  void _when_0_end(int proceed);                                               \
  void _atomic_0(int proceed);                                                 \
  int _when_1();                                                               \
  void _when_1_end(int proceed);                                               \
  void _atomic_1(int proceed);                                                 \
  int _when_2();                                                               \
  void _when_2_end(double energyP, double energyK);                            \
  void _atomic_2(double energyP, double energyK);                              \
  int _when_3();                                                               \
  void _when_3_end(double energyP, double energyK);                            \
  void _atomic_3(double energyP, double energyK);                              \
  int _when_4();                                                               \
  void _when_4_end(int done);                                                  \
  void _atomic_4(int done);                                                    \
public:                                                                        \
  void computesCreated(int proceed);                                           \
  void sectionsCreated(int proceed);                                           \
  void energySumP(double energyP);                                             \
  void energySumK(double energyK);                                             \
  void allDone(int done);                                                      \
private:                                                                       \
  CDep *__cDep;                                                                \
  void __sdag_init();                                                          \
public:                                                                        \
  void __sdag_pup(PUP::er& p) {                                                \
    if (__cDep) { __cDep->pup(p); }                                            \
  }                                                                            \
  static void __sdag_register();                                               \
  static int _sdag_idx_Main_atomic_0();                                        \
  static int _sdag_reg_Main_atomic_0();                                        \
  static int _sdag_idx_Main_atomic_1();                                        \
  static int _sdag_reg_Main_atomic_1();                                        \
  static int _sdag_idx_Main_atomic_2();                                        \
  static int _sdag_reg_Main_atomic_2();                                        \
  static int _sdag_idx_Main_atomic_3();                                        \
  static int _sdag_reg_Main_atomic_3();                                        \
  static int _sdag_idx_Main_atomic_4();                                        \
  static int _sdag_reg_Main_atomic_4();                                        \

typedef CBaseT1<Chare, CProxy_Main> CBase_Main;

/* DECLS: message ParticleDataMsg{
vec3 part[];
}
;
 */
class ParticleDataMsg;
class CMessage_ParticleDataMsg:public CkMessage{
  public:
    static int __idx;
    void* operator new(size_t, void*p) { return p; }
    void* operator new(size_t);
    void* operator new(size_t, int*, const int);
    void* operator new(size_t, int*);
#if CMK_MULTIPLE_DELETE
    void operator delete(void*p, void*){dealloc(p);}
    void operator delete(void*p){dealloc(p);}
    void operator delete(void*p, int*, const int){dealloc(p);}
    void operator delete(void*p, int*){dealloc(p);}
#endif
    void operator delete(void*p, size_t){dealloc(p);}
    static void* alloc(int,size_t, int*, int);
    static void dealloc(void *p);
    CMessage_ParticleDataMsg();
    static void *pack(ParticleDataMsg *p);
    static ParticleDataMsg* unpack(void* p);
    void *operator new(size_t, int);
    void *operator new(size_t, int, const int);
#if CMK_MULTIPLE_DELETE
    void operator delete(void *p, int){dealloc(p);}
    void operator delete(void *p, int, const int){dealloc(p);}
#endif
    static void __register(const char *s, size_t size, CkPackFnPtr pack, CkUnpackFnPtr unpack) {
      __idx = CkRegisterMsg(s, pack, unpack, dealloc, size);
    }
};

/* DECLS: array Cell: ArrayElement{
Cell(CkMigrateMessage* impl_msg);
Cell(void);
void createComputes(void);
void createSection(void);
void receiveParticles(const CkVec<Particle > &updates);
void ResumeFromSync(void);
void resumeAfterLB(int resume);
void reduceForces(const vec3 *forces, int n);
void run(void);
};
 */
 class Cell;
 class CkIndex_Cell;
 class CProxy_Cell;
 class CProxyElement_Cell;
 class CProxySection_Cell;
/* --------------- index object ------------------ */
class CkIndex_Cell:public CProxyElement_ArrayElement{
  public:
    typedef Cell local_t;
    typedef CkIndex_Cell index_t;
    typedef CProxy_Cell proxy_t;
    typedef CProxyElement_Cell element_t;
    typedef CProxySection_Cell section_t;

    static int __idx;
    static void __register(const char *s, size_t size);
    /* DECLS: Cell(CkMigrateMessage* impl_msg);
     */
    // Entry point registration at startup
    
    static int reg_Cell_CkMigrateMessage();
    // Entry point index lookup
    
    inline static int idx_Cell_CkMigrateMessage() {
      static int epidx = reg_Cell_CkMigrateMessage();
      return epidx;
    }

    
    static int ckNew(CkMigrateMessage* impl_msg) { return idx_Cell_CkMigrateMessage(); }
    
    static void _call_Cell_CkMigrateMessage(void* impl_msg, void* impl_obj);
    /* DECLS: Cell(void);
     */
    // Entry point registration at startup
    
    static int reg_Cell_void();
    // Entry point index lookup
    
    inline static int idx_Cell_void() {
      static int epidx = reg_Cell_void();
      return epidx;
    }

    
    static int ckNew(void) { return idx_Cell_void(); }
    
    static void _call_Cell_void(void* impl_msg, void* impl_obj);
    /* DECLS: void createComputes(void);
     */
    // Entry point registration at startup
    
    static int reg_createComputes_void();
    // Entry point index lookup
    
    inline static int idx_createComputes_void() {
      static int epidx = reg_createComputes_void();
      return epidx;
    }

    
    inline static int idx_createComputes(void (Cell::*)(void) ) {
      return idx_createComputes_void();
    }


    
    static int createComputes(void) { return idx_createComputes_void(); }
    
    static void _call_createComputes_void(void* impl_msg, void* impl_obj);
    /* DECLS: void createSection(void);
     */
    // Entry point registration at startup
    
    static int reg_createSection_void();
    // Entry point index lookup
    
    inline static int idx_createSection_void() {
      static int epidx = reg_createSection_void();
      return epidx;
    }

    
    inline static int idx_createSection(void (Cell::*)(void) ) {
      return idx_createSection_void();
    }


    
    static int createSection(void) { return idx_createSection_void(); }
    
    static void _call_createSection_void(void* impl_msg, void* impl_obj);
    /* DECLS: void receiveParticles(const CkVec<Particle > &updates);
     */
    // Entry point registration at startup
    
    static int reg_receiveParticles_marshall4();
    // Entry point index lookup
    
    inline static int idx_receiveParticles_marshall4() {
      static int epidx = reg_receiveParticles_marshall4();
      return epidx;
    }

    
    inline static int idx_receiveParticles(void (Cell::*)(const CkVec<Particle > &updates) ) {
      return idx_receiveParticles_marshall4();
    }


    
    static int receiveParticles(const CkVec<Particle > &updates) { return idx_receiveParticles_marshall4(); }
    
    static void _call_receiveParticles_marshall4(void* impl_msg, void* impl_obj);
    
    static int _callmarshall_receiveParticles_marshall4(char* impl_buf, void* impl_obj_void);
    
    static void _marshallmessagepup_receiveParticles_marshall4(PUP::er &p,void *msg);
    /* DECLS: void ResumeFromSync(void);
     */
    // Entry point registration at startup
    
    static int reg_ResumeFromSync_void();
    // Entry point index lookup
    
    inline static int idx_ResumeFromSync_void() {
      static int epidx = reg_ResumeFromSync_void();
      return epidx;
    }

    
    inline static int idx_ResumeFromSync(void (Cell::*)(void) ) {
      return idx_ResumeFromSync_void();
    }


    
    static int ResumeFromSync(void) { return idx_ResumeFromSync_void(); }
    
    static void _call_ResumeFromSync_void(void* impl_msg, void* impl_obj);
    /* DECLS: void resumeAfterLB(int resume);
     */
    // Entry point registration at startup
    
    static int reg_resumeAfterLB_marshall6();
    // Entry point index lookup
    
    inline static int idx_resumeAfterLB_marshall6() {
      static int epidx = reg_resumeAfterLB_marshall6();
      return epidx;
    }

    
    inline static int idx_resumeAfterLB(void (Cell::*)(int resume) ) {
      return idx_resumeAfterLB_marshall6();
    }


    
    static int resumeAfterLB(int resume) { return idx_resumeAfterLB_marshall6(); }
    
    static void _call_resumeAfterLB_marshall6(void* impl_msg, void* impl_obj);
    
    static int _callmarshall_resumeAfterLB_marshall6(char* impl_buf, void* impl_obj_void);
    
    static void _marshallmessagepup_resumeAfterLB_marshall6(PUP::er &p,void *msg);
    /* DECLS: void reduceForces(const vec3 *forces, int n);
     */
    // Entry point registration at startup
    
    static int reg_reduceForces_marshall7();
    // Entry point index lookup
    
    inline static int idx_reduceForces_marshall7() {
      static int epidx = reg_reduceForces_marshall7();
      return epidx;
    }

    
    inline static int idx_reduceForces(void (Cell::*)(const vec3 *forces, int n) ) {
      return idx_reduceForces_marshall7();
    }


    
    static int reduceForces(const vec3 *forces, int n) { return idx_reduceForces_marshall7(); }
    // Entry point registration at startup
    
    static int reg_redn_wrapper_reduceForces_marshall7();
    // Entry point index lookup
    
    inline static int idx_redn_wrapper_reduceForces_marshall7() {
      static int epidx = reg_redn_wrapper_reduceForces_marshall7();
      return epidx;
    }
    
    static int redn_wrapper_reduceForces(CkReductionMsg* impl_msg) { return idx_redn_wrapper_reduceForces_marshall7(); }
    
    static void _call_redn_wrapper_reduceForces_marshall7(void* impl_msg, void* impl_obj_void);
    
    static void _call_reduceForces_marshall7(void* impl_msg, void* impl_obj);
    
    static int _callmarshall_reduceForces_marshall7(char* impl_buf, void* impl_obj_void);
    
    static void _marshallmessagepup_reduceForces_marshall7(PUP::er &p,void *msg);
    /* DECLS: void run(void);
     */
    // Entry point registration at startup
    
    static int reg_run_void();
    // Entry point index lookup
    
    inline static int idx_run_void() {
      static int epidx = reg_run_void();
      return epidx;
    }

    
    inline static int idx_run(void (Cell::*)(void) ) {
      return idx_run_void();
    }


    
    static int run(void) { return idx_run_void(); }
    
    static void _call_run_void(void* impl_msg, void* impl_obj);
};
/* --------------- element proxy ------------------ */
 class CProxyElement_Cell : public CProxyElement_ArrayElement{
  public:
    typedef Cell local_t;
    typedef CkIndex_Cell index_t;
    typedef CProxy_Cell proxy_t;
    typedef CProxyElement_Cell element_t;
    typedef CProxySection_Cell section_t;

    CProxyElement_Cell(void) {}
    CProxyElement_Cell(const ArrayElement *e) : CProxyElement_ArrayElement(e){  }

    void ckDelegate(CkDelegateMgr *dTo,CkDelegateData *dPtr=NULL)
    {       CProxyElement_ArrayElement::ckDelegate(dTo,dPtr); }
    void ckUndelegate(void)
    {       CProxyElement_ArrayElement::ckUndelegate(); }
    void pup(PUP::er &p)
    {       CProxyElement_ArrayElement::pup(p); }

    int ckIsDelegated(void) const
    { return CProxyElement_ArrayElement::ckIsDelegated(); }
    inline CkDelegateMgr *ckDelegatedTo(void) const
    { return CProxyElement_ArrayElement::ckDelegatedTo(); }
    inline CkDelegateData *ckDelegatedPtr(void) const
    { return CProxyElement_ArrayElement::ckDelegatedPtr(); }
    CkGroupID ckDelegatedIdx(void) const
    { return CProxyElement_ArrayElement::ckDelegatedIdx(); }

    inline void ckCheck(void) const
    { CProxyElement_ArrayElement::ckCheck(); }
    inline operator CkArrayID () const
    { return ckGetArrayID(); }
    inline CkArrayID ckGetArrayID(void) const
    { return CProxyElement_ArrayElement::ckGetArrayID(); }
    inline CkArray *ckLocalBranch(void) const
    { return CProxyElement_ArrayElement::ckLocalBranch(); }
    inline CkLocMgr *ckLocMgr(void) const
    { return CProxyElement_ArrayElement::ckLocMgr(); }

    inline static CkArrayID ckCreateEmptyArray(void)
    { return CProxyElement_ArrayElement::ckCreateEmptyArray(); }
    inline static CkArrayID ckCreateArray(CkArrayMessage *m,int ctor,const CkArrayOptions &opts)
    { return CProxyElement_ArrayElement::ckCreateArray(m,ctor,opts); }
    inline void ckInsertIdx(CkArrayMessage *m,int ctor,int onPe,const CkArrayIndex &idx)
    { CProxyElement_ArrayElement::ckInsertIdx(m,ctor,onPe,idx); }
    inline void doneInserting(void)
    { CProxyElement_ArrayElement::doneInserting(); }

    inline void ckBroadcast(CkArrayMessage *m, int ep, int opts=0) const
    { CProxyElement_ArrayElement::ckBroadcast(m,ep,opts); }
    inline void setReductionClient(CkReductionClientFn fn,void *param=NULL) const
    { CProxyElement_ArrayElement::setReductionClient(fn,param); }
    inline void ckSetReductionClient(CkReductionClientFn fn,void *param=NULL) const
    { CProxyElement_ArrayElement::ckSetReductionClient(fn,param); }
    inline void ckSetReductionClient(CkCallback *cb) const
    { CProxyElement_ArrayElement::ckSetReductionClient(cb); }

    inline void ckInsert(CkArrayMessage *m,int ctor,int onPe)
    { CProxyElement_ArrayElement::ckInsert(m,ctor,onPe); }
    inline void ckSend(CkArrayMessage *m, int ep, int opts = 0) const
    { CProxyElement_ArrayElement::ckSend(m,ep,opts); }
    inline void *ckSendSync(CkArrayMessage *m, int ep) const
    { return CProxyElement_ArrayElement::ckSendSync(m,ep); }
    inline const CkArrayIndex &ckGetIndex() const
    { return CProxyElement_ArrayElement::ckGetIndex(); }

    Cell *ckLocal(void) const
    { return (Cell *)CProxyElement_ArrayElement::ckLocal(); }

    CProxyElement_Cell(const CkArrayID &aid,const CkArrayIndex3D &idx,CK_DELCTOR_PARAM)
        :CProxyElement_ArrayElement(aid,idx,CK_DELCTOR_ARGS)
    {}
    CProxyElement_Cell(const CkArrayID &aid,const CkArrayIndex3D &idx)
        :CProxyElement_ArrayElement(aid,idx)
    {}

    CProxyElement_Cell(const CkArrayID &aid,const CkArrayIndex &idx,CK_DELCTOR_PARAM)
        :CProxyElement_ArrayElement(aid,idx,CK_DELCTOR_ARGS)
    {}
    CProxyElement_Cell(const CkArrayID &aid,const CkArrayIndex &idx)
        :CProxyElement_ArrayElement(aid,idx)
    {}
/* DECLS: Cell(CkMigrateMessage* impl_msg);
 */

/* DECLS: Cell(void);
 */
    
    void insert(int onPE=-1);
/* DECLS: void createComputes(void);
 */
    
    void createComputes(void) ;

/* DECLS: void createSection(void);
 */
    
    void createSection(void) ;

/* DECLS: void receiveParticles(const CkVec<Particle > &updates);
 */
    
    void receiveParticles(const CkVec<Particle > &updates, const CkEntryOptions *impl_e_opts=NULL) ;

/* DECLS: void ResumeFromSync(void);
 */
    
    void ResumeFromSync(void) ;

/* DECLS: void resumeAfterLB(int resume);
 */
    
    void resumeAfterLB(int resume, const CkEntryOptions *impl_e_opts=NULL) ;

/* DECLS: void reduceForces(const vec3 *forces, int n);
 */
    
    void reduceForces(const vec3 *forces, int n, const CkEntryOptions *impl_e_opts=NULL) ;

/* DECLS: void run(void);
 */
    
    void run(void) ;

};
PUPmarshall(CProxyElement_Cell)
/* ---------------- collective proxy -------------- */
 class CProxy_Cell : public CProxy_ArrayElement{
  public:
    typedef Cell local_t;
    typedef CkIndex_Cell index_t;
    typedef CProxy_Cell proxy_t;
    typedef CProxyElement_Cell element_t;
    typedef CProxySection_Cell section_t;

    CProxy_Cell(void) {}
    CProxy_Cell(const ArrayElement *e) : CProxy_ArrayElement(e){  }

    void ckDelegate(CkDelegateMgr *dTo,CkDelegateData *dPtr=NULL)
    {       CProxy_ArrayElement::ckDelegate(dTo,dPtr); }
    void ckUndelegate(void)
    {       CProxy_ArrayElement::ckUndelegate(); }
    void pup(PUP::er &p)
    {       CProxy_ArrayElement::pup(p); }

    int ckIsDelegated(void) const
    { return CProxy_ArrayElement::ckIsDelegated(); }
    inline CkDelegateMgr *ckDelegatedTo(void) const
    { return CProxy_ArrayElement::ckDelegatedTo(); }
    inline CkDelegateData *ckDelegatedPtr(void) const
    { return CProxy_ArrayElement::ckDelegatedPtr(); }
    CkGroupID ckDelegatedIdx(void) const
    { return CProxy_ArrayElement::ckDelegatedIdx(); }

    inline void ckCheck(void) const
    { CProxy_ArrayElement::ckCheck(); }
    inline operator CkArrayID () const
    { return ckGetArrayID(); }
    inline CkArrayID ckGetArrayID(void) const
    { return CProxy_ArrayElement::ckGetArrayID(); }
    inline CkArray *ckLocalBranch(void) const
    { return CProxy_ArrayElement::ckLocalBranch(); }
    inline CkLocMgr *ckLocMgr(void) const
    { return CProxy_ArrayElement::ckLocMgr(); }

    inline static CkArrayID ckCreateEmptyArray(void)
    { return CProxy_ArrayElement::ckCreateEmptyArray(); }
    inline static CkArrayID ckCreateArray(CkArrayMessage *m,int ctor,const CkArrayOptions &opts)
    { return CProxy_ArrayElement::ckCreateArray(m,ctor,opts); }
    inline void ckInsertIdx(CkArrayMessage *m,int ctor,int onPe,const CkArrayIndex &idx)
    { CProxy_ArrayElement::ckInsertIdx(m,ctor,onPe,idx); }
    inline void doneInserting(void)
    { CProxy_ArrayElement::doneInserting(); }

    inline void ckBroadcast(CkArrayMessage *m, int ep, int opts=0) const
    { CProxy_ArrayElement::ckBroadcast(m,ep,opts); }
    inline void setReductionClient(CkReductionClientFn fn,void *param=NULL) const
    { CProxy_ArrayElement::setReductionClient(fn,param); }
    inline void ckSetReductionClient(CkReductionClientFn fn,void *param=NULL) const
    { CProxy_ArrayElement::ckSetReductionClient(fn,param); }
    inline void ckSetReductionClient(CkCallback *cb) const
    { CProxy_ArrayElement::ckSetReductionClient(cb); }

    static CkArrayID ckNew(void) { return ckCreateEmptyArray(); }
    // Generalized array indexing:
    CProxyElement_Cell operator [] (const CkArrayIndex3D &idx) const
    { return CProxyElement_Cell(ckGetArrayID(), idx, CK_DELCTOR_CALL); }
    CProxyElement_Cell operator() (const CkArrayIndex3D &idx) const
    { return CProxyElement_Cell(ckGetArrayID(), idx, CK_DELCTOR_CALL); }
    CProxyElement_Cell operator () (int i0,int i1,int i2) const 
        {return CProxyElement_Cell(ckGetArrayID(), CkArrayIndex3D(i0,i1,i2), CK_DELCTOR_CALL);}
    CProxyElement_Cell operator () (CkIndex3D idx) const 
        {return CProxyElement_Cell(ckGetArrayID(), CkArrayIndex3D(idx), CK_DELCTOR_CALL);}
    CProxy_Cell(const CkArrayID &aid,CK_DELCTOR_PARAM) 
        :CProxy_ArrayElement(aid,CK_DELCTOR_ARGS) {}
    CProxy_Cell(const CkArrayID &aid) 
        :CProxy_ArrayElement(aid) {}
/* DECLS: Cell(CkMigrateMessage* impl_msg);
 */

/* DECLS: Cell(void);
 */
    
    static CkArrayID ckNew(const CkArrayOptions &opts);
    static CkArrayID ckNew(const int s1, const int s2, const int s3);

/* DECLS: void createComputes(void);
 */
    
    void createComputes(void) ;

/* DECLS: void createSection(void);
 */
    
    void createSection(void) ;

/* DECLS: void receiveParticles(const CkVec<Particle > &updates);
 */
    
    void receiveParticles(const CkVec<Particle > &updates, const CkEntryOptions *impl_e_opts=NULL) ;

/* DECLS: void ResumeFromSync(void);
 */
    
    void ResumeFromSync(void) ;

/* DECLS: void resumeAfterLB(int resume);
 */
    
    void resumeAfterLB(int resume, const CkEntryOptions *impl_e_opts=NULL) ;

/* DECLS: void reduceForces(const vec3 *forces, int n);
 */
    
    void reduceForces(const vec3 *forces, int n, const CkEntryOptions *impl_e_opts=NULL) ;

/* DECLS: void run(void);
 */
    
    void run(void) ;

};
PUPmarshall(CProxy_Cell)
/* ---------------- section proxy -------------- */
 class CProxySection_Cell : public CProxySection_ArrayElement{
  public:
    typedef Cell local_t;
    typedef CkIndex_Cell index_t;
    typedef CProxy_Cell proxy_t;
    typedef CProxyElement_Cell element_t;
    typedef CProxySection_Cell section_t;

    CProxySection_Cell(void) {}

    void ckDelegate(CkDelegateMgr *dTo,CkDelegateData *dPtr=NULL)
    {       CProxySection_ArrayElement::ckDelegate(dTo,dPtr); }
    void ckUndelegate(void)
    {       CProxySection_ArrayElement::ckUndelegate(); }
    void pup(PUP::er &p)
    {       CProxySection_ArrayElement::pup(p); }

    int ckIsDelegated(void) const
    { return CProxySection_ArrayElement::ckIsDelegated(); }
    inline CkDelegateMgr *ckDelegatedTo(void) const
    { return CProxySection_ArrayElement::ckDelegatedTo(); }
    inline CkDelegateData *ckDelegatedPtr(void) const
    { return CProxySection_ArrayElement::ckDelegatedPtr(); }
    CkGroupID ckDelegatedIdx(void) const
    { return CProxySection_ArrayElement::ckDelegatedIdx(); }

    inline void ckCheck(void) const
    { CProxySection_ArrayElement::ckCheck(); }
    inline operator CkArrayID () const
    { return ckGetArrayID(); }
    inline CkArrayID ckGetArrayID(void) const
    { return CProxySection_ArrayElement::ckGetArrayID(); }
    inline CkArray *ckLocalBranch(void) const
    { return CProxySection_ArrayElement::ckLocalBranch(); }
    inline CkLocMgr *ckLocMgr(void) const
    { return CProxySection_ArrayElement::ckLocMgr(); }

    inline static CkArrayID ckCreateEmptyArray(void)
    { return CProxySection_ArrayElement::ckCreateEmptyArray(); }
    inline static CkArrayID ckCreateArray(CkArrayMessage *m,int ctor,const CkArrayOptions &opts)
    { return CProxySection_ArrayElement::ckCreateArray(m,ctor,opts); }
    inline void ckInsertIdx(CkArrayMessage *m,int ctor,int onPe,const CkArrayIndex &idx)
    { CProxySection_ArrayElement::ckInsertIdx(m,ctor,onPe,idx); }
    inline void doneInserting(void)
    { CProxySection_ArrayElement::doneInserting(); }

    inline void ckBroadcast(CkArrayMessage *m, int ep, int opts=0) const
    { CProxySection_ArrayElement::ckBroadcast(m,ep,opts); }
    inline void setReductionClient(CkReductionClientFn fn,void *param=NULL) const
    { CProxySection_ArrayElement::setReductionClient(fn,param); }
    inline void ckSetReductionClient(CkReductionClientFn fn,void *param=NULL) const
    { CProxySection_ArrayElement::ckSetReductionClient(fn,param); }
    inline void ckSetReductionClient(CkCallback *cb) const
    { CProxySection_ArrayElement::ckSetReductionClient(cb); }

    inline void ckSend(CkArrayMessage *m, int ep, int opts = 0)
    { CProxySection_ArrayElement::ckSend(m,ep,opts); }
    inline CkSectionInfo &ckGetSectionInfo()
    { return CProxySection_ArrayElement::ckGetSectionInfo(); }
    inline CkSectionID *ckGetSectionIDs()
    { return CProxySection_ArrayElement::ckGetSectionIDs(); }
    inline CkSectionID &ckGetSectionID()
    { return CProxySection_ArrayElement::ckGetSectionID(); }
    inline CkSectionID &ckGetSectionID(int i)
    { return CProxySection_ArrayElement::ckGetSectionID(i); }
    inline CkArrayID ckGetArrayIDn(int i) const
    { return CProxySection_ArrayElement::ckGetArrayIDn(i); } 
    inline CkArrayIndex *ckGetArrayElements() const
    { return CProxySection_ArrayElement::ckGetArrayElements(); }
    inline CkArrayIndex *ckGetArrayElements(int i) const
    { return CProxySection_ArrayElement::ckGetArrayElements(i); }
    inline int ckGetNumElements() const
    { return CProxySection_ArrayElement::ckGetNumElements(); } 
    inline int ckGetNumElements(int i) const
    { return CProxySection_ArrayElement::ckGetNumElements(i); }    // Generalized array indexing:
    CProxyElement_Cell operator [] (const CkArrayIndex3D &idx) const
        {return CProxyElement_Cell(ckGetArrayID(), idx, CK_DELCTOR_CALL);}
    CProxyElement_Cell operator() (const CkArrayIndex3D &idx) const
        {return CProxyElement_Cell(ckGetArrayID(), idx, CK_DELCTOR_CALL);}
    CProxyElement_Cell operator () (int idx) const 
        {return CProxyElement_Cell(ckGetArrayID(), *(CkArrayIndex3D*)&ckGetArrayElements()[idx], CK_DELCTOR_CALL);}
    static CkSectionID ckNew(const CkArrayID &aid, CkArrayIndex3D *elems, int nElems) {
      return CkSectionID(aid, elems, nElems);
    } 
    static CkSectionID ckNew(const CkArrayID &aid, int l1, int u1, int s1, int l2, int u2, int s2, int l3, int u3, int s3) {
      CkVec<CkArrayIndex3D> al;
      for (int i=l1; i<=u1; i+=s1) 
        for (int j=l2; j<=u2; j+=s2) 
          for (int k=l3; k<=u3; k+=s3) 
          al.push_back(CkArrayIndex3D(i, j, k));
      return CkSectionID(aid, al.getVec(), al.size());
    } 
    CProxySection_Cell(const CkArrayID &aid, CkArrayIndex *elems, int nElems, CK_DELCTOR_PARAM) 
        :CProxySection_ArrayElement(aid,elems,nElems,CK_DELCTOR_ARGS) {}
    CProxySection_Cell(const CkArrayID &aid, CkArrayIndex *elems, int nElems) 
        :CProxySection_ArrayElement(aid,elems,nElems) {}
    CProxySection_Cell(const CkSectionID &sid)       :CProxySection_ArrayElement(sid) {}
    CProxySection_Cell(int n, const CkArrayID *aid, CkArrayIndex const * const *elems, const int *nElems, CK_DELCTOR_PARAM) 
        :CProxySection_ArrayElement(n,aid,elems,nElems,CK_DELCTOR_ARGS) {}
    CProxySection_Cell(int n, const CkArrayID *aid, CkArrayIndex const * const *elems, const int *nElems) 
        :CProxySection_ArrayElement(n,aid,elems,nElems) {}
    static CkSectionID ckNew(const CkArrayID &aid, CkArrayIndex *elems, int nElems) {
      return CkSectionID(aid, elems, nElems);
    } 
/* DECLS: Cell(CkMigrateMessage* impl_msg);
 */

/* DECLS: Cell(void);
 */
    

/* DECLS: void createComputes(void);
 */
    
    void createComputes(void) ;

/* DECLS: void createSection(void);
 */
    
    void createSection(void) ;

/* DECLS: void receiveParticles(const CkVec<Particle > &updates);
 */
    
    void receiveParticles(const CkVec<Particle > &updates, const CkEntryOptions *impl_e_opts=NULL) ;

/* DECLS: void ResumeFromSync(void);
 */
    
    void ResumeFromSync(void) ;

/* DECLS: void resumeAfterLB(int resume);
 */
    
    void resumeAfterLB(int resume, const CkEntryOptions *impl_e_opts=NULL) ;

/* DECLS: void reduceForces(const vec3 *forces, int n);
 */
    
    void reduceForces(const vec3 *forces, int n, const CkEntryOptions *impl_e_opts=NULL) ;

/* DECLS: void run(void);
 */
    
    void run(void) ;

};
PUPmarshall(CProxySection_Cell)
#define Cell_SDAG_CODE                                                         \
public:                                                                        \
  void run();                                                                  \
private:                                                                       \
  void run_end();                                                              \
  void _slist_0();                                                             \
  void _slist_0_end();                                                         \
  void _if_0();                                                                \
  void _if_0_end();                                                            \
  void _atomic_0();                                                            \
  void _for_0();                                                               \
  void _for_0_end();                                                           \
  void _slist_1();                                                             \
  void _slist_1_end();                                                         \
  void _atomic_1();                                                            \
  int _when_0();                                                               \
  void _when_0_end(vec3 * forces, int n);                                      \
  void _slist_2(vec3 * forces, int n);                                         \
  void _slist_2_end(vec3 * forces, int n);                                     \
  void _atomic_2(vec3 * forces, int n);                                        \
  void _if_1();                                                                \
  void _if_1_end();                                                            \
  void _slist_3();                                                             \
  void _slist_3_end();                                                         \
  void _atomic_3();                                                            \
  void _for_1();                                                               \
  void _for_1_end();                                                           \
  void _slist_4();                                                             \
  void _slist_4_end();                                                         \
  int _when_1();                                                               \
  void _when_1_end(CkVec<Particle > updates);                                  \
  void _atomic_4(CkVec<Particle > updates);                                    \
  void _if_2();                                                                \
  void _if_2_end();                                                            \
  void _atomic_5();                                                            \
  void _if_3();                                                                \
  void _if_3_end();                                                            \
  void _slist_5();                                                             \
  void _slist_5_end();                                                         \
  void _atomic_6();                                                            \
  int _when_2();                                                               \
  void _when_2_end(int resume);                                                \
  void _atomic_7(int resume);                                                  \
  void _atomic_8();                                                            \
public:                                                                        \
  void reduceForces(vec3 *forces, int n);                                      \
  void receiveParticles(CkVec<Particle > updates);                             \
  void resumeAfterLB(int resume);                                              \
private:                                                                       \
  CDep *__cDep;                                                                \
  void __sdag_init();                                                          \
public:                                                                        \
  void __sdag_pup(PUP::er& p) {                                                \
    if (__cDep) { __cDep->pup(p); }                                            \
  }                                                                            \
  static void __sdag_register();                                               \
  static int _sdag_idx_Cell_atomic_0();                                        \
  static int _sdag_reg_Cell_atomic_0();                                        \
  static int _sdag_idx_Cell_atomic_1();                                        \
  static int _sdag_reg_Cell_atomic_1();                                        \
  static int _sdag_idx_Cell_atomic_2();                                        \
  static int _sdag_reg_Cell_atomic_2();                                        \
  static int _sdag_idx_Cell_atomic_3();                                        \
  static int _sdag_reg_Cell_atomic_3();                                        \
  static int _sdag_idx_Cell_atomic_4();                                        \
  static int _sdag_reg_Cell_atomic_4();                                        \
  static int _sdag_idx_Cell_atomic_5();                                        \
  static int _sdag_reg_Cell_atomic_5();                                        \
  static int _sdag_idx_Cell_atomic_6();                                        \
  static int _sdag_reg_Cell_atomic_6();                                        \
  static int _sdag_idx_Cell_atomic_7();                                        \
  static int _sdag_reg_Cell_atomic_7();                                        \
  static int _sdag_idx_Cell_atomic_8();                                        \
  static int _sdag_reg_Cell_atomic_8();                                        \

typedef CBaseT1<ArrayElementT<CkIndex3D>, CProxy_Cell> CBase_Cell;

/* DECLS: array Compute: ArrayElement{
Compute(CkMigrateMessage* impl_msg);
Compute(void);
void ResumeFromSync(void);
void calculateForces(ParticleDataMsg* impl_msg);
void run(void);
};
 */
 class Compute;
 class CkIndex_Compute;
 class CProxy_Compute;
 class CProxyElement_Compute;
 class CProxySection_Compute;
/* --------------- index object ------------------ */
class CkIndex_Compute:public CProxyElement_ArrayElement{
  public:
    typedef Compute local_t;
    typedef CkIndex_Compute index_t;
    typedef CProxy_Compute proxy_t;
    typedef CProxyElement_Compute element_t;
    typedef CProxySection_Compute section_t;

    static int __idx;
    static void __register(const char *s, size_t size);
    /* DECLS: Compute(CkMigrateMessage* impl_msg);
     */
    // Entry point registration at startup
    
    static int reg_Compute_CkMigrateMessage();
    // Entry point index lookup
    
    inline static int idx_Compute_CkMigrateMessage() {
      static int epidx = reg_Compute_CkMigrateMessage();
      return epidx;
    }

    
    static int ckNew(CkMigrateMessage* impl_msg) { return idx_Compute_CkMigrateMessage(); }
    
    static void _call_Compute_CkMigrateMessage(void* impl_msg, void* impl_obj);
    /* DECLS: Compute(void);
     */
    // Entry point registration at startup
    
    static int reg_Compute_void();
    // Entry point index lookup
    
    inline static int idx_Compute_void() {
      static int epidx = reg_Compute_void();
      return epidx;
    }

    
    static int ckNew(void) { return idx_Compute_void(); }
    
    static void _call_Compute_void(void* impl_msg, void* impl_obj);
    /* DECLS: void ResumeFromSync(void);
     */
    // Entry point registration at startup
    
    static int reg_ResumeFromSync_void();
    // Entry point index lookup
    
    inline static int idx_ResumeFromSync_void() {
      static int epidx = reg_ResumeFromSync_void();
      return epidx;
    }

    
    inline static int idx_ResumeFromSync(void (Compute::*)(void) ) {
      return idx_ResumeFromSync_void();
    }


    
    static int ResumeFromSync(void) { return idx_ResumeFromSync_void(); }
    
    static void _call_ResumeFromSync_void(void* impl_msg, void* impl_obj);
    /* DECLS: void calculateForces(ParticleDataMsg* impl_msg);
     */
    // Entry point registration at startup
    
    static int reg_calculateForces_ParticleDataMsg();
    // Entry point index lookup
    
    inline static int idx_calculateForces_ParticleDataMsg() {
      static int epidx = reg_calculateForces_ParticleDataMsg();
      return epidx;
    }

    
    inline static int idx_calculateForces(void (Compute::*)(ParticleDataMsg* impl_msg) ) {
      return idx_calculateForces_ParticleDataMsg();
    }


    
    static int calculateForces(ParticleDataMsg* impl_msg) { return idx_calculateForces_ParticleDataMsg(); }
    
    static void _call_calculateForces_ParticleDataMsg(void* impl_msg, void* impl_obj);
    /* DECLS: void run(void);
     */
    // Entry point registration at startup
    
    static int reg_run_void();
    // Entry point index lookup
    
    inline static int idx_run_void() {
      static int epidx = reg_run_void();
      return epidx;
    }

    
    inline static int idx_run(void (Compute::*)(void) ) {
      return idx_run_void();
    }


    
    static int run(void) { return idx_run_void(); }
    
    static void _call_run_void(void* impl_msg, void* impl_obj);
};
/* --------------- element proxy ------------------ */
 class CProxyElement_Compute : public CProxyElement_ArrayElement{
  public:
    typedef Compute local_t;
    typedef CkIndex_Compute index_t;
    typedef CProxy_Compute proxy_t;
    typedef CProxyElement_Compute element_t;
    typedef CProxySection_Compute section_t;

    CProxyElement_Compute(void) {}
    CProxyElement_Compute(const ArrayElement *e) : CProxyElement_ArrayElement(e){  }

    void ckDelegate(CkDelegateMgr *dTo,CkDelegateData *dPtr=NULL)
    {       CProxyElement_ArrayElement::ckDelegate(dTo,dPtr); }
    void ckUndelegate(void)
    {       CProxyElement_ArrayElement::ckUndelegate(); }
    void pup(PUP::er &p)
    {       CProxyElement_ArrayElement::pup(p); }

    int ckIsDelegated(void) const
    { return CProxyElement_ArrayElement::ckIsDelegated(); }
    inline CkDelegateMgr *ckDelegatedTo(void) const
    { return CProxyElement_ArrayElement::ckDelegatedTo(); }
    inline CkDelegateData *ckDelegatedPtr(void) const
    { return CProxyElement_ArrayElement::ckDelegatedPtr(); }
    CkGroupID ckDelegatedIdx(void) const
    { return CProxyElement_ArrayElement::ckDelegatedIdx(); }

    inline void ckCheck(void) const
    { CProxyElement_ArrayElement::ckCheck(); }
    inline operator CkArrayID () const
    { return ckGetArrayID(); }
    inline CkArrayID ckGetArrayID(void) const
    { return CProxyElement_ArrayElement::ckGetArrayID(); }
    inline CkArray *ckLocalBranch(void) const
    { return CProxyElement_ArrayElement::ckLocalBranch(); }
    inline CkLocMgr *ckLocMgr(void) const
    { return CProxyElement_ArrayElement::ckLocMgr(); }

    inline static CkArrayID ckCreateEmptyArray(void)
    { return CProxyElement_ArrayElement::ckCreateEmptyArray(); }
    inline static CkArrayID ckCreateArray(CkArrayMessage *m,int ctor,const CkArrayOptions &opts)
    { return CProxyElement_ArrayElement::ckCreateArray(m,ctor,opts); }
    inline void ckInsertIdx(CkArrayMessage *m,int ctor,int onPe,const CkArrayIndex &idx)
    { CProxyElement_ArrayElement::ckInsertIdx(m,ctor,onPe,idx); }
    inline void doneInserting(void)
    { CProxyElement_ArrayElement::doneInserting(); }

    inline void ckBroadcast(CkArrayMessage *m, int ep, int opts=0) const
    { CProxyElement_ArrayElement::ckBroadcast(m,ep,opts); }
    inline void setReductionClient(CkReductionClientFn fn,void *param=NULL) const
    { CProxyElement_ArrayElement::setReductionClient(fn,param); }
    inline void ckSetReductionClient(CkReductionClientFn fn,void *param=NULL) const
    { CProxyElement_ArrayElement::ckSetReductionClient(fn,param); }
    inline void ckSetReductionClient(CkCallback *cb) const
    { CProxyElement_ArrayElement::ckSetReductionClient(cb); }

    inline void ckInsert(CkArrayMessage *m,int ctor,int onPe)
    { CProxyElement_ArrayElement::ckInsert(m,ctor,onPe); }
    inline void ckSend(CkArrayMessage *m, int ep, int opts = 0) const
    { CProxyElement_ArrayElement::ckSend(m,ep,opts); }
    inline void *ckSendSync(CkArrayMessage *m, int ep) const
    { return CProxyElement_ArrayElement::ckSendSync(m,ep); }
    inline const CkArrayIndex &ckGetIndex() const
    { return CProxyElement_ArrayElement::ckGetIndex(); }

    Compute *ckLocal(void) const
    { return (Compute *)CProxyElement_ArrayElement::ckLocal(); }

    CProxyElement_Compute(const CkArrayID &aid,const CkArrayIndex6D &idx,CK_DELCTOR_PARAM)
        :CProxyElement_ArrayElement(aid,idx,CK_DELCTOR_ARGS)
    {}
    CProxyElement_Compute(const CkArrayID &aid,const CkArrayIndex6D &idx)
        :CProxyElement_ArrayElement(aid,idx)
    {}

    CProxyElement_Compute(const CkArrayID &aid,const CkArrayIndex &idx,CK_DELCTOR_PARAM)
        :CProxyElement_ArrayElement(aid,idx,CK_DELCTOR_ARGS)
    {}
    CProxyElement_Compute(const CkArrayID &aid,const CkArrayIndex &idx)
        :CProxyElement_ArrayElement(aid,idx)
    {}
/* DECLS: Compute(CkMigrateMessage* impl_msg);
 */

/* DECLS: Compute(void);
 */
    
    void insert(int onPE=-1);
/* DECLS: void ResumeFromSync(void);
 */
    
    void ResumeFromSync(void) ;

/* DECLS: void calculateForces(ParticleDataMsg* impl_msg);
 */
    
    void calculateForces(ParticleDataMsg* impl_msg) ;

/* DECLS: void run(void);
 */
    
    void run(void) ;

};
PUPmarshall(CProxyElement_Compute)
/* ---------------- collective proxy -------------- */
 class CProxy_Compute : public CProxy_ArrayElement{
  public:
    typedef Compute local_t;
    typedef CkIndex_Compute index_t;
    typedef CProxy_Compute proxy_t;
    typedef CProxyElement_Compute element_t;
    typedef CProxySection_Compute section_t;

    CProxy_Compute(void) {}
    CProxy_Compute(const ArrayElement *e) : CProxy_ArrayElement(e){  }

    void ckDelegate(CkDelegateMgr *dTo,CkDelegateData *dPtr=NULL)
    {       CProxy_ArrayElement::ckDelegate(dTo,dPtr); }
    void ckUndelegate(void)
    {       CProxy_ArrayElement::ckUndelegate(); }
    void pup(PUP::er &p)
    {       CProxy_ArrayElement::pup(p); }

    int ckIsDelegated(void) const
    { return CProxy_ArrayElement::ckIsDelegated(); }
    inline CkDelegateMgr *ckDelegatedTo(void) const
    { return CProxy_ArrayElement::ckDelegatedTo(); }
    inline CkDelegateData *ckDelegatedPtr(void) const
    { return CProxy_ArrayElement::ckDelegatedPtr(); }
    CkGroupID ckDelegatedIdx(void) const
    { return CProxy_ArrayElement::ckDelegatedIdx(); }

    inline void ckCheck(void) const
    { CProxy_ArrayElement::ckCheck(); }
    inline operator CkArrayID () const
    { return ckGetArrayID(); }
    inline CkArrayID ckGetArrayID(void) const
    { return CProxy_ArrayElement::ckGetArrayID(); }
    inline CkArray *ckLocalBranch(void) const
    { return CProxy_ArrayElement::ckLocalBranch(); }
    inline CkLocMgr *ckLocMgr(void) const
    { return CProxy_ArrayElement::ckLocMgr(); }

    inline static CkArrayID ckCreateEmptyArray(void)
    { return CProxy_ArrayElement::ckCreateEmptyArray(); }
    inline static CkArrayID ckCreateArray(CkArrayMessage *m,int ctor,const CkArrayOptions &opts)
    { return CProxy_ArrayElement::ckCreateArray(m,ctor,opts); }
    inline void ckInsertIdx(CkArrayMessage *m,int ctor,int onPe,const CkArrayIndex &idx)
    { CProxy_ArrayElement::ckInsertIdx(m,ctor,onPe,idx); }
    inline void doneInserting(void)
    { CProxy_ArrayElement::doneInserting(); }

    inline void ckBroadcast(CkArrayMessage *m, int ep, int opts=0) const
    { CProxy_ArrayElement::ckBroadcast(m,ep,opts); }
    inline void setReductionClient(CkReductionClientFn fn,void *param=NULL) const
    { CProxy_ArrayElement::setReductionClient(fn,param); }
    inline void ckSetReductionClient(CkReductionClientFn fn,void *param=NULL) const
    { CProxy_ArrayElement::ckSetReductionClient(fn,param); }
    inline void ckSetReductionClient(CkCallback *cb) const
    { CProxy_ArrayElement::ckSetReductionClient(cb); }

    static CkArrayID ckNew(void) { return ckCreateEmptyArray(); }
    // Generalized array indexing:
    CProxyElement_Compute operator [] (const CkArrayIndex6D &idx) const
    { return CProxyElement_Compute(ckGetArrayID(), idx, CK_DELCTOR_CALL); }
    CProxyElement_Compute operator() (const CkArrayIndex6D &idx) const
    { return CProxyElement_Compute(ckGetArrayID(), idx, CK_DELCTOR_CALL); }
    CProxyElement_Compute operator () (short int i0,short int i1,short int i2,short int i3,short int i4,short int i5) const 
        {return CProxyElement_Compute(ckGetArrayID(), CkArrayIndex6D(i0,i1,i2,i3,i4,i5), CK_DELCTOR_CALL);}
    CProxyElement_Compute operator () (CkIndex6D idx) const 
        {return CProxyElement_Compute(ckGetArrayID(), CkArrayIndex6D(idx), CK_DELCTOR_CALL);}
    CProxy_Compute(const CkArrayID &aid,CK_DELCTOR_PARAM) 
        :CProxy_ArrayElement(aid,CK_DELCTOR_ARGS) {}
    CProxy_Compute(const CkArrayID &aid) 
        :CProxy_ArrayElement(aid) {}
/* DECLS: Compute(CkMigrateMessage* impl_msg);
 */

/* DECLS: Compute(void);
 */
    
    static CkArrayID ckNew(const CkArrayOptions &opts);

/* DECLS: void ResumeFromSync(void);
 */
    
    void ResumeFromSync(void) ;

/* DECLS: void calculateForces(ParticleDataMsg* impl_msg);
 */
    
    void calculateForces(ParticleDataMsg* impl_msg) ;

/* DECLS: void run(void);
 */
    
    void run(void) ;

};
PUPmarshall(CProxy_Compute)
/* ---------------- section proxy -------------- */
 class CProxySection_Compute : public CProxySection_ArrayElement{
  public:
    typedef Compute local_t;
    typedef CkIndex_Compute index_t;
    typedef CProxy_Compute proxy_t;
    typedef CProxyElement_Compute element_t;
    typedef CProxySection_Compute section_t;

    CProxySection_Compute(void) {}

    void ckDelegate(CkDelegateMgr *dTo,CkDelegateData *dPtr=NULL)
    {       CProxySection_ArrayElement::ckDelegate(dTo,dPtr); }
    void ckUndelegate(void)
    {       CProxySection_ArrayElement::ckUndelegate(); }
    void pup(PUP::er &p)
    {       CProxySection_ArrayElement::pup(p); }

    int ckIsDelegated(void) const
    { return CProxySection_ArrayElement::ckIsDelegated(); }
    inline CkDelegateMgr *ckDelegatedTo(void) const
    { return CProxySection_ArrayElement::ckDelegatedTo(); }
    inline CkDelegateData *ckDelegatedPtr(void) const
    { return CProxySection_ArrayElement::ckDelegatedPtr(); }
    CkGroupID ckDelegatedIdx(void) const
    { return CProxySection_ArrayElement::ckDelegatedIdx(); }

    inline void ckCheck(void) const
    { CProxySection_ArrayElement::ckCheck(); }
    inline operator CkArrayID () const
    { return ckGetArrayID(); }
    inline CkArrayID ckGetArrayID(void) const
    { return CProxySection_ArrayElement::ckGetArrayID(); }
    inline CkArray *ckLocalBranch(void) const
    { return CProxySection_ArrayElement::ckLocalBranch(); }
    inline CkLocMgr *ckLocMgr(void) const
    { return CProxySection_ArrayElement::ckLocMgr(); }

    inline static CkArrayID ckCreateEmptyArray(void)
    { return CProxySection_ArrayElement::ckCreateEmptyArray(); }
    inline static CkArrayID ckCreateArray(CkArrayMessage *m,int ctor,const CkArrayOptions &opts)
    { return CProxySection_ArrayElement::ckCreateArray(m,ctor,opts); }
    inline void ckInsertIdx(CkArrayMessage *m,int ctor,int onPe,const CkArrayIndex &idx)
    { CProxySection_ArrayElement::ckInsertIdx(m,ctor,onPe,idx); }
    inline void doneInserting(void)
    { CProxySection_ArrayElement::doneInserting(); }

    inline void ckBroadcast(CkArrayMessage *m, int ep, int opts=0) const
    { CProxySection_ArrayElement::ckBroadcast(m,ep,opts); }
    inline void setReductionClient(CkReductionClientFn fn,void *param=NULL) const
    { CProxySection_ArrayElement::setReductionClient(fn,param); }
    inline void ckSetReductionClient(CkReductionClientFn fn,void *param=NULL) const
    { CProxySection_ArrayElement::ckSetReductionClient(fn,param); }
    inline void ckSetReductionClient(CkCallback *cb) const
    { CProxySection_ArrayElement::ckSetReductionClient(cb); }

    inline void ckSend(CkArrayMessage *m, int ep, int opts = 0)
    { CProxySection_ArrayElement::ckSend(m,ep,opts); }
    inline CkSectionInfo &ckGetSectionInfo()
    { return CProxySection_ArrayElement::ckGetSectionInfo(); }
    inline CkSectionID *ckGetSectionIDs()
    { return CProxySection_ArrayElement::ckGetSectionIDs(); }
    inline CkSectionID &ckGetSectionID()
    { return CProxySection_ArrayElement::ckGetSectionID(); }
    inline CkSectionID &ckGetSectionID(int i)
    { return CProxySection_ArrayElement::ckGetSectionID(i); }
    inline CkArrayID ckGetArrayIDn(int i) const
    { return CProxySection_ArrayElement::ckGetArrayIDn(i); } 
    inline CkArrayIndex *ckGetArrayElements() const
    { return CProxySection_ArrayElement::ckGetArrayElements(); }
    inline CkArrayIndex *ckGetArrayElements(int i) const
    { return CProxySection_ArrayElement::ckGetArrayElements(i); }
    inline int ckGetNumElements() const
    { return CProxySection_ArrayElement::ckGetNumElements(); } 
    inline int ckGetNumElements(int i) const
    { return CProxySection_ArrayElement::ckGetNumElements(i); }    // Generalized array indexing:
    CProxyElement_Compute operator [] (const CkArrayIndex6D &idx) const
        {return CProxyElement_Compute(ckGetArrayID(), idx, CK_DELCTOR_CALL);}
    CProxyElement_Compute operator() (const CkArrayIndex6D &idx) const
        {return CProxyElement_Compute(ckGetArrayID(), idx, CK_DELCTOR_CALL);}
    CProxyElement_Compute operator () (int idx) const 
        {return CProxyElement_Compute(ckGetArrayID(), *(CkArrayIndex6D*)&ckGetArrayElements()[idx], CK_DELCTOR_CALL);}
    static CkSectionID ckNew(const CkArrayID &aid, CkArrayIndex6D *elems, int nElems) {
      return CkSectionID(aid, elems, nElems);
    } 
    static CkSectionID ckNew(const CkArrayID &aid, int l1, int u1, int s1, int l2, int u2, int s2, int l3, int u3, int s3, int l4, int u4, int s4, int l5, int u5, int s5, int l6, int u6, int s6) {
      CkVec<CkArrayIndex6D> al;
      for (int i=l1; i<=u1; i+=s1) 
        for (int j=l2; j<=u2; j+=s2) 
          for (int k=l3; k<=u3; k+=s3) 
            for (int l=l4; l<=u4; l+=s4) 
              for (int m=l5; m<=u5; m+=s5) 
                for (int n=l6; n<=u6; n+=s6) 
                  al.push_back(CkArrayIndex6D(i, j, k, l, m, n));
      return CkSectionID(aid, al.getVec(), al.size());
    } 
    CProxySection_Compute(const CkArrayID &aid, CkArrayIndex *elems, int nElems, CK_DELCTOR_PARAM) 
        :CProxySection_ArrayElement(aid,elems,nElems,CK_DELCTOR_ARGS) {}
    CProxySection_Compute(const CkArrayID &aid, CkArrayIndex *elems, int nElems) 
        :CProxySection_ArrayElement(aid,elems,nElems) {}
    CProxySection_Compute(const CkSectionID &sid)       :CProxySection_ArrayElement(sid) {}
    CProxySection_Compute(int n, const CkArrayID *aid, CkArrayIndex const * const *elems, const int *nElems, CK_DELCTOR_PARAM) 
        :CProxySection_ArrayElement(n,aid,elems,nElems,CK_DELCTOR_ARGS) {}
    CProxySection_Compute(int n, const CkArrayID *aid, CkArrayIndex const * const *elems, const int *nElems) 
        :CProxySection_ArrayElement(n,aid,elems,nElems) {}
    static CkSectionID ckNew(const CkArrayID &aid, CkArrayIndex *elems, int nElems) {
      return CkSectionID(aid, elems, nElems);
    } 
/* DECLS: Compute(CkMigrateMessage* impl_msg);
 */

/* DECLS: Compute(void);
 */
    

/* DECLS: void ResumeFromSync(void);
 */
    
    void ResumeFromSync(void) ;

/* DECLS: void calculateForces(ParticleDataMsg* impl_msg);
 */
    
    void calculateForces(ParticleDataMsg* impl_msg) ;

/* DECLS: void run(void);
 */
    
    void run(void) ;

};
PUPmarshall(CProxySection_Compute)
#define Compute_SDAG_CODE                                                      \
public:                                                                        \
  void run();                                                                  \
private:                                                                       \
  void run_end();                                                              \
  void _slist_0();                                                             \
  void _slist_0_end();                                                         \
  void _for_0();                                                               \
  void _for_0_end();                                                           \
  void _slist_1();                                                             \
  void _slist_1_end();                                                         \
  int _when_0();                                                               \
  void _when_0_end(ParticleDataMsg* msg);                                      \
  void _atomic_0(ParticleDataMsg* msg);                                        \
  void _if_0();                                                                \
  void _if_0_end();                                                            \
  void _slist_2();                                                             \
  void _slist_2_end();                                                         \
  int _when_1();                                                               \
  void _when_1_end(ParticleDataMsg* msg);                                      \
  void _atomic_1(ParticleDataMsg* msg);                                        \
  void _if_1();                                                                \
  void _if_1_end();                                                            \
  void _atomic_2();                                                            \
public:                                                                        \
  void calculateForces(ParticleDataMsg* msg_msg);                              \
private:                                                                       \
  CDep *__cDep;                                                                \
  void __sdag_init();                                                          \
public:                                                                        \
  void __sdag_pup(PUP::er& p) {                                                \
    if (__cDep) { __cDep->pup(p); }                                            \
  }                                                                            \
  static void __sdag_register();                                               \
  static int _sdag_idx_Compute_atomic_0();                                     \
  static int _sdag_reg_Compute_atomic_0();                                     \
  static int _sdag_idx_Compute_atomic_1();                                     \
  static int _sdag_reg_Compute_atomic_1();                                     \
  static int _sdag_idx_Compute_atomic_2();                                     \
  static int _sdag_reg_Compute_atomic_2();                                     \

typedef CBaseT1<ArrayElementT<CkIndex6D>, CProxy_Compute> CBase_Compute;

extern void _registerleanmd(void);
extern "C" void CkRegisterMainModule(void);
#endif
