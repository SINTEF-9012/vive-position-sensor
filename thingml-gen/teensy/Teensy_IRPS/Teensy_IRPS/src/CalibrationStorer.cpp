#include "CalibrationStorer.h"
/*****************************************************************************
 * Implementation for type : CalibrationStorer
 *****************************************************************************/


// BEGIN: Code from the c_global annotation CalibrationStorer

    #define STORE_KEY 42

// END: Code from the c_global annotation CalibrationStorer

// Declaration of prototypes:
//Prototypes: State Machine
void CalibrationStorer_Loader_OnExit(int state, struct CalibrationStorer_Instance *_instance);
//Prototypes: Message Sending
void CalibrationStorer_send_storeReader_readByte(struct CalibrationStorer_Instance *_instance, uint8_t id);
void CalibrationStorer_send_storeReader_readConfig(struct CalibrationStorer_Instance *_instance);
void CalibrationStorer_send_storeWriter_writeByte(struct CalibrationStorer_Instance *_instance, uint8_t id, uint8_t val);
void CalibrationStorer_send_storeWriter_writeConfig(struct CalibrationStorer_Instance *_instance, double bx, double by, double bz, double brx, double bry, double brz, double cx, double cy, double cz, double crx, double cry, double crz);
void CalibrationStorer_send_storer_endload(struct CalibrationStorer_Instance *_instance);
void CalibrationStorer_send_storer_errorload(struct CalibrationStorer_Instance *_instance);
void CalibrationStorer_send_progress_storerToIdle(struct CalibrationStorer_Instance *_instance);
//Prototypes: Function
// Declaration of functions:

// Sessions functionss:


// On Entry Actions:
void CalibrationStorer_Loader_OnEntry(int state, struct CalibrationStorer_Instance *_instance) {
switch(state) {
case CALIBRATIONSTORER_LOADER_STATE:{
_instance->CalibrationStorer_Loader_State = CALIBRATIONSTORER_LOADER_IDLE_STATE;
CalibrationStorer_Loader_OnEntry(_instance->CalibrationStorer_Loader_State, _instance);
break;
}
case CALIBRATIONSTORER_LOADER_IDLE_STATE:{
break;
}
case CALIBRATIONSTORER_LOADER_LOAD_STATE:{
CalibrationStorer_send_storeReader_readByte(_instance, 0);
break;
}
case CALIBRATIONSTORER_LOADER_SAVE_STATE:{
CalibrationStorer_send_storeWriter_writeByte(_instance, 0, STORE_KEY);
CalibrationStorer_send_storeWriter_writeConfig(_instance, posePb.position.getX(), posePb.position.getY(), posePb.position.getZ(), posePb.orientation.getX(), posePb.orientation.getY(), posePb.orientation.getZ(), posePc.position.getX(), posePc.position.getY(), posePc.position.getZ(), posePc.orientation.getX(), posePc.orientation.getY(), posePc.orientation.getZ());
break;
}
default: break;
}
}

// On Exit Actions:
void CalibrationStorer_Loader_OnExit(int state, struct CalibrationStorer_Instance *_instance) {
switch(state) {
case CALIBRATIONSTORER_LOADER_STATE:{
CalibrationStorer_Loader_OnExit(_instance->CalibrationStorer_Loader_State, _instance);
break;}
case CALIBRATIONSTORER_LOADER_IDLE_STATE:{
break;}
case CALIBRATIONSTORER_LOADER_LOAD_STATE:{
break;}
case CALIBRATIONSTORER_LOADER_SAVE_STATE:{
break;}
default: break;
}
}

// Event Handlers for incoming messages:
void CalibrationStorer_handle_storer_load(struct CalibrationStorer_Instance *_instance) {
if(!(_instance->active)) return;
//Region Loader
uint8_t CalibrationStorer_Loader_State_event_consumed = 0;
if (_instance->CalibrationStorer_Loader_State == CALIBRATIONSTORER_LOADER_IDLE_STATE) {
if (CalibrationStorer_Loader_State_event_consumed == 0 && 1) {
CalibrationStorer_Loader_OnExit(CALIBRATIONSTORER_LOADER_IDLE_STATE, _instance);
_instance->CalibrationStorer_Loader_State = CALIBRATIONSTORER_LOADER_LOAD_STATE;
CalibrationStorer_Loader_OnEntry(CALIBRATIONSTORER_LOADER_LOAD_STATE, _instance);
CalibrationStorer_Loader_State_event_consumed = 1;
}
}
//End Region Loader
//End dsregion Loader
//Session list: 
}
void CalibrationStorer_handle_storer_save(struct CalibrationStorer_Instance *_instance) {
if(!(_instance->active)) return;
//Region Loader
uint8_t CalibrationStorer_Loader_State_event_consumed = 0;
if (_instance->CalibrationStorer_Loader_State == CALIBRATIONSTORER_LOADER_IDLE_STATE) {
if (CalibrationStorer_Loader_State_event_consumed == 0 && 1) {
CalibrationStorer_Loader_OnExit(CALIBRATIONSTORER_LOADER_IDLE_STATE, _instance);
_instance->CalibrationStorer_Loader_State = CALIBRATIONSTORER_LOADER_SAVE_STATE;
CalibrationStorer_Loader_OnEntry(CALIBRATIONSTORER_LOADER_SAVE_STATE, _instance);
CalibrationStorer_Loader_State_event_consumed = 1;
}
}
//End Region Loader
//End dsregion Loader
//Session list: 
}
void CalibrationStorer_handle_progress_storerToIdle(struct CalibrationStorer_Instance *_instance) {
if(!(_instance->active)) return;
//Region Loader
uint8_t CalibrationStorer_Loader_State_event_consumed = 0;
if (_instance->CalibrationStorer_Loader_State == CALIBRATIONSTORER_LOADER_LOAD_STATE) {
if (CalibrationStorer_Loader_State_event_consumed == 0 && 1) {
CalibrationStorer_Loader_OnExit(CALIBRATIONSTORER_LOADER_LOAD_STATE, _instance);
_instance->CalibrationStorer_Loader_State = CALIBRATIONSTORER_LOADER_IDLE_STATE;
CalibrationStorer_Loader_OnEntry(CALIBRATIONSTORER_LOADER_IDLE_STATE, _instance);
CalibrationStorer_Loader_State_event_consumed = 1;
}
}
//End Region Loader
//End dsregion Loader
//Session list: 
}
void CalibrationStorer_handle_storeWriter_configWritten(struct CalibrationStorer_Instance *_instance) {
if(!(_instance->active)) return;
//Region Loader
uint8_t CalibrationStorer_Loader_State_event_consumed = 0;
if (_instance->CalibrationStorer_Loader_State == CALIBRATIONSTORER_LOADER_SAVE_STATE) {
if (CalibrationStorer_Loader_State_event_consumed == 0 && 1) {
CalibrationStorer_Loader_OnExit(CALIBRATIONSTORER_LOADER_SAVE_STATE, _instance);
_instance->CalibrationStorer_Loader_State = CALIBRATIONSTORER_LOADER_IDLE_STATE;
CalibrationStorer_Loader_OnEntry(CALIBRATIONSTORER_LOADER_IDLE_STATE, _instance);
CalibrationStorer_Loader_State_event_consumed = 1;
}
}
//End Region Loader
//End dsregion Loader
//Session list: 
}
void CalibrationStorer_handle_storeReader_configRead(struct CalibrationStorer_Instance *_instance, double bx, double by, double bz, double brx, double bry, double brz, double cx, double cy, double cz, double crx, double cry, double crz) {
if(!(_instance->active)) return;
//Region Loader
uint8_t CalibrationStorer_Loader_State_event_consumed = 0;
if (_instance->CalibrationStorer_Loader_State == CALIBRATIONSTORER_LOADER_LOAD_STATE) {
if (CalibrationStorer_Loader_State_event_consumed == 0 && 1) {
CalibrationStorer_Loader_OnExit(CALIBRATIONSTORER_LOADER_LOAD_STATE, _instance);
_instance->CalibrationStorer_Loader_State = CALIBRATIONSTORER_LOADER_IDLE_STATE;

                posePb = Pose({bx, by, bz}, {brx, bry, brz});
                posePc = Pose({cx, cy, cz}, {crx, cry, crz});
			    pointError = 0;
			    calibrationFailed = false;
			    
CalibrationStorer_send_storer_endload(_instance);
CalibrationStorer_Loader_OnEntry(CALIBRATIONSTORER_LOADER_IDLE_STATE, _instance);
CalibrationStorer_Loader_State_event_consumed = 1;
}
}
//End Region Loader
//End dsregion Loader
//Session list: 
}
void CalibrationStorer_handle_storeReader_byteRead(struct CalibrationStorer_Instance *_instance, uint8_t val) {
if(!(_instance->active)) return;
//Region Loader
uint8_t CalibrationStorer_Loader_State_event_consumed = 0;
if (_instance->CalibrationStorer_Loader_State == CALIBRATIONSTORER_LOADER_LOAD_STATE) {
if (CalibrationStorer_Loader_State_event_consumed == 0 && 1) {
if(val == STORE_KEY) {
CalibrationStorer_send_storeReader_readConfig(_instance);

} else {
CalibrationStorer_send_storer_errorload(_instance);
CalibrationStorer_send_progress_storerToIdle(_instance);

}
CalibrationStorer_Loader_State_event_consumed = 1;
}
}
//End Region Loader
//End dsregion Loader
//Session list: 
}

// Observers for outgoing messages:
void (*external_CalibrationStorer_send_storeReader_readByte_listener)(struct CalibrationStorer_Instance *, uint8_t)= 0x0;
void (*CalibrationStorer_send_storeReader_readByte_listener)(struct CalibrationStorer_Instance *, uint8_t)= 0x0;
void register_external_CalibrationStorer_send_storeReader_readByte_listener(void (*_listener)(struct CalibrationStorer_Instance *, uint8_t)){
external_CalibrationStorer_send_storeReader_readByte_listener = _listener;
}
void register_CalibrationStorer_send_storeReader_readByte_listener(void (*_listener)(struct CalibrationStorer_Instance *, uint8_t)){
CalibrationStorer_send_storeReader_readByte_listener = _listener;
}
void CalibrationStorer_send_storeReader_readByte(struct CalibrationStorer_Instance *_instance, uint8_t id){
if (CalibrationStorer_send_storeReader_readByte_listener != 0x0) CalibrationStorer_send_storeReader_readByte_listener(_instance, id);
if (external_CalibrationStorer_send_storeReader_readByte_listener != 0x0) external_CalibrationStorer_send_storeReader_readByte_listener(_instance, id);
;
}
void (*external_CalibrationStorer_send_storeReader_readConfig_listener)(struct CalibrationStorer_Instance *)= 0x0;
void (*CalibrationStorer_send_storeReader_readConfig_listener)(struct CalibrationStorer_Instance *)= 0x0;
void register_external_CalibrationStorer_send_storeReader_readConfig_listener(void (*_listener)(struct CalibrationStorer_Instance *)){
external_CalibrationStorer_send_storeReader_readConfig_listener = _listener;
}
void register_CalibrationStorer_send_storeReader_readConfig_listener(void (*_listener)(struct CalibrationStorer_Instance *)){
CalibrationStorer_send_storeReader_readConfig_listener = _listener;
}
void CalibrationStorer_send_storeReader_readConfig(struct CalibrationStorer_Instance *_instance){
if (CalibrationStorer_send_storeReader_readConfig_listener != 0x0) CalibrationStorer_send_storeReader_readConfig_listener(_instance);
if (external_CalibrationStorer_send_storeReader_readConfig_listener != 0x0) external_CalibrationStorer_send_storeReader_readConfig_listener(_instance);
;
}
void (*external_CalibrationStorer_send_storeWriter_writeByte_listener)(struct CalibrationStorer_Instance *, uint8_t, uint8_t)= 0x0;
void (*CalibrationStorer_send_storeWriter_writeByte_listener)(struct CalibrationStorer_Instance *, uint8_t, uint8_t)= 0x0;
void register_external_CalibrationStorer_send_storeWriter_writeByte_listener(void (*_listener)(struct CalibrationStorer_Instance *, uint8_t, uint8_t)){
external_CalibrationStorer_send_storeWriter_writeByte_listener = _listener;
}
void register_CalibrationStorer_send_storeWriter_writeByte_listener(void (*_listener)(struct CalibrationStorer_Instance *, uint8_t, uint8_t)){
CalibrationStorer_send_storeWriter_writeByte_listener = _listener;
}
void CalibrationStorer_send_storeWriter_writeByte(struct CalibrationStorer_Instance *_instance, uint8_t id, uint8_t val){
if (CalibrationStorer_send_storeWriter_writeByte_listener != 0x0) CalibrationStorer_send_storeWriter_writeByte_listener(_instance, id, val);
if (external_CalibrationStorer_send_storeWriter_writeByte_listener != 0x0) external_CalibrationStorer_send_storeWriter_writeByte_listener(_instance, id, val);
;
}
void (*external_CalibrationStorer_send_storeWriter_writeConfig_listener)(struct CalibrationStorer_Instance *, double, double, double, double, double, double, double, double, double, double, double, double)= 0x0;
void (*CalibrationStorer_send_storeWriter_writeConfig_listener)(struct CalibrationStorer_Instance *, double, double, double, double, double, double, double, double, double, double, double, double)= 0x0;
void register_external_CalibrationStorer_send_storeWriter_writeConfig_listener(void (*_listener)(struct CalibrationStorer_Instance *, double, double, double, double, double, double, double, double, double, double, double, double)){
external_CalibrationStorer_send_storeWriter_writeConfig_listener = _listener;
}
void register_CalibrationStorer_send_storeWriter_writeConfig_listener(void (*_listener)(struct CalibrationStorer_Instance *, double, double, double, double, double, double, double, double, double, double, double, double)){
CalibrationStorer_send_storeWriter_writeConfig_listener = _listener;
}
void CalibrationStorer_send_storeWriter_writeConfig(struct CalibrationStorer_Instance *_instance, double bx, double by, double bz, double brx, double bry, double brz, double cx, double cy, double cz, double crx, double cry, double crz){
if (CalibrationStorer_send_storeWriter_writeConfig_listener != 0x0) CalibrationStorer_send_storeWriter_writeConfig_listener(_instance, bx, by, bz, brx, bry, brz, cx, cy, cz, crx, cry, crz);
if (external_CalibrationStorer_send_storeWriter_writeConfig_listener != 0x0) external_CalibrationStorer_send_storeWriter_writeConfig_listener(_instance, bx, by, bz, brx, bry, brz, cx, cy, cz, crx, cry, crz);
;
}
void (*external_CalibrationStorer_send_storer_endload_listener)(struct CalibrationStorer_Instance *)= 0x0;
void (*CalibrationStorer_send_storer_endload_listener)(struct CalibrationStorer_Instance *)= 0x0;
void register_external_CalibrationStorer_send_storer_endload_listener(void (*_listener)(struct CalibrationStorer_Instance *)){
external_CalibrationStorer_send_storer_endload_listener = _listener;
}
void register_CalibrationStorer_send_storer_endload_listener(void (*_listener)(struct CalibrationStorer_Instance *)){
CalibrationStorer_send_storer_endload_listener = _listener;
}
void CalibrationStorer_send_storer_endload(struct CalibrationStorer_Instance *_instance){
if (CalibrationStorer_send_storer_endload_listener != 0x0) CalibrationStorer_send_storer_endload_listener(_instance);
if (external_CalibrationStorer_send_storer_endload_listener != 0x0) external_CalibrationStorer_send_storer_endload_listener(_instance);
;
}
void (*external_CalibrationStorer_send_storer_errorload_listener)(struct CalibrationStorer_Instance *)= 0x0;
void (*CalibrationStorer_send_storer_errorload_listener)(struct CalibrationStorer_Instance *)= 0x0;
void register_external_CalibrationStorer_send_storer_errorload_listener(void (*_listener)(struct CalibrationStorer_Instance *)){
external_CalibrationStorer_send_storer_errorload_listener = _listener;
}
void register_CalibrationStorer_send_storer_errorload_listener(void (*_listener)(struct CalibrationStorer_Instance *)){
CalibrationStorer_send_storer_errorload_listener = _listener;
}
void CalibrationStorer_send_storer_errorload(struct CalibrationStorer_Instance *_instance){
if (CalibrationStorer_send_storer_errorload_listener != 0x0) CalibrationStorer_send_storer_errorload_listener(_instance);
if (external_CalibrationStorer_send_storer_errorload_listener != 0x0) external_CalibrationStorer_send_storer_errorload_listener(_instance);
;
}
void (*external_CalibrationStorer_send_progress_storerToIdle_listener)(struct CalibrationStorer_Instance *)= 0x0;
void (*CalibrationStorer_send_progress_storerToIdle_listener)(struct CalibrationStorer_Instance *)= 0x0;
void register_external_CalibrationStorer_send_progress_storerToIdle_listener(void (*_listener)(struct CalibrationStorer_Instance *)){
external_CalibrationStorer_send_progress_storerToIdle_listener = _listener;
}
void register_CalibrationStorer_send_progress_storerToIdle_listener(void (*_listener)(struct CalibrationStorer_Instance *)){
CalibrationStorer_send_progress_storerToIdle_listener = _listener;
}
void CalibrationStorer_send_progress_storerToIdle(struct CalibrationStorer_Instance *_instance){
if (CalibrationStorer_send_progress_storerToIdle_listener != 0x0) CalibrationStorer_send_progress_storerToIdle_listener(_instance);
if (external_CalibrationStorer_send_progress_storerToIdle_listener != 0x0) external_CalibrationStorer_send_progress_storerToIdle_listener(_instance);
;
}



