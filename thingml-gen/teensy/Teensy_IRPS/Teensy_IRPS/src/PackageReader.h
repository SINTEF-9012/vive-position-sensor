#ifndef PackageReader
#define PackageReader
#include "WProgram.h"
/*****************************************************************************
 * Headers for type : PackageReader
 *****************************************************************************/


// BEGIN: Code from the c_header annotation PackageReader

        #include <constants.h>
    
// END: Code from the c_header annotation PackageReader

// Definition of the instance struct:
struct PackageReader_Instance {

// Instances of different sessions
bool active;
// Variables for the ID of the ports of the instance
uint16_t id_PulseReceiver;
uint16_t id_PackageSender;
uint16_t id_StatusSender;
// Variables for the current instance state
int PackageReader_PackageRead_State;
// Variables for the properties of the instance

};
// generateEventHandlers2
int PackageReader_handle_empty_event(struct PackageReader_Instance *_instance);
// Declaration of prototypes outgoing messages :
void PackageReader_PackageRead_OnEntry(int state, struct PackageReader_Instance *_instance);
void PackageReader_handle_PulseReceiver_pulseDetectedEvent(struct PackageReader_Instance *_instance, uint32_t start, uint32_t duration);
// Declaration of callbacks for incoming messages:
void register_PackageReader_send_PackageSender_packageDetectedEvent_listener(void (*_listener)(struct PackageReader_Instance *, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t));
void register_external_PackageReader_send_PackageSender_packageDetectedEvent_listener(void (*_listener)(struct PackageReader_Instance *, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t));
void register_PackageReader_send_StatusSender_status_listener(void (*_listener)(struct PackageReader_Instance *, uint8_t));
void register_external_PackageReader_send_StatusSender_status_listener(void (*_listener)(struct PackageReader_Instance *, uint8_t));

// Definition of the states:
#define PACKAGEREADER_PACKAGEREAD_STATE 0
#define PACKAGEREADER_PACKAGEREAD_IDLE_STATE 1



#endif