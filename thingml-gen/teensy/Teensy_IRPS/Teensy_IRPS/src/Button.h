#ifndef Button
#define Button
#include "WProgram.h"
/*****************************************************************************
 * Headers for type : Button
 *****************************************************************************/


// BEGIN: Code from the c_header annotation Button
#include <Timer.h>
// END: Code from the c_header annotation Button

// Definition of the instance struct:
struct Button_Instance {

// Instances of different sessions
bool active;
// Variables for the ID of the ports of the instance
uint16_t id_clock;
uint16_t id_evt;
// Variables for the current instance state
int Button_Button_State;
// Variables for the properties of the instance
uint8_t Button_PIN_var;

};
// generateEventHandlers2
int Button_handle_empty_event(struct Button_Instance *_instance);
// Declaration of prototypes outgoing messages :
void Button_Button_OnEntry(int state, struct Button_Instance *_instance);
void Button_handle_clock_ms25_tic(struct Button_Instance *_instance);
// Declaration of callbacks for incoming messages:
void register_Button_send_clock_ms25_tic_listener(void (*_listener)(struct Button_Instance *));
void register_external_Button_send_clock_ms25_tic_listener(void (*_listener)(struct Button_Instance *));
void register_Button_send_evt_press_listener(void (*_listener)(struct Button_Instance *));
void register_external_Button_send_evt_press_listener(void (*_listener)(struct Button_Instance *));
void register_Button_send_evt_release_listener(void (*_listener)(struct Button_Instance *));
void register_external_Button_send_evt_release_listener(void (*_listener)(struct Button_Instance *));

// Definition of the states:
#define BUTTON_BUTTON_STATE 0
#define BUTTON_BUTTON_RELEASED_STATE 1
#define BUTTON_BUTTON_PRESSED_STATE 2



#endif