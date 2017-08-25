#include "SerialIn.h"
/*****************************************************************************
 * Implementation for type : SerialIn
 *****************************************************************************/


// BEGIN: Code from the c_global annotation SerialIn
extern struct SerialIn_Instance serialIn_var;
// END: Code from the c_global annotation SerialIn

// Declaration of prototypes:
//Prototypes: State Machine
void SerialIn_serialreader_OnExit(int state, struct SerialIn_Instance *_instance);
//Prototypes: Message Sending
void SerialIn_send_serialcall_calibrationreceived(struct SerialIn_Instance *_instance, double bx, double by, double bz, double brx, double bry, double brz, double cx, double cy, double cz, double crx, double cry, double crz);
void SerialIn_send_Timer_serial_timeout(struct SerialIn_Instance *_instance);
//Prototypes: Function
void timeout_serialreader();
// Declaration of functions:
// Definition of function timeout_serialreader
void timeout_serialreader() {
SerialIn_send_Timer_serial_timeout(&serialIn_var);
}

// Sessions functionss:


// On Entry Actions:
void SerialIn_serialreader_OnEntry(int state, struct SerialIn_Instance *_instance) {
switch(state) {
case SERIALIN_SERIALREADER_STATE:{
_instance->SerialIn_serialreader_State = SERIALIN_SERIALREADER_IDLE_STATE;
SerialIn_serialreader_OnEntry(_instance->SerialIn_serialreader_State, _instance);
break;
}
case SERIALIN_SERIALREADER_IDLE_STATE:{
break;
}
case SERIALIN_SERIALREADER_CALIBRATIONRECEIVER_STATE:{
start_timer(2, 25, &timeout_serialreader);
break;
}
default: break;
}
}

// On Exit Actions:
void SerialIn_serialreader_OnExit(int state, struct SerialIn_Instance *_instance) {
switch(state) {
case SERIALIN_SERIALREADER_STATE:{
SerialIn_serialreader_OnExit(_instance->SerialIn_serialreader_State, _instance);
break;}
case SERIALIN_SERIALREADER_IDLE_STATE:{
break;}
case SERIALIN_SERIALREADER_CALIBRATIONRECEIVER_STATE:{
break;}
default: break;
}
}

// Event Handlers for incoming messages:
void SerialIn_handle_serialcall_waitcalibration(struct SerialIn_Instance *_instance) {
if(!(_instance->active)) return;
//Region serialreader
uint8_t SerialIn_serialreader_State_event_consumed = 0;
if (_instance->SerialIn_serialreader_State == SERIALIN_SERIALREADER_IDLE_STATE) {
if (SerialIn_serialreader_State_event_consumed == 0 && 1) {
SerialIn_serialreader_OnExit(SERIALIN_SERIALREADER_IDLE_STATE, _instance);
_instance->SerialIn_serialreader_State = SERIALIN_SERIALREADER_CALIBRATIONRECEIVER_STATE;
SerialIn_serialreader_OnEntry(SERIALIN_SERIALREADER_CALIBRATIONRECEIVER_STATE, _instance);
SerialIn_serialreader_State_event_consumed = 1;
}
}
//End Region serialreader
//End dsregion serialreader
//Session list: 
}
void SerialIn_handle_Timer_serial_timeout(struct SerialIn_Instance *_instance) {
if(!(_instance->active)) return;
//Region serialreader
uint8_t SerialIn_serialreader_State_event_consumed = 0;
if (_instance->SerialIn_serialreader_State == SERIALIN_SERIALREADER_CALIBRATIONRECEIVER_STATE) {
if (SerialIn_serialreader_State_event_consumed == 0 && Serial.available()) {
SerialIn_serialreader_OnExit(SERIALIN_SERIALREADER_CALIBRATIONRECEIVER_STATE, _instance);
_instance->SerialIn_serialreader_State = SERIALIN_SERIALREADER_IDLE_STATE;

																udouble ud ;
																for(int i = 0; i < 96; i++){
																		ud.b[i] = Serial.read();
																 }
SerialIn_send_serialcall_calibrationreceived(_instance, ud.d[0], ud.d[1], ud.d[2], ud.d[3], ud.d[4], ud.d[5], ud.d[6], ud.d[7], ud.d[8], ud.d[9], ud.d[10], ud.d[11]);
SerialIn_serialreader_OnEntry(SERIALIN_SERIALREADER_IDLE_STATE, _instance);
SerialIn_serialreader_State_event_consumed = 1;
}
}
//End Region serialreader
//End dsregion serialreader
//Session list: 
}

// Observers for outgoing messages:
void (*external_SerialIn_send_serialcall_calibrationreceived_listener)(struct SerialIn_Instance *, double, double, double, double, double, double, double, double, double, double, double, double)= 0x0;
void (*SerialIn_send_serialcall_calibrationreceived_listener)(struct SerialIn_Instance *, double, double, double, double, double, double, double, double, double, double, double, double)= 0x0;
void register_external_SerialIn_send_serialcall_calibrationreceived_listener(void (*_listener)(struct SerialIn_Instance *, double, double, double, double, double, double, double, double, double, double, double, double)){
external_SerialIn_send_serialcall_calibrationreceived_listener = _listener;
}
void register_SerialIn_send_serialcall_calibrationreceived_listener(void (*_listener)(struct SerialIn_Instance *, double, double, double, double, double, double, double, double, double, double, double, double)){
SerialIn_send_serialcall_calibrationreceived_listener = _listener;
}
void SerialIn_send_serialcall_calibrationreceived(struct SerialIn_Instance *_instance, double bx, double by, double bz, double brx, double bry, double brz, double cx, double cy, double cz, double crx, double cry, double crz){
if (SerialIn_send_serialcall_calibrationreceived_listener != 0x0) SerialIn_send_serialcall_calibrationreceived_listener(_instance, bx, by, bz, brx, bry, brz, cx, cy, cz, crx, cry, crz);
if (external_SerialIn_send_serialcall_calibrationreceived_listener != 0x0) external_SerialIn_send_serialcall_calibrationreceived_listener(_instance, bx, by, bz, brx, bry, brz, cx, cy, cz, crx, cry, crz);
;
}
void (*external_SerialIn_send_Timer_serial_timeout_listener)(struct SerialIn_Instance *)= 0x0;
void (*SerialIn_send_Timer_serial_timeout_listener)(struct SerialIn_Instance *)= 0x0;
void register_external_SerialIn_send_Timer_serial_timeout_listener(void (*_listener)(struct SerialIn_Instance *)){
external_SerialIn_send_Timer_serial_timeout_listener = _listener;
}
void register_SerialIn_send_Timer_serial_timeout_listener(void (*_listener)(struct SerialIn_Instance *)){
SerialIn_send_Timer_serial_timeout_listener = _listener;
}
void SerialIn_send_Timer_serial_timeout(struct SerialIn_Instance *_instance){
if (SerialIn_send_Timer_serial_timeout_listener != 0x0) SerialIn_send_Timer_serial_timeout_listener(_instance);
if (external_SerialIn_send_Timer_serial_timeout_listener != 0x0) external_SerialIn_send_Timer_serial_timeout_listener(_instance);
;
}



