#ifndef _DECL_kNeighbor_H_
#define _DECL_kNeighbor_H_
#include "charm++.h"
/* DECLS: readonly CProxy_Main mainProxy;
 */

/* DECLS: readonly int num_chares;
 */

/* DECLS: readonly int gMsgSize;
 */

/* DECLS: readonly int gLBFreq;
 */

/* DECLS: readonly int amt_work;
 */

/* DECLS: message toNeighborMsg{
int data[];
}
;
 */
class toNeighborMsg;
class CMessage_toNeighborMsg:public CkMessage{
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
    CMessage_toNeighborMsg();
    static void *pack(toNeighborMsg *p);
    static toNeighborMsg* unpack(void* p);
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

/* DECLS: mainchare Main: Chare{
Main(CkArgMsg* impl_msg);
void nextStep(CkReductionMsg* impl_msg);
void terminate(CkReductionMsg* impl_msg);
void resumeIter(void);
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
    /* DECLS: void terminate(CkReductionMsg* impl_msg);
     */
    // Entry point registration at startup
    
    static int reg_terminate_CkReductionMsg();
    // Entry point index lookup
    
    inline static int idx_terminate_CkReductionMsg() {
      static int epidx = reg_terminate_CkReductionMsg();
      return epidx;
    }

    
    inline static int idx_terminate(void (Main::*)(CkReductionMsg* impl_msg) ) {
      return idx_terminate_CkReductionMsg();
    }


    
    static int terminate(CkReductionMsg* impl_msg) { return idx_terminate_CkReductionMsg(); }
    
    static void _call_terminate_CkReductionMsg(void* impl_msg, void* impl_obj);
    /* DECLS: void resumeIter(void);
     */
    // Entry point registration at startup
    
    static int reg_resumeIter_void();
    // Entry point index lookup
    
    inline static int idx_resumeIter_void() {
      static int epidx = reg_resumeIter_void();
      return epidx;
    }

    
    inline static int idx_resumeIter(void (Main::*)(void) ) {
      return idx_resumeIter_void();
    }


    
    static int resumeIter(void) { return idx_resumeIter_void(); }
    
    static void _call_resumeIter_void(void* impl_msg, void* impl_obj);
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

/* DECLS: void nextStep(CkReductionMsg* impl_msg);
 */
    
    void nextStep(CkReductionMsg* impl_msg);

/* DECLS: void terminate(CkReductionMsg* impl_msg);
 */
    
    void terminate(CkReductionMsg* impl_msg);

/* DECLS: void resumeIter(void);
 */
    
    void resumeIter(void);

};
PUPmarshall(CProxy_Main)
typedef CBaseT1<Chare, CProxy_Main> CBase_Main;

/* DECLS: array Block: ArrayElement{
Block(CkMigrateMessage* impl_msg);
Block(void);
void commWithNeighbors(void);
void recvReplies(toNeighborMsg* impl_msg);
void recvMsgs(toNeighborMsg* impl_msg);
void pauseForLB(void);
};
 */
 class Block;
 class CkIndex_Block;
 class CProxy_Block;
 class CProxyElement_Block;
 class CProxySection_Block;
/* --------------- index object ------------------ */
class CkIndex_Block:public CProxyElement_ArrayElement{
  public:
    typedef Block local_t;
    typedef CkIndex_Block index_t;
    typedef CProxy_Block proxy_t;
    typedef CProxyElement_Block element_t;
    typedef CProxySection_Block section_t;

    static int __idx;
    static void __register(const char *s, size_t size);
    /* DECLS: Block(CkMigrateMessage* impl_msg);
     */
    // Entry point registration at startup
    
    static int reg_Block_CkMigrateMessage();
    // Entry point index lookup
    
    inline static int idx_Block_CkMigrateMessage() {
      static int epidx = reg_Block_CkMigrateMessage();
      return epidx;
    }

    
    static int ckNew(CkMigrateMessage* impl_msg) { return idx_Block_CkMigrateMessage(); }
    
    static void _call_Block_CkMigrateMessage(void* impl_msg, void* impl_obj);
    /* DECLS: Block(void);
     */
    // Entry point registration at startup
    
    static int reg_Block_void();
    // Entry point index lookup
    
    inline static int idx_Block_void() {
      static int epidx = reg_Block_void();
      return epidx;
    }

    
    static int ckNew(void) { return idx_Block_void(); }
    
    static void _call_Block_void(void* impl_msg, void* impl_obj);
    /* DECLS: void commWithNeighbors(void);
     */
    // Entry point registration at startup
    
    static int reg_commWithNeighbors_void();
    // Entry point index lookup
    
    inline static int idx_commWithNeighbors_void() {
      static int epidx = reg_commWithNeighbors_void();
      return epidx;
    }

    
    inline static int idx_commWithNeighbors(void (Block::*)(void) ) {
      return idx_commWithNeighbors_void();
    }


    
    static int commWithNeighbors(void) { return idx_commWithNeighbors_void(); }
    
    static void _call_commWithNeighbors_void(void* impl_msg, void* impl_obj);
    /* DECLS: void recvReplies(toNeighborMsg* impl_msg);
     */
    // Entry point registration at startup
    
    static int reg_recvReplies_toNeighborMsg();
    // Entry point index lookup
    
    inline static int idx_recvReplies_toNeighborMsg() {
      static int epidx = reg_recvReplies_toNeighborMsg();
      return epidx;
    }

    
    inline static int idx_recvReplies(void (Block::*)(toNeighborMsg* impl_msg) ) {
      return idx_recvReplies_toNeighborMsg();
    }


    
    static int recvReplies(toNeighborMsg* impl_msg) { return idx_recvReplies_toNeighborMsg(); }
    
    static void _call_recvReplies_toNeighborMsg(void* impl_msg, void* impl_obj);
    /* DECLS: void recvMsgs(toNeighborMsg* impl_msg);
     */
    // Entry point registration at startup
    
    static int reg_recvMsgs_toNeighborMsg();
    // Entry point index lookup
    
    inline static int idx_recvMsgs_toNeighborMsg() {
      static int epidx = reg_recvMsgs_toNeighborMsg();
      return epidx;
    }

    
    inline static int idx_recvMsgs(void (Block::*)(toNeighborMsg* impl_msg) ) {
      return idx_recvMsgs_toNeighborMsg();
    }


    
    static int recvMsgs(toNeighborMsg* impl_msg) { return idx_recvMsgs_toNeighborMsg(); }
    
    static void _call_recvMsgs_toNeighborMsg(void* impl_msg, void* impl_obj);
    /* DECLS: void pauseForLB(void);
     */
    // Entry point registration at startup
    
    static int reg_pauseForLB_void();
    // Entry point index lookup
    
    inline static int idx_pauseForLB_void() {
      static int epidx = reg_pauseForLB_void();
      return epidx;
    }

    
    inline static int idx_pauseForLB(void (Block::*)(void) ) {
      return idx_pauseForLB_void();
    }


    
    static int pauseForLB(void) { return idx_pauseForLB_void(); }
    
    static void _call_pauseForLB_void(void* impl_msg, void* impl_obj);
};
/* --------------- element proxy ------------------ */
 class CProxyElement_Block : public CProxyElement_ArrayElement{
  public:
    typedef Block local_t;
    typedef CkIndex_Block index_t;
    typedef CProxy_Block proxy_t;
    typedef CProxyElement_Block element_t;
    typedef CProxySection_Block section_t;

    CProxyElement_Block(void) {}
    CProxyElement_Block(const ArrayElement *e) : CProxyElement_ArrayElement(e){  }

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

    Block *ckLocal(void) const
    { return (Block *)CProxyElement_ArrayElement::ckLocal(); }

    CProxyElement_Block(const CkArrayID &aid,const CkArrayIndex1D &idx,CK_DELCTOR_PARAM)
        :CProxyElement_ArrayElement(aid,idx,CK_DELCTOR_ARGS)
    {}
    CProxyElement_Block(const CkArrayID &aid,const CkArrayIndex1D &idx)
        :CProxyElement_ArrayElement(aid,idx)
    {}

    CProxyElement_Block(const CkArrayID &aid,const CkArrayIndex &idx,CK_DELCTOR_PARAM)
        :CProxyElement_ArrayElement(aid,idx,CK_DELCTOR_ARGS)
    {}
    CProxyElement_Block(const CkArrayID &aid,const CkArrayIndex &idx)
        :CProxyElement_ArrayElement(aid,idx)
    {}
/* DECLS: Block(CkMigrateMessage* impl_msg);
 */

/* DECLS: Block(void);
 */
    
    void insert(int onPE=-1);
/* DECLS: void commWithNeighbors(void);
 */
    
    void commWithNeighbors(void) ;

/* DECLS: void recvReplies(toNeighborMsg* impl_msg);
 */
    
    void recvReplies(toNeighborMsg* impl_msg) ;

/* DECLS: void recvMsgs(toNeighborMsg* impl_msg);
 */
    
    void recvMsgs(toNeighborMsg* impl_msg) ;

/* DECLS: void pauseForLB(void);
 */
    
    void pauseForLB(void) ;

};
PUPmarshall(CProxyElement_Block)
/* ---------------- collective proxy -------------- */
 class CProxy_Block : public CProxy_ArrayElement{
  public:
    typedef Block local_t;
    typedef CkIndex_Block index_t;
    typedef CProxy_Block proxy_t;
    typedef CProxyElement_Block element_t;
    typedef CProxySection_Block section_t;

    CProxy_Block(void) {}
    CProxy_Block(const ArrayElement *e) : CProxy_ArrayElement(e){  }

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
    CProxyElement_Block operator [] (const CkArrayIndex1D &idx) const
    { return CProxyElement_Block(ckGetArrayID(), idx, CK_DELCTOR_CALL); }
    CProxyElement_Block operator() (const CkArrayIndex1D &idx) const
    { return CProxyElement_Block(ckGetArrayID(), idx, CK_DELCTOR_CALL); }
    CProxyElement_Block operator [] (int idx) const 
        {return CProxyElement_Block(ckGetArrayID(), CkArrayIndex1D(idx), CK_DELCTOR_CALL);}
    CProxyElement_Block operator () (int idx) const 
        {return CProxyElement_Block(ckGetArrayID(), CkArrayIndex1D(idx), CK_DELCTOR_CALL);}
    CProxy_Block(const CkArrayID &aid,CK_DELCTOR_PARAM) 
        :CProxy_ArrayElement(aid,CK_DELCTOR_ARGS) {}
    CProxy_Block(const CkArrayID &aid) 
        :CProxy_ArrayElement(aid) {}
/* DECLS: Block(CkMigrateMessage* impl_msg);
 */

/* DECLS: Block(void);
 */
    
    static CkArrayID ckNew(const CkArrayOptions &opts);
    static CkArrayID ckNew(const int s1);

/* DECLS: void commWithNeighbors(void);
 */
    
    void commWithNeighbors(void) ;

/* DECLS: void recvReplies(toNeighborMsg* impl_msg);
 */
    
    void recvReplies(toNeighborMsg* impl_msg) ;

/* DECLS: void recvMsgs(toNeighborMsg* impl_msg);
 */
    
    void recvMsgs(toNeighborMsg* impl_msg) ;

/* DECLS: void pauseForLB(void);
 */
    
    void pauseForLB(void) ;

};
PUPmarshall(CProxy_Block)
/* ---------------- section proxy -------------- */
 class CProxySection_Block : public CProxySection_ArrayElement{
  public:
    typedef Block local_t;
    typedef CkIndex_Block index_t;
    typedef CProxy_Block proxy_t;
    typedef CProxyElement_Block element_t;
    typedef CProxySection_Block section_t;

    CProxySection_Block(void) {}

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
    CProxyElement_Block operator [] (const CkArrayIndex1D &idx) const
        {return CProxyElement_Block(ckGetArrayID(), idx, CK_DELCTOR_CALL);}
    CProxyElement_Block operator() (const CkArrayIndex1D &idx) const
        {return CProxyElement_Block(ckGetArrayID(), idx, CK_DELCTOR_CALL);}
    CProxyElement_Block operator [] (int idx) const 
        {return CProxyElement_Block(ckGetArrayID(), *(CkArrayIndex1D*)&ckGetArrayElements()[idx], CK_DELCTOR_CALL);}
    CProxyElement_Block operator () (int idx) const 
        {return CProxyElement_Block(ckGetArrayID(), *(CkArrayIndex1D*)&ckGetArrayElements()[idx], CK_DELCTOR_CALL);}
    static CkSectionID ckNew(const CkArrayID &aid, CkArrayIndex1D *elems, int nElems) {
      return CkSectionID(aid, elems, nElems);
    } 
    static CkSectionID ckNew(const CkArrayID &aid, int l, int u, int s) {
      CkVec<CkArrayIndex1D> al;
      for (int i=l; i<=u; i+=s) al.push_back(CkArrayIndex1D(i));
      return CkSectionID(aid, al.getVec(), al.size());
    } 
    CProxySection_Block(const CkArrayID &aid, CkArrayIndex *elems, int nElems, CK_DELCTOR_PARAM) 
        :CProxySection_ArrayElement(aid,elems,nElems,CK_DELCTOR_ARGS) {}
    CProxySection_Block(const CkArrayID &aid, CkArrayIndex *elems, int nElems) 
        :CProxySection_ArrayElement(aid,elems,nElems) {}
    CProxySection_Block(const CkSectionID &sid)       :CProxySection_ArrayElement(sid) {}
    CProxySection_Block(int n, const CkArrayID *aid, CkArrayIndex const * const *elems, const int *nElems, CK_DELCTOR_PARAM) 
        :CProxySection_ArrayElement(n,aid,elems,nElems,CK_DELCTOR_ARGS) {}
    CProxySection_Block(int n, const CkArrayID *aid, CkArrayIndex const * const *elems, const int *nElems) 
        :CProxySection_ArrayElement(n,aid,elems,nElems) {}
    static CkSectionID ckNew(const CkArrayID &aid, CkArrayIndex *elems, int nElems) {
      return CkSectionID(aid, elems, nElems);
    } 
/* DECLS: Block(CkMigrateMessage* impl_msg);
 */

/* DECLS: Block(void);
 */
    

/* DECLS: void commWithNeighbors(void);
 */
    
    void commWithNeighbors(void) ;

/* DECLS: void recvReplies(toNeighborMsg* impl_msg);
 */
    
    void recvReplies(toNeighborMsg* impl_msg) ;

/* DECLS: void recvMsgs(toNeighborMsg* impl_msg);
 */
    
    void recvMsgs(toNeighborMsg* impl_msg) ;

/* DECLS: void pauseForLB(void);
 */
    
    void pauseForLB(void) ;

};
PUPmarshall(CProxySection_Block)
typedef CBaseT1<ArrayElementT<CkIndex1D>, CProxy_Block> CBase_Block;

extern void _registerkNeighbor(void);
extern "C" void CkRegisterMainModule(void);
#endif
