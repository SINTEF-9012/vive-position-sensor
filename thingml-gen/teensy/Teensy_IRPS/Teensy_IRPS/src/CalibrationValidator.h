#ifndef CalibrationValidator
#define CalibrationValidator
#include "WProgram.h"
/*****************************************************************************
 * Headers for type : CalibrationValidator
 *****************************************************************************/

// Definition of the instance struct:
struct CalibrationValidator_Instance {

// Instances of different sessions
bool active;
// Variables for the ID of the ports of the instance
uint16_t id_validator;
uint16_t id_avt;
// Variables for the current instance state
int CalibrationValidator_Validator_State;
// Variables for the properties of the instance

};
// generateEventHandlers2
int CalibrationValidator_handle_empty_event(struct CalibrationValidator_Instance *_instance);
// Declaration of prototypes outgoing messages :
void CalibrationValidator_Validator_OnEntry(int state, struct CalibrationValidator_Instance *_instance);
void CalibrationValidator_handle_validator_validate(struct CalibrationValidator_Instance *_instance);
// Declaration of callbacks for incoming messages:
void register_CalibrationValidator_send_validator_endvalidate_listener(void (*_listener)(struct CalibrationValidator_Instance *));
void register_external_CalibrationValidator_send_validator_endvalidate_listener(void (*_listener)(struct CalibrationValidator_Instance *));
void register_CalibrationValidator_send_validator_errvalidate_listener(void (*_listener)(struct CalibrationValidator_Instance *));
void register_external_CalibrationValidator_send_validator_errvalidate_listener(void (*_listener)(struct CalibrationValidator_Instance *));
void register_CalibrationValidator_send_avt_validating_listener(void (*_listener)(struct CalibrationValidator_Instance *));
void register_external_CalibrationValidator_send_avt_validating_listener(void (*_listener)(struct CalibrationValidator_Instance *));

// Definition of the states:
#define CALIBRATIONVALIDATOR_VALIDATOR_STATE 0
#define CALIBRATIONVALIDATOR_VALIDATOR_IDLE_STATE 1



#endif