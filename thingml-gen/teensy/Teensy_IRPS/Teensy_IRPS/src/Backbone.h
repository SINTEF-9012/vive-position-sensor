#ifndef Backbone
#define Backbone
#include "WProgram.h"
/*****************************************************************************
 * Headers for type : Backbone
 *****************************************************************************/


// BEGIN: Code from the c_header annotation Backbone

        #include <Timer.h>
        #include <constants.h>
    
// END: Code from the c_header annotation Backbone

// Definition of the instance struct:
struct Backbone_Instance {

// Instances of different sessions
bool active;
// Variables for the ID of the ports of the instance
uint16_t id_Output;
uint16_t id_AngleReceiver;
uint16_t id_Run;
uint16_t id_CalibrationStorer;
uint16_t id_validator;
uint16_t id_calibrator;
uint16_t id_printer;
uint16_t id_serialRead;
uint16_t id_pixel;
uint16_t id_presser;
uint16_t id_StatusHandler;
uint16_t id_StateHandler;
uint16_t id_transitions;
// Variables for the current instance state
int Backbone_Main_State;
// Variables for the properties of the instance

};
// generateEventHandlers2
int Backbone_handle_empty_event(struct Backbone_Instance *_instance);
// Declaration of prototypes outgoing messages :
void Backbone_Main_OnEntry(int state, struct Backbone_Instance *_instance);
void Backbone_handle_AngleReceiver_allAngles(struct Backbone_Instance *_instance, double bh, double bv, double ch, double cv);
void Backbone_handle_StateHandler_currentState(struct Backbone_Instance *_instance, uint8_t id);
void Backbone_handle_Run_coordinates(struct Backbone_Instance *_instance, double x, double y, double z, double separation);
void Backbone_handle_presser_double_click(struct Backbone_Instance *_instance);
void Backbone_handle_presser_click(struct Backbone_Instance *_instance);
void Backbone_handle_presser_long_press(struct Backbone_Instance *_instance);
void Backbone_handle_calibrator_endcalibrate(struct Backbone_Instance *_instance);
void Backbone_handle_calibrator_errcalibrate(struct Backbone_Instance *_instance);
void Backbone_handle_CalibrationStorer_errorload(struct Backbone_Instance *_instance);
void Backbone_handle_CalibrationStorer_endload(struct Backbone_Instance *_instance);
void Backbone_handle_StatusHandler_status(struct Backbone_Instance *_instance, uint8_t id);
void Backbone_handle_validator_errvalidate(struct Backbone_Instance *_instance);
void Backbone_handle_validator_endvalidate(struct Backbone_Instance *_instance);
// Declaration of callbacks for incoming messages:
void register_Backbone_send_Output_positionCoordinates_listener(void (*_listener)(struct Backbone_Instance *, double, double, double));
void register_external_Backbone_send_Output_positionCoordinates_listener(void (*_listener)(struct Backbone_Instance *, double, double, double));
void register_Backbone_send_Run_baseStationAngles_listener(void (*_listener)(struct Backbone_Instance *, double, double, double, double));
void register_external_Backbone_send_Run_baseStationAngles_listener(void (*_listener)(struct Backbone_Instance *, double, double, double, double));
void register_Backbone_send_CalibrationStorer_load_listener(void (*_listener)(struct Backbone_Instance *));
void register_external_Backbone_send_CalibrationStorer_load_listener(void (*_listener)(struct Backbone_Instance *));
void register_Backbone_send_CalibrationStorer_save_listener(void (*_listener)(struct Backbone_Instance *));
void register_external_Backbone_send_CalibrationStorer_save_listener(void (*_listener)(struct Backbone_Instance *));
void register_Backbone_send_validator_validate_listener(void (*_listener)(struct Backbone_Instance *));
void register_external_Backbone_send_validator_validate_listener(void (*_listener)(struct Backbone_Instance *));
void register_Backbone_send_calibrator_calibrate_listener(void (*_listener)(struct Backbone_Instance *));
void register_external_Backbone_send_calibrator_calibrate_listener(void (*_listener)(struct Backbone_Instance *));
void register_Backbone_send_calibrator_entrypoint_listener(void (*_listener)(struct Backbone_Instance *));
void register_external_Backbone_send_calibrator_entrypoint_listener(void (*_listener)(struct Backbone_Instance *));
void register_Backbone_send_calibrator_receiveAngles_listener(void (*_listener)(struct Backbone_Instance *, double, double, double, double));
void register_external_Backbone_send_calibrator_receiveAngles_listener(void (*_listener)(struct Backbone_Instance *, double, double, double, double));
void register_Backbone_send_calibrator_receivecalibration_listener(void (*_listener)(struct Backbone_Instance *, double, double, double, double, double, double, double, double, double, double, double, double));
void register_external_Backbone_send_calibrator_receivecalibration_listener(void (*_listener)(struct Backbone_Instance *, double, double, double, double, double, double, double, double, double, double, double, double));
void register_Backbone_send_printer_printStatus_listener(void (*_listener)(struct Backbone_Instance *, uint8_t, uint8_t));
void register_external_Backbone_send_printer_printStatus_listener(void (*_listener)(struct Backbone_Instance *, uint8_t, uint8_t));
void register_Backbone_send_printer_printOperationState_listener(void (*_listener)(struct Backbone_Instance *, uint8_t, uint8_t));
void register_external_Backbone_send_printer_printOperationState_listener(void (*_listener)(struct Backbone_Instance *, uint8_t, uint8_t));
void register_Backbone_send_printer_printPoint_listener(void (*_listener)(struct Backbone_Instance *, double, double, double, double, uint8_t));
void register_external_Backbone_send_printer_printPoint_listener(void (*_listener)(struct Backbone_Instance *, double, double, double, double, uint8_t));
void register_Backbone_send_serialRead_waitcalibration_listener(void (*_listener)(struct Backbone_Instance *));
void register_external_Backbone_send_serialRead_waitcalibration_listener(void (*_listener)(struct Backbone_Instance *));
void register_Backbone_send_pixel_stateID_listener(void (*_listener)(struct Backbone_Instance *, uint8_t));
void register_external_Backbone_send_pixel_stateID_listener(void (*_listener)(struct Backbone_Instance *, uint8_t));
void register_Backbone_send_pixel_statusID_listener(void (*_listener)(struct Backbone_Instance *, uint8_t));
void register_external_Backbone_send_pixel_statusID_listener(void (*_listener)(struct Backbone_Instance *, uint8_t));
void register_Backbone_send_StateHandler_currentState_listener(void (*_listener)(struct Backbone_Instance *, uint8_t));
void register_external_Backbone_send_StateHandler_currentState_listener(void (*_listener)(struct Backbone_Instance *, uint8_t));
void register_Backbone_send_transitions_toIdle_listener(void (*_listener)(struct Backbone_Instance *));
void register_external_Backbone_send_transitions_toIdle_listener(void (*_listener)(struct Backbone_Instance *));

// Definition of the states:
#define BACKBONE_MAIN_STATE 0
#define BACKBONE_MAIN_LOAD_CALIBRATION_STATE 1
#define BACKBONE_MAIN_CALIBRATION_STATE 2
#define BACKBONE_MAIN_VALIDATE_CALIBRATION_STATE 3
#define BACKBONE_MAIN_RUNNER_STATE 4



#endif