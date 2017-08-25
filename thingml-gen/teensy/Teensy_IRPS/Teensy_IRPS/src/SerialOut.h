#ifndef SerialOut
#define SerialOut
#include "WProgram.h"
/*****************************************************************************
 * Headers for type : SerialOut
 *****************************************************************************/

// Definition of the instance struct:
struct SerialOut_Instance {

// Instances of different sessions
bool active;
// Variables for the ID of the ports of the instance
uint16_t id_basic;
// Variables for the current instance state
int SerialOut_Message_State;
// Variables for the properties of the instance

};
// generateEventHandlers2
int SerialOut_handle_empty_event(struct SerialOut_Instance *_instance);
// Declaration of prototypes outgoing messages :
void SerialOut_Message_OnEntry(int state, struct SerialOut_Instance *_instance);
void SerialOut_handle_basic_printPoint(struct SerialOut_Instance *_instance, double x, double y, double z, double separation, uint8_t verbose);
void SerialOut_handle_basic_printOperationState(struct SerialOut_Instance *_instance, uint8_t id, uint8_t verbose);
void SerialOut_handle_basic_printStatus(struct SerialOut_Instance *_instance, uint8_t id, uint8_t verbose);
// Declaration of callbacks for incoming messages:

// Definition of the states:
#define SERIALOUT_MESSAGE_STATE 0
#define SERIALOUT_MESSAGE_IDLE_STATE 1



#endif