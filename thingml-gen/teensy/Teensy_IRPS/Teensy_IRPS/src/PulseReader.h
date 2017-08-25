#ifndef PulseReader
#define PulseReader
#include "WProgram.h"
/*****************************************************************************
 * Headers for type : PulseReader
 *****************************************************************************/


// BEGIN: Code from the c_header annotation PulseReader

        #include <constants.h>
    
// END: Code from the c_header annotation PulseReader

// Definition of the instance struct:
struct PulseReader_Instance {

// Instances of different sessions
bool active;
// Variables for the ID of the ports of the instance
uint16_t id_PulseSender;
uint16_t id_OverflowNotifier;
uint16_t id_Transitions;
// Variables for the current instance state
int PulseReader_PulseRead_State;
// Variables for the properties of the instance

};
// generateEventHandlers2
int PulseReader_handle_empty_event(struct PulseReader_Instance *_instance);
// Declaration of prototypes outgoing messages :
void PulseReader_PulseRead_OnEntry(int state, struct PulseReader_Instance *_instance);
void PulseReader_handle_Transitions_pulseDetected(struct PulseReader_Instance *_instance, uint32_t start, uint32_t duration);
// Declaration of callbacks for incoming messages:
void register_PulseReader_send_PulseSender_pulseDetectedEvent_listener(void (*_listener)(struct PulseReader_Instance *, uint32_t, uint32_t));
void register_external_PulseReader_send_PulseSender_pulseDetectedEvent_listener(void (*_listener)(struct PulseReader_Instance *, uint32_t, uint32_t));
void register_PulseReader_send_OverflowNotifier_timerOverflow_listener(void (*_listener)(struct PulseReader_Instance *));
void register_external_PulseReader_send_OverflowNotifier_timerOverflow_listener(void (*_listener)(struct PulseReader_Instance *));
void register_PulseReader_send_Transitions_pulseDetected_listener(void (*_listener)(struct PulseReader_Instance *, uint32_t, uint32_t));
void register_external_PulseReader_send_Transitions_pulseDetected_listener(void (*_listener)(struct PulseReader_Instance *, uint32_t, uint32_t));

// Definition of the states:
#define PULSEREADER_PULSEREAD_STATE 0
#define PULSEREADER_PULSEREAD_IDLE_STATE 1



#endif