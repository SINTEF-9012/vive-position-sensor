#include "SerialOut.h"
/*****************************************************************************
 * Implementation for type : SerialOut
 *****************************************************************************/

// Declaration of prototypes:
//Prototypes: State Machine
void SerialOut_Message_OnExit(int state, struct SerialOut_Instance *_instance);
//Prototypes: Message Sending
//Prototypes: Function
// Declaration of functions:

// Sessions functionss:


// On Entry Actions:
void SerialOut_Message_OnEntry(int state, struct SerialOut_Instance *_instance) {
switch(state) {
case SERIALOUT_MESSAGE_STATE:{
_instance->SerialOut_Message_State = SERIALOUT_MESSAGE_IDLE_STATE;
Serial.begin(115200);
SerialOut_Message_OnEntry(_instance->SerialOut_Message_State, _instance);
break;
}
case SERIALOUT_MESSAGE_IDLE_STATE:{
break;
}
default: break;
}
}

// On Exit Actions:
void SerialOut_Message_OnExit(int state, struct SerialOut_Instance *_instance) {
switch(state) {
case SERIALOUT_MESSAGE_STATE:{
SerialOut_Message_OnExit(_instance->SerialOut_Message_State, _instance);
break;}
case SERIALOUT_MESSAGE_IDLE_STATE:{
break;}
default: break;
}
}

// Event Handlers for incoming messages:
void SerialOut_handle_basic_printPoint(struct SerialOut_Instance *_instance, double x, double y, double z, double separation, uint8_t verbose) {
if(!(_instance->active)) return;
//Region Message
uint8_t SerialOut_Message_State_event_consumed = 0;
if (_instance->SerialOut_Message_State == SERIALOUT_MESSAGE_IDLE_STATE) {
if (SerialOut_Message_State_event_consumed == 0 && 1) {
if(verbose) {

    		        Serial.print("\nJ,");
    		        Serial.print(x,3);
    		        Serial.print(",");
    		        Serial.print(y,3);
    		        Serial.print(",");
    		        Serial.print(z,3);
    		        Serial.print(",");
    		        Serial.print(separation,4);
                    Serial.print(",");
    		    

} else {

                    Serial.print("\nPoint:\t");
                    Serial.print(x,3);
                    Serial.print(",\t");
                    Serial.print(y,3);
                    Serial.print(",\t");
                    Serial.print(z,3);
                    Serial.print(",\t"); 
                    Serial.print(separation,4);
    		    

}
SerialOut_Message_State_event_consumed = 1;
}
}
//End Region Message
//End dsregion Message
//Session list: 
}
void SerialOut_handle_basic_printOperationState(struct SerialOut_Instance *_instance, uint8_t id, uint8_t verbose) {
if(!(_instance->active)) return;
//Region Message
uint8_t SerialOut_Message_State_event_consumed = 0;
if (_instance->SerialOut_Message_State == SERIALOUT_MESSAGE_IDLE_STATE) {
if (SerialOut_Message_State_event_consumed == 0 && 1) {
if(verbose) {

                    Serial.print("\nI,");
                    Serial.print(id);
                    Serial.print(",");
                

} else {

                    Serial.print("\nState:\t");
                    Serial.print(id);
                

}
SerialOut_Message_State_event_consumed = 1;
}
}
//End Region Message
//End dsregion Message
//Session list: 
}
void SerialOut_handle_basic_printStatus(struct SerialOut_Instance *_instance, uint8_t id, uint8_t verbose) {
if(!(_instance->active)) return;
//Region Message
uint8_t SerialOut_Message_State_event_consumed = 0;
if (_instance->SerialOut_Message_State == SERIALOUT_MESSAGE_IDLE_STATE) {
if (SerialOut_Message_State_event_consumed == 0 && 1) {
if(verbose) {

                    Serial.print("\nH,");
                    Serial.print(id);
                    Serial.print(",");
                

} else {

		            Serial.print("\nStatus:\t");
		            Serial.print(id);
		        

}
SerialOut_Message_State_event_consumed = 1;
}
}
//End Region Message
//End dsregion Message
//Session list: 
}

// Observers for outgoing messages:



