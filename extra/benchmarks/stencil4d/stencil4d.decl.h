#ifndef _DECL_stencil4d_H_
#define _DECL_stencil4d_H_
#include "charm++.h"
/* DECLS: readonly CProxy_Main mainProxy;
 */

/* DECLS: readonly int arrayDimW;
 */

/* DECLS: readonly int arrayDimX;
 */

/* DECLS: readonly int arrayDimY;
 */

/* DECLS: readonly int arrayDimZ;
 */

/* DECLS: readonly int blockDimW;
 */

/* DECLS: readonly int blockDimX;
 */

/* DECLS: readonly int blockDimY;
 */

/* DECLS: readonly int blockDimZ;
 */

/* DECLS: readonly int num_chare_w;
 */

/* DECLS: readonly int num_chare_x;
 */

/* DECLS: readonly int num_chare_y;
 */

/* DECLS: readonly int num_chare_z;
 */

/* DECLS: mainchare Main: Chare{
Main(CkArgMsg* impl_msg);
void terminate(void);
void nextStep(CkReductionMsg* impl_msg);
void beginIteration(void);
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
    /* DECLS: void terminate(void);
     */
    // Entry point registration at startup
    
    static int reg_terminate_void();
    // Entry point index lookup
    
    inline static int idx_terminate_void() {
      static int epidx = reg_terminate_void();
      return epidx;
    }

    
    inline static int idx_terminate(void (Main::*)(void) ) {
      return idx_terminate_void();
    }


    
    static int terminate(void) { return idx_terminate_void(); }
    
    static void _call_terminate_void(void* impl_msg, void* impl_obj);
    /* DECLS: void nextStep(CkReductionMsg* impl_msg);
     */
    // Entry point registration at startup
    
    static int reg_nextStep_CkReductionMsg();
    // Entry point index lookup
    
    inline static int idx_nextStep_CkReductionMsg() {
      static int epidx = reg_nextStep_CkReductionMsg();
      return epidx;
    }

    
    inline static int idx_nextStep(void (Main::*)(CkReductionMsg* impl_msg) ) {
      return idx_nextStep_CkReductionMsg();
    }


    
    static int nextStep(CkReductionMsg* impl_msg) { return idx_nextStep_CkReductionMsg(); }
    
    static void _call_nextStep_CkReductionMsg(void* impl_msg, void* impl_obj);
    /* DECLS: void beginIteration(void);
     */
    // Entry point registration at startup
    
    static int reg_beginIteration_void();
    // Entry point index lookup
    
    inline static int idx_beginIteration_void() {
      static int epidx = reg_beginIteration_void();
      return epidx;
    }

    
    inline static int idx_beginIteration(void (Main::*)(void) ) {
      return idx_beginIteration_void();
    }


    
    static int beginIteration(void) { return idx_beginIteration_void(); }
    
    static void _call_beginIteration_void(void* impl_msg, void* impl_obj);
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
/* DECLS: Main(CkArgMsg* impl_msg);
 */
    static CkChareID ckNew(CkArgMsg* impl_msg, int onPE=CK_PE_ANY);
    static void ckNew(CkArgMsg* impl_msg, CkChareID* pcid, int onPE=CK_PE_ANY);
    CProxy_Main(CkArgMsg* impl_msg, int onPE=CK_PE_ANY);

/* DECLS: void terminate(void);
 */
    
    void terminate(void);

/* DECLS: void nextStep(CkReductionMsg* impl_msg);
 */
    
    void nextStep(CkReductionMsg* impl_msg);

/* DECLS: void beginIteration(void);
 */
    
    void beginIteration(void);

};
PUPmarshall(CProxy_Main)
typedef CBaseT1<Chare, CProxy_Main> CBase_Main;

/* DECLS: array Stencil: ArrayElement{
Stencil(CkMigrateMessage* impl_msg);
Stencil(void);
void begin_iteration(void);
void receiveGhosts(int iter, int dir, int length, int width, int height, const double *ghosts);
void pauseForLB(void);
void doStep(void);
};
 */
 class Stencil;
 class CkIndex_Stencil;
 class CProxy_Stencil;
 class CProxyElement_Stencil;
 class CProxySection_Stencil;
/* --------------- index object ------------------ */
class CkIndex_Stencil:public CProxyElement_ArrayElement{
  public:
    typedef Stencil local_t;
    typedef CkIndex_Stencil index_t;
    typedef CProxy_Stencil proxy_t;
    typedef CProxyElement_Stencil element_t;
    typedef CProxySection_Stencil section_t;

    static int __idx;
    static void __register(const char *s, size_t size);
    /* DECLS: Stencil(CkMigrateMessage* impl_msg);
     */
    // Entry point registration at startup
    
    static int reg_Stencil_CkMigrateMessage();
    // Entry point index lookup
    
    inline static int idx_Stencil_CkMigrateMessage() {
      static int epidx = reg_Stencil_CkMigrateMessage();
      return epidx;
    }

    
    static int ckNew(CkMigrateMessage* impl_msg) { return idx_Stencil_CkMigrateMessage(); }
    
    static void _call_Stencil_CkMigrateMessage(void* impl_msg, void* impl_obj);
    /* DECLS: Stencil(void);
     */
    // Entry point registration at startup
    
    static int reg_Stencil_void();
    // Entry point index lookup
    
    inline static int idx_Stencil_void() {
      static int epidx = reg_Stencil_void();
      return epidx;
    }

    
    static int ckNew(void) { return idx_Stencil_void(); }
    
    static void _call_Stencil_void(void* impl_msg, void* impl_obj);
    /* DECLS: void begin_iteration(void);
     */
    // Entry point registration at startup
    
    static int reg_begin_iteration_void();
    // Entry point index lookup
    
    inline static int idx_begin_iteration_void() {
      static int epidx = reg_begin_iteration_void();
      return epidx;
    }

    
    inline static int idx_begin_iteration(void (Stencil::*)(void) ) {
      return idx_begin_iteration_void();
    }


    
    static int begin_iteration(void) { return idx_begin_iteration_void(); }
    
    static void _call_begin_iteration_void(void* impl_msg, void* impl_obj);
    /* DECLS: void receiveGhosts(int iter, int dir, int length, int width, int height, const double *ghosts);
     */
    // Entry point registration at startup
    
    static int reg_receiveGhosts_marshall3();
    // Entry point index lookup
    
    inline static int idx_receiveGhosts_marshall3() {
      static int epidx = reg_receiveGhosts_marshall3();
      return epidx;
    }

    
    inline static int idx_receiveGhosts(void (Stencil::*)(int iter, int dir, int length, int width, int height, const double *ghosts) ) {
      return idx_receiveGhosts_marshall3();
    }


    
    static int receiveGhosts(int iter, int dir, int length, int width, int height, const double *ghosts) { return idx_receiveGhosts_marshall3(); }
    
    static void _call_receiveGhosts_marshall3(void* impl_msg, void* impl_obj);
    
    static int _callmarshall_receiveGhosts_marshall3(char* impl_buf, void* impl_obj_void);
    
    static void _marshallmessagepup_receiveGhosts_marshall3(PUP::er &p,void *msg);
    /* DECLS: void pauseForLB(void);
     */
    // Entry point registration at startup
    
    static int reg_pauseForLB_void();
    // Entry point index lookup
    
    inline static int idx_pauseForLB_void() {
      static int epidx = reg_pauseForLB_void();
      return epidx;
    }

    
    inline static int idx_pauseForLB(void (Stencil::*)(void) ) {
      return idx_pauseForLB_void();
    }


    
    static int pauseForLB(void) { return idx_pauseForLB_void(); }
    
    static void _call_pauseForLB_void(void* impl_msg, void* impl_obj);
    /* DECLS: void doStep(void);
     */
    // Entry point registration at startup
    
    static int reg_doStep_void();
    // Entry point index lookup
    
    inline static int idx_doStep_void() {
      static int epidx = reg_doStep_void();
      return epidx;
    }

    
    inline static int idx_doStep(void (Stencil::*)(void) ) {
      return idx_doStep_void();
    }


    
    static int doStep(void) { return idx_doStep_void(); }
    
    static void _call_doStep_void(void* impl_msg, void* impl_obj);
};
/* --------------- element proxy ------------------ */
 class CProxyElement_Stencil : public CProxyElement_ArrayElement{
  public:
    typedef Stencil local_t;
    typedef CkIndex_Stencil index_t;
    typedef CProxy_Stencil proxy_t;
    typedef CProxyElement_Stencil element_t;
    typedef CProxySection_Stencil section_t;

    CProxyElement_Stencil(void) {}
    CProxyElement_Stencil(const ArrayElement *e) : CProxyElement_ArrayElement(e){  }

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

    Stencil *ckLocal(void) const
    { return (Stencil *)CProxyElement_ArrayElement::ckLocal(); }

    CProxyElement_Stencil(const CkArrayID &aid,const CkArrayIndex4D &idx,CK_DELCTOR_PARAM)
        :CProxyElement_ArrayElement(aid,idx,CK_DELCTOR_ARGS)
    {}
    CProxyElement_Stencil(const CkArrayID &aid,const CkArrayIndex4D &idx)
        :CProxyElement_ArrayElement(aid,idx)
    {}

    CProxyElement_Stencil(const CkArrayID &aid,const CkArrayIndex &idx,CK_DELCTOR_PARAM)
        :CProxyElement_ArrayElement(aid,idx,CK_DELCTOR_ARGS)
    {}
    CProxyElement_Stencil(const CkArrayID &aid,const CkArrayIndex &idx)
        :CProxyElement_ArrayElement(aid,idx)
    {}
/* DECLS: Stencil(CkMigrateMessage* impl_msg);
 */

/* DECLS: Stencil(void);
 */
    
    void insert(int onPE=-1);
/* DECLS: void begin_iteration(void);
 */
    
    void begin_iteration(void) ;

/* DECLS: void receiveGhosts(int iter, int dir, int length, int width, int height, const double *ghosts);
 */
    
    void receiveGhosts(int iter, int dir, int length, int width, int height, const double *ghosts, const CkEntryOptions *impl_e_opts=NULL) ;

/* DECLS: void pauseForLB(void);
 */
    
    void pauseForLB(void) ;

/* DECLS: void doStep(void);
 */
    
    void doStep(void) ;

};
PUPmarshall(CProxyElement_Stencil)
/* ---------------- collective proxy -------------- */
 class CProxy_Stencil : public CProxy_ArrayElement{
  public:
    typedef Stencil local_t;
    typedef CkIndex_Stencil index_t;
    typedef CProxy_Stencil proxy_t;
    typedef CProxyElement_Stencil element_t;
    typedef CProxySection_Stencil section_t;

    CProxy_Stencil(void) {}
    CProxy_Stencil(const ArrayElement *e) : CProxy_ArrayElement(e){  }

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
    CProxyElement_Stencil operator [] (const CkArrayIndex4D &idx) const
    { return CProxyElement_Stencil(ckGetArrayID(), idx, CK_DELCTOR_CALL); }
    CProxyElement_Stencil operator() (const CkArrayIndex4D &idx) const
    { return CProxyElement_Stencil(ckGetArrayID(), idx, CK_DELCTOR_CALL); }
    CProxyElement_Stencil operator () (short int i0,short int i1,short int i2,short int i3) const 
        {return CProxyElement_Stencil(ckGetArrayID(), CkArrayIndex4D(i0,i1,i2,i3), CK_DELCTOR_CALL);}
    CProxyElement_Stencil operator () (CkIndex4D idx) const 
        {return CProxyElement_Stencil(ckGetArrayID(), CkArrayIndex4D(idx), CK_DELCTOR_CALL);}
    CProxy_Stencil(const CkArrayID &aid,CK_DELCTOR_PARAM) 
        :CProxy_ArrayElement(aid,CK_DELCTOR_ARGS) {}
    CProxy_Stencil(const CkArrayID &aid) 
        :CProxy_ArrayElement(aid) {}
/* DECLS: Stencil(CkMigrateMessage* impl_msg);
 */

/* DECLS: Stencil(void);
 */
    
    static CkArrayID ckNew(const CkArrayOptions &opts);

/* DECLS: void begin_iteration(void);
 */
    
    void begin_iteration(void) ;

/* DECLS: void receiveGhosts(int iter, int dir, int length, int width, int height, const double *ghosts);
 */
    
    void receiveGhosts(int iter, int dir, int length, int width, int height, const double *ghosts, const CkEntryOptions *impl_e_opts=NULL) ;

/* DECLS: void pauseForLB(void);
 */
    
    void pauseForLB(void) ;

/* DECLS: void doStep(void);
 */
    
    void doStep(void) ;

};
PUPmarshall(CProxy_Stencil)
/* ---------------- section proxy -------------- */
 class CProxySection_Stencil : public CProxySection_ArrayElement{
  public:
    typedef Stencil local_t;
    typedef CkIndex_Stencil index_t;
    typedef CProxy_Stencil proxy_t;
    typedef CProxyElement_Stencil element_t;
    typedef CProxySection_Stencil section_t;

    CProxySection_Stencil(void) {}

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
    CProxyElement_Stencil operator [] (const CkArrayIndex4D &idx) const
        {return CProxyElement_Stencil(ckGetArrayID(), idx, CK_DELCTOR_CALL);}
    CProxyElement_Stencil operator() (const CkArrayIndex4D &idx) const
        {return CProxyElement_Stencil(ckGetArrayID(), idx, CK_DELCTOR_CALL);}
    CProxyElement_Stencil operator () (int idx) const 
        {return CProxyElement_Stencil(ckGetArrayID(), *(CkArrayIndex4D*)&ckGetArrayElements()[idx], CK_DELCTOR_CALL);}
    static CkSectionID ckNew(const CkArrayID &aid, CkArrayIndex4D *elems, int nElems) {
      return CkSectionID(aid, elems, nElems);
    } 
    static CkSectionID ckNew(const CkArrayID &aid, int l1, int u1, int s1, int l2, int u2, int s2, int l3, int u3, int s3, int l4, int u4, int s4) {
      CkVec<CkArrayIndex4D> al;
      for (int i=l1; i<=u1; i+=s1) 
        for (int j=l2; j<=u2; j+=s2) 
          for (int k=l3; k<=u3; k+=s3) 
            for (int l=l4; l<=u4; l+=s4) 
              al.push_back(CkArrayIndex4D(i, j, k, l));
      return CkSectionID(aid, al.getVec(), al.size());
    } 
    CProxySection_Stencil(const CkArrayID &aid, CkArrayIndex *elems, int nElems, CK_DELCTOR_PARAM) 
        :CProxySection_ArrayElement(aid,elems,nElems,CK_DELCTOR_ARGS) {}
    CProxySection_Stencil(const CkArrayID &aid, CkArrayIndex *elems, int nElems) 
        :CProxySection_ArrayElement(aid,elems,nElems) {}
    CProxySection_Stencil(const CkSectionID &sid)       :CProxySection_ArrayElement(sid) {}
    CProxySection_Stencil(int n, const CkArrayID *aid, CkArrayIndex const * const *elems, const int *nElems, CK_DELCTOR_PARAM) 
        :CProxySection_ArrayElement(n,aid,elems,nElems,CK_DELCTOR_ARGS) {}
    CProxySection_Stencil(int n, const CkArrayID *aid, CkArrayIndex const * const *elems, const int *nElems) 
        :CProxySection_ArrayElement(n,aid,elems,nElems) {}
    static CkSectionID ckNew(const CkArrayID &aid, CkArrayIndex *elems, int nElems) {
      return CkSectionID(aid, elems, nElems);
    } 
/* DECLS: Stencil(CkMigrateMessage* impl_msg);
 */

/* DECLS: Stencil(void);
 */
    

/* DECLS: void begin_iteration(void);
 */
    
    void begin_iteration(void) ;

/* DECLS: void receiveGhosts(int iter, int dir, int length, int width, int height, const double *ghosts);
 */
    
    void receiveGhosts(int iter, int dir, int length, int width, int height, const double *ghosts, const CkEntryOptions *impl_e_opts=NULL) ;

/* DECLS: void pauseForLB(void);
 */
    
    void pauseForLB(void) ;

/* DECLS: void doStep(void);
 */
    
    void doStep(void) ;

};
PUPmarshall(CProxySection_Stencil)
#define Stencil_SDAG_CODE                                                      \
public:                                                                        \
  void doStep();                                                               \
private:                                                                       \
  void doStep_end();                                                           \
  void _slist_0();                                                             \
  void _slist_0_end();                                                         \
  void _atomic_0();                                                            \
  void _for_0();                                                               \
  void _for_0_end();                                                           \
  void _slist_1();                                                             \
  void _slist_1_end();                                                         \
  int _when_0();                                                               \
  void _when_0_end(int iter, int dir, int length, int width, int height, double * ghosts);\
  void _atomic_1(int iter, int dir, int length, int width, int height, double * ghosts);\
  void _atomic_2();                                                            \
public:                                                                        \
  void receiveGhosts(int iter, int dir, int length, int width, int height, double *ghosts);\
private:                                                                       \
  CDep *__cDep;                                                                \
  void __sdag_init();                                                          \
public:                                                                        \
  void __sdag_pup(PUP::er& p) {                                                \
    if (__cDep) { __cDep->pup(p); }                                            \
  }                                                                            \
  static void __sdag_register();                                               \
  static int _sdag_idx_Stencil_begin_iteration();                              \
  static int _sdag_reg_Stencil_begin_iteration();                              \
  static int _sdag_idx_Stencil_process_ghosts();                               \
  static int _sdag_reg_Stencil_process_ghosts();                               \
  static int _sdag_idx_Stencil_do_work();                                      \
  static int _sdag_reg_Stencil_do_work();                                      \

typedef CBaseT1<ArrayElementT<CkIndex4D>, CProxy_Stencil> CBase_Stencil;

extern void _registerstencil4d(void);
extern "C" void CkRegisterMainModule(void);
#endif
