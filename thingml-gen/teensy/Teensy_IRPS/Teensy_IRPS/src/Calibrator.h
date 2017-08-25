#ifndef Calibrator
#define Calibrator
#include "WProgram.h"
/*****************************************************************************
 * Headers for type : Calibrator
 *****************************************************************************/


// BEGIN: Code from the c_header annotation Calibrator

    #include <Timer.h>
    #include <constants.h>
    #include <calibration.hpp>

// END: Code from the c_header annotation Calibrator

// Definition of the instance struct:
struct Calibrator_Instance {

// Instances of different sessions
bool active;
// Variables for the ID of the ports of the instance
uint16_t id_calibrator;
uint16_t id_StatusSender;
uint16_t id_avt;
// Variables for the current instance state
int Calibrator_Calibrator_State;
// Variables for the properties of the instance

};
// generateEventHandlers2
int Calibrator_handle_empty_event(struct Calibrator_Instance *_instance);
// Declaration of prototypes outgoing messages :
void Calibrator_Calibrator_OnEntry(int state, struct Calibrator_Instance *_instance);
void Calibrator_handle_avt_calibrationComplete(struct Calibrator_Instance *_instance);
void Calibrator_handle_avt_calibrationFailed(struct Calibrator_Instance *_instance);
void Calibrator_handle_avt_calibrating(struct Calibrator_Instance *_instance);
void Calibrator_handle_calibrator_entrypoint(struct Calibrator_Instance *_instance);
void Calibrator_handle_calibrator_receiveAngles(struct Calibrator_Instance *_instance, double bh, double bv, double ch, double cv);
void Calibrator_handle_calibrator_calibrate(struct Calibrator_Instance *_instance);
// Declaration of callbacks for incoming messages:
void register_Calibrator_send_calibrator_endcalibrate_listener(void (*_listener)(struct Calibrator_Instance *));
void register_external_Calibrator_send_calibrator_endcalibrate_listener(void (*_listener)(struct Calibrator_Instance *));
void register_Calibrator_send_calibrator_errcalibrate_listener(void (*_listener)(struct Calibrator_Instance *));
void register_external_Calibrator_send_calibrator_errcalibrate_listener(void (*_listener)(struct Calibrator_Instance *));
void register_Calibrator_send_calibrator_calibrationfromserial_listener(void (*_listener)(struct Calibrator_Instance *));
void register_external_Calibrator_send_calibrator_calibrationfromserial_listener(void (*_listener)(struct Calibrator_Instance *));
void register_Calibrator_send_StatusSender_status_listener(void (*_listener)(struct Calibrator_Instance *, uint8_t));
void register_external_Calibrator_send_StatusSender_status_listener(void (*_listener)(struct Calibrator_Instance *, uint8_t));
void register_Calibrator_send_avt_calibrating_listener(void (*_listener)(struct Calibrator_Instance *));
void register_external_Calibrator_send_avt_calibrating_listener(void (*_listener)(struct Calibrator_Instance *));
void register_Calibrator_send_avt_calibrationComplete_listener(void (*_listener)(struct Calibrator_Instance *));
void register_external_Calibrator_send_avt_calibrationComplete_listener(void (*_listener)(struct Calibrator_Instance *));
void register_Calibrator_send_avt_calibrationFailed_listener(void (*_listener)(struct Calibrator_Instance *));
void register_external_Calibrator_send_avt_calibrationFailed_listener(void (*_listener)(struct Calibrator_Instance *));

// Definition of the states:
#define CALIBRATOR_CALIBRATOR_STATE 0
#define CALIBRATOR_CALIBRATOR_IDLE_STATE 1
#define CALIBRATOR_CALIBRATOR_CALIBRATE_STATE 2
#define CALIBRATOR_CALIBRATOR_POINTCOLLECT_STATE 3



#endif