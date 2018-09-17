/* DEFS: readonly CProxy_Main mainProxy;
 */
extern CProxy_Main mainProxy;
#ifndef CK_TEMPLATES_ONLY
extern "C" void __xlater_roPup_mainProxy(void *_impl_pup_er) {
  PUP::er &_impl_p=*(PUP::er *)_impl_pup_er;
  _impl_p|mainProxy;
}
#endif /* CK_TEMPLATES_ONLY */

/* DEFS: readonly CProxy_Cell cellArray;
 */
extern CProxy_Cell cellArray;
#ifndef CK_TEMPLATES_ONLY
extern "C" void __xlater_roPup_cellArray(void *_impl_pup_er) {
  PUP::er &_impl_p=*(PUP::er *)_impl_pup_er;
  _impl_p|cellArray;
}
#endif /* CK_TEMPLATES_ONLY */

/* DEFS: readonly CProxy_Compute computeArray;
 */
extern CProxy_Compute computeArray;
#ifndef CK_TEMPLATES_ONLY
extern "C" void __xlater_roPup_computeArray(void *_impl_pup_er) {
  PUP::er &_impl_p=*(PUP::er *)_impl_pup_er;
  _impl_p|computeArray;
}
#endif /* CK_TEMPLATES_ONLY */

/* DEFS: readonly CkGroupID mCastGrpID;
 */
extern CkGroupID mCastGrpID;
#ifndef CK_TEMPLATES_ONLY
extern "C" void __xlater_roPup_mCastGrpID(void *_impl_pup_er) {
  PUP::er &_impl_p=*(PUP::er *)_impl_pup_er;
  _impl_p|mCastGrpID;
}
#endif /* CK_TEMPLATES_ONLY */

/* DEFS: readonly int cellArrayDimX;
 */
extern int cellArrayDimX;
#ifndef CK_TEMPLATES_ONLY
extern "C" void __xlater_roPup_cellArrayDimX(void *_impl_pup_er) {
  PUP::er &_impl_p=*(PUP::er *)_impl_pup_er;
  _impl_p|cellArrayDimX;
}
#endif /* CK_TEMPLATES_ONLY */

/* DEFS: readonly int cellArrayDimY;
 */
extern int cellArrayDimY;
#ifndef CK_TEMPLATES_ONLY
extern "C" void __xlater_roPup_cellArrayDimY(void *_impl_pup_er) {
  PUP::er &_impl_p=*(PUP::er *)_impl_pup_er;
  _impl_p|cellArrayDimY;
}
#endif /* CK_TEMPLATES_ONLY */

/* DEFS: readonly int cellArrayDimZ;
 */
extern int cellArrayDimZ;
#ifndef CK_TEMPLATES_ONLY
extern "C" void __xlater_roPup_cellArrayDimZ(void *_impl_pup_er) {
  PUP::er &_impl_p=*(PUP::er *)_impl_pup_er;
  _impl_p|cellArrayDimZ;
}
#endif /* CK_TEMPLATES_ONLY */

/* DEFS: readonly int finalStepCount;
 */
extern int finalStepCount;
#ifndef CK_TEMPLATES_ONLY
extern "C" void __xlater_roPup_finalStepCount(void *_impl_pup_er) {
  PUP::er &_impl_p=*(PUP::er *)_impl_pup_er;
  _impl_p|finalStepCount;
}
#endif /* CK_TEMPLATES_ONLY */

/* DEFS: readonly int firstLdbStep;
 */
extern int firstLdbStep;
#ifndef CK_TEMPLATES_ONLY
extern "C" void __xlater_roPup_firstLdbStep(void *_impl_pup_er) {
  PUP::er &_impl_p=*(PUP::er *)_impl_pup_er;
  _impl_p|firstLdbStep;
}
#endif /* CK_TEMPLATES_ONLY */

/* DEFS: readonly int ldbPeriod;
 */
extern int ldbPeriod;
#ifndef CK_TEMPLATES_ONLY
extern "C" void __xlater_roPup_ldbPeriod(void *_impl_pup_er) {
  PUP::er &_impl_p=*(PUP::er *)_impl_pup_er;
  _impl_p|ldbPeriod;
}
#endif /* CK_TEMPLATES_ONLY */

/* DEFS: mainchare Main: Chare{
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
#ifndef CK_TEMPLATES_ONLY
 int CkIndex_Main::__idx=0;
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
/* DEFS: Main(CkMigrateMessage* impl_msg);
 */

// Entry point registration function

int CkIndex_Main::reg_Main_CkMigrateMessage() {
  int epidx = CkRegisterEp("Main(CkMigrateMessage* impl_msg)",
      _call_Main_CkMigrateMessage, 0, __idx, 0);
  return epidx;
}


void CkIndex_Main::_call_Main_CkMigrateMessage(void* impl_msg, void* impl_obj_void)
{
  Main* impl_obj = static_cast<Main *>(impl_obj_void);
  new (impl_obj) Main((CkMigrateMessage*)impl_msg);
}
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
/* DEFS: void allDone(int done);
 */

void CProxy_Main::allDone(int done, const CkEntryOptions *impl_e_opts)
{
  ckCheck();
  //Marshall: int done
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|done;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|done;
  }
  if (ckIsDelegated()) {
    int destPE=CkChareMsgPrep(CkIndex_Main::idx_allDone_marshall2(), impl_msg, &ckGetChareID());
    if (destPE!=-1) ckDelegatedTo()->ChareSend(ckDelegatedPtr(),CkIndex_Main::idx_allDone_marshall2(), impl_msg, &ckGetChareID(),destPE);
  }
  else CkSendMsg(CkIndex_Main::idx_allDone_marshall2(), impl_msg, &ckGetChareID(),0);
}

void CkIndex_Main::_call_redn_wrapper_allDone_marshall2(void* impl_msg, void* impl_obj_void)
{
  Main* impl_obj = static_cast<Main*> (impl_obj_void);
  char* impl_buf = (char*)((CkReductionMsg*)impl_msg)->getData();
  /*Unmarshall pup'd fields: int done*/
  PUP::fromMem implP(impl_buf);
  /* non two-param case */
  int done; implP|done;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->allDone(done);
  delete (CkReductionMsg*)impl_msg;
}


// Entry point registration function

int CkIndex_Main::reg_allDone_marshall2() {
  int epidx = CkRegisterEp("allDone(int done)",
      _call_allDone_marshall2, CkMarshallMsg::__idx, __idx, 0+CK_EP_NOKEEP);
  CkRegisterMarshallUnpackFn(epidx, _callmarshall_allDone_marshall2);
  CkRegisterMessagePupFn(epidx, _marshallmessagepup_allDone_marshall2);

  return epidx;
}


// Redn wrapper registration function

int CkIndex_Main::reg_redn_wrapper_allDone_marshall2() {
  return CkRegisterEp("redn_wrapper_allDone(CkReductionMsg *impl_msg)",
      _call_redn_wrapper_allDone_marshall2, CkMarshallMsg::__idx, __idx, 0);
}


void CkIndex_Main::_call_allDone_marshall2(void* impl_msg, void* impl_obj_void)
{
  Main* impl_obj = static_cast<Main *>(impl_obj_void);
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: int done*/
  PUP::fromMem implP(impl_buf);
  int done; implP|done;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->allDone(done);
}

int CkIndex_Main::_callmarshall_allDone_marshall2(char* impl_buf, void* impl_obj_void) {
  Main* impl_obj = static_cast< Main *>(impl_obj_void);
  /*Unmarshall pup'd fields: int done*/
  PUP::fromMem implP(impl_buf);
  int done; implP|done;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->allDone(done);
  return implP.size();
}

void CkIndex_Main::_marshallmessagepup_allDone_marshall2(PUP::er &implDestP,void *impl_msg) {
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: int done*/
  PUP::fromMem implP(impl_buf);
  int done; implP|done;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  if (implDestP.hasComments()) implDestP.comment("done");
  implDestP|done;
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void computesCreated(int proceed);
 */

void CProxy_Main::computesCreated(int proceed, const CkEntryOptions *impl_e_opts)
{
  ckCheck();
  //Marshall: int proceed
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|proceed;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|proceed;
  }
  if (ckIsDelegated()) {
    int destPE=CkChareMsgPrep(CkIndex_Main::idx_computesCreated_marshall3(), impl_msg, &ckGetChareID());
    if (destPE!=-1) ckDelegatedTo()->ChareSend(ckDelegatedPtr(),CkIndex_Main::idx_computesCreated_marshall3(), impl_msg, &ckGetChareID(),destPE);
  }
  else CkSendMsg(CkIndex_Main::idx_computesCreated_marshall3(), impl_msg, &ckGetChareID(),0);
}

void CkIndex_Main::_call_redn_wrapper_computesCreated_marshall3(void* impl_msg, void* impl_obj_void)
{
  Main* impl_obj = static_cast<Main*> (impl_obj_void);
  char* impl_buf = (char*)((CkReductionMsg*)impl_msg)->getData();
  /*Unmarshall pup'd fields: int proceed*/
  PUP::fromMem implP(impl_buf);
  /* non two-param case */
  int proceed; implP|proceed;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->computesCreated(proceed);
  delete (CkReductionMsg*)impl_msg;
}


// Entry point registration function

int CkIndex_Main::reg_computesCreated_marshall3() {
  int epidx = CkRegisterEp("computesCreated(int proceed)",
      _call_computesCreated_marshall3, CkMarshallMsg::__idx, __idx, 0+CK_EP_NOKEEP);
  CkRegisterMarshallUnpackFn(epidx, _callmarshall_computesCreated_marshall3);
  CkRegisterMessagePupFn(epidx, _marshallmessagepup_computesCreated_marshall3);

  return epidx;
}


// Redn wrapper registration function

int CkIndex_Main::reg_redn_wrapper_computesCreated_marshall3() {
  return CkRegisterEp("redn_wrapper_computesCreated(CkReductionMsg *impl_msg)",
      _call_redn_wrapper_computesCreated_marshall3, CkMarshallMsg::__idx, __idx, 0);
}


void CkIndex_Main::_call_computesCreated_marshall3(void* impl_msg, void* impl_obj_void)
{
  Main* impl_obj = static_cast<Main *>(impl_obj_void);
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: int proceed*/
  PUP::fromMem implP(impl_buf);
  int proceed; implP|proceed;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->computesCreated(proceed);
}

int CkIndex_Main::_callmarshall_computesCreated_marshall3(char* impl_buf, void* impl_obj_void) {
  Main* impl_obj = static_cast< Main *>(impl_obj_void);
  /*Unmarshall pup'd fields: int proceed*/
  PUP::fromMem implP(impl_buf);
  int proceed; implP|proceed;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->computesCreated(proceed);
  return implP.size();
}

void CkIndex_Main::_marshallmessagepup_computesCreated_marshall3(PUP::er &implDestP,void *impl_msg) {
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: int proceed*/
  PUP::fromMem implP(impl_buf);
  int proceed; implP|proceed;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  if (implDestP.hasComments()) implDestP.comment("proceed");
  implDestP|proceed;
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void sectionsCreated(int proceed);
 */

void CProxy_Main::sectionsCreated(int proceed, const CkEntryOptions *impl_e_opts)
{
  ckCheck();
  //Marshall: int proceed
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|proceed;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|proceed;
  }
  if (ckIsDelegated()) {
    int destPE=CkChareMsgPrep(CkIndex_Main::idx_sectionsCreated_marshall4(), impl_msg, &ckGetChareID());
    if (destPE!=-1) ckDelegatedTo()->ChareSend(ckDelegatedPtr(),CkIndex_Main::idx_sectionsCreated_marshall4(), impl_msg, &ckGetChareID(),destPE);
  }
  else CkSendMsg(CkIndex_Main::idx_sectionsCreated_marshall4(), impl_msg, &ckGetChareID(),0);
}

void CkIndex_Main::_call_redn_wrapper_sectionsCreated_marshall4(void* impl_msg, void* impl_obj_void)
{
  Main* impl_obj = static_cast<Main*> (impl_obj_void);
  char* impl_buf = (char*)((CkReductionMsg*)impl_msg)->getData();
  /*Unmarshall pup'd fields: int proceed*/
  PUP::fromMem implP(impl_buf);
  /* non two-param case */
  int proceed; implP|proceed;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->sectionsCreated(proceed);
  delete (CkReductionMsg*)impl_msg;
}


// Entry point registration function

int CkIndex_Main::reg_sectionsCreated_marshall4() {
  int epidx = CkRegisterEp("sectionsCreated(int proceed)",
      _call_sectionsCreated_marshall4, CkMarshallMsg::__idx, __idx, 0+CK_EP_NOKEEP);
  CkRegisterMarshallUnpackFn(epidx, _callmarshall_sectionsCreated_marshall4);
  CkRegisterMessagePupFn(epidx, _marshallmessagepup_sectionsCreated_marshall4);

  return epidx;
}


// Redn wrapper registration function

int CkIndex_Main::reg_redn_wrapper_sectionsCreated_marshall4() {
  return CkRegisterEp("redn_wrapper_sectionsCreated(CkReductionMsg *impl_msg)",
      _call_redn_wrapper_sectionsCreated_marshall4, CkMarshallMsg::__idx, __idx, 0);
}


void CkIndex_Main::_call_sectionsCreated_marshall4(void* impl_msg, void* impl_obj_void)
{
  Main* impl_obj = static_cast<Main *>(impl_obj_void);
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: int proceed*/
  PUP::fromMem implP(impl_buf);
  int proceed; implP|proceed;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->sectionsCreated(proceed);
}

int CkIndex_Main::_callmarshall_sectionsCreated_marshall4(char* impl_buf, void* impl_obj_void) {
  Main* impl_obj = static_cast< Main *>(impl_obj_void);
  /*Unmarshall pup'd fields: int proceed*/
  PUP::fromMem implP(impl_buf);
  int proceed; implP|proceed;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->sectionsCreated(proceed);
  return implP.size();
}

void CkIndex_Main::_marshallmessagepup_sectionsCreated_marshall4(PUP::er &implDestP,void *impl_msg) {
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: int proceed*/
  PUP::fromMem implP(impl_buf);
  int proceed; implP|proceed;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  if (implDestP.hasComments()) implDestP.comment("proceed");
  implDestP|proceed;
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void energySumP(double energyIn);
 */

void CProxy_Main::energySumP(double energyIn, const CkEntryOptions *impl_e_opts)
{
  ckCheck();
  //Marshall: double energyIn
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|energyIn;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|energyIn;
  }
  if (ckIsDelegated()) {
    int destPE=CkChareMsgPrep(CkIndex_Main::idx_energySumP_marshall5(), impl_msg, &ckGetChareID());
    if (destPE!=-1) ckDelegatedTo()->ChareSend(ckDelegatedPtr(),CkIndex_Main::idx_energySumP_marshall5(), impl_msg, &ckGetChareID(),destPE);
  }
  else CkSendMsg(CkIndex_Main::idx_energySumP_marshall5(), impl_msg, &ckGetChareID(),0);
}

void CkIndex_Main::_call_redn_wrapper_energySumP_marshall5(void* impl_msg, void* impl_obj_void)
{
  Main* impl_obj = static_cast<Main*> (impl_obj_void);
  char* impl_buf = (char*)((CkReductionMsg*)impl_msg)->getData();
  /*Unmarshall pup'd fields: double energyIn*/
  PUP::fromMem implP(impl_buf);
  /* non two-param case */
  double energyIn; implP|energyIn;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->energySumP(energyIn);
  delete (CkReductionMsg*)impl_msg;
}


// Entry point registration function

int CkIndex_Main::reg_energySumP_marshall5() {
  int epidx = CkRegisterEp("energySumP(double energyIn)",
      _call_energySumP_marshall5, CkMarshallMsg::__idx, __idx, 0+CK_EP_NOKEEP);
  CkRegisterMarshallUnpackFn(epidx, _callmarshall_energySumP_marshall5);
  CkRegisterMessagePupFn(epidx, _marshallmessagepup_energySumP_marshall5);

  return epidx;
}


// Redn wrapper registration function

int CkIndex_Main::reg_redn_wrapper_energySumP_marshall5() {
  return CkRegisterEp("redn_wrapper_energySumP(CkReductionMsg *impl_msg)",
      _call_redn_wrapper_energySumP_marshall5, CkMarshallMsg::__idx, __idx, 0);
}


void CkIndex_Main::_call_energySumP_marshall5(void* impl_msg, void* impl_obj_void)
{
  Main* impl_obj = static_cast<Main *>(impl_obj_void);
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: double energyIn*/
  PUP::fromMem implP(impl_buf);
  double energyIn; implP|energyIn;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->energySumP(energyIn);
}

int CkIndex_Main::_callmarshall_energySumP_marshall5(char* impl_buf, void* impl_obj_void) {
  Main* impl_obj = static_cast< Main *>(impl_obj_void);
  /*Unmarshall pup'd fields: double energyIn*/
  PUP::fromMem implP(impl_buf);
  double energyIn; implP|energyIn;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->energySumP(energyIn);
  return implP.size();
}

void CkIndex_Main::_marshallmessagepup_energySumP_marshall5(PUP::er &implDestP,void *impl_msg) {
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: double energyIn*/
  PUP::fromMem implP(impl_buf);
  double energyIn; implP|energyIn;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  if (implDestP.hasComments()) implDestP.comment("energyIn");
  implDestP|energyIn;
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void energySumK(double energyIn);
 */

void CProxy_Main::energySumK(double energyIn, const CkEntryOptions *impl_e_opts)
{
  ckCheck();
  //Marshall: double energyIn
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|energyIn;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|energyIn;
  }
  if (ckIsDelegated()) {
    int destPE=CkChareMsgPrep(CkIndex_Main::idx_energySumK_marshall6(), impl_msg, &ckGetChareID());
    if (destPE!=-1) ckDelegatedTo()->ChareSend(ckDelegatedPtr(),CkIndex_Main::idx_energySumK_marshall6(), impl_msg, &ckGetChareID(),destPE);
  }
  else CkSendMsg(CkIndex_Main::idx_energySumK_marshall6(), impl_msg, &ckGetChareID(),0);
}

void CkIndex_Main::_call_redn_wrapper_energySumK_marshall6(void* impl_msg, void* impl_obj_void)
{
  Main* impl_obj = static_cast<Main*> (impl_obj_void);
  char* impl_buf = (char*)((CkReductionMsg*)impl_msg)->getData();
  /*Unmarshall pup'd fields: double energyIn*/
  PUP::fromMem implP(impl_buf);
  /* non two-param case */
  double energyIn; implP|energyIn;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->energySumK(energyIn);
  delete (CkReductionMsg*)impl_msg;
}


// Entry point registration function

int CkIndex_Main::reg_energySumK_marshall6() {
  int epidx = CkRegisterEp("energySumK(double energyIn)",
      _call_energySumK_marshall6, CkMarshallMsg::__idx, __idx, 0+CK_EP_NOKEEP);
  CkRegisterMarshallUnpackFn(epidx, _callmarshall_energySumK_marshall6);
  CkRegisterMessagePupFn(epidx, _marshallmessagepup_energySumK_marshall6);

  return epidx;
}


// Redn wrapper registration function

int CkIndex_Main::reg_redn_wrapper_energySumK_marshall6() {
  return CkRegisterEp("redn_wrapper_energySumK(CkReductionMsg *impl_msg)",
      _call_redn_wrapper_energySumK_marshall6, CkMarshallMsg::__idx, __idx, 0);
}


void CkIndex_Main::_call_energySumK_marshall6(void* impl_msg, void* impl_obj_void)
{
  Main* impl_obj = static_cast<Main *>(impl_obj_void);
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: double energyIn*/
  PUP::fromMem implP(impl_buf);
  double energyIn; implP|energyIn;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->energySumK(energyIn);
}

int CkIndex_Main::_callmarshall_energySumK_marshall6(char* impl_buf, void* impl_obj_void) {
  Main* impl_obj = static_cast< Main *>(impl_obj_void);
  /*Unmarshall pup'd fields: double energyIn*/
  PUP::fromMem implP(impl_buf);
  double energyIn; implP|energyIn;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->energySumK(energyIn);
  return implP.size();
}

void CkIndex_Main::_marshallmessagepup_energySumK_marshall6(PUP::er &implDestP,void *impl_msg) {
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: double energyIn*/
  PUP::fromMem implP(impl_buf);
  double energyIn; implP|energyIn;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  if (implDestP.hasComments()) implDestP.comment("energyIn");
  implDestP|energyIn;
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void run(void);
 */

void CProxy_Main::run(void)
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg();
  if (ckIsDelegated()) {
    int destPE=CkChareMsgPrep(CkIndex_Main::idx_run_void(), impl_msg, &ckGetChareID());
    if (destPE!=-1) ckDelegatedTo()->ChareSend(ckDelegatedPtr(),CkIndex_Main::idx_run_void(), impl_msg, &ckGetChareID(),destPE);
  }
  else CkSendMsg(CkIndex_Main::idx_run_void(), impl_msg, &ckGetChareID(),0);
}

// Entry point registration function

int CkIndex_Main::reg_run_void() {
  int epidx = CkRegisterEp("run(void)",
      _call_run_void, 0, __idx, 0);
  return epidx;
}


void CkIndex_Main::_call_run_void(void* impl_msg, void* impl_obj_void)
{
  Main* impl_obj = static_cast<Main *>(impl_obj_void);
  CkFreeSysMsg(impl_msg);
  impl_obj->run();
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
void CkIndex_Main::__register(const char *s, size_t size) {
  __idx = CkRegisterChare(s, size, TypeMainChare);
  CkRegisterBase(__idx, CkIndex_Chare::__idx);
  // REG: Main(CkMigrateMessage* impl_msg);
  idx_Main_CkMigrateMessage();
  CkRegisterMigCtor(__idx, idx_Main_CkMigrateMessage());

  // REG: Main(CkArgMsg* impl_msg);
  idx_Main_CkArgMsg();
  CkRegisterMainChare(__idx, idx_Main_CkArgMsg());

  // REG: void allDone(int done);
  idx_allDone_marshall2();
  idx_redn_wrapper_allDone_marshall2();

  // REG: void computesCreated(int proceed);
  idx_computesCreated_marshall3();
  idx_redn_wrapper_computesCreated_marshall3();

  // REG: void sectionsCreated(int proceed);
  idx_sectionsCreated_marshall4();
  idx_redn_wrapper_sectionsCreated_marshall4();

  // REG: void energySumP(double energyIn);
  idx_energySumP_marshall5();
  idx_redn_wrapper_energySumP_marshall5();

  // REG: void energySumK(double energyIn);
  idx_energySumK_marshall6();
  idx_redn_wrapper_energySumK_marshall6();

  // REG: void run(void);
  idx_run_void();

  Main::__sdag_register(); 
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
void Main::run() {
    _TRACE_END_EXECUTE(); 
    _slist_0();
    _TRACE_BEGIN_EXECUTE_DETAILED(-1, -1, _dummyEP, CkMyPe(), 0, NULL); 
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Main::run_end() {
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Main::_slist_0() {
    _when_0();
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Main::_slist_0_end() {
    run_end();
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
int Main::_when_0() {
    CMsgBuffer *computesCreated_buf;
    CkMarshallMsg *computesCreated_msg;

    computesCreated_buf = __cDep->getMessage(0); // SEGFAULT? __cDep = 0x0? Did you call __sdag_init() in your constructor?

    if ((computesCreated_buf != 0)) {
       computesCreated_msg = (CkMarshallMsg *)computesCreated_buf->msg;
       char *computesCreated_impl_buf=((CkMarshallMsg *)computesCreated_msg)->msgBuf;
       PUP::fromMem computesCreated_implP(computesCreated_impl_buf);
       int proceed; computesCreated_implP|proceed;
       computesCreated_impl_buf+=CK_ALIGN(computesCreated_implP.size(),16);
       __cDep->removeMessage(computesCreated_buf);
       delete computesCreated_buf;
       _atomic_0(proceed);
       delete computesCreated_msg;
       return 1;
    } else {
       CWhenTrigger *tr;
       tr = new CWhenTrigger(0, 1, 0, 1);
       tr->args[0] = (size_t)0xFF;
       tr->anyEntries[0] = 0;
       __cDep->Register(tr);
       return 0;
    }
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Main::_when_0_end(int proceed) {
    _when_1();
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Main::_atomic_0(int proceed) {
    _TRACE_BEGIN_EXECUTE_DETAILED(-1, -1, (_sdag_idx_Main_atomic_0()), CkMyPe(), 0, NULL); 
    
        computeArray.doneInserting();
        CkPrintf("Computes: %d .... created\n", (NUM_NEIGHBORS/2+1)*cellArrayDimX*cellArrayDimY*cellArrayDimZ);
        cellArray.createSection();
      
    _TRACE_END_EXECUTE(); 
    _when_0_end(proceed);
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
int Main::_when_1() {
    CMsgBuffer *sectionsCreated_buf;
    CkMarshallMsg *sectionsCreated_msg;

    sectionsCreated_buf = __cDep->getMessage(1); // SEGFAULT? __cDep = 0x0? Did you call __sdag_init() in your constructor?

    if ((sectionsCreated_buf != 0)) {
       sectionsCreated_msg = (CkMarshallMsg *)sectionsCreated_buf->msg;
       char *sectionsCreated_impl_buf=((CkMarshallMsg *)sectionsCreated_msg)->msgBuf;
       PUP::fromMem sectionsCreated_implP(sectionsCreated_impl_buf);
       int proceed; sectionsCreated_implP|proceed;
       sectionsCreated_impl_buf+=CK_ALIGN(sectionsCreated_implP.size(),16);
       __cDep->removeMessage(sectionsCreated_buf);
       delete sectionsCreated_buf;
       _atomic_1(proceed);
       delete sectionsCreated_msg;
       return 1;
    } else {
       CWhenTrigger *tr;
       tr = new CWhenTrigger(1, 1, 0, 1);
       tr->args[0] = (size_t)0xFF;
       tr->anyEntries[0] = 1;
       __cDep->Register(tr);
       return 0;
    }
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Main::_when_1_end(int proceed) {
    _when_2();
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Main::_atomic_1(int proceed) {
    _TRACE_BEGIN_EXECUTE_DETAILED(-1, -1, (_sdag_idx_Main_atomic_1()), CkMyPe(), 0, NULL); 
    
        CkPrintf("Multicast sections .... created\n");
        CkPrintf("Starting simulation .... \n\n");
        cellArray.run();
        computeArray.run();
      
    _TRACE_END_EXECUTE(); 
    _when_1_end(proceed);
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
int Main::_when_2() {
    CMsgBuffer *energySumP_buf;
    CkMarshallMsg *energySumP_msg;
    CMsgBuffer *energySumK_buf;
    CkMarshallMsg *energySumK_msg;

    energySumP_buf = __cDep->getMessage(2); // SEGFAULT? __cDep = 0x0? Did you call __sdag_init() in your constructor?
    energySumK_buf = __cDep->getMessage(3); // SEGFAULT? __cDep = 0x0? Did you call __sdag_init() in your constructor?

    if ((energySumP_buf != 0)&&(energySumK_buf != 0)) {
       energySumP_msg = (CkMarshallMsg *)energySumP_buf->msg;
       char *energySumP_impl_buf=((CkMarshallMsg *)energySumP_msg)->msgBuf;
       PUP::fromMem energySumP_implP(energySumP_impl_buf);
       double energyP; energySumP_implP|energyP;
       energySumP_impl_buf+=CK_ALIGN(energySumP_implP.size(),16);
       __cDep->removeMessage(energySumP_buf);
       delete energySumP_buf;
       energySumK_msg = (CkMarshallMsg *)energySumK_buf->msg;
       char *energySumK_impl_buf=((CkMarshallMsg *)energySumK_msg)->msgBuf;
       PUP::fromMem energySumK_implP(energySumK_impl_buf);
       double energyK; energySumK_implP|energyK;
       energySumK_impl_buf+=CK_ALIGN(energySumK_implP.size(),16);
       __cDep->removeMessage(energySumK_buf);
       delete energySumK_buf;
       _atomic_2(energyP, energyK);
       delete energySumP_msg;
       delete energySumK_msg;
       return 1;
    } else {
       CWhenTrigger *tr;
       tr = new CWhenTrigger(2, 1, 0, 2);
       tr->args[0] = (size_t)0xFF;
       tr->anyEntries[0] = 2;
       tr->anyEntries[1] = 3;
       __cDep->Register(tr);
       return 0;
    }
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Main::_when_2_end(double energyP, double energyK) {
    _when_3();
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Main::_atomic_2(double energyP, double energyK) {
    _TRACE_BEGIN_EXECUTE_DETAILED(-1, -1, (_sdag_idx_Main_atomic_2()), CkMyPe(), 0, NULL); 
    
        prevEnergy = energyP + energyK;
      
    _TRACE_END_EXECUTE(); 
    _when_2_end(energyP, energyK);
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
int Main::_when_3() {
    CMsgBuffer *energySumP_buf;
    CkMarshallMsg *energySumP_msg;
    CMsgBuffer *energySumK_buf;
    CkMarshallMsg *energySumK_msg;

    energySumP_buf = __cDep->getMessage(2); // SEGFAULT? __cDep = 0x0? Did you call __sdag_init() in your constructor?
    energySumK_buf = __cDep->getMessage(3); // SEGFAULT? __cDep = 0x0? Did you call __sdag_init() in your constructor?

    if ((energySumP_buf != 0)&&(energySumK_buf != 0)) {
       energySumP_msg = (CkMarshallMsg *)energySumP_buf->msg;
       char *energySumP_impl_buf=((CkMarshallMsg *)energySumP_msg)->msgBuf;
       PUP::fromMem energySumP_implP(energySumP_impl_buf);
       double energyP; energySumP_implP|energyP;
       energySumP_impl_buf+=CK_ALIGN(energySumP_implP.size(),16);
       __cDep->removeMessage(energySumP_buf);
       delete energySumP_buf;
       energySumK_msg = (CkMarshallMsg *)energySumK_buf->msg;
       char *energySumK_impl_buf=((CkMarshallMsg *)energySumK_msg)->msgBuf;
       PUP::fromMem energySumK_implP(energySumK_impl_buf);
       double energyK; energySumK_implP|energyK;
       energySumK_impl_buf+=CK_ALIGN(energySumK_implP.size(),16);
       __cDep->removeMessage(energySumK_buf);
       delete energySumK_buf;
       _atomic_3(energyP, energyK);
       delete energySumP_msg;
       delete energySumK_msg;
       return 1;
    } else {
       CWhenTrigger *tr;
       tr = new CWhenTrigger(3, 1, 0, 2);
       tr->args[0] = (size_t)0xFF;
       tr->anyEntries[0] = 2;
       tr->anyEntries[1] = 3;
       __cDep->Register(tr);
       return 0;
    }
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Main::_when_3_end(double energyP, double energyK) {
    _when_4();
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Main::_atomic_3(double energyP, double energyK) {
    _TRACE_BEGIN_EXECUTE_DETAILED(-1, -1, (_sdag_idx_Main_atomic_3()), CkMyPe(), 0, NULL); 
    
        energy = energyP + energyK;
        if(abs(energy-prevEnergy)>ENERGY_VAR) {
          CkPrintf("Energy value has varied significantly from %E to %E\n",prevEnergy,energy);
          testFailed = 1;
        }
      
    _TRACE_END_EXECUTE(); 
    _when_3_end(energyP, energyK);
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
int Main::_when_4() {
    CMsgBuffer *allDone_buf;
    CkMarshallMsg *allDone_msg;

    allDone_buf = __cDep->getMessage(4); // SEGFAULT? __cDep = 0x0? Did you call __sdag_init() in your constructor?

    if ((allDone_buf != 0)) {
       allDone_msg = (CkMarshallMsg *)allDone_buf->msg;
       char *allDone_impl_buf=((CkMarshallMsg *)allDone_msg)->msgBuf;
       PUP::fromMem allDone_implP(allDone_impl_buf);
       int done; allDone_implP|done;
       allDone_impl_buf+=CK_ALIGN(allDone_implP.size(),16);
       __cDep->removeMessage(allDone_buf);
       delete allDone_buf;
       _atomic_4(done);
       delete allDone_msg;
       return 1;
    } else {
       CWhenTrigger *tr;
       tr = new CWhenTrigger(4, 1, 0, 1);
       tr->args[0] = (size_t)0xFF;
       tr->anyEntries[0] = 4;
       __cDep->Register(tr);
       return 0;
    }
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Main::_when_4_end(int done) {
    _slist_0_end();
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Main::_atomic_4(int done) {
    _TRACE_BEGIN_EXECUTE_DETAILED(-1, -1, (_sdag_idx_Main_atomic_4()), CkMyPe(), 0, NULL); 
    
        if(testFailed) {
          CkPrintf("\nEnergy conservation test failed for maximum allowed variation of %E units.\nSIMULATION UNSUCCESSFULL\n",ENERGY_VAR);  
        } else {
          CkPrintf("\nEnergy conservation test passed for maximum allowed variation of %E units.\nSIMULATION SUCCESSFULL \n",ENERGY_VAR);
        }
        CkExit();
      
    _TRACE_END_EXECUTE(); 
    _when_4_end(done);
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Main::computesCreated(int proceed){
    CWhenTrigger *tr;
    void* _bgParentLog = NULL;
    CMsgBuffer* cmsgbuf;
    int impl_off=0; int impl_arrstart=0;
    {
      PUP::sizer implP1;
      implP1|proceed;
      impl_off+=implP1.size();
    }
    CkMarshallMsg *impl_msg1=CkAllocateMarshallMsg(impl_off,NULL);
    {
      PUP::toMem implP1((void *)impl_msg1->msgBuf);
      implP1|proceed;
    }
    cmsgbuf = __cDep->bufferMessage(0, (void *) impl_msg1, (void*) _bgParentLog, 0);
    tr = __cDep->getTrigger(0, 0);
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
void Main::sectionsCreated(int proceed){
    CWhenTrigger *tr;
    void* _bgParentLog = NULL;
    CMsgBuffer* cmsgbuf;
    int impl_off=0; int impl_arrstart=0;
    {
      PUP::sizer implP1;
      implP1|proceed;
      impl_off+=implP1.size();
    }
    CkMarshallMsg *impl_msg1=CkAllocateMarshallMsg(impl_off,NULL);
    {
      PUP::toMem implP1((void *)impl_msg1->msgBuf);
      implP1|proceed;
    }
    cmsgbuf = __cDep->bufferMessage(1, (void *) impl_msg1, (void*) _bgParentLog, 0);
    tr = __cDep->getTrigger(1, 0);
    if (tr == 0)
      return;
    _TRACE_END_EXECUTE(); 
    {
        tr->args[0] = 0;
        _when_1();
        delete tr;
        _TRACE_BEGIN_EXECUTE_DETAILED(-1, -1, _dummyEP, CkMyPe(), 0, NULL); 
        return;
    }
}

#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
void Main::energySumP(double energyP){
    CWhenTrigger *tr;
    void* _bgParentLog = NULL;
    CMsgBuffer* cmsgbuf;
    int impl_off=0; int impl_arrstart=0;
    {
      PUP::sizer implP1;
      implP1|energyP;
      impl_off+=implP1.size();
    }
    CkMarshallMsg *impl_msg1=CkAllocateMarshallMsg(impl_off,NULL);
    {
      PUP::toMem implP1((void *)impl_msg1->msgBuf);
      implP1|energyP;
    }
    cmsgbuf = __cDep->bufferMessage(2, (void *) impl_msg1, (void*) _bgParentLog, 0);
    tr = __cDep->getTrigger(2, 0);
    if (tr == 0)
      return;
    _TRACE_END_EXECUTE(); 
    switch(tr->whenID) {
      case 2:
      {
        tr->args[0] = 0;
        _when_2();
        delete tr;
        _TRACE_BEGIN_EXECUTE_DETAILED(-1, -1, _dummyEP, CkMyPe(), 0, NULL); 
        return;
      }
      case 3:
      {
        tr->args[0] = 0;
        _when_3();
        delete tr;
        _TRACE_BEGIN_EXECUTE_DETAILED(-1, -1, _dummyEP, CkMyPe(), 0, NULL); 
        return;
      }
    }
}

#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
void Main::energySumK(double energyK){
    CWhenTrigger *tr;
    void* _bgParentLog = NULL;
    CMsgBuffer* cmsgbuf;
    int impl_off=0; int impl_arrstart=0;
    {
      PUP::sizer implP1;
      implP1|energyK;
      impl_off+=implP1.size();
    }
    CkMarshallMsg *impl_msg1=CkAllocateMarshallMsg(impl_off,NULL);
    {
      PUP::toMem implP1((void *)impl_msg1->msgBuf);
      implP1|energyK;
    }
    cmsgbuf = __cDep->bufferMessage(3, (void *) impl_msg1, (void*) _bgParentLog, 0);
    tr = __cDep->getTrigger(3, 0);
    if (tr == 0)
      return;
    _TRACE_END_EXECUTE(); 
    switch(tr->whenID) {
      case 2:
      {
        tr->args[0] = 0;
        _when_2();
        delete tr;
        _TRACE_BEGIN_EXECUTE_DETAILED(-1, -1, _dummyEP, CkMyPe(), 0, NULL); 
        return;
      }
      case 3:
      {
        tr->args[0] = 0;
        _when_3();
        delete tr;
        _TRACE_BEGIN_EXECUTE_DETAILED(-1, -1, _dummyEP, CkMyPe(), 0, NULL); 
        return;
      }
    }
}

#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
void Main::allDone(int done){
    CWhenTrigger *tr;
    void* _bgParentLog = NULL;
    CMsgBuffer* cmsgbuf;
    int impl_off=0; int impl_arrstart=0;
    {
      PUP::sizer implP1;
      implP1|done;
      impl_off+=implP1.size();
    }
    CkMarshallMsg *impl_msg1=CkAllocateMarshallMsg(impl_off,NULL);
    {
      PUP::toMem implP1((void *)impl_msg1->msgBuf);
      implP1|done;
    }
    cmsgbuf = __cDep->bufferMessage(4, (void *) impl_msg1, (void*) _bgParentLog, 0);
    tr = __cDep->getTrigger(4, 0);
    if (tr == 0)
      return;
    _TRACE_END_EXECUTE(); 
    {
        tr->args[0] = 0;
        _when_4();
        delete tr;
        _TRACE_BEGIN_EXECUTE_DETAILED(-1, -1, _dummyEP, CkMyPe(), 0, NULL); 
        return;
    }
}

#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
void Main::__sdag_init() {
    __cDep = new CDep(5,5);
    __cDep->addDepends(0,0);
    __cDep->addDepends(1,1);
    __cDep->addDepends(2,2);
    __cDep->addDepends(3,2);
    __cDep->addDepends(2,3);
    __cDep->addDepends(3,3);
    __cDep->addDepends(4,4);
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Main::__sdag_register() {
    (void)_sdag_idx_Main_atomic_0();
    (void)_sdag_idx_Main_atomic_1();
    (void)_sdag_idx_Main_atomic_2();
    (void)_sdag_idx_Main_atomic_3();
    (void)_sdag_idx_Main_atomic_4();
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
int Main::_sdag_idx_Main_atomic_0() {
  static int epidx = _sdag_reg_Main_atomic_0();
  return epidx;
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
int Main::_sdag_reg_Main_atomic_0() {
  return CkRegisterEp("Main_atomic_0", NULL, 0, CkIndex_Main::__idx, 0);
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
int Main::_sdag_idx_Main_atomic_1() {
  static int epidx = _sdag_reg_Main_atomic_1();
  return epidx;
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
int Main::_sdag_reg_Main_atomic_1() {
  return CkRegisterEp("Main_atomic_1", NULL, 0, CkIndex_Main::__idx, 0);
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
int Main::_sdag_idx_Main_atomic_2() {
  static int epidx = _sdag_reg_Main_atomic_2();
  return epidx;
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
int Main::_sdag_reg_Main_atomic_2() {
  return CkRegisterEp("Main_atomic_2", NULL, 0, CkIndex_Main::__idx, 0);
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
int Main::_sdag_idx_Main_atomic_3() {
  static int epidx = _sdag_reg_Main_atomic_3();
  return epidx;
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
int Main::_sdag_reg_Main_atomic_3() {
  return CkRegisterEp("Main_atomic_3", NULL, 0, CkIndex_Main::__idx, 0);
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
int Main::_sdag_idx_Main_atomic_4() {
  static int epidx = _sdag_reg_Main_atomic_4();
  return epidx;
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
int Main::_sdag_reg_Main_atomic_4() {
  return CkRegisterEp("Main_atomic_4", NULL, 0, CkIndex_Main::__idx, 0);
}
#endif /* CK_TEMPLATES_ONLY */



/* DEFS: message ParticleDataMsg{
vec3 part[];
}
;
 */
#ifndef CK_TEMPLATES_ONLY
void *CMessage_ParticleDataMsg::operator new(size_t s){
  return ParticleDataMsg::alloc(__idx, s, 0, 0);
}
void *CMessage_ParticleDataMsg::operator new(size_t s, int* sz){
  return ParticleDataMsg::alloc(__idx, s, sz, 0);
}
void *CMessage_ParticleDataMsg::operator new(size_t s, int* sz,const int pb){
  return ParticleDataMsg::alloc(__idx, s, sz, pb);
}
void *CMessage_ParticleDataMsg::operator new(size_t s, int sz0) {
  int sizes[1];
  sizes[0] = sz0;
  return ParticleDataMsg::alloc(__idx, s, sizes, 0);
}
void *CMessage_ParticleDataMsg::operator new(size_t s, int sz0, const int p) {
  int sizes[1];
  sizes[0] = sz0;
  return ParticleDataMsg::alloc(__idx, s, sizes, p);
}
void* CMessage_ParticleDataMsg::alloc(int msgnum, size_t sz, int *sizes, int pb) {
  CkpvAccess(_offsets)[0] = ALIGN8(sz);
  if(sizes==0)
    CkpvAccess(_offsets)[1] = CkpvAccess(_offsets)[0];
  else
    CkpvAccess(_offsets)[1] = CkpvAccess(_offsets)[0] + ALIGN8(sizeof(vec3)*sizes[0]);
  return CkAllocMsg(msgnum, CkpvAccess(_offsets)[1], pb);
}
CMessage_ParticleDataMsg::CMessage_ParticleDataMsg() {
ParticleDataMsg *newmsg = (ParticleDataMsg *)this;
  newmsg->part = (vec3 *) ((char *)newmsg + CkpvAccess(_offsets)[0]);
}
void CMessage_ParticleDataMsg::dealloc(void *p) {
  CkFreeMsg(p);
}
void* CMessage_ParticleDataMsg::pack(ParticleDataMsg *msg) {
  msg->part = (vec3 *) ((char *)msg->part - (char *)msg);
  return (void *) msg;
}
ParticleDataMsg* CMessage_ParticleDataMsg::unpack(void* buf) {
  ParticleDataMsg *msg = (ParticleDataMsg *) buf;
  msg->part = (vec3 *) ((size_t)msg->part + (char *)msg);
  return msg;
}
int CMessage_ParticleDataMsg::__idx=0;
#endif /* CK_TEMPLATES_ONLY */

/* DEFS: array Cell: ArrayElement{
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
#ifndef CK_TEMPLATES_ONLY
 int CkIndex_Cell::__idx=0;
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
/* DEFS: Cell(CkMigrateMessage* impl_msg);
 */
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: Cell(void);
 */

void CProxyElement_Cell::insert(int onPE)
{ 
  void *impl_msg = CkAllocSysMsg();
   ckInsert((CkArrayMessage *)impl_msg,CkIndex_Cell::idx_Cell_void(),onPE);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void createComputes(void);
 */

void CProxyElement_Cell::createComputes(void) 
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg();
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Cell::idx_createComputes_void(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void createSection(void);
 */

void CProxyElement_Cell::createSection(void) 
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg();
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Cell::idx_createSection_void(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void receiveParticles(const CkVec<Particle > &updates);
 */

void CProxyElement_Cell::receiveParticles(const CkVec<Particle > &updates, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: const CkVec<Particle > &updates
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    //Have to cast away const-ness to get pup routine
    implP|(CkVec<Particle > &)updates;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    //Have to cast away const-ness to get pup routine
    implP|(CkVec<Particle > &)updates;
  }
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Cell::idx_receiveParticles_marshall4(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void ResumeFromSync(void);
 */

void CProxyElement_Cell::ResumeFromSync(void) 
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg();
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Cell::idx_ResumeFromSync_void(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void resumeAfterLB(int resume);
 */

void CProxyElement_Cell::resumeAfterLB(int resume, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: int resume
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|resume;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|resume;
  }
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Cell::idx_resumeAfterLB_marshall6(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void reduceForces(const vec3 *forces, int n);
 */

void CProxyElement_Cell::reduceForces(const vec3 *forces, int n, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: const vec3 *forces, int n
  int impl_off=0;
  int impl_arrstart=0;
  int impl_off_forces, impl_cnt_forces;
  impl_off_forces=impl_off=CK_ALIGN(impl_off,sizeof(vec3));
  impl_off+=(impl_cnt_forces=sizeof(vec3)*(n));
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|impl_off_forces;
    implP|impl_cnt_forces;
    implP|n;
    impl_arrstart=CK_ALIGN(implP.size(),16);
    impl_off+=impl_arrstart;
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|impl_off_forces;
    implP|impl_cnt_forces;
    implP|n;
  }
  char *impl_buf=impl_msg->msgBuf+impl_arrstart;
  memcpy(impl_buf+impl_off_forces,forces,impl_cnt_forces);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Cell::idx_reduceForces_marshall7(),0);
}

void CkIndex_Cell::_call_redn_wrapper_reduceForces_marshall7(void* impl_msg, void* impl_obj_void)
{
  Cell* impl_obj = static_cast<Cell*> (impl_obj_void);
  char* impl_buf = (char*)((CkReductionMsg*)impl_msg)->getData();
  /*Unmarshall pup'd fields: const vec3 *forces, int n*/
  PUP::fromMem implP(impl_buf);
  int n; n = ((CkReductionMsg*)impl_msg)->getLength() / sizeof(vec3);
  vec3* forces; forces = (vec3*)impl_buf;
  impl_obj->reduceForces(forces, n);
  delete (CkReductionMsg*)impl_msg;
}

#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void run(void);
 */

void CProxyElement_Cell::run(void) 
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg();
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Cell::idx_run_void(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: Cell(CkMigrateMessage* impl_msg);
 */

// Entry point registration function

int CkIndex_Cell::reg_Cell_CkMigrateMessage() {
  int epidx = CkRegisterEp("Cell(CkMigrateMessage* impl_msg)",
      _call_Cell_CkMigrateMessage, 0, __idx, 0);
  return epidx;
}


void CkIndex_Cell::_call_Cell_CkMigrateMessage(void* impl_msg, void* impl_obj_void)
{
  Cell* impl_obj = static_cast<Cell *>(impl_obj_void);
  new (impl_obj) Cell((CkMigrateMessage*)impl_msg);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: Cell(void);
 */

CkArrayID CProxy_Cell::ckNew(const CkArrayOptions &opts)
{ 
  void *impl_msg = CkAllocSysMsg();
   return ckCreateArray((CkArrayMessage *)impl_msg,CkIndex_Cell::idx_Cell_void(),opts);
}

CkArrayID CProxy_Cell::ckNew(const int s1, const int s2, const int s3)
{ 
  void *impl_msg = CkAllocSysMsg();
   return ckCreateArray((CkArrayMessage *)impl_msg,CkIndex_Cell::idx_Cell_void(),CkArrayOptions(s1, s2, s3));
}

// Entry point registration function

int CkIndex_Cell::reg_Cell_void() {
  int epidx = CkRegisterEp("Cell(void)",
      _call_Cell_void, 0, __idx, 0);
  return epidx;
}


void CkIndex_Cell::_call_Cell_void(void* impl_msg, void* impl_obj_void)
{
  Cell* impl_obj = static_cast<Cell *>(impl_obj_void);
  CkFreeSysMsg(impl_msg);
  new (impl_obj) Cell();
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void createComputes(void);
 */

void CProxy_Cell::createComputes(void) 
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg();
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckBroadcast(impl_amsg, CkIndex_Cell::idx_createComputes_void(),0);
}

// Entry point registration function

int CkIndex_Cell::reg_createComputes_void() {
  int epidx = CkRegisterEp("createComputes(void)",
      _call_createComputes_void, 0, __idx, 0);
  return epidx;
}


void CkIndex_Cell::_call_createComputes_void(void* impl_msg, void* impl_obj_void)
{
  Cell* impl_obj = static_cast<Cell *>(impl_obj_void);
  CkFreeSysMsg(impl_msg);
  impl_obj->createComputes();
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void createSection(void);
 */

void CProxy_Cell::createSection(void) 
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg();
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckBroadcast(impl_amsg, CkIndex_Cell::idx_createSection_void(),0);
}

// Entry point registration function

int CkIndex_Cell::reg_createSection_void() {
  int epidx = CkRegisterEp("createSection(void)",
      _call_createSection_void, 0, __idx, 0);
  return epidx;
}


void CkIndex_Cell::_call_createSection_void(void* impl_msg, void* impl_obj_void)
{
  Cell* impl_obj = static_cast<Cell *>(impl_obj_void);
  CkFreeSysMsg(impl_msg);
  impl_obj->createSection();
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void receiveParticles(const CkVec<Particle > &updates);
 */

void CProxy_Cell::receiveParticles(const CkVec<Particle > &updates, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: const CkVec<Particle > &updates
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    //Have to cast away const-ness to get pup routine
    implP|(CkVec<Particle > &)updates;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    //Have to cast away const-ness to get pup routine
    implP|(CkVec<Particle > &)updates;
  }
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckBroadcast(impl_amsg, CkIndex_Cell::idx_receiveParticles_marshall4(),0);
}

// Entry point registration function

int CkIndex_Cell::reg_receiveParticles_marshall4() {
  int epidx = CkRegisterEp("receiveParticles(const CkVec<Particle > &updates)",
      _call_receiveParticles_marshall4, CkMarshallMsg::__idx, __idx, 0+CK_EP_NOKEEP);
  CkRegisterMarshallUnpackFn(epidx, _callmarshall_receiveParticles_marshall4);
  CkRegisterMessagePupFn(epidx, _marshallmessagepup_receiveParticles_marshall4);

  return epidx;
}


void CkIndex_Cell::_call_receiveParticles_marshall4(void* impl_msg, void* impl_obj_void)
{
  Cell* impl_obj = static_cast<Cell *>(impl_obj_void);
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: const CkVec<Particle > &updates*/
  PUP::fromMem implP(impl_buf);
  CkVec<Particle > updates; implP|updates;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->receiveParticles(updates);
}

int CkIndex_Cell::_callmarshall_receiveParticles_marshall4(char* impl_buf, void* impl_obj_void) {
  Cell* impl_obj = static_cast< Cell *>(impl_obj_void);
  /*Unmarshall pup'd fields: const CkVec<Particle > &updates*/
  PUP::fromMem implP(impl_buf);
  CkVec<Particle > updates; implP|updates;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->receiveParticles(updates);
  return implP.size();
}

void CkIndex_Cell::_marshallmessagepup_receiveParticles_marshall4(PUP::er &implDestP,void *impl_msg) {
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: const CkVec<Particle > &updates*/
  PUP::fromMem implP(impl_buf);
  CkVec<Particle > updates; implP|updates;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  if (implDestP.hasComments()) implDestP.comment("updates");
  implDestP|updates;
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void ResumeFromSync(void);
 */

void CProxy_Cell::ResumeFromSync(void) 
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg();
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckBroadcast(impl_amsg, CkIndex_Cell::idx_ResumeFromSync_void(),0);
}

// Entry point registration function

int CkIndex_Cell::reg_ResumeFromSync_void() {
  int epidx = CkRegisterEp("ResumeFromSync(void)",
      _call_ResumeFromSync_void, 0, __idx, 0);
  return epidx;
}


void CkIndex_Cell::_call_ResumeFromSync_void(void* impl_msg, void* impl_obj_void)
{
  Cell* impl_obj = static_cast<Cell *>(impl_obj_void);
  CkFreeSysMsg(impl_msg);
  impl_obj->ResumeFromSync();
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void resumeAfterLB(int resume);
 */

void CProxy_Cell::resumeAfterLB(int resume, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: int resume
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|resume;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|resume;
  }
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckBroadcast(impl_amsg, CkIndex_Cell::idx_resumeAfterLB_marshall6(),0);
}

// Entry point registration function

int CkIndex_Cell::reg_resumeAfterLB_marshall6() {
  int epidx = CkRegisterEp("resumeAfterLB(int resume)",
      _call_resumeAfterLB_marshall6, CkMarshallMsg::__idx, __idx, 0+CK_EP_NOKEEP);
  CkRegisterMarshallUnpackFn(epidx, _callmarshall_resumeAfterLB_marshall6);
  CkRegisterMessagePupFn(epidx, _marshallmessagepup_resumeAfterLB_marshall6);

  return epidx;
}


void CkIndex_Cell::_call_resumeAfterLB_marshall6(void* impl_msg, void* impl_obj_void)
{
  Cell* impl_obj = static_cast<Cell *>(impl_obj_void);
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: int resume*/
  PUP::fromMem implP(impl_buf);
  int resume; implP|resume;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->resumeAfterLB(resume);
}

int CkIndex_Cell::_callmarshall_resumeAfterLB_marshall6(char* impl_buf, void* impl_obj_void) {
  Cell* impl_obj = static_cast< Cell *>(impl_obj_void);
  /*Unmarshall pup'd fields: int resume*/
  PUP::fromMem implP(impl_buf);
  int resume; implP|resume;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  impl_obj->resumeAfterLB(resume);
  return implP.size();
}

void CkIndex_Cell::_marshallmessagepup_resumeAfterLB_marshall6(PUP::er &implDestP,void *impl_msg) {
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: int resume*/
  PUP::fromMem implP(impl_buf);
  int resume; implP|resume;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  if (implDestP.hasComments()) implDestP.comment("resume");
  implDestP|resume;
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void reduceForces(const vec3 *forces, int n);
 */

void CProxy_Cell::reduceForces(const vec3 *forces, int n, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: const vec3 *forces, int n
  int impl_off=0;
  int impl_arrstart=0;
  int impl_off_forces, impl_cnt_forces;
  impl_off_forces=impl_off=CK_ALIGN(impl_off,sizeof(vec3));
  impl_off+=(impl_cnt_forces=sizeof(vec3)*(n));
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|impl_off_forces;
    implP|impl_cnt_forces;
    implP|n;
    impl_arrstart=CK_ALIGN(implP.size(),16);
    impl_off+=impl_arrstart;
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|impl_off_forces;
    implP|impl_cnt_forces;
    implP|n;
  }
  char *impl_buf=impl_msg->msgBuf+impl_arrstart;
  memcpy(impl_buf+impl_off_forces,forces,impl_cnt_forces);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckBroadcast(impl_amsg, CkIndex_Cell::idx_reduceForces_marshall7(),0);
}

// Entry point registration function

int CkIndex_Cell::reg_reduceForces_marshall7() {
  int epidx = CkRegisterEp("reduceForces(const vec3 *forces, int n)",
      _call_reduceForces_marshall7, CkMarshallMsg::__idx, __idx, 0+CK_EP_NOKEEP);
  CkRegisterMarshallUnpackFn(epidx, _callmarshall_reduceForces_marshall7);
  CkRegisterMessagePupFn(epidx, _marshallmessagepup_reduceForces_marshall7);

  return epidx;
}


// Redn wrapper registration function

int CkIndex_Cell::reg_redn_wrapper_reduceForces_marshall7() {
  return CkRegisterEp("redn_wrapper_reduceForces(CkReductionMsg *impl_msg)",
      _call_redn_wrapper_reduceForces_marshall7, CkMarshallMsg::__idx, __idx, 0);
}


void CkIndex_Cell::_call_reduceForces_marshall7(void* impl_msg, void* impl_obj_void)
{
  Cell* impl_obj = static_cast<Cell *>(impl_obj_void);
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: const vec3 *forces, int n*/
  PUP::fromMem implP(impl_buf);
  int impl_off_forces, impl_cnt_forces; 
  implP|impl_off_forces;
  implP|impl_cnt_forces;
  int n; implP|n;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  vec3 *forces=(vec3 *)(impl_buf+impl_off_forces);
  impl_obj->reduceForces(forces, n);
}

int CkIndex_Cell::_callmarshall_reduceForces_marshall7(char* impl_buf, void* impl_obj_void) {
  Cell* impl_obj = static_cast< Cell *>(impl_obj_void);
  /*Unmarshall pup'd fields: const vec3 *forces, int n*/
  PUP::fromMem implP(impl_buf);
  int impl_off_forces, impl_cnt_forces; 
  implP|impl_off_forces;
  implP|impl_cnt_forces;
  int n; implP|n;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  vec3 *forces=(vec3 *)(impl_buf+impl_off_forces);
  impl_obj->reduceForces(forces, n);
  return implP.size();
}

void CkIndex_Cell::_marshallmessagepup_reduceForces_marshall7(PUP::er &implDestP,void *impl_msg) {
  CkMarshallMsg *impl_msg_typed=(CkMarshallMsg *)impl_msg;
  char *impl_buf=impl_msg_typed->msgBuf;
  /*Unmarshall pup'd fields: const vec3 *forces, int n*/
  PUP::fromMem implP(impl_buf);
  int impl_off_forces, impl_cnt_forces; 
  implP|impl_off_forces;
  implP|impl_cnt_forces;
  int n; implP|n;
  impl_buf+=CK_ALIGN(implP.size(),16);
  /*Unmarshall arrays:*/
  vec3 *forces=(vec3 *)(impl_buf+impl_off_forces);
  if (implDestP.hasComments()) implDestP.comment("forces");
  implDestP.synchronize(PUP::sync_begin_array);
  { for (int impl_i=0;impl_i*(sizeof(*forces))<impl_cnt_forces;impl_i++) { 
      implDestP.synchronize(PUP::sync_item);
      implDestP|forces[impl_i];
  } } 
  implDestP.synchronize(PUP::sync_end_array);
  if (implDestP.hasComments()) implDestP.comment("n");
  implDestP|n;
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void run(void);
 */

void CProxy_Cell::run(void) 
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg();
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckBroadcast(impl_amsg, CkIndex_Cell::idx_run_void(),0);
}

// Entry point registration function

int CkIndex_Cell::reg_run_void() {
  int epidx = CkRegisterEp("run(void)",
      _call_run_void, 0, __idx, 0);
  return epidx;
}


void CkIndex_Cell::_call_run_void(void* impl_msg, void* impl_obj_void)
{
  Cell* impl_obj = static_cast<Cell *>(impl_obj_void);
  CkFreeSysMsg(impl_msg);
  impl_obj->run();
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: Cell(CkMigrateMessage* impl_msg);
 */
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: Cell(void);
 */
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void createComputes(void);
 */

void CProxySection_Cell::createComputes(void) 
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg();
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Cell::idx_createComputes_void(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void createSection(void);
 */

void CProxySection_Cell::createSection(void) 
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg();
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Cell::idx_createSection_void(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void receiveParticles(const CkVec<Particle > &updates);
 */

void CProxySection_Cell::receiveParticles(const CkVec<Particle > &updates, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: const CkVec<Particle > &updates
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    //Have to cast away const-ness to get pup routine
    implP|(CkVec<Particle > &)updates;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    //Have to cast away const-ness to get pup routine
    implP|(CkVec<Particle > &)updates;
  }
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Cell::idx_receiveParticles_marshall4(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void ResumeFromSync(void);
 */

void CProxySection_Cell::ResumeFromSync(void) 
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg();
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Cell::idx_ResumeFromSync_void(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void resumeAfterLB(int resume);
 */

void CProxySection_Cell::resumeAfterLB(int resume, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: int resume
  int impl_off=0;
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|resume;
    impl_off+=implP.size();
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|resume;
  }
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Cell::idx_resumeAfterLB_marshall6(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void reduceForces(const vec3 *forces, int n);
 */

void CProxySection_Cell::reduceForces(const vec3 *forces, int n, const CkEntryOptions *impl_e_opts) 
{
  ckCheck();
  //Marshall: const vec3 *forces, int n
  int impl_off=0;
  int impl_arrstart=0;
  int impl_off_forces, impl_cnt_forces;
  impl_off_forces=impl_off=CK_ALIGN(impl_off,sizeof(vec3));
  impl_off+=(impl_cnt_forces=sizeof(vec3)*(n));
  { //Find the size of the PUP'd data
    PUP::sizer implP;
    implP|impl_off_forces;
    implP|impl_cnt_forces;
    implP|n;
    impl_arrstart=CK_ALIGN(implP.size(),16);
    impl_off+=impl_arrstart;
  }
  CkMarshallMsg *impl_msg=CkAllocateMarshallMsg(impl_off,impl_e_opts);
  { //Copy over the PUP'd data
    PUP::toMem implP((void *)impl_msg->msgBuf);
    implP|impl_off_forces;
    implP|impl_cnt_forces;
    implP|n;
  }
  char *impl_buf=impl_msg->msgBuf+impl_arrstart;
  memcpy(impl_buf+impl_off_forces,forces,impl_cnt_forces);
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Cell::idx_reduceForces_marshall7(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void run(void);
 */

void CProxySection_Cell::run(void) 
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg();
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Cell::idx_run_void(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
void CkIndex_Cell::__register(const char *s, size_t size) {
  __idx = CkRegisterChare(s, size, TypeArray);
  CkRegisterBase(__idx, CkIndex_ArrayElement::__idx);
  // REG: Cell(CkMigrateMessage* impl_msg);
  idx_Cell_CkMigrateMessage();
  CkRegisterMigCtor(__idx, idx_Cell_CkMigrateMessage());

  // REG: Cell(void);
  idx_Cell_void();
  CkRegisterDefaultCtor(__idx, idx_Cell_void());

  // REG: void createComputes(void);
  idx_createComputes_void();

  // REG: void createSection(void);
  idx_createSection_void();

  // REG: void receiveParticles(const CkVec<Particle > &updates);
  idx_receiveParticles_marshall4();

  // REG: void ResumeFromSync(void);
  idx_ResumeFromSync_void();

  // REG: void resumeAfterLB(int resume);
  idx_resumeAfterLB_marshall6();

  // REG: void reduceForces(const vec3 *forces, int n);
  idx_reduceForces_marshall7();
  idx_redn_wrapper_reduceForces_marshall7();

  // REG: void run(void);
  idx_run_void();

  Cell::__sdag_register(); 
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
void Cell::run() {
    _TRACE_END_EXECUTE(); 
    _slist_0();
    _TRACE_BEGIN_EXECUTE_DETAILED(-1, -1, _dummyEP, CkMyPe(), 0, NULL); 
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Cell::run_end() {
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Cell::_slist_0() {
    _if_0();
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Cell::_slist_0_end() {
    run_end();
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Cell::_if_0() {
    if (thisIndex.x==0 && thisIndex.y==0 && thisIndex.z==0) {
      _atomic_0();
    } else {
      _if_0_end();
    }
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Cell::_if_0_end() {
    _for_0();
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Cell::_atomic_0() {
    _TRACE_BEGIN_EXECUTE_DETAILED(-1, -1, (_sdag_idx_Cell_atomic_0()), CkMyPe(), 0, NULL); 
    
        stepTime = CkWallTimer();
      
    _TRACE_END_EXECUTE(); 
    _if_0_end();
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Cell::_for_0() {
    stepCount = 0;
    if ( stepCount < finalStepCount) {
      _slist_1();
    } else {
      _atomic_8();
    }
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Cell::_for_0_end() {
    stepCount++;
    if ( stepCount < finalStepCount) {
      _slist_1();
    } else {
      _atomic_8();
    }
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Cell::_slist_1() {
    _atomic_1();
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Cell::_slist_1_end() {
    _for_0_end();
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Cell::_atomic_1() {
    _TRACE_BEGIN_EXECUTE_DETAILED(-1, -1, (_sdag_idx_Cell_atomic_1()), CkMyPe(), 0, NULL); 
    
          sendPositions();                                                
        
    _TRACE_END_EXECUTE(); 
    _when_0();
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
int Cell::_when_0() {
    CMsgBuffer *reduceForces_buf;
    CkMarshallMsg *reduceForces_msg;

    reduceForces_buf = __cDep->getMessage(0); // SEGFAULT? __cDep = 0x0? Did you call __sdag_init() in your constructor?

    if ((reduceForces_buf != 0)) {
       reduceForces_msg = (CkMarshallMsg *)reduceForces_buf->msg;
       char *reduceForces_impl_buf=((CkMarshallMsg *)reduceForces_msg)->msgBuf;
       PUP::fromMem reduceForces_implP(reduceForces_impl_buf);
       int impl_off_forces; reduceForces_implP|impl_off_forces;
       int n; reduceForces_implP|n;
       reduceForces_impl_buf+=CK_ALIGN(reduceForces_implP.size(),16);
       vec3 *forces=(vec3 *)(reduceForces_impl_buf+impl_off_forces);
       __cDep->removeMessage(reduceForces_buf);
       delete reduceForces_buf;
       _slist_2(forces, n);
       delete reduceForces_msg;
       return 1;
    } else {
       CWhenTrigger *tr;
       tr = new CWhenTrigger(0, 1, 0, 1);
       tr->args[0] = (size_t)0xFF;
       tr->anyEntries[0] = 0;
       __cDep->Register(tr);
       return 0;
    }
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Cell::_when_0_end(vec3 * forces, int n) {
    _if_1();
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Cell::_slist_2(vec3 * forces, int n) {
    _atomic_2(forces, n);
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Cell::_slist_2_end(vec3 * forces, int n) {
    _when_0_end(forces, n);
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Cell::_atomic_2(vec3 * forces, int n) {
    _TRACE_BEGIN_EXECUTE_DETAILED(-1, -1, (_sdag_idx_Cell_atomic_2()), CkMyPe(), 0, NULL); 
    
            updateProperties(forces, n);                                                      
          
    _TRACE_END_EXECUTE(); 
    _slist_2_end(forces, n);
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Cell::_if_1() {
    if (stepCount > 0 && (stepCount %  MIGRATE_STEPCOUNT) == 0) {
      _slist_3();
    } else {
      _if_1_end();
    }
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Cell::_if_1_end() {
    _if_2();
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Cell::_slist_3() {
    _atomic_3();
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Cell::_slist_3_end() {
    _if_1_end();
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Cell::_atomic_3() {
    _TRACE_BEGIN_EXECUTE_DETAILED(-1, -1, (_sdag_idx_Cell_atomic_3()), CkMyPe(), 0, NULL); 
    
            migrateParticles();                                                         
          
    _TRACE_END_EXECUTE(); 
    _for_1();
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Cell::_for_1() {
    updateCount = 0;
    if ( updateCount < inbrs) {
      _slist_4();
    } else {
      _slist_3_end();
    }
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Cell::_for_1_end() {
    updateCount++;
    if ( updateCount < inbrs) {
      _slist_4();
    } else {
      _slist_3_end();
    }
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Cell::_slist_4() {
    _when_1();
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Cell::_slist_4_end() {
    _for_1_end();
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
int Cell::_when_1() {
    CMsgBuffer *receiveParticles_buf;
    CkMarshallMsg *receiveParticles_msg;

    receiveParticles_buf = __cDep->getMessage(1); // SEGFAULT? __cDep = 0x0? Did you call __sdag_init() in your constructor?

    if ((receiveParticles_buf != 0)) {
       receiveParticles_msg = (CkMarshallMsg *)receiveParticles_buf->msg;
       char *receiveParticles_impl_buf=((CkMarshallMsg *)receiveParticles_msg)->msgBuf;
       PUP::fromMem receiveParticles_implP(receiveParticles_impl_buf);
       CkVec<Particle > updates; receiveParticles_implP|updates;
       receiveParticles_impl_buf+=CK_ALIGN(receiveParticles_implP.size(),16);
       __cDep->removeMessage(receiveParticles_buf);
       delete receiveParticles_buf;
       _atomic_4(updates);
       delete receiveParticles_msg;
       return 1;
    } else {
       CWhenTrigger *tr;
       tr = new CWhenTrigger(1, 1, 0, 1);
       tr->args[0] = (size_t)0xFF;
       tr->anyEntries[0] = 1;
       __cDep->Register(tr);
       return 0;
    }
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Cell::_when_1_end(CkVec<Particle > updates) {
    _slist_4_end();
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Cell::_atomic_4(CkVec<Particle > updates) {
    _TRACE_BEGIN_EXECUTE_DETAILED(-1, -1, (_sdag_idx_Cell_atomic_4()), CkMyPe(), 0, NULL); 
    
              for(int i=0; i < updates.length(); i++) {
                particles.push_back(updates[i]);                                                                      
              }
            
    _TRACE_END_EXECUTE(); 
    _when_1_end(updates);
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Cell::_if_2() {
    if (stepCount && thisIndex.x==0 && thisIndex.y==0 && thisIndex.z==0 && stepCount%20==0) {
      _atomic_5();
    } else {
      _if_2_end();
    }
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Cell::_if_2_end() {
    _if_3();
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Cell::_atomic_5() {
    _TRACE_BEGIN_EXECUTE_DETAILED(-1, -1, (_sdag_idx_Cell_atomic_5()), CkMyPe(), 0, NULL); 
    
          double timer = CkWallTimer();
          CkPrintf("Step %d Benchmark Time %lf ms/step\n", 
              stepCount, ((timer - stepTime)/20)*1000);
          stepTime = CkWallTimer();
        
    _TRACE_END_EXECUTE(); 
    _if_2_end();
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Cell::_if_3() {
    if (stepCount >= firstLdbStep && (stepCount - firstLdbStep) % ldbPeriod == 0) {
      _slist_5();
    } else {
      _if_3_end();
    }
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Cell::_if_3_end() {
    _slist_1_end();
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Cell::_slist_5() {
    _atomic_6();
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Cell::_slist_5_end() {
    _if_3_end();
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Cell::_atomic_6() {
    _TRACE_BEGIN_EXECUTE_DETAILED(-1, -1, (_sdag_idx_Cell_atomic_6()), CkMyPe(), 0, NULL); 
    
            AtSync();
          
    _TRACE_END_EXECUTE(); 
    _when_2();
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
int Cell::_when_2() {
    CMsgBuffer *resumeAfterLB_buf;
    CkMarshallMsg *resumeAfterLB_msg;

    resumeAfterLB_buf = __cDep->getMessage(2); // SEGFAULT? __cDep = 0x0? Did you call __sdag_init() in your constructor?

    if ((resumeAfterLB_buf != 0)) {
       resumeAfterLB_msg = (CkMarshallMsg *)resumeAfterLB_buf->msg;
       char *resumeAfterLB_impl_buf=((CkMarshallMsg *)resumeAfterLB_msg)->msgBuf;
       PUP::fromMem resumeAfterLB_implP(resumeAfterLB_impl_buf);
       int resume; resumeAfterLB_implP|resume;
       resumeAfterLB_impl_buf+=CK_ALIGN(resumeAfterLB_implP.size(),16);
       __cDep->removeMessage(resumeAfterLB_buf);
       delete resumeAfterLB_buf;
       _atomic_7(resume);
       delete resumeAfterLB_msg;
       return 1;
    } else {
       CWhenTrigger *tr;
       tr = new CWhenTrigger(2, 1, 0, 1);
       tr->args[0] = (size_t)0xFF;
       tr->anyEntries[0] = 2;
       __cDep->Register(tr);
       return 0;
    }
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Cell::_when_2_end(int resume) {
    _slist_5_end();
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Cell::_atomic_7(int resume) {
    _TRACE_BEGIN_EXECUTE_DETAILED(-1, -1, (_sdag_idx_Cell_atomic_7()), CkMyPe(), 0, NULL); 
    
            stepTime = CkWallTimer();
          
    _TRACE_END_EXECUTE(); 
    _when_2_end(resume);
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Cell::_atomic_8() {
    _TRACE_BEGIN_EXECUTE_DETAILED(-1, -1, (_sdag_idx_Cell_atomic_8()), CkMyPe(), 0, NULL); 
    
        int num;
        contribute(sizeof(int),&num,CkReduction::max_int,CkCallback(CkReductionTarget(Main,allDone),mainProxy));
                                                                     
      
    _TRACE_END_EXECUTE(); 
    _slist_0_end();
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Cell::reduceForces(vec3 *forces, int n){
    CWhenTrigger *tr;
    void* _bgParentLog = NULL;
    CMsgBuffer* cmsgbuf;
    int impl_off=0; int impl_arrstart=0;
    int impl_off_forces, impl_cnt_forces;
    impl_off_forces=impl_off=CK_ALIGN(impl_off,sizeof(vec3));
    impl_off+=(impl_cnt_forces=sizeof(vec3)*(n));
    {
      PUP::sizer implP1;
      implP1|impl_off_forces;
      implP1|n;
      impl_arrstart=CK_ALIGN(implP1.size(),16);
      impl_off+=impl_arrstart;
    }
    CkMarshallMsg *impl_msg1=CkAllocateMarshallMsg(impl_off,NULL);
    {
      PUP::toMem implP1((void *)impl_msg1->msgBuf);
      implP1|impl_off_forces;
      implP1|n;
    }
    char *impl_buf1=impl_msg1->msgBuf+impl_arrstart;
    memcpy(impl_buf1+impl_off_forces,forces,impl_cnt_forces);
    cmsgbuf = __cDep->bufferMessage(0, (void *) impl_msg1, (void*) _bgParentLog, 0);
    tr = __cDep->getTrigger(0, 0);
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
void Cell::receiveParticles(CkVec<Particle > updates){
    CWhenTrigger *tr;
    void* _bgParentLog = NULL;
    CMsgBuffer* cmsgbuf;
    int impl_off=0; int impl_arrstart=0;
    {
      PUP::sizer implP1;
      implP1|updates;
      impl_off+=implP1.size();
    }
    CkMarshallMsg *impl_msg1=CkAllocateMarshallMsg(impl_off,NULL);
    {
      PUP::toMem implP1((void *)impl_msg1->msgBuf);
      implP1|updates;
    }
    cmsgbuf = __cDep->bufferMessage(1, (void *) impl_msg1, (void*) _bgParentLog, 0);
    tr = __cDep->getTrigger(1, 0);
    if (tr == 0)
      return;
    _TRACE_END_EXECUTE(); 
    {
        tr->args[0] = 0;
        _when_1();
        delete tr;
        _TRACE_BEGIN_EXECUTE_DETAILED(-1, -1, _dummyEP, CkMyPe(), 0, NULL); 
        return;
    }
}

#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
void Cell::resumeAfterLB(int resume){
    CWhenTrigger *tr;
    void* _bgParentLog = NULL;
    CMsgBuffer* cmsgbuf;
    int impl_off=0; int impl_arrstart=0;
    {
      PUP::sizer implP1;
      implP1|resume;
      impl_off+=implP1.size();
    }
    CkMarshallMsg *impl_msg1=CkAllocateMarshallMsg(impl_off,NULL);
    {
      PUP::toMem implP1((void *)impl_msg1->msgBuf);
      implP1|resume;
    }
    cmsgbuf = __cDep->bufferMessage(2, (void *) impl_msg1, (void*) _bgParentLog, 0);
    tr = __cDep->getTrigger(2, 0);
    if (tr == 0)
      return;
    _TRACE_END_EXECUTE(); 
    {
        tr->args[0] = 0;
        _when_2();
        delete tr;
        _TRACE_BEGIN_EXECUTE_DETAILED(-1, -1, _dummyEP, CkMyPe(), 0, NULL); 
        return;
    }
}

#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
void Cell::__sdag_init() {
    __cDep = new CDep(3,3);
    __cDep->addDepends(0,0);
    __cDep->addDepends(1,1);
    __cDep->addDepends(2,2);
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Cell::__sdag_register() {
    (void)_sdag_idx_Cell_atomic_0();
    (void)_sdag_idx_Cell_atomic_1();
    (void)_sdag_idx_Cell_atomic_2();
    (void)_sdag_idx_Cell_atomic_3();
    (void)_sdag_idx_Cell_atomic_4();
    (void)_sdag_idx_Cell_atomic_5();
    (void)_sdag_idx_Cell_atomic_6();
    (void)_sdag_idx_Cell_atomic_7();
    (void)_sdag_idx_Cell_atomic_8();
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
int Cell::_sdag_idx_Cell_atomic_0() {
  static int epidx = _sdag_reg_Cell_atomic_0();
  return epidx;
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
int Cell::_sdag_reg_Cell_atomic_0() {
  return CkRegisterEp("Cell_atomic_0", NULL, 0, CkIndex_Cell::__idx, 0);
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
int Cell::_sdag_idx_Cell_atomic_1() {
  static int epidx = _sdag_reg_Cell_atomic_1();
  return epidx;
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
int Cell::_sdag_reg_Cell_atomic_1() {
  return CkRegisterEp("Cell_atomic_1", NULL, 0, CkIndex_Cell::__idx, 0);
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
int Cell::_sdag_idx_Cell_atomic_2() {
  static int epidx = _sdag_reg_Cell_atomic_2();
  return epidx;
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
int Cell::_sdag_reg_Cell_atomic_2() {
  return CkRegisterEp("Cell_atomic_2", NULL, 0, CkIndex_Cell::__idx, 0);
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
int Cell::_sdag_idx_Cell_atomic_3() {
  static int epidx = _sdag_reg_Cell_atomic_3();
  return epidx;
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
int Cell::_sdag_reg_Cell_atomic_3() {
  return CkRegisterEp("Cell_atomic_3", NULL, 0, CkIndex_Cell::__idx, 0);
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
int Cell::_sdag_idx_Cell_atomic_4() {
  static int epidx = _sdag_reg_Cell_atomic_4();
  return epidx;
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
int Cell::_sdag_reg_Cell_atomic_4() {
  return CkRegisterEp("Cell_atomic_4", NULL, 0, CkIndex_Cell::__idx, 0);
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
int Cell::_sdag_idx_Cell_atomic_5() {
  static int epidx = _sdag_reg_Cell_atomic_5();
  return epidx;
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
int Cell::_sdag_reg_Cell_atomic_5() {
  return CkRegisterEp("Cell_atomic_5", NULL, 0, CkIndex_Cell::__idx, 0);
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
int Cell::_sdag_idx_Cell_atomic_6() {
  static int epidx = _sdag_reg_Cell_atomic_6();
  return epidx;
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
int Cell::_sdag_reg_Cell_atomic_6() {
  return CkRegisterEp("Cell_atomic_6", NULL, 0, CkIndex_Cell::__idx, 0);
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
int Cell::_sdag_idx_Cell_atomic_7() {
  static int epidx = _sdag_reg_Cell_atomic_7();
  return epidx;
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
int Cell::_sdag_reg_Cell_atomic_7() {
  return CkRegisterEp("Cell_atomic_7", NULL, 0, CkIndex_Cell::__idx, 0);
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
int Cell::_sdag_idx_Cell_atomic_8() {
  static int epidx = _sdag_reg_Cell_atomic_8();
  return epidx;
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
int Cell::_sdag_reg_Cell_atomic_8() {
  return CkRegisterEp("Cell_atomic_8", NULL, 0, CkIndex_Cell::__idx, 0);
}
#endif /* CK_TEMPLATES_ONLY */



/* DEFS: array Compute: ArrayElement{
Compute(CkMigrateMessage* impl_msg);
Compute(void);
void ResumeFromSync(void);
void calculateForces(ParticleDataMsg* impl_msg);
void run(void);
};
 */
#ifndef CK_TEMPLATES_ONLY
 int CkIndex_Compute::__idx=0;
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
/* DEFS: Compute(CkMigrateMessage* impl_msg);
 */
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: Compute(void);
 */

void CProxyElement_Compute::insert(int onPE)
{ 
  void *impl_msg = CkAllocSysMsg();
   ckInsert((CkArrayMessage *)impl_msg,CkIndex_Compute::idx_Compute_void(),onPE);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void ResumeFromSync(void);
 */

void CProxyElement_Compute::ResumeFromSync(void) 
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg();
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Compute::idx_ResumeFromSync_void(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void calculateForces(ParticleDataMsg* impl_msg);
 */

void CProxyElement_Compute::calculateForces(ParticleDataMsg* impl_msg) 
{
  ckCheck();
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Compute::idx_calculateForces_ParticleDataMsg(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void run(void);
 */

void CProxyElement_Compute::run(void) 
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg();
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Compute::idx_run_void(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: Compute(CkMigrateMessage* impl_msg);
 */

// Entry point registration function

int CkIndex_Compute::reg_Compute_CkMigrateMessage() {
  int epidx = CkRegisterEp("Compute(CkMigrateMessage* impl_msg)",
      _call_Compute_CkMigrateMessage, 0, __idx, 0);
  return epidx;
}


void CkIndex_Compute::_call_Compute_CkMigrateMessage(void* impl_msg, void* impl_obj_void)
{
  Compute* impl_obj = static_cast<Compute *>(impl_obj_void);
  new (impl_obj) Compute((CkMigrateMessage*)impl_msg);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: Compute(void);
 */

CkArrayID CProxy_Compute::ckNew(const CkArrayOptions &opts)
{ 
  void *impl_msg = CkAllocSysMsg();
   return ckCreateArray((CkArrayMessage *)impl_msg,CkIndex_Compute::idx_Compute_void(),opts);
}

// Entry point registration function

int CkIndex_Compute::reg_Compute_void() {
  int epidx = CkRegisterEp("Compute(void)",
      _call_Compute_void, 0, __idx, 0);
  return epidx;
}


void CkIndex_Compute::_call_Compute_void(void* impl_msg, void* impl_obj_void)
{
  Compute* impl_obj = static_cast<Compute *>(impl_obj_void);
  CkFreeSysMsg(impl_msg);
  new (impl_obj) Compute();
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void ResumeFromSync(void);
 */

void CProxy_Compute::ResumeFromSync(void) 
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg();
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckBroadcast(impl_amsg, CkIndex_Compute::idx_ResumeFromSync_void(),0);
}

// Entry point registration function

int CkIndex_Compute::reg_ResumeFromSync_void() {
  int epidx = CkRegisterEp("ResumeFromSync(void)",
      _call_ResumeFromSync_void, 0, __idx, 0);
  return epidx;
}


void CkIndex_Compute::_call_ResumeFromSync_void(void* impl_msg, void* impl_obj_void)
{
  Compute* impl_obj = static_cast<Compute *>(impl_obj_void);
  CkFreeSysMsg(impl_msg);
  impl_obj->ResumeFromSync();
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void calculateForces(ParticleDataMsg* impl_msg);
 */

void CProxy_Compute::calculateForces(ParticleDataMsg* impl_msg) 
{
  ckCheck();
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckBroadcast(impl_amsg, CkIndex_Compute::idx_calculateForces_ParticleDataMsg(),0);
}

// Entry point registration function

int CkIndex_Compute::reg_calculateForces_ParticleDataMsg() {
  int epidx = CkRegisterEp("calculateForces(ParticleDataMsg* impl_msg)",
      _call_calculateForces_ParticleDataMsg, CMessage_ParticleDataMsg::__idx, __idx, 0);
  return epidx;
}


void CkIndex_Compute::_call_calculateForces_ParticleDataMsg(void* impl_msg, void* impl_obj_void)
{
  Compute* impl_obj = static_cast<Compute *>(impl_obj_void);
  impl_obj->calculateForces((ParticleDataMsg*)impl_msg);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void run(void);
 */

void CProxy_Compute::run(void) 
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg();
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckBroadcast(impl_amsg, CkIndex_Compute::idx_run_void(),0);
}

// Entry point registration function

int CkIndex_Compute::reg_run_void() {
  int epidx = CkRegisterEp("run(void)",
      _call_run_void, 0, __idx, 0);
  return epidx;
}


void CkIndex_Compute::_call_run_void(void* impl_msg, void* impl_obj_void)
{
  Compute* impl_obj = static_cast<Compute *>(impl_obj_void);
  CkFreeSysMsg(impl_msg);
  impl_obj->run();
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: Compute(CkMigrateMessage* impl_msg);
 */
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: Compute(void);
 */
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void ResumeFromSync(void);
 */

void CProxySection_Compute::ResumeFromSync(void) 
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg();
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Compute::idx_ResumeFromSync_void(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void calculateForces(ParticleDataMsg* impl_msg);
 */

void CProxySection_Compute::calculateForces(ParticleDataMsg* impl_msg) 
{
  ckCheck();
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Compute::idx_calculateForces_ParticleDataMsg(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
/* DEFS: void run(void);
 */

void CProxySection_Compute::run(void) 
{
  ckCheck();
  void *impl_msg = CkAllocSysMsg();
  CkArrayMessage *impl_amsg=(CkArrayMessage *)impl_msg;
  impl_amsg->array_setIfNotThere(CkArray_IfNotThere_buffer);
  ckSend(impl_amsg, CkIndex_Compute::idx_run_void(),0);
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
void CkIndex_Compute::__register(const char *s, size_t size) {
  __idx = CkRegisterChare(s, size, TypeArray);
  CkRegisterBase(__idx, CkIndex_ArrayElement::__idx);
  // REG: Compute(CkMigrateMessage* impl_msg);
  idx_Compute_CkMigrateMessage();
  CkRegisterMigCtor(__idx, idx_Compute_CkMigrateMessage());

  // REG: Compute(void);
  idx_Compute_void();
  CkRegisterDefaultCtor(__idx, idx_Compute_void());

  // REG: void ResumeFromSync(void);
  idx_ResumeFromSync_void();

  // REG: void calculateForces(ParticleDataMsg* impl_msg);
  idx_calculateForces_ParticleDataMsg();

  // REG: void run(void);
  idx_run_void();

  Compute::__sdag_register(); 
}
#endif /* CK_TEMPLATES_ONLY */

#ifndef CK_TEMPLATES_ONLY
void Compute::run() {
    _TRACE_END_EXECUTE(); 
    _slist_0();
    _TRACE_BEGIN_EXECUTE_DETAILED(-1, -1, _dummyEP, CkMyPe(), 0, NULL); 
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Compute::run_end() {
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Compute::_slist_0() {
    _for_0();
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Compute::_slist_0_end() {
    run_end();
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Compute::_for_0() {
    stepCount = 0;
    if ( stepCount < finalStepCount) {
      _slist_1();
    } else {
      _slist_0_end();
    }
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Compute::_for_0_end() {
    stepCount++;
    if ( stepCount < finalStepCount) {
      _slist_1();
    } else {
      _slist_0_end();
    }
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Compute::_slist_1() {
    _when_0();
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Compute::_slist_1_end() {
    _for_0_end();
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
int Compute::_when_0() {
    CMsgBuffer *msg_buf;
    ParticleDataMsg* msg;

    msg_buf = __cDep->getMessage(0); // SEGFAULT? __cDep = 0x0? Did you call __sdag_init() in your constructor?

    if ((msg_buf != 0)) {
       msg = (ParticleDataMsg*) msg_buf->msg;
       __cDep->removeMessage(msg_buf);
       delete msg_buf;
       _atomic_0(msg);
       return 1;
    } else {
       CWhenTrigger *tr;
       tr = new CWhenTrigger(0, 1, 0, 1);
       tr->args[0] = (size_t)0xFF;
       tr->anyEntries[0] = 0;
       __cDep->Register(tr);
       return 0;
    }
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Compute::_when_0_end(ParticleDataMsg* msg) {
    _if_0();
    CmiFree(UsrToEnv(msg));
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Compute::_atomic_0(ParticleDataMsg* msg) {
    _TRACE_BEGIN_EXECUTE_DETAILED(-1, -1, (_sdag_idx_Compute_atomic_0()), CkMyPe(), 0, NULL); 
    
          interact(msg);
        
    _TRACE_END_EXECUTE(); 
    _when_0_end(msg);
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Compute::_if_0() {
    if (thisIndex.x1!=thisIndex.x2 || thisIndex.y1!=thisIndex.y2 || thisIndex.z1!=thisIndex.z2) {
      _slist_2();
    } else {
      _if_0_end();
    }
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Compute::_if_0_end() {
    _if_1();
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Compute::_slist_2() {
    _when_1();
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Compute::_slist_2_end() {
    _if_0_end();
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
int Compute::_when_1() {
    CMsgBuffer *msg_buf;
    ParticleDataMsg* msg;

    msg_buf = __cDep->getMessage(0); // SEGFAULT? __cDep = 0x0? Did you call __sdag_init() in your constructor?

    if ((msg_buf != 0)) {
       msg = (ParticleDataMsg*) msg_buf->msg;
       __cDep->removeMessage(msg_buf);
       delete msg_buf;
       _atomic_1(msg);
       return 1;
    } else {
       CWhenTrigger *tr;
       tr = new CWhenTrigger(1, 1, 0, 1);
       tr->args[0] = (size_t)0xFF;
       tr->anyEntries[0] = 0;
       __cDep->Register(tr);
       return 0;
    }
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Compute::_when_1_end(ParticleDataMsg* msg) {
    _slist_2_end();
    CmiFree(UsrToEnv(msg));
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Compute::_atomic_1(ParticleDataMsg* msg) {
    _TRACE_BEGIN_EXECUTE_DETAILED(-1, -1, (_sdag_idx_Compute_atomic_1()), CkMyPe(), 0, NULL); 
    
            interact(msg);
          
    _TRACE_END_EXECUTE(); 
    _when_1_end(msg);
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Compute::_if_1() {
    if (stepCount >= firstLdbStep && (stepCount - firstLdbStep) % ldbPeriod== 0) {
      _atomic_2();
    } else {
      _if_1_end();
    }
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Compute::_if_1_end() {
    _slist_1_end();
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Compute::_atomic_2() {
    _TRACE_BEGIN_EXECUTE_DETAILED(-1, -1, (_sdag_idx_Compute_atomic_2()), CkMyPe(), 0, NULL); 
    
          AtSync();
        
    _TRACE_END_EXECUTE(); 
    _if_1_end();
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Compute::calculateForces(ParticleDataMsg* msg_msg){
    CWhenTrigger *tr;
    void* _bgParentLog = NULL;
    CMsgBuffer* cmsgbuf;
    CmiReference(UsrToEnv(msg_msg));
    cmsgbuf = __cDep->bufferMessage(0, (void *) msg_msg,  (void *) _bgParentLog, 0);
    tr = __cDep->getTrigger(0, 0);
    if (tr == 0)
      return;
    _TRACE_END_EXECUTE(); 
    switch(tr->whenID) {
      case 0:
      {
        tr->args[0] = 0;
        _when_0();
        delete tr;
        _TRACE_BEGIN_EXECUTE_DETAILED(-1, -1, _dummyEP, CkMyPe(), 0, NULL); 
        return;
      }
      case 1:
      {
        tr->args[0] = 0;
        _when_1();
        delete tr;
        _TRACE_BEGIN_EXECUTE_DETAILED(-1, -1, _dummyEP, CkMyPe(), 0, NULL); 
        return;
      }
    }
}

#endif /* CK_TEMPLATES_ONLY */
#ifndef CK_TEMPLATES_ONLY
void Compute::__sdag_init() {
    __cDep = new CDep(1,2);
    __cDep->addDepends(0,0);
    __cDep->addDepends(1,0);
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
void Compute::__sdag_register() {
    (void)_sdag_idx_Compute_atomic_0();
    (void)_sdag_idx_Compute_atomic_1();
    (void)_sdag_idx_Compute_atomic_2();
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
int Compute::_sdag_idx_Compute_atomic_0() {
  static int epidx = _sdag_reg_Compute_atomic_0();
  return epidx;
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
int Compute::_sdag_reg_Compute_atomic_0() {
  return CkRegisterEp("Compute_atomic_0", NULL, 0, CkIndex_Compute::__idx, 0);
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
int Compute::_sdag_idx_Compute_atomic_1() {
  static int epidx = _sdag_reg_Compute_atomic_1();
  return epidx;
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
int Compute::_sdag_reg_Compute_atomic_1() {
  return CkRegisterEp("Compute_atomic_1", NULL, 0, CkIndex_Compute::__idx, 0);
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
int Compute::_sdag_idx_Compute_atomic_2() {
  static int epidx = _sdag_reg_Compute_atomic_2();
  return epidx;
}
#endif /* CK_TEMPLATES_ONLY */


#ifndef CK_TEMPLATES_ONLY
int Compute::_sdag_reg_Compute_atomic_2() {
  return CkRegisterEp("Compute_atomic_2", NULL, 0, CkIndex_Compute::__idx, 0);
}
#endif /* CK_TEMPLATES_ONLY */



#ifndef CK_TEMPLATES_ONLY
void _registerleanmd(void)
{
  static int _done = 0; if(_done) return; _done = 1;
  CkRegisterReadonly("mainProxy","CProxy_Main",sizeof(mainProxy),(void *) &mainProxy,__xlater_roPup_mainProxy);

  CkRegisterReadonly("cellArray","CProxy_Cell",sizeof(cellArray),(void *) &cellArray,__xlater_roPup_cellArray);

  CkRegisterReadonly("computeArray","CProxy_Compute",sizeof(computeArray),(void *) &computeArray,__xlater_roPup_computeArray);

  CkRegisterReadonly("mCastGrpID","CkGroupID",sizeof(mCastGrpID),(void *) &mCastGrpID,__xlater_roPup_mCastGrpID);

  CkRegisterReadonly("cellArrayDimX","int",sizeof(cellArrayDimX),(void *) &cellArrayDimX,__xlater_roPup_cellArrayDimX);

  CkRegisterReadonly("cellArrayDimY","int",sizeof(cellArrayDimY),(void *) &cellArrayDimY,__xlater_roPup_cellArrayDimY);

  CkRegisterReadonly("cellArrayDimZ","int",sizeof(cellArrayDimZ),(void *) &cellArrayDimZ,__xlater_roPup_cellArrayDimZ);

  CkRegisterReadonly("finalStepCount","int",sizeof(finalStepCount),(void *) &finalStepCount,__xlater_roPup_finalStepCount);

  CkRegisterReadonly("firstLdbStep","int",sizeof(firstLdbStep),(void *) &firstLdbStep,__xlater_roPup_firstLdbStep);

  CkRegisterReadonly("ldbPeriod","int",sizeof(ldbPeriod),(void *) &ldbPeriod,__xlater_roPup_ldbPeriod);

/* REG: mainchare Main: Chare{
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
  CkIndex_Main::__register("Main", sizeof(Main));

/* REG: message ParticleDataMsg{
vec3 part[];
}
;
*/
CMessage_ParticleDataMsg::__register("ParticleDataMsg", sizeof(ParticleDataMsg),(CkPackFnPtr) ParticleDataMsg::pack,(CkUnpackFnPtr) ParticleDataMsg::unpack);

/* REG: array Cell: ArrayElement{
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
  CkIndex_Cell::__register("Cell", sizeof(Cell));

/* REG: array Compute: ArrayElement{
Compute(CkMigrateMessage* impl_msg);
Compute(void);
void ResumeFromSync(void);
void calculateForces(ParticleDataMsg* impl_msg);
void run(void);
};
*/
  CkIndex_Compute::__register("Compute", sizeof(Compute));

}
extern "C" void CkRegisterMainModule(void) {
  _registerleanmd();
}
#endif /* CK_TEMPLATES_ONLY */
