#include "Backbone.h"
/*****************************************************************************
 * Implementation for type : Backbone
 *****************************************************************************/


// BEGIN: Code from the c_global annotation Backbone

        extern struct Backbone_Instance backbone_var; // for timeout_angleStatus() function
   
        bool angleReadingArrived = false; // For alerting user is no angles are received over longer period
        
        // Globally available debug flags (extern in constants.h)        
        bool DEBUG = false;
        bool VERBOSE = false;
    
// END: Code from the c_global annotation Backbone

// Declaration of prototypes:
//Prototypes: State Machine
void Backbone_Main_OnExit(int state, struct Backbone_Instance *_instance);
//Prototypes: Message Sending
void Backbone_send_Output_positionCoordinates(struct Backbone_Instance *_instance, double x, double y, double z);
void Backbone_send_Run_baseStationAngles(struct Backbone_Instance *_instance, double bh, double bv, double ch, double cv);
void Backbone_send_CalibrationStorer_load(struct Backbone_Instance *_instance);
void Backbone_send_CalibrationStorer_save(struct Backbone_Instance *_instance);
void Backbone_send_validator_validate(struct Backbone_Instance *_instance);
void Backbone_send_calibrator_calibrate(struct Backbone_Instance *_instance);
void Backbone_send_calibrator_entrypoint(struct Backbone_Instance *_instance);
void Backbone_send_calibrator_receiveAngles(struct Backbone_Instance *_instance, double bh, double bv, double ch, double cv);
void Backbone_send_calibrator_receivecalibration(struct Backbone_Instance *_instance, double bx, double by, double bz, double brx, double bry, double brz, double cx, double cy, double cz, double crx, double cry, double crz);
void Backbone_send_printer_printStatus(struct Backbone_Instance *_instance, uint8_t id, uint8_t verbose);
void Backbone_send_printer_printOperationState(struct Backbone_Instance *_instance, uint8_t id, uint8_t verbose);
void Backbone_send_printer_printPoint(struct Backbone_Instance *_instance, double x, double y, double z, double separation, uint8_t verbose);
void Backbone_send_serialRead_waitcalibration(struct Backbone_Instance *_instance);
void Backbone_send_pixel_stateID(struct Backbone_Instance *_instance, uint8_t id);
void Backbone_send_pixel_statusID(struct Backbone_Instance *_instance, uint8_t id);
void Backbone_send_StateHandler_currentState(struct Backbone_Instance *_instance, uint8_t id);
void Backbone_send_transitions_toIdle(struct Backbone_Instance *_instance);
//Prototypes: Function
void f_Backbone_sendStatus(struct Backbone_Instance *_instance, uint8_t id);
void timeout_angleStatus();
// Declaration of functions:
// Definition of function sendStatus
void f_Backbone_sendStatus(struct Backbone_Instance *_instance, uint8_t id) {
Backbone_send_pixel_statusID(_instance, id);
if (DEBUG)
Backbone_send_printer_printStatus(_instance, id, VERBOSE);
}
// Definition of function timeout_angleStatus
void timeout_angleStatus() {
if (angleReadingArrived) {
             angleReadingArrived = false;
         } else {
             f_Backbone_sendStatus(&backbone_var, 14);
         }
         start_timer(4, NO_PACKAGES_TO_ERROR_DISPLAY_DURATION, &timeout_angleStatus);
         
}

// Sessions functionss:


// On Entry Actions:
void Backbone_Main_OnEntry(int state, struct Backbone_Instance *_instance) {
switch(state) {
case BACKBONE_MAIN_STATE:{
_instance->Backbone_Main_State = BACKBONE_MAIN_LOAD_CALIBRATION_STATE;

		    timeout_angleStatus(); // Start monitoring for durations of no signals
		    
		    pinMode(12, OUTPUT);
            digitalWriteFast(12, HIGH);
            pinMode(11, INPUT);
            DEBUG = !digitalRead(11);
            
Backbone_Main_OnEntry(_instance->Backbone_Main_State, _instance);
break;
}
case BACKBONE_MAIN_LOAD_CALIBRATION_STATE:{
Backbone_send_StateHandler_currentState(_instance, 1);
Backbone_send_CalibrationStorer_load(_instance);
break;
}
case BACKBONE_MAIN_CALIBRATION_STATE:{
Backbone_send_StateHandler_currentState(_instance, 2);
Backbone_send_calibrator_calibrate(_instance);
break;
}
case BACKBONE_MAIN_VALIDATE_CALIBRATION_STATE:{
Backbone_send_StateHandler_currentState(_instance, 3);
Backbone_send_validator_validate(_instance);
break;
}
case BACKBONE_MAIN_RUNNER_STATE:{
Backbone_send_StateHandler_currentState(_instance, 4);
break;
}
default: break;
}
}

// On Exit Actions:
void Backbone_Main_OnExit(int state, struct Backbone_Instance *_instance) {
switch(state) {
case BACKBONE_MAIN_STATE:{
Backbone_Main_OnExit(_instance->Backbone_Main_State, _instance);
break;}
case BACKBONE_MAIN_LOAD_CALIBRATION_STATE:{
break;}
case BACKBONE_MAIN_CALIBRATION_STATE:{
break;}
case BACKBONE_MAIN_VALIDATE_CALIBRATION_STATE:{
break;}
case BACKBONE_MAIN_RUNNER_STATE:{
break;}
default: break;
}
}

// Event Handlers for incoming messages:
void Backbone_handle_AngleReceiver_allAngles(struct Backbone_Instance *_instance, double bh, double bv, double ch, double cv) {
if(!(_instance->active)) return;
//Region Main
uint8_t Backbone_Main_State_event_consumed = 0;
if (_instance->Backbone_Main_State == BACKBONE_MAIN_CALIBRATION_STATE) {
if (Backbone_Main_State_event_consumed == 0 && 1) {
Backbone_send_calibrator_receiveAngles(_instance, bh, bv, ch, cv);
Backbone_Main_State_event_consumed = 1;
}
}
else if (_instance->Backbone_Main_State == BACKBONE_MAIN_RUNNER_STATE) {
if (Backbone_Main_State_event_consumed == 0 && 1) {
Backbone_send_Run_baseStationAngles(_instance, bh, bv, ch, cv);
Backbone_Main_State_event_consumed = 1;
}
}
//End Region Main
//End dsregion Main
//Session list: 
if (1) {
angleReadingArrived = true;
Backbone_Main_State_event_consumed = 1;
}
}
void Backbone_handle_StateHandler_currentState(struct Backbone_Instance *_instance, uint8_t id) {
if(!(_instance->active)) return;
//Region Main
uint8_t Backbone_Main_State_event_consumed = 0;
//End Region Main
//End dsregion Main
//Session list: 
if (1) {
Backbone_send_pixel_stateID(_instance, id);
if (DEBUG)
Backbone_send_printer_printOperationState(_instance, id, VERBOSE);
Backbone_Main_State_event_consumed = 1;
}
}
void Backbone_handle_Run_coordinates(struct Backbone_Instance *_instance, double x, double y, double z, double separation) {
if(!(_instance->active)) return;
//Region Main
uint8_t Backbone_Main_State_event_consumed = 0;
if (_instance->Backbone_Main_State == BACKBONE_MAIN_RUNNER_STATE) {
if (Backbone_Main_State_event_consumed == 0 && 1) {
if(DEBUG) {
Backbone_send_printer_printPoint(_instance, x, y, z, separation, VERBOSE);

}
Backbone_send_Output_positionCoordinates(_instance, x, y, z);
Backbone_Main_State_event_consumed = 1;
}
}
//End Region Main
//End dsregion Main
//Session list: 
}
void Backbone_handle_presser_double_click(struct Backbone_Instance *_instance) {
if(!(_instance->active)) return;
//Region Main
uint8_t Backbone_Main_State_event_consumed = 0;
//End Region Main
//End dsregion Main
//Session list: 
if (1) {
VERBOSE = DEBUG & !VERBOSE;
Backbone_Main_State_event_consumed = 1;
}
}
void Backbone_handle_presser_click(struct Backbone_Instance *_instance) {
if(!(_instance->active)) return;
//Region Main
uint8_t Backbone_Main_State_event_consumed = 0;
if (_instance->Backbone_Main_State == BACKBONE_MAIN_CALIBRATION_STATE) {
if (Backbone_Main_State_event_consumed == 0 && 1) {
Backbone_send_calibrator_entrypoint(_instance);
Backbone_Main_State_event_consumed = 1;
}
}
//End Region Main
//End dsregion Main
//Session list: 
}
void Backbone_handle_presser_long_press(struct Backbone_Instance *_instance) {
if(!(_instance->active)) return;
//Region Main
uint8_t Backbone_Main_State_event_consumed = 0;
if (_instance->Backbone_Main_State == BACKBONE_MAIN_CALIBRATION_STATE) {
if (Backbone_Main_State_event_consumed == 0 && 1) {
Backbone_Main_OnExit(BACKBONE_MAIN_CALIBRATION_STATE, _instance);
_instance->Backbone_Main_State = BACKBONE_MAIN_CALIBRATION_STATE;
Backbone_Main_OnEntry(BACKBONE_MAIN_CALIBRATION_STATE, _instance);
Backbone_Main_State_event_consumed = 1;
}
}
else if (_instance->Backbone_Main_State == BACKBONE_MAIN_RUNNER_STATE) {
if (Backbone_Main_State_event_consumed == 0 && 1) {
Backbone_Main_OnExit(BACKBONE_MAIN_RUNNER_STATE, _instance);
_instance->Backbone_Main_State = BACKBONE_MAIN_CALIBRATION_STATE;
Backbone_Main_OnEntry(BACKBONE_MAIN_CALIBRATION_STATE, _instance);
Backbone_Main_State_event_consumed = 1;
}
}
//End Region Main
//End dsregion Main
//Session list: 
}
void Backbone_handle_calibrator_endcalibrate(struct Backbone_Instance *_instance) {
if(!(_instance->active)) return;
//Region Main
uint8_t Backbone_Main_State_event_consumed = 0;
if (_instance->Backbone_Main_State == BACKBONE_MAIN_CALIBRATION_STATE) {
if (Backbone_Main_State_event_consumed == 0 && 1) {
Backbone_Main_OnExit(BACKBONE_MAIN_CALIBRATION_STATE, _instance);
_instance->Backbone_Main_State = BACKBONE_MAIN_VALIDATE_CALIBRATION_STATE;
Backbone_send_CalibrationStorer_save(_instance);
Backbone_Main_OnEntry(BACKBONE_MAIN_VALIDATE_CALIBRATION_STATE, _instance);
Backbone_Main_State_event_consumed = 1;
}
}
//End Region Main
//End dsregion Main
//Session list: 
}
void Backbone_handle_calibrator_errcalibrate(struct Backbone_Instance *_instance) {
if(!(_instance->active)) return;
//Region Main
uint8_t Backbone_Main_State_event_consumed = 0;
if (_instance->Backbone_Main_State == BACKBONE_MAIN_CALIBRATION_STATE) {
if (Backbone_Main_State_event_consumed == 0 && 1) {
Backbone_Main_OnExit(BACKBONE_MAIN_CALIBRATION_STATE, _instance);
_instance->Backbone_Main_State = BACKBONE_MAIN_CALIBRATION_STATE;
Backbone_Main_OnEntry(BACKBONE_MAIN_CALIBRATION_STATE, _instance);
Backbone_Main_State_event_consumed = 1;
}
}
//End Region Main
//End dsregion Main
//Session list: 
}
void Backbone_handle_CalibrationStorer_errorload(struct Backbone_Instance *_instance) {
if(!(_instance->active)) return;
//Region Main
uint8_t Backbone_Main_State_event_consumed = 0;
if (_instance->Backbone_Main_State == BACKBONE_MAIN_LOAD_CALIBRATION_STATE) {
if (Backbone_Main_State_event_consumed == 0 && 1) {
Backbone_Main_OnExit(BACKBONE_MAIN_LOAD_CALIBRATION_STATE, _instance);
_instance->Backbone_Main_State = BACKBONE_MAIN_CALIBRATION_STATE;
f_Backbone_sendStatus(_instance, 6);
Backbone_Main_OnEntry(BACKBONE_MAIN_CALIBRATION_STATE, _instance);
Backbone_Main_State_event_consumed = 1;
}
}
//End Region Main
//End dsregion Main
//Session list: 
}
void Backbone_handle_CalibrationStorer_endload(struct Backbone_Instance *_instance) {
if(!(_instance->active)) return;
//Region Main
uint8_t Backbone_Main_State_event_consumed = 0;
if (_instance->Backbone_Main_State == BACKBONE_MAIN_LOAD_CALIBRATION_STATE) {
if (Backbone_Main_State_event_consumed == 0 && 1) {
Backbone_Main_OnExit(BACKBONE_MAIN_LOAD_CALIBRATION_STATE, _instance);
_instance->Backbone_Main_State = BACKBONE_MAIN_VALIDATE_CALIBRATION_STATE;
f_Backbone_sendStatus(_instance, 5);
Backbone_Main_OnEntry(BACKBONE_MAIN_VALIDATE_CALIBRATION_STATE, _instance);
Backbone_Main_State_event_consumed = 1;
}
}
//End Region Main
//End dsregion Main
//Session list: 
}
void Backbone_handle_StatusHandler_status(struct Backbone_Instance *_instance, uint8_t id) {
if(!(_instance->active)) return;
//Region Main
uint8_t Backbone_Main_State_event_consumed = 0;
//End Region Main
//End dsregion Main
//Session list: 
if (1) {
f_Backbone_sendStatus(_instance, id);
Backbone_Main_State_event_consumed = 1;
}
}
void Backbone_handle_validator_errvalidate(struct Backbone_Instance *_instance) {
if(!(_instance->active)) return;
//Region Main
uint8_t Backbone_Main_State_event_consumed = 0;
if (_instance->Backbone_Main_State == BACKBONE_MAIN_VALIDATE_CALIBRATION_STATE) {
if (Backbone_Main_State_event_consumed == 0 && 1) {
Backbone_Main_OnExit(BACKBONE_MAIN_VALIDATE_CALIBRATION_STATE, _instance);
_instance->Backbone_Main_State = BACKBONE_MAIN_CALIBRATION_STATE;
Backbone_Main_OnEntry(BACKBONE_MAIN_CALIBRATION_STATE, _instance);
Backbone_Main_State_event_consumed = 1;
}
}
//End Region Main
//End dsregion Main
//Session list: 
}
void Backbone_handle_validator_endvalidate(struct Backbone_Instance *_instance) {
if(!(_instance->active)) return;
//Region Main
uint8_t Backbone_Main_State_event_consumed = 0;
if (_instance->Backbone_Main_State == BACKBONE_MAIN_VALIDATE_CALIBRATION_STATE) {
if (Backbone_Main_State_event_consumed == 0 && 1) {
Backbone_Main_OnExit(BACKBONE_MAIN_VALIDATE_CALIBRATION_STATE, _instance);
_instance->Backbone_Main_State = BACKBONE_MAIN_RUNNER_STATE;
Backbone_Main_OnEntry(BACKBONE_MAIN_RUNNER_STATE, _instance);
Backbone_Main_State_event_consumed = 1;
}
}
//End Region Main
//End dsregion Main
//Session list: 
}

// Observers for outgoing messages:
void (*external_Backbone_send_Output_positionCoordinates_listener)(struct Backbone_Instance *, double, double, double)= 0x0;
void (*Backbone_send_Output_positionCoordinates_listener)(struct Backbone_Instance *, double, double, double)= 0x0;
void register_external_Backbone_send_Output_positionCoordinates_listener(void (*_listener)(struct Backbone_Instance *, double, double, double)){
external_Backbone_send_Output_positionCoordinates_listener = _listener;
}
void register_Backbone_send_Output_positionCoordinates_listener(void (*_listener)(struct Backbone_Instance *, double, double, double)){
Backbone_send_Output_positionCoordinates_listener = _listener;
}
void Backbone_send_Output_positionCoordinates(struct Backbone_Instance *_instance, double x, double y, double z){
if (Backbone_send_Output_positionCoordinates_listener != 0x0) Backbone_send_Output_positionCoordinates_listener(_instance, x, y, z);
if (external_Backbone_send_Output_positionCoordinates_listener != 0x0) external_Backbone_send_Output_positionCoordinates_listener(_instance, x, y, z);
;
}
void (*external_Backbone_send_Run_baseStationAngles_listener)(struct Backbone_Instance *, double, double, double, double)= 0x0;
void (*Backbone_send_Run_baseStationAngles_listener)(struct Backbone_Instance *, double, double, double, double)= 0x0;
void register_external_Backbone_send_Run_baseStationAngles_listener(void (*_listener)(struct Backbone_Instance *, double, double, double, double)){
external_Backbone_send_Run_baseStationAngles_listener = _listener;
}
void register_Backbone_send_Run_baseStationAngles_listener(void (*_listener)(struct Backbone_Instance *, double, double, double, double)){
Backbone_send_Run_baseStationAngles_listener = _listener;
}
void Backbone_send_Run_baseStationAngles(struct Backbone_Instance *_instance, double bh, double bv, double ch, double cv){
if (Backbone_send_Run_baseStationAngles_listener != 0x0) Backbone_send_Run_baseStationAngles_listener(_instance, bh, bv, ch, cv);
if (external_Backbone_send_Run_baseStationAngles_listener != 0x0) external_Backbone_send_Run_baseStationAngles_listener(_instance, bh, bv, ch, cv);
;
}
void (*external_Backbone_send_CalibrationStorer_load_listener)(struct Backbone_Instance *)= 0x0;
void (*Backbone_send_CalibrationStorer_load_listener)(struct Backbone_Instance *)= 0x0;
void register_external_Backbone_send_CalibrationStorer_load_listener(void (*_listener)(struct Backbone_Instance *)){
external_Backbone_send_CalibrationStorer_load_listener = _listener;
}
void register_Backbone_send_CalibrationStorer_load_listener(void (*_listener)(struct Backbone_Instance *)){
Backbone_send_CalibrationStorer_load_listener = _listener;
}
void Backbone_send_CalibrationStorer_load(struct Backbone_Instance *_instance){
if (Backbone_send_CalibrationStorer_load_listener != 0x0) Backbone_send_CalibrationStorer_load_listener(_instance);
if (external_Backbone_send_CalibrationStorer_load_listener != 0x0) external_Backbone_send_CalibrationStorer_load_listener(_instance);
;
}
void (*external_Backbone_send_CalibrationStorer_save_listener)(struct Backbone_Instance *)= 0x0;
void (*Backbone_send_CalibrationStorer_save_listener)(struct Backbone_Instance *)= 0x0;
void register_external_Backbone_send_CalibrationStorer_save_listener(void (*_listener)(struct Backbone_Instance *)){
external_Backbone_send_CalibrationStorer_save_listener = _listener;
}
void register_Backbone_send_CalibrationStorer_save_listener(void (*_listener)(struct Backbone_Instance *)){
Backbone_send_CalibrationStorer_save_listener = _listener;
}
void Backbone_send_CalibrationStorer_save(struct Backbone_Instance *_instance){
if (Backbone_send_CalibrationStorer_save_listener != 0x0) Backbone_send_CalibrationStorer_save_listener(_instance);
if (external_Backbone_send_CalibrationStorer_save_listener != 0x0) external_Backbone_send_CalibrationStorer_save_listener(_instance);
;
}
void (*external_Backbone_send_validator_validate_listener)(struct Backbone_Instance *)= 0x0;
void (*Backbone_send_validator_validate_listener)(struct Backbone_Instance *)= 0x0;
void register_external_Backbone_send_validator_validate_listener(void (*_listener)(struct Backbone_Instance *)){
external_Backbone_send_validator_validate_listener = _listener;
}
void register_Backbone_send_validator_validate_listener(void (*_listener)(struct Backbone_Instance *)){
Backbone_send_validator_validate_listener = _listener;
}
void Backbone_send_validator_validate(struct Backbone_Instance *_instance){
if (Backbone_send_validator_validate_listener != 0x0) Backbone_send_validator_validate_listener(_instance);
if (external_Backbone_send_validator_validate_listener != 0x0) external_Backbone_send_validator_validate_listener(_instance);
;
}
void (*external_Backbone_send_calibrator_calibrate_listener)(struct Backbone_Instance *)= 0x0;
void (*Backbone_send_calibrator_calibrate_listener)(struct Backbone_Instance *)= 0x0;
void register_external_Backbone_send_calibrator_calibrate_listener(void (*_listener)(struct Backbone_Instance *)){
external_Backbone_send_calibrator_calibrate_listener = _listener;
}
void register_Backbone_send_calibrator_calibrate_listener(void (*_listener)(struct Backbone_Instance *)){
Backbone_send_calibrator_calibrate_listener = _listener;
}
void Backbone_send_calibrator_calibrate(struct Backbone_Instance *_instance){
if (Backbone_send_calibrator_calibrate_listener != 0x0) Backbone_send_calibrator_calibrate_listener(_instance);
if (external_Backbone_send_calibrator_calibrate_listener != 0x0) external_Backbone_send_calibrator_calibrate_listener(_instance);
;
}
void (*external_Backbone_send_calibrator_entrypoint_listener)(struct Backbone_Instance *)= 0x0;
void (*Backbone_send_calibrator_entrypoint_listener)(struct Backbone_Instance *)= 0x0;
void register_external_Backbone_send_calibrator_entrypoint_listener(void (*_listener)(struct Backbone_Instance *)){
external_Backbone_send_calibrator_entrypoint_listener = _listener;
}
void register_Backbone_send_calibrator_entrypoint_listener(void (*_listener)(struct Backbone_Instance *)){
Backbone_send_calibrator_entrypoint_listener = _listener;
}
void Backbone_send_calibrator_entrypoint(struct Backbone_Instance *_instance){
if (Backbone_send_calibrator_entrypoint_listener != 0x0) Backbone_send_calibrator_entrypoint_listener(_instance);
if (external_Backbone_send_calibrator_entrypoint_listener != 0x0) external_Backbone_send_calibrator_entrypoint_listener(_instance);
;
}
void (*external_Backbone_send_calibrator_receiveAngles_listener)(struct Backbone_Instance *, double, double, double, double)= 0x0;
void (*Backbone_send_calibrator_receiveAngles_listener)(struct Backbone_Instance *, double, double, double, double)= 0x0;
void register_external_Backbone_send_calibrator_receiveAngles_listener(void (*_listener)(struct Backbone_Instance *, double, double, double, double)){
external_Backbone_send_calibrator_receiveAngles_listener = _listener;
}
void register_Backbone_send_calibrator_receiveAngles_listener(void (*_listener)(struct Backbone_Instance *, double, double, double, double)){
Backbone_send_calibrator_receiveAngles_listener = _listener;
}
void Backbone_send_calibrator_receiveAngles(struct Backbone_Instance *_instance, double bh, double bv, double ch, double cv){
if (Backbone_send_calibrator_receiveAngles_listener != 0x0) Backbone_send_calibrator_receiveAngles_listener(_instance, bh, bv, ch, cv);
if (external_Backbone_send_calibrator_receiveAngles_listener != 0x0) external_Backbone_send_calibrator_receiveAngles_listener(_instance, bh, bv, ch, cv);
;
}
void (*external_Backbone_send_calibrator_receivecalibration_listener)(struct Backbone_Instance *, double, double, double, double, double, double, double, double, double, double, double, double)= 0x0;
void (*Backbone_send_calibrator_receivecalibration_listener)(struct Backbone_Instance *, double, double, double, double, double, double, double, double, double, double, double, double)= 0x0;
void register_external_Backbone_send_calibrator_receivecalibration_listener(void (*_listener)(struct Backbone_Instance *, double, double, double, double, double, double, double, double, double, double, double, double)){
external_Backbone_send_calibrator_receivecalibration_listener = _listener;
}
void register_Backbone_send_calibrator_receivecalibration_listener(void (*_listener)(struct Backbone_Instance *, double, double, double, double, double, double, double, double, double, double, double, double)){
Backbone_send_calibrator_receivecalibration_listener = _listener;
}
void Backbone_send_calibrator_receivecalibration(struct Backbone_Instance *_instance, double bx, double by, double bz, double brx, double bry, double brz, double cx, double cy, double cz, double crx, double cry, double crz){
if (Backbone_send_calibrator_receivecalibration_listener != 0x0) Backbone_send_calibrator_receivecalibration_listener(_instance, bx, by, bz, brx, bry, brz, cx, cy, cz, crx, cry, crz);
if (external_Backbone_send_calibrator_receivecalibration_listener != 0x0) external_Backbone_send_calibrator_receivecalibration_listener(_instance, bx, by, bz, brx, bry, brz, cx, cy, cz, crx, cry, crz);
;
}
void (*external_Backbone_send_printer_printStatus_listener)(struct Backbone_Instance *, uint8_t, uint8_t)= 0x0;
void (*Backbone_send_printer_printStatus_listener)(struct Backbone_Instance *, uint8_t, uint8_t)= 0x0;
void register_external_Backbone_send_printer_printStatus_listener(void (*_listener)(struct Backbone_Instance *, uint8_t, uint8_t)){
external_Backbone_send_printer_printStatus_listener = _listener;
}
void register_Backbone_send_printer_printStatus_listener(void (*_listener)(struct Backbone_Instance *, uint8_t, uint8_t)){
Backbone_send_printer_printStatus_listener = _listener;
}
void Backbone_send_printer_printStatus(struct Backbone_Instance *_instance, uint8_t id, uint8_t verbose){
if (Backbone_send_printer_printStatus_listener != 0x0) Backbone_send_printer_printStatus_listener(_instance, id, verbose);
if (external_Backbone_send_printer_printStatus_listener != 0x0) external_Backbone_send_printer_printStatus_listener(_instance, id, verbose);
;
}
void (*external_Backbone_send_printer_printOperationState_listener)(struct Backbone_Instance *, uint8_t, uint8_t)= 0x0;
void (*Backbone_send_printer_printOperationState_listener)(struct Backbone_Instance *, uint8_t, uint8_t)= 0x0;
void register_external_Backbone_send_printer_printOperationState_listener(void (*_listener)(struct Backbone_Instance *, uint8_t, uint8_t)){
external_Backbone_send_printer_printOperationState_listener = _listener;
}
void register_Backbone_send_printer_printOperationState_listener(void (*_listener)(struct Backbone_Instance *, uint8_t, uint8_t)){
Backbone_send_printer_printOperationState_listener = _listener;
}
void Backbone_send_printer_printOperationState(struct Backbone_Instance *_instance, uint8_t id, uint8_t verbose){
if (Backbone_send_printer_printOperationState_listener != 0x0) Backbone_send_printer_printOperationState_listener(_instance, id, verbose);
if (external_Backbone_send_printer_printOperationState_listener != 0x0) external_Backbone_send_printer_printOperationState_listener(_instance, id, verbose);
;
}
void (*external_Backbone_send_printer_printPoint_listener)(struct Backbone_Instance *, double, double, double, double, uint8_t)= 0x0;
void (*Backbone_send_printer_printPoint_listener)(struct Backbone_Instance *, double, double, double, double, uint8_t)= 0x0;
void register_external_Backbone_send_printer_printPoint_listener(void (*_listener)(struct Backbone_Instance *, double, double, double, double, uint8_t)){
external_Backbone_send_printer_printPoint_listener = _listener;
}
void register_Backbone_send_printer_printPoint_listener(void (*_listener)(struct Backbone_Instance *, double, double, double, double, uint8_t)){
Backbone_send_printer_printPoint_listener = _listener;
}
void Backbone_send_printer_printPoint(struct Backbone_Instance *_instance, double x, double y, double z, double separation, uint8_t verbose){
if (Backbone_send_printer_printPoint_listener != 0x0) Backbone_send_printer_printPoint_listener(_instance, x, y, z, separation, verbose);
if (external_Backbone_send_printer_printPoint_listener != 0x0) external_Backbone_send_printer_printPoint_listener(_instance, x, y, z, separation, verbose);
;
}
void (*external_Backbone_send_serialRead_waitcalibration_listener)(struct Backbone_Instance *)= 0x0;
void (*Backbone_send_serialRead_waitcalibration_listener)(struct Backbone_Instance *)= 0x0;
void register_external_Backbone_send_serialRead_waitcalibration_listener(void (*_listener)(struct Backbone_Instance *)){
external_Backbone_send_serialRead_waitcalibration_listener = _listener;
}
void register_Backbone_send_serialRead_waitcalibration_listener(void (*_listener)(struct Backbone_Instance *)){
Backbone_send_serialRead_waitcalibration_listener = _listener;
}
void Backbone_send_serialRead_waitcalibration(struct Backbone_Instance *_instance){
if (Backbone_send_serialRead_waitcalibration_listener != 0x0) Backbone_send_serialRead_waitcalibration_listener(_instance);
if (external_Backbone_send_serialRead_waitcalibration_listener != 0x0) external_Backbone_send_serialRead_waitcalibration_listener(_instance);
;
}
void (*external_Backbone_send_pixel_stateID_listener)(struct Backbone_Instance *, uint8_t)= 0x0;
void (*Backbone_send_pixel_stateID_listener)(struct Backbone_Instance *, uint8_t)= 0x0;
void register_external_Backbone_send_pixel_stateID_listener(void (*_listener)(struct Backbone_Instance *, uint8_t)){
external_Backbone_send_pixel_stateID_listener = _listener;
}
void register_Backbone_send_pixel_stateID_listener(void (*_listener)(struct Backbone_Instance *, uint8_t)){
Backbone_send_pixel_stateID_listener = _listener;
}
void Backbone_send_pixel_stateID(struct Backbone_Instance *_instance, uint8_t id){
if (Backbone_send_pixel_stateID_listener != 0x0) Backbone_send_pixel_stateID_listener(_instance, id);
if (external_Backbone_send_pixel_stateID_listener != 0x0) external_Backbone_send_pixel_stateID_listener(_instance, id);
;
}
void (*external_Backbone_send_pixel_statusID_listener)(struct Backbone_Instance *, uint8_t)= 0x0;
void (*Backbone_send_pixel_statusID_listener)(struct Backbone_Instance *, uint8_t)= 0x0;
void register_external_Backbone_send_pixel_statusID_listener(void (*_listener)(struct Backbone_Instance *, uint8_t)){
external_Backbone_send_pixel_statusID_listener = _listener;
}
void register_Backbone_send_pixel_statusID_listener(void (*_listener)(struct Backbone_Instance *, uint8_t)){
Backbone_send_pixel_statusID_listener = _listener;
}
void Backbone_send_pixel_statusID(struct Backbone_Instance *_instance, uint8_t id){
if (Backbone_send_pixel_statusID_listener != 0x0) Backbone_send_pixel_statusID_listener(_instance, id);
if (external_Backbone_send_pixel_statusID_listener != 0x0) external_Backbone_send_pixel_statusID_listener(_instance, id);
;
}
void (*external_Backbone_send_StateHandler_currentState_listener)(struct Backbone_Instance *, uint8_t)= 0x0;
void (*Backbone_send_StateHandler_currentState_listener)(struct Backbone_Instance *, uint8_t)= 0x0;
void register_external_Backbone_send_StateHandler_currentState_listener(void (*_listener)(struct Backbone_Instance *, uint8_t)){
external_Backbone_send_StateHandler_currentState_listener = _listener;
}
void register_Backbone_send_StateHandler_currentState_listener(void (*_listener)(struct Backbone_Instance *, uint8_t)){
Backbone_send_StateHandler_currentState_listener = _listener;
}
void Backbone_send_StateHandler_currentState(struct Backbone_Instance *_instance, uint8_t id){
if (Backbone_send_StateHandler_currentState_listener != 0x0) Backbone_send_StateHandler_currentState_listener(_instance, id);
if (external_Backbone_send_StateHandler_currentState_listener != 0x0) external_Backbone_send_StateHandler_currentState_listener(_instance, id);
;
}
void (*external_Backbone_send_transitions_toIdle_listener)(struct Backbone_Instance *)= 0x0;
void (*Backbone_send_transitions_toIdle_listener)(struct Backbone_Instance *)= 0x0;
void register_external_Backbone_send_transitions_toIdle_listener(void (*_listener)(struct Backbone_Instance *)){
external_Backbone_send_transitions_toIdle_listener = _listener;
}
void register_Backbone_send_transitions_toIdle_listener(void (*_listener)(struct Backbone_Instance *)){
Backbone_send_transitions_toIdle_listener = _listener;
}
void Backbone_send_transitions_toIdle(struct Backbone_Instance *_instance){
if (Backbone_send_transitions_toIdle_listener != 0x0) Backbone_send_transitions_toIdle_listener(_instance);
if (external_Backbone_send_transitions_toIdle_listener != 0x0) external_Backbone_send_transitions_toIdle_listener(_instance);
;
}



