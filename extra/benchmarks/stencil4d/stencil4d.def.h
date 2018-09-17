/* DEFS: readonly CProxy_Main mainProxy;
 */
extern CProxy_Main mainProxy;
#ifndef CK_TEMPLATES_ONLY
extern "C" void __xlater_roPup_mainProxy(void *_impl_pup_er) {
  PUP::er &_impl_p=*(PUP::er *)_impl_pup_er;
  _impl_p|mainProxy;
}
#endif /* CK_TEMPLATES_ONLY */

/* DEFS: readonly int arrayDimW;
 */
extern int arrayDimW;
#ifndef CK_TEMPLATES_ONLY
extern "C" void __xlater_roPup_arrayDimW(void *_impl_pup_er) {
  PUP::er &_impl_p=*(PUP::er *)_impl_pup_er;
  _impl_p|arrayDimW;
}
#endif /* CK_TEMPLATES_ONLY */

/* DEFS: readonly int arrayDimX;
 */
extern int arrayDimX;
#ifndef CK_TEMPLATES_ONLY
extern "C" void __xlater_roPup_arrayDimX(void *_impl_pup_er) {
  PUP::er &_impl_p=*(PUP::er *)_impl_pup_er;
  _impl_p|arrayDimX;
}
#endif /* CK_TEMPLATES_ONLY */

/* DEFS: readonly int arrayDimY;
 */
extern int arrayDimY;
#ifndef CK_TEMPLATES_ONLY
extern "C" void __xlater_roPup_arrayDimY(void *_impl_pup_er) {
  PUP::er &_impl_p=*(PUP::er *)_impl_pup_er;
  _impl_p|arrayDimY;
}
#endif /* CK_TEMPLATES_ONLY */

/* DEFS: readonly int arrayDimZ;
 */
extern int arrayDimZ;
#ifndef CK_TEMPLATES_ONLY
extern "C" void __xlater_roPup_arrayDimZ(void *_impl_pup_er) {
  PUP::er &_impl_p=*(PUP::er *)_impl_pup_er;
  _impl_p|arrayDimZ;
}
#endif /* CK_TEMPLATES_ONLY */

/* DEFS: readonly int blockDimW;
 */
extern int blockDimW;
#ifndef CK_TEMPLATES_ONLY
extern "C" void __xlater_roPup_blockDimW(void *_impl_pup_er) {
  PUP::er &_impl_p=*(PUP::er *)_impl_pup_er;
  _impl_p|blockDimW;
}
#endif /* CK_TEMPLATES_ONLY */

/* DEFS: readonly int blockDimX;
 */
extern int blockDimX;
#ifndef CK_TEMPLATES_ONLY
extern "C" void __xlater_roPup_blockDimX(void *_impl_pup_er) {
  PUP::er &_impl_p=*(PUP::er *)_impl_pup_er;
  _impl_p|blockDimX;
}
#endif /* CK_TEMPLATES_ONLY */

/* DEFS: readonly int blockDimY;
 */
extern int blockDimY;
#ifndef CK_TEMPLATES_ONLY
extern "C" void __xlater_roPup_blockDimY(void *_impl_pup_er) {
  PUP::er &_impl_p=*(PUP::er *)_impl_pup_er;
  _impl_p|blockDimY;
}
#endif /* CK_TEMPLATES_ONLY */

/* DEFS: readonly int blockDimZ;
 */
extern int blockDimZ;
#ifndef CK_TEMPLATES_ONLY
extern "C" void __xlater_roPup_blockDimZ(void *_impl_pup_er) {
  PUP::er &_impl_p=*(PUP::er *)_impl_pup_er;
  _impl_p|blockDimZ;
}
#endif /* CK_TEMPLATES_ONLY */

/* DEFS: readonly int num_chare_w;
 */
extern int num_chare_w;
#ifndef CK_TEMPLATES_ONLY
extern "C" void __xlater_roPup_num_chare_w(void *_impl_pup_er) {
  PUP::er &_impl_p=*(PUP::er *)_impl_pup_er;
  _impl_p|num_chare_w;
}
#endif /* CK_TEMPLATES_ONLY */

/* DEFS: readonly int num_chare_x;
 */
extern int num_chare_x;
#ifndef CK_TEMPLATES_ONLY
extern "C" void __xlater_roPup_num_chare_x(void *_impl_pup_er) {
  PUP::er &_impl_p=*(PUP::er *)_impl_pup_er;
  _impl_p|num_chare_x;
}
#endif /* CK_TEMPLATES_ONLY */

/* DEFS: readonly int num_chare_y;
 */
extern int num_chare_y;
#ifndef CK_TEMPLATES_ONLY
extern "C" void __xlater_roPup_num_chare_y(void *_impl_pup_er) {
  PUP::er &_impl_p=*(PUP::er *)_impl_pup_er;
  _impl_p|num_chare_y;
}
#endif /* CK_TEMPLATES_ONLY */

/* DEFS: readonly int num_chare_z;
 */
extern int num_chare_z;
#ifndef CK_TEMPLATES_ONLY
extern "C" void __xlater_roPup_num_chare_z(void *_impl_pup_er) {
  PUP::er &_impl_p=*(PUP::er *)_impl_pup_er;
  _impl_p|num_chare_z;
}
#endif /* CK_TEMPLATES_ONLY */

/* DEFS: mainchare Main: Chare{
Main(CkArgMsg* impl_msg);
void terminate(void);
void nextStep(CkReductionMsg* impl_msg);
void beginIteration(void);
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
/* DEFS: void terminate(void);
 */

void CProxy_Main::terminate(void)
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg();
  if (ckIsDelegated()) {
    int destPE=CkChareMsgPrep(CkIndex_Main::idx_terminate_void(), impl_msg, &ckGetChareID());
    if (destPE!=-1) ckDelegatedTo()->ChareSend(ckDelegatedPtr(),CkIndex_Main::idx_terminate_void(), impl_msg, &ckGetChareID(),destPE);
  }
  else CkSendMsg(CkIndex_Main::idx_terminate_void(), impl_msg, &ckGetChareID(),0);
}

// Entry point registration function

int CkIndex_Main::reg_terminate_void() {
  int epidx = CkRegisterEp("terminate(void)",
      _call_terminate_void, 0, __idx, 0);
  return epidx;
}


void CkIndex_Main::_call_terminate_void(void* impl_msg, void* impl_obj_void)
{
  Main* impl_obj = static_cast<Main *>(impl_obj_void);
  CkFreeSysMsg(impl_msg);
  impl_obj->terminate();
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
/* DEFS: void beginIteration(void);
 */

void CProxy_Main::beginIteration(void)
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg();
  if (ckIsDelegated()) {
    int destPE=CkChareMsgPrep(CkIndex_Main::idx_beginIteration_void(), impl_msg, &ckGetChareID());
    if (destPE!=-1) ckDelegatedTo()->ChareSend(ckDelegatedPtr(),CkIndex_Main::idx_beginIteration_void(), impl_msg, &ckGetChareID(),destPE);
  }
  else CkSendMsg(CkIndex_Main::idx_beginIteration_void(), impl_msg, &ckGetChareID(),0);
}

// Entry point registration function

int CkIndex_Main::reg_beginIteration_void() {
  int epidx = CkRegisterEp("beginIteration(void)",
      _call_beginIteration_void, 0, __idx, 0);
  return epidx;
}


void CkIndex_Main::_call_beginIteration_void(void* impl_msg, void* impl_obj_void)
{
  Main* impl_obj = static_cast<Main *>(impl_obj_void);
  CkFreeSysMsg(impl_msg);
  impl_obj->beginIteration();
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

  // REG: void terminate(void);
  idx_terminate_void();

  // REG: void nextStep(CkReductionMsg* impl_msg);
  idx_nextStep_CkReductionMsg();

  // REG: void beginIteration(void);
  idx_beginIteration_void();

}
#endif /* CK_TEMPLATES_ONLY */

/* DEFS: array Stencil: ArrayElement{
Stencil(CkMigrateMessage* impl_msg);
Stencil(void);
void begin_iteration(void);
void receiveGhosts(int iter, int dir, int length, int width, int height, const double *ghosts);
void pauseForLB(void);
void doStep(void);
};
 */
#ifndef CK_TEMPLATES_ONLY
 int CkIndex_Stencil::__idx=0;
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
/* DEFS: Stencil(CkMigrateMessage* impl_msg);
 */
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: Stencil(void);
 */

void CProxyElement_Stencil::insert(int onPE)
{ 
  void *impl_msg = CkAllocSysMsg();
   ckInsert((CkArrayMessage *)impl_msg,CkIndex_Stencil::idx_Stencil_void(),onPE);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void begin_iteration(void);
 */

void CProxyElement_Stencil::begin_iteration(void) 
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg();
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Stencil::idx_begin_iteration_void(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void receiveGhosts(int iter, int dir, int length, int width, int height, const double *ghosts);
 */

void CProxyElement_Stencil::receiveGhosts(int iter, int dir, int length, int width, int height, const double *ghosts, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: int iter, int dir, int length, int width, int height, const double *ghosts
  int impl_off=0;
  int impl_arrstart=0;
  int impl_off_ghosts, impl_cnt_ghosts;
  impl_off_ghosts=impl_off=CK_ALIGN(impl_off,sizeof(double));
  impl_off+=(impl_cnt_ghosts=sizeof(double)*(length*height*width));
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|iter;
    implP|dir;
    implP|length;
    implP|width;
    implP|height;
    implP|impl_off_ghosts;
    implP|impl_cnt_ghosts;
    impl_arrstart=CK_ALIGN(implP.size(),16);
    impl_off+=impl_arrstart;
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|iter;
    implP|dir;
    implP|length;
    implP|width;
    implP|height;
    implP|impl_off_ghosts;
    implP|impl_cnt_ghosts;
  }
  char *impl_buf=impl_msg->msgBuf+impl_arrstart;
  memcpy(impl_buf+impl_off_ghosts,ghosts,impl_cnt_ghosts);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Stencil::idx_receiveGhosts_marshall3(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void pauseForLB(void);
 */

void CProxyElement_Stencil::pauseForLB(void) 
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg();
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Stencil::idx_pauseForLB_void(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void doStep(void);
 */

void CProxyElement_Stencil::doStep(void) 
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg();
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Stencil::idx_doStep_void(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: Stencil(CkMigrateMessage* impl_msg);
 */

// Entry point registration function

int CkIndex_Stencil::reg_Stencil_CkMigrateMessage() {
  int epidx = CkRegisterEp("Stencil(CkMigrateMessage* impl_msg)",
      _call_Stencil_CkMigrateMessage, 0, __idx, 0);
  return epidx;
}


void CkIndex_Stencil::_call_Stencil_CkMigrateMessage(void* impl_msg, void* impl_obj_void)
{
  Stencil* impl_obj = static_cast<Stencil *>(impl_obj_void);
  new (impl_obj) Stencil((CkMigrateMessage*)impl_msg);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: Stencil(void);
 */

CkArrayID CProxy_Stencil::ckNew(const CkArrayOptions &opts)
{ 
  void *impl_msg = CkAllocSysMsg();
   return ckCreateArray((CkArrayMessage *)impl_msg,CkIndex_Stencil::idx_Stencil_void(),opts);
}

// Entry point registration function

int CkIndex_Stencil::reg_Stencil_void() {
  int epidx = CkRegisterEp("Stencil(void)",
      _call_Stencil_void, 0, __idx, 0);
  return epidx;
}


void CkIndex_Stencil::_call_Stencil_void(void* impl_msg, void* impl_obj_void)
{
  Stencil* impl_obj = static_cast<Stencil *>(impl_obj_void);
  CkFreeSysMsg(impl_msg);
  new (impl_obj) Stencil();
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void begin_iteration(void);
 */

void CProxy_Stencil::begin_iteration(void) 
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg();
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckBroadcast(impl_amsg, CkIndex_Stencil::idx_begin_iteration_void(),0);
}

// Entry point registration function

int CkIndex_Stencil::reg_begin_iteration_void() {
  int epidx = CkRegisterEp("begin_iteration(void)",
      _call_begin_iteration_void, 0, __idx, 0);
  return epidx;
}


void CkIndex_Stencil::_call_begin_iteration_void(void* impl_msg, void* impl_obj_void)
{
  Stencil* impl_obj = static_cast<Stencil *>(impl_obj_void);
  CkFreeSysMsg(impl_msg);
  impl_obj->begin_iteration();
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void receiveGhosts(int iter, int dir, int length, int width, int height, const double *ghosts);
 */

void CProxy_Stencil::receiveGhosts(int iter, int dir, int length, int width, int height, const double *ghosts, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: int iter, int dir, int length, int width, int height, const double *ghosts
  int impl_off=0;
  int impl_arrstart=0;
  int impl_off_ghosts, impl_cnt_ghosts;
  impl_off_ghosts=impl_off=CK_ALIGN(impl_off,sizeof(double));
  impl_off+=(impl_cnt_ghosts=sizeof(double)*(length*height*width));
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|iter;
    implP|dir;
    implP|length;
    implP|width;
    implP|height;
    implP|impl_off_ghosts;
    implP|impl_cnt_ghosts;
    impl_arrstart=CK_ALIGN(implP.size(),16);
    impl_off+=impl_arrstart;
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|iter;
    implP|dir;
    implP|length;
    implP|width;
    implP|height;
    implP|impl_off_ghosts;
    implP|impl_cnt_ghosts;
  }
  char *impl_buf=impl_msg->msgBuf+impl_arrstart;
  memcpy(impl_buf+impl_off_ghosts,ghosts,impl_cnt_ghosts);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckBroadcast(impl_amsg, CkIndex_Stencil::idx_receiveGhosts_marshall3(),0);
}

// Entry point registration function

int CkIndex_Stencil::reg_receiveGhosts_marshall3() {
  int epidx = CkRegisterEp("receiveGhosts(int iter, int dir, int length, int width, int height, const double *ghosts)",
      _call_receiveGhosts_marshall3, CkMarshallMsg::__idx, __idx, 0+CK_EP_NOKEEP);
  CkRegisterMarshallUnpackFn(epidx, _callmarshall_receiveGhosts_marshall3);
  CkRegisterMessagePupFn(epidx, _marshallmessagepup_receiveGhosts_marshall3);

  return epidx;
}


void CkIndex_Stencil::_call_receiveGhosts_marshall3(void* impl_msg, void* impl_obj_void)
{
  Stencil* impl_obj = static_cast<Stencil *>(impl_obj_void);
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: int iter, int dir, int length, int width, int height, const double *ghosts*/
  PUP::fromMem implP(impl_buf);
  int iter; implP|iter;
  int dir; implP|dir;
  int length; implP|length;
  int width; implP|width;
  int height; implP|height;
  int impl_off_ghosts, impl_cnt_ghosts; 
  implP|impl_off_ghosts;
  implP|impl_cnt_ghosts;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  double *ghosts=(double *)(impl_buf+impl_off_ghosts);
  impl_obj->receiveGhosts(iter, dir, length, width, height, ghosts);
}

int CkIndex_Stencil::_callmarshall_receiveGhosts_marshall3(char* impl_buf, void* impl_obj_void) {
  Stencil* impl_obj = static_cast< Stencil *>(impl_obj_void);
  /*Unmarshall pup'd fields: int iter, int dir, int length, int width, int height, const double *ghosts*/
  PUP::fromMem implP(impl_buf);
  int iter; implP|iter;
  int dir; implP|dir;
  int length; implP|length;
  int width; implP|width;
  int height; implP|height;
  int impl_off_ghosts, impl_cnt_ghosts; 
  implP|impl_off_ghosts;
  implP|impl_cnt_ghosts;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  double *ghosts=(double *)(impl_buf+impl_off_ghosts);
  impl_obj->receiveGhosts(iter, dir, length, width, height, ghosts);
  return implP.size();
}

void CkIndex_Stencil::_marshallmessagepup_receiveGhosts_marshall3(PUP::er &implDestP,void *impl_msg) {
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: int iter, int dir, int length, int width, int height, const double *ghosts*/
  PUP::fromMem implP(impl_buf);
  int iter; implP|iter;
  int dir; implP|dir;
  int length; implP|length;
  int width; implP|width;
  int height; implP|height;
  int impl_off_ghosts, impl_cnt_ghosts; 
  implP|impl_off_ghosts;
  implP|impl_cnt_ghosts;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  double *ghosts=(double *)(impl_buf+impl_off_ghosts);
  if (implDestP.hasComments()) implDestP.comment("iter");
  implDestP|iter;
  if (implDestP.hasComments()) implDestP.comment("dir");
  implDestP|dir;
  if (implDestP.hasComments()) implDestP.comment("length");
  implDestP|length;
  if (implDestP.hasComments()) implDestP.comment("width");
  implDestP|width;
  if (implDestP.hasComments()) implDestP.comment("height");
  implDestP|height;
  if (implDestP.hasComments()) implDestP.comment("ghosts");
  implDestP.synchronize(PUP::sync_begin_array);
  { for (int impl_i=0;impl_i*(sizeof(*ghosts))<impl_cnt_ghosts;impl_i++) { 
      implDestP.synchronize(PUP::sync_item);
      implDestP|ghosts[impl_i];
  } } 
  implDestP.synchronize(PUP::sync_end_array);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void pauseForLB(void);
 */

void CProxy_Stencil::pauseForLB(void) 
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg();
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckBroadcast(impl_amsg, CkIndex_Stencil::idx_pauseForLB_void(),0);
}

// Entry point registration function

int CkIndex_Stencil::reg_pauseForLB_void() {
  int epidx = CkRegisterEp("pauseForLB(void)",
      _call_pauseForLB_void, 0, __idx, 0);
  return epidx;
}


void CkIndex_Stencil::_call_pauseForLB_void(void* impl_msg, void* impl_obj_void)
{
  Stencil* impl_obj = static_cast<Stencil *>(impl_obj_void);
  CkFreeSysMsg(impl_msg);
  impl_obj->pauseForLB();
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void doStep(void);
 */

void CProxy_Stencil::doStep(void) 
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg();
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckBroadcast(impl_amsg, CkIndex_Stencil::idx_doStep_void(),0);
}

// Entry point registration function

int CkIndex_Stencil::reg_doStep_void() {
  int epidx = CkRegisterEp("doStep(void)",
      _call_doStep_void, 0, __idx, 0);
  return epidx;
}


void CkIndex_Stencil::_call_doStep_void(void* impl_msg, void* impl_obj_void)
{
  Stencil* impl_obj = static_cast<Stencil *>(impl_obj_void);
  CkFreeSysMsg(impl_msg);
  impl_obj->doStep();
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: Stencil(CkMigrateMessage* impl_msg);
 */
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: Stencil(void);
 */
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void begin_iteration(void);
 */

void CProxySection_Stencil::begin_iteration(void) 
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg();
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Stencil::idx_begin_iteration_void(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void receiveGhosts(int iter, int dir, int length, int width, int height, const double *ghosts);
 */

void CProxySection_Stencil::receiveGhosts(int iter, int dir, int length, int width, int height, const double *ghosts, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: int iter, int dir, int length, int width, int height, const double *ghosts
  int impl_off=0;
  int impl_arrstart=0;
  int impl_off_ghosts, impl_cnt_ghosts;
  impl_off_ghosts=impl_off=CK_ALIGN(impl_off,sizeof(double));
  impl_off+=(impl_cnt_ghosts=sizeof(double)*(length*height*width));
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|iter;
    implP|dir;
    implP|length;
    implP|width;
    implP|height;
    implP|impl_off_ghosts;
    implP|impl_cnt_ghosts;
    impl_arrstart=CK_ALIGN(implP.size(),16);
    impl_off+=impl_arrstart;
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|iter;
    implP|dir;
    implP|length;
    implP|width;
    implP|height;
    implP|impl_off_ghosts;
    implP|impl_cnt_ghosts;
  }
  char *impl_buf=impl_msg->msgBuf+impl_arrstart;
  memcpy(impl_buf+impl_off_ghosts,ghosts,impl_cnt_ghosts);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Stencil::idx_receiveGhosts_marshall3(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void pauseForLB(void);
 */

void CProxySection_Stencil::pauseForLB(void) 
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg();
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Stencil::idx_pauseForLB_void(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void doStep(void);
 */

void CProxySection_Stencil::doStep(void) 
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg();
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Stencil::idx_doStep_void(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
void CkIndex_Stencil::__register(const char *s, size_t size) {
  __idx = CkRegisterChare(s, size, TypeArray);
  CkRegisterBase(__idx, CkIndex_ArrayElement::__idx);
  // REG: Stencil(CkMigrateMessage* impl_msg);
  idx_Stencil_CkMigrateMessage();
  CkRegisterMigCtor(__idx, idx_Stencil_CkMigrateMessage());

  // REG: Stencil(void);
  idx_Stencil_void();
  CkRegisterDefaultCtor(__idx, idx_Stencil_void());

  // REG: void begin_iteration(void);
  idx_begin_iteration_void();

  // REG: void receiveGhosts(int iter, int dir, int length, int width, int height, const double *ghosts);
  idx_receiveGhosts_marshall3();

  // REG: void pauseForLB(void);
  idx_pauseForLB_void();

  // REG: void doStep(void);
  idx_doStep_void();

  Stencil::__sdag_register(); 
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
void Stencil::doStep() {
    _TRACE_END_EXECUTE(); 
    _slist_0();
    _TRACE_BEGIN_EXECUTE_DETAILED(-1, -1, _dummyEP, CkMyPe(), 0, NULL); 
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Stencil::doStep_end() {
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Stencil::_slist_0() {
    _atomic_0();
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Stencil::_slist_0_end() {
    doStep_end();
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Stencil::_atomic_0() {
    _TRACE_BEGIN_EXECUTE_DETAILED(-1, -1, (_sdag_idx_Stencil_begin_iteration()), CkMyPe(), 0, NULL); 
    
	begin_iteration();
      
    _TRACE_END_EXECUTE(); 
    _for_0();
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Stencil::_for_0() {
    imsg = 0;
    if ( imsg < 8) {
      _slist_1();
    } else {
      _atomic_2();
    }
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Stencil::_for_0_end() {
    imsg++;
    if ( imsg < 8) {
      _slist_1();
    } else {
      _atomic_2();
    }
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Stencil::_slist_1() {
    _when_0();
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Stencil::_slist_1_end() {
    _for_0_end();
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
int Stencil::_when_0() {
    CMsgBuffer *receiveGhosts_buf;
    CkMarshallMsg *receiveGhosts_msg;

    receiveGhosts_buf = __cDep->getMessage(0, iterations); // SEGFAULT? __cDep = 0x0? Did you call __sdag_init() in your constructor?

    if ((receiveGhosts_buf != 0)) {
       receiveGhosts_msg = (CkMarshallMsg *)receiveGhosts_buf->msg;
       char *receiveGhosts_impl_buf=((CkMarshallMsg *)receiveGhosts_msg)->msgBuf;
       PUP::fromMem receiveGhosts_implP(receiveGhosts_impl_buf);
       int iter; receiveGhosts_implP|iter;
       int dir; receiveGhosts_implP|dir;
       int length; receiveGhosts_implP|length;
       int width; receiveGhosts_implP|width;
       int height; receiveGhosts_implP|height;
       int impl_off_ghosts; receiveGhosts_implP|impl_off_ghosts;
       receiveGhosts_impl_buf+=CK_ALIGN(receiveGhosts_implP.size(),16);
       double *ghosts=(double *)(receiveGhosts_impl_buf+impl_off_ghosts);
       __cDep->removeMessage(receiveGhosts_buf);
       delete receiveGhosts_buf;
       _atomic_1(iter, dir, length, width, height, ghosts);
       delete receiveGhosts_msg;
       return 1;
    } else {
       CWhenTrigger *tr;
       tr = new CWhenTrigger(0, 1, 1, 0);
       tr->args[0] = (size_t)0xFF;
       tr->entries[0] = 0;
       tr->refnums[0] = iterations;
       __cDep->Register(tr);
       return 0;
    }
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Stencil::_when_0_end(int iter, int dir, int length, int width, int height, double * ghosts) {
    _slist_1_end();
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Stencil::_atomic_1(int iter, int dir, int length, int width, int height, double * ghosts) {
    _TRACE_BEGIN_EXECUTE_DETAILED(-1, -1, (_sdag_idx_Stencil_process_ghosts()), CkMyPe(), 0, NULL); 
    
            processGhosts(dir, length, width, height, ghosts);
          
    _TRACE_END_EXECUTE(); 
    _when_0_end(iter, dir, length, width, height, ghosts);
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Stencil::_atomic_2() {
    _TRACE_BEGIN_EXECUTE_DETAILED(-1, -1, (_sdag_idx_Stencil_do_work()), CkMyPe(), 0, NULL); 
    
	check_and_compute();
      
    _TRACE_END_EXECUTE(); 
    _slist_0_end();
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Stencil::receiveGhosts(int iter, int dir, int length, int width, int height, double *ghosts){
    CWhenTrigger *tr;
    void* _bgParentLog = NULL;
    CMsgBuffer* cmsgbuf;
    int impl_off=0; int impl_arrstart=0;
    int impl_off_ghosts, impl_cnt_ghosts;
    impl_off_ghosts=impl_off=CK_ALIGN(impl_off,sizeof(double));
    impl_off+=(impl_cnt_ghosts=sizeof(double)*(length*height*width));
    {
      PUP::sizer implP1;
      implP1|iter;
      implP1|dir;
      implP1|length;
      implP1|width;
      implP1|height;
      implP1|impl_off_ghosts;
      impl_arrstart=CK_ALIGN(implP1.size(),16);
      impl_off+=impl_arrstart;
    }
    CkMarshallMsg *impl_msg1=CkAllocateMarshallMsg(impl_off,NULL);
    {
      PUP::toMem implP1((void *)impl_msg1->msgBuf);
      implP1|iter;
      implP1|dir;
      implP1|length;
      implP1|width;
      implP1|height;
      implP1|impl_off_ghosts;
    }
    char *impl_buf1=impl_msg1->msgBuf+impl_arrstart;
    memcpy(impl_buf1+impl_off_ghosts,ghosts,impl_cnt_ghosts);
    cmsgbuf = __cDep->bufferMessage(0, (void *) impl_msg1, (void*) _bgParentLog, iter);
    tr = __cDep->getTrigger(0, iter);
    if (tr == 0)
      return;
    _TRACE_END_EXECUTE(); 
    {
        tr->args[0] = 0;
        _when_0();
        delete tr;
        _TRACE_BEGIN_EXECUTE_DETAILED(-1, -1, _dummyEP, CkMyPe(), 0, NULL); 
        return;
    }
}

#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
void Stencil::__sdag_init() {
    __cDep = new CDep(1,1);
    __cDep->addDepends(0,0);
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Stencil::__sdag_register() {
    (void)_sdag_idx_Stencil_begin_iteration();
    (void)_sdag_idx_Stencil_process_ghosts();
    (void)_sdag_idx_Stencil_do_work();
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
int Stencil::_sdag_idx_Stencil_begin_iteration() {
  static int epidx = _sdag_reg_Stencil_begin_iteration();
  return epidx;
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
int Stencil::_sdag_reg_Stencil_begin_iteration() {
  return CkRegisterEp("Stencil_begin_iteration", NULL, 0, CkIndex_Stencil::__idx, 0);
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
int Stencil::_sdag_idx_Stencil_process_ghosts() {
  static int epidx = _sdag_reg_Stencil_process_ghosts();
  return epidx;
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
int Stencil::_sdag_reg_Stencil_process_ghosts() {
  return CkRegisterEp("Stencil_process_ghosts", NULL, 0, CkIndex_Stencil::__idx, 0);
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
int Stencil::_sdag_idx_Stencil_do_work() {
  static int epidx = _sdag_reg_Stencil_do_work();
  return epidx;
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
int Stencil::_sdag_reg_Stencil_do_work() {
  return CkRegisterEp("Stencil_do_work", NULL, 0, CkIndex_Stencil::__idx, 0);
}
#endif /* CK_TEMPLATES_ONLY */



#ifndef CK_TEMPLATES_ONLY
void _registerstencil4d(void)
{
  static int _done = 0; if(_done) return; _done = 1;
  CkRegisterReadonly("mainProxy","CProxy_Main",sizeof(mainProxy),(void *) &mainProxy,__xlater_roPup_mainProxy);

  CkRegisterReadonly("arrayDimW","int",sizeof(arrayDimW),(void *) &arrayDimW,__xlater_roPup_arrayDimW);

  CkRegisterReadonly("arrayDimX","int",sizeof(arrayDimX),(void *) &arrayDimX,__xlater_roPup_arrayDimX);

  CkRegisterReadonly("arrayDimY","int",sizeof(arrayDimY),(void *) &arrayDimY,__xlater_roPup_arrayDimY);

  CkRegisterReadonly("arrayDimZ","int",sizeof(arrayDimZ),(void *) &arrayDimZ,__xlater_roPup_arrayDimZ);

  CkRegisterReadonly("blockDimW","int",sizeof(blockDimW),(void *) &blockDimW,__xlater_roPup_blockDimW);

  CkRegisterReadonly("blockDimX","int",sizeof(blockDimX),(void *) &blockDimX,__xlater_roPup_blockDimX);

  CkRegisterReadonly("blockDimY","int",sizeof(blockDimY),(void *) &blockDimY,__xlater_roPup_blockDimY);

  CkRegisterReadonly("blockDimZ","int",sizeof(blockDimZ),(void *) &blockDimZ,__xlater_roPup_blockDimZ);

  CkRegisterReadonly("num_chare_w","int",sizeof(num_chare_w),(void *) &num_chare_w,__xlater_roPup_num_chare_w);

  CkRegisterReadonly("num_chare_x","int",sizeof(num_chare_x),(void *) &num_chare_x,__xlater_roPup_num_chare_x);

  CkRegisterReadonly("num_chare_y","int",sizeof(num_chare_y),(void *) &num_chare_y,__xlater_roPup_num_chare_y);

  CkRegisterReadonly("num_chare_z","int",sizeof(num_chare_z),(void *) &num_chare_z,__xlater_roPup_num_chare_z);

/* REG: mainchare Main: Chare{
Main(CkArgMsg* impl_msg);
void terminate(void);
void nextStep(CkReductionMsg* impl_msg);
void beginIteration(void);
};
*/
  CkIndex_Main::__register("Main", sizeof(Main));

/* REG: array Stencil: ArrayElement{
Stencil(CkMigrateMessage* impl_msg);
Stencil(void);
void begin_iteration(void);
void receiveGhosts(int iter, int dir, int length, int width, int height, const double *ghosts);
void pauseForLB(void);
void doStep(void);
};
*/
  CkIndex_Stencil::__register("Stencil", sizeof(Stencil));

}
extern "C" void CkRegisterMainModule(void) {
  _registerstencil4d();
}
#endif /* CK_TEMPLATES_ONLY */
