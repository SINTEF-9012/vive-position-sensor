#include "Blinker.h"
/*****************************************************************************
 * Implementation for type : Blinker
 *****************************************************************************/


// BEGIN: Code from the c_global annotation Blinker

extern struct Blinker_Instance blinker_var;
boolean current_blink = HIGH;

#define PIN 8
#define NUM_LEDS 1
#define BRIGHTNESS 50

uint32_t returnColor = RED;
bool timeout = false;
int8_t timeoutPriority = 0;

Adafruit_NeoPixel led = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRBW + NEO_KHZ800);

// END: Code from the c_global annotation Blinker

// Declaration of prototypes:
//Prototypes: State Machine
void Blinker_BlinkerState_OnExit(int state, struct Blinker_Instance *_instance);
//Prototypes: Message Sending
void Blinker_send_evt_blink(struct Blinker_Instance *_instance);
//Prototypes: Function
void f_Blinker_startLEDFlashAfterDuration(struct Blinker_Instance *_instance, uint32_t duration);
void callback_message_flash();
void f_Blinker_setColorForDuration(struct Blinker_Instance *_instance, uint32_t color, uint32_t duration);
void callback_message_neopixel();
void f_Blinker_timeoutColorChangeForDuration(struct Blinker_Instance *_instance, uint32_t duration);
void callback_message_timeout();
// Declaration of functions:
// Definition of function startLEDFlashAfterDuration
void f_Blinker_startLEDFlashAfterDuration(struct Blinker_Instance *_instance, uint32_t duration) {
start_timer(5, duration, &callback_message_flash);
}
// Definition of function callback_message_flash
void callback_message_flash() {

        Blinker_send_evt_blink(&blinker_var);
        start_timer(5, 100, &callback_message_flash);
        
}
// Definition of function setColorForDuration
void f_Blinker_setColorForDuration(struct Blinker_Instance *_instance, uint32_t color, uint32_t duration) {
led.setPixelColor(0, color);
        led.show();
start_timer(6, duration, &callback_message_neopixel);
}
// Definition of function callback_message_neopixel
void callback_message_neopixel() {

        led.setPixelColor(0, returnColor);
        led.show();
        
}
// Definition of function timeoutColorChangeForDuration
void f_Blinker_timeoutColorChangeForDuration(struct Blinker_Instance *_instance, uint32_t duration) {
timeout = true;
start_timer(7, duration, &callback_message_timeout);
}
// Definition of function callback_message_timeout
void callback_message_timeout() {
timeout = false;
}

// Sessions functionss:


// On Entry Actions:
void Blinker_BlinkerState_OnEntry(int state, struct Blinker_Instance *_instance) {
switch(state) {
case BLINKER_BLINKERSTATE_STATE:{
_instance->Blinker_BlinkerState_State = BLINKER_BLINKERSTATE_IDLE_STATE;
pinMode(13, OUTPUT);
    				 led.setBrightness(BRIGHTNESS);
					 led.begin();
					 led.show();
    				 
f_Blinker_startLEDFlashAfterDuration(_instance, 1000);
Blinker_BlinkerState_OnEntry(_instance->Blinker_BlinkerState_State, _instance);
break;
}
case BLINKER_BLINKERSTATE_IDLE_STATE:{
break;
}
default: break;
}
}

// On Exit Actions:
void Blinker_BlinkerState_OnExit(int state, struct Blinker_Instance *_instance) {
switch(state) {
case BLINKER_BLINKERSTATE_STATE:{
Blinker_BlinkerState_OnExit(_instance->Blinker_BlinkerState_State, _instance);
break;}
case BLINKER_BLINKERSTATE_IDLE_STATE:{
break;}
default: break;
}
}

// Event Handlers for incoming messages:
void Blinker_handle_neopixel_statusID(struct Blinker_Instance *_instance, uint8_t id) {
if(!(_instance->active)) return;
//Region BlinkerState
uint8_t Blinker_BlinkerState_State_event_consumed = 0;
//End Region BlinkerState
//End dsregion BlinkerState
//Session list: 
if (1) {


    		uint32_t flashColor;
    		int8_t priority;

    		switch(id) {
    			case 0:  flashColor = RED;           priority = 1; break;
    			case 1:  flashColor = BLUE;          priority = 0; break;
    			case 2:  flashColor = LIME;          priority = 1; break;
    			case 3:  flashColor = LAVENDER;      priority =-1; break;
    			case 4:  flashColor = DARK_GREEN;    priority = 4; break;
    			case 5:  flashColor = DARK_GREEN;    priority = 3; break;
    			case 6:  flashColor = DARK_RED;      priority = 3; break;
    			case 7:  flashColor = DARK_RED;      priority = 4; break;
    			case 8:  flashColor = GREEN;         priority = 2; break;
    			case 9:  flashColor = RED;           priority = 2; break;
    			case 10: flashColor = YELLOW;        priority = 0; break;
    			case 11: flashColor = BROWN;         priority = 1; break;
    			case 12: flashColor = CIAN;          priority = 0; break;
    			case 13: flashColor = DARK_GREEN;    priority = 0; break;
    			case 14: flashColor = PURPLE;        priority =-1; break;
    			case 15: flashColor = GREY;          priority = 0; break;
    			default: flashColor = BLACK;         priority = 0;
        	}
        	if (!timeout || priority > timeoutPriority) {
        	    timeoutPriority = priority;
        	    uint16_t duration = priority > 0 ? 600 : 100;
f_Blinker_setColorForDuration(_instance, flashColor, duration+100);
f_Blinker_timeoutColorChangeForDuration(_instance, duration);
}
Blinker_BlinkerState_State_event_consumed = 1;
}
}
void Blinker_handle_neopixel_stateID(struct Blinker_Instance *_instance, uint8_t id) {
if(!(_instance->active)) return;
//Region BlinkerState
uint8_t Blinker_BlinkerState_State_event_consumed = 0;
//End Region BlinkerState
//End dsregion BlinkerState
//Session list: 
if (1) {


    		switch(id) {
    		    case 1: returnColor  = ORANGE; break; // LoadCalibration
    		    case 2: returnColor  = WHITE; break;  // Calibration
    		    case 3: returnColor  = ORANGE; break; // Validate_Calibration
    		    case 4: returnColor  = GREEN;  break; // Runner
    		    default: returnColor = BLACK;
    		}

    		if (!timeout) {
    		    led.setPixelColor(0, returnColor);
    		    led.show();
    		    
f_Blinker_timeoutColorChangeForDuration(_instance, 1000);

    		}
      		
Blinker_BlinkerState_State_event_consumed = 1;
}
}
void Blinker_handle_evt_blink(struct Blinker_Instance *_instance) {
if(!(_instance->active)) return;
//Region BlinkerState
uint8_t Blinker_BlinkerState_State_event_consumed = 0;
//End Region BlinkerState
//End dsregion BlinkerState
//Session list: 
if (1) {

		    digitalWriteFast(13, current_blink);
    		current_blink = (current_blink == HIGH)? LOW : HIGH;
    	    
Blinker_BlinkerState_State_event_consumed = 1;
}
}

// Observers for outgoing messages:
void (*external_Blinker_send_evt_blink_listener)(struct Blinker_Instance *)= 0x0;
void (*Blinker_send_evt_blink_listener)(struct Blinker_Instance *)= 0x0;
void register_external_Blinker_send_evt_blink_listener(void (*_listener)(struct Blinker_Instance *)){
external_Blinker_send_evt_blink_listener = _listener;
}
void register_Blinker_send_evt_blink_listener(void (*_listener)(struct Blinker_Instance *)){
Blinker_send_evt_blink_listener = _listener;
}
void Blinker_send_evt_blink(struct Blinker_Instance *_instance){
if (Blinker_send_evt_blink_listener != 0x0) Blinker_send_evt_blink_listener(_instance);
if (external_Blinker_send_evt_blink_listener != 0x0) external_Blinker_send_evt_blink_listener(_instance);
;
}



