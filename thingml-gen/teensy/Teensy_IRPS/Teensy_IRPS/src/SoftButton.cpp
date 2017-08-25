#include "SoftButton.h"
/*****************************************************************************
 * Implementation for type : SoftButton
 *****************************************************************************/


// BEGIN: Code from the c_global annotation SoftButton
extern struct SoftButton_Instance softButton_var;
// END: Code from the c_global annotation SoftButton

// Declaration of prototypes:
//Prototypes: State Machine
void SoftButton_SoftButtonImpl_OnExit(int state, struct SoftButton_Instance *_instance);
//Prototypes: Message Sending
void SoftButton_send_Timer_timer_timeout(struct SoftButton_Instance *_instance);
void SoftButton_send_SoftButton_click(struct SoftButton_Instance *_instance);
void SoftButton_send_SoftButton_double_click(struct SoftButton_Instance *_instance);
void SoftButton_send_SoftButton_long_press(struct SoftButton_Instance *_instance);
//Prototypes: Function
void timeout_button();
// Declaration of functions:
// Definition of function timeout_button
void timeout_button() {
SoftButton_send_Timer_timer_timeout(&softButton_var);
}

// Sessions functionss:


// On Entry Actions:
void SoftButton_SoftButtonImpl_OnEntry(int state, struct SoftButton_Instance *_instance) {
switch(state) {
case SOFTBUTTON_SOFTBUTTONIMPL_STATE:{
_instance->SoftButton_SoftButtonImpl_State = SOFTBUTTON_SOFTBUTTONIMPL_IDLE_STATE;
SoftButton_SoftButtonImpl_OnEntry(_instance->SoftButton_SoftButtonImpl_State, _instance);
break;
}
case SOFTBUTTON_SOFTBUTTONIMPL_IDLE_STATE:{
break;
}
case SOFTBUTTON_SOFTBUTTONIMPL_PRESSED_STATE:{
start_timer(1, _instance->SoftButton_long_delay_var, &timeout_button);
break;
}
case SOFTBUTTON_SOFTBUTTONIMPL_RELEASED_STATE:{
start_timer(1, _instance->SoftButton_double_delay_var, &timeout_button);
break;
}
default: break;
}
}

// On Exit Actions:
void SoftButton_SoftButtonImpl_OnExit(int state, struct SoftButton_Instance *_instance) {
switch(state) {
case SOFTBUTTON_SOFTBUTTONIMPL_STATE:{
SoftButton_SoftButtonImpl_OnExit(_instance->SoftButton_SoftButtonImpl_State, _instance);
break;}
case SOFTBUTTON_SOFTBUTTONIMPL_IDLE_STATE:{
break;}
case SOFTBUTTON_SOFTBUTTONIMPL_PRESSED_STATE:{
timer_cancel(1);
break;}
case SOFTBUTTON_SOFTBUTTONIMPL_RELEASED_STATE:{
timer_cancel(1);
break;}
default: break;
}
}

// Event Handlers for incoming messages:
void SoftButton_handle_Button_press(struct SoftButton_Instance *_instance) {
if(!(_instance->active)) return;
//Region SoftButtonImpl
uint8_t SoftButton_SoftButtonImpl_State_event_consumed = 0;
if (_instance->SoftButton_SoftButtonImpl_State == SOFTBUTTON_SOFTBUTTONIMPL_IDLE_STATE) {
if (SoftButton_SoftButtonImpl_State_event_consumed == 0 && 1) {
SoftButton_SoftButtonImpl_OnExit(SOFTBUTTON_SOFTBUTTONIMPL_IDLE_STATE, _instance);
_instance->SoftButton_SoftButtonImpl_State = SOFTBUTTON_SOFTBUTTONIMPL_PRESSED_STATE;
SoftButton_SoftButtonImpl_OnEntry(SOFTBUTTON_SOFTBUTTONIMPL_PRESSED_STATE, _instance);
SoftButton_SoftButtonImpl_State_event_consumed = 1;
}
}
else if (_instance->SoftButton_SoftButtonImpl_State == SOFTBUTTON_SOFTBUTTONIMPL_RELEASED_STATE) {
if (SoftButton_SoftButtonImpl_State_event_consumed == 0 && 1) {
SoftButton_SoftButtonImpl_OnExit(SOFTBUTTON_SOFTBUTTONIMPL_RELEASED_STATE, _instance);
_instance->SoftButton_SoftButtonImpl_State = SOFTBUTTON_SOFTBUTTONIMPL_IDLE_STATE;
SoftButton_send_SoftButton_double_click(_instance);
SoftButton_SoftButtonImpl_OnEntry(SOFTBUTTON_SOFTBUTTONIMPL_IDLE_STATE, _instance);
SoftButton_SoftButtonImpl_State_event_consumed = 1;
}
}
//End Region SoftButtonImpl
//End dsregion SoftButtonImpl
//Session list: 
}
void SoftButton_handle_Button_release(struct SoftButton_Instance *_instance) {
if(!(_instance->active)) return;
//Region SoftButtonImpl
uint8_t SoftButton_SoftButtonImpl_State_event_consumed = 0;
if (_instance->SoftButton_SoftButtonImpl_State == SOFTBUTTON_SOFTBUTTONIMPL_PRESSED_STATE) {
if (SoftButton_SoftButtonImpl_State_event_consumed == 0 && 1) {
SoftButton_SoftButtonImpl_OnExit(SOFTBUTTON_SOFTBUTTONIMPL_PRESSED_STATE, _instance);
_instance->SoftButton_SoftButtonImpl_State = SOFTBUTTON_SOFTBUTTONIMPL_RELEASED_STATE;
SoftButton_SoftButtonImpl_OnEntry(SOFTBUTTON_SOFTBUTTONIMPL_RELEASED_STATE, _instance);
SoftButton_SoftButtonImpl_State_event_consumed = 1;
}
}
//End Region SoftButtonImpl
//End dsregion SoftButtonImpl
//Session list: 
}
void SoftButton_handle_Timer_timer_timeout(struct SoftButton_Instance *_instance) {
if(!(_instance->active)) return;
//Region SoftButtonImpl
uint8_t SoftButton_SoftButtonImpl_State_event_consumed = 0;
if (_instance->SoftButton_SoftButtonImpl_State == SOFTBUTTON_SOFTBUTTONIMPL_PRESSED_STATE) {
if (SoftButton_SoftButtonImpl_State_event_consumed == 0 && 1) {
SoftButton_SoftButtonImpl_OnExit(SOFTBUTTON_SOFTBUTTONIMPL_PRESSED_STATE, _instance);
_instance->SoftButton_SoftButtonImpl_State = SOFTBUTTON_SOFTBUTTONIMPL_IDLE_STATE;
SoftButton_send_SoftButton_long_press(_instance);
SoftButton_SoftButtonImpl_OnEntry(SOFTBUTTON_SOFTBUTTONIMPL_IDLE_STATE, _instance);
SoftButton_SoftButtonImpl_State_event_consumed = 1;
}
}
else if (_instance->SoftButton_SoftButtonImpl_State == SOFTBUTTON_SOFTBUTTONIMPL_RELEASED_STATE) {
if (SoftButton_SoftButtonImpl_State_event_consumed == 0 && 1) {
SoftButton_SoftButtonImpl_OnExit(SOFTBUTTON_SOFTBUTTONIMPL_RELEASED_STATE, _instance);
_instance->SoftButton_SoftButtonImpl_State = SOFTBUTTON_SOFTBUTTONIMPL_IDLE_STATE;
SoftButton_send_SoftButton_click(_instance);
SoftButton_SoftButtonImpl_OnEntry(SOFTBUTTON_SOFTBUTTONIMPL_IDLE_STATE, _instance);
SoftButton_SoftButtonImpl_State_event_consumed = 1;
}
}
//End Region SoftButtonImpl
//End dsregion SoftButtonImpl
//Session list: 
}

// Observers for outgoing messages:
void (*external_SoftButton_send_Timer_timer_timeout_listener)(struct SoftButton_Instance *)= 0x0;
void (*SoftButton_send_Timer_timer_timeout_listener)(struct SoftButton_Instance *)= 0x0;
void register_external_SoftButton_send_Timer_timer_timeout_listener(void (*_listener)(struct SoftButton_Instance *)){
external_SoftButton_send_Timer_timer_timeout_listener = _listener;
}
void register_SoftButton_send_Timer_timer_timeout_listener(void (*_listener)(struct SoftButton_Instance *)){
SoftButton_send_Timer_timer_timeout_listener = _listener;
}
void SoftButton_send_Timer_timer_timeout(struct SoftButton_Instance *_instance){
if (SoftButton_send_Timer_timer_timeout_listener != 0x0) SoftButton_send_Timer_timer_timeout_listener(_instance);
if (external_SoftButton_send_Timer_timer_timeout_listener != 0x0) external_SoftButton_send_Timer_timer_timeout_listener(_instance);
;
}
void (*external_SoftButton_send_SoftButton_click_listener)(struct SoftButton_Instance *)= 0x0;
void (*SoftButton_send_SoftButton_click_listener)(struct SoftButton_Instance *)= 0x0;
void register_external_SoftButton_send_SoftButton_click_listener(void (*_listener)(struct SoftButton_Instance *)){
external_SoftButton_send_SoftButton_click_listener = _listener;
}
void register_SoftButton_send_SoftButton_click_listener(void (*_listener)(struct SoftButton_Instance *)){
SoftButton_send_SoftButton_click_listener = _listener;
}
void SoftButton_send_SoftButton_click(struct SoftButton_Instance *_instance){
if (SoftButton_send_SoftButton_click_listener != 0x0) SoftButton_send_SoftButton_click_listener(_instance);
if (external_SoftButton_send_SoftButton_click_listener != 0x0) external_SoftButton_send_SoftButton_click_listener(_instance);
;
}
void (*external_SoftButton_send_SoftButton_double_click_listener)(struct SoftButton_Instance *)= 0x0;
void (*SoftButton_send_SoftButton_double_click_listener)(struct SoftButton_Instance *)= 0x0;
void register_external_SoftButton_send_SoftButton_double_click_listener(void (*_listener)(struct SoftButton_Instance *)){
external_SoftButton_send_SoftButton_double_click_listener = _listener;
}
void register_SoftButton_send_SoftButton_double_click_listener(void (*_listener)(struct SoftButton_Instance *)){
SoftButton_send_SoftButton_double_click_listener = _listener;
}
void SoftButton_send_SoftButton_double_click(struct SoftButton_Instance *_instance){
if (SoftButton_send_SoftButton_double_click_listener != 0x0) SoftButton_send_SoftButton_double_click_listener(_instance);
if (external_SoftButton_send_SoftButton_double_click_listener != 0x0) external_SoftButton_send_SoftButton_double_click_listener(_instance);
;
}
void (*external_SoftButton_send_SoftButton_long_press_listener)(struct SoftButton_Instance *)= 0x0;
void (*SoftButton_send_SoftButton_long_press_listener)(struct SoftButton_Instance *)= 0x0;
void register_external_SoftButton_send_SoftButton_long_press_listener(void (*_listener)(struct SoftButton_Instance *)){
external_SoftButton_send_SoftButton_long_press_listener = _listener;
}
void register_SoftButton_send_SoftButton_long_press_listener(void (*_listener)(struct SoftButton_Instance *)){
SoftButton_send_SoftButton_long_press_listener = _listener;
}
void SoftButton_send_SoftButton_long_press(struct SoftButton_Instance *_instance){
if (SoftButton_send_SoftButton_long_press_listener != 0x0) SoftButton_send_SoftButton_long_press_listener(_instance);
if (external_SoftButton_send_SoftButton_long_press_listener != 0x0) external_SoftButton_send_SoftButton_long_press_listener(_instance);
;
}



