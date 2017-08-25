#ifndef Storer
#define Storer
#include "WProgram.h"
/*****************************************************************************
 * Headers for type : Storer
 *****************************************************************************/


// BEGIN: Code from the c_header annotation Storer

    #include <constants.h>
    
#include <inttypes.h>
#include <avr/eeprom.h>
#include <avr/io.h>

// END: Code from the c_header annotation Storer

// Definition of the instance struct:
struct Storer_Instance {

// Instances of different sessions
bool active;
// Variables for the ID of the ports of the instance
uint16_t id_reader;
uint16_t id_writer;
// Variables for the current instance state
int Storer_EESave_State;
// Variables for the properties of the instance

};
// generateEventHandlers2
int Storer_handle_empty_event(struct Storer_Instance *_instance);
// Declaration of prototypes outgoing messages :
void Storer_EESave_OnEntry(int state, struct Storer_Instance *_instance);
void Storer_handle_reader_readByte(struct Storer_Instance *_instance, uint8_t id);
void Storer_handle_reader_readConfig(struct Storer_Instance *_instance);
void Storer_handle_writer_writeByte(struct Storer_Instance *_instance, uint8_t id, uint8_t val);
void Storer_handle_writer_writeConfig(struct Storer_Instance *_instance, double bx, double by, double bz, double brx, double bry, double brz, double cx, double cy, double cz, double crx, double cry, double crz);
// Declaration of callbacks for incoming messages:
void register_Storer_send_reader_byteRead_listener(void (*_listener)(struct Storer_Instance *, uint8_t));
void register_external_Storer_send_reader_byteRead_listener(void (*_listener)(struct Storer_Instance *, uint8_t));
void register_Storer_send_reader_configRead_listener(void (*_listener)(struct Storer_Instance *, double, double, double, double, double, double, double, double, double, double, double, double));
void register_external_Storer_send_reader_configRead_listener(void (*_listener)(struct Storer_Instance *, double, double, double, double, double, double, double, double, double, double, double, double));
void register_Storer_send_writer_byteWritten_listener(void (*_listener)(struct Storer_Instance *));
void register_external_Storer_send_writer_byteWritten_listener(void (*_listener)(struct Storer_Instance *));
void register_Storer_send_writer_configWritten_listener(void (*_listener)(struct Storer_Instance *));
void register_external_Storer_send_writer_configWritten_listener(void (*_listener)(struct Storer_Instance *));

// Definition of the states:
#define STORER_EESAVE_STATE 0
#define STORER_EESAVE_IDLE_STATE 1



#endif