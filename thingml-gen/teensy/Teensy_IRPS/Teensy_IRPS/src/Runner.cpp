#include "Runner.h"
/*****************************************************************************
 * Implementation for type : Runner
 *****************************************************************************/


// BEGIN: Code from the c_global annotation Runner

    Pose bPose;
    Pose cPose;

// END: Code from the c_global annotation Runner

// Declaration of prototypes:
//Prototypes: State Machine
void Runner_Running_OnExit(int state, struct Runner_Instance *_instance);
//Prototypes: Message Sending
void Runner_send_Run_coordinates(struct Runner_Instance *_instance, double x, double y, double z, double separation);
void Runner_send_StatusSender_status(struct Runner_Instance *_instance, uint8_t id);
//Prototypes: Function
// Declaration of functions:

// Sessions functionss:


// On Entry Actions:
void Runner_Running_OnEntry(int state, struct Runner_Instance *_instance) {
switch(state) {
case RUNNER_RUNNING_STATE:{
_instance->Runner_Running_State = RUNNER_RUNNING_IDLE_STATE;
Runner_Running_OnEntry(_instance->Runner_Running_State, _instance);
break;
}
case RUNNER_RUNNING_IDLE_STATE:{
break;
}
default: break;
}
}

// On Exit Actions:
void Runner_Running_OnExit(int state, struct Runner_Instance *_instance) {
switch(state) {
case RUNNER_RUNNING_STATE:{
Runner_Running_OnExit(_instance->Runner_Running_State, _instance);
break;}
case RUNNER_RUNNING_IDLE_STATE:{
break;}
default: break;
}
}

// Event Handlers for incoming messages:
void Runner_handle_Run_baseStationAngles(struct Runner_Instance *_instance, double bh, double bv, double ch, double cv) {
if(!(_instance->active)) return;
//Region Running
uint8_t Runner_Running_State_event_consumed = 0;
//End Region Running
//End dsregion Running
//Session list: 
if (1) {
Vec p = positionFromAngles(bh,bv,ch,cv);
Runner_send_Run_coordinates(_instance, p[0], p[1], p[2], diststanceBetweenLines);
if(diststanceBetweenLines > MAX_LINE_SEPARATION) {
Runner_send_StatusSender_status(_instance, 0);

}
Runner_Running_State_event_consumed = 1;
}
}

// Observers for outgoing messages:
void (*external_Runner_send_Run_coordinates_listener)(struct Runner_Instance *, double, double, double, double)= 0x0;
void (*Runner_send_Run_coordinates_listener)(struct Runner_Instance *, double, double, double, double)= 0x0;
void register_external_Runner_send_Run_coordinates_listener(void (*_listener)(struct Runner_Instance *, double, double, double, double)){
external_Runner_send_Run_coordinates_listener = _listener;
}
void register_Runner_send_Run_coordinates_listener(void (*_listener)(struct Runner_Instance *, double, double, double, double)){
Runner_send_Run_coordinates_listener = _listener;
}
void Runner_send_Run_coordinates(struct Runner_Instance *_instance, double x, double y, double z, double separation){
if (Runner_send_Run_coordinates_listener != 0x0) Runner_send_Run_coordinates_listener(_instance, x, y, z, separation);
if (external_Runner_send_Run_coordinates_listener != 0x0) external_Runner_send_Run_coordinates_listener(_instance, x, y, z, separation);
;
}
void (*external_Runner_send_StatusSender_status_listener)(struct Runner_Instance *, uint8_t)= 0x0;
void (*Runner_send_StatusSender_status_listener)(struct Runner_Instance *, uint8_t)= 0x0;
void register_external_Runner_send_StatusSender_status_listener(void (*_listener)(struct Runner_Instance *, uint8_t)){
external_Runner_send_StatusSender_status_listener = _listener;
}
void register_Runner_send_StatusSender_status_listener(void (*_listener)(struct Runner_Instance *, uint8_t)){
Runner_send_StatusSender_status_listener = _listener;
}
void Runner_send_StatusSender_status(struct Runner_Instance *_instance, uint8_t id){
if (Runner_send_StatusSender_status_listener != 0x0) Runner_send_StatusSender_status_listener(_instance, id);
if (external_Runner_send_StatusSender_status_listener != 0x0) external_Runner_send_StatusSender_status_listener(_instance, id);
;
}



