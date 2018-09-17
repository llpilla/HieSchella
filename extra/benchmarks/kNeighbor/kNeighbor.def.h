/* DEFS: readonly CProxy_Main mainProxy;
 */
extern CProxy_Main mainProxy;
#ifndef CK_TEMPLATES_ONLY
extern "C" void __xlater_roPup_mainProxy(void *_impl_pup_er) {
  PUP::er &_impl_p=*(PUP::er *)_impl_pup_er;
  _impl_p|mainProxy;
}
#endif /* CK_TEMPLATES_ONLY */

/* DEFS: readonly int num_chares;
 */
extern int num_chares;
#ifndef CK_TEMPLATES_ONLY
extern "C" void __xlater_roPup_num_chares(void *_impl_pup_er) {
  PUP::er &_impl_p=*(PUP::er *)_impl_pup_er;
  _impl_p|num_chares;
}
#endif /* CK_TEMPLATES_ONLY */

/* DEFS: readonly int gMsgSize;
 */
extern int gMsgSize;
#ifndef CK_TEMPLATES_ONLY
extern "C" void __xlater_roPup_gMsgSize(void *_impl_pup_er) {
  PUP::er &_impl_p=*(PUP::er *)_impl_pup_er;
  _impl_p|gMsgSize;
}
#endif /* CK_TEMPLATES_ONLY */

/* DEFS: readonly int gLBFreq;
 */
extern int gLBFreq;
#ifndef CK_TEMPLATES_ONLY
extern "C" void __xlater_roPup_gLBFreq(void *_impl_pup_er) {
  PUP::er &_impl_p=*(PUP::er *)_impl_pup_er;
  _impl_p|gLBFreq;
}
#endif /* CK_TEMPLATES_ONLY */

/* DEFS: readonly int amt_work;
 */
extern int amt_work;
#ifndef CK_TEMPLATES_ONLY
extern "C" void __xlater_roPup_amt_work(void *_impl_pup_er) {
  PUP::er &_impl_p=*(PUP::er *)_impl_pup_er;
  _impl_p|amt_work;
}
#endif /* CK_TEMPLATES_ONLY */

/* DEFS: message toNeighborMsg{
int data[];
}
;
 */
#ifndef CK_TEMPLATES_ONLY
void *CMessage_toNeighborMsg::operator new(size_t s){
  return toNeighborMsg::alloc(__idx, s, 0, 0);
}
void *CMessage_toNeighborMsg::operator new(size_t s, int* sz){
  return toNeighborMsg::alloc(__idx, s, sz, 0);
}
void *CMessage_toNeighborMsg::operator new(size_t s, int* sz,const int pb){
  return toNeighborMsg::alloc(__idx, s, sz, pb);
}
void *CMessage_toNeighborMsg::operator new(size_t s, int sz0) {
  int sizes[1];
  sizes[0] = sz0;
  return toNeighborMsg::alloc(__idx, s, sizes, 0);
}
void *CMessage_toNeighborMsg::operator new(size_t s, int sz0, const int p) {
  int sizes[1];
  sizes[0] = sz0;
  return toNeighborMsg::alloc(__idx, s, sizes, p);
}
void* CMessage_toNeighborMsg::alloc(int msgnum, size_t sz, int *sizes, int pb) {
  CkpvAccess(_offsets)[0] = ALIGN8(sz);
  if(sizes==0)
    CkpvAccess(_offsets)[1] = CkpvAccess(_offsets)[0];
  else
    CkpvAccess(_offsets)[1] = CkpvAccess(_offsets)[0] + ALIGN8(sizeof(int)*sizes[0]);
  return CkAllocMsg(msgnum, CkpvAccess(_offsets)[1], pb);
}
CMessage_toNeighborMsg::CMessage_toNeighborMsg() {
toNeighborMsg *newmsg = (toNeighborMsg *)this;
  newmsg->data = (int *) ((char *)newmsg + CkpvAccess(_offsets)[0]);
}
void CMessage_toNeighborMsg::dealloc(void *p) {
  CkFreeMsg(p);
}
void* CMessage_toNeighborMsg::pack(toNeighborMsg *msg) {
  msg->data = (int *) ((char *)msg->data - (char *)msg);
  return (void *) msg;
}
toNeighborMsg* CMessage_toNeighborMsg::unpack(void* buf) {
  toNeighborMsg *msg = (toNeighborMsg *) buf;
  msg->data = (int *) ((size_t)msg->data + (char *)msg);
  return msg;
}
int CMessage_toNeighborMsg::__idx=0;
#endif /* CK_TEMPLATES_ONLY */

/* DEFS: mainchare Main: Chare{
Main(CkArgMsg* impl_msg);
void nextStep(CkReductionMsg* impl_msg);
void terminate(CkReductionMsg* impl_msg);
void resumeIter(void);
};
 */
#ifndef CK_TEMPLATES_ONLY
 int CkIndex_Main::__idx=0;
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
/* DEFS: Main(CkArgMsg* impl_msg);
 */

CkChareID CProxy_Main::ckNew(CkArgMsg* impl_msg, int impl_onPE)
{
  CkChareID impl_ret;
  CkCreateChare(CkIndex_Main::__idx, CkIndex_Main::idx_Main_CkArgMsg(), impl_msg, &impl_ret, impl_onPE);
  return impl_ret;
}

void CProxy_Main::ckNew(CkArgMsg* impl_msg, CkChareID* pcid, int impl_onPE)
{
  CkCreateChare(CkIndex_Main::__idx, CkIndex_Main::idx_Main_CkArgMsg(), impl_msg, pcid, impl_onPE);
}

  CProxy_Main::CProxy_Main(CkArgMsg* impl_msg, int impl_onPE)
{
  CkChareID impl_ret;
  CkCreateChare(CkIndex_Main::__idx, CkIndex_Main::idx_Main_CkArgMsg(), impl_msg, &impl_ret, impl_onPE);
  ckSetChareID(impl_ret);
}

// Entry point registration function

int CkIndex_Main::reg_Main_CkArgMsg() {
  int epidx = CkRegisterEp("Main(CkArgMsg* impl_msg)",
      _call_Main_CkArgMsg, CMessage_CkArgMsg::__idx, __idx, 0);
  return epidx;
}


void CkIndex_Main::_call_Main_CkArgMsg(void* impl_msg, void* impl_obj_void)
{
  Main* impl_obj = static_cast<Main *>(impl_obj_void);
  new (impl_obj) Main((CkArgMsg*)impl_msg);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void nextStep(CkReductionMsg* impl_msg);
 */

void CProxy_Main::nextStep(CkReductionMsg* impl_msg)
{
  ckCheck();
  if (ckIsDelegated()) {
    int destPE=CkChareMsgPrep(CkIndex_Main::idx_nextStep_CkReductionMsg(), impl_msg, &ckGetChareID());
    if (destPE!=-1) ckDelegatedTo()->ChareSend(ckDelegatedPtr(),CkIndex_Main::idx_nextStep_CkReductionMsg(), impl_msg, &ckGetChareID(),destPE);
  }
  else CkSendMsg(CkIndex_Main::idx_nextStep_CkReductionMsg(), impl_msg, &ckGetChareID(),0);
}

// Entry point registration function

int CkIndex_Main::reg_nextStep_CkReductionMsg() {
  int epidx = CkRegisterEp("nextStep(CkReductionMsg* impl_msg)",
      _call_nextStep_CkReductionMsg, CMessage_CkReductionMsg::__idx, __idx, 0);
  return epidx;
}


void CkIndex_Main::_call_nextStep_CkReductionMsg(void* impl_msg, void* impl_obj_void)
{
  Main* impl_obj = static_cast<Main *>(impl_obj_void);
  impl_obj->nextStep((CkReductionMsg*)impl_msg);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void terminate(CkReductionMsg* impl_msg);
 */

void CProxy_Main::terminate(CkReductionMsg* impl_msg)
{
  ckCheck();
  if (ckIsDelegated()) {
    int destPE=CkChareMsgPrep(CkIndex_Main::idx_terminate_CkReductionMsg(), impl_msg, &ckGetChareID());
    if (destPE!=-1) ckDelegatedTo()->ChareSend(ckDelegatedPtr(),CkIndex_Main::idx_terminate_CkReductionMsg(), impl_msg, &ckGetChareID(),destPE);
  }
  else CkSendMsg(CkIndex_Main::idx_terminate_CkReductionMsg(), impl_msg, &ckGetChareID(),0);
}

// Entry point registration function

int CkIndex_Main::reg_terminate_CkReductionMsg() {
  int epidx = CkRegisterEp("terminate(CkReductionMsg* impl_msg)",
      _call_terminate_CkReductionMsg, CMessage_CkReductionMsg::__idx, __idx, 0);
  return epidx;
}


void CkIndex_Main::_call_terminate_CkReductionMsg(void* impl_msg, void* impl_obj_void)
{
  Main* impl_obj = static_cast<Main *>(impl_obj_void);
  impl_obj->terminate((CkReductionMsg*)impl_msg);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void resumeIter(void);
 */

void CProxy_Main::resumeIter(void)
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg();
  if (ckIsDelegated()) {
    int destPE=CkChareMsgPrep(CkIndex_Main::idx_resumeIter_void(), impl_msg, &ckGetChareID());
    if (destPE!=-1) ckDelegatedTo()->ChareSend(ckDelegatedPtr(),CkIndex_Main::idx_resumeIter_void(), impl_msg, &ckGetChareID(),destPE);
  }
  else CkSendMsg(CkIndex_Main::idx_resumeIter_void(), impl_msg, &ckGetChareID(),0);
}

// Entry point registration function

int CkIndex_Main::reg_resumeIter_void() {
  int epidx = CkRegisterEp("resumeIter(void)",
      _call_resumeIter_void, 0, __idx, 0);
  return epidx;
}


void CkIndex_Main::_call_resumeIter_void(void* impl_msg, void* impl_obj_void)
{
  Main* impl_obj = static_cast<Main *>(impl_obj_void);
  CkFreeSysMsg(impl_msg);
  impl_obj->resumeIter();
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
void CkIndex_Main::__register(const char *s, size_t size) {
  __idx = CkRegisterChare(s, size, TypeMainChare);
  CkRegisterBase(__idx, CkIndex_Chare::__idx);
  // REG: Main(CkArgMsg* impl_msg);
  idx_Main_CkArgMsg();
  CkRegisterMainChare(__idx, idx_Main_CkArgMsg());

  // REG: void nextStep(CkReductionMsg* impl_msg);
  idx_nextStep_CkReductionMsg();

  // REG: void terminate(CkReductionMsg* impl_msg);
  idx_terminate_CkReductionMsg();

  // REG: void resumeIter(void);
  idx_resumeIter_void();

}
#endif /* CK_TEMPLATES_ONLY */

/* DEFS: array Block: ArrayElement{
Block(CkMigrateMessage* impl_msg);
Block(void);
void commWithNeighbors(void);
void recvReplies(toNeighborMsg* impl_msg);
void recvMsgs(toNeighborMsg* impl_msg);
void pauseForLB(void);
};
 */
#ifndef CK_TEMPLATES_ONLY
 int CkIndex_Block::__idx=0;
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
/* DEFS: Block(CkMigrateMessage* impl_msg);
 */
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: Block(void);
 */

void CProxyElement_Block::insert(int onPE)
{ 
  void *impl_msg = CkAllocSysMsg();
   ckInsert((CkArrayMessage *)impl_msg,CkIndex_Block::idx_Block_void(),onPE);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void commWithNeighbors(void);
 */

void CProxyElement_Block::commWithNeighbors(void) 
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg();
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Block::idx_commWithNeighbors_void(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void recvReplies(toNeighborMsg* impl_msg);
 */

void CProxyElement_Block::recvReplies(toNeighborMsg* impl_msg) 
{
  ckCheck();
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Block::idx_recvReplies_toNeighborMsg(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void recvMsgs(toNeighborMsg* impl_msg);
 */

void CProxyElement_Block::recvMsgs(toNeighborMsg* impl_msg) 
{
  ckCheck();
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Block::idx_recvMsgs_toNeighborMsg(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void pauseForLB(void);
 */

void CProxyElement_Block::pauseForLB(void) 
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg();
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Block::idx_pauseForLB_void(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: Block(CkMigrateMessage* impl_msg);
 */

// Entry point registration function

int CkIndex_Block::reg_Block_CkMigrateMessage() {
  int epidx = CkRegisterEp("Block(CkMigrateMessage* impl_msg)",
      _call_Block_CkMigrateMessage, 0, __idx, 0);
  return epidx;
}


void CkIndex_Block::_call_Block_CkMigrateMessage(void* impl_msg, void* impl_obj_void)
{
  Block* impl_obj = static_cast<Block *>(impl_obj_void);
  new (impl_obj) Block((CkMigrateMessage*)impl_msg);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: Block(void);
 */

CkArrayID CProxy_Block::ckNew(const CkArrayOptions &opts)
{ 
  void *impl_msg = CkAllocSysMsg();
   return ckCreateArray((CkArrayMessage *)impl_msg,CkIndex_Block::idx_Block_void(),opts);
}

CkArrayID CProxy_Block::ckNew(const int s1)
{ 
  void *impl_msg = CkAllocSysMsg();
   return ckCreateArray((CkArrayMessage *)impl_msg,CkIndex_Block::idx_Block_void(),CkArrayOptions(s1));
}

// Entry point registration function

int CkIndex_Block::reg_Block_void() {
  int epidx = CkRegisterEp("Block(void)",
      _call_Block_void, 0, __idx, 0);
  return epidx;
}


void CkIndex_Block::_call_Block_void(void* impl_msg, void* impl_obj_void)
{
  Block* impl_obj = static_cast<Block *>(impl_obj_void);
  CkFreeSysMsg(impl_msg);
  new (impl_obj) Block();
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void commWithNeighbors(void);
 */

void CProxy_Block::commWithNeighbors(void) 
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg();
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckBroadcast(impl_amsg, CkIndex_Block::idx_commWithNeighbors_void(),0);
}

// Entry point registration function

int CkIndex_Block::reg_commWithNeighbors_void() {
  int epidx = CkRegisterEp("commWithNeighbors(void)",
      _call_commWithNeighbors_void, 0, __idx, 0);
  return epidx;
}


void CkIndex_Block::_call_commWithNeighbors_void(void* impl_msg, void* impl_obj_void)
{
  Block* impl_obj = static_cast<Block *>(impl_obj_void);
  CkFreeSysMsg(impl_msg);
  impl_obj->commWithNeighbors();
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void recvReplies(toNeighborMsg* impl_msg);
 */

void CProxy_Block::recvReplies(toNeighborMsg* impl_msg) 
{
  ckCheck();
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckBroadcast(impl_amsg, CkIndex_Block::idx_recvReplies_toNeighborMsg(),0);
}

// Entry point registration function

int CkIndex_Block::reg_recvReplies_toNeighborMsg() {
  int epidx = CkRegisterEp("recvReplies(toNeighborMsg* impl_msg)",
      _call_recvReplies_toNeighborMsg, CMessage_toNeighborMsg::__idx, __idx, 0);
  return epidx;
}


void CkIndex_Block::_call_recvReplies_toNeighborMsg(void* impl_msg, void* impl_obj_void)
{
  Block* impl_obj = static_cast<Block *>(impl_obj_void);
  impl_obj->recvReplies((toNeighborMsg*)impl_msg);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void recvMsgs(toNeighborMsg* impl_msg);
 */

void CProxy_Block::recvMsgs(toNeighborMsg* impl_msg) 
{
  ckCheck();
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckBroadcast(impl_amsg, CkIndex_Block::idx_recvMsgs_toNeighborMsg(),0);
}

// Entry point registration function

int CkIndex_Block::reg_recvMsgs_toNeighborMsg() {
  int epidx = CkRegisterEp("recvMsgs(toNeighborMsg* impl_msg)",
      _call_recvMsgs_toNeighborMsg, CMessage_toNeighborMsg::__idx, __idx, 0);
  return epidx;
}


void CkIndex_Block::_call_recvMsgs_toNeighborMsg(void* impl_msg, void* impl_obj_void)
{
  Block* impl_obj = static_cast<Block *>(impl_obj_void);
  impl_obj->recvMsgs((toNeighborMsg*)impl_msg);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void pauseForLB(void);
 */

void CProxy_Block::pauseForLB(void) 
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg();
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckBroadcast(impl_amsg, CkIndex_Block::idx_pauseForLB_void(),0);
}

// Entry point registration function

int CkIndex_Block::reg_pauseForLB_void() {
  int epidx = CkRegisterEp("pauseForLB(void)",
      _call_pauseForLB_void, 0, __idx, 0);
  return epidx;
}


void CkIndex_Block::_call_pauseForLB_void(void* impl_msg, void* impl_obj_void)
{
  Block* impl_obj = static_cast<Block *>(impl_obj_void);
  CkFreeSysMsg(impl_msg);
  impl_obj->pauseForLB();
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: Block(CkMigrateMessage* impl_msg);
 */
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: Block(void);
 */
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void commWithNeighbors(void);
 */

void CProxySection_Block::commWithNeighbors(void) 
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg();
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Block::idx_commWithNeighbors_void(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void recvReplies(toNeighborMsg* impl_msg);
 */

void CProxySection_Block::recvReplies(toNeighborMsg* impl_msg) 
{
  ckCheck();
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Block::idx_recvReplies_toNeighborMsg(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void recvMsgs(toNeighborMsg* impl_msg);
 */

void CProxySection_Block::recvMsgs(toNeighborMsg* impl_msg) 
{
  ckCheck();
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Block::idx_recvMsgs_toNeighborMsg(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void pauseForLB(void);
 */

void CProxySection_Block::pauseForLB(void) 
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg();
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Block::idx_pauseForLB_void(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
void CkIndex_Block::__register(const char *s, size_t size) {
  __idx = CkRegisterChare(s, size, TypeArray);
  CkRegisterBase(__idx, CkIndex_ArrayElement::__idx);
  // REG: Block(CkMigrateMessage* impl_msg);
  idx_Block_CkMigrateMessage();
  CkRegisterMigCtor(__idx, idx_Block_CkMigrateMessage());

  // REG: Block(void);
  idx_Block_void();
  CkRegisterDefaultCtor(__idx, idx_Block_void());

  // REG: void commWithNeighbors(void);
  idx_commWithNeighbors_void();

  // REG: void recvReplies(toNeighborMsg* impl_msg);
  idx_recvReplies_toNeighborMsg();

  // REG: void recvMsgs(toNeighborMsg* impl_msg);
  idx_recvMsgs_toNeighborMsg();

  // REG: void pauseForLB(void);
  idx_pauseForLB_void();

}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
void _registerkNeighbor(void)
{
  static int _done = 0; if(_done) return; _done = 1;
  CkRegisterReadonly("mainProxy","CProxy_Main",sizeof(mainProxy),(void *) &mainProxy,__xlater_roPup_mainProxy);

  CkRegisterReadonly("num_chares","int",sizeof(num_chares),(void *) &num_chares,__xlater_roPup_num_chares);

  CkRegisterReadonly("gMsgSize","int",sizeof(gMsgSize),(void *) &gMsgSize,__xlater_roPup_gMsgSize);

  CkRegisterReadonly("gLBFreq","int",sizeof(gLBFreq),(void *) &gLBFreq,__xlater_roPup_gLBFreq);

  CkRegisterReadonly("amt_work","int",sizeof(amt_work),(void *) &amt_work,__xlater_roPup_amt_work);

/* REG: message toNeighborMsg{
int data[];
}
;
*/
CMessage_toNeighborMsg::__register("toNeighborMsg", sizeof(toNeighborMsg),(CkPackFnPtr) toNeighborMsg::pack,(CkUnpackFnPtr) toNeighborMsg::unpack);

/* REG: mainchare Main: Chare{
Main(CkArgMsg* impl_msg);
void nextStep(CkReductionMsg* impl_msg);
void terminate(CkReductionMsg* impl_msg);
void resumeIter(void);
};
*/
  CkIndex_Main::__register("Main", sizeof(Main));

/* REG: array Block: ArrayElement{
Block(CkMigrateMessage* impl_msg);
Block(void);
void commWithNeighbors(void);
void recvReplies(toNeighborMsg* impl_msg);
void recvMsgs(toNeighborMsg* impl_msg);
void pauseForLB(void);
};
*/
  CkIndex_Block::__register("Block", sizeof(Block));

}
extern "C" void CkRegisterMainModule(void) {
  _registerkNeighbor();
}
#endif /* CK_TEMPLATES_ONLY */
