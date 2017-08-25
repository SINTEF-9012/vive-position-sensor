#include "Storer.h"
/*****************************************************************************
 * Implementation for type : Storer
 *****************************************************************************/

// Declaration of prototypes:
//Prototypes: State Machine
void Storer_EESave_OnExit(int state, struct Storer_Instance *_instance);
//Prototypes: Message Sending
void Storer_send_reader_byteRead(struct Storer_Instance *_instance, uint8_t val);
void Storer_send_reader_configRead(struct Storer_Instance *_instance, double bx, double by, double bz, double brx, double bry, double brz, double cx, double cy, double cz, double crx, double cry, double crz);
void Storer_send_writer_byteWritten(struct Storer_Instance *_instance);
void Storer_send_writer_configWritten(struct Storer_Instance *_instance);
//Prototypes: Function
// Declaration of functions:

// Sessions functionss:


// On Entry Actions:
void Storer_EESave_OnEntry(int state, struct Storer_Instance *_instance) {
switch(state) {
case STORER_EESAVE_STATE:{
_instance->Storer_EESave_State = STORER_EESAVE_IDLE_STATE;
Storer_EESave_OnEntry(_instance->Storer_EESave_State, _instance);
break;
}
case STORER_EESAVE_IDLE_STATE:{
break;
}
default: break;
}
}

// On Exit Actions:
void Storer_EESave_OnExit(int state, struct Storer_Instance *_instance) {
switch(state) {
case STORER_EESAVE_STATE:{
Storer_EESave_OnExit(_instance->Storer_EESave_State, _instance);
break;}
case STORER_EESAVE_IDLE_STATE:{
break;}
default: break;
}
}

// Event Handlers for incoming messages:
void Storer_handle_reader_readByte(struct Storer_Instance *_instance, uint8_t id) {
if(!(_instance->active)) return;
//Region EESave
uint8_t Storer_EESave_State_event_consumed = 0;
if (_instance->Storer_EESave_State == STORER_EESAVE_IDLE_STATE) {
if (Storer_EESave_State_event_consumed == 0 && 1) {
Storer_send_reader_byteRead(_instance, eeprom_read_byte((uint8_t*) id));
Storer_EESave_State_event_consumed = 1;
}
}
//End Region EESave
//End dsregion EESave
//Session list: 
}
void Storer_handle_reader_readConfig(struct Storer_Instance *_instance) {
if(!(_instance->active)) return;
//Region EESave
uint8_t Storer_EESave_State_event_consumed = 0;
if (_instance->Storer_EESave_State == STORER_EESAVE_IDLE_STATE) {
if (Storer_EESave_State_event_consumed == 0 && 1) {

    			udouble ud; 
    			for (int i = 0; i < 96; i++) {
    				ud.b[i] = eeprom_read_byte((uint8_t*) i+1);
    			}
Storer_send_reader_configRead(_instance, ud.d[0], ud.d[1], ud.d[2], ud.d[3], ud.d[4], ud.d[5], ud.d[6], ud.d[7], ud.d[8], ud.d[9], ud.d[10], ud.d[11]);
Storer_EESave_State_event_consumed = 1;
}
}
//End Region EESave
//End dsregion EESave
//Session list: 
}
void Storer_handle_writer_writeByte(struct Storer_Instance *_instance, uint8_t id, uint8_t val) {
if(!(_instance->active)) return;
//Region EESave
uint8_t Storer_EESave_State_event_consumed = 0;
if (_instance->Storer_EESave_State == STORER_EESAVE_IDLE_STATE) {
if (Storer_EESave_State_event_consumed == 0 && 1) {

        		if(val != eeprom_read_byte((uint8_t*) id))	eeprom_write_byte((uint8_t*) id,val);
Storer_send_writer_byteWritten(_instance);
Storer_EESave_State_event_consumed = 1;
}
}
//End Region EESave
//End dsregion EESave
//Session list: 
}
void Storer_handle_writer_writeConfig(struct Storer_Instance *_instance, double bx, double by, double bz, double brx, double bry, double brz, double cx, double cy, double cz, double crx, double cry, double crz) {
if(!(_instance->active)) return;
//Region EESave
uint8_t Storer_EESave_State_event_consumed = 0;
if (_instance->Storer_EESave_State == STORER_EESAVE_IDLE_STATE) {
if (Storer_EESave_State_event_consumed == 0 && 1) {

			
			    udouble data;
			    data.d[0] = bx;
			    data.d[1] = by;
			    data.d[2] = bz;
			    data.d[3] = brx;
			    data.d[4] = bry;
			    data.d[5] = brz;
			    data.d[6] = cx;
			    data.d[7] = cy;
			    data.d[8] = cz;
			    data.d[9] = crx;
			    data.d[10] = cry;
			    data.d[11] = crz;
			    			    
			    for (int i = 0; i < 96; i++) {
                    if(data.b[i] != eeprom_read_byte((uint8_t*) i+1))	eeprom_write_byte((uint8_t*) i+1, data.b[i]);
                }
Storer_send_writer_configWritten(_instance);
Storer_EESave_State_event_consumed = 1;
}
}
//End Region EESave
//End dsregion EESave
//Session list: 
}

// Observers for outgoing messages:
void (*external_Storer_send_reader_byteRead_listener)(struct Storer_Instance *, uint8_t)= 0x0;
void (*Storer_send_reader_byteRead_listener)(struct Storer_Instance *, uint8_t)= 0x0;
void register_external_Storer_send_reader_byteRead_listener(void (*_listener)(struct Storer_Instance *, uint8_t)){
external_Storer_send_reader_byteRead_listener = _listener;
}
void register_Storer_send_reader_byteRead_listener(void (*_listener)(struct Storer_Instance *, uint8_t)){
Storer_send_reader_byteRead_listener = _listener;
}
void Storer_send_reader_byteRead(struct Storer_Instance *_instance, uint8_t val){
if (Storer_send_reader_byteRead_listener != 0x0) Storer_send_reader_byteRead_listener(_instance, val);
if (external_Storer_send_reader_byteRead_listener != 0x0) external_Storer_send_reader_byteRead_listener(_instance, val);
;
}
void (*external_Storer_send_reader_configRead_listener)(struct Storer_Instance *, double, double, double, double, double, double, double, double, double, double, double, double)= 0x0;
void (*Storer_send_reader_configRead_listener)(struct Storer_Instance *, double, double, double, double, double, double, double, double, double, double, double, double)= 0x0;
void register_external_Storer_send_reader_configRead_listener(void (*_listener)(struct Storer_Instance *, double, double, double, double, double, double, double, double, double, double, double, double)){
external_Storer_send_reader_configRead_listener = _listener;
}
void register_Storer_send_reader_configRead_listener(void (*_listener)(struct Storer_Instance *, double, double, double, double, double, double, double, double, double, double, double, double)){
Storer_send_reader_configRead_listener = _listener;
}
void Storer_send_reader_configRead(struct Storer_Instance *_instance, double bx, double by, double bz, double brx, double bry, double brz, double cx, double cy, double cz, double crx, double cry, double crz){
if (Storer_send_reader_configRead_listener != 0x0) Storer_send_reader_configRead_listener(_instance, bx, by, bz, brx, bry, brz, cx, cy, cz, crx, cry, crz);
if (external_Storer_send_reader_configRead_listener != 0x0) external_Storer_send_reader_configRead_listener(_instance, bx, by, bz, brx, bry, brz, cx, cy, cz, crx, cry, crz);
;
}
void (*external_Storer_send_writer_byteWritten_listener)(struct Storer_Instance *)= 0x0;
void (*Storer_send_writer_byteWritten_listener)(struct Storer_Instance *)= 0x0;
void register_external_Storer_send_writer_byteWritten_listener(void (*_listener)(struct Storer_Instance *)){
external_Storer_send_writer_byteWritten_listener = _listener;
}
void register_Storer_send_writer_byteWritten_listener(void (*_listener)(struct Storer_Instance *)){
Storer_send_writer_byteWritten_listener = _listener;
}
void Storer_send_writer_byteWritten(struct Storer_Instance *_instance){
if (Storer_send_writer_byteWritten_listener != 0x0) Storer_send_writer_byteWritten_listener(_instance);
if (external_Storer_send_writer_byteWritten_listener != 0x0) external_Storer_send_writer_byteWritten_listener(_instance);
;
}
void (*external_Storer_send_writer_configWritten_listener)(struct Storer_Instance *)= 0x0;
void (*Storer_send_writer_configWritten_listener)(struct Storer_Instance *)= 0x0;
void register_external_Storer_send_writer_configWritten_listener(void (*_listener)(struct Storer_Instance *)){
external_Storer_send_writer_configWritten_listener = _listener;
}
void register_Storer_send_writer_configWritten_listener(void (*_listener)(struct Storer_Instance *)){
Storer_send_writer_configWritten_listener = _listener;
}
void Storer_send_writer_configWritten(struct Storer_Instance *_instance){
if (Storer_send_writer_configWritten_listener != 0x0) Storer_send_writer_configWritten_listener(_instance);
if (external_Storer_send_writer_configWritten_listener != 0x0) external_Storer_send_writer_configWritten_listener(_instance);
;
}



