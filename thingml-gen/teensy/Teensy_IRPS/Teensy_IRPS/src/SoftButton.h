#ifndef SoftButton
#define SoftButton
#include "WProgram.h"
/*****************************************************************************
 * Headers for type : SoftButton
 *****************************************************************************/


// BEGIN: Code from the c_header annotation SoftButton
#include <Timer.h>
// END: Code from the c_header annotation SoftButton

// Definition of the instance struct:
struct SoftButton_Instance {

// Instances of different sessions
bool active;
// Variables for the ID of the ports of the instance
uint16_t id_Button;
uint16_t id_Timer;
uint16_t id_SoftButton;
// Variables for the current instance state
int SoftButton_SoftButtonImpl_State;
// Variables for the properties of the instance
uint16_t SoftButton_long_delay_var;
uint16_t SoftButton_double_delay_var;

};
// generateEventHandlers2
int SoftButton_handle_empty_event(struct SoftButton_Instance *_instance);
// Declaration of prototypes outgoing messages :
void SoftButton_SoftButtonImpl_OnEntry(int state, struct SoftButton_Instance *_instance);
void SoftButton_handle_Button_press(struct SoftButton_Instance *_instance);
void SoftButton_handle_Button_release(struct SoftButton_Instance *_instance);
void SoftButton_handle_Timer_timer_timeout(struct SoftButton_Instance *_instance);
// Declaration of callbacks for incoming messages:
void register_SoftButton_send_Timer_timer_timeout_listener(void (*_listener)(struct SoftButton_Instance *));
void register_external_SoftButton_send_Timer_timer_timeout_listener(void (*_listener)(struct SoftButton_Instance *));
void register_SoftButton_send_SoftButton_click_listener(void (*_listener)(struct SoftButton_Instance *));
void register_external_SoftButton_send_SoftButton_click_listener(void (*_listener)(struct SoftButton_Instance *));
void register_SoftButton_send_SoftButton_double_click_listener(void (*_listener)(struct SoftButton_Instance *));
void register_external_SoftButton_send_SoftButton_double_click_listener(void (*_listener)(struct SoftButton_Instance *));
void register_SoftButton_send_SoftButton_long_press_listener(void (*_listener)(struct SoftButton_Instance *));
void register_external_SoftButton_send_SoftButton_long_press_listener(void (*_listener)(struct SoftButton_Instance *));

// Definition of the states:
#define SOFTBUTTON_SOFTBUTTONIMPL_STATE 0
#define SOFTBUTTON_SOFTBUTTONIMPL_IDLE_STATE 1
#define SOFTBUTTON_SOFTBUTTONIMPL_PRESSED_STATE 2
#define SOFTBUTTON_SOFTBUTTONIMPL_RELEASED_STATE 3



#endif