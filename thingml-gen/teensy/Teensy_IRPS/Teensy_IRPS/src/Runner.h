#ifndef Runner
#define Runner
#include "WProgram.h"
/*****************************************************************************
 * Headers for type : Runner
 *****************************************************************************/


// BEGIN: Code from the c_header annotation Runner

    #include <constants.h>
    #include <calibration.hpp>

// END: Code from the c_header annotation Runner

// Definition of the instance struct:
struct Runner_Instance {

// Instances of different sessions
bool active;
// Variables for the ID of the ports of the instance
uint16_t id_Run;
uint16_t id_StatusSender;
// Variables for the current instance state
int Runner_Running_State;
// Variables for the properties of the instance

};
// generateEventHandlers2
int Runner_handle_empty_event(struct Runner_Instance *_instance);
// Declaration of prototypes outgoing messages :
void Runner_Running_OnEntry(int state, struct Runner_Instance *_instance);
void Runner_handle_Run_baseStationAngles(struct Runner_Instance *_instance, double bh, double bv, double ch, double cv);
// Declaration of callbacks for incoming messages:
void register_Runner_send_Run_coordinates_listener(void (*_listener)(struct Runner_Instance *, double, double, double, double));
void register_external_Runner_send_Run_coordinates_listener(void (*_listener)(struct Runner_Instance *, double, double, double, double));
void register_Runner_send_StatusSender_status_listener(void (*_listener)(struct Runner_Instance *, uint8_t));
void register_external_Runner_send_StatusSender_status_listener(void (*_listener)(struct Runner_Instance *, uint8_t));

// Definition of the states:
#define RUNNER_RUNNING_STATE 0
#define RUNNER_RUNNING_IDLE_STATE 1



#endif