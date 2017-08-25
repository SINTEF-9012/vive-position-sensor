#include "Calibrator.h"
/*****************************************************************************
 * Implementation for type : Calibrator
 *****************************************************************************/


// BEGIN: Code from the c_global annotation Calibrator

    double angleValues[CALIBRATION_POINT_COLLECTION_COUNT][4] = {0};
    int angleIndex = 0;
    bool endCalibration = 0;
    
    uint8_t fourCounter = 0;

// END: Code from the c_global annotation Calibrator

// Declaration of prototypes:
//Prototypes: State Machine
void Calibrator_Calibrator_OnExit(int state, struct Calibrator_Instance *_instance);
//Prototypes: Message Sending
void Calibrator_send_calibrator_endcalibrate(struct Calibrator_Instance *_instance);
void Calibrator_send_calibrator_errcalibrate(struct Calibrator_Instance *_instance);
void Calibrator_send_calibrator_calibrationfromserial(struct Calibrator_Instance *_instance);
void Calibrator_send_StatusSender_status(struct Calibrator_Instance *_instance, uint8_t id);
void Calibrator_send_avt_calibrating(struct Calibrator_Instance *_instance);
void Calibrator_send_avt_calibrationComplete(struct Calibrator_Instance *_instance);
void Calibrator_send_avt_calibrationFailed(struct Calibrator_Instance *_instance);
//Prototypes: Function
void f_Calibrator_printAngles(struct Calibrator_Instance *_instance, double bh, double bv, double ch, double cv);
void f_Calibrator_printVariation(struct Calibrator_Instance *_instance, double bh, double bv, double ch, double cv);
void f_Calibrator_printCalibration(struct Calibrator_Instance *_instance);
// Declaration of functions:
// Definition of function printAngles
void f_Calibrator_printAngles(struct Calibrator_Instance *_instance, double bh, double bv, double ch, double cv) {
if (VERBOSE) Serial.print("\nF,");
        else Serial.print("\nAverage Angles:\t");
        
        Serial.print(bh,6);
        Serial.print(",");
        Serial.print(bv,6);
        Serial.print(",");
        Serial.print(ch,6);
        Serial.print(",");
        Serial.print(cv,6);
        Serial.print(",");
}
// Definition of function printVariation
void f_Calibrator_printVariation(struct Calibrator_Instance *_instance, double bh, double bv, double ch, double cv) {
if (VERBOSE) Serial.print("\nG,");
        else Serial.print("\nVariation Angles:\t");
        
        Serial.print(bh,6);
        Serial.print(",");
        Serial.print(bv,6);
        Serial.print(",");
        Serial.print(ch,6);
        Serial.print(",");
        Serial.print(cv,6);
        Serial.print(",");
}
// Definition of function printCalibration
void f_Calibrator_printCalibration(struct Calibrator_Instance *_instance) {

	   if (VERBOSE) Serial.print("\nK,");
	   else Serial.print("\nCalibration:\n\nPb:\t");
	   
	   Serial.print(",");
       Serial.print(posePb.position.getX());
       Serial.print(",");
       Serial.print(posePb.position.getY());
       Serial.print(",");
       Serial.print(posePb.position.getZ());
       Serial.print(",");
       Serial.print(posePb.orientation.getX());
       Serial.print(",");
       Serial.print(posePb.orientation.getY());
       Serial.print(",");
       Serial.println(posePb.orientation.getZ());
       Serial.print(",");

       if (!VERBOSE) Serial.print("\nPc:\t");
       
       Serial.print(posePc.position.getX());
       Serial.print(",");
       Serial.print(posePc.position.getY());
       Serial.print(",");
       Serial.print(posePc.position.getZ());
       Serial.print(",");
       Serial.print(posePc.orientation.getX());
       Serial.print(",");
       Serial.print(posePc.orientation.getY());
       Serial.print(",");
       Serial.println(posePc.orientation.getZ());
       Serial.print(",");
       
       if (!VERBOSE) Serial.print("\n Point 4 error:\t");
       
       Serial.print(pointError);
	   Serial.print(",");
	   
	   if (!VERBOSE) Serial.print("\n");
	   
}

// Sessions functionss:


// On Entry Actions:
void Calibrator_Calibrator_OnEntry(int state, struct Calibrator_Instance *_instance) {
switch(state) {
case CALIBRATOR_CALIBRATOR_STATE:{
_instance->Calibrator_Calibrator_State = CALIBRATOR_CALIBRATOR_IDLE_STATE;
Calibrator_Calibrator_OnEntry(_instance->Calibrator_Calibrator_State, _instance);
break;
}
case CALIBRATOR_CALIBRATOR_IDLE_STATE:{
break;
}
case CALIBRATOR_CALIBRATOR_CALIBRATE_STATE:{
if(endCalibration) {
if(calibrationFailed) {
Calibrator_send_StatusSender_status(_instance, 7);
Calibrator_send_avt_calibrationFailed(_instance);

} else {
Calibrator_send_StatusSender_status(_instance, 4);
if(DEBUG) {
f_Calibrator_printCalibration(_instance);

}
Calibrator_send_avt_calibrationComplete(_instance);

}

                    endCalibration = 0;
                    calibrationFailed = false;
                    

}
break;
}
case CALIBRATOR_CALIBRATOR_POINTCOLLECT_STATE:{
angleIndex = 0;
Calibrator_send_StatusSender_status(_instance, 2);
break;
}
default: break;
}
}

// On Exit Actions:
void Calibrator_Calibrator_OnExit(int state, struct Calibrator_Instance *_instance) {
switch(state) {
case CALIBRATOR_CALIBRATOR_STATE:{
Calibrator_Calibrator_OnExit(_instance->Calibrator_Calibrator_State, _instance);
break;}
case CALIBRATOR_CALIBRATOR_IDLE_STATE:{
break;}
case CALIBRATOR_CALIBRATOR_CALIBRATE_STATE:{
break;}
case CALIBRATOR_CALIBRATOR_POINTCOLLECT_STATE:{
break;}
default: break;
}
}

// Event Handlers for incoming messages:
void Calibrator_handle_avt_calibrationComplete(struct Calibrator_Instance *_instance) {
if(!(_instance->active)) return;
//Region Calibrator
uint8_t Calibrator_Calibrator_State_event_consumed = 0;
if (_instance->Calibrator_Calibrator_State == CALIBRATOR_CALIBRATOR_CALIBRATE_STATE) {
if (Calibrator_Calibrator_State_event_consumed == 0 && 1) {
Calibrator_Calibrator_OnExit(CALIBRATOR_CALIBRATOR_CALIBRATE_STATE, _instance);
_instance->Calibrator_Calibrator_State = CALIBRATOR_CALIBRATOR_IDLE_STATE;
Calibrator_send_calibrator_endcalibrate(_instance);
Calibrator_Calibrator_OnEntry(CALIBRATOR_CALIBRATOR_IDLE_STATE, _instance);
Calibrator_Calibrator_State_event_consumed = 1;
}
}
//End Region Calibrator
//End dsregion Calibrator
//Session list: 
}
void Calibrator_handle_avt_calibrationFailed(struct Calibrator_Instance *_instance) {
if(!(_instance->active)) return;
//Region Calibrator
uint8_t Calibrator_Calibrator_State_event_consumed = 0;
if (_instance->Calibrator_Calibrator_State == CALIBRATOR_CALIBRATOR_CALIBRATE_STATE) {
if (Calibrator_Calibrator_State_event_consumed == 0 && 1) {
Calibrator_Calibrator_OnExit(CALIBRATOR_CALIBRATOR_CALIBRATE_STATE, _instance);
_instance->Calibrator_Calibrator_State = CALIBRATOR_CALIBRATOR_IDLE_STATE;
Calibrator_send_calibrator_errcalibrate(_instance);
Calibrator_Calibrator_OnEntry(CALIBRATOR_CALIBRATOR_IDLE_STATE, _instance);
Calibrator_Calibrator_State_event_consumed = 1;
}
}
//End Region Calibrator
//End dsregion Calibrator
//Session list: 
}
void Calibrator_handle_avt_calibrating(struct Calibrator_Instance *_instance) {
if(!(_instance->active)) return;
//Region Calibrator
uint8_t Calibrator_Calibrator_State_event_consumed = 0;
if (_instance->Calibrator_Calibrator_State == CALIBRATOR_CALIBRATOR_POINTCOLLECT_STATE) {
if (Calibrator_Calibrator_State_event_consumed == 0 && 1) {
Calibrator_Calibrator_OnExit(CALIBRATOR_CALIBRATOR_POINTCOLLECT_STATE, _instance);
_instance->Calibrator_Calibrator_State = CALIBRATOR_CALIBRATOR_CALIBRATE_STATE;

                double largest[4] = {angleValues[0][0], angleValues[0][1], angleValues[0][2], angleValues[0][3]};
                double smallest[4] = {angleValues[0][0], angleValues[0][1], angleValues[0][2], angleValues[0][3]};
                double sum[4] = {0};
                
                for (int i = 0; i < CALIBRATION_POINT_COLLECTION_COUNT; i++) {
                    for (int j = 0; j <  4; j++) {
                        if (largest[j] < angleValues[i][j]) largest[j] = angleValues[i][j];
                        if (smallest[j] > angleValues[i][j]) smallest[j] = angleValues[i][j];
                        sum[j] += angleValues[i][j];
                    }
                }
                
                double average[4] = {0};
                bool ok = true;
                
                for (int j = 0; j <  4; j++) {
                    if (largest[j] - smallest[j] > LARGEST_ANGLE_DEVIATION_FOR_SINGLE_MEASURNMENT) {
ok = false;
                    }
                    average[j] = sum[j]/CALIBRATION_POINT_COLLECTION_COUNT;
                } 
                
                if (ok) {
                    
Calibrator_send_StatusSender_status(_instance, 8);

                    
                    STOP = true;
                    endCalibration = collectAnglesForPoint(average[0], average[1], average[2], average[3]);
                    STOP = false;
                    
if(DEBUG) {
f_Calibrator_printAngles(_instance, average[0], average[1], average[2], average[3]);

}
} else {
Calibrator_send_StatusSender_status(_instance, 9);
}
if(DEBUG) {
f_Calibrator_printVariation(_instance, largest[0]-smallest[0], largest[1]-smallest[1], largest[2]-smallest[2], largest[3]-smallest[3]);

}
Calibrator_Calibrator_OnEntry(CALIBRATOR_CALIBRATOR_CALIBRATE_STATE, _instance);
Calibrator_Calibrator_State_event_consumed = 1;
}
}
//End Region Calibrator
//End dsregion Calibrator
//Session list: 
}
void Calibrator_handle_calibrator_entrypoint(struct Calibrator_Instance *_instance) {
if(!(_instance->active)) return;
//Region Calibrator
uint8_t Calibrator_Calibrator_State_event_consumed = 0;
if (_instance->Calibrator_Calibrator_State == CALIBRATOR_CALIBRATOR_CALIBRATE_STATE) {
if (Calibrator_Calibrator_State_event_consumed == 0 && 1) {
Calibrator_Calibrator_OnExit(CALIBRATOR_CALIBRATOR_CALIBRATE_STATE, _instance);
_instance->Calibrator_Calibrator_State = CALIBRATOR_CALIBRATOR_POINTCOLLECT_STATE;
Calibrator_Calibrator_OnEntry(CALIBRATOR_CALIBRATOR_POINTCOLLECT_STATE, _instance);
Calibrator_Calibrator_State_event_consumed = 1;
}
}
//End Region Calibrator
//End dsregion Calibrator
//Session list: 
}
void Calibrator_handle_calibrator_receiveAngles(struct Calibrator_Instance *_instance, double bh, double bv, double ch, double cv) {
if(!(_instance->active)) return;
//Region Calibrator
uint8_t Calibrator_Calibrator_State_event_consumed = 0;
if (_instance->Calibrator_Calibrator_State == CALIBRATOR_CALIBRATOR_POINTCOLLECT_STATE) {
if (Calibrator_Calibrator_State_event_consumed == 0 && 1) {

                // Only collect data-points whena all have been refreshed
                if (++fourCounter == 4) {
                    fourCounter = 0;
                    
                    angleValues[angleIndex][0] = bh;
                    angleValues[angleIndex][1] = bv;
                    angleValues[angleIndex][2] = ch;
                    angleValues[angleIndex][3] = cv;
                    angleIndex++;
                }
                
                if (angleIndex == CALIBRATION_POINT_COLLECTION_COUNT) {
                    angleIndex = 0;
Calibrator_send_avt_calibrating(_instance);
}
Calibrator_Calibrator_State_event_consumed = 1;
}
}
//End Region Calibrator
//End dsregion Calibrator
//Session list: 
}
void Calibrator_handle_calibrator_calibrate(struct Calibrator_Instance *_instance) {
if(!(_instance->active)) return;
//Region Calibrator
uint8_t Calibrator_Calibrator_State_event_consumed = 0;
if (_instance->Calibrator_Calibrator_State == CALIBRATOR_CALIBRATOR_IDLE_STATE) {
if (Calibrator_Calibrator_State_event_consumed == 0 && 1) {
Calibrator_Calibrator_OnExit(CALIBRATOR_CALIBRATOR_IDLE_STATE, _instance);
_instance->Calibrator_Calibrator_State = CALIBRATOR_CALIBRATOR_CALIBRATE_STATE;
Calibrator_Calibrator_OnEntry(CALIBRATOR_CALIBRATOR_CALIBRATE_STATE, _instance);
Calibrator_Calibrator_State_event_consumed = 1;
}
}
else if (_instance->Calibrator_Calibrator_State == CALIBRATOR_CALIBRATOR_CALIBRATE_STATE) {
if (Calibrator_Calibrator_State_event_consumed == 0 && 1) {
Calibrator_Calibrator_OnExit(CALIBRATOR_CALIBRATOR_CALIBRATE_STATE, _instance);
_instance->Calibrator_Calibrator_State = CALIBRATOR_CALIBRATOR_CALIBRATE_STATE;
restartCalibration();
Calibrator_Calibrator_OnEntry(CALIBRATOR_CALIBRATOR_CALIBRATE_STATE, _instance);
Calibrator_Calibrator_State_event_consumed = 1;
}
}
else if (_instance->Calibrator_Calibrator_State == CALIBRATOR_CALIBRATOR_POINTCOLLECT_STATE) {
if (Calibrator_Calibrator_State_event_consumed == 0 && 1) {
Calibrator_Calibrator_OnExit(CALIBRATOR_CALIBRATOR_POINTCOLLECT_STATE, _instance);
_instance->Calibrator_Calibrator_State = CALIBRATOR_CALIBRATOR_CALIBRATE_STATE;
restartCalibration();
Calibrator_Calibrator_OnEntry(CALIBRATOR_CALIBRATOR_CALIBRATE_STATE, _instance);
Calibrator_Calibrator_State_event_consumed = 1;
}
}
//End Region Calibrator
//End dsregion Calibrator
//Session list: 
}

// Observers for outgoing messages:
void (*external_Calibrator_send_calibrator_endcalibrate_listener)(struct Calibrator_Instance *)= 0x0;
void (*Calibrator_send_calibrator_endcalibrate_listener)(struct Calibrator_Instance *)= 0x0;
void register_external_Calibrator_send_calibrator_endcalibrate_listener(void (*_listener)(struct Calibrator_Instance *)){
external_Calibrator_send_calibrator_endcalibrate_listener = _listener;
}
void register_Calibrator_send_calibrator_endcalibrate_listener(void (*_listener)(struct Calibrator_Instance *)){
Calibrator_send_calibrator_endcalibrate_listener = _listener;
}
void Calibrator_send_calibrator_endcalibrate(struct Calibrator_Instance *_instance){
if (Calibrator_send_calibrator_endcalibrate_listener != 0x0) Calibrator_send_calibrator_endcalibrate_listener(_instance);
if (external_Calibrator_send_calibrator_endcalibrate_listener != 0x0) external_Calibrator_send_calibrator_endcalibrate_listener(_instance);
;
}
void (*external_Calibrator_send_calibrator_errcalibrate_listener)(struct Calibrator_Instance *)= 0x0;
void (*Calibrator_send_calibrator_errcalibrate_listener)(struct Calibrator_Instance *)= 0x0;
void register_external_Calibrator_send_calibrator_errcalibrate_listener(void (*_listener)(struct Calibrator_Instance *)){
external_Calibrator_send_calibrator_errcalibrate_listener = _listener;
}
void register_Calibrator_send_calibrator_errcalibrate_listener(void (*_listener)(struct Calibrator_Instance *)){
Calibrator_send_calibrator_errcalibrate_listener = _listener;
}
void Calibrator_send_calibrator_errcalibrate(struct Calibrator_Instance *_instance){
if (Calibrator_send_calibrator_errcalibrate_listener != 0x0) Calibrator_send_calibrator_errcalibrate_listener(_instance);
if (external_Calibrator_send_calibrator_errcalibrate_listener != 0x0) external_Calibrator_send_calibrator_errcalibrate_listener(_instance);
;
}
void (*external_Calibrator_send_calibrator_calibrationfromserial_listener)(struct Calibrator_Instance *)= 0x0;
void (*Calibrator_send_calibrator_calibrationfromserial_listener)(struct Calibrator_Instance *)= 0x0;
void register_external_Calibrator_send_calibrator_calibrationfromserial_listener(void (*_listener)(struct Calibrator_Instance *)){
external_Calibrator_send_calibrator_calibrationfromserial_listener = _listener;
}
void register_Calibrator_send_calibrator_calibrationfromserial_listener(void (*_listener)(struct Calibrator_Instance *)){
Calibrator_send_calibrator_calibrationfromserial_listener = _listener;
}
void Calibrator_send_calibrator_calibrationfromserial(struct Calibrator_Instance *_instance){
if (Calibrator_send_calibrator_calibrationfromserial_listener != 0x0) Calibrator_send_calibrator_calibrationfromserial_listener(_instance);
if (external_Calibrator_send_calibrator_calibrationfromserial_listener != 0x0) external_Calibrator_send_calibrator_calibrationfromserial_listener(_instance);
;
}
void (*external_Calibrator_send_StatusSender_status_listener)(struct Calibrator_Instance *, uint8_t)= 0x0;
void (*Calibrator_send_StatusSender_status_listener)(struct Calibrator_Instance *, uint8_t)= 0x0;
void register_external_Calibrator_send_StatusSender_status_listener(void (*_listener)(struct Calibrator_Instance *, uint8_t)){
external_Calibrator_send_StatusSender_status_listener = _listener;
}
void register_Calibrator_send_StatusSender_status_listener(void (*_listener)(struct Calibrator_Instance *, uint8_t)){
Calibrator_send_StatusSender_status_listener = _listener;
}
void Calibrator_send_StatusSender_status(struct Calibrator_Instance *_instance, uint8_t id){
if (Calibrator_send_StatusSender_status_listener != 0x0) Calibrator_send_StatusSender_status_listener(_instance, id);
if (external_Calibrator_send_StatusSender_status_listener != 0x0) external_Calibrator_send_StatusSender_status_listener(_instance, id);
;
}
void (*external_Calibrator_send_avt_calibrating_listener)(struct Calibrator_Instance *)= 0x0;
void (*Calibrator_send_avt_calibrating_listener)(struct Calibrator_Instance *)= 0x0;
void register_external_Calibrator_send_avt_calibrating_listener(void (*_listener)(struct Calibrator_Instance *)){
external_Calibrator_send_avt_calibrating_listener = _listener;
}
void register_Calibrator_send_avt_calibrating_listener(void (*_listener)(struct Calibrator_Instance *)){
Calibrator_send_avt_calibrating_listener = _listener;
}
void Calibrator_send_avt_calibrating(struct Calibrator_Instance *_instance){
if (Calibrator_send_avt_calibrating_listener != 0x0) Calibrator_send_avt_calibrating_listener(_instance);
if (external_Calibrator_send_avt_calibrating_listener != 0x0) external_Calibrator_send_avt_calibrating_listener(_instance);
;
}
void (*external_Calibrator_send_avt_calibrationComplete_listener)(struct Calibrator_Instance *)= 0x0;
void (*Calibrator_send_avt_calibrationComplete_listener)(struct Calibrator_Instance *)= 0x0;
void register_external_Calibrator_send_avt_calibrationComplete_listener(void (*_listener)(struct Calibrator_Instance *)){
external_Calibrator_send_avt_calibrationComplete_listener = _listener;
}
void register_Calibrator_send_avt_calibrationComplete_listener(void (*_listener)(struct Calibrator_Instance *)){
Calibrator_send_avt_calibrationComplete_listener = _listener;
}
void Calibrator_send_avt_calibrationComplete(struct Calibrator_Instance *_instance){
if (Calibrator_send_avt_calibrationComplete_listener != 0x0) Calibrator_send_avt_calibrationComplete_listener(_instance);
if (external_Calibrator_send_avt_calibrationComplete_listener != 0x0) external_Calibrator_send_avt_calibrationComplete_listener(_instance);
;
}
void (*external_Calibrator_send_avt_calibrationFailed_listener)(struct Calibrator_Instance *)= 0x0;
void (*Calibrator_send_avt_calibrationFailed_listener)(struct Calibrator_Instance *)= 0x0;
void register_external_Calibrator_send_avt_calibrationFailed_listener(void (*_listener)(struct Calibrator_Instance *)){
external_Calibrator_send_avt_calibrationFailed_listener = _listener;
}
void register_Calibrator_send_avt_calibrationFailed_listener(void (*_listener)(struct Calibrator_Instance *)){
Calibrator_send_avt_calibrationFailed_listener = _listener;
}
void Calibrator_send_avt_calibrationFailed(struct Calibrator_Instance *_instance){
if (Calibrator_send_avt_calibrationFailed_listener != 0x0) Calibrator_send_avt_calibrationFailed_listener(_instance);
if (external_Calibrator_send_avt_calibrationFailed_listener != 0x0) external_Calibrator_send_avt_calibrationFailed_listener(_instance);
;
}



