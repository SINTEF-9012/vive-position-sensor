#include "CalibrationValidator.h"
/*****************************************************************************
 * Implementation for type : CalibrationValidator
 *****************************************************************************/

// Declaration of prototypes:
//Prototypes: State Machine
void CalibrationValidator_Validator_OnExit(int state, struct CalibrationValidator_Instance *_instance);
//Prototypes: Message Sending
void CalibrationValidator_send_validator_endvalidate(struct CalibrationValidator_Instance *_instance);
void CalibrationValidator_send_validator_errvalidate(struct CalibrationValidator_Instance *_instance);
void CalibrationValidator_send_avt_validating(struct CalibrationValidator_Instance *_instance);
//Prototypes: Function
// Declaration of functions:

// Sessions functionss:


// On Entry Actions:
void CalibrationValidator_Validator_OnEntry(int state, struct CalibrationValidator_Instance *_instance) {
switch(state) {
case CALIBRATIONVALIDATOR_VALIDATOR_STATE:{
_instance->CalibrationValidator_Validator_State = CALIBRATIONVALIDATOR_VALIDATOR_IDLE_STATE;
CalibrationValidator_Validator_OnEntry(_instance->CalibrationValidator_Validator_State, _instance);
break;
}
case CALIBRATIONVALIDATOR_VALIDATOR_IDLE_STATE:{
break;
}
default: break;
}
}

// On Exit Actions:
void CalibrationValidator_Validator_OnExit(int state, struct CalibrationValidator_Instance *_instance) {
switch(state) {
case CALIBRATIONVALIDATOR_VALIDATOR_STATE:{
CalibrationValidator_Validator_OnExit(_instance->CalibrationValidator_Validator_State, _instance);
break;}
case CALIBRATIONVALIDATOR_VALIDATOR_IDLE_STATE:{
break;}
default: break;
}
}

// Event Handlers for incoming messages:
void CalibrationValidator_handle_validator_validate(struct CalibrationValidator_Instance *_instance) {
if(!(_instance->active)) return;
//Region Validator
uint8_t CalibrationValidator_Validator_State_event_consumed = 0;
if (_instance->CalibrationValidator_Validator_State == CALIBRATIONVALIDATOR_VALIDATOR_IDLE_STATE) {
if (CalibrationValidator_Validator_State_event_consumed == 0 && 1) {
CalibrationValidator_Validator_OnExit(CALIBRATIONVALIDATOR_VALIDATOR_IDLE_STATE, _instance);
_instance->CalibrationValidator_Validator_State = CALIBRATIONVALIDATOR_VALIDATOR_IDLE_STATE;
CalibrationValidator_send_validator_endvalidate(_instance);
CalibrationValidator_Validator_OnEntry(CALIBRATIONVALIDATOR_VALIDATOR_IDLE_STATE, _instance);
CalibrationValidator_Validator_State_event_consumed = 1;
}
}
//End Region Validator
//End dsregion Validator
//Session list: 
}

// Observers for outgoing messages:
void (*external_CalibrationValidator_send_validator_endvalidate_listener)(struct CalibrationValidator_Instance *)= 0x0;
void (*CalibrationValidator_send_validator_endvalidate_listener)(struct CalibrationValidator_Instance *)= 0x0;
void register_external_CalibrationValidator_send_validator_endvalidate_listener(void (*_listener)(struct CalibrationValidator_Instance *)){
external_CalibrationValidator_send_validator_endvalidate_listener = _listener;
}
void register_CalibrationValidator_send_validator_endvalidate_listener(void (*_listener)(struct CalibrationValidator_Instance *)){
CalibrationValidator_send_validator_endvalidate_listener = _listener;
}
void CalibrationValidator_send_validator_endvalidate(struct CalibrationValidator_Instance *_instance){
if (CalibrationValidator_send_validator_endvalidate_listener != 0x0) CalibrationValidator_send_validator_endvalidate_listener(_instance);
if (external_CalibrationValidator_send_validator_endvalidate_listener != 0x0) external_CalibrationValidator_send_validator_endvalidate_listener(_instance);
;
}
void (*external_CalibrationValidator_send_validator_errvalidate_listener)(struct CalibrationValidator_Instance *)= 0x0;
void (*CalibrationValidator_send_validator_errvalidate_listener)(struct CalibrationValidator_Instance *)= 0x0;
void register_external_CalibrationValidator_send_validator_errvalidate_listener(void (*_listener)(struct CalibrationValidator_Instance *)){
external_CalibrationValidator_send_validator_errvalidate_listener = _listener;
}
void register_CalibrationValidator_send_validator_errvalidate_listener(void (*_listener)(struct CalibrationValidator_Instance *)){
CalibrationValidator_send_validator_errvalidate_listener = _listener;
}
void CalibrationValidator_send_validator_errvalidate(struct CalibrationValidator_Instance *_instance){
if (CalibrationValidator_send_validator_errvalidate_listener != 0x0) CalibrationValidator_send_validator_errvalidate_listener(_instance);
if (external_CalibrationValidator_send_validator_errvalidate_listener != 0x0) external_CalibrationValidator_send_validator_errvalidate_listener(_instance);
;
}
void (*external_CalibrationValidator_send_avt_validating_listener)(struct CalibrationValidator_Instance *)= 0x0;
void (*CalibrationValidator_send_avt_validating_listener)(struct CalibrationValidator_Instance *)= 0x0;
void register_external_CalibrationValidator_send_avt_validating_listener(void (*_listener)(struct CalibrationValidator_Instance *)){
external_CalibrationValidator_send_avt_validating_listener = _listener;
}
void register_CalibrationValidator_send_avt_validating_listener(void (*_listener)(struct CalibrationValidator_Instance *)){
CalibrationValidator_send_avt_validating_listener = _listener;
}
void CalibrationValidator_send_avt_validating(struct CalibrationValidator_Instance *_instance){
if (CalibrationValidator_send_avt_validating_listener != 0x0) CalibrationValidator_send_avt_validating_listener(_instance);
if (external_CalibrationValidator_send_avt_validating_listener != 0x0) external_CalibrationValidator_send_avt_validating_listener(_instance);
;
}



