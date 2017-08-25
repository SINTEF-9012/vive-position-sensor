#ifndef Blinker
#define Blinker
#include "WProgram.h"
/*****************************************************************************
 * Headers for type : Blinker
 *****************************************************************************/


// BEGIN: Code from the c_header annotation Blinker

#include <Timer.h>
#include <Adafruit_NeoPixel.h>
#include <Color_Helper.h>

// END: Code from the c_header annotation Blinker

// Definition of the instance struct:
struct Blinker_Instance {

// Instances of different sessions
bool active;
// Variables for the ID of the ports of the instance
uint16_t id_evt;
uint16_t id_neopixel;
// Variables for the current instance state
int Blinker_BlinkerState_State;
// Variables for the properties of the instance

};
// generateEventHandlers2
int Blinker_handle_empty_event(struct Blinker_Instance *_instance);
// Declaration of prototypes outgoing messages :
void Blinker_BlinkerState_OnEntry(int state, struct Blinker_Instance *_instance);
void Blinker_handle_neopixel_statusID(struct Blinker_Instance *_instance, uint8_t id);
void Blinker_handle_neopixel_stateID(struct Blinker_Instance *_instance, uint8_t id);
void Blinker_handle_evt_blink(struct Blinker_Instance *_instance);
// Declaration of callbacks for incoming messages:
void register_Blinker_send_evt_blink_listener(void (*_listener)(struct Blinker_Instance *));
void register_external_Blinker_send_evt_blink_listener(void (*_listener)(struct Blinker_Instance *));

// Definition of the states:
#define BLINKER_BLINKERSTATE_STATE 0
#define BLINKER_BLINKERSTATE_IDLE_STATE 1



#endif