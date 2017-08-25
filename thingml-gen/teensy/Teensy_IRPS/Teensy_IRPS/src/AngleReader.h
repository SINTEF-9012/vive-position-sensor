#ifndef AngleReader
#define AngleReader
#include "WProgram.h"
/*****************************************************************************
 * Headers for type : AngleReader
 *****************************************************************************/


// BEGIN: Code from the c_header annotation AngleReader

        #include <constants.h>
        
        enum SignalType {
            // b - master, c - slave
            // h - horisontal, v - vertical
            bh = 0, bv = 1, ch = 2, cv = 3, error = 4
        };
    
// END: Code from the c_header annotation AngleReader

// Definition of the instance struct:
struct AngleReader_Instance {

// Instances of different sessions
bool active;
// Variables for the ID of the ports of the instance
uint16_t id_PackageReceiver;
uint16_t id_AngleSender;
uint16_t id_OverflowNotifier;
uint16_t id_StatusSender;
uint16_t id_Transitions;
// Variables for the current instance state
int AngleReader_SingalDetectionStrategy_State;
// Variables for the properties of the instance

};
// generateEventHandlers2
int AngleReader_handle_empty_event(struct AngleReader_Instance *_instance);
// Declaration of prototypes outgoing messages :
void AngleReader_SingalDetectionStrategy_OnEntry(int state, struct AngleReader_Instance *_instance);
void AngleReader_handle_OverflowNotifier_timerOverflow(struct AngleReader_Instance *_instance);
void AngleReader_handle_PackageReceiver_packageDetectedEvent(struct AngleReader_Instance *_instance, uint32_t startTimeL1, uint32_t startTimeL2, uint32_t durationL1, uint32_t durationL2, uint32_t signal);
void AngleReader_handle_Transitions_startTimeCalibrated(struct AngleReader_Instance *_instance);
void AngleReader_handle_Transitions_recalibrate(struct AngleReader_Instance *_instance);
// Declaration of callbacks for incoming messages:
void register_AngleReader_send_AngleSender_allAngles_listener(void (*_listener)(struct AngleReader_Instance *, double, double, double, double));
void register_external_AngleReader_send_AngleSender_allAngles_listener(void (*_listener)(struct AngleReader_Instance *, double, double, double, double));
void register_AngleReader_send_StatusSender_status_listener(void (*_listener)(struct AngleReader_Instance *, uint8_t));
void register_external_AngleReader_send_StatusSender_status_listener(void (*_listener)(struct AngleReader_Instance *, uint8_t));
void register_AngleReader_send_Transitions_startTimeCalibrated_listener(void (*_listener)(struct AngleReader_Instance *));
void register_external_AngleReader_send_Transitions_startTimeCalibrated_listener(void (*_listener)(struct AngleReader_Instance *));
void register_AngleReader_send_Transitions_recalibrate_listener(void (*_listener)(struct AngleReader_Instance *));
void register_external_AngleReader_send_Transitions_recalibrate_listener(void (*_listener)(struct AngleReader_Instance *));

// Definition of the states:
#define ANGLEREADER_SINGALDETECTIONSTRATEGY_STATE 0
#define ANGLEREADER_SINGALDETECTIONSTRATEGY_PULSEWIDTHS_STATE 1
#define ANGLEREADER_SINGALDETECTIONSTRATEGY_ARRIVALTIME_STATE 2



#endif