#include "Button.h"
/*****************************************************************************
 * Implementation for type : Button
 *****************************************************************************/


// BEGIN: Code from the c_global annotation Button
extern struct Button_Instance button_var;
// END: Code from the c_global annotation Button

// Declaration of prototypes:
//Prototypes: State Machine
void Button_Button_OnExit(int state, struct Button_Instance *_instance);
//Prototypes: Message Sending
void Button_send_clock_ms25_tic(struct Button_Instance *_instance);
void Button_send_evt_press(struct Button_Instance *_instance);
void Button_send_evt_release(struct Button_Instance *_instance);
//Prototypes: Function
uint8_t f_Button_is_pressed(struct Button_Instance *_instance);
void time_25ms();
// Declaration of functions:
// Definition of function is_pressed
uint8_t f_Button_is_pressed(struct Button_Instance *_instance) {
return 1 - digitalRead(_instance->Button_PIN_var);
}
// Definition of function time_25ms
void time_25ms() {
Button_send_clock_ms25_tic(&button_var);
start_timer(0, 25, &time_25ms);
}

// Sessions functionss:


// On Entry Actions:
void Button_Button_OnEntry(int state, struct Button_Instance *_instance) {
switch(state) {
case BUTTON_BUTTON_STATE:{
_instance->Button_Button_State = BUTTON_BUTTON_RELEASED_STATE;
pinMode(_instance->Button_PIN_var, INPUT_PULLUP);
			initialize_timer();
			start_timer(0, 125, &time_25ms);
Button_Button_OnEntry(_instance->Button_Button_State, _instance);
break;
}
case BUTTON_BUTTON_RELEASED_STATE:{
break;
}
case BUTTON_BUTTON_PRESSED_STATE:{
break;
}
default: break;
}
}

// On Exit Actions:
void Button_Button_OnExit(int state, struct Button_Instance *_instance) {
switch(state) {
case BUTTON_BUTTON_STATE:{
Button_Button_OnExit(_instance->Button_Button_State, _instance);
break;}
case BUTTON_BUTTON_RELEASED_STATE:{
break;}
case BUTTON_BUTTON_PRESSED_STATE:{
break;}
default: break;
}
}

// Event Handlers for incoming messages:
void Button_handle_clock_ms25_tic(struct Button_Instance *_instance) {
if(!(_instance->active)) return;
//Region Button
uint8_t Button_Button_State_event_consumed = 0;
if (_instance->Button_Button_State == BUTTON_BUTTON_RELEASED_STATE) {
if (Button_Button_State_event_consumed == 0 && f_Button_is_pressed(_instance)) {
Button_Button_OnExit(BUTTON_BUTTON_RELEASED_STATE, _instance);
_instance->Button_Button_State = BUTTON_BUTTON_PRESSED_STATE;
Button_send_evt_press(_instance);
Button_Button_OnEntry(BUTTON_BUTTON_PRESSED_STATE, _instance);
Button_Button_State_event_consumed = 1;
}
}
else if (_instance->Button_Button_State == BUTTON_BUTTON_PRESSED_STATE) {
if (Button_Button_State_event_consumed == 0 &&  !(f_Button_is_pressed(_instance))) {
Button_Button_OnExit(BUTTON_BUTTON_PRESSED_STATE, _instance);
_instance->Button_Button_State = BUTTON_BUTTON_RELEASED_STATE;
Button_send_evt_release(_instance);
Button_Button_OnEntry(BUTTON_BUTTON_RELEASED_STATE, _instance);
Button_Button_State_event_consumed = 1;
}
}
//End Region Button
//End dsregion Button
//Session list: 
}

// Observers for outgoing messages:
void (*external_Button_send_clock_ms25_tic_listener)(struct Button_Instance *)= 0x0;
void (*Button_send_clock_ms25_tic_listener)(struct Button_Instance *)= 0x0;
void register_external_Button_send_clock_ms25_tic_listener(void (*_listener)(struct Button_Instance *)){
external_Button_send_clock_ms25_tic_listener = _listener;
}
void register_Button_send_clock_ms25_tic_listener(void (*_listener)(struct Button_Instance *)){
Button_send_clock_ms25_tic_listener = _listener;
}
void Button_send_clock_ms25_tic(struct Button_Instance *_instance){
if (Button_send_clock_ms25_tic_listener != 0x0) Button_send_clock_ms25_tic_listener(_instance);
if (external_Button_send_clock_ms25_tic_listener != 0x0) external_Button_send_clock_ms25_tic_listener(_instance);
;
}
void (*external_Button_send_evt_press_listener)(struct Button_Instance *)= 0x0;
void (*Button_send_evt_press_listener)(struct Button_Instance *)= 0x0;
void register_external_Button_send_evt_press_listener(void (*_listener)(struct Button_Instance *)){
external_Button_send_evt_press_listener = _listener;
}
void register_Button_send_evt_press_listener(void (*_listener)(struct Button_Instance *)){
Button_send_evt_press_listener = _listener;
}
void Button_send_evt_press(struct Button_Instance *_instance){
if (Button_send_evt_press_listener != 0x0) Button_send_evt_press_listener(_instance);
if (external_Button_send_evt_press_listener != 0x0) external_Button_send_evt_press_listener(_instance);
;
}
void (*external_Button_send_evt_release_listener)(struct Button_Instance *)= 0x0;
void (*Button_send_evt_release_listener)(struct Button_Instance *)= 0x0;
void register_external_Button_send_evt_release_listener(void (*_listener)(struct Button_Instance *)){
external_Button_send_evt_release_listener = _listener;
}
void register_Button_send_evt_release_listener(void (*_listener)(struct Button_Instance *)){
Button_send_evt_release_listener = _listener;
}
void Button_send_evt_release(struct Button_Instance *_instance){
if (Button_send_evt_release_listener != 0x0) Button_send_evt_release_listener(_instance);
if (external_Button_send_evt_release_listener != 0x0) external_Button_send_evt_release_listener(_instance);
;
}



