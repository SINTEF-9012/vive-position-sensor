#ifndef CalibrationStorer
#define CalibrationStorer
#include "WProgram.h"
/*****************************************************************************
 * Headers for type : CalibrationStorer
 *****************************************************************************/


// BEGIN: Code from the c_header annotation CalibrationStorer

    #import <calibration.hpp>

// END: Code from the c_header annotation CalibrationStorer

// Definition of the instance struct:
struct CalibrationStorer_Instance {

// Instances of different sessions
bool active;
// Variables for the ID of the ports of the instance
uint16_t id_storeReader;
uint16_t id_storeWriter;
uint16_t id_storer;
uint16_t id_progress;
// Variables for the current instance state
int CalibrationStorer_Loader_State;
// Variables for the properties of the instance

};
// generateEventHandlers2
int CalibrationStorer_handle_empty_event(struct CalibrationStorer_Instance *_instance);
// Declaration of prototypes outgoing messages :
void CalibrationStorer_Loader_OnEntry(int state, struct CalibrationStorer_Instance *_instance);
void CalibrationStorer_handle_storer_load(struct CalibrationStorer_Instance *_instance);
void CalibrationStorer_handle_storer_save(struct CalibrationStorer_Instance *_instance);
void CalibrationStorer_handle_progress_storerToIdle(struct CalibrationStorer_Instance *_instance);
void CalibrationStorer_handle_storeWriter_configWritten(struct CalibrationStorer_Instance *_instance);
void CalibrationStorer_handle_storeReader_configRead(struct CalibrationStorer_Instance *_instance, double bx, double by, double bz, double brx, double bry, double brz, double cx, double cy, double cz, double crx, double cry, double crz);
void CalibrationStorer_handle_storeReader_byteRead(struct CalibrationStorer_Instance *_instance, uint8_t val);
// Declaration of callbacks for incoming messages:
void register_CalibrationStorer_send_storeReader_readByte_listener(void (*_listener)(struct CalibrationStorer_Instance *, uint8_t));
void register_external_CalibrationStorer_send_storeReader_readByte_listener(void (*_listener)(struct CalibrationStorer_Instance *, uint8_t));
void register_CalibrationStorer_send_storeReader_readConfig_listener(void (*_listener)(struct CalibrationStorer_Instance *));
void register_external_CalibrationStorer_send_storeReader_readConfig_listener(void (*_listener)(struct CalibrationStorer_Instance *));
void register_CalibrationStorer_send_storeWriter_writeByte_listener(void (*_listener)(struct CalibrationStorer_Instance *, uint8_t, uint8_t));
void register_external_CalibrationStorer_send_storeWriter_writeByte_listener(void (*_listener)(struct CalibrationStorer_Instance *, uint8_t, uint8_t));
void register_CalibrationStorer_send_storeWriter_writeConfig_listener(void (*_listener)(struct CalibrationStorer_Instance *, double, double, double, double, double, double, double, double, double, double, double, double));
void register_external_CalibrationStorer_send_storeWriter_writeConfig_listener(void (*_listener)(struct CalibrationStorer_Instance *, double, double, double, double, double, double, double, double, double, double, double, double));
void register_CalibrationStorer_send_storer_endload_listener(void (*_listener)(struct CalibrationStorer_Instance *));
void register_external_CalibrationStorer_send_storer_endload_listener(void (*_listener)(struct CalibrationStorer_Instance *));
void register_CalibrationStorer_send_storer_errorload_listener(void (*_listener)(struct CalibrationStorer_Instance *));
void register_external_CalibrationStorer_send_storer_errorload_listener(void (*_listener)(struct CalibrationStorer_Instance *));
void register_CalibrationStorer_send_progress_storerToIdle_listener(void (*_listener)(struct CalibrationStorer_Instance *));
void register_external_CalibrationStorer_send_progress_storerToIdle_listener(void (*_listener)(struct CalibrationStorer_Instance *));

// Definition of the states:
#define CALIBRATIONSTORER_LOADER_STATE 0
#define CALIBRATIONSTORER_LOADER_IDLE_STATE 1
#define CALIBRATIONSTORER_LOADER_LOAD_STATE 2
#define CALIBRATIONSTORER_LOADER_SAVE_STATE 3



#endif