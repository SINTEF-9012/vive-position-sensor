#ifndef SerialIn
#define SerialIn
#include "WProgram.h"
/*****************************************************************************
 * Headers for type : SerialIn
 *****************************************************************************/


// BEGIN: Code from the c_header annotation SerialIn
#include <Timer.h>
#include <constants.h>
// END: Code from the c_header annotation SerialIn

// Definition of the instance struct:
struct SerialIn_Instance {

// Instances of different sessions
bool active;
// Variables for the ID of the ports of the instance
uint16_t id_serialcall;
uint16_t id_Timer;
// Variables for the current instance state
int SerialIn_serialreader_State;
// Variables for the properties of the instance

};
// generateEventHandlers2
int SerialIn_handle_empty_event(struct SerialIn_Instance *_instance);
// Declaration of prototypes outgoing messages :
void SerialIn_serialreader_OnEntry(int state, struct SerialIn_Instance *_instance);
void SerialIn_handle_serialcall_waitcalibration(struct SerialIn_Instance *_instance);
void SerialIn_handle_Timer_serial_timeout(struct SerialIn_Instance *_instance);
// Declaration of callbacks for incoming messages:
void register_SerialIn_send_serialcall_calibrationreceived_listener(void (*_listener)(struct SerialIn_Instance *, double, double, double, double, double, double, double, double, double, double, double, double));
void register_external_SerialIn_send_serialcall_calibrationreceived_listener(void (*_listener)(struct SerialIn_Instance *, double, double, double, double, double, double, double, double, double, double, double, double));
void register_SerialIn_send_Timer_serial_timeout_listener(void (*_listener)(struct SerialIn_Instance *));
void register_external_SerialIn_send_Timer_serial_timeout_listener(void (*_listener)(struct SerialIn_Instance *));

// Definition of the states:
#define SERIALIN_SERIALREADER_STATE 0
#define SERIALIN_SERIALREADER_IDLE_STATE 1
#define SERIALIN_SERIALREADER_CALIBRATIONRECEIVER_STATE 2



#endif