#include "SoftButton.h"
#include "Button.h"
#include "Runner.h"
#include "SerialIn.h"
#include "CalibrationStorer.h"
#include "Calibrator.h"
#include "AngleReader.h"
#include "SerialOut.h"
#include "PulseReader.h"
#include "thingml_typedefs.h"
#include "PackageReader.h"
#include "runtime.h"
#include "Backbone.h"
#include "CalibrationValidator.h"
#include "Blinker.h"
#include "Storer.h"



/*****************************************************************************
 * Definitions for configuration : Teensy_IRPS
 *****************************************************************************/

//Declaration of instance variables
//Instance angleReader
// Variables for the properties of the instance
struct AngleReader_Instance angleReader_var;
// Variables for the sessions of the instance
//Instance button
// Variables for the properties of the instance
struct Button_Instance button_var;
// Variables for the sessions of the instance
//Instance serial
// Variables for the properties of the instance
struct SerialOut_Instance serial_var;
// Variables for the sessions of the instance
//Instance packageReader
// Variables for the properties of the instance
struct PackageReader_Instance packageReader_var;
// Variables for the sessions of the instance
//Instance calibrationStorer
// Variables for the properties of the instance
struct CalibrationStorer_Instance calibrationStorer_var;
// Variables for the sessions of the instance
//Instance storer
// Variables for the properties of the instance
struct Storer_Instance storer_var;
// Variables for the sessions of the instance
//Instance runner
// Variables for the properties of the instance
struct Runner_Instance runner_var;
// Variables for the sessions of the instance
//Instance softButton
// Variables for the properties of the instance
struct SoftButton_Instance softButton_var;
// Variables for the sessions of the instance
//Instance calibrator
// Variables for the properties of the instance
struct Calibrator_Instance calibrator_var;
// Variables for the sessions of the instance
//Instance calibrationValidator
// Variables for the properties of the instance
struct CalibrationValidator_Instance calibrationValidator_var;
// Variables for the sessions of the instance
//Instance pulseReader
// Variables for the properties of the instance
struct PulseReader_Instance pulseReader_var;
// Variables for the sessions of the instance
//Instance serialIn
// Variables for the properties of the instance
struct SerialIn_Instance serialIn_var;
// Variables for the sessions of the instance
//Instance backbone
// Variables for the properties of the instance
struct Backbone_Instance backbone_var;
// Variables for the sessions of the instance
//Instance blinker
// Variables for the properties of the instance
struct Blinker_Instance blinker_var;
// Variables for the sessions of the instance


// Enqueue of messages AngleReader::AngleSender::allAngles
void enqueue_AngleReader_send_AngleSender_allAngles(struct AngleReader_Instance *_instance, double bh, double bv, double ch, double cv){
if ( fifo_byte_available() > 36 ) {

_fifo_enqueue( (1 >> 8) & 0xFF );
_fifo_enqueue( 1 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_AngleSender >> 8) & 0xFF );
_fifo_enqueue( _instance->id_AngleSender & 0xFF );

// parameter bh
union u_bh_t {
double p;
byte bytebuffer[8];
} u_bh;
u_bh.p = bh;
_fifo_enqueue(u_bh.bytebuffer[7] & 0xFF );
_fifo_enqueue(u_bh.bytebuffer[6] & 0xFF );
_fifo_enqueue(u_bh.bytebuffer[5] & 0xFF );
_fifo_enqueue(u_bh.bytebuffer[4] & 0xFF );
_fifo_enqueue(u_bh.bytebuffer[3] & 0xFF );
_fifo_enqueue(u_bh.bytebuffer[2] & 0xFF );
_fifo_enqueue(u_bh.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_bh.bytebuffer[0] & 0xFF );

// parameter bv
union u_bv_t {
double p;
byte bytebuffer[8];
} u_bv;
u_bv.p = bv;
_fifo_enqueue(u_bv.bytebuffer[7] & 0xFF );
_fifo_enqueue(u_bv.bytebuffer[6] & 0xFF );
_fifo_enqueue(u_bv.bytebuffer[5] & 0xFF );
_fifo_enqueue(u_bv.bytebuffer[4] & 0xFF );
_fifo_enqueue(u_bv.bytebuffer[3] & 0xFF );
_fifo_enqueue(u_bv.bytebuffer[2] & 0xFF );
_fifo_enqueue(u_bv.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_bv.bytebuffer[0] & 0xFF );

// parameter ch
union u_ch_t {
double p;
byte bytebuffer[8];
} u_ch;
u_ch.p = ch;
_fifo_enqueue(u_ch.bytebuffer[7] & 0xFF );
_fifo_enqueue(u_ch.bytebuffer[6] & 0xFF );
_fifo_enqueue(u_ch.bytebuffer[5] & 0xFF );
_fifo_enqueue(u_ch.bytebuffer[4] & 0xFF );
_fifo_enqueue(u_ch.bytebuffer[3] & 0xFF );
_fifo_enqueue(u_ch.bytebuffer[2] & 0xFF );
_fifo_enqueue(u_ch.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_ch.bytebuffer[0] & 0xFF );

// parameter cv
union u_cv_t {
double p;
byte bytebuffer[8];
} u_cv;
u_cv.p = cv;
_fifo_enqueue(u_cv.bytebuffer[7] & 0xFF );
_fifo_enqueue(u_cv.bytebuffer[6] & 0xFF );
_fifo_enqueue(u_cv.bytebuffer[5] & 0xFF );
_fifo_enqueue(u_cv.bytebuffer[4] & 0xFF );
_fifo_enqueue(u_cv.bytebuffer[3] & 0xFF );
_fifo_enqueue(u_cv.bytebuffer[2] & 0xFF );
_fifo_enqueue(u_cv.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_cv.bytebuffer[0] & 0xFF );
}
}
// Enqueue of messages AngleReader::StatusSender::status
void enqueue_AngleReader_send_StatusSender_status(struct AngleReader_Instance *_instance, uint8_t id){
if ( fifo_byte_available() > 5 ) {

_fifo_enqueue( (2 >> 8) & 0xFF );
_fifo_enqueue( 2 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_StatusSender >> 8) & 0xFF );
_fifo_enqueue( _instance->id_StatusSender & 0xFF );

// parameter id
union u_id_t {
uint8_t p;
byte bytebuffer[1];
} u_id;
u_id.p = id;
_fifo_enqueue(u_id.bytebuffer[0] & 0xFF );
}
}
// Enqueue of messages AngleReader::Transitions::startTimeCalibrated
void enqueue_AngleReader_send_Transitions_startTimeCalibrated(struct AngleReader_Instance *_instance){
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (3 >> 8) & 0xFF );
_fifo_enqueue( 3 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_Transitions >> 8) & 0xFF );
_fifo_enqueue( _instance->id_Transitions & 0xFF );
}
}
// Enqueue of messages AngleReader::Transitions::recalibrate
void enqueue_AngleReader_send_Transitions_recalibrate(struct AngleReader_Instance *_instance){
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (4 >> 8) & 0xFF );
_fifo_enqueue( 4 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_Transitions >> 8) & 0xFF );
_fifo_enqueue( _instance->id_Transitions & 0xFF );
}
}
// Enqueue of messages Button::clock::ms25_tic
void enqueue_Button_send_clock_ms25_tic(struct Button_Instance *_instance){
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (5 >> 8) & 0xFF );
_fifo_enqueue( 5 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_clock >> 8) & 0xFF );
_fifo_enqueue( _instance->id_clock & 0xFF );
}
}
// Enqueue of messages Button::evt::press
void enqueue_Button_send_evt_press(struct Button_Instance *_instance){
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (6 >> 8) & 0xFF );
_fifo_enqueue( 6 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_evt >> 8) & 0xFF );
_fifo_enqueue( _instance->id_evt & 0xFF );
}
}
// Enqueue of messages Button::evt::release
void enqueue_Button_send_evt_release(struct Button_Instance *_instance){
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (7 >> 8) & 0xFF );
_fifo_enqueue( 7 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_evt >> 8) & 0xFF );
_fifo_enqueue( _instance->id_evt & 0xFF );
}
}
// Enqueue of messages PackageReader::PackageSender::packageDetectedEvent
void enqueue_PackageReader_send_PackageSender_packageDetectedEvent(struct PackageReader_Instance *_instance, uint32_t startTimeL1, uint32_t startTimeL2, uint32_t durationL1, uint32_t durationL2, uint32_t signal){
if ( fifo_byte_available() > 24 ) {

_fifo_enqueue( (8 >> 8) & 0xFF );
_fifo_enqueue( 8 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_PackageSender >> 8) & 0xFF );
_fifo_enqueue( _instance->id_PackageSender & 0xFF );

// parameter startTimeL1
union u_startTimeL1_t {
uint32_t p;
byte bytebuffer[4];
} u_startTimeL1;
u_startTimeL1.p = startTimeL1;
_fifo_enqueue(u_startTimeL1.bytebuffer[3] & 0xFF );
_fifo_enqueue(u_startTimeL1.bytebuffer[2] & 0xFF );
_fifo_enqueue(u_startTimeL1.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_startTimeL1.bytebuffer[0] & 0xFF );

// parameter startTimeL2
union u_startTimeL2_t {
uint32_t p;
byte bytebuffer[4];
} u_startTimeL2;
u_startTimeL2.p = startTimeL2;
_fifo_enqueue(u_startTimeL2.bytebuffer[3] & 0xFF );
_fifo_enqueue(u_startTimeL2.bytebuffer[2] & 0xFF );
_fifo_enqueue(u_startTimeL2.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_startTimeL2.bytebuffer[0] & 0xFF );

// parameter durationL1
union u_durationL1_t {
uint32_t p;
byte bytebuffer[4];
} u_durationL1;
u_durationL1.p = durationL1;
_fifo_enqueue(u_durationL1.bytebuffer[3] & 0xFF );
_fifo_enqueue(u_durationL1.bytebuffer[2] & 0xFF );
_fifo_enqueue(u_durationL1.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_durationL1.bytebuffer[0] & 0xFF );

// parameter durationL2
union u_durationL2_t {
uint32_t p;
byte bytebuffer[4];
} u_durationL2;
u_durationL2.p = durationL2;
_fifo_enqueue(u_durationL2.bytebuffer[3] & 0xFF );
_fifo_enqueue(u_durationL2.bytebuffer[2] & 0xFF );
_fifo_enqueue(u_durationL2.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_durationL2.bytebuffer[0] & 0xFF );

// parameter signal
union u_signal_t {
uint32_t p;
byte bytebuffer[4];
} u_signal;
u_signal.p = signal;
_fifo_enqueue(u_signal.bytebuffer[3] & 0xFF );
_fifo_enqueue(u_signal.bytebuffer[2] & 0xFF );
_fifo_enqueue(u_signal.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_signal.bytebuffer[0] & 0xFF );
}
}
// Enqueue of messages PackageReader::StatusSender::status
void enqueue_PackageReader_send_StatusSender_status(struct PackageReader_Instance *_instance, uint8_t id){
if ( fifo_byte_available() > 5 ) {

_fifo_enqueue( (2 >> 8) & 0xFF );
_fifo_enqueue( 2 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_StatusSender >> 8) & 0xFF );
_fifo_enqueue( _instance->id_StatusSender & 0xFF );

// parameter id
union u_id_t {
uint8_t p;
byte bytebuffer[1];
} u_id;
u_id.p = id;
_fifo_enqueue(u_id.bytebuffer[0] & 0xFF );
}
}
// Enqueue of messages CalibrationStorer::storeReader::readByte
void enqueue_CalibrationStorer_send_storeReader_readByte(struct CalibrationStorer_Instance *_instance, uint8_t id){
if ( fifo_byte_available() > 5 ) {

_fifo_enqueue( (9 >> 8) & 0xFF );
_fifo_enqueue( 9 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_storeReader >> 8) & 0xFF );
_fifo_enqueue( _instance->id_storeReader & 0xFF );

// parameter id
union u_id_t {
uint8_t p;
byte bytebuffer[1];
} u_id;
u_id.p = id;
_fifo_enqueue(u_id.bytebuffer[0] & 0xFF );
}
}
// Enqueue of messages CalibrationStorer::storeReader::readConfig
void enqueue_CalibrationStorer_send_storeReader_readConfig(struct CalibrationStorer_Instance *_instance){
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (10 >> 8) & 0xFF );
_fifo_enqueue( 10 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_storeReader >> 8) & 0xFF );
_fifo_enqueue( _instance->id_storeReader & 0xFF );
}
}
// Enqueue of messages CalibrationStorer::storeWriter::writeByte
void enqueue_CalibrationStorer_send_storeWriter_writeByte(struct CalibrationStorer_Instance *_instance, uint8_t id, uint8_t val){
if ( fifo_byte_available() > 6 ) {

_fifo_enqueue( (11 >> 8) & 0xFF );
_fifo_enqueue( 11 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_storeWriter >> 8) & 0xFF );
_fifo_enqueue( _instance->id_storeWriter & 0xFF );

// parameter id
union u_id_t {
uint8_t p;
byte bytebuffer[1];
} u_id;
u_id.p = id;
_fifo_enqueue(u_id.bytebuffer[0] & 0xFF );

// parameter val
union u_val_t {
uint8_t p;
byte bytebuffer[1];
} u_val;
u_val.p = val;
_fifo_enqueue(u_val.bytebuffer[0] & 0xFF );
}
}
// Enqueue of messages CalibrationStorer::storeWriter::writeConfig
void enqueue_CalibrationStorer_send_storeWriter_writeConfig(struct CalibrationStorer_Instance *_instance, double bx, double by, double bz, double brx, double bry, double brz, double cx, double cy, double cz, double crx, double cry, double crz){
if ( fifo_byte_available() > 100 ) {

_fifo_enqueue( (12 >> 8) & 0xFF );
_fifo_enqueue( 12 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_storeWriter >> 8) & 0xFF );
_fifo_enqueue( _instance->id_storeWriter & 0xFF );

// parameter bx
union u_bx_t {
double p;
byte bytebuffer[8];
} u_bx;
u_bx.p = bx;
_fifo_enqueue(u_bx.bytebuffer[7] & 0xFF );
_fifo_enqueue(u_bx.bytebuffer[6] & 0xFF );
_fifo_enqueue(u_bx.bytebuffer[5] & 0xFF );
_fifo_enqueue(u_bx.bytebuffer[4] & 0xFF );
_fifo_enqueue(u_bx.bytebuffer[3] & 0xFF );
_fifo_enqueue(u_bx.bytebuffer[2] & 0xFF );
_fifo_enqueue(u_bx.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_bx.bytebuffer[0] & 0xFF );

// parameter by
union u_by_t {
double p;
byte bytebuffer[8];
} u_by;
u_by.p = by;
_fifo_enqueue(u_by.bytebuffer[7] & 0xFF );
_fifo_enqueue(u_by.bytebuffer[6] & 0xFF );
_fifo_enqueue(u_by.bytebuffer[5] & 0xFF );
_fifo_enqueue(u_by.bytebuffer[4] & 0xFF );
_fifo_enqueue(u_by.bytebuffer[3] & 0xFF );
_fifo_enqueue(u_by.bytebuffer[2] & 0xFF );
_fifo_enqueue(u_by.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_by.bytebuffer[0] & 0xFF );

// parameter bz
union u_bz_t {
double p;
byte bytebuffer[8];
} u_bz;
u_bz.p = bz;
_fifo_enqueue(u_bz.bytebuffer[7] & 0xFF );
_fifo_enqueue(u_bz.bytebuffer[6] & 0xFF );
_fifo_enqueue(u_bz.bytebuffer[5] & 0xFF );
_fifo_enqueue(u_bz.bytebuffer[4] & 0xFF );
_fifo_enqueue(u_bz.bytebuffer[3] & 0xFF );
_fifo_enqueue(u_bz.bytebuffer[2] & 0xFF );
_fifo_enqueue(u_bz.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_bz.bytebuffer[0] & 0xFF );

// parameter brx
union u_brx_t {
double p;
byte bytebuffer[8];
} u_brx;
u_brx.p = brx;
_fifo_enqueue(u_brx.bytebuffer[7] & 0xFF );
_fifo_enqueue(u_brx.bytebuffer[6] & 0xFF );
_fifo_enqueue(u_brx.bytebuffer[5] & 0xFF );
_fifo_enqueue(u_brx.bytebuffer[4] & 0xFF );
_fifo_enqueue(u_brx.bytebuffer[3] & 0xFF );
_fifo_enqueue(u_brx.bytebuffer[2] & 0xFF );
_fifo_enqueue(u_brx.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_brx.bytebuffer[0] & 0xFF );

// parameter bry
union u_bry_t {
double p;
byte bytebuffer[8];
} u_bry;
u_bry.p = bry;
_fifo_enqueue(u_bry.bytebuffer[7] & 0xFF );
_fifo_enqueue(u_bry.bytebuffer[6] & 0xFF );
_fifo_enqueue(u_bry.bytebuffer[5] & 0xFF );
_fifo_enqueue(u_bry.bytebuffer[4] & 0xFF );
_fifo_enqueue(u_bry.bytebuffer[3] & 0xFF );
_fifo_enqueue(u_bry.bytebuffer[2] & 0xFF );
_fifo_enqueue(u_bry.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_bry.bytebuffer[0] & 0xFF );

// parameter brz
union u_brz_t {
double p;
byte bytebuffer[8];
} u_brz;
u_brz.p = brz;
_fifo_enqueue(u_brz.bytebuffer[7] & 0xFF );
_fifo_enqueue(u_brz.bytebuffer[6] & 0xFF );
_fifo_enqueue(u_brz.bytebuffer[5] & 0xFF );
_fifo_enqueue(u_brz.bytebuffer[4] & 0xFF );
_fifo_enqueue(u_brz.bytebuffer[3] & 0xFF );
_fifo_enqueue(u_brz.bytebuffer[2] & 0xFF );
_fifo_enqueue(u_brz.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_brz.bytebuffer[0] & 0xFF );

// parameter cx
union u_cx_t {
double p;
byte bytebuffer[8];
} u_cx;
u_cx.p = cx;
_fifo_enqueue(u_cx.bytebuffer[7] & 0xFF );
_fifo_enqueue(u_cx.bytebuffer[6] & 0xFF );
_fifo_enqueue(u_cx.bytebuffer[5] & 0xFF );
_fifo_enqueue(u_cx.bytebuffer[4] & 0xFF );
_fifo_enqueue(u_cx.bytebuffer[3] & 0xFF );
_fifo_enqueue(u_cx.bytebuffer[2] & 0xFF );
_fifo_enqueue(u_cx.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_cx.bytebuffer[0] & 0xFF );

// parameter cy
union u_cy_t {
double p;
byte bytebuffer[8];
} u_cy;
u_cy.p = cy;
_fifo_enqueue(u_cy.bytebuffer[7] & 0xFF );
_fifo_enqueue(u_cy.bytebuffer[6] & 0xFF );
_fifo_enqueue(u_cy.bytebuffer[5] & 0xFF );
_fifo_enqueue(u_cy.bytebuffer[4] & 0xFF );
_fifo_enqueue(u_cy.bytebuffer[3] & 0xFF );
_fifo_enqueue(u_cy.bytebuffer[2] & 0xFF );
_fifo_enqueue(u_cy.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_cy.bytebuffer[0] & 0xFF );

// parameter cz
union u_cz_t {
double p;
byte bytebuffer[8];
} u_cz;
u_cz.p = cz;
_fifo_enqueue(u_cz.bytebuffer[7] & 0xFF );
_fifo_enqueue(u_cz.bytebuffer[6] & 0xFF );
_fifo_enqueue(u_cz.bytebuffer[5] & 0xFF );
_fifo_enqueue(u_cz.bytebuffer[4] & 0xFF );
_fifo_enqueue(u_cz.bytebuffer[3] & 0xFF );
_fifo_enqueue(u_cz.bytebuffer[2] & 0xFF );
_fifo_enqueue(u_cz.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_cz.bytebuffer[0] & 0xFF );

// parameter crx
union u_crx_t {
double p;
byte bytebuffer[8];
} u_crx;
u_crx.p = crx;
_fifo_enqueue(u_crx.bytebuffer[7] & 0xFF );
_fifo_enqueue(u_crx.bytebuffer[6] & 0xFF );
_fifo_enqueue(u_crx.bytebuffer[5] & 0xFF );
_fifo_enqueue(u_crx.bytebuffer[4] & 0xFF );
_fifo_enqueue(u_crx.bytebuffer[3] & 0xFF );
_fifo_enqueue(u_crx.bytebuffer[2] & 0xFF );
_fifo_enqueue(u_crx.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_crx.bytebuffer[0] & 0xFF );

// parameter cry
union u_cry_t {
double p;
byte bytebuffer[8];
} u_cry;
u_cry.p = cry;
_fifo_enqueue(u_cry.bytebuffer[7] & 0xFF );
_fifo_enqueue(u_cry.bytebuffer[6] & 0xFF );
_fifo_enqueue(u_cry.bytebuffer[5] & 0xFF );
_fifo_enqueue(u_cry.bytebuffer[4] & 0xFF );
_fifo_enqueue(u_cry.bytebuffer[3] & 0xFF );
_fifo_enqueue(u_cry.bytebuffer[2] & 0xFF );
_fifo_enqueue(u_cry.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_cry.bytebuffer[0] & 0xFF );

// parameter crz
union u_crz_t {
double p;
byte bytebuffer[8];
} u_crz;
u_crz.p = crz;
_fifo_enqueue(u_crz.bytebuffer[7] & 0xFF );
_fifo_enqueue(u_crz.bytebuffer[6] & 0xFF );
_fifo_enqueue(u_crz.bytebuffer[5] & 0xFF );
_fifo_enqueue(u_crz.bytebuffer[4] & 0xFF );
_fifo_enqueue(u_crz.bytebuffer[3] & 0xFF );
_fifo_enqueue(u_crz.bytebuffer[2] & 0xFF );
_fifo_enqueue(u_crz.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_crz.bytebuffer[0] & 0xFF );
}
}
// Enqueue of messages CalibrationStorer::storer::errorload
void enqueue_CalibrationStorer_send_storer_errorload(struct CalibrationStorer_Instance *_instance){
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (13 >> 8) & 0xFF );
_fifo_enqueue( 13 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_storer >> 8) & 0xFF );
_fifo_enqueue( _instance->id_storer & 0xFF );
}
}
// Enqueue of messages CalibrationStorer::storer::endload
void enqueue_CalibrationStorer_send_storer_endload(struct CalibrationStorer_Instance *_instance){
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (14 >> 8) & 0xFF );
_fifo_enqueue( 14 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_storer >> 8) & 0xFF );
_fifo_enqueue( _instance->id_storer & 0xFF );
}
}
// Enqueue of messages CalibrationStorer::progress::storerToIdle
void enqueue_CalibrationStorer_send_progress_storerToIdle(struct CalibrationStorer_Instance *_instance){
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (15 >> 8) & 0xFF );
_fifo_enqueue( 15 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_progress >> 8) & 0xFF );
_fifo_enqueue( _instance->id_progress & 0xFF );
}
}
// Enqueue of messages Storer::reader::byteRead
void enqueue_Storer_send_reader_byteRead(struct Storer_Instance *_instance, uint8_t val){
if ( fifo_byte_available() > 5 ) {

_fifo_enqueue( (16 >> 8) & 0xFF );
_fifo_enqueue( 16 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_reader >> 8) & 0xFF );
_fifo_enqueue( _instance->id_reader & 0xFF );

// parameter val
union u_val_t {
uint8_t p;
byte bytebuffer[1];
} u_val;
u_val.p = val;
_fifo_enqueue(u_val.bytebuffer[0] & 0xFF );
}
}
// Enqueue of messages Storer::reader::configRead
void enqueue_Storer_send_reader_configRead(struct Storer_Instance *_instance, double bx, double by, double bz, double brx, double bry, double brz, double cx, double cy, double cz, double crx, double cry, double crz){
if ( fifo_byte_available() > 100 ) {

_fifo_enqueue( (17 >> 8) & 0xFF );
_fifo_enqueue( 17 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_reader >> 8) & 0xFF );
_fifo_enqueue( _instance->id_reader & 0xFF );

// parameter bx
union u_bx_t {
double p;
byte bytebuffer[8];
} u_bx;
u_bx.p = bx;
_fifo_enqueue(u_bx.bytebuffer[7] & 0xFF );
_fifo_enqueue(u_bx.bytebuffer[6] & 0xFF );
_fifo_enqueue(u_bx.bytebuffer[5] & 0xFF );
_fifo_enqueue(u_bx.bytebuffer[4] & 0xFF );
_fifo_enqueue(u_bx.bytebuffer[3] & 0xFF );
_fifo_enqueue(u_bx.bytebuffer[2] & 0xFF );
_fifo_enqueue(u_bx.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_bx.bytebuffer[0] & 0xFF );

// parameter by
union u_by_t {
double p;
byte bytebuffer[8];
} u_by;
u_by.p = by;
_fifo_enqueue(u_by.bytebuffer[7] & 0xFF );
_fifo_enqueue(u_by.bytebuffer[6] & 0xFF );
_fifo_enqueue(u_by.bytebuffer[5] & 0xFF );
_fifo_enqueue(u_by.bytebuffer[4] & 0xFF );
_fifo_enqueue(u_by.bytebuffer[3] & 0xFF );
_fifo_enqueue(u_by.bytebuffer[2] & 0xFF );
_fifo_enqueue(u_by.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_by.bytebuffer[0] & 0xFF );

// parameter bz
union u_bz_t {
double p;
byte bytebuffer[8];
} u_bz;
u_bz.p = bz;
_fifo_enqueue(u_bz.bytebuffer[7] & 0xFF );
_fifo_enqueue(u_bz.bytebuffer[6] & 0xFF );
_fifo_enqueue(u_bz.bytebuffer[5] & 0xFF );
_fifo_enqueue(u_bz.bytebuffer[4] & 0xFF );
_fifo_enqueue(u_bz.bytebuffer[3] & 0xFF );
_fifo_enqueue(u_bz.bytebuffer[2] & 0xFF );
_fifo_enqueue(u_bz.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_bz.bytebuffer[0] & 0xFF );

// parameter brx
union u_brx_t {
double p;
byte bytebuffer[8];
} u_brx;
u_brx.p = brx;
_fifo_enqueue(u_brx.bytebuffer[7] & 0xFF );
_fifo_enqueue(u_brx.bytebuffer[6] & 0xFF );
_fifo_enqueue(u_brx.bytebuffer[5] & 0xFF );
_fifo_enqueue(u_brx.bytebuffer[4] & 0xFF );
_fifo_enqueue(u_brx.bytebuffer[3] & 0xFF );
_fifo_enqueue(u_brx.bytebuffer[2] & 0xFF );
_fifo_enqueue(u_brx.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_brx.bytebuffer[0] & 0xFF );

// parameter bry
union u_bry_t {
double p;
byte bytebuffer[8];
} u_bry;
u_bry.p = bry;
_fifo_enqueue(u_bry.bytebuffer[7] & 0xFF );
_fifo_enqueue(u_bry.bytebuffer[6] & 0xFF );
_fifo_enqueue(u_bry.bytebuffer[5] & 0xFF );
_fifo_enqueue(u_bry.bytebuffer[4] & 0xFF );
_fifo_enqueue(u_bry.bytebuffer[3] & 0xFF );
_fifo_enqueue(u_bry.bytebuffer[2] & 0xFF );
_fifo_enqueue(u_bry.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_bry.bytebuffer[0] & 0xFF );

// parameter brz
union u_brz_t {
double p;
byte bytebuffer[8];
} u_brz;
u_brz.p = brz;
_fifo_enqueue(u_brz.bytebuffer[7] & 0xFF );
_fifo_enqueue(u_brz.bytebuffer[6] & 0xFF );
_fifo_enqueue(u_brz.bytebuffer[5] & 0xFF );
_fifo_enqueue(u_brz.bytebuffer[4] & 0xFF );
_fifo_enqueue(u_brz.bytebuffer[3] & 0xFF );
_fifo_enqueue(u_brz.bytebuffer[2] & 0xFF );
_fifo_enqueue(u_brz.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_brz.bytebuffer[0] & 0xFF );

// parameter cx
union u_cx_t {
double p;
byte bytebuffer[8];
} u_cx;
u_cx.p = cx;
_fifo_enqueue(u_cx.bytebuffer[7] & 0xFF );
_fifo_enqueue(u_cx.bytebuffer[6] & 0xFF );
_fifo_enqueue(u_cx.bytebuffer[5] & 0xFF );
_fifo_enqueue(u_cx.bytebuffer[4] & 0xFF );
_fifo_enqueue(u_cx.bytebuffer[3] & 0xFF );
_fifo_enqueue(u_cx.bytebuffer[2] & 0xFF );
_fifo_enqueue(u_cx.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_cx.bytebuffer[0] & 0xFF );

// parameter cy
union u_cy_t {
double p;
byte bytebuffer[8];
} u_cy;
u_cy.p = cy;
_fifo_enqueue(u_cy.bytebuffer[7] & 0xFF );
_fifo_enqueue(u_cy.bytebuffer[6] & 0xFF );
_fifo_enqueue(u_cy.bytebuffer[5] & 0xFF );
_fifo_enqueue(u_cy.bytebuffer[4] & 0xFF );
_fifo_enqueue(u_cy.bytebuffer[3] & 0xFF );
_fifo_enqueue(u_cy.bytebuffer[2] & 0xFF );
_fifo_enqueue(u_cy.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_cy.bytebuffer[0] & 0xFF );

// parameter cz
union u_cz_t {
double p;
byte bytebuffer[8];
} u_cz;
u_cz.p = cz;
_fifo_enqueue(u_cz.bytebuffer[7] & 0xFF );
_fifo_enqueue(u_cz.bytebuffer[6] & 0xFF );
_fifo_enqueue(u_cz.bytebuffer[5] & 0xFF );
_fifo_enqueue(u_cz.bytebuffer[4] & 0xFF );
_fifo_enqueue(u_cz.bytebuffer[3] & 0xFF );
_fifo_enqueue(u_cz.bytebuffer[2] & 0xFF );
_fifo_enqueue(u_cz.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_cz.bytebuffer[0] & 0xFF );

// parameter crx
union u_crx_t {
double p;
byte bytebuffer[8];
} u_crx;
u_crx.p = crx;
_fifo_enqueue(u_crx.bytebuffer[7] & 0xFF );
_fifo_enqueue(u_crx.bytebuffer[6] & 0xFF );
_fifo_enqueue(u_crx.bytebuffer[5] & 0xFF );
_fifo_enqueue(u_crx.bytebuffer[4] & 0xFF );
_fifo_enqueue(u_crx.bytebuffer[3] & 0xFF );
_fifo_enqueue(u_crx.bytebuffer[2] & 0xFF );
_fifo_enqueue(u_crx.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_crx.bytebuffer[0] & 0xFF );

// parameter cry
union u_cry_t {
double p;
byte bytebuffer[8];
} u_cry;
u_cry.p = cry;
_fifo_enqueue(u_cry.bytebuffer[7] & 0xFF );
_fifo_enqueue(u_cry.bytebuffer[6] & 0xFF );
_fifo_enqueue(u_cry.bytebuffer[5] & 0xFF );
_fifo_enqueue(u_cry.bytebuffer[4] & 0xFF );
_fifo_enqueue(u_cry.bytebuffer[3] & 0xFF );
_fifo_enqueue(u_cry.bytebuffer[2] & 0xFF );
_fifo_enqueue(u_cry.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_cry.bytebuffer[0] & 0xFF );

// parameter crz
union u_crz_t {
double p;
byte bytebuffer[8];
} u_crz;
u_crz.p = crz;
_fifo_enqueue(u_crz.bytebuffer[7] & 0xFF );
_fifo_enqueue(u_crz.bytebuffer[6] & 0xFF );
_fifo_enqueue(u_crz.bytebuffer[5] & 0xFF );
_fifo_enqueue(u_crz.bytebuffer[4] & 0xFF );
_fifo_enqueue(u_crz.bytebuffer[3] & 0xFF );
_fifo_enqueue(u_crz.bytebuffer[2] & 0xFF );
_fifo_enqueue(u_crz.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_crz.bytebuffer[0] & 0xFF );
}
}
// Enqueue of messages Storer::writer::configWritten
void enqueue_Storer_send_writer_configWritten(struct Storer_Instance *_instance){
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (18 >> 8) & 0xFF );
_fifo_enqueue( 18 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_writer >> 8) & 0xFF );
_fifo_enqueue( _instance->id_writer & 0xFF );
}
}
// Enqueue of messages Storer::writer::byteWritten
void enqueue_Storer_send_writer_byteWritten(struct Storer_Instance *_instance){
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (19 >> 8) & 0xFF );
_fifo_enqueue( 19 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_writer >> 8) & 0xFF );
_fifo_enqueue( _instance->id_writer & 0xFF );
}
}
// Enqueue of messages Runner::Run::coordinates
void enqueue_Runner_send_Run_coordinates(struct Runner_Instance *_instance, double x, double y, double z, double separation){
if ( fifo_byte_available() > 36 ) {

_fifo_enqueue( (20 >> 8) & 0xFF );
_fifo_enqueue( 20 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_Run >> 8) & 0xFF );
_fifo_enqueue( _instance->id_Run & 0xFF );

// parameter x
union u_x_t {
double p;
byte bytebuffer[8];
} u_x;
u_x.p = x;
_fifo_enqueue(u_x.bytebuffer[7] & 0xFF );
_fifo_enqueue(u_x.bytebuffer[6] & 0xFF );
_fifo_enqueue(u_x.bytebuffer[5] & 0xFF );
_fifo_enqueue(u_x.bytebuffer[4] & 0xFF );
_fifo_enqueue(u_x.bytebuffer[3] & 0xFF );
_fifo_enqueue(u_x.bytebuffer[2] & 0xFF );
_fifo_enqueue(u_x.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_x.bytebuffer[0] & 0xFF );

// parameter y
union u_y_t {
double p;
byte bytebuffer[8];
} u_y;
u_y.p = y;
_fifo_enqueue(u_y.bytebuffer[7] & 0xFF );
_fifo_enqueue(u_y.bytebuffer[6] & 0xFF );
_fifo_enqueue(u_y.bytebuffer[5] & 0xFF );
_fifo_enqueue(u_y.bytebuffer[4] & 0xFF );
_fifo_enqueue(u_y.bytebuffer[3] & 0xFF );
_fifo_enqueue(u_y.bytebuffer[2] & 0xFF );
_fifo_enqueue(u_y.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_y.bytebuffer[0] & 0xFF );

// parameter z
union u_z_t {
double p;
byte bytebuffer[8];
} u_z;
u_z.p = z;
_fifo_enqueue(u_z.bytebuffer[7] & 0xFF );
_fifo_enqueue(u_z.bytebuffer[6] & 0xFF );
_fifo_enqueue(u_z.bytebuffer[5] & 0xFF );
_fifo_enqueue(u_z.bytebuffer[4] & 0xFF );
_fifo_enqueue(u_z.bytebuffer[3] & 0xFF );
_fifo_enqueue(u_z.bytebuffer[2] & 0xFF );
_fifo_enqueue(u_z.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_z.bytebuffer[0] & 0xFF );

// parameter separation
union u_separation_t {
double p;
byte bytebuffer[8];
} u_separation;
u_separation.p = separation;
_fifo_enqueue(u_separation.bytebuffer[7] & 0xFF );
_fifo_enqueue(u_separation.bytebuffer[6] & 0xFF );
_fifo_enqueue(u_separation.bytebuffer[5] & 0xFF );
_fifo_enqueue(u_separation.bytebuffer[4] & 0xFF );
_fifo_enqueue(u_separation.bytebuffer[3] & 0xFF );
_fifo_enqueue(u_separation.bytebuffer[2] & 0xFF );
_fifo_enqueue(u_separation.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_separation.bytebuffer[0] & 0xFF );
}
}
// Enqueue of messages Runner::StatusSender::status
void enqueue_Runner_send_StatusSender_status(struct Runner_Instance *_instance, uint8_t id){
if ( fifo_byte_available() > 5 ) {

_fifo_enqueue( (2 >> 8) & 0xFF );
_fifo_enqueue( 2 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_StatusSender >> 8) & 0xFF );
_fifo_enqueue( _instance->id_StatusSender & 0xFF );

// parameter id
union u_id_t {
uint8_t p;
byte bytebuffer[1];
} u_id;
u_id.p = id;
_fifo_enqueue(u_id.bytebuffer[0] & 0xFF );
}
}
// Enqueue of messages SoftButton::Timer::timer_timeout
void enqueue_SoftButton_send_Timer_timer_timeout(struct SoftButton_Instance *_instance){
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (21 >> 8) & 0xFF );
_fifo_enqueue( 21 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_Timer >> 8) & 0xFF );
_fifo_enqueue( _instance->id_Timer & 0xFF );
}
}
// Enqueue of messages SoftButton::SoftButton::double_click
void enqueue_SoftButton_send_SoftButton_double_click(struct SoftButton_Instance *_instance){
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (22 >> 8) & 0xFF );
_fifo_enqueue( 22 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_SoftButton >> 8) & 0xFF );
_fifo_enqueue( _instance->id_SoftButton & 0xFF );
}
}
// Enqueue of messages SoftButton::SoftButton::click
void enqueue_SoftButton_send_SoftButton_click(struct SoftButton_Instance *_instance){
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (23 >> 8) & 0xFF );
_fifo_enqueue( 23 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_SoftButton >> 8) & 0xFF );
_fifo_enqueue( _instance->id_SoftButton & 0xFF );
}
}
// Enqueue of messages SoftButton::SoftButton::long_press
void enqueue_SoftButton_send_SoftButton_long_press(struct SoftButton_Instance *_instance){
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (24 >> 8) & 0xFF );
_fifo_enqueue( 24 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_SoftButton >> 8) & 0xFF );
_fifo_enqueue( _instance->id_SoftButton & 0xFF );
}
}
// Enqueue of messages Calibrator::calibrator::endcalibrate
void enqueue_Calibrator_send_calibrator_endcalibrate(struct Calibrator_Instance *_instance){
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (25 >> 8) & 0xFF );
_fifo_enqueue( 25 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_calibrator >> 8) & 0xFF );
_fifo_enqueue( _instance->id_calibrator & 0xFF );
}
}
// Enqueue of messages Calibrator::calibrator::calibrationfromserial
void enqueue_Calibrator_send_calibrator_calibrationfromserial(struct Calibrator_Instance *_instance){
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (26 >> 8) & 0xFF );
_fifo_enqueue( 26 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_calibrator >> 8) & 0xFF );
_fifo_enqueue( _instance->id_calibrator & 0xFF );
}
}
// Enqueue of messages Calibrator::calibrator::errcalibrate
void enqueue_Calibrator_send_calibrator_errcalibrate(struct Calibrator_Instance *_instance){
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (27 >> 8) & 0xFF );
_fifo_enqueue( 27 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_calibrator >> 8) & 0xFF );
_fifo_enqueue( _instance->id_calibrator & 0xFF );
}
}
// Enqueue of messages Calibrator::StatusSender::status
void enqueue_Calibrator_send_StatusSender_status(struct Calibrator_Instance *_instance, uint8_t id){
if ( fifo_byte_available() > 5 ) {

_fifo_enqueue( (2 >> 8) & 0xFF );
_fifo_enqueue( 2 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_StatusSender >> 8) & 0xFF );
_fifo_enqueue( _instance->id_StatusSender & 0xFF );

// parameter id
union u_id_t {
uint8_t p;
byte bytebuffer[1];
} u_id;
u_id.p = id;
_fifo_enqueue(u_id.bytebuffer[0] & 0xFF );
}
}
// Enqueue of messages Calibrator::avt::calibrationComplete
void enqueue_Calibrator_send_avt_calibrationComplete(struct Calibrator_Instance *_instance){
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (28 >> 8) & 0xFF );
_fifo_enqueue( 28 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_avt >> 8) & 0xFF );
_fifo_enqueue( _instance->id_avt & 0xFF );
}
}
// Enqueue of messages Calibrator::avt::calibrationFailed
void enqueue_Calibrator_send_avt_calibrationFailed(struct Calibrator_Instance *_instance){
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (29 >> 8) & 0xFF );
_fifo_enqueue( 29 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_avt >> 8) & 0xFF );
_fifo_enqueue( _instance->id_avt & 0xFF );
}
}
// Enqueue of messages Calibrator::avt::calibrating
void enqueue_Calibrator_send_avt_calibrating(struct Calibrator_Instance *_instance){
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (30 >> 8) & 0xFF );
_fifo_enqueue( 30 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_avt >> 8) & 0xFF );
_fifo_enqueue( _instance->id_avt & 0xFF );
}
}
// Enqueue of messages CalibrationValidator::validator::errvalidate
void enqueue_CalibrationValidator_send_validator_errvalidate(struct CalibrationValidator_Instance *_instance){
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (31 >> 8) & 0xFF );
_fifo_enqueue( 31 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_validator >> 8) & 0xFF );
_fifo_enqueue( _instance->id_validator & 0xFF );
}
}
// Enqueue of messages CalibrationValidator::validator::endvalidate
void enqueue_CalibrationValidator_send_validator_endvalidate(struct CalibrationValidator_Instance *_instance){
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (32 >> 8) & 0xFF );
_fifo_enqueue( 32 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_validator >> 8) & 0xFF );
_fifo_enqueue( _instance->id_validator & 0xFF );
}
}
// Enqueue of messages CalibrationValidator::avt::validating
void enqueue_CalibrationValidator_send_avt_validating(struct CalibrationValidator_Instance *_instance){
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (33 >> 8) & 0xFF );
_fifo_enqueue( 33 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_avt >> 8) & 0xFF );
_fifo_enqueue( _instance->id_avt & 0xFF );
}
}
// Enqueue of messages PulseReader::PulseSender::pulseDetectedEvent
void enqueue_PulseReader_send_PulseSender_pulseDetectedEvent(struct PulseReader_Instance *_instance, uint32_t start, uint32_t duration){
if ( fifo_byte_available() > 12 ) {

_fifo_enqueue( (34 >> 8) & 0xFF );
_fifo_enqueue( 34 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_PulseSender >> 8) & 0xFF );
_fifo_enqueue( _instance->id_PulseSender & 0xFF );

// parameter start
union u_start_t {
uint32_t p;
byte bytebuffer[4];
} u_start;
u_start.p = start;
_fifo_enqueue(u_start.bytebuffer[3] & 0xFF );
_fifo_enqueue(u_start.bytebuffer[2] & 0xFF );
_fifo_enqueue(u_start.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_start.bytebuffer[0] & 0xFF );

// parameter duration
union u_duration_t {
uint32_t p;
byte bytebuffer[4];
} u_duration;
u_duration.p = duration;
_fifo_enqueue(u_duration.bytebuffer[3] & 0xFF );
_fifo_enqueue(u_duration.bytebuffer[2] & 0xFF );
_fifo_enqueue(u_duration.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_duration.bytebuffer[0] & 0xFF );
}
}
// Enqueue of messages PulseReader::OverflowNotifier::timerOverflow
void enqueue_PulseReader_send_OverflowNotifier_timerOverflow(struct PulseReader_Instance *_instance){
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (35 >> 8) & 0xFF );
_fifo_enqueue( 35 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_OverflowNotifier >> 8) & 0xFF );
_fifo_enqueue( _instance->id_OverflowNotifier & 0xFF );
}
}
// Enqueue of messages PulseReader::Transitions::pulseDetected
void enqueue_PulseReader_send_Transitions_pulseDetected(struct PulseReader_Instance *_instance, uint32_t start, uint32_t duration){
if ( fifo_byte_available() > 12 ) {

_fifo_enqueue( (36 >> 8) & 0xFF );
_fifo_enqueue( 36 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_Transitions >> 8) & 0xFF );
_fifo_enqueue( _instance->id_Transitions & 0xFF );

// parameter start
union u_start_t {
uint32_t p;
byte bytebuffer[4];
} u_start;
u_start.p = start;
_fifo_enqueue(u_start.bytebuffer[3] & 0xFF );
_fifo_enqueue(u_start.bytebuffer[2] & 0xFF );
_fifo_enqueue(u_start.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_start.bytebuffer[0] & 0xFF );

// parameter duration
union u_duration_t {
uint32_t p;
byte bytebuffer[4];
} u_duration;
u_duration.p = duration;
_fifo_enqueue(u_duration.bytebuffer[3] & 0xFF );
_fifo_enqueue(u_duration.bytebuffer[2] & 0xFF );
_fifo_enqueue(u_duration.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_duration.bytebuffer[0] & 0xFF );
}
}
// Enqueue of messages SerialIn::serialcall::calibrationreceived
void enqueue_SerialIn_send_serialcall_calibrationreceived(struct SerialIn_Instance *_instance, double bx, double by, double bz, double brx, double bry, double brz, double cx, double cy, double cz, double crx, double cry, double crz){
if ( fifo_byte_available() > 100 ) {

_fifo_enqueue( (37 >> 8) & 0xFF );
_fifo_enqueue( 37 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_serialcall >> 8) & 0xFF );
_fifo_enqueue( _instance->id_serialcall & 0xFF );

// parameter bx
union u_bx_t {
double p;
byte bytebuffer[8];
} u_bx;
u_bx.p = bx;
_fifo_enqueue(u_bx.bytebuffer[7] & 0xFF );
_fifo_enqueue(u_bx.bytebuffer[6] & 0xFF );
_fifo_enqueue(u_bx.bytebuffer[5] & 0xFF );
_fifo_enqueue(u_bx.bytebuffer[4] & 0xFF );
_fifo_enqueue(u_bx.bytebuffer[3] & 0xFF );
_fifo_enqueue(u_bx.bytebuffer[2] & 0xFF );
_fifo_enqueue(u_bx.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_bx.bytebuffer[0] & 0xFF );

// parameter by
union u_by_t {
double p;
byte bytebuffer[8];
} u_by;
u_by.p = by;
_fifo_enqueue(u_by.bytebuffer[7] & 0xFF );
_fifo_enqueue(u_by.bytebuffer[6] & 0xFF );
_fifo_enqueue(u_by.bytebuffer[5] & 0xFF );
_fifo_enqueue(u_by.bytebuffer[4] & 0xFF );
_fifo_enqueue(u_by.bytebuffer[3] & 0xFF );
_fifo_enqueue(u_by.bytebuffer[2] & 0xFF );
_fifo_enqueue(u_by.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_by.bytebuffer[0] & 0xFF );

// parameter bz
union u_bz_t {
double p;
byte bytebuffer[8];
} u_bz;
u_bz.p = bz;
_fifo_enqueue(u_bz.bytebuffer[7] & 0xFF );
_fifo_enqueue(u_bz.bytebuffer[6] & 0xFF );
_fifo_enqueue(u_bz.bytebuffer[5] & 0xFF );
_fifo_enqueue(u_bz.bytebuffer[4] & 0xFF );
_fifo_enqueue(u_bz.bytebuffer[3] & 0xFF );
_fifo_enqueue(u_bz.bytebuffer[2] & 0xFF );
_fifo_enqueue(u_bz.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_bz.bytebuffer[0] & 0xFF );

// parameter brx
union u_brx_t {
double p;
byte bytebuffer[8];
} u_brx;
u_brx.p = brx;
_fifo_enqueue(u_brx.bytebuffer[7] & 0xFF );
_fifo_enqueue(u_brx.bytebuffer[6] & 0xFF );
_fifo_enqueue(u_brx.bytebuffer[5] & 0xFF );
_fifo_enqueue(u_brx.bytebuffer[4] & 0xFF );
_fifo_enqueue(u_brx.bytebuffer[3] & 0xFF );
_fifo_enqueue(u_brx.bytebuffer[2] & 0xFF );
_fifo_enqueue(u_brx.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_brx.bytebuffer[0] & 0xFF );

// parameter bry
union u_bry_t {
double p;
byte bytebuffer[8];
} u_bry;
u_bry.p = bry;
_fifo_enqueue(u_bry.bytebuffer[7] & 0xFF );
_fifo_enqueue(u_bry.bytebuffer[6] & 0xFF );
_fifo_enqueue(u_bry.bytebuffer[5] & 0xFF );
_fifo_enqueue(u_bry.bytebuffer[4] & 0xFF );
_fifo_enqueue(u_bry.bytebuffer[3] & 0xFF );
_fifo_enqueue(u_bry.bytebuffer[2] & 0xFF );
_fifo_enqueue(u_bry.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_bry.bytebuffer[0] & 0xFF );

// parameter brz
union u_brz_t {
double p;
byte bytebuffer[8];
} u_brz;
u_brz.p = brz;
_fifo_enqueue(u_brz.bytebuffer[7] & 0xFF );
_fifo_enqueue(u_brz.bytebuffer[6] & 0xFF );
_fifo_enqueue(u_brz.bytebuffer[5] & 0xFF );
_fifo_enqueue(u_brz.bytebuffer[4] & 0xFF );
_fifo_enqueue(u_brz.bytebuffer[3] & 0xFF );
_fifo_enqueue(u_brz.bytebuffer[2] & 0xFF );
_fifo_enqueue(u_brz.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_brz.bytebuffer[0] & 0xFF );

// parameter cx
union u_cx_t {
double p;
byte bytebuffer[8];
} u_cx;
u_cx.p = cx;
_fifo_enqueue(u_cx.bytebuffer[7] & 0xFF );
_fifo_enqueue(u_cx.bytebuffer[6] & 0xFF );
_fifo_enqueue(u_cx.bytebuffer[5] & 0xFF );
_fifo_enqueue(u_cx.bytebuffer[4] & 0xFF );
_fifo_enqueue(u_cx.bytebuffer[3] & 0xFF );
_fifo_enqueue(u_cx.bytebuffer[2] & 0xFF );
_fifo_enqueue(u_cx.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_cx.bytebuffer[0] & 0xFF );

// parameter cy
union u_cy_t {
double p;
byte bytebuffer[8];
} u_cy;
u_cy.p = cy;
_fifo_enqueue(u_cy.bytebuffer[7] & 0xFF );
_fifo_enqueue(u_cy.bytebuffer[6] & 0xFF );
_fifo_enqueue(u_cy.bytebuffer[5] & 0xFF );
_fifo_enqueue(u_cy.bytebuffer[4] & 0xFF );
_fifo_enqueue(u_cy.bytebuffer[3] & 0xFF );
_fifo_enqueue(u_cy.bytebuffer[2] & 0xFF );
_fifo_enqueue(u_cy.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_cy.bytebuffer[0] & 0xFF );

// parameter cz
union u_cz_t {
double p;
byte bytebuffer[8];
} u_cz;
u_cz.p = cz;
_fifo_enqueue(u_cz.bytebuffer[7] & 0xFF );
_fifo_enqueue(u_cz.bytebuffer[6] & 0xFF );
_fifo_enqueue(u_cz.bytebuffer[5] & 0xFF );
_fifo_enqueue(u_cz.bytebuffer[4] & 0xFF );
_fifo_enqueue(u_cz.bytebuffer[3] & 0xFF );
_fifo_enqueue(u_cz.bytebuffer[2] & 0xFF );
_fifo_enqueue(u_cz.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_cz.bytebuffer[0] & 0xFF );

// parameter crx
union u_crx_t {
double p;
byte bytebuffer[8];
} u_crx;
u_crx.p = crx;
_fifo_enqueue(u_crx.bytebuffer[7] & 0xFF );
_fifo_enqueue(u_crx.bytebuffer[6] & 0xFF );
_fifo_enqueue(u_crx.bytebuffer[5] & 0xFF );
_fifo_enqueue(u_crx.bytebuffer[4] & 0xFF );
_fifo_enqueue(u_crx.bytebuffer[3] & 0xFF );
_fifo_enqueue(u_crx.bytebuffer[2] & 0xFF );
_fifo_enqueue(u_crx.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_crx.bytebuffer[0] & 0xFF );

// parameter cry
union u_cry_t {
double p;
byte bytebuffer[8];
} u_cry;
u_cry.p = cry;
_fifo_enqueue(u_cry.bytebuffer[7] & 0xFF );
_fifo_enqueue(u_cry.bytebuffer[6] & 0xFF );
_fifo_enqueue(u_cry.bytebuffer[5] & 0xFF );
_fifo_enqueue(u_cry.bytebuffer[4] & 0xFF );
_fifo_enqueue(u_cry.bytebuffer[3] & 0xFF );
_fifo_enqueue(u_cry.bytebuffer[2] & 0xFF );
_fifo_enqueue(u_cry.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_cry.bytebuffer[0] & 0xFF );

// parameter crz
union u_crz_t {
double p;
byte bytebuffer[8];
} u_crz;
u_crz.p = crz;
_fifo_enqueue(u_crz.bytebuffer[7] & 0xFF );
_fifo_enqueue(u_crz.bytebuffer[6] & 0xFF );
_fifo_enqueue(u_crz.bytebuffer[5] & 0xFF );
_fifo_enqueue(u_crz.bytebuffer[4] & 0xFF );
_fifo_enqueue(u_crz.bytebuffer[3] & 0xFF );
_fifo_enqueue(u_crz.bytebuffer[2] & 0xFF );
_fifo_enqueue(u_crz.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_crz.bytebuffer[0] & 0xFF );
}
}
// Enqueue of messages SerialIn::Timer::serial_timeout
void enqueue_SerialIn_send_Timer_serial_timeout(struct SerialIn_Instance *_instance){
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (38 >> 8) & 0xFF );
_fifo_enqueue( 38 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_Timer >> 8) & 0xFF );
_fifo_enqueue( _instance->id_Timer & 0xFF );
}
}
// Enqueue of messages Backbone::Run::baseStationAngles
void enqueue_Backbone_send_Run_baseStationAngles(struct Backbone_Instance *_instance, double bh, double bv, double ch, double cv){
if ( fifo_byte_available() > 36 ) {

_fifo_enqueue( (39 >> 8) & 0xFF );
_fifo_enqueue( 39 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_Run >> 8) & 0xFF );
_fifo_enqueue( _instance->id_Run & 0xFF );

// parameter bh
union u_bh_t {
double p;
byte bytebuffer[8];
} u_bh;
u_bh.p = bh;
_fifo_enqueue(u_bh.bytebuffer[7] & 0xFF );
_fifo_enqueue(u_bh.bytebuffer[6] & 0xFF );
_fifo_enqueue(u_bh.bytebuffer[5] & 0xFF );
_fifo_enqueue(u_bh.bytebuffer[4] & 0xFF );
_fifo_enqueue(u_bh.bytebuffer[3] & 0xFF );
_fifo_enqueue(u_bh.bytebuffer[2] & 0xFF );
_fifo_enqueue(u_bh.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_bh.bytebuffer[0] & 0xFF );

// parameter bv
union u_bv_t {
double p;
byte bytebuffer[8];
} u_bv;
u_bv.p = bv;
_fifo_enqueue(u_bv.bytebuffer[7] & 0xFF );
_fifo_enqueue(u_bv.bytebuffer[6] & 0xFF );
_fifo_enqueue(u_bv.bytebuffer[5] & 0xFF );
_fifo_enqueue(u_bv.bytebuffer[4] & 0xFF );
_fifo_enqueue(u_bv.bytebuffer[3] & 0xFF );
_fifo_enqueue(u_bv.bytebuffer[2] & 0xFF );
_fifo_enqueue(u_bv.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_bv.bytebuffer[0] & 0xFF );

// parameter ch
union u_ch_t {
double p;
byte bytebuffer[8];
} u_ch;
u_ch.p = ch;
_fifo_enqueue(u_ch.bytebuffer[7] & 0xFF );
_fifo_enqueue(u_ch.bytebuffer[6] & 0xFF );
_fifo_enqueue(u_ch.bytebuffer[5] & 0xFF );
_fifo_enqueue(u_ch.bytebuffer[4] & 0xFF );
_fifo_enqueue(u_ch.bytebuffer[3] & 0xFF );
_fifo_enqueue(u_ch.bytebuffer[2] & 0xFF );
_fifo_enqueue(u_ch.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_ch.bytebuffer[0] & 0xFF );

// parameter cv
union u_cv_t {
double p;
byte bytebuffer[8];
} u_cv;
u_cv.p = cv;
_fifo_enqueue(u_cv.bytebuffer[7] & 0xFF );
_fifo_enqueue(u_cv.bytebuffer[6] & 0xFF );
_fifo_enqueue(u_cv.bytebuffer[5] & 0xFF );
_fifo_enqueue(u_cv.bytebuffer[4] & 0xFF );
_fifo_enqueue(u_cv.bytebuffer[3] & 0xFF );
_fifo_enqueue(u_cv.bytebuffer[2] & 0xFF );
_fifo_enqueue(u_cv.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_cv.bytebuffer[0] & 0xFF );
}
}
// Enqueue of messages Backbone::CalibrationStorer::load
void enqueue_Backbone_send_CalibrationStorer_load(struct Backbone_Instance *_instance){
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (40 >> 8) & 0xFF );
_fifo_enqueue( 40 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_CalibrationStorer >> 8) & 0xFF );
_fifo_enqueue( _instance->id_CalibrationStorer & 0xFF );
}
}
// Enqueue of messages Backbone::CalibrationStorer::save
void enqueue_Backbone_send_CalibrationStorer_save(struct Backbone_Instance *_instance){
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (41 >> 8) & 0xFF );
_fifo_enqueue( 41 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_CalibrationStorer >> 8) & 0xFF );
_fifo_enqueue( _instance->id_CalibrationStorer & 0xFF );
}
}
// Enqueue of messages Backbone::validator::validate
void enqueue_Backbone_send_validator_validate(struct Backbone_Instance *_instance){
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (42 >> 8) & 0xFF );
_fifo_enqueue( 42 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_validator >> 8) & 0xFF );
_fifo_enqueue( _instance->id_validator & 0xFF );
}
}
// Enqueue of messages Backbone::calibrator::entrypoint
void enqueue_Backbone_send_calibrator_entrypoint(struct Backbone_Instance *_instance){
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (43 >> 8) & 0xFF );
_fifo_enqueue( 43 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_calibrator >> 8) & 0xFF );
_fifo_enqueue( _instance->id_calibrator & 0xFF );
}
}
// Enqueue of messages Backbone::calibrator::receiveAngles
void enqueue_Backbone_send_calibrator_receiveAngles(struct Backbone_Instance *_instance, double bh, double bv, double ch, double cv){
if ( fifo_byte_available() > 36 ) {

_fifo_enqueue( (44 >> 8) & 0xFF );
_fifo_enqueue( 44 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_calibrator >> 8) & 0xFF );
_fifo_enqueue( _instance->id_calibrator & 0xFF );

// parameter bh
union u_bh_t {
double p;
byte bytebuffer[8];
} u_bh;
u_bh.p = bh;
_fifo_enqueue(u_bh.bytebuffer[7] & 0xFF );
_fifo_enqueue(u_bh.bytebuffer[6] & 0xFF );
_fifo_enqueue(u_bh.bytebuffer[5] & 0xFF );
_fifo_enqueue(u_bh.bytebuffer[4] & 0xFF );
_fifo_enqueue(u_bh.bytebuffer[3] & 0xFF );
_fifo_enqueue(u_bh.bytebuffer[2] & 0xFF );
_fifo_enqueue(u_bh.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_bh.bytebuffer[0] & 0xFF );

// parameter bv
union u_bv_t {
double p;
byte bytebuffer[8];
} u_bv;
u_bv.p = bv;
_fifo_enqueue(u_bv.bytebuffer[7] & 0xFF );
_fifo_enqueue(u_bv.bytebuffer[6] & 0xFF );
_fifo_enqueue(u_bv.bytebuffer[5] & 0xFF );
_fifo_enqueue(u_bv.bytebuffer[4] & 0xFF );
_fifo_enqueue(u_bv.bytebuffer[3] & 0xFF );
_fifo_enqueue(u_bv.bytebuffer[2] & 0xFF );
_fifo_enqueue(u_bv.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_bv.bytebuffer[0] & 0xFF );

// parameter ch
union u_ch_t {
double p;
byte bytebuffer[8];
} u_ch;
u_ch.p = ch;
_fifo_enqueue(u_ch.bytebuffer[7] & 0xFF );
_fifo_enqueue(u_ch.bytebuffer[6] & 0xFF );
_fifo_enqueue(u_ch.bytebuffer[5] & 0xFF );
_fifo_enqueue(u_ch.bytebuffer[4] & 0xFF );
_fifo_enqueue(u_ch.bytebuffer[3] & 0xFF );
_fifo_enqueue(u_ch.bytebuffer[2] & 0xFF );
_fifo_enqueue(u_ch.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_ch.bytebuffer[0] & 0xFF );

// parameter cv
union u_cv_t {
double p;
byte bytebuffer[8];
} u_cv;
u_cv.p = cv;
_fifo_enqueue(u_cv.bytebuffer[7] & 0xFF );
_fifo_enqueue(u_cv.bytebuffer[6] & 0xFF );
_fifo_enqueue(u_cv.bytebuffer[5] & 0xFF );
_fifo_enqueue(u_cv.bytebuffer[4] & 0xFF );
_fifo_enqueue(u_cv.bytebuffer[3] & 0xFF );
_fifo_enqueue(u_cv.bytebuffer[2] & 0xFF );
_fifo_enqueue(u_cv.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_cv.bytebuffer[0] & 0xFF );
}
}
// Enqueue of messages Backbone::calibrator::calibrate
void enqueue_Backbone_send_calibrator_calibrate(struct Backbone_Instance *_instance){
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (45 >> 8) & 0xFF );
_fifo_enqueue( 45 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_calibrator >> 8) & 0xFF );
_fifo_enqueue( _instance->id_calibrator & 0xFF );
}
}
// Enqueue of messages Backbone::calibrator::receivecalibration
void enqueue_Backbone_send_calibrator_receivecalibration(struct Backbone_Instance *_instance, double bx, double by, double bz, double brx, double bry, double brz, double cx, double cy, double cz, double crx, double cry, double crz){
if ( fifo_byte_available() > 100 ) {

_fifo_enqueue( (46 >> 8) & 0xFF );
_fifo_enqueue( 46 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_calibrator >> 8) & 0xFF );
_fifo_enqueue( _instance->id_calibrator & 0xFF );

// parameter bx
union u_bx_t {
double p;
byte bytebuffer[8];
} u_bx;
u_bx.p = bx;
_fifo_enqueue(u_bx.bytebuffer[7] & 0xFF );
_fifo_enqueue(u_bx.bytebuffer[6] & 0xFF );
_fifo_enqueue(u_bx.bytebuffer[5] & 0xFF );
_fifo_enqueue(u_bx.bytebuffer[4] & 0xFF );
_fifo_enqueue(u_bx.bytebuffer[3] & 0xFF );
_fifo_enqueue(u_bx.bytebuffer[2] & 0xFF );
_fifo_enqueue(u_bx.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_bx.bytebuffer[0] & 0xFF );

// parameter by
union u_by_t {
double p;
byte bytebuffer[8];
} u_by;
u_by.p = by;
_fifo_enqueue(u_by.bytebuffer[7] & 0xFF );
_fifo_enqueue(u_by.bytebuffer[6] & 0xFF );
_fifo_enqueue(u_by.bytebuffer[5] & 0xFF );
_fifo_enqueue(u_by.bytebuffer[4] & 0xFF );
_fifo_enqueue(u_by.bytebuffer[3] & 0xFF );
_fifo_enqueue(u_by.bytebuffer[2] & 0xFF );
_fifo_enqueue(u_by.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_by.bytebuffer[0] & 0xFF );

// parameter bz
union u_bz_t {
double p;
byte bytebuffer[8];
} u_bz;
u_bz.p = bz;
_fifo_enqueue(u_bz.bytebuffer[7] & 0xFF );
_fifo_enqueue(u_bz.bytebuffer[6] & 0xFF );
_fifo_enqueue(u_bz.bytebuffer[5] & 0xFF );
_fifo_enqueue(u_bz.bytebuffer[4] & 0xFF );
_fifo_enqueue(u_bz.bytebuffer[3] & 0xFF );
_fifo_enqueue(u_bz.bytebuffer[2] & 0xFF );
_fifo_enqueue(u_bz.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_bz.bytebuffer[0] & 0xFF );

// parameter brx
union u_brx_t {
double p;
byte bytebuffer[8];
} u_brx;
u_brx.p = brx;
_fifo_enqueue(u_brx.bytebuffer[7] & 0xFF );
_fifo_enqueue(u_brx.bytebuffer[6] & 0xFF );
_fifo_enqueue(u_brx.bytebuffer[5] & 0xFF );
_fifo_enqueue(u_brx.bytebuffer[4] & 0xFF );
_fifo_enqueue(u_brx.bytebuffer[3] & 0xFF );
_fifo_enqueue(u_brx.bytebuffer[2] & 0xFF );
_fifo_enqueue(u_brx.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_brx.bytebuffer[0] & 0xFF );

// parameter bry
union u_bry_t {
double p;
byte bytebuffer[8];
} u_bry;
u_bry.p = bry;
_fifo_enqueue(u_bry.bytebuffer[7] & 0xFF );
_fifo_enqueue(u_bry.bytebuffer[6] & 0xFF );
_fifo_enqueue(u_bry.bytebuffer[5] & 0xFF );
_fifo_enqueue(u_bry.bytebuffer[4] & 0xFF );
_fifo_enqueue(u_bry.bytebuffer[3] & 0xFF );
_fifo_enqueue(u_bry.bytebuffer[2] & 0xFF );
_fifo_enqueue(u_bry.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_bry.bytebuffer[0] & 0xFF );

// parameter brz
union u_brz_t {
double p;
byte bytebuffer[8];
} u_brz;
u_brz.p = brz;
_fifo_enqueue(u_brz.bytebuffer[7] & 0xFF );
_fifo_enqueue(u_brz.bytebuffer[6] & 0xFF );
_fifo_enqueue(u_brz.bytebuffer[5] & 0xFF );
_fifo_enqueue(u_brz.bytebuffer[4] & 0xFF );
_fifo_enqueue(u_brz.bytebuffer[3] & 0xFF );
_fifo_enqueue(u_brz.bytebuffer[2] & 0xFF );
_fifo_enqueue(u_brz.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_brz.bytebuffer[0] & 0xFF );

// parameter cx
union u_cx_t {
double p;
byte bytebuffer[8];
} u_cx;
u_cx.p = cx;
_fifo_enqueue(u_cx.bytebuffer[7] & 0xFF );
_fifo_enqueue(u_cx.bytebuffer[6] & 0xFF );
_fifo_enqueue(u_cx.bytebuffer[5] & 0xFF );
_fifo_enqueue(u_cx.bytebuffer[4] & 0xFF );
_fifo_enqueue(u_cx.bytebuffer[3] & 0xFF );
_fifo_enqueue(u_cx.bytebuffer[2] & 0xFF );
_fifo_enqueue(u_cx.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_cx.bytebuffer[0] & 0xFF );

// parameter cy
union u_cy_t {
double p;
byte bytebuffer[8];
} u_cy;
u_cy.p = cy;
_fifo_enqueue(u_cy.bytebuffer[7] & 0xFF );
_fifo_enqueue(u_cy.bytebuffer[6] & 0xFF );
_fifo_enqueue(u_cy.bytebuffer[5] & 0xFF );
_fifo_enqueue(u_cy.bytebuffer[4] & 0xFF );
_fifo_enqueue(u_cy.bytebuffer[3] & 0xFF );
_fifo_enqueue(u_cy.bytebuffer[2] & 0xFF );
_fifo_enqueue(u_cy.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_cy.bytebuffer[0] & 0xFF );

// parameter cz
union u_cz_t {
double p;
byte bytebuffer[8];
} u_cz;
u_cz.p = cz;
_fifo_enqueue(u_cz.bytebuffer[7] & 0xFF );
_fifo_enqueue(u_cz.bytebuffer[6] & 0xFF );
_fifo_enqueue(u_cz.bytebuffer[5] & 0xFF );
_fifo_enqueue(u_cz.bytebuffer[4] & 0xFF );
_fifo_enqueue(u_cz.bytebuffer[3] & 0xFF );
_fifo_enqueue(u_cz.bytebuffer[2] & 0xFF );
_fifo_enqueue(u_cz.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_cz.bytebuffer[0] & 0xFF );

// parameter crx
union u_crx_t {
double p;
byte bytebuffer[8];
} u_crx;
u_crx.p = crx;
_fifo_enqueue(u_crx.bytebuffer[7] & 0xFF );
_fifo_enqueue(u_crx.bytebuffer[6] & 0xFF );
_fifo_enqueue(u_crx.bytebuffer[5] & 0xFF );
_fifo_enqueue(u_crx.bytebuffer[4] & 0xFF );
_fifo_enqueue(u_crx.bytebuffer[3] & 0xFF );
_fifo_enqueue(u_crx.bytebuffer[2] & 0xFF );
_fifo_enqueue(u_crx.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_crx.bytebuffer[0] & 0xFF );

// parameter cry
union u_cry_t {
double p;
byte bytebuffer[8];
} u_cry;
u_cry.p = cry;
_fifo_enqueue(u_cry.bytebuffer[7] & 0xFF );
_fifo_enqueue(u_cry.bytebuffer[6] & 0xFF );
_fifo_enqueue(u_cry.bytebuffer[5] & 0xFF );
_fifo_enqueue(u_cry.bytebuffer[4] & 0xFF );
_fifo_enqueue(u_cry.bytebuffer[3] & 0xFF );
_fifo_enqueue(u_cry.bytebuffer[2] & 0xFF );
_fifo_enqueue(u_cry.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_cry.bytebuffer[0] & 0xFF );

// parameter crz
union u_crz_t {
double p;
byte bytebuffer[8];
} u_crz;
u_crz.p = crz;
_fifo_enqueue(u_crz.bytebuffer[7] & 0xFF );
_fifo_enqueue(u_crz.bytebuffer[6] & 0xFF );
_fifo_enqueue(u_crz.bytebuffer[5] & 0xFF );
_fifo_enqueue(u_crz.bytebuffer[4] & 0xFF );
_fifo_enqueue(u_crz.bytebuffer[3] & 0xFF );
_fifo_enqueue(u_crz.bytebuffer[2] & 0xFF );
_fifo_enqueue(u_crz.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_crz.bytebuffer[0] & 0xFF );
}
}
// Enqueue of messages Backbone::printer::printPoint
void enqueue_Backbone_send_printer_printPoint(struct Backbone_Instance *_instance, double x, double y, double z, double separation, uint8_t verbose){
if ( fifo_byte_available() > 37 ) {

_fifo_enqueue( (47 >> 8) & 0xFF );
_fifo_enqueue( 47 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_printer >> 8) & 0xFF );
_fifo_enqueue( _instance->id_printer & 0xFF );

// parameter x
union u_x_t {
double p;
byte bytebuffer[8];
} u_x;
u_x.p = x;
_fifo_enqueue(u_x.bytebuffer[7] & 0xFF );
_fifo_enqueue(u_x.bytebuffer[6] & 0xFF );
_fifo_enqueue(u_x.bytebuffer[5] & 0xFF );
_fifo_enqueue(u_x.bytebuffer[4] & 0xFF );
_fifo_enqueue(u_x.bytebuffer[3] & 0xFF );
_fifo_enqueue(u_x.bytebuffer[2] & 0xFF );
_fifo_enqueue(u_x.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_x.bytebuffer[0] & 0xFF );

// parameter y
union u_y_t {
double p;
byte bytebuffer[8];
} u_y;
u_y.p = y;
_fifo_enqueue(u_y.bytebuffer[7] & 0xFF );
_fifo_enqueue(u_y.bytebuffer[6] & 0xFF );
_fifo_enqueue(u_y.bytebuffer[5] & 0xFF );
_fifo_enqueue(u_y.bytebuffer[4] & 0xFF );
_fifo_enqueue(u_y.bytebuffer[3] & 0xFF );
_fifo_enqueue(u_y.bytebuffer[2] & 0xFF );
_fifo_enqueue(u_y.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_y.bytebuffer[0] & 0xFF );

// parameter z
union u_z_t {
double p;
byte bytebuffer[8];
} u_z;
u_z.p = z;
_fifo_enqueue(u_z.bytebuffer[7] & 0xFF );
_fifo_enqueue(u_z.bytebuffer[6] & 0xFF );
_fifo_enqueue(u_z.bytebuffer[5] & 0xFF );
_fifo_enqueue(u_z.bytebuffer[4] & 0xFF );
_fifo_enqueue(u_z.bytebuffer[3] & 0xFF );
_fifo_enqueue(u_z.bytebuffer[2] & 0xFF );
_fifo_enqueue(u_z.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_z.bytebuffer[0] & 0xFF );

// parameter separation
union u_separation_t {
double p;
byte bytebuffer[8];
} u_separation;
u_separation.p = separation;
_fifo_enqueue(u_separation.bytebuffer[7] & 0xFF );
_fifo_enqueue(u_separation.bytebuffer[6] & 0xFF );
_fifo_enqueue(u_separation.bytebuffer[5] & 0xFF );
_fifo_enqueue(u_separation.bytebuffer[4] & 0xFF );
_fifo_enqueue(u_separation.bytebuffer[3] & 0xFF );
_fifo_enqueue(u_separation.bytebuffer[2] & 0xFF );
_fifo_enqueue(u_separation.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_separation.bytebuffer[0] & 0xFF );

// parameter verbose
union u_verbose_t {
uint8_t p;
byte bytebuffer[1];
} u_verbose;
u_verbose.p = verbose;
_fifo_enqueue(u_verbose.bytebuffer[0] & 0xFF );
}
}
// Enqueue of messages Backbone::printer::printOperationState
void enqueue_Backbone_send_printer_printOperationState(struct Backbone_Instance *_instance, uint8_t id, uint8_t verbose){
if ( fifo_byte_available() > 6 ) {

_fifo_enqueue( (48 >> 8) & 0xFF );
_fifo_enqueue( 48 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_printer >> 8) & 0xFF );
_fifo_enqueue( _instance->id_printer & 0xFF );

// parameter id
union u_id_t {
uint8_t p;
byte bytebuffer[1];
} u_id;
u_id.p = id;
_fifo_enqueue(u_id.bytebuffer[0] & 0xFF );

// parameter verbose
union u_verbose_t {
uint8_t p;
byte bytebuffer[1];
} u_verbose;
u_verbose.p = verbose;
_fifo_enqueue(u_verbose.bytebuffer[0] & 0xFF );
}
}
// Enqueue of messages Backbone::printer::printStatus
void enqueue_Backbone_send_printer_printStatus(struct Backbone_Instance *_instance, uint8_t id, uint8_t verbose){
if ( fifo_byte_available() > 6 ) {

_fifo_enqueue( (49 >> 8) & 0xFF );
_fifo_enqueue( 49 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_printer >> 8) & 0xFF );
_fifo_enqueue( _instance->id_printer & 0xFF );

// parameter id
union u_id_t {
uint8_t p;
byte bytebuffer[1];
} u_id;
u_id.p = id;
_fifo_enqueue(u_id.bytebuffer[0] & 0xFF );

// parameter verbose
union u_verbose_t {
uint8_t p;
byte bytebuffer[1];
} u_verbose;
u_verbose.p = verbose;
_fifo_enqueue(u_verbose.bytebuffer[0] & 0xFF );
}
}
// Enqueue of messages Backbone::serialRead::waitcalibration
void enqueue_Backbone_send_serialRead_waitcalibration(struct Backbone_Instance *_instance){
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (50 >> 8) & 0xFF );
_fifo_enqueue( 50 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_serialRead >> 8) & 0xFF );
_fifo_enqueue( _instance->id_serialRead & 0xFF );
}
}
// Enqueue of messages Backbone::pixel::statusID
void enqueue_Backbone_send_pixel_statusID(struct Backbone_Instance *_instance, uint8_t id){
if ( fifo_byte_available() > 5 ) {

_fifo_enqueue( (51 >> 8) & 0xFF );
_fifo_enqueue( 51 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_pixel >> 8) & 0xFF );
_fifo_enqueue( _instance->id_pixel & 0xFF );

// parameter id
union u_id_t {
uint8_t p;
byte bytebuffer[1];
} u_id;
u_id.p = id;
_fifo_enqueue(u_id.bytebuffer[0] & 0xFF );
}
}
// Enqueue of messages Backbone::pixel::stateID
void enqueue_Backbone_send_pixel_stateID(struct Backbone_Instance *_instance, uint8_t id){
if ( fifo_byte_available() > 5 ) {

_fifo_enqueue( (52 >> 8) & 0xFF );
_fifo_enqueue( 52 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_pixel >> 8) & 0xFF );
_fifo_enqueue( _instance->id_pixel & 0xFF );

// parameter id
union u_id_t {
uint8_t p;
byte bytebuffer[1];
} u_id;
u_id.p = id;
_fifo_enqueue(u_id.bytebuffer[0] & 0xFF );
}
}
// Enqueue of messages Backbone::StateHandler::currentState
void enqueue_Backbone_send_StateHandler_currentState(struct Backbone_Instance *_instance, uint8_t id){
if ( fifo_byte_available() > 5 ) {

_fifo_enqueue( (53 >> 8) & 0xFF );
_fifo_enqueue( 53 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_StateHandler >> 8) & 0xFF );
_fifo_enqueue( _instance->id_StateHandler & 0xFF );

// parameter id
union u_id_t {
uint8_t p;
byte bytebuffer[1];
} u_id;
u_id.p = id;
_fifo_enqueue(u_id.bytebuffer[0] & 0xFF );
}
}
// Enqueue of messages Backbone::transitions::toIdle
void enqueue_Backbone_send_transitions_toIdle(struct Backbone_Instance *_instance){
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (54 >> 8) & 0xFF );
_fifo_enqueue( 54 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_transitions >> 8) & 0xFF );
_fifo_enqueue( _instance->id_transitions & 0xFF );
}
}
// Enqueue of messages Blinker::evt::blink
void enqueue_Blinker_send_evt_blink(struct Blinker_Instance *_instance){
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (55 >> 8) & 0xFF );
_fifo_enqueue( 55 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_evt >> 8) & 0xFF );
_fifo_enqueue( _instance->id_evt & 0xFF );
}
}


//New dispatcher for messages
void dispatch_errvalidate(uint16_t sender) {
if (sender == backbone_var.id_transitions) {

}
if (sender == button_var.id_clock) {

}
if (sender == softButton_var.id_Timer) {

}
if (sender == calibrator_var.id_avt) {

}
if (sender == calibrationValidator_var.id_avt) {

}
if (sender == blinker_var.id_evt) {

}
if (sender == backbone_var.id_StateHandler) {

}
if (sender == pulseReader_var.id_Transitions) {

}
if (sender == angleReader_var.id_Transitions) {

}
if (sender == serialIn_var.id_Timer) {

}
if (sender == calibrationValidator_var.id_validator) {
Backbone_handle_validator_errvalidate(&backbone_var);

}
if (sender == calibrationStorer_var.id_progress) {

}

}


//New dispatcher for messages
void dispatch_configRead(uint16_t sender, double param_bx, double param_by, double param_bz, double param_brx, double param_bry, double param_brz, double param_cx, double param_cy, double param_cz, double param_crx, double param_cry, double param_crz) {
if (sender == backbone_var.id_transitions) {

}
if (sender == button_var.id_clock) {

}
if (sender == softButton_var.id_Timer) {

}
if (sender == calibrator_var.id_avt) {

}
if (sender == calibrationValidator_var.id_avt) {

}
if (sender == storer_var.id_reader) {
CalibrationStorer_handle_storeReader_configRead(&calibrationStorer_var, param_bx, param_by, param_bz, param_brx, param_bry, param_brz, param_cx, param_cy, param_cz, param_crx, param_cry, param_crz);

}
if (sender == blinker_var.id_evt) {

}
if (sender == backbone_var.id_StateHandler) {

}
if (sender == pulseReader_var.id_Transitions) {

}
if (sender == angleReader_var.id_Transitions) {

}
if (sender == serialIn_var.id_Timer) {

}
if (sender == calibrationStorer_var.id_progress) {

}

}


//New dispatcher for messages
void dispatch_recalibrate(uint16_t sender) {
if (sender == backbone_var.id_transitions) {

}
if (sender == button_var.id_clock) {

}
if (sender == softButton_var.id_Timer) {

}
if (sender == calibrator_var.id_avt) {

}
if (sender == calibrationValidator_var.id_avt) {

}
if (sender == blinker_var.id_evt) {

}
if (sender == backbone_var.id_StateHandler) {

}
if (sender == pulseReader_var.id_Transitions) {

}
if (sender == angleReader_var.id_Transitions) {
AngleReader_handle_Transitions_recalibrate(&angleReader_var);

}
if (sender == serialIn_var.id_Timer) {

}
if (sender == calibrationStorer_var.id_progress) {

}

}


//New dispatcher for messages
void dispatch_load(uint16_t sender) {
if (sender == backbone_var.id_CalibrationStorer) {
CalibrationStorer_handle_storer_load(&calibrationStorer_var);

}
if (sender == backbone_var.id_transitions) {

}
if (sender == button_var.id_clock) {

}
if (sender == softButton_var.id_Timer) {

}
if (sender == calibrator_var.id_avt) {

}
if (sender == calibrationValidator_var.id_avt) {

}
if (sender == blinker_var.id_evt) {

}
if (sender == backbone_var.id_StateHandler) {

}
if (sender == pulseReader_var.id_Transitions) {

}
if (sender == angleReader_var.id_Transitions) {

}
if (sender == serialIn_var.id_Timer) {

}
if (sender == calibrationStorer_var.id_progress) {

}

}


//New dispatcher for messages
void dispatch_printOperationState(uint16_t sender, uint8_t param_id, uint8_t param_verbose) {
if (sender == backbone_var.id_printer) {
SerialOut_handle_basic_printOperationState(&serial_var, param_id, param_verbose);

}
if (sender == backbone_var.id_transitions) {

}
if (sender == button_var.id_clock) {

}
if (sender == softButton_var.id_Timer) {

}
if (sender == calibrator_var.id_avt) {

}
if (sender == calibrationValidator_var.id_avt) {

}
if (sender == blinker_var.id_evt) {

}
if (sender == backbone_var.id_StateHandler) {

}
if (sender == pulseReader_var.id_Transitions) {

}
if (sender == angleReader_var.id_Transitions) {

}
if (sender == serialIn_var.id_Timer) {

}
if (sender == calibrationStorer_var.id_progress) {

}

}


//New dispatcher for messages
void dispatch_allAngles(uint16_t sender, double param_bh, double param_bv, double param_ch, double param_cv) {
if (sender == backbone_var.id_transitions) {

}
if (sender == button_var.id_clock) {

}
if (sender == softButton_var.id_Timer) {

}
if (sender == angleReader_var.id_AngleSender) {
Backbone_handle_AngleReceiver_allAngles(&backbone_var, param_bh, param_bv, param_ch, param_cv);

}
if (sender == calibrator_var.id_avt) {

}
if (sender == calibrationValidator_var.id_avt) {

}
if (sender == blinker_var.id_evt) {

}
if (sender == backbone_var.id_StateHandler) {

}
if (sender == pulseReader_var.id_Transitions) {

}
if (sender == angleReader_var.id_Transitions) {

}
if (sender == serialIn_var.id_Timer) {

}
if (sender == calibrationStorer_var.id_progress) {

}

}


//New dispatcher for messages
void dispatch_coordinates(uint16_t sender, double param_x, double param_y, double param_z, double param_separation) {
if (sender == backbone_var.id_transitions) {

}
if (sender == button_var.id_clock) {

}
if (sender == softButton_var.id_Timer) {

}
if (sender == calibrator_var.id_avt) {

}
if (sender == calibrationValidator_var.id_avt) {

}
if (sender == runner_var.id_Run) {
Backbone_handle_Run_coordinates(&backbone_var, param_x, param_y, param_z, param_separation);

}
if (sender == blinker_var.id_evt) {

}
if (sender == backbone_var.id_StateHandler) {

}
if (sender == pulseReader_var.id_Transitions) {

}
if (sender == angleReader_var.id_Transitions) {

}
if (sender == serialIn_var.id_Timer) {

}
if (sender == calibrationStorer_var.id_progress) {

}

}


//New dispatcher for messages
void dispatch_currentState(uint16_t sender, uint8_t param_id) {
if (sender == backbone_var.id_transitions) {

}
if (sender == button_var.id_clock) {

}
if (sender == softButton_var.id_Timer) {

}
if (sender == calibrator_var.id_avt) {

}
if (sender == calibrationValidator_var.id_avt) {

}
if (sender == blinker_var.id_evt) {

}
if (sender == backbone_var.id_StateHandler) {
Backbone_handle_StateHandler_currentState(&backbone_var, param_id);

}
if (sender == pulseReader_var.id_Transitions) {

}
if (sender == angleReader_var.id_Transitions) {

}
if (sender == serialIn_var.id_Timer) {

}
if (sender == calibrationStorer_var.id_progress) {

}

}


//New dispatcher for messages
void dispatch_receivecalibration(uint16_t sender, double param_bx, double param_by, double param_bz, double param_brx, double param_bry, double param_brz, double param_cx, double param_cy, double param_cz, double param_crx, double param_cry, double param_crz) {
if (sender == backbone_var.id_transitions) {

}
if (sender == backbone_var.id_calibrator) {

}
if (sender == button_var.id_clock) {

}
if (sender == softButton_var.id_Timer) {

}
if (sender == calibrator_var.id_avt) {

}
if (sender == calibrationValidator_var.id_avt) {

}
if (sender == blinker_var.id_evt) {

}
if (sender == backbone_var.id_StateHandler) {

}
if (sender == pulseReader_var.id_Transitions) {

}
if (sender == angleReader_var.id_Transitions) {

}
if (sender == serialIn_var.id_Timer) {

}
if (sender == calibrationStorer_var.id_progress) {

}

}


//New dispatcher for messages
void dispatch_stopPrinting(uint16_t sender) {
if (sender == backbone_var.id_transitions) {

}
if (sender == button_var.id_clock) {

}
if (sender == softButton_var.id_Timer) {

}
if (sender == calibrator_var.id_avt) {

}
if (sender == calibrationValidator_var.id_avt) {

}
if (sender == blinker_var.id_evt) {

}
if (sender == backbone_var.id_StateHandler) {

}
if (sender == pulseReader_var.id_Transitions) {

}
if (sender == angleReader_var.id_Transitions) {

}
if (sender == serialIn_var.id_Timer) {

}
if (sender == calibrationStorer_var.id_progress) {

}

}


//New dispatcher for messages
void dispatch_calibrationFailed(uint16_t sender) {
if (sender == backbone_var.id_transitions) {

}
if (sender == button_var.id_clock) {

}
if (sender == softButton_var.id_Timer) {

}
if (sender == calibrator_var.id_avt) {
Calibrator_handle_avt_calibrationFailed(&calibrator_var);

}
if (sender == calibrationValidator_var.id_avt) {

}
if (sender == blinker_var.id_evt) {

}
if (sender == backbone_var.id_StateHandler) {

}
if (sender == pulseReader_var.id_Transitions) {

}
if (sender == angleReader_var.id_Transitions) {

}
if (sender == serialIn_var.id_Timer) {

}
if (sender == calibrationStorer_var.id_progress) {

}

}


//New dispatcher for messages
void dispatch_receiveAngles(uint16_t sender, double param_bh, double param_bv, double param_ch, double param_cv) {
if (sender == backbone_var.id_transitions) {

}
if (sender == backbone_var.id_calibrator) {
Calibrator_handle_calibrator_receiveAngles(&calibrator_var, param_bh, param_bv, param_ch, param_cv);

}
if (sender == button_var.id_clock) {

}
if (sender == softButton_var.id_Timer) {

}
if (sender == calibrator_var.id_avt) {

}
if (sender == calibrationValidator_var.id_avt) {

}
if (sender == blinker_var.id_evt) {

}
if (sender == backbone_var.id_StateHandler) {

}
if (sender == pulseReader_var.id_Transitions) {

}
if (sender == angleReader_var.id_Transitions) {

}
if (sender == serialIn_var.id_Timer) {

}
if (sender == calibrationStorer_var.id_progress) {

}

}


//New dispatcher for messages
void dispatch_calibrate(uint16_t sender) {
if (sender == backbone_var.id_transitions) {

}
if (sender == backbone_var.id_calibrator) {
Calibrator_handle_calibrator_calibrate(&calibrator_var);

}
if (sender == button_var.id_clock) {

}
if (sender == softButton_var.id_Timer) {

}
if (sender == calibrator_var.id_avt) {

}
if (sender == calibrationValidator_var.id_avt) {

}
if (sender == blinker_var.id_evt) {

}
if (sender == backbone_var.id_StateHandler) {

}
if (sender == pulseReader_var.id_Transitions) {

}
if (sender == angleReader_var.id_Transitions) {

}
if (sender == serialIn_var.id_Timer) {

}
if (sender == calibrationStorer_var.id_progress) {

}

}


//New dispatcher for messages
void dispatch_byteWritten(uint16_t sender) {
if (sender == backbone_var.id_transitions) {

}
if (sender == button_var.id_clock) {

}
if (sender == softButton_var.id_Timer) {

}
if (sender == calibrator_var.id_avt) {

}
if (sender == calibrationValidator_var.id_avt) {

}
if (sender == blinker_var.id_evt) {

}
if (sender == backbone_var.id_StateHandler) {

}
if (sender == pulseReader_var.id_Transitions) {

}
if (sender == angleReader_var.id_Transitions) {

}
if (sender == serialIn_var.id_Timer) {

}
if (sender == storer_var.id_writer) {

}
if (sender == calibrationStorer_var.id_progress) {

}

}


//New dispatcher for messages
void dispatch_printStatus(uint16_t sender, uint8_t param_id, uint8_t param_verbose) {
if (sender == backbone_var.id_printer) {
SerialOut_handle_basic_printStatus(&serial_var, param_id, param_verbose);

}
if (sender == backbone_var.id_transitions) {

}
if (sender == button_var.id_clock) {

}
if (sender == softButton_var.id_Timer) {

}
if (sender == calibrator_var.id_avt) {

}
if (sender == calibrationValidator_var.id_avt) {

}
if (sender == blinker_var.id_evt) {

}
if (sender == backbone_var.id_StateHandler) {

}
if (sender == pulseReader_var.id_Transitions) {

}
if (sender == angleReader_var.id_Transitions) {

}
if (sender == serialIn_var.id_Timer) {

}
if (sender == calibrationStorer_var.id_progress) {

}

}


//New dispatcher for messages
void dispatch_calibrating(uint16_t sender) {
if (sender == backbone_var.id_transitions) {

}
if (sender == button_var.id_clock) {

}
if (sender == softButton_var.id_Timer) {

}
if (sender == calibrator_var.id_avt) {
Calibrator_handle_avt_calibrating(&calibrator_var);

}
if (sender == calibrationValidator_var.id_avt) {

}
if (sender == blinker_var.id_evt) {

}
if (sender == backbone_var.id_StateHandler) {

}
if (sender == pulseReader_var.id_Transitions) {

}
if (sender == angleReader_var.id_Transitions) {

}
if (sender == serialIn_var.id_Timer) {

}
if (sender == calibrationStorer_var.id_progress) {

}

}


//New dispatcher for messages
void dispatch_byteRead(uint16_t sender, uint8_t param_val) {
if (sender == backbone_var.id_transitions) {

}
if (sender == button_var.id_clock) {

}
if (sender == softButton_var.id_Timer) {

}
if (sender == calibrator_var.id_avt) {

}
if (sender == calibrationValidator_var.id_avt) {

}
if (sender == storer_var.id_reader) {
CalibrationStorer_handle_storeReader_byteRead(&calibrationStorer_var, param_val);

}
if (sender == blinker_var.id_evt) {

}
if (sender == backbone_var.id_StateHandler) {

}
if (sender == pulseReader_var.id_Transitions) {

}
if (sender == angleReader_var.id_Transitions) {

}
if (sender == serialIn_var.id_Timer) {

}
if (sender == calibrationStorer_var.id_progress) {

}

}


//New dispatcher for messages
void dispatch_storerToIdle(uint16_t sender) {
if (sender == backbone_var.id_transitions) {

}
if (sender == button_var.id_clock) {

}
if (sender == softButton_var.id_Timer) {

}
if (sender == calibrator_var.id_avt) {

}
if (sender == calibrationValidator_var.id_avt) {

}
if (sender == blinker_var.id_evt) {

}
if (sender == backbone_var.id_StateHandler) {

}
if (sender == pulseReader_var.id_Transitions) {

}
if (sender == angleReader_var.id_Transitions) {

}
if (sender == serialIn_var.id_Timer) {

}
if (sender == calibrationStorer_var.id_progress) {
CalibrationStorer_handle_progress_storerToIdle(&calibrationStorer_var);

}

}


//New dispatcher for messages
void dispatch_toIdle(uint16_t sender) {
if (sender == backbone_var.id_transitions) {

}
if (sender == button_var.id_clock) {

}
if (sender == softButton_var.id_Timer) {

}
if (sender == calibrator_var.id_avt) {

}
if (sender == calibrationValidator_var.id_avt) {

}
if (sender == blinker_var.id_evt) {

}
if (sender == backbone_var.id_StateHandler) {

}
if (sender == pulseReader_var.id_Transitions) {

}
if (sender == angleReader_var.id_Transitions) {

}
if (sender == serialIn_var.id_Timer) {

}
if (sender == calibrationStorer_var.id_progress) {

}

}


//New dispatcher for messages
void dispatch_startPrinting(uint16_t sender) {
if (sender == backbone_var.id_transitions) {

}
if (sender == button_var.id_clock) {

}
if (sender == softButton_var.id_Timer) {

}
if (sender == calibrator_var.id_avt) {

}
if (sender == calibrationValidator_var.id_avt) {

}
if (sender == blinker_var.id_evt) {

}
if (sender == backbone_var.id_StateHandler) {

}
if (sender == pulseReader_var.id_Transitions) {

}
if (sender == angleReader_var.id_Transitions) {

}
if (sender == serialIn_var.id_Timer) {

}
if (sender == calibrationStorer_var.id_progress) {

}

}


//New dispatcher for messages
void dispatch_packageDetectedEvent(uint16_t sender, uint32_t param_startTimeL1, uint32_t param_startTimeL2, uint32_t param_durationL1, uint32_t param_durationL2, uint32_t param_signal) {
if (sender == backbone_var.id_transitions) {

}
if (sender == packageReader_var.id_PackageSender) {
AngleReader_handle_PackageReceiver_packageDetectedEvent(&angleReader_var, param_startTimeL1, param_startTimeL2, param_durationL1, param_durationL2, param_signal);

}
if (sender == button_var.id_clock) {

}
if (sender == softButton_var.id_Timer) {

}
if (sender == calibrator_var.id_avt) {

}
if (sender == calibrationValidator_var.id_avt) {

}
if (sender == blinker_var.id_evt) {

}
if (sender == backbone_var.id_StateHandler) {

}
if (sender == pulseReader_var.id_Transitions) {

}
if (sender == angleReader_var.id_Transitions) {

}
if (sender == serialIn_var.id_Timer) {

}
if (sender == calibrationStorer_var.id_progress) {

}

}


//New dispatcher for messages
void dispatch_status(uint16_t sender, uint8_t param_id) {
if (sender == softButton_var.id_Timer) {

}
if (sender == calibrationValidator_var.id_avt) {

}
if (sender == runner_var.id_StatusSender) {
Backbone_handle_StatusHandler_status(&backbone_var, param_id);

}
if (sender == backbone_var.id_StateHandler) {

}
if (sender == serialIn_var.id_Timer) {

}
if (sender == backbone_var.id_transitions) {

}
if (sender == angleReader_var.id_StatusSender) {
Backbone_handle_StatusHandler_status(&backbone_var, param_id);

}
if (sender == calibrator_var.id_StatusSender) {
Backbone_handle_StatusHandler_status(&backbone_var, param_id);

}
if (sender == button_var.id_clock) {

}
if (sender == calibrator_var.id_avt) {

}
if (sender == packageReader_var.id_StatusSender) {
Backbone_handle_StatusHandler_status(&backbone_var, param_id);

}
if (sender == blinker_var.id_evt) {

}
if (sender == pulseReader_var.id_Transitions) {

}
if (sender == angleReader_var.id_Transitions) {

}
if (sender == calibrationStorer_var.id_progress) {

}

}


//New dispatcher for messages
void dispatch_timerOverflow(uint16_t sender) {
if (sender == backbone_var.id_transitions) {

}
if (sender == button_var.id_clock) {

}
if (sender == softButton_var.id_Timer) {

}
if (sender == calibrator_var.id_avt) {

}
if (sender == calibrationValidator_var.id_avt) {

}
if (sender == blinker_var.id_evt) {

}
if (sender == backbone_var.id_StateHandler) {

}
if (sender == pulseReader_var.id_OverflowNotifier) {
AngleReader_handle_OverflowNotifier_timerOverflow(&angleReader_var);

}
if (sender == pulseReader_var.id_Transitions) {

}
if (sender == angleReader_var.id_Transitions) {

}
if (sender == serialIn_var.id_Timer) {

}
if (sender == calibrationStorer_var.id_progress) {

}

}


//New dispatcher for messages
void dispatch_printPoint(uint16_t sender, double param_x, double param_y, double param_z, double param_separation, uint8_t param_verbose) {
if (sender == backbone_var.id_printer) {
SerialOut_handle_basic_printPoint(&serial_var, param_x, param_y, param_z, param_separation, param_verbose);

}
if (sender == backbone_var.id_transitions) {

}
if (sender == button_var.id_clock) {

}
if (sender == softButton_var.id_Timer) {

}
if (sender == calibrator_var.id_avt) {

}
if (sender == calibrationValidator_var.id_avt) {

}
if (sender == blinker_var.id_evt) {

}
if (sender == backbone_var.id_StateHandler) {

}
if (sender == pulseReader_var.id_Transitions) {

}
if (sender == angleReader_var.id_Transitions) {

}
if (sender == serialIn_var.id_Timer) {

}
if (sender == calibrationStorer_var.id_progress) {

}

}


//New dispatcher for messages
void dispatch_writeByte(uint16_t sender, uint8_t param_id, uint8_t param_val) {
if (sender == backbone_var.id_transitions) {

}
if (sender == button_var.id_clock) {

}
if (sender == softButton_var.id_Timer) {

}
if (sender == calibrator_var.id_avt) {

}
if (sender == calibrationValidator_var.id_avt) {

}
if (sender == blinker_var.id_evt) {

}
if (sender == backbone_var.id_StateHandler) {

}
if (sender == calibrationStorer_var.id_storeWriter) {
Storer_handle_writer_writeByte(&storer_var, param_id, param_val);

}
if (sender == pulseReader_var.id_Transitions) {

}
if (sender == angleReader_var.id_Transitions) {

}
if (sender == serialIn_var.id_Timer) {

}
if (sender == calibrationStorer_var.id_progress) {

}

}


//New dispatcher for messages
void dispatch_startTimeCalibrated(uint16_t sender) {
if (sender == backbone_var.id_transitions) {

}
if (sender == button_var.id_clock) {

}
if (sender == softButton_var.id_Timer) {

}
if (sender == calibrator_var.id_avt) {

}
if (sender == calibrationValidator_var.id_avt) {

}
if (sender == blinker_var.id_evt) {

}
if (sender == backbone_var.id_StateHandler) {

}
if (sender == pulseReader_var.id_Transitions) {

}
if (sender == angleReader_var.id_Transitions) {
AngleReader_handle_Transitions_startTimeCalibrated(&angleReader_var);

}
if (sender == serialIn_var.id_Timer) {

}
if (sender == calibrationStorer_var.id_progress) {

}

}


//New dispatcher for messages
void dispatch_ms25_tic(uint16_t sender) {
if (sender == backbone_var.id_transitions) {

}
if (sender == button_var.id_clock) {
Button_handle_clock_ms25_tic(&button_var);

}
if (sender == softButton_var.id_Timer) {

}
if (sender == calibrator_var.id_avt) {

}
if (sender == calibrationValidator_var.id_avt) {

}
if (sender == blinker_var.id_evt) {

}
if (sender == backbone_var.id_StateHandler) {

}
if (sender == pulseReader_var.id_Transitions) {

}
if (sender == angleReader_var.id_Transitions) {

}
if (sender == serialIn_var.id_Timer) {

}
if (sender == calibrationStorer_var.id_progress) {

}

}


//New dispatcher for messages
void dispatch_readByte(uint16_t sender, uint8_t param_id) {
if (sender == backbone_var.id_transitions) {

}
if (sender == button_var.id_clock) {

}
if (sender == softButton_var.id_Timer) {

}
if (sender == calibrator_var.id_avt) {

}
if (sender == calibrationValidator_var.id_avt) {

}
if (sender == blinker_var.id_evt) {

}
if (sender == calibrationStorer_var.id_storeReader) {
Storer_handle_reader_readByte(&storer_var, param_id);

}
if (sender == backbone_var.id_StateHandler) {

}
if (sender == pulseReader_var.id_Transitions) {

}
if (sender == angleReader_var.id_Transitions) {

}
if (sender == serialIn_var.id_Timer) {

}
if (sender == calibrationStorer_var.id_progress) {

}

}


//New dispatcher for messages
void dispatch_endvalidate(uint16_t sender) {
if (sender == backbone_var.id_transitions) {

}
if (sender == button_var.id_clock) {

}
if (sender == softButton_var.id_Timer) {

}
if (sender == calibrator_var.id_avt) {

}
if (sender == calibrationValidator_var.id_avt) {

}
if (sender == blinker_var.id_evt) {

}
if (sender == backbone_var.id_StateHandler) {

}
if (sender == pulseReader_var.id_Transitions) {

}
if (sender == angleReader_var.id_Transitions) {

}
if (sender == serialIn_var.id_Timer) {

}
if (sender == calibrationValidator_var.id_validator) {
Backbone_handle_validator_endvalidate(&backbone_var);

}
if (sender == calibrationStorer_var.id_progress) {

}

}


//New dispatcher for messages
void dispatch_stateID(uint16_t sender, uint8_t param_id) {
if (sender == backbone_var.id_transitions) {

}
if (sender == backbone_var.id_pixel) {
Blinker_handle_neopixel_stateID(&blinker_var, param_id);

}
if (sender == button_var.id_clock) {

}
if (sender == softButton_var.id_Timer) {

}
if (sender == calibrator_var.id_avt) {

}
if (sender == calibrationValidator_var.id_avt) {

}
if (sender == blinker_var.id_evt) {

}
if (sender == backbone_var.id_StateHandler) {

}
if (sender == pulseReader_var.id_Transitions) {

}
if (sender == angleReader_var.id_Transitions) {

}
if (sender == serialIn_var.id_Timer) {

}
if (sender == calibrationStorer_var.id_progress) {

}

}


//New dispatcher for messages
void dispatch_positionCoordinates(uint16_t sender, double param_x, double param_y, double param_z) {
if (sender == backbone_var.id_transitions) {

}
if (sender == button_var.id_clock) {

}
if (sender == softButton_var.id_Timer) {

}
if (sender == calibrator_var.id_avt) {

}
if (sender == calibrationValidator_var.id_avt) {

}
if (sender == blinker_var.id_evt) {

}
if (sender == backbone_var.id_StateHandler) {

}
if (sender == pulseReader_var.id_Transitions) {

}
if (sender == angleReader_var.id_Transitions) {

}
if (sender == serialIn_var.id_Timer) {

}
if (sender == calibrationStorer_var.id_progress) {

}

}


//New dispatcher for messages
void dispatch_endload(uint16_t sender) {
if (sender == backbone_var.id_transitions) {

}
if (sender == button_var.id_clock) {

}
if (sender == softButton_var.id_Timer) {

}
if (sender == calibrator_var.id_avt) {

}
if (sender == calibrationValidator_var.id_avt) {

}
if (sender == calibrationStorer_var.id_storer) {
Backbone_handle_CalibrationStorer_endload(&backbone_var);

}
if (sender == blinker_var.id_evt) {

}
if (sender == backbone_var.id_StateHandler) {

}
if (sender == pulseReader_var.id_Transitions) {

}
if (sender == angleReader_var.id_Transitions) {

}
if (sender == serialIn_var.id_Timer) {

}
if (sender == calibrationStorer_var.id_progress) {

}

}


//New dispatcher for messages
void dispatch_errcalibrate(uint16_t sender) {
if (sender == backbone_var.id_transitions) {

}
if (sender == button_var.id_clock) {

}
if (sender == softButton_var.id_Timer) {

}
if (sender == calibrator_var.id_avt) {

}
if (sender == calibrationValidator_var.id_avt) {

}
if (sender == blinker_var.id_evt) {

}
if (sender == calibrator_var.id_calibrator) {
Backbone_handle_calibrator_errcalibrate(&backbone_var);

}
if (sender == backbone_var.id_StateHandler) {

}
if (sender == pulseReader_var.id_Transitions) {

}
if (sender == angleReader_var.id_Transitions) {

}
if (sender == serialIn_var.id_Timer) {

}
if (sender == calibrationStorer_var.id_progress) {

}

}


//New dispatcher for messages
void dispatch_pulseDetected(uint16_t sender, uint32_t param_start, uint32_t param_duration) {
if (sender == backbone_var.id_transitions) {

}
if (sender == button_var.id_clock) {

}
if (sender == softButton_var.id_Timer) {

}
if (sender == calibrator_var.id_avt) {

}
if (sender == calibrationValidator_var.id_avt) {

}
if (sender == blinker_var.id_evt) {

}
if (sender == backbone_var.id_StateHandler) {

}
if (sender == pulseReader_var.id_Transitions) {
PulseReader_handle_Transitions_pulseDetected(&pulseReader_var, param_start, param_duration);

}
if (sender == angleReader_var.id_Transitions) {

}
if (sender == serialIn_var.id_Timer) {

}
if (sender == calibrationStorer_var.id_progress) {

}

}


//New dispatcher for messages
void dispatch_errorload(uint16_t sender) {
if (sender == backbone_var.id_transitions) {

}
if (sender == button_var.id_clock) {

}
if (sender == softButton_var.id_Timer) {

}
if (sender == calibrator_var.id_avt) {

}
if (sender == calibrationValidator_var.id_avt) {

}
if (sender == calibrationStorer_var.id_storer) {
Backbone_handle_CalibrationStorer_errorload(&backbone_var);

}
if (sender == blinker_var.id_evt) {

}
if (sender == backbone_var.id_StateHandler) {

}
if (sender == pulseReader_var.id_Transitions) {

}
if (sender == angleReader_var.id_Transitions) {

}
if (sender == serialIn_var.id_Timer) {

}
if (sender == calibrationStorer_var.id_progress) {

}

}


//New dispatcher for messages
void dispatch_pulseDetectedEvent(uint16_t sender, uint32_t param_start, uint32_t param_duration) {
if (sender == backbone_var.id_transitions) {

}
if (sender == button_var.id_clock) {

}
if (sender == softButton_var.id_Timer) {

}
if (sender == calibrator_var.id_avt) {

}
if (sender == calibrationValidator_var.id_avt) {

}
if (sender == blinker_var.id_evt) {

}
if (sender == backbone_var.id_StateHandler) {

}
if (sender == pulseReader_var.id_Transitions) {

}
if (sender == angleReader_var.id_Transitions) {

}
if (sender == serialIn_var.id_Timer) {

}
if (sender == pulseReader_var.id_PulseSender) {
PackageReader_handle_PulseReceiver_pulseDetectedEvent(&packageReader_var, param_start, param_duration);

}
if (sender == calibrationStorer_var.id_progress) {

}

}


//New dispatcher for messages
void dispatch_blink(uint16_t sender) {
if (sender == backbone_var.id_transitions) {

}
if (sender == button_var.id_clock) {

}
if (sender == softButton_var.id_Timer) {

}
if (sender == calibrator_var.id_avt) {

}
if (sender == calibrationValidator_var.id_avt) {

}
if (sender == blinker_var.id_evt) {
Blinker_handle_evt_blink(&blinker_var);

}
if (sender == backbone_var.id_StateHandler) {

}
if (sender == pulseReader_var.id_Transitions) {

}
if (sender == angleReader_var.id_Transitions) {

}
if (sender == serialIn_var.id_Timer) {

}
if (sender == calibrationStorer_var.id_progress) {

}

}


//New dispatcher for messages
void dispatch_writeConfig(uint16_t sender, double param_bx, double param_by, double param_bz, double param_brx, double param_bry, double param_brz, double param_cx, double param_cy, double param_cz, double param_crx, double param_cry, double param_crz) {
if (sender == backbone_var.id_transitions) {

}
if (sender == button_var.id_clock) {

}
if (sender == softButton_var.id_Timer) {

}
if (sender == calibrator_var.id_avt) {

}
if (sender == calibrationValidator_var.id_avt) {

}
if (sender == blinker_var.id_evt) {

}
if (sender == backbone_var.id_StateHandler) {

}
if (sender == calibrationStorer_var.id_storeWriter) {
Storer_handle_writer_writeConfig(&storer_var, param_bx, param_by, param_bz, param_brx, param_bry, param_brz, param_cx, param_cy, param_cz, param_crx, param_cry, param_crz);

}
if (sender == pulseReader_var.id_Transitions) {

}
if (sender == angleReader_var.id_Transitions) {

}
if (sender == serialIn_var.id_Timer) {

}
if (sender == calibrationStorer_var.id_progress) {

}

}


//New dispatcher for messages
void dispatch_save(uint16_t sender) {
if (sender == backbone_var.id_CalibrationStorer) {
CalibrationStorer_handle_storer_save(&calibrationStorer_var);

}
if (sender == backbone_var.id_transitions) {

}
if (sender == button_var.id_clock) {

}
if (sender == softButton_var.id_Timer) {

}
if (sender == calibrator_var.id_avt) {

}
if (sender == calibrationValidator_var.id_avt) {

}
if (sender == blinker_var.id_evt) {

}
if (sender == backbone_var.id_StateHandler) {

}
if (sender == pulseReader_var.id_Transitions) {

}
if (sender == angleReader_var.id_Transitions) {

}
if (sender == serialIn_var.id_Timer) {

}
if (sender == calibrationStorer_var.id_progress) {

}

}


//New dispatcher for messages
void dispatch_serial_timeout(uint16_t sender) {
if (sender == backbone_var.id_transitions) {

}
if (sender == button_var.id_clock) {

}
if (sender == softButton_var.id_Timer) {

}
if (sender == calibrator_var.id_avt) {

}
if (sender == calibrationValidator_var.id_avt) {

}
if (sender == blinker_var.id_evt) {

}
if (sender == backbone_var.id_StateHandler) {

}
if (sender == pulseReader_var.id_Transitions) {

}
if (sender == angleReader_var.id_Transitions) {

}
if (sender == serialIn_var.id_Timer) {
SerialIn_handle_Timer_serial_timeout(&serialIn_var);

}
if (sender == calibrationStorer_var.id_progress) {

}

}


//New dispatcher for messages
void dispatch_double_click(uint16_t sender) {
if (sender == backbone_var.id_transitions) {

}
if (sender == button_var.id_clock) {

}
if (sender == softButton_var.id_Timer) {

}
if (sender == calibrator_var.id_avt) {

}
if (sender == calibrationValidator_var.id_avt) {

}
if (sender == blinker_var.id_evt) {

}
if (sender == backbone_var.id_StateHandler) {

}
if (sender == pulseReader_var.id_Transitions) {

}
if (sender == softButton_var.id_SoftButton) {
Backbone_handle_presser_double_click(&backbone_var);

}
if (sender == angleReader_var.id_Transitions) {

}
if (sender == serialIn_var.id_Timer) {

}
if (sender == calibrationStorer_var.id_progress) {

}

}


//New dispatcher for messages
void dispatch_entrypoint(uint16_t sender) {
if (sender == backbone_var.id_transitions) {

}
if (sender == backbone_var.id_calibrator) {
Calibrator_handle_calibrator_entrypoint(&calibrator_var);

}
if (sender == button_var.id_clock) {

}
if (sender == softButton_var.id_Timer) {

}
if (sender == calibrator_var.id_avt) {

}
if (sender == calibrationValidator_var.id_avt) {

}
if (sender == blinker_var.id_evt) {

}
if (sender == backbone_var.id_StateHandler) {

}
if (sender == pulseReader_var.id_Transitions) {

}
if (sender == angleReader_var.id_Transitions) {

}
if (sender == serialIn_var.id_Timer) {

}
if (sender == calibrationStorer_var.id_progress) {

}

}


//New dispatcher for messages
void dispatch_validating(uint16_t sender) {
if (sender == backbone_var.id_transitions) {

}
if (sender == button_var.id_clock) {

}
if (sender == softButton_var.id_Timer) {

}
if (sender == calibrator_var.id_avt) {

}
if (sender == calibrationValidator_var.id_avt) {

}
if (sender == blinker_var.id_evt) {

}
if (sender == backbone_var.id_StateHandler) {

}
if (sender == pulseReader_var.id_Transitions) {

}
if (sender == angleReader_var.id_Transitions) {

}
if (sender == serialIn_var.id_Timer) {

}
if (sender == calibrationStorer_var.id_progress) {

}

}


//New dispatcher for messages
void dispatch_click(uint16_t sender) {
if (sender == backbone_var.id_transitions) {

}
if (sender == button_var.id_clock) {

}
if (sender == softButton_var.id_Timer) {

}
if (sender == calibrator_var.id_avt) {

}
if (sender == calibrationValidator_var.id_avt) {

}
if (sender == blinker_var.id_evt) {

}
if (sender == backbone_var.id_StateHandler) {

}
if (sender == pulseReader_var.id_Transitions) {

}
if (sender == softButton_var.id_SoftButton) {
Backbone_handle_presser_click(&backbone_var);

}
if (sender == angleReader_var.id_Transitions) {

}
if (sender == serialIn_var.id_Timer) {

}
if (sender == calibrationStorer_var.id_progress) {

}

}


//New dispatcher for messages
void dispatch_waitcalibration(uint16_t sender) {
if (sender == backbone_var.id_transitions) {

}
if (sender == button_var.id_clock) {

}
if (sender == softButton_var.id_Timer) {

}
if (sender == calibrator_var.id_avt) {

}
if (sender == calibrationValidator_var.id_avt) {

}
if (sender == blinker_var.id_evt) {

}
if (sender == backbone_var.id_StateHandler) {

}
if (sender == pulseReader_var.id_Transitions) {

}
if (sender == angleReader_var.id_Transitions) {

}
if (sender == serialIn_var.id_Timer) {

}
if (sender == backbone_var.id_serialRead) {
SerialIn_handle_serialcall_waitcalibration(&serialIn_var);

}
if (sender == calibrationStorer_var.id_progress) {

}

}


//New dispatcher for messages
void dispatch_validate(uint16_t sender) {
if (sender == backbone_var.id_transitions) {

}
if (sender == button_var.id_clock) {

}
if (sender == softButton_var.id_Timer) {

}
if (sender == backbone_var.id_validator) {
CalibrationValidator_handle_validator_validate(&calibrationValidator_var);

}
if (sender == calibrator_var.id_avt) {

}
if (sender == calibrationValidator_var.id_avt) {

}
if (sender == blinker_var.id_evt) {

}
if (sender == backbone_var.id_StateHandler) {

}
if (sender == pulseReader_var.id_Transitions) {

}
if (sender == angleReader_var.id_Transitions) {

}
if (sender == serialIn_var.id_Timer) {

}
if (sender == calibrationStorer_var.id_progress) {

}

}


//New dispatcher for messages
void dispatch_calibrationComplete(uint16_t sender) {
if (sender == backbone_var.id_transitions) {

}
if (sender == button_var.id_clock) {

}
if (sender == softButton_var.id_Timer) {

}
if (sender == calibrator_var.id_avt) {
Calibrator_handle_avt_calibrationComplete(&calibrator_var);

}
if (sender == calibrationValidator_var.id_avt) {

}
if (sender == blinker_var.id_evt) {

}
if (sender == backbone_var.id_StateHandler) {

}
if (sender == pulseReader_var.id_Transitions) {

}
if (sender == angleReader_var.id_Transitions) {

}
if (sender == serialIn_var.id_Timer) {

}
if (sender == calibrationStorer_var.id_progress) {

}

}


//New dispatcher for messages
void dispatch_configWritten(uint16_t sender) {
if (sender == backbone_var.id_transitions) {

}
if (sender == button_var.id_clock) {

}
if (sender == softButton_var.id_Timer) {

}
if (sender == calibrator_var.id_avt) {

}
if (sender == calibrationValidator_var.id_avt) {

}
if (sender == blinker_var.id_evt) {

}
if (sender == backbone_var.id_StateHandler) {

}
if (sender == pulseReader_var.id_Transitions) {

}
if (sender == angleReader_var.id_Transitions) {

}
if (sender == serialIn_var.id_Timer) {

}
if (sender == storer_var.id_writer) {
CalibrationStorer_handle_storeWriter_configWritten(&calibrationStorer_var);

}
if (sender == calibrationStorer_var.id_progress) {

}

}


//New dispatcher for messages
void dispatch_timer_timeout(uint16_t sender) {
if (sender == backbone_var.id_transitions) {

}
if (sender == button_var.id_clock) {

}
if (sender == softButton_var.id_Timer) {
SoftButton_handle_Timer_timer_timeout(&softButton_var);

}
if (sender == calibrator_var.id_avt) {

}
if (sender == calibrationValidator_var.id_avt) {

}
if (sender == blinker_var.id_evt) {

}
if (sender == backbone_var.id_StateHandler) {

}
if (sender == pulseReader_var.id_Transitions) {

}
if (sender == angleReader_var.id_Transitions) {

}
if (sender == serialIn_var.id_Timer) {

}
if (sender == calibrationStorer_var.id_progress) {

}

}


//New dispatcher for messages
void dispatch_calibrationfromserial(uint16_t sender) {
if (sender == backbone_var.id_transitions) {

}
if (sender == button_var.id_clock) {

}
if (sender == softButton_var.id_Timer) {

}
if (sender == calibrator_var.id_avt) {

}
if (sender == calibrationValidator_var.id_avt) {

}
if (sender == blinker_var.id_evt) {

}
if (sender == calibrator_var.id_calibrator) {

}
if (sender == backbone_var.id_StateHandler) {

}
if (sender == pulseReader_var.id_Transitions) {

}
if (sender == angleReader_var.id_Transitions) {

}
if (sender == serialIn_var.id_Timer) {

}
if (sender == calibrationStorer_var.id_progress) {

}

}


//New dispatcher for messages
void dispatch_readConfig(uint16_t sender) {
if (sender == backbone_var.id_transitions) {

}
if (sender == button_var.id_clock) {

}
if (sender == softButton_var.id_Timer) {

}
if (sender == calibrator_var.id_avt) {

}
if (sender == calibrationValidator_var.id_avt) {

}
if (sender == blinker_var.id_evt) {

}
if (sender == calibrationStorer_var.id_storeReader) {
Storer_handle_reader_readConfig(&storer_var);

}
if (sender == backbone_var.id_StateHandler) {

}
if (sender == pulseReader_var.id_Transitions) {

}
if (sender == angleReader_var.id_Transitions) {

}
if (sender == serialIn_var.id_Timer) {

}
if (sender == calibrationStorer_var.id_progress) {

}

}


//New dispatcher for messages
void dispatch_release(uint16_t sender) {
if (sender == backbone_var.id_transitions) {

}
if (sender == button_var.id_clock) {

}
if (sender == softButton_var.id_Timer) {

}
if (sender == calibrator_var.id_avt) {

}
if (sender == calibrationValidator_var.id_avt) {

}
if (sender == blinker_var.id_evt) {

}
if (sender == backbone_var.id_StateHandler) {

}
if (sender == pulseReader_var.id_Transitions) {

}
if (sender == angleReader_var.id_Transitions) {

}
if (sender == serialIn_var.id_Timer) {

}
if (sender == button_var.id_evt) {
SoftButton_handle_Button_release(&softButton_var);

}
if (sender == calibrationStorer_var.id_progress) {

}

}


//New dispatcher for messages
void dispatch_statusID(uint16_t sender, uint8_t param_id) {
if (sender == backbone_var.id_transitions) {

}
if (sender == backbone_var.id_pixel) {
Blinker_handle_neopixel_statusID(&blinker_var, param_id);

}
if (sender == button_var.id_clock) {

}
if (sender == softButton_var.id_Timer) {

}
if (sender == calibrator_var.id_avt) {

}
if (sender == calibrationValidator_var.id_avt) {

}
if (sender == blinker_var.id_evt) {

}
if (sender == backbone_var.id_StateHandler) {

}
if (sender == pulseReader_var.id_Transitions) {

}
if (sender == angleReader_var.id_Transitions) {

}
if (sender == serialIn_var.id_Timer) {

}
if (sender == calibrationStorer_var.id_progress) {

}

}


//New dispatcher for messages
void dispatch_press(uint16_t sender) {
if (sender == backbone_var.id_transitions) {

}
if (sender == button_var.id_clock) {

}
if (sender == softButton_var.id_Timer) {

}
if (sender == calibrator_var.id_avt) {

}
if (sender == calibrationValidator_var.id_avt) {

}
if (sender == blinker_var.id_evt) {

}
if (sender == backbone_var.id_StateHandler) {

}
if (sender == pulseReader_var.id_Transitions) {

}
if (sender == angleReader_var.id_Transitions) {

}
if (sender == serialIn_var.id_Timer) {

}
if (sender == button_var.id_evt) {
SoftButton_handle_Button_press(&softButton_var);

}
if (sender == calibrationStorer_var.id_progress) {

}

}


//New dispatcher for messages
void dispatch_endcalibrate(uint16_t sender) {
if (sender == backbone_var.id_transitions) {

}
if (sender == button_var.id_clock) {

}
if (sender == softButton_var.id_Timer) {

}
if (sender == calibrator_var.id_avt) {

}
if (sender == calibrationValidator_var.id_avt) {

}
if (sender == blinker_var.id_evt) {

}
if (sender == calibrator_var.id_calibrator) {
Backbone_handle_calibrator_endcalibrate(&backbone_var);

}
if (sender == backbone_var.id_StateHandler) {

}
if (sender == pulseReader_var.id_Transitions) {

}
if (sender == angleReader_var.id_Transitions) {

}
if (sender == serialIn_var.id_Timer) {

}
if (sender == calibrationStorer_var.id_progress) {

}

}


//New dispatcher for messages
void dispatch_baseStationAngles(uint16_t sender, double param_bh, double param_bv, double param_ch, double param_cv) {
if (sender == backbone_var.id_transitions) {

}
if (sender == button_var.id_clock) {

}
if (sender == softButton_var.id_Timer) {

}
if (sender == calibrator_var.id_avt) {

}
if (sender == calibrationValidator_var.id_avt) {

}
if (sender == blinker_var.id_evt) {

}
if (sender == backbone_var.id_StateHandler) {

}
if (sender == pulseReader_var.id_Transitions) {

}
if (sender == angleReader_var.id_Transitions) {

}
if (sender == serialIn_var.id_Timer) {

}
if (sender == backbone_var.id_Run) {
Runner_handle_Run_baseStationAngles(&runner_var, param_bh, param_bv, param_ch, param_cv);

}
if (sender == calibrationStorer_var.id_progress) {

}

}


//New dispatcher for messages
void dispatch_long_press(uint16_t sender) {
if (sender == backbone_var.id_transitions) {

}
if (sender == button_var.id_clock) {

}
if (sender == softButton_var.id_Timer) {

}
if (sender == calibrator_var.id_avt) {

}
if (sender == calibrationValidator_var.id_avt) {

}
if (sender == blinker_var.id_evt) {

}
if (sender == backbone_var.id_StateHandler) {

}
if (sender == pulseReader_var.id_Transitions) {

}
if (sender == softButton_var.id_SoftButton) {
Backbone_handle_presser_long_press(&backbone_var);

}
if (sender == angleReader_var.id_Transitions) {

}
if (sender == serialIn_var.id_Timer) {

}
if (sender == calibrationStorer_var.id_progress) {

}

}


//New dispatcher for messages
void dispatch_calibrationreceived(uint16_t sender, double param_bx, double param_by, double param_bz, double param_brx, double param_bry, double param_brz, double param_cx, double param_cy, double param_cz, double param_crx, double param_cry, double param_crz) {
if (sender == backbone_var.id_transitions) {

}
if (sender == button_var.id_clock) {

}
if (sender == softButton_var.id_Timer) {

}
if (sender == calibrator_var.id_avt) {

}
if (sender == calibrationValidator_var.id_avt) {

}
if (sender == blinker_var.id_evt) {

}
if (sender == serialIn_var.id_serialcall) {

}
if (sender == backbone_var.id_StateHandler) {

}
if (sender == pulseReader_var.id_Transitions) {

}
if (sender == angleReader_var.id_Transitions) {

}
if (sender == serialIn_var.id_Timer) {

}
if (sender == calibrationStorer_var.id_progress) {

}

}


int processMessageQueue() {
if (fifo_empty()) return 0; // return 0 if there is nothing to do

uint8_t mbufi = 0;

// Read the code of the next port/message in the queue
uint16_t code = fifo_dequeue() << 8;

code += fifo_dequeue();

// Switch to call the appropriate handler
switch(code) {
case 31:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_errvalidate = 2;
dispatch_errvalidate((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
case 17:{
byte mbuf[100 - 2];
while (mbufi < (100 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_configRead = 2;
union u_configRead_bx_t {
double p;
byte bytebuffer[8];
} u_configRead_bx;
u_configRead_bx.bytebuffer[7] = mbuf[mbufi_configRead + 0];
u_configRead_bx.bytebuffer[6] = mbuf[mbufi_configRead + 1];
u_configRead_bx.bytebuffer[5] = mbuf[mbufi_configRead + 2];
u_configRead_bx.bytebuffer[4] = mbuf[mbufi_configRead + 3];
u_configRead_bx.bytebuffer[3] = mbuf[mbufi_configRead + 4];
u_configRead_bx.bytebuffer[2] = mbuf[mbufi_configRead + 5];
u_configRead_bx.bytebuffer[1] = mbuf[mbufi_configRead + 6];
u_configRead_bx.bytebuffer[0] = mbuf[mbufi_configRead + 7];
mbufi_configRead += 8;
union u_configRead_by_t {
double p;
byte bytebuffer[8];
} u_configRead_by;
u_configRead_by.bytebuffer[7] = mbuf[mbufi_configRead + 0];
u_configRead_by.bytebuffer[6] = mbuf[mbufi_configRead + 1];
u_configRead_by.bytebuffer[5] = mbuf[mbufi_configRead + 2];
u_configRead_by.bytebuffer[4] = mbuf[mbufi_configRead + 3];
u_configRead_by.bytebuffer[3] = mbuf[mbufi_configRead + 4];
u_configRead_by.bytebuffer[2] = mbuf[mbufi_configRead + 5];
u_configRead_by.bytebuffer[1] = mbuf[mbufi_configRead + 6];
u_configRead_by.bytebuffer[0] = mbuf[mbufi_configRead + 7];
mbufi_configRead += 8;
union u_configRead_bz_t {
double p;
byte bytebuffer[8];
} u_configRead_bz;
u_configRead_bz.bytebuffer[7] = mbuf[mbufi_configRead + 0];
u_configRead_bz.bytebuffer[6] = mbuf[mbufi_configRead + 1];
u_configRead_bz.bytebuffer[5] = mbuf[mbufi_configRead + 2];
u_configRead_bz.bytebuffer[4] = mbuf[mbufi_configRead + 3];
u_configRead_bz.bytebuffer[3] = mbuf[mbufi_configRead + 4];
u_configRead_bz.bytebuffer[2] = mbuf[mbufi_configRead + 5];
u_configRead_bz.bytebuffer[1] = mbuf[mbufi_configRead + 6];
u_configRead_bz.bytebuffer[0] = mbuf[mbufi_configRead + 7];
mbufi_configRead += 8;
union u_configRead_brx_t {
double p;
byte bytebuffer[8];
} u_configRead_brx;
u_configRead_brx.bytebuffer[7] = mbuf[mbufi_configRead + 0];
u_configRead_brx.bytebuffer[6] = mbuf[mbufi_configRead + 1];
u_configRead_brx.bytebuffer[5] = mbuf[mbufi_configRead + 2];
u_configRead_brx.bytebuffer[4] = mbuf[mbufi_configRead + 3];
u_configRead_brx.bytebuffer[3] = mbuf[mbufi_configRead + 4];
u_configRead_brx.bytebuffer[2] = mbuf[mbufi_configRead + 5];
u_configRead_brx.bytebuffer[1] = mbuf[mbufi_configRead + 6];
u_configRead_brx.bytebuffer[0] = mbuf[mbufi_configRead + 7];
mbufi_configRead += 8;
union u_configRead_bry_t {
double p;
byte bytebuffer[8];
} u_configRead_bry;
u_configRead_bry.bytebuffer[7] = mbuf[mbufi_configRead + 0];
u_configRead_bry.bytebuffer[6] = mbuf[mbufi_configRead + 1];
u_configRead_bry.bytebuffer[5] = mbuf[mbufi_configRead + 2];
u_configRead_bry.bytebuffer[4] = mbuf[mbufi_configRead + 3];
u_configRead_bry.bytebuffer[3] = mbuf[mbufi_configRead + 4];
u_configRead_bry.bytebuffer[2] = mbuf[mbufi_configRead + 5];
u_configRead_bry.bytebuffer[1] = mbuf[mbufi_configRead + 6];
u_configRead_bry.bytebuffer[0] = mbuf[mbufi_configRead + 7];
mbufi_configRead += 8;
union u_configRead_brz_t {
double p;
byte bytebuffer[8];
} u_configRead_brz;
u_configRead_brz.bytebuffer[7] = mbuf[mbufi_configRead + 0];
u_configRead_brz.bytebuffer[6] = mbuf[mbufi_configRead + 1];
u_configRead_brz.bytebuffer[5] = mbuf[mbufi_configRead + 2];
u_configRead_brz.bytebuffer[4] = mbuf[mbufi_configRead + 3];
u_configRead_brz.bytebuffer[3] = mbuf[mbufi_configRead + 4];
u_configRead_brz.bytebuffer[2] = mbuf[mbufi_configRead + 5];
u_configRead_brz.bytebuffer[1] = mbuf[mbufi_configRead + 6];
u_configRead_brz.bytebuffer[0] = mbuf[mbufi_configRead + 7];
mbufi_configRead += 8;
union u_configRead_cx_t {
double p;
byte bytebuffer[8];
} u_configRead_cx;
u_configRead_cx.bytebuffer[7] = mbuf[mbufi_configRead + 0];
u_configRead_cx.bytebuffer[6] = mbuf[mbufi_configRead + 1];
u_configRead_cx.bytebuffer[5] = mbuf[mbufi_configRead + 2];
u_configRead_cx.bytebuffer[4] = mbuf[mbufi_configRead + 3];
u_configRead_cx.bytebuffer[3] = mbuf[mbufi_configRead + 4];
u_configRead_cx.bytebuffer[2] = mbuf[mbufi_configRead + 5];
u_configRead_cx.bytebuffer[1] = mbuf[mbufi_configRead + 6];
u_configRead_cx.bytebuffer[0] = mbuf[mbufi_configRead + 7];
mbufi_configRead += 8;
union u_configRead_cy_t {
double p;
byte bytebuffer[8];
} u_configRead_cy;
u_configRead_cy.bytebuffer[7] = mbuf[mbufi_configRead + 0];
u_configRead_cy.bytebuffer[6] = mbuf[mbufi_configRead + 1];
u_configRead_cy.bytebuffer[5] = mbuf[mbufi_configRead + 2];
u_configRead_cy.bytebuffer[4] = mbuf[mbufi_configRead + 3];
u_configRead_cy.bytebuffer[3] = mbuf[mbufi_configRead + 4];
u_configRead_cy.bytebuffer[2] = mbuf[mbufi_configRead + 5];
u_configRead_cy.bytebuffer[1] = mbuf[mbufi_configRead + 6];
u_configRead_cy.bytebuffer[0] = mbuf[mbufi_configRead + 7];
mbufi_configRead += 8;
union u_configRead_cz_t {
double p;
byte bytebuffer[8];
} u_configRead_cz;
u_configRead_cz.bytebuffer[7] = mbuf[mbufi_configRead + 0];
u_configRead_cz.bytebuffer[6] = mbuf[mbufi_configRead + 1];
u_configRead_cz.bytebuffer[5] = mbuf[mbufi_configRead + 2];
u_configRead_cz.bytebuffer[4] = mbuf[mbufi_configRead + 3];
u_configRead_cz.bytebuffer[3] = mbuf[mbufi_configRead + 4];
u_configRead_cz.bytebuffer[2] = mbuf[mbufi_configRead + 5];
u_configRead_cz.bytebuffer[1] = mbuf[mbufi_configRead + 6];
u_configRead_cz.bytebuffer[0] = mbuf[mbufi_configRead + 7];
mbufi_configRead += 8;
union u_configRead_crx_t {
double p;
byte bytebuffer[8];
} u_configRead_crx;
u_configRead_crx.bytebuffer[7] = mbuf[mbufi_configRead + 0];
u_configRead_crx.bytebuffer[6] = mbuf[mbufi_configRead + 1];
u_configRead_crx.bytebuffer[5] = mbuf[mbufi_configRead + 2];
u_configRead_crx.bytebuffer[4] = mbuf[mbufi_configRead + 3];
u_configRead_crx.bytebuffer[3] = mbuf[mbufi_configRead + 4];
u_configRead_crx.bytebuffer[2] = mbuf[mbufi_configRead + 5];
u_configRead_crx.bytebuffer[1] = mbuf[mbufi_configRead + 6];
u_configRead_crx.bytebuffer[0] = mbuf[mbufi_configRead + 7];
mbufi_configRead += 8;
union u_configRead_cry_t {
double p;
byte bytebuffer[8];
} u_configRead_cry;
u_configRead_cry.bytebuffer[7] = mbuf[mbufi_configRead + 0];
u_configRead_cry.bytebuffer[6] = mbuf[mbufi_configRead + 1];
u_configRead_cry.bytebuffer[5] = mbuf[mbufi_configRead + 2];
u_configRead_cry.bytebuffer[4] = mbuf[mbufi_configRead + 3];
u_configRead_cry.bytebuffer[3] = mbuf[mbufi_configRead + 4];
u_configRead_cry.bytebuffer[2] = mbuf[mbufi_configRead + 5];
u_configRead_cry.bytebuffer[1] = mbuf[mbufi_configRead + 6];
u_configRead_cry.bytebuffer[0] = mbuf[mbufi_configRead + 7];
mbufi_configRead += 8;
union u_configRead_crz_t {
double p;
byte bytebuffer[8];
} u_configRead_crz;
u_configRead_crz.bytebuffer[7] = mbuf[mbufi_configRead + 0];
u_configRead_crz.bytebuffer[6] = mbuf[mbufi_configRead + 1];
u_configRead_crz.bytebuffer[5] = mbuf[mbufi_configRead + 2];
u_configRead_crz.bytebuffer[4] = mbuf[mbufi_configRead + 3];
u_configRead_crz.bytebuffer[3] = mbuf[mbufi_configRead + 4];
u_configRead_crz.bytebuffer[2] = mbuf[mbufi_configRead + 5];
u_configRead_crz.bytebuffer[1] = mbuf[mbufi_configRead + 6];
u_configRead_crz.bytebuffer[0] = mbuf[mbufi_configRead + 7];
mbufi_configRead += 8;
dispatch_configRead((mbuf[0] << 8) + mbuf[1] /* instance port*/,
 u_configRead_bx.p /* bx */ ,
 u_configRead_by.p /* by */ ,
 u_configRead_bz.p /* bz */ ,
 u_configRead_brx.p /* brx */ ,
 u_configRead_bry.p /* bry */ ,
 u_configRead_brz.p /* brz */ ,
 u_configRead_cx.p /* cx */ ,
 u_configRead_cy.p /* cy */ ,
 u_configRead_cz.p /* cz */ ,
 u_configRead_crx.p /* crx */ ,
 u_configRead_cry.p /* cry */ ,
 u_configRead_crz.p /* crz */ );
break;
}
case 4:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_recalibrate = 2;
dispatch_recalibrate((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
case 40:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_load = 2;
dispatch_load((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
case 48:{
byte mbuf[6 - 2];
while (mbufi < (6 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_printOperationState = 2;
union u_printOperationState_id_t {
uint8_t p;
byte bytebuffer[1];
} u_printOperationState_id;
u_printOperationState_id.bytebuffer[0] = mbuf[mbufi_printOperationState + 0];
mbufi_printOperationState += 1;
union u_printOperationState_verbose_t {
uint8_t p;
byte bytebuffer[1];
} u_printOperationState_verbose;
u_printOperationState_verbose.bytebuffer[0] = mbuf[mbufi_printOperationState + 0];
mbufi_printOperationState += 1;
dispatch_printOperationState((mbuf[0] << 8) + mbuf[1] /* instance port*/,
 u_printOperationState_id.p /* id */ ,
 u_printOperationState_verbose.p /* verbose */ );
break;
}
case 1:{
byte mbuf[36 - 2];
while (mbufi < (36 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_allAngles = 2;
union u_allAngles_bh_t {
double p;
byte bytebuffer[8];
} u_allAngles_bh;
u_allAngles_bh.bytebuffer[7] = mbuf[mbufi_allAngles + 0];
u_allAngles_bh.bytebuffer[6] = mbuf[mbufi_allAngles + 1];
u_allAngles_bh.bytebuffer[5] = mbuf[mbufi_allAngles + 2];
u_allAngles_bh.bytebuffer[4] = mbuf[mbufi_allAngles + 3];
u_allAngles_bh.bytebuffer[3] = mbuf[mbufi_allAngles + 4];
u_allAngles_bh.bytebuffer[2] = mbuf[mbufi_allAngles + 5];
u_allAngles_bh.bytebuffer[1] = mbuf[mbufi_allAngles + 6];
u_allAngles_bh.bytebuffer[0] = mbuf[mbufi_allAngles + 7];
mbufi_allAngles += 8;
union u_allAngles_bv_t {
double p;
byte bytebuffer[8];
} u_allAngles_bv;
u_allAngles_bv.bytebuffer[7] = mbuf[mbufi_allAngles + 0];
u_allAngles_bv.bytebuffer[6] = mbuf[mbufi_allAngles + 1];
u_allAngles_bv.bytebuffer[5] = mbuf[mbufi_allAngles + 2];
u_allAngles_bv.bytebuffer[4] = mbuf[mbufi_allAngles + 3];
u_allAngles_bv.bytebuffer[3] = mbuf[mbufi_allAngles + 4];
u_allAngles_bv.bytebuffer[2] = mbuf[mbufi_allAngles + 5];
u_allAngles_bv.bytebuffer[1] = mbuf[mbufi_allAngles + 6];
u_allAngles_bv.bytebuffer[0] = mbuf[mbufi_allAngles + 7];
mbufi_allAngles += 8;
union u_allAngles_ch_t {
double p;
byte bytebuffer[8];
} u_allAngles_ch;
u_allAngles_ch.bytebuffer[7] = mbuf[mbufi_allAngles + 0];
u_allAngles_ch.bytebuffer[6] = mbuf[mbufi_allAngles + 1];
u_allAngles_ch.bytebuffer[5] = mbuf[mbufi_allAngles + 2];
u_allAngles_ch.bytebuffer[4] = mbuf[mbufi_allAngles + 3];
u_allAngles_ch.bytebuffer[3] = mbuf[mbufi_allAngles + 4];
u_allAngles_ch.bytebuffer[2] = mbuf[mbufi_allAngles + 5];
u_allAngles_ch.bytebuffer[1] = mbuf[mbufi_allAngles + 6];
u_allAngles_ch.bytebuffer[0] = mbuf[mbufi_allAngles + 7];
mbufi_allAngles += 8;
union u_allAngles_cv_t {
double p;
byte bytebuffer[8];
} u_allAngles_cv;
u_allAngles_cv.bytebuffer[7] = mbuf[mbufi_allAngles + 0];
u_allAngles_cv.bytebuffer[6] = mbuf[mbufi_allAngles + 1];
u_allAngles_cv.bytebuffer[5] = mbuf[mbufi_allAngles + 2];
u_allAngles_cv.bytebuffer[4] = mbuf[mbufi_allAngles + 3];
u_allAngles_cv.bytebuffer[3] = mbuf[mbufi_allAngles + 4];
u_allAngles_cv.bytebuffer[2] = mbuf[mbufi_allAngles + 5];
u_allAngles_cv.bytebuffer[1] = mbuf[mbufi_allAngles + 6];
u_allAngles_cv.bytebuffer[0] = mbuf[mbufi_allAngles + 7];
mbufi_allAngles += 8;
dispatch_allAngles((mbuf[0] << 8) + mbuf[1] /* instance port*/,
 u_allAngles_bh.p /* bh */ ,
 u_allAngles_bv.p /* bv */ ,
 u_allAngles_ch.p /* ch */ ,
 u_allAngles_cv.p /* cv */ );
break;
}
case 20:{
byte mbuf[36 - 2];
while (mbufi < (36 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_coordinates = 2;
union u_coordinates_x_t {
double p;
byte bytebuffer[8];
} u_coordinates_x;
u_coordinates_x.bytebuffer[7] = mbuf[mbufi_coordinates + 0];
u_coordinates_x.bytebuffer[6] = mbuf[mbufi_coordinates + 1];
u_coordinates_x.bytebuffer[5] = mbuf[mbufi_coordinates + 2];
u_coordinates_x.bytebuffer[4] = mbuf[mbufi_coordinates + 3];
u_coordinates_x.bytebuffer[3] = mbuf[mbufi_coordinates + 4];
u_coordinates_x.bytebuffer[2] = mbuf[mbufi_coordinates + 5];
u_coordinates_x.bytebuffer[1] = mbuf[mbufi_coordinates + 6];
u_coordinates_x.bytebuffer[0] = mbuf[mbufi_coordinates + 7];
mbufi_coordinates += 8;
union u_coordinates_y_t {
double p;
byte bytebuffer[8];
} u_coordinates_y;
u_coordinates_y.bytebuffer[7] = mbuf[mbufi_coordinates + 0];
u_coordinates_y.bytebuffer[6] = mbuf[mbufi_coordinates + 1];
u_coordinates_y.bytebuffer[5] = mbuf[mbufi_coordinates + 2];
u_coordinates_y.bytebuffer[4] = mbuf[mbufi_coordinates + 3];
u_coordinates_y.bytebuffer[3] = mbuf[mbufi_coordinates + 4];
u_coordinates_y.bytebuffer[2] = mbuf[mbufi_coordinates + 5];
u_coordinates_y.bytebuffer[1] = mbuf[mbufi_coordinates + 6];
u_coordinates_y.bytebuffer[0] = mbuf[mbufi_coordinates + 7];
mbufi_coordinates += 8;
union u_coordinates_z_t {
double p;
byte bytebuffer[8];
} u_coordinates_z;
u_coordinates_z.bytebuffer[7] = mbuf[mbufi_coordinates + 0];
u_coordinates_z.bytebuffer[6] = mbuf[mbufi_coordinates + 1];
u_coordinates_z.bytebuffer[5] = mbuf[mbufi_coordinates + 2];
u_coordinates_z.bytebuffer[4] = mbuf[mbufi_coordinates + 3];
u_coordinates_z.bytebuffer[3] = mbuf[mbufi_coordinates + 4];
u_coordinates_z.bytebuffer[2] = mbuf[mbufi_coordinates + 5];
u_coordinates_z.bytebuffer[1] = mbuf[mbufi_coordinates + 6];
u_coordinates_z.bytebuffer[0] = mbuf[mbufi_coordinates + 7];
mbufi_coordinates += 8;
union u_coordinates_separation_t {
double p;
byte bytebuffer[8];
} u_coordinates_separation;
u_coordinates_separation.bytebuffer[7] = mbuf[mbufi_coordinates + 0];
u_coordinates_separation.bytebuffer[6] = mbuf[mbufi_coordinates + 1];
u_coordinates_separation.bytebuffer[5] = mbuf[mbufi_coordinates + 2];
u_coordinates_separation.bytebuffer[4] = mbuf[mbufi_coordinates + 3];
u_coordinates_separation.bytebuffer[3] = mbuf[mbufi_coordinates + 4];
u_coordinates_separation.bytebuffer[2] = mbuf[mbufi_coordinates + 5];
u_coordinates_separation.bytebuffer[1] = mbuf[mbufi_coordinates + 6];
u_coordinates_separation.bytebuffer[0] = mbuf[mbufi_coordinates + 7];
mbufi_coordinates += 8;
dispatch_coordinates((mbuf[0] << 8) + mbuf[1] /* instance port*/,
 u_coordinates_x.p /* x */ ,
 u_coordinates_y.p /* y */ ,
 u_coordinates_z.p /* z */ ,
 u_coordinates_separation.p /* separation */ );
break;
}
case 53:{
byte mbuf[5 - 2];
while (mbufi < (5 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_currentState = 2;
union u_currentState_id_t {
uint8_t p;
byte bytebuffer[1];
} u_currentState_id;
u_currentState_id.bytebuffer[0] = mbuf[mbufi_currentState + 0];
mbufi_currentState += 1;
dispatch_currentState((mbuf[0] << 8) + mbuf[1] /* instance port*/,
 u_currentState_id.p /* id */ );
break;
}
case 46:{
byte mbuf[100 - 2];
while (mbufi < (100 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_receivecalibration = 2;
union u_receivecalibration_bx_t {
double p;
byte bytebuffer[8];
} u_receivecalibration_bx;
u_receivecalibration_bx.bytebuffer[7] = mbuf[mbufi_receivecalibration + 0];
u_receivecalibration_bx.bytebuffer[6] = mbuf[mbufi_receivecalibration + 1];
u_receivecalibration_bx.bytebuffer[5] = mbuf[mbufi_receivecalibration + 2];
u_receivecalibration_bx.bytebuffer[4] = mbuf[mbufi_receivecalibration + 3];
u_receivecalibration_bx.bytebuffer[3] = mbuf[mbufi_receivecalibration + 4];
u_receivecalibration_bx.bytebuffer[2] = mbuf[mbufi_receivecalibration + 5];
u_receivecalibration_bx.bytebuffer[1] = mbuf[mbufi_receivecalibration + 6];
u_receivecalibration_bx.bytebuffer[0] = mbuf[mbufi_receivecalibration + 7];
mbufi_receivecalibration += 8;
union u_receivecalibration_by_t {
double p;
byte bytebuffer[8];
} u_receivecalibration_by;
u_receivecalibration_by.bytebuffer[7] = mbuf[mbufi_receivecalibration + 0];
u_receivecalibration_by.bytebuffer[6] = mbuf[mbufi_receivecalibration + 1];
u_receivecalibration_by.bytebuffer[5] = mbuf[mbufi_receivecalibration + 2];
u_receivecalibration_by.bytebuffer[4] = mbuf[mbufi_receivecalibration + 3];
u_receivecalibration_by.bytebuffer[3] = mbuf[mbufi_receivecalibration + 4];
u_receivecalibration_by.bytebuffer[2] = mbuf[mbufi_receivecalibration + 5];
u_receivecalibration_by.bytebuffer[1] = mbuf[mbufi_receivecalibration + 6];
u_receivecalibration_by.bytebuffer[0] = mbuf[mbufi_receivecalibration + 7];
mbufi_receivecalibration += 8;
union u_receivecalibration_bz_t {
double p;
byte bytebuffer[8];
} u_receivecalibration_bz;
u_receivecalibration_bz.bytebuffer[7] = mbuf[mbufi_receivecalibration + 0];
u_receivecalibration_bz.bytebuffer[6] = mbuf[mbufi_receivecalibration + 1];
u_receivecalibration_bz.bytebuffer[5] = mbuf[mbufi_receivecalibration + 2];
u_receivecalibration_bz.bytebuffer[4] = mbuf[mbufi_receivecalibration + 3];
u_receivecalibration_bz.bytebuffer[3] = mbuf[mbufi_receivecalibration + 4];
u_receivecalibration_bz.bytebuffer[2] = mbuf[mbufi_receivecalibration + 5];
u_receivecalibration_bz.bytebuffer[1] = mbuf[mbufi_receivecalibration + 6];
u_receivecalibration_bz.bytebuffer[0] = mbuf[mbufi_receivecalibration + 7];
mbufi_receivecalibration += 8;
union u_receivecalibration_brx_t {
double p;
byte bytebuffer[8];
} u_receivecalibration_brx;
u_receivecalibration_brx.bytebuffer[7] = mbuf[mbufi_receivecalibration + 0];
u_receivecalibration_brx.bytebuffer[6] = mbuf[mbufi_receivecalibration + 1];
u_receivecalibration_brx.bytebuffer[5] = mbuf[mbufi_receivecalibration + 2];
u_receivecalibration_brx.bytebuffer[4] = mbuf[mbufi_receivecalibration + 3];
u_receivecalibration_brx.bytebuffer[3] = mbuf[mbufi_receivecalibration + 4];
u_receivecalibration_brx.bytebuffer[2] = mbuf[mbufi_receivecalibration + 5];
u_receivecalibration_brx.bytebuffer[1] = mbuf[mbufi_receivecalibration + 6];
u_receivecalibration_brx.bytebuffer[0] = mbuf[mbufi_receivecalibration + 7];
mbufi_receivecalibration += 8;
union u_receivecalibration_bry_t {
double p;
byte bytebuffer[8];
} u_receivecalibration_bry;
u_receivecalibration_bry.bytebuffer[7] = mbuf[mbufi_receivecalibration + 0];
u_receivecalibration_bry.bytebuffer[6] = mbuf[mbufi_receivecalibration + 1];
u_receivecalibration_bry.bytebuffer[5] = mbuf[mbufi_receivecalibration + 2];
u_receivecalibration_bry.bytebuffer[4] = mbuf[mbufi_receivecalibration + 3];
u_receivecalibration_bry.bytebuffer[3] = mbuf[mbufi_receivecalibration + 4];
u_receivecalibration_bry.bytebuffer[2] = mbuf[mbufi_receivecalibration + 5];
u_receivecalibration_bry.bytebuffer[1] = mbuf[mbufi_receivecalibration + 6];
u_receivecalibration_bry.bytebuffer[0] = mbuf[mbufi_receivecalibration + 7];
mbufi_receivecalibration += 8;
union u_receivecalibration_brz_t {
double p;
byte bytebuffer[8];
} u_receivecalibration_brz;
u_receivecalibration_brz.bytebuffer[7] = mbuf[mbufi_receivecalibration + 0];
u_receivecalibration_brz.bytebuffer[6] = mbuf[mbufi_receivecalibration + 1];
u_receivecalibration_brz.bytebuffer[5] = mbuf[mbufi_receivecalibration + 2];
u_receivecalibration_brz.bytebuffer[4] = mbuf[mbufi_receivecalibration + 3];
u_receivecalibration_brz.bytebuffer[3] = mbuf[mbufi_receivecalibration + 4];
u_receivecalibration_brz.bytebuffer[2] = mbuf[mbufi_receivecalibration + 5];
u_receivecalibration_brz.bytebuffer[1] = mbuf[mbufi_receivecalibration + 6];
u_receivecalibration_brz.bytebuffer[0] = mbuf[mbufi_receivecalibration + 7];
mbufi_receivecalibration += 8;
union u_receivecalibration_cx_t {
double p;
byte bytebuffer[8];
} u_receivecalibration_cx;
u_receivecalibration_cx.bytebuffer[7] = mbuf[mbufi_receivecalibration + 0];
u_receivecalibration_cx.bytebuffer[6] = mbuf[mbufi_receivecalibration + 1];
u_receivecalibration_cx.bytebuffer[5] = mbuf[mbufi_receivecalibration + 2];
u_receivecalibration_cx.bytebuffer[4] = mbuf[mbufi_receivecalibration + 3];
u_receivecalibration_cx.bytebuffer[3] = mbuf[mbufi_receivecalibration + 4];
u_receivecalibration_cx.bytebuffer[2] = mbuf[mbufi_receivecalibration + 5];
u_receivecalibration_cx.bytebuffer[1] = mbuf[mbufi_receivecalibration + 6];
u_receivecalibration_cx.bytebuffer[0] = mbuf[mbufi_receivecalibration + 7];
mbufi_receivecalibration += 8;
union u_receivecalibration_cy_t {
double p;
byte bytebuffer[8];
} u_receivecalibration_cy;
u_receivecalibration_cy.bytebuffer[7] = mbuf[mbufi_receivecalibration + 0];
u_receivecalibration_cy.bytebuffer[6] = mbuf[mbufi_receivecalibration + 1];
u_receivecalibration_cy.bytebuffer[5] = mbuf[mbufi_receivecalibration + 2];
u_receivecalibration_cy.bytebuffer[4] = mbuf[mbufi_receivecalibration + 3];
u_receivecalibration_cy.bytebuffer[3] = mbuf[mbufi_receivecalibration + 4];
u_receivecalibration_cy.bytebuffer[2] = mbuf[mbufi_receivecalibration + 5];
u_receivecalibration_cy.bytebuffer[1] = mbuf[mbufi_receivecalibration + 6];
u_receivecalibration_cy.bytebuffer[0] = mbuf[mbufi_receivecalibration + 7];
mbufi_receivecalibration += 8;
union u_receivecalibration_cz_t {
double p;
byte bytebuffer[8];
} u_receivecalibration_cz;
u_receivecalibration_cz.bytebuffer[7] = mbuf[mbufi_receivecalibration + 0];
u_receivecalibration_cz.bytebuffer[6] = mbuf[mbufi_receivecalibration + 1];
u_receivecalibration_cz.bytebuffer[5] = mbuf[mbufi_receivecalibration + 2];
u_receivecalibration_cz.bytebuffer[4] = mbuf[mbufi_receivecalibration + 3];
u_receivecalibration_cz.bytebuffer[3] = mbuf[mbufi_receivecalibration + 4];
u_receivecalibration_cz.bytebuffer[2] = mbuf[mbufi_receivecalibration + 5];
u_receivecalibration_cz.bytebuffer[1] = mbuf[mbufi_receivecalibration + 6];
u_receivecalibration_cz.bytebuffer[0] = mbuf[mbufi_receivecalibration + 7];
mbufi_receivecalibration += 8;
union u_receivecalibration_crx_t {
double p;
byte bytebuffer[8];
} u_receivecalibration_crx;
u_receivecalibration_crx.bytebuffer[7] = mbuf[mbufi_receivecalibration + 0];
u_receivecalibration_crx.bytebuffer[6] = mbuf[mbufi_receivecalibration + 1];
u_receivecalibration_crx.bytebuffer[5] = mbuf[mbufi_receivecalibration + 2];
u_receivecalibration_crx.bytebuffer[4] = mbuf[mbufi_receivecalibration + 3];
u_receivecalibration_crx.bytebuffer[3] = mbuf[mbufi_receivecalibration + 4];
u_receivecalibration_crx.bytebuffer[2] = mbuf[mbufi_receivecalibration + 5];
u_receivecalibration_crx.bytebuffer[1] = mbuf[mbufi_receivecalibration + 6];
u_receivecalibration_crx.bytebuffer[0] = mbuf[mbufi_receivecalibration + 7];
mbufi_receivecalibration += 8;
union u_receivecalibration_cry_t {
double p;
byte bytebuffer[8];
} u_receivecalibration_cry;
u_receivecalibration_cry.bytebuffer[7] = mbuf[mbufi_receivecalibration + 0];
u_receivecalibration_cry.bytebuffer[6] = mbuf[mbufi_receivecalibration + 1];
u_receivecalibration_cry.bytebuffer[5] = mbuf[mbufi_receivecalibration + 2];
u_receivecalibration_cry.bytebuffer[4] = mbuf[mbufi_receivecalibration + 3];
u_receivecalibration_cry.bytebuffer[3] = mbuf[mbufi_receivecalibration + 4];
u_receivecalibration_cry.bytebuffer[2] = mbuf[mbufi_receivecalibration + 5];
u_receivecalibration_cry.bytebuffer[1] = mbuf[mbufi_receivecalibration + 6];
u_receivecalibration_cry.bytebuffer[0] = mbuf[mbufi_receivecalibration + 7];
mbufi_receivecalibration += 8;
union u_receivecalibration_crz_t {
double p;
byte bytebuffer[8];
} u_receivecalibration_crz;
u_receivecalibration_crz.bytebuffer[7] = mbuf[mbufi_receivecalibration + 0];
u_receivecalibration_crz.bytebuffer[6] = mbuf[mbufi_receivecalibration + 1];
u_receivecalibration_crz.bytebuffer[5] = mbuf[mbufi_receivecalibration + 2];
u_receivecalibration_crz.bytebuffer[4] = mbuf[mbufi_receivecalibration + 3];
u_receivecalibration_crz.bytebuffer[3] = mbuf[mbufi_receivecalibration + 4];
u_receivecalibration_crz.bytebuffer[2] = mbuf[mbufi_receivecalibration + 5];
u_receivecalibration_crz.bytebuffer[1] = mbuf[mbufi_receivecalibration + 6];
u_receivecalibration_crz.bytebuffer[0] = mbuf[mbufi_receivecalibration + 7];
mbufi_receivecalibration += 8;
dispatch_receivecalibration((mbuf[0] << 8) + mbuf[1] /* instance port*/,
 u_receivecalibration_bx.p /* bx */ ,
 u_receivecalibration_by.p /* by */ ,
 u_receivecalibration_bz.p /* bz */ ,
 u_receivecalibration_brx.p /* brx */ ,
 u_receivecalibration_bry.p /* bry */ ,
 u_receivecalibration_brz.p /* brz */ ,
 u_receivecalibration_cx.p /* cx */ ,
 u_receivecalibration_cy.p /* cy */ ,
 u_receivecalibration_cz.p /* cz */ ,
 u_receivecalibration_crx.p /* crx */ ,
 u_receivecalibration_cry.p /* cry */ ,
 u_receivecalibration_crz.p /* crz */ );
break;
}
case 29:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_calibrationFailed = 2;
dispatch_calibrationFailed((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
case 44:{
byte mbuf[36 - 2];
while (mbufi < (36 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_receiveAngles = 2;
union u_receiveAngles_bh_t {
double p;
byte bytebuffer[8];
} u_receiveAngles_bh;
u_receiveAngles_bh.bytebuffer[7] = mbuf[mbufi_receiveAngles + 0];
u_receiveAngles_bh.bytebuffer[6] = mbuf[mbufi_receiveAngles + 1];
u_receiveAngles_bh.bytebuffer[5] = mbuf[mbufi_receiveAngles + 2];
u_receiveAngles_bh.bytebuffer[4] = mbuf[mbufi_receiveAngles + 3];
u_receiveAngles_bh.bytebuffer[3] = mbuf[mbufi_receiveAngles + 4];
u_receiveAngles_bh.bytebuffer[2] = mbuf[mbufi_receiveAngles + 5];
u_receiveAngles_bh.bytebuffer[1] = mbuf[mbufi_receiveAngles + 6];
u_receiveAngles_bh.bytebuffer[0] = mbuf[mbufi_receiveAngles + 7];
mbufi_receiveAngles += 8;
union u_receiveAngles_bv_t {
double p;
byte bytebuffer[8];
} u_receiveAngles_bv;
u_receiveAngles_bv.bytebuffer[7] = mbuf[mbufi_receiveAngles + 0];
u_receiveAngles_bv.bytebuffer[6] = mbuf[mbufi_receiveAngles + 1];
u_receiveAngles_bv.bytebuffer[5] = mbuf[mbufi_receiveAngles + 2];
u_receiveAngles_bv.bytebuffer[4] = mbuf[mbufi_receiveAngles + 3];
u_receiveAngles_bv.bytebuffer[3] = mbuf[mbufi_receiveAngles + 4];
u_receiveAngles_bv.bytebuffer[2] = mbuf[mbufi_receiveAngles + 5];
u_receiveAngles_bv.bytebuffer[1] = mbuf[mbufi_receiveAngles + 6];
u_receiveAngles_bv.bytebuffer[0] = mbuf[mbufi_receiveAngles + 7];
mbufi_receiveAngles += 8;
union u_receiveAngles_ch_t {
double p;
byte bytebuffer[8];
} u_receiveAngles_ch;
u_receiveAngles_ch.bytebuffer[7] = mbuf[mbufi_receiveAngles + 0];
u_receiveAngles_ch.bytebuffer[6] = mbuf[mbufi_receiveAngles + 1];
u_receiveAngles_ch.bytebuffer[5] = mbuf[mbufi_receiveAngles + 2];
u_receiveAngles_ch.bytebuffer[4] = mbuf[mbufi_receiveAngles + 3];
u_receiveAngles_ch.bytebuffer[3] = mbuf[mbufi_receiveAngles + 4];
u_receiveAngles_ch.bytebuffer[2] = mbuf[mbufi_receiveAngles + 5];
u_receiveAngles_ch.bytebuffer[1] = mbuf[mbufi_receiveAngles + 6];
u_receiveAngles_ch.bytebuffer[0] = mbuf[mbufi_receiveAngles + 7];
mbufi_receiveAngles += 8;
union u_receiveAngles_cv_t {
double p;
byte bytebuffer[8];
} u_receiveAngles_cv;
u_receiveAngles_cv.bytebuffer[7] = mbuf[mbufi_receiveAngles + 0];
u_receiveAngles_cv.bytebuffer[6] = mbuf[mbufi_receiveAngles + 1];
u_receiveAngles_cv.bytebuffer[5] = mbuf[mbufi_receiveAngles + 2];
u_receiveAngles_cv.bytebuffer[4] = mbuf[mbufi_receiveAngles + 3];
u_receiveAngles_cv.bytebuffer[3] = mbuf[mbufi_receiveAngles + 4];
u_receiveAngles_cv.bytebuffer[2] = mbuf[mbufi_receiveAngles + 5];
u_receiveAngles_cv.bytebuffer[1] = mbuf[mbufi_receiveAngles + 6];
u_receiveAngles_cv.bytebuffer[0] = mbuf[mbufi_receiveAngles + 7];
mbufi_receiveAngles += 8;
dispatch_receiveAngles((mbuf[0] << 8) + mbuf[1] /* instance port*/,
 u_receiveAngles_bh.p /* bh */ ,
 u_receiveAngles_bv.p /* bv */ ,
 u_receiveAngles_ch.p /* ch */ ,
 u_receiveAngles_cv.p /* cv */ );
break;
}
case 45:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_calibrate = 2;
dispatch_calibrate((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
case 19:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_byteWritten = 2;
dispatch_byteWritten((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
case 30:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_calibrating = 2;
dispatch_calibrating((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
case 49:{
byte mbuf[6 - 2];
while (mbufi < (6 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_printStatus = 2;
union u_printStatus_id_t {
uint8_t p;
byte bytebuffer[1];
} u_printStatus_id;
u_printStatus_id.bytebuffer[0] = mbuf[mbufi_printStatus + 0];
mbufi_printStatus += 1;
union u_printStatus_verbose_t {
uint8_t p;
byte bytebuffer[1];
} u_printStatus_verbose;
u_printStatus_verbose.bytebuffer[0] = mbuf[mbufi_printStatus + 0];
mbufi_printStatus += 1;
dispatch_printStatus((mbuf[0] << 8) + mbuf[1] /* instance port*/,
 u_printStatus_id.p /* id */ ,
 u_printStatus_verbose.p /* verbose */ );
break;
}
case 16:{
byte mbuf[5 - 2];
while (mbufi < (5 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_byteRead = 2;
union u_byteRead_val_t {
uint8_t p;
byte bytebuffer[1];
} u_byteRead_val;
u_byteRead_val.bytebuffer[0] = mbuf[mbufi_byteRead + 0];
mbufi_byteRead += 1;
dispatch_byteRead((mbuf[0] << 8) + mbuf[1] /* instance port*/,
 u_byteRead_val.p /* val */ );
break;
}
case 15:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_storerToIdle = 2;
dispatch_storerToIdle((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
case 54:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_toIdle = 2;
dispatch_toIdle((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
case 2:{
byte mbuf[5 - 2];
while (mbufi < (5 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_status = 2;
union u_status_id_t {
uint8_t p;
byte bytebuffer[1];
} u_status_id;
u_status_id.bytebuffer[0] = mbuf[mbufi_status + 0];
mbufi_status += 1;
dispatch_status((mbuf[0] << 8) + mbuf[1] /* instance port*/,
 u_status_id.p /* id */ );
break;
}
case 8:{
byte mbuf[24 - 2];
while (mbufi < (24 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_packageDetectedEvent = 2;
union u_packageDetectedEvent_startTimeL1_t {
uint32_t p;
byte bytebuffer[4];
} u_packageDetectedEvent_startTimeL1;
u_packageDetectedEvent_startTimeL1.bytebuffer[3] = mbuf[mbufi_packageDetectedEvent + 0];
u_packageDetectedEvent_startTimeL1.bytebuffer[2] = mbuf[mbufi_packageDetectedEvent + 1];
u_packageDetectedEvent_startTimeL1.bytebuffer[1] = mbuf[mbufi_packageDetectedEvent + 2];
u_packageDetectedEvent_startTimeL1.bytebuffer[0] = mbuf[mbufi_packageDetectedEvent + 3];
mbufi_packageDetectedEvent += 4;
union u_packageDetectedEvent_startTimeL2_t {
uint32_t p;
byte bytebuffer[4];
} u_packageDetectedEvent_startTimeL2;
u_packageDetectedEvent_startTimeL2.bytebuffer[3] = mbuf[mbufi_packageDetectedEvent + 0];
u_packageDetectedEvent_startTimeL2.bytebuffer[2] = mbuf[mbufi_packageDetectedEvent + 1];
u_packageDetectedEvent_startTimeL2.bytebuffer[1] = mbuf[mbufi_packageDetectedEvent + 2];
u_packageDetectedEvent_startTimeL2.bytebuffer[0] = mbuf[mbufi_packageDetectedEvent + 3];
mbufi_packageDetectedEvent += 4;
union u_packageDetectedEvent_durationL1_t {
uint32_t p;
byte bytebuffer[4];
} u_packageDetectedEvent_durationL1;
u_packageDetectedEvent_durationL1.bytebuffer[3] = mbuf[mbufi_packageDetectedEvent + 0];
u_packageDetectedEvent_durationL1.bytebuffer[2] = mbuf[mbufi_packageDetectedEvent + 1];
u_packageDetectedEvent_durationL1.bytebuffer[1] = mbuf[mbufi_packageDetectedEvent + 2];
u_packageDetectedEvent_durationL1.bytebuffer[0] = mbuf[mbufi_packageDetectedEvent + 3];
mbufi_packageDetectedEvent += 4;
union u_packageDetectedEvent_durationL2_t {
uint32_t p;
byte bytebuffer[4];
} u_packageDetectedEvent_durationL2;
u_packageDetectedEvent_durationL2.bytebuffer[3] = mbuf[mbufi_packageDetectedEvent + 0];
u_packageDetectedEvent_durationL2.bytebuffer[2] = mbuf[mbufi_packageDetectedEvent + 1];
u_packageDetectedEvent_durationL2.bytebuffer[1] = mbuf[mbufi_packageDetectedEvent + 2];
u_packageDetectedEvent_durationL2.bytebuffer[0] = mbuf[mbufi_packageDetectedEvent + 3];
mbufi_packageDetectedEvent += 4;
union u_packageDetectedEvent_signal_t {
uint32_t p;
byte bytebuffer[4];
} u_packageDetectedEvent_signal;
u_packageDetectedEvent_signal.bytebuffer[3] = mbuf[mbufi_packageDetectedEvent + 0];
u_packageDetectedEvent_signal.bytebuffer[2] = mbuf[mbufi_packageDetectedEvent + 1];
u_packageDetectedEvent_signal.bytebuffer[1] = mbuf[mbufi_packageDetectedEvent + 2];
u_packageDetectedEvent_signal.bytebuffer[0] = mbuf[mbufi_packageDetectedEvent + 3];
mbufi_packageDetectedEvent += 4;
dispatch_packageDetectedEvent((mbuf[0] << 8) + mbuf[1] /* instance port*/,
 u_packageDetectedEvent_startTimeL1.p /* startTimeL1 */ ,
 u_packageDetectedEvent_startTimeL2.p /* startTimeL2 */ ,
 u_packageDetectedEvent_durationL1.p /* durationL1 */ ,
 u_packageDetectedEvent_durationL2.p /* durationL2 */ ,
 u_packageDetectedEvent_signal.p /* signal */ );
break;
}
case 35:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_timerOverflow = 2;
dispatch_timerOverflow((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
case 11:{
byte mbuf[6 - 2];
while (mbufi < (6 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_writeByte = 2;
union u_writeByte_id_t {
uint8_t p;
byte bytebuffer[1];
} u_writeByte_id;
u_writeByte_id.bytebuffer[0] = mbuf[mbufi_writeByte + 0];
mbufi_writeByte += 1;
union u_writeByte_val_t {
uint8_t p;
byte bytebuffer[1];
} u_writeByte_val;
u_writeByte_val.bytebuffer[0] = mbuf[mbufi_writeByte + 0];
mbufi_writeByte += 1;
dispatch_writeByte((mbuf[0] << 8) + mbuf[1] /* instance port*/,
 u_writeByte_id.p /* id */ ,
 u_writeByte_val.p /* val */ );
break;
}
case 47:{
byte mbuf[37 - 2];
while (mbufi < (37 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_printPoint = 2;
union u_printPoint_x_t {
double p;
byte bytebuffer[8];
} u_printPoint_x;
u_printPoint_x.bytebuffer[7] = mbuf[mbufi_printPoint + 0];
u_printPoint_x.bytebuffer[6] = mbuf[mbufi_printPoint + 1];
u_printPoint_x.bytebuffer[5] = mbuf[mbufi_printPoint + 2];
u_printPoint_x.bytebuffer[4] = mbuf[mbufi_printPoint + 3];
u_printPoint_x.bytebuffer[3] = mbuf[mbufi_printPoint + 4];
u_printPoint_x.bytebuffer[2] = mbuf[mbufi_printPoint + 5];
u_printPoint_x.bytebuffer[1] = mbuf[mbufi_printPoint + 6];
u_printPoint_x.bytebuffer[0] = mbuf[mbufi_printPoint + 7];
mbufi_printPoint += 8;
union u_printPoint_y_t {
double p;
byte bytebuffer[8];
} u_printPoint_y;
u_printPoint_y.bytebuffer[7] = mbuf[mbufi_printPoint + 0];
u_printPoint_y.bytebuffer[6] = mbuf[mbufi_printPoint + 1];
u_printPoint_y.bytebuffer[5] = mbuf[mbufi_printPoint + 2];
u_printPoint_y.bytebuffer[4] = mbuf[mbufi_printPoint + 3];
u_printPoint_y.bytebuffer[3] = mbuf[mbufi_printPoint + 4];
u_printPoint_y.bytebuffer[2] = mbuf[mbufi_printPoint + 5];
u_printPoint_y.bytebuffer[1] = mbuf[mbufi_printPoint + 6];
u_printPoint_y.bytebuffer[0] = mbuf[mbufi_printPoint + 7];
mbufi_printPoint += 8;
union u_printPoint_z_t {
double p;
byte bytebuffer[8];
} u_printPoint_z;
u_printPoint_z.bytebuffer[7] = mbuf[mbufi_printPoint + 0];
u_printPoint_z.bytebuffer[6] = mbuf[mbufi_printPoint + 1];
u_printPoint_z.bytebuffer[5] = mbuf[mbufi_printPoint + 2];
u_printPoint_z.bytebuffer[4] = mbuf[mbufi_printPoint + 3];
u_printPoint_z.bytebuffer[3] = mbuf[mbufi_printPoint + 4];
u_printPoint_z.bytebuffer[2] = mbuf[mbufi_printPoint + 5];
u_printPoint_z.bytebuffer[1] = mbuf[mbufi_printPoint + 6];
u_printPoint_z.bytebuffer[0] = mbuf[mbufi_printPoint + 7];
mbufi_printPoint += 8;
union u_printPoint_separation_t {
double p;
byte bytebuffer[8];
} u_printPoint_separation;
u_printPoint_separation.bytebuffer[7] = mbuf[mbufi_printPoint + 0];
u_printPoint_separation.bytebuffer[6] = mbuf[mbufi_printPoint + 1];
u_printPoint_separation.bytebuffer[5] = mbuf[mbufi_printPoint + 2];
u_printPoint_separation.bytebuffer[4] = mbuf[mbufi_printPoint + 3];
u_printPoint_separation.bytebuffer[3] = mbuf[mbufi_printPoint + 4];
u_printPoint_separation.bytebuffer[2] = mbuf[mbufi_printPoint + 5];
u_printPoint_separation.bytebuffer[1] = mbuf[mbufi_printPoint + 6];
u_printPoint_separation.bytebuffer[0] = mbuf[mbufi_printPoint + 7];
mbufi_printPoint += 8;
union u_printPoint_verbose_t {
uint8_t p;
byte bytebuffer[1];
} u_printPoint_verbose;
u_printPoint_verbose.bytebuffer[0] = mbuf[mbufi_printPoint + 0];
mbufi_printPoint += 1;
dispatch_printPoint((mbuf[0] << 8) + mbuf[1] /* instance port*/,
 u_printPoint_x.p /* x */ ,
 u_printPoint_y.p /* y */ ,
 u_printPoint_z.p /* z */ ,
 u_printPoint_separation.p /* separation */ ,
 u_printPoint_verbose.p /* verbose */ );
break;
}
case 3:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_startTimeCalibrated = 2;
dispatch_startTimeCalibrated((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
case 5:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_ms25_tic = 2;
dispatch_ms25_tic((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
case 9:{
byte mbuf[5 - 2];
while (mbufi < (5 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_readByte = 2;
union u_readByte_id_t {
uint8_t p;
byte bytebuffer[1];
} u_readByte_id;
u_readByte_id.bytebuffer[0] = mbuf[mbufi_readByte + 0];
mbufi_readByte += 1;
dispatch_readByte((mbuf[0] << 8) + mbuf[1] /* instance port*/,
 u_readByte_id.p /* id */ );
break;
}
case 32:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_endvalidate = 2;
dispatch_endvalidate((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
case 52:{
byte mbuf[5 - 2];
while (mbufi < (5 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_stateID = 2;
union u_stateID_id_t {
uint8_t p;
byte bytebuffer[1];
} u_stateID_id;
u_stateID_id.bytebuffer[0] = mbuf[mbufi_stateID + 0];
mbufi_stateID += 1;
dispatch_stateID((mbuf[0] << 8) + mbuf[1] /* instance port*/,
 u_stateID_id.p /* id */ );
break;
}
case 14:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_endload = 2;
dispatch_endload((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
case 27:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_errcalibrate = 2;
dispatch_errcalibrate((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
case 36:{
byte mbuf[12 - 2];
while (mbufi < (12 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_pulseDetected = 2;
union u_pulseDetected_start_t {
uint32_t p;
byte bytebuffer[4];
} u_pulseDetected_start;
u_pulseDetected_start.bytebuffer[3] = mbuf[mbufi_pulseDetected + 0];
u_pulseDetected_start.bytebuffer[2] = mbuf[mbufi_pulseDetected + 1];
u_pulseDetected_start.bytebuffer[1] = mbuf[mbufi_pulseDetected + 2];
u_pulseDetected_start.bytebuffer[0] = mbuf[mbufi_pulseDetected + 3];
mbufi_pulseDetected += 4;
union u_pulseDetected_duration_t {
uint32_t p;
byte bytebuffer[4];
} u_pulseDetected_duration;
u_pulseDetected_duration.bytebuffer[3] = mbuf[mbufi_pulseDetected + 0];
u_pulseDetected_duration.bytebuffer[2] = mbuf[mbufi_pulseDetected + 1];
u_pulseDetected_duration.bytebuffer[1] = mbuf[mbufi_pulseDetected + 2];
u_pulseDetected_duration.bytebuffer[0] = mbuf[mbufi_pulseDetected + 3];
mbufi_pulseDetected += 4;
dispatch_pulseDetected((mbuf[0] << 8) + mbuf[1] /* instance port*/,
 u_pulseDetected_start.p /* start */ ,
 u_pulseDetected_duration.p /* duration */ );
break;
}
case 13:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_errorload = 2;
dispatch_errorload((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
case 34:{
byte mbuf[12 - 2];
while (mbufi < (12 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_pulseDetectedEvent = 2;
union u_pulseDetectedEvent_start_t {
uint32_t p;
byte bytebuffer[4];
} u_pulseDetectedEvent_start;
u_pulseDetectedEvent_start.bytebuffer[3] = mbuf[mbufi_pulseDetectedEvent + 0];
u_pulseDetectedEvent_start.bytebuffer[2] = mbuf[mbufi_pulseDetectedEvent + 1];
u_pulseDetectedEvent_start.bytebuffer[1] = mbuf[mbufi_pulseDetectedEvent + 2];
u_pulseDetectedEvent_start.bytebuffer[0] = mbuf[mbufi_pulseDetectedEvent + 3];
mbufi_pulseDetectedEvent += 4;
union u_pulseDetectedEvent_duration_t {
uint32_t p;
byte bytebuffer[4];
} u_pulseDetectedEvent_duration;
u_pulseDetectedEvent_duration.bytebuffer[3] = mbuf[mbufi_pulseDetectedEvent + 0];
u_pulseDetectedEvent_duration.bytebuffer[2] = mbuf[mbufi_pulseDetectedEvent + 1];
u_pulseDetectedEvent_duration.bytebuffer[1] = mbuf[mbufi_pulseDetectedEvent + 2];
u_pulseDetectedEvent_duration.bytebuffer[0] = mbuf[mbufi_pulseDetectedEvent + 3];
mbufi_pulseDetectedEvent += 4;
dispatch_pulseDetectedEvent((mbuf[0] << 8) + mbuf[1] /* instance port*/,
 u_pulseDetectedEvent_start.p /* start */ ,
 u_pulseDetectedEvent_duration.p /* duration */ );
break;
}
case 55:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_blink = 2;
dispatch_blink((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
case 12:{
byte mbuf[100 - 2];
while (mbufi < (100 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_writeConfig = 2;
union u_writeConfig_bx_t {
double p;
byte bytebuffer[8];
} u_writeConfig_bx;
u_writeConfig_bx.bytebuffer[7] = mbuf[mbufi_writeConfig + 0];
u_writeConfig_bx.bytebuffer[6] = mbuf[mbufi_writeConfig + 1];
u_writeConfig_bx.bytebuffer[5] = mbuf[mbufi_writeConfig + 2];
u_writeConfig_bx.bytebuffer[4] = mbuf[mbufi_writeConfig + 3];
u_writeConfig_bx.bytebuffer[3] = mbuf[mbufi_writeConfig + 4];
u_writeConfig_bx.bytebuffer[2] = mbuf[mbufi_writeConfig + 5];
u_writeConfig_bx.bytebuffer[1] = mbuf[mbufi_writeConfig + 6];
u_writeConfig_bx.bytebuffer[0] = mbuf[mbufi_writeConfig + 7];
mbufi_writeConfig += 8;
union u_writeConfig_by_t {
double p;
byte bytebuffer[8];
} u_writeConfig_by;
u_writeConfig_by.bytebuffer[7] = mbuf[mbufi_writeConfig + 0];
u_writeConfig_by.bytebuffer[6] = mbuf[mbufi_writeConfig + 1];
u_writeConfig_by.bytebuffer[5] = mbuf[mbufi_writeConfig + 2];
u_writeConfig_by.bytebuffer[4] = mbuf[mbufi_writeConfig + 3];
u_writeConfig_by.bytebuffer[3] = mbuf[mbufi_writeConfig + 4];
u_writeConfig_by.bytebuffer[2] = mbuf[mbufi_writeConfig + 5];
u_writeConfig_by.bytebuffer[1] = mbuf[mbufi_writeConfig + 6];
u_writeConfig_by.bytebuffer[0] = mbuf[mbufi_writeConfig + 7];
mbufi_writeConfig += 8;
union u_writeConfig_bz_t {
double p;
byte bytebuffer[8];
} u_writeConfig_bz;
u_writeConfig_bz.bytebuffer[7] = mbuf[mbufi_writeConfig + 0];
u_writeConfig_bz.bytebuffer[6] = mbuf[mbufi_writeConfig + 1];
u_writeConfig_bz.bytebuffer[5] = mbuf[mbufi_writeConfig + 2];
u_writeConfig_bz.bytebuffer[4] = mbuf[mbufi_writeConfig + 3];
u_writeConfig_bz.bytebuffer[3] = mbuf[mbufi_writeConfig + 4];
u_writeConfig_bz.bytebuffer[2] = mbuf[mbufi_writeConfig + 5];
u_writeConfig_bz.bytebuffer[1] = mbuf[mbufi_writeConfig + 6];
u_writeConfig_bz.bytebuffer[0] = mbuf[mbufi_writeConfig + 7];
mbufi_writeConfig += 8;
union u_writeConfig_brx_t {
double p;
byte bytebuffer[8];
} u_writeConfig_brx;
u_writeConfig_brx.bytebuffer[7] = mbuf[mbufi_writeConfig + 0];
u_writeConfig_brx.bytebuffer[6] = mbuf[mbufi_writeConfig + 1];
u_writeConfig_brx.bytebuffer[5] = mbuf[mbufi_writeConfig + 2];
u_writeConfig_brx.bytebuffer[4] = mbuf[mbufi_writeConfig + 3];
u_writeConfig_brx.bytebuffer[3] = mbuf[mbufi_writeConfig + 4];
u_writeConfig_brx.bytebuffer[2] = mbuf[mbufi_writeConfig + 5];
u_writeConfig_brx.bytebuffer[1] = mbuf[mbufi_writeConfig + 6];
u_writeConfig_brx.bytebuffer[0] = mbuf[mbufi_writeConfig + 7];
mbufi_writeConfig += 8;
union u_writeConfig_bry_t {
double p;
byte bytebuffer[8];
} u_writeConfig_bry;
u_writeConfig_bry.bytebuffer[7] = mbuf[mbufi_writeConfig + 0];
u_writeConfig_bry.bytebuffer[6] = mbuf[mbufi_writeConfig + 1];
u_writeConfig_bry.bytebuffer[5] = mbuf[mbufi_writeConfig + 2];
u_writeConfig_bry.bytebuffer[4] = mbuf[mbufi_writeConfig + 3];
u_writeConfig_bry.bytebuffer[3] = mbuf[mbufi_writeConfig + 4];
u_writeConfig_bry.bytebuffer[2] = mbuf[mbufi_writeConfig + 5];
u_writeConfig_bry.bytebuffer[1] = mbuf[mbufi_writeConfig + 6];
u_writeConfig_bry.bytebuffer[0] = mbuf[mbufi_writeConfig + 7];
mbufi_writeConfig += 8;
union u_writeConfig_brz_t {
double p;
byte bytebuffer[8];
} u_writeConfig_brz;
u_writeConfig_brz.bytebuffer[7] = mbuf[mbufi_writeConfig + 0];
u_writeConfig_brz.bytebuffer[6] = mbuf[mbufi_writeConfig + 1];
u_writeConfig_brz.bytebuffer[5] = mbuf[mbufi_writeConfig + 2];
u_writeConfig_brz.bytebuffer[4] = mbuf[mbufi_writeConfig + 3];
u_writeConfig_brz.bytebuffer[3] = mbuf[mbufi_writeConfig + 4];
u_writeConfig_brz.bytebuffer[2] = mbuf[mbufi_writeConfig + 5];
u_writeConfig_brz.bytebuffer[1] = mbuf[mbufi_writeConfig + 6];
u_writeConfig_brz.bytebuffer[0] = mbuf[mbufi_writeConfig + 7];
mbufi_writeConfig += 8;
union u_writeConfig_cx_t {
double p;
byte bytebuffer[8];
} u_writeConfig_cx;
u_writeConfig_cx.bytebuffer[7] = mbuf[mbufi_writeConfig + 0];
u_writeConfig_cx.bytebuffer[6] = mbuf[mbufi_writeConfig + 1];
u_writeConfig_cx.bytebuffer[5] = mbuf[mbufi_writeConfig + 2];
u_writeConfig_cx.bytebuffer[4] = mbuf[mbufi_writeConfig + 3];
u_writeConfig_cx.bytebuffer[3] = mbuf[mbufi_writeConfig + 4];
u_writeConfig_cx.bytebuffer[2] = mbuf[mbufi_writeConfig + 5];
u_writeConfig_cx.bytebuffer[1] = mbuf[mbufi_writeConfig + 6];
u_writeConfig_cx.bytebuffer[0] = mbuf[mbufi_writeConfig + 7];
mbufi_writeConfig += 8;
union u_writeConfig_cy_t {
double p;
byte bytebuffer[8];
} u_writeConfig_cy;
u_writeConfig_cy.bytebuffer[7] = mbuf[mbufi_writeConfig + 0];
u_writeConfig_cy.bytebuffer[6] = mbuf[mbufi_writeConfig + 1];
u_writeConfig_cy.bytebuffer[5] = mbuf[mbufi_writeConfig + 2];
u_writeConfig_cy.bytebuffer[4] = mbuf[mbufi_writeConfig + 3];
u_writeConfig_cy.bytebuffer[3] = mbuf[mbufi_writeConfig + 4];
u_writeConfig_cy.bytebuffer[2] = mbuf[mbufi_writeConfig + 5];
u_writeConfig_cy.bytebuffer[1] = mbuf[mbufi_writeConfig + 6];
u_writeConfig_cy.bytebuffer[0] = mbuf[mbufi_writeConfig + 7];
mbufi_writeConfig += 8;
union u_writeConfig_cz_t {
double p;
byte bytebuffer[8];
} u_writeConfig_cz;
u_writeConfig_cz.bytebuffer[7] = mbuf[mbufi_writeConfig + 0];
u_writeConfig_cz.bytebuffer[6] = mbuf[mbufi_writeConfig + 1];
u_writeConfig_cz.bytebuffer[5] = mbuf[mbufi_writeConfig + 2];
u_writeConfig_cz.bytebuffer[4] = mbuf[mbufi_writeConfig + 3];
u_writeConfig_cz.bytebuffer[3] = mbuf[mbufi_writeConfig + 4];
u_writeConfig_cz.bytebuffer[2] = mbuf[mbufi_writeConfig + 5];
u_writeConfig_cz.bytebuffer[1] = mbuf[mbufi_writeConfig + 6];
u_writeConfig_cz.bytebuffer[0] = mbuf[mbufi_writeConfig + 7];
mbufi_writeConfig += 8;
union u_writeConfig_crx_t {
double p;
byte bytebuffer[8];
} u_writeConfig_crx;
u_writeConfig_crx.bytebuffer[7] = mbuf[mbufi_writeConfig + 0];
u_writeConfig_crx.bytebuffer[6] = mbuf[mbufi_writeConfig + 1];
u_writeConfig_crx.bytebuffer[5] = mbuf[mbufi_writeConfig + 2];
u_writeConfig_crx.bytebuffer[4] = mbuf[mbufi_writeConfig + 3];
u_writeConfig_crx.bytebuffer[3] = mbuf[mbufi_writeConfig + 4];
u_writeConfig_crx.bytebuffer[2] = mbuf[mbufi_writeConfig + 5];
u_writeConfig_crx.bytebuffer[1] = mbuf[mbufi_writeConfig + 6];
u_writeConfig_crx.bytebuffer[0] = mbuf[mbufi_writeConfig + 7];
mbufi_writeConfig += 8;
union u_writeConfig_cry_t {
double p;
byte bytebuffer[8];
} u_writeConfig_cry;
u_writeConfig_cry.bytebuffer[7] = mbuf[mbufi_writeConfig + 0];
u_writeConfig_cry.bytebuffer[6] = mbuf[mbufi_writeConfig + 1];
u_writeConfig_cry.bytebuffer[5] = mbuf[mbufi_writeConfig + 2];
u_writeConfig_cry.bytebuffer[4] = mbuf[mbufi_writeConfig + 3];
u_writeConfig_cry.bytebuffer[3] = mbuf[mbufi_writeConfig + 4];
u_writeConfig_cry.bytebuffer[2] = mbuf[mbufi_writeConfig + 5];
u_writeConfig_cry.bytebuffer[1] = mbuf[mbufi_writeConfig + 6];
u_writeConfig_cry.bytebuffer[0] = mbuf[mbufi_writeConfig + 7];
mbufi_writeConfig += 8;
union u_writeConfig_crz_t {
double p;
byte bytebuffer[8];
} u_writeConfig_crz;
u_writeConfig_crz.bytebuffer[7] = mbuf[mbufi_writeConfig + 0];
u_writeConfig_crz.bytebuffer[6] = mbuf[mbufi_writeConfig + 1];
u_writeConfig_crz.bytebuffer[5] = mbuf[mbufi_writeConfig + 2];
u_writeConfig_crz.bytebuffer[4] = mbuf[mbufi_writeConfig + 3];
u_writeConfig_crz.bytebuffer[3] = mbuf[mbufi_writeConfig + 4];
u_writeConfig_crz.bytebuffer[2] = mbuf[mbufi_writeConfig + 5];
u_writeConfig_crz.bytebuffer[1] = mbuf[mbufi_writeConfig + 6];
u_writeConfig_crz.bytebuffer[0] = mbuf[mbufi_writeConfig + 7];
mbufi_writeConfig += 8;
dispatch_writeConfig((mbuf[0] << 8) + mbuf[1] /* instance port*/,
 u_writeConfig_bx.p /* bx */ ,
 u_writeConfig_by.p /* by */ ,
 u_writeConfig_bz.p /* bz */ ,
 u_writeConfig_brx.p /* brx */ ,
 u_writeConfig_bry.p /* bry */ ,
 u_writeConfig_brz.p /* brz */ ,
 u_writeConfig_cx.p /* cx */ ,
 u_writeConfig_cy.p /* cy */ ,
 u_writeConfig_cz.p /* cz */ ,
 u_writeConfig_crx.p /* crx */ ,
 u_writeConfig_cry.p /* cry */ ,
 u_writeConfig_crz.p /* crz */ );
break;
}
case 41:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_save = 2;
dispatch_save((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
case 38:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_serial_timeout = 2;
dispatch_serial_timeout((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
case 22:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_double_click = 2;
dispatch_double_click((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
case 43:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_entrypoint = 2;
dispatch_entrypoint((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
case 33:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_validating = 2;
dispatch_validating((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
case 23:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_click = 2;
dispatch_click((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
case 50:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_waitcalibration = 2;
dispatch_waitcalibration((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
case 42:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_validate = 2;
dispatch_validate((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
case 28:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_calibrationComplete = 2;
dispatch_calibrationComplete((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
case 18:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_configWritten = 2;
dispatch_configWritten((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
case 21:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_timer_timeout = 2;
dispatch_timer_timeout((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
case 26:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_calibrationfromserial = 2;
dispatch_calibrationfromserial((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
case 10:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_readConfig = 2;
dispatch_readConfig((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
case 7:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_release = 2;
dispatch_release((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
case 51:{
byte mbuf[5 - 2];
while (mbufi < (5 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_statusID = 2;
union u_statusID_id_t {
uint8_t p;
byte bytebuffer[1];
} u_statusID_id;
u_statusID_id.bytebuffer[0] = mbuf[mbufi_statusID + 0];
mbufi_statusID += 1;
dispatch_statusID((mbuf[0] << 8) + mbuf[1] /* instance port*/,
 u_statusID_id.p /* id */ );
break;
}
case 6:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_press = 2;
dispatch_press((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
case 25:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_endcalibrate = 2;
dispatch_endcalibrate((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
case 39:{
byte mbuf[36 - 2];
while (mbufi < (36 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_baseStationAngles = 2;
union u_baseStationAngles_bh_t {
double p;
byte bytebuffer[8];
} u_baseStationAngles_bh;
u_baseStationAngles_bh.bytebuffer[7] = mbuf[mbufi_baseStationAngles + 0];
u_baseStationAngles_bh.bytebuffer[6] = mbuf[mbufi_baseStationAngles + 1];
u_baseStationAngles_bh.bytebuffer[5] = mbuf[mbufi_baseStationAngles + 2];
u_baseStationAngles_bh.bytebuffer[4] = mbuf[mbufi_baseStationAngles + 3];
u_baseStationAngles_bh.bytebuffer[3] = mbuf[mbufi_baseStationAngles + 4];
u_baseStationAngles_bh.bytebuffer[2] = mbuf[mbufi_baseStationAngles + 5];
u_baseStationAngles_bh.bytebuffer[1] = mbuf[mbufi_baseStationAngles + 6];
u_baseStationAngles_bh.bytebuffer[0] = mbuf[mbufi_baseStationAngles + 7];
mbufi_baseStationAngles += 8;
union u_baseStationAngles_bv_t {
double p;
byte bytebuffer[8];
} u_baseStationAngles_bv;
u_baseStationAngles_bv.bytebuffer[7] = mbuf[mbufi_baseStationAngles + 0];
u_baseStationAngles_bv.bytebuffer[6] = mbuf[mbufi_baseStationAngles + 1];
u_baseStationAngles_bv.bytebuffer[5] = mbuf[mbufi_baseStationAngles + 2];
u_baseStationAngles_bv.bytebuffer[4] = mbuf[mbufi_baseStationAngles + 3];
u_baseStationAngles_bv.bytebuffer[3] = mbuf[mbufi_baseStationAngles + 4];
u_baseStationAngles_bv.bytebuffer[2] = mbuf[mbufi_baseStationAngles + 5];
u_baseStationAngles_bv.bytebuffer[1] = mbuf[mbufi_baseStationAngles + 6];
u_baseStationAngles_bv.bytebuffer[0] = mbuf[mbufi_baseStationAngles + 7];
mbufi_baseStationAngles += 8;
union u_baseStationAngles_ch_t {
double p;
byte bytebuffer[8];
} u_baseStationAngles_ch;
u_baseStationAngles_ch.bytebuffer[7] = mbuf[mbufi_baseStationAngles + 0];
u_baseStationAngles_ch.bytebuffer[6] = mbuf[mbufi_baseStationAngles + 1];
u_baseStationAngles_ch.bytebuffer[5] = mbuf[mbufi_baseStationAngles + 2];
u_baseStationAngles_ch.bytebuffer[4] = mbuf[mbufi_baseStationAngles + 3];
u_baseStationAngles_ch.bytebuffer[3] = mbuf[mbufi_baseStationAngles + 4];
u_baseStationAngles_ch.bytebuffer[2] = mbuf[mbufi_baseStationAngles + 5];
u_baseStationAngles_ch.bytebuffer[1] = mbuf[mbufi_baseStationAngles + 6];
u_baseStationAngles_ch.bytebuffer[0] = mbuf[mbufi_baseStationAngles + 7];
mbufi_baseStationAngles += 8;
union u_baseStationAngles_cv_t {
double p;
byte bytebuffer[8];
} u_baseStationAngles_cv;
u_baseStationAngles_cv.bytebuffer[7] = mbuf[mbufi_baseStationAngles + 0];
u_baseStationAngles_cv.bytebuffer[6] = mbuf[mbufi_baseStationAngles + 1];
u_baseStationAngles_cv.bytebuffer[5] = mbuf[mbufi_baseStationAngles + 2];
u_baseStationAngles_cv.bytebuffer[4] = mbuf[mbufi_baseStationAngles + 3];
u_baseStationAngles_cv.bytebuffer[3] = mbuf[mbufi_baseStationAngles + 4];
u_baseStationAngles_cv.bytebuffer[2] = mbuf[mbufi_baseStationAngles + 5];
u_baseStationAngles_cv.bytebuffer[1] = mbuf[mbufi_baseStationAngles + 6];
u_baseStationAngles_cv.bytebuffer[0] = mbuf[mbufi_baseStationAngles + 7];
mbufi_baseStationAngles += 8;
dispatch_baseStationAngles((mbuf[0] << 8) + mbuf[1] /* instance port*/,
 u_baseStationAngles_bh.p /* bh */ ,
 u_baseStationAngles_bv.p /* bv */ ,
 u_baseStationAngles_ch.p /* ch */ ,
 u_baseStationAngles_cv.p /* cv */ );
break;
}
case 24:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_long_press = 2;
dispatch_long_press((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
case 37:{
byte mbuf[100 - 2];
while (mbufi < (100 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_calibrationreceived = 2;
union u_calibrationreceived_bx_t {
double p;
byte bytebuffer[8];
} u_calibrationreceived_bx;
u_calibrationreceived_bx.bytebuffer[7] = mbuf[mbufi_calibrationreceived + 0];
u_calibrationreceived_bx.bytebuffer[6] = mbuf[mbufi_calibrationreceived + 1];
u_calibrationreceived_bx.bytebuffer[5] = mbuf[mbufi_calibrationreceived + 2];
u_calibrationreceived_bx.bytebuffer[4] = mbuf[mbufi_calibrationreceived + 3];
u_calibrationreceived_bx.bytebuffer[3] = mbuf[mbufi_calibrationreceived + 4];
u_calibrationreceived_bx.bytebuffer[2] = mbuf[mbufi_calibrationreceived + 5];
u_calibrationreceived_bx.bytebuffer[1] = mbuf[mbufi_calibrationreceived + 6];
u_calibrationreceived_bx.bytebuffer[0] = mbuf[mbufi_calibrationreceived + 7];
mbufi_calibrationreceived += 8;
union u_calibrationreceived_by_t {
double p;
byte bytebuffer[8];
} u_calibrationreceived_by;
u_calibrationreceived_by.bytebuffer[7] = mbuf[mbufi_calibrationreceived + 0];
u_calibrationreceived_by.bytebuffer[6] = mbuf[mbufi_calibrationreceived + 1];
u_calibrationreceived_by.bytebuffer[5] = mbuf[mbufi_calibrationreceived + 2];
u_calibrationreceived_by.bytebuffer[4] = mbuf[mbufi_calibrationreceived + 3];
u_calibrationreceived_by.bytebuffer[3] = mbuf[mbufi_calibrationreceived + 4];
u_calibrationreceived_by.bytebuffer[2] = mbuf[mbufi_calibrationreceived + 5];
u_calibrationreceived_by.bytebuffer[1] = mbuf[mbufi_calibrationreceived + 6];
u_calibrationreceived_by.bytebuffer[0] = mbuf[mbufi_calibrationreceived + 7];
mbufi_calibrationreceived += 8;
union u_calibrationreceived_bz_t {
double p;
byte bytebuffer[8];
} u_calibrationreceived_bz;
u_calibrationreceived_bz.bytebuffer[7] = mbuf[mbufi_calibrationreceived + 0];
u_calibrationreceived_bz.bytebuffer[6] = mbuf[mbufi_calibrationreceived + 1];
u_calibrationreceived_bz.bytebuffer[5] = mbuf[mbufi_calibrationreceived + 2];
u_calibrationreceived_bz.bytebuffer[4] = mbuf[mbufi_calibrationreceived + 3];
u_calibrationreceived_bz.bytebuffer[3] = mbuf[mbufi_calibrationreceived + 4];
u_calibrationreceived_bz.bytebuffer[2] = mbuf[mbufi_calibrationreceived + 5];
u_calibrationreceived_bz.bytebuffer[1] = mbuf[mbufi_calibrationreceived + 6];
u_calibrationreceived_bz.bytebuffer[0] = mbuf[mbufi_calibrationreceived + 7];
mbufi_calibrationreceived += 8;
union u_calibrationreceived_brx_t {
double p;
byte bytebuffer[8];
} u_calibrationreceived_brx;
u_calibrationreceived_brx.bytebuffer[7] = mbuf[mbufi_calibrationreceived + 0];
u_calibrationreceived_brx.bytebuffer[6] = mbuf[mbufi_calibrationreceived + 1];
u_calibrationreceived_brx.bytebuffer[5] = mbuf[mbufi_calibrationreceived + 2];
u_calibrationreceived_brx.bytebuffer[4] = mbuf[mbufi_calibrationreceived + 3];
u_calibrationreceived_brx.bytebuffer[3] = mbuf[mbufi_calibrationreceived + 4];
u_calibrationreceived_brx.bytebuffer[2] = mbuf[mbufi_calibrationreceived + 5];
u_calibrationreceived_brx.bytebuffer[1] = mbuf[mbufi_calibrationreceived + 6];
u_calibrationreceived_brx.bytebuffer[0] = mbuf[mbufi_calibrationreceived + 7];
mbufi_calibrationreceived += 8;
union u_calibrationreceived_bry_t {
double p;
byte bytebuffer[8];
} u_calibrationreceived_bry;
u_calibrationreceived_bry.bytebuffer[7] = mbuf[mbufi_calibrationreceived + 0];
u_calibrationreceived_bry.bytebuffer[6] = mbuf[mbufi_calibrationreceived + 1];
u_calibrationreceived_bry.bytebuffer[5] = mbuf[mbufi_calibrationreceived + 2];
u_calibrationreceived_bry.bytebuffer[4] = mbuf[mbufi_calibrationreceived + 3];
u_calibrationreceived_bry.bytebuffer[3] = mbuf[mbufi_calibrationreceived + 4];
u_calibrationreceived_bry.bytebuffer[2] = mbuf[mbufi_calibrationreceived + 5];
u_calibrationreceived_bry.bytebuffer[1] = mbuf[mbufi_calibrationreceived + 6];
u_calibrationreceived_bry.bytebuffer[0] = mbuf[mbufi_calibrationreceived + 7];
mbufi_calibrationreceived += 8;
union u_calibrationreceived_brz_t {
double p;
byte bytebuffer[8];
} u_calibrationreceived_brz;
u_calibrationreceived_brz.bytebuffer[7] = mbuf[mbufi_calibrationreceived + 0];
u_calibrationreceived_brz.bytebuffer[6] = mbuf[mbufi_calibrationreceived + 1];
u_calibrationreceived_brz.bytebuffer[5] = mbuf[mbufi_calibrationreceived + 2];
u_calibrationreceived_brz.bytebuffer[4] = mbuf[mbufi_calibrationreceived + 3];
u_calibrationreceived_brz.bytebuffer[3] = mbuf[mbufi_calibrationreceived + 4];
u_calibrationreceived_brz.bytebuffer[2] = mbuf[mbufi_calibrationreceived + 5];
u_calibrationreceived_brz.bytebuffer[1] = mbuf[mbufi_calibrationreceived + 6];
u_calibrationreceived_brz.bytebuffer[0] = mbuf[mbufi_calibrationreceived + 7];
mbufi_calibrationreceived += 8;
union u_calibrationreceived_cx_t {
double p;
byte bytebuffer[8];
} u_calibrationreceived_cx;
u_calibrationreceived_cx.bytebuffer[7] = mbuf[mbufi_calibrationreceived + 0];
u_calibrationreceived_cx.bytebuffer[6] = mbuf[mbufi_calibrationreceived + 1];
u_calibrationreceived_cx.bytebuffer[5] = mbuf[mbufi_calibrationreceived + 2];
u_calibrationreceived_cx.bytebuffer[4] = mbuf[mbufi_calibrationreceived + 3];
u_calibrationreceived_cx.bytebuffer[3] = mbuf[mbufi_calibrationreceived + 4];
u_calibrationreceived_cx.bytebuffer[2] = mbuf[mbufi_calibrationreceived + 5];
u_calibrationreceived_cx.bytebuffer[1] = mbuf[mbufi_calibrationreceived + 6];
u_calibrationreceived_cx.bytebuffer[0] = mbuf[mbufi_calibrationreceived + 7];
mbufi_calibrationreceived += 8;
union u_calibrationreceived_cy_t {
double p;
byte bytebuffer[8];
} u_calibrationreceived_cy;
u_calibrationreceived_cy.bytebuffer[7] = mbuf[mbufi_calibrationreceived + 0];
u_calibrationreceived_cy.bytebuffer[6] = mbuf[mbufi_calibrationreceived + 1];
u_calibrationreceived_cy.bytebuffer[5] = mbuf[mbufi_calibrationreceived + 2];
u_calibrationreceived_cy.bytebuffer[4] = mbuf[mbufi_calibrationreceived + 3];
u_calibrationreceived_cy.bytebuffer[3] = mbuf[mbufi_calibrationreceived + 4];
u_calibrationreceived_cy.bytebuffer[2] = mbuf[mbufi_calibrationreceived + 5];
u_calibrationreceived_cy.bytebuffer[1] = mbuf[mbufi_calibrationreceived + 6];
u_calibrationreceived_cy.bytebuffer[0] = mbuf[mbufi_calibrationreceived + 7];
mbufi_calibrationreceived += 8;
union u_calibrationreceived_cz_t {
double p;
byte bytebuffer[8];
} u_calibrationreceived_cz;
u_calibrationreceived_cz.bytebuffer[7] = mbuf[mbufi_calibrationreceived + 0];
u_calibrationreceived_cz.bytebuffer[6] = mbuf[mbufi_calibrationreceived + 1];
u_calibrationreceived_cz.bytebuffer[5] = mbuf[mbufi_calibrationreceived + 2];
u_calibrationreceived_cz.bytebuffer[4] = mbuf[mbufi_calibrationreceived + 3];
u_calibrationreceived_cz.bytebuffer[3] = mbuf[mbufi_calibrationreceived + 4];
u_calibrationreceived_cz.bytebuffer[2] = mbuf[mbufi_calibrationreceived + 5];
u_calibrationreceived_cz.bytebuffer[1] = mbuf[mbufi_calibrationreceived + 6];
u_calibrationreceived_cz.bytebuffer[0] = mbuf[mbufi_calibrationreceived + 7];
mbufi_calibrationreceived += 8;
union u_calibrationreceived_crx_t {
double p;
byte bytebuffer[8];
} u_calibrationreceived_crx;
u_calibrationreceived_crx.bytebuffer[7] = mbuf[mbufi_calibrationreceived + 0];
u_calibrationreceived_crx.bytebuffer[6] = mbuf[mbufi_calibrationreceived + 1];
u_calibrationreceived_crx.bytebuffer[5] = mbuf[mbufi_calibrationreceived + 2];
u_calibrationreceived_crx.bytebuffer[4] = mbuf[mbufi_calibrationreceived + 3];
u_calibrationreceived_crx.bytebuffer[3] = mbuf[mbufi_calibrationreceived + 4];
u_calibrationreceived_crx.bytebuffer[2] = mbuf[mbufi_calibrationreceived + 5];
u_calibrationreceived_crx.bytebuffer[1] = mbuf[mbufi_calibrationreceived + 6];
u_calibrationreceived_crx.bytebuffer[0] = mbuf[mbufi_calibrationreceived + 7];
mbufi_calibrationreceived += 8;
union u_calibrationreceived_cry_t {
double p;
byte bytebuffer[8];
} u_calibrationreceived_cry;
u_calibrationreceived_cry.bytebuffer[7] = mbuf[mbufi_calibrationreceived + 0];
u_calibrationreceived_cry.bytebuffer[6] = mbuf[mbufi_calibrationreceived + 1];
u_calibrationreceived_cry.bytebuffer[5] = mbuf[mbufi_calibrationreceived + 2];
u_calibrationreceived_cry.bytebuffer[4] = mbuf[mbufi_calibrationreceived + 3];
u_calibrationreceived_cry.bytebuffer[3] = mbuf[mbufi_calibrationreceived + 4];
u_calibrationreceived_cry.bytebuffer[2] = mbuf[mbufi_calibrationreceived + 5];
u_calibrationreceived_cry.bytebuffer[1] = mbuf[mbufi_calibrationreceived + 6];
u_calibrationreceived_cry.bytebuffer[0] = mbuf[mbufi_calibrationreceived + 7];
mbufi_calibrationreceived += 8;
union u_calibrationreceived_crz_t {
double p;
byte bytebuffer[8];
} u_calibrationreceived_crz;
u_calibrationreceived_crz.bytebuffer[7] = mbuf[mbufi_calibrationreceived + 0];
u_calibrationreceived_crz.bytebuffer[6] = mbuf[mbufi_calibrationreceived + 1];
u_calibrationreceived_crz.bytebuffer[5] = mbuf[mbufi_calibrationreceived + 2];
u_calibrationreceived_crz.bytebuffer[4] = mbuf[mbufi_calibrationreceived + 3];
u_calibrationreceived_crz.bytebuffer[3] = mbuf[mbufi_calibrationreceived + 4];
u_calibrationreceived_crz.bytebuffer[2] = mbuf[mbufi_calibrationreceived + 5];
u_calibrationreceived_crz.bytebuffer[1] = mbuf[mbufi_calibrationreceived + 6];
u_calibrationreceived_crz.bytebuffer[0] = mbuf[mbufi_calibrationreceived + 7];
mbufi_calibrationreceived += 8;
dispatch_calibrationreceived((mbuf[0] << 8) + mbuf[1] /* instance port*/,
 u_calibrationreceived_bx.p /* bx */ ,
 u_calibrationreceived_by.p /* by */ ,
 u_calibrationreceived_bz.p /* bz */ ,
 u_calibrationreceived_brx.p /* brx */ ,
 u_calibrationreceived_bry.p /* bry */ ,
 u_calibrationreceived_brz.p /* brz */ ,
 u_calibrationreceived_cx.p /* cx */ ,
 u_calibrationreceived_cy.p /* cy */ ,
 u_calibrationreceived_cz.p /* cz */ ,
 u_calibrationreceived_crx.p /* crx */ ,
 u_calibrationreceived_cry.p /* cry */ ,
 u_calibrationreceived_crz.p /* crz */ );
break;
}
}
return 1;
}


//external Message enqueue

void initialize_configuration_Teensy_IRPS() {
// Initialize connectors
register_AngleReader_send_AngleSender_allAngles_listener(&enqueue_AngleReader_send_AngleSender_allAngles);
register_AngleReader_send_StatusSender_status_listener(&enqueue_AngleReader_send_StatusSender_status);
register_AngleReader_send_Transitions_startTimeCalibrated_listener(&enqueue_AngleReader_send_Transitions_startTimeCalibrated);
register_AngleReader_send_Transitions_recalibrate_listener(&enqueue_AngleReader_send_Transitions_recalibrate);
register_Button_send_clock_ms25_tic_listener(&enqueue_Button_send_clock_ms25_tic);
register_Button_send_evt_press_listener(&enqueue_Button_send_evt_press);
register_Button_send_evt_release_listener(&enqueue_Button_send_evt_release);
register_PackageReader_send_PackageSender_packageDetectedEvent_listener(&enqueue_PackageReader_send_PackageSender_packageDetectedEvent);
register_PackageReader_send_StatusSender_status_listener(&enqueue_PackageReader_send_StatusSender_status);
register_CalibrationStorer_send_storeReader_readByte_listener(&enqueue_CalibrationStorer_send_storeReader_readByte);
register_CalibrationStorer_send_storeReader_readConfig_listener(&enqueue_CalibrationStorer_send_storeReader_readConfig);
register_CalibrationStorer_send_storeWriter_writeByte_listener(&enqueue_CalibrationStorer_send_storeWriter_writeByte);
register_CalibrationStorer_send_storeWriter_writeConfig_listener(&enqueue_CalibrationStorer_send_storeWriter_writeConfig);
register_CalibrationStorer_send_storer_endload_listener(&enqueue_CalibrationStorer_send_storer_endload);
register_CalibrationStorer_send_storer_errorload_listener(&enqueue_CalibrationStorer_send_storer_errorload);
register_CalibrationStorer_send_progress_storerToIdle_listener(&enqueue_CalibrationStorer_send_progress_storerToIdle);
register_Storer_send_reader_byteRead_listener(&enqueue_Storer_send_reader_byteRead);
register_Storer_send_reader_configRead_listener(&enqueue_Storer_send_reader_configRead);
register_Storer_send_writer_byteWritten_listener(&enqueue_Storer_send_writer_byteWritten);
register_Storer_send_writer_configWritten_listener(&enqueue_Storer_send_writer_configWritten);
register_Runner_send_Run_coordinates_listener(&enqueue_Runner_send_Run_coordinates);
register_Runner_send_StatusSender_status_listener(&enqueue_Runner_send_StatusSender_status);
register_SoftButton_send_Timer_timer_timeout_listener(&enqueue_SoftButton_send_Timer_timer_timeout);
register_SoftButton_send_SoftButton_click_listener(&enqueue_SoftButton_send_SoftButton_click);
register_SoftButton_send_SoftButton_double_click_listener(&enqueue_SoftButton_send_SoftButton_double_click);
register_SoftButton_send_SoftButton_long_press_listener(&enqueue_SoftButton_send_SoftButton_long_press);
register_Calibrator_send_calibrator_endcalibrate_listener(&enqueue_Calibrator_send_calibrator_endcalibrate);
register_Calibrator_send_calibrator_errcalibrate_listener(&enqueue_Calibrator_send_calibrator_errcalibrate);
register_Calibrator_send_calibrator_calibrationfromserial_listener(&enqueue_Calibrator_send_calibrator_calibrationfromserial);
register_Calibrator_send_StatusSender_status_listener(&enqueue_Calibrator_send_StatusSender_status);
register_Calibrator_send_avt_calibrating_listener(&enqueue_Calibrator_send_avt_calibrating);
register_Calibrator_send_avt_calibrationComplete_listener(&enqueue_Calibrator_send_avt_calibrationComplete);
register_Calibrator_send_avt_calibrationFailed_listener(&enqueue_Calibrator_send_avt_calibrationFailed);
register_CalibrationValidator_send_validator_endvalidate_listener(&enqueue_CalibrationValidator_send_validator_endvalidate);
register_CalibrationValidator_send_validator_errvalidate_listener(&enqueue_CalibrationValidator_send_validator_errvalidate);
register_CalibrationValidator_send_avt_validating_listener(&enqueue_CalibrationValidator_send_avt_validating);
register_PulseReader_send_PulseSender_pulseDetectedEvent_listener(&enqueue_PulseReader_send_PulseSender_pulseDetectedEvent);
register_PulseReader_send_OverflowNotifier_timerOverflow_listener(&enqueue_PulseReader_send_OverflowNotifier_timerOverflow);
register_PulseReader_send_Transitions_pulseDetected_listener(&enqueue_PulseReader_send_Transitions_pulseDetected);
register_SerialIn_send_serialcall_calibrationreceived_listener(&enqueue_SerialIn_send_serialcall_calibrationreceived);
register_SerialIn_send_Timer_serial_timeout_listener(&enqueue_SerialIn_send_Timer_serial_timeout);
register_Backbone_send_Run_baseStationAngles_listener(&enqueue_Backbone_send_Run_baseStationAngles);
register_Backbone_send_CalibrationStorer_load_listener(&enqueue_Backbone_send_CalibrationStorer_load);
register_Backbone_send_CalibrationStorer_save_listener(&enqueue_Backbone_send_CalibrationStorer_save);
register_Backbone_send_validator_validate_listener(&enqueue_Backbone_send_validator_validate);
register_Backbone_send_calibrator_calibrate_listener(&enqueue_Backbone_send_calibrator_calibrate);
register_Backbone_send_calibrator_entrypoint_listener(&enqueue_Backbone_send_calibrator_entrypoint);
register_Backbone_send_calibrator_receiveAngles_listener(&enqueue_Backbone_send_calibrator_receiveAngles);
register_Backbone_send_calibrator_receivecalibration_listener(&enqueue_Backbone_send_calibrator_receivecalibration);
register_Backbone_send_printer_printStatus_listener(&enqueue_Backbone_send_printer_printStatus);
register_Backbone_send_printer_printOperationState_listener(&enqueue_Backbone_send_printer_printOperationState);
register_Backbone_send_printer_printPoint_listener(&enqueue_Backbone_send_printer_printPoint);
register_Backbone_send_serialRead_waitcalibration_listener(&enqueue_Backbone_send_serialRead_waitcalibration);
register_Backbone_send_pixel_stateID_listener(&enqueue_Backbone_send_pixel_stateID);
register_Backbone_send_pixel_statusID_listener(&enqueue_Backbone_send_pixel_statusID);
register_Backbone_send_StateHandler_currentState_listener(&enqueue_Backbone_send_StateHandler_currentState);
register_Backbone_send_transitions_toIdle_listener(&enqueue_Backbone_send_transitions_toIdle);
register_Blinker_send_evt_blink_listener(&enqueue_Blinker_send_evt_blink);


// Network Initialization
// End Network Initialization

// Init the ID, state variables and properties for instance angleReader
angleReader_var.active = true;
angleReader_var.id_PackageReceiver = add_instance( (void*) &angleReader_var);
angleReader_var.id_AngleSender = add_instance( (void*) &angleReader_var);
angleReader_var.id_OverflowNotifier = add_instance( (void*) &angleReader_var);
angleReader_var.id_StatusSender = add_instance( (void*) &angleReader_var);
angleReader_var.id_Transitions = add_instance( (void*) &angleReader_var);
angleReader_var.AngleReader_SingalDetectionStrategy_State = ANGLEREADER_SINGALDETECTIONSTRATEGY_PULSEWIDTHS_STATE;

AngleReader_SingalDetectionStrategy_OnEntry(ANGLEREADER_SINGALDETECTIONSTRATEGY_STATE, &angleReader_var);
// Init the ID, state variables and properties for instance button
button_var.active = true;
button_var.id_clock = add_instance( (void*) &button_var);
button_var.id_evt = add_instance( (void*) &button_var);
button_var.Button_Button_State = BUTTON_BUTTON_RELEASED_STATE;
button_var.Button_PIN_var = 7;

Button_Button_OnEntry(BUTTON_BUTTON_STATE, &button_var);
// Init the ID, state variables and properties for instance serial
serial_var.active = true;
serial_var.id_basic = add_instance( (void*) &serial_var);
serial_var.SerialOut_Message_State = SERIALOUT_MESSAGE_IDLE_STATE;

SerialOut_Message_OnEntry(SERIALOUT_MESSAGE_STATE, &serial_var);
// Init the ID, state variables and properties for instance packageReader
packageReader_var.active = true;
packageReader_var.id_PulseReceiver = add_instance( (void*) &packageReader_var);
packageReader_var.id_PackageSender = add_instance( (void*) &packageReader_var);
packageReader_var.id_StatusSender = add_instance( (void*) &packageReader_var);
packageReader_var.PackageReader_PackageRead_State = PACKAGEREADER_PACKAGEREAD_IDLE_STATE;

PackageReader_PackageRead_OnEntry(PACKAGEREADER_PACKAGEREAD_STATE, &packageReader_var);
// Init the ID, state variables and properties for instance storer
storer_var.active = true;
storer_var.id_reader = add_instance( (void*) &storer_var);
storer_var.id_writer = add_instance( (void*) &storer_var);
storer_var.Storer_EESave_State = STORER_EESAVE_IDLE_STATE;

Storer_EESave_OnEntry(STORER_EESAVE_STATE, &storer_var);
// Init the ID, state variables and properties for instance calibrationStorer
calibrationStorer_var.active = true;
calibrationStorer_var.id_storeReader = add_instance( (void*) &calibrationStorer_var);
calibrationStorer_var.id_storeWriter = add_instance( (void*) &calibrationStorer_var);
calibrationStorer_var.id_storer = add_instance( (void*) &calibrationStorer_var);
calibrationStorer_var.id_progress = add_instance( (void*) &calibrationStorer_var);
calibrationStorer_var.CalibrationStorer_Loader_State = CALIBRATIONSTORER_LOADER_IDLE_STATE;

CalibrationStorer_Loader_OnEntry(CALIBRATIONSTORER_LOADER_STATE, &calibrationStorer_var);
// Init the ID, state variables and properties for instance runner
runner_var.active = true;
runner_var.id_Run = add_instance( (void*) &runner_var);
runner_var.id_StatusSender = add_instance( (void*) &runner_var);
runner_var.Runner_Running_State = RUNNER_RUNNING_IDLE_STATE;

Runner_Running_OnEntry(RUNNER_RUNNING_STATE, &runner_var);
// Init the ID, state variables and properties for instance softButton
softButton_var.active = true;
softButton_var.id_Button = add_instance( (void*) &softButton_var);
softButton_var.id_Timer = add_instance( (void*) &softButton_var);
softButton_var.id_SoftButton = add_instance( (void*) &softButton_var);
softButton_var.SoftButton_SoftButtonImpl_State = SOFTBUTTON_SOFTBUTTONIMPL_IDLE_STATE;
softButton_var.SoftButton_long_delay_var = 1000;
softButton_var.SoftButton_double_delay_var = 250;

SoftButton_SoftButtonImpl_OnEntry(SOFTBUTTON_SOFTBUTTONIMPL_STATE, &softButton_var);
// Init the ID, state variables and properties for instance calibrator
calibrator_var.active = true;
calibrator_var.id_calibrator = add_instance( (void*) &calibrator_var);
calibrator_var.id_StatusSender = add_instance( (void*) &calibrator_var);
calibrator_var.id_avt = add_instance( (void*) &calibrator_var);
calibrator_var.Calibrator_Calibrator_State = CALIBRATOR_CALIBRATOR_IDLE_STATE;

Calibrator_Calibrator_OnEntry(CALIBRATOR_CALIBRATOR_STATE, &calibrator_var);
// Init the ID, state variables and properties for instance calibrationValidator
calibrationValidator_var.active = true;
calibrationValidator_var.id_validator = add_instance( (void*) &calibrationValidator_var);
calibrationValidator_var.id_avt = add_instance( (void*) &calibrationValidator_var);
calibrationValidator_var.CalibrationValidator_Validator_State = CALIBRATIONVALIDATOR_VALIDATOR_IDLE_STATE;

CalibrationValidator_Validator_OnEntry(CALIBRATIONVALIDATOR_VALIDATOR_STATE, &calibrationValidator_var);
// Init the ID, state variables and properties for instance pulseReader
pulseReader_var.active = true;
pulseReader_var.id_PulseSender = add_instance( (void*) &pulseReader_var);
pulseReader_var.id_OverflowNotifier = add_instance( (void*) &pulseReader_var);
pulseReader_var.id_Transitions = add_instance( (void*) &pulseReader_var);
pulseReader_var.PulseReader_PulseRead_State = PULSEREADER_PULSEREAD_IDLE_STATE;

PulseReader_PulseRead_OnEntry(PULSEREADER_PULSEREAD_STATE, &pulseReader_var);
// Init the ID, state variables and properties for instance serialIn
serialIn_var.active = true;
serialIn_var.id_serialcall = add_instance( (void*) &serialIn_var);
serialIn_var.id_Timer = add_instance( (void*) &serialIn_var);
serialIn_var.SerialIn_serialreader_State = SERIALIN_SERIALREADER_IDLE_STATE;

SerialIn_serialreader_OnEntry(SERIALIN_SERIALREADER_STATE, &serialIn_var);
// Init the ID, state variables and properties for instance blinker
blinker_var.active = true;
blinker_var.id_evt = add_instance( (void*) &blinker_var);
blinker_var.id_neopixel = add_instance( (void*) &blinker_var);
blinker_var.Blinker_BlinkerState_State = BLINKER_BLINKERSTATE_IDLE_STATE;

Blinker_BlinkerState_OnEntry(BLINKER_BLINKERSTATE_STATE, &blinker_var);
// Init the ID, state variables and properties for instance backbone
backbone_var.active = true;
backbone_var.id_Output = add_instance( (void*) &backbone_var);
backbone_var.id_AngleReceiver = add_instance( (void*) &backbone_var);
backbone_var.id_Run = add_instance( (void*) &backbone_var);
backbone_var.id_CalibrationStorer = add_instance( (void*) &backbone_var);
backbone_var.id_validator = add_instance( (void*) &backbone_var);
backbone_var.id_calibrator = add_instance( (void*) &backbone_var);
backbone_var.id_printer = add_instance( (void*) &backbone_var);
backbone_var.id_serialRead = add_instance( (void*) &backbone_var);
backbone_var.id_pixel = add_instance( (void*) &backbone_var);
backbone_var.id_presser = add_instance( (void*) &backbone_var);
backbone_var.id_StatusHandler = add_instance( (void*) &backbone_var);
backbone_var.id_StateHandler = add_instance( (void*) &backbone_var);
backbone_var.id_transitions = add_instance( (void*) &backbone_var);
backbone_var.Backbone_Main_State = BACKBONE_MAIN_LOAD_CALIBRATION_STATE;

Backbone_Main_OnEntry(BACKBONE_MAIN_STATE, &backbone_var);
}




int main(){

	initialize_configuration_Teensy_IRPS();


	while(1) {
	
// Network Listener// End Network Listener

int emptyEventConsumed = 1;
while (emptyEventConsumed != 0) {
emptyEventConsumed = 0;
}

	    processMessageQueue();
	}

}