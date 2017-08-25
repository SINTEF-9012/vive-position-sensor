#include "AngleReader.h"
/*****************************************************************************
 * Implementation for type : AngleReader
 *****************************************************************************/


// BEGIN: Code from the c_global annotation AngleReader

    
        // Last package arrays
        uint32_t L1s [STORED_STEPS];
        uint32_t L2s [STORED_STEPS];
        int signalIndex = 0;
        
        double signalAngles[4];         // Last read angles sufficiently close to its own previous value
        double lastSignalAngles[4];     // Last read angles
        
        uint32_t lastStartTime = 0;
        
        uint32_t calibrationStartTime;
        int calibrationStep = 0;
        int initiationCount = 0;
        int recalibrateCount = 0;
        
        int printWhenZero = 0;         // Only print when we have gotten four consecutive angles
        
        enum Signal {
            off = 0, horisontal = 1, vertical = 2
        };
        
        uint32_t average(uint32_t L[], int count) {
            uint32_t sum = 0;
        
            for (int i = 0; i < count; i++) {
                sum += L[i];
            }
            return sum/count;
        }
        
        uint32_t maxVal(uint32_t L[], int count) {
            uint32_t ret = L[0];
            for (int i = 1; i<count; i++) {
                if (L[i] > ret) {
                    ret = L[i];
                }
            }
            return ret;
        }
        
        uint32_t minVal(uint32_t L[], int count) {
            uint32_t ret = L[0];
            for (int i = 1; i<count; i++) {
                if (L[i] < ret) {
                    ret = L[i];
                }
            }
            return ret;
        }
        
        Signal classifyPulse(uint32_t signal, uint32_t L[], int count) {
        
            int min = minVal(L, count);
            int max = maxVal(L, count);
        
            int category = (7*(signal - min + PULSE_WIDTH_SEPARATION/2))/(max - min);
            
            switch (category) {
                case 0:
                    return Signal::horisontal;
                    break;
                case 1:
                    return Signal::vertical;
                    break;
                case 2:
                    return Signal::horisontal;
                    break;
                case 3:
                    return Signal::vertical;
                    break;
                default:
                    return Signal::off;
                    break;
            }
        
            return Signal::off;   
        }
        
        SignalType identifySignal(Signal L1, Signal L2) {
            return (L1 == Signal::off) ? (L2 == Signal::horisontal) ? SignalType::ch:(L2 == Signal::vertical) ? SignalType::cv : SignalType::error : (L2 == Signal::off) ? (L1 == Signal::horisontal) ? SignalType::bh : (L1 == Signal::vertical) ? SignalType::bv : SignalType::error : SignalType::error;
        }
    
// END: Code from the c_global annotation AngleReader

// Declaration of prototypes:
//Prototypes: State Machine
void AngleReader_SingalDetectionStrategy_OnExit(int state, struct AngleReader_Instance *_instance);
//Prototypes: Message Sending
void AngleReader_send_AngleSender_allAngles(struct AngleReader_Instance *_instance, double bh, double bv, double ch, double cv);
void AngleReader_send_StatusSender_status(struct AngleReader_Instance *_instance, uint8_t id);
void AngleReader_send_Transitions_startTimeCalibrated(struct AngleReader_Instance *_instance);
void AngleReader_send_Transitions_recalibrate(struct AngleReader_Instance *_instance);
//Prototypes: Function
void f_AngleReader_updateAngles(struct AngleReader_Instance *_instance, uint32_t inputSignal, uint8_t signalType, uint32_t L2delay, uint8_t calibrated);
void f_AngleReader_printAngleInformation(struct AngleReader_Instance *_instance, uint32_t L1, uint32_t L2);
void f_AngleReader_updateLastPackageArrays(struct AngleReader_Instance *_instance, uint32_t L1, uint32_t L2);
// Declaration of functions:
// Definition of function updateAngles
void f_AngleReader_updateAngles(struct AngleReader_Instance *_instance, uint32_t inputSignal, uint8_t signalType, uint32_t L2delay, uint8_t calibrated) {

        SignalType type = SignalType(signalType);
        uint32_t signal = (type == SignalType::bh || type == SignalType::bv) ? inputSignal : inputSignal - L2delay;
        
        double signalAngleMag = PI * ((double) signal)/PERIOD - PI/2;
        double signalAngle = (type == SignalType::bh || type == SignalType::ch) ? -signalAngleMag : signalAngleMag;
        
        // Account for observed deviation in angle measurnment 
        //signalAngle = signalAngle*(1.0-0.00455);
        
        if (type == SignalType::error) {
            
AngleReader_send_StatusSender_status(_instance, 15);

            
        } else {
           
            if (abs(signalAngle - lastSignalAngles[type]) < MAX_VALID_ANGLE_DIFFERENCE) {
                 signalAngles[type] = signalAngle;  // Only print angle for consecutive simular angles
            } 
           
            lastSignalAngles[type] = signalAngle;   // Record last measured angle regardless
        }
        
        if (DEBUG && VERBOSE) {
            if (calibrated) {
                Serial.print("\nD,");
                Serial.print(type);
                Serial.print(",");
                Serial.print(signalAngle,6);
                Serial.print(",");
            }
            
            if (type == SignalType::bh) {
                Serial.print("\nE,");
                Serial.print(signalAngles[0],6);
                Serial.print(",");
                Serial.print(signalAngles[1],6);
                Serial.print(",");
                Serial.print(signalAngles[2],6);
                Serial.print(",");
                Serial.print(signalAngles[3],6);
                Serial.print(",");
            }
        }
        
}
// Definition of function printAngleInformation
void f_AngleReader_printAngleInformation(struct AngleReader_Instance *_instance, uint32_t L1, uint32_t L2) {

        Signal L1Type = classifyPulse(L1, L1s, STORED_STEPS);
        Signal L2Type = classifyPulse(L2, L2s, STORED_STEPS);
        SignalType signalType = identifySignal(L1Type, L2Type);

        Serial.print("\nC,");
        Serial.print((int) L1Type);
        Serial.print(",");
        Serial.print((int) L2Type);
        Serial.print(",");
        Serial.print((int) signalType);
        Serial.print(",");
        Serial.print(calibrationStep);
        Serial.print(",");
        
}
// Definition of function updateLastPackageArrays
void f_AngleReader_updateLastPackageArrays(struct AngleReader_Instance *_instance, uint32_t L1, uint32_t L2) {

        L1s[signalIndex] = L1;
        L2s[signalIndex] = L2;
        
        // update index for next itteration
        if (signalIndex < STORED_STEPS) {
            signalIndex++;
        } else {
            signalIndex = 0;
        }
        
}

// Sessions functionss:


// On Entry Actions:
void AngleReader_SingalDetectionStrategy_OnEntry(int state, struct AngleReader_Instance *_instance) {
switch(state) {
case ANGLEREADER_SINGALDETECTIONSTRATEGY_STATE:{
_instance->AngleReader_SingalDetectionStrategy_State = ANGLEREADER_SINGALDETECTIONSTRATEGY_PULSEWIDTHS_STATE;
AngleReader_SingalDetectionStrategy_OnEntry(_instance->AngleReader_SingalDetectionStrategy_State, _instance);
break;
}
case ANGLEREADER_SINGALDETECTIONSTRATEGY_PULSEWIDTHS_STATE:{
AngleReader_send_StatusSender_status(_instance, 12);
break;
}
case ANGLEREADER_SINGALDETECTIONSTRATEGY_ARRIVALTIME_STATE:{
AngleReader_send_StatusSender_status(_instance, 13);
break;
}
default: break;
}
}

// On Exit Actions:
void AngleReader_SingalDetectionStrategy_OnExit(int state, struct AngleReader_Instance *_instance) {
switch(state) {
case ANGLEREADER_SINGALDETECTIONSTRATEGY_STATE:{
AngleReader_SingalDetectionStrategy_OnExit(_instance->AngleReader_SingalDetectionStrategy_State, _instance);
break;}
case ANGLEREADER_SINGALDETECTIONSTRATEGY_PULSEWIDTHS_STATE:{
break;}
case ANGLEREADER_SINGALDETECTIONSTRATEGY_ARRIVALTIME_STATE:{
break;}
default: break;
}
}

// Event Handlers for incoming messages:
void AngleReader_handle_OverflowNotifier_timerOverflow(struct AngleReader_Instance *_instance) {
if(!(_instance->active)) return;
//Region SingalDetectionStrategy
uint8_t AngleReader_SingalDetectionStrategy_State_event_consumed = 0;
//End Region SingalDetectionStrategy
//End dsregion SingalDetectionStrategy
//Session list: 
if (1) {
calibrationStartTime = (calibrationStartTime + (PERIODS_PER_CLOCK+1) * PERIOD * 4) % (PERIOD * 4);
            
            if (DEBUG && !VERBOSE) {
                Serial.print("\nTimer overflow occured. ");
            }
            
            
AngleReader_SingalDetectionStrategy_State_event_consumed = 1;
}
}
void AngleReader_handle_PackageReceiver_packageDetectedEvent(struct AngleReader_Instance *_instance, uint32_t startTimeL1, uint32_t startTimeL2, uint32_t durationL1, uint32_t durationL2, uint32_t signal) {
if(!(_instance->active)) return;
//Region SingalDetectionStrategy
uint8_t AngleReader_SingalDetectionStrategy_State_event_consumed = 0;
if (_instance->AngleReader_SingalDetectionStrategy_State == ANGLEREADER_SINGALDETECTIONSTRATEGY_PULSEWIDTHS_STATE) {
if (AngleReader_SingalDetectionStrategy_State_event_consumed == 0 && 1) {
f_AngleReader_updateLastPackageArrays(_instance, durationL1, durationL2);

                if (initiationCount >= STORED_STEPS) {
                    Signal L1Type = classifyPulse(durationL1, L1s, STORED_STEPS);
                    Signal L2Type = classifyPulse(durationL2, L2s, STORED_STEPS);
    
                    SignalType signalType = identifySignal(L1Type, L2Type);
                    
                    if (calibrationStep % 4 == signalType) {
                        calibrationStep++;
                    } else {
                        calibrationStep = 0;
                    }
                    
                    if (calibrationStep == CALIBRATION_SAMPLES * 4 + 1) {
AngleReader_send_Transitions_startTimeCalibrated(_instance);
calibrationStartTime = startTimeL1 % (PERIOD * 4);
                    }
                    
f_AngleReader_updateAngles(_instance, signal, signalType, startTimeL2 - startTimeL1, 0);
AngleReader_send_AngleSender_allAngles(_instance, signalAngles[0], signalAngles[1], signalAngles[2], signalAngles[3]);
if (DEBUG && VERBOSE) {
f_AngleReader_printAngleInformation(_instance, durationL1, durationL2);
}
                } else {
                    initiationCount++;
                }
AngleReader_SingalDetectionStrategy_State_event_consumed = 1;
}
}
else if (_instance->AngleReader_SingalDetectionStrategy_State == ANGLEREADER_SINGALDETECTIONSTRATEGY_ARRIVALTIME_STATE) {
if (AngleReader_SingalDetectionStrategy_State_event_consumed == 0 && 1) {

                // Handle first few pulses in signal that arrive "before" startTime (after foverflow)
                uint32_t startTime = startTimeL1 < calibrationStartTime ? startTimeL1 += 4*PERIOD : startTimeL1;
                
                // Send event if one or more angles have not been read
                uint32_t diff = startTime - lastStartTime;
                if (!(MIN_PACKAGE_SEPARATION < diff && diff < MAX_PACKAGE_SEPARATION)) {
                    printWhenZero = 4; // Wait until this angle-measurnment arrives next (in four itterations). 
AngleReader_send_StatusSender_status(_instance, 1);
}
                lastStartTime = startTime;
                
                // Classify package
                int val = ((startTime-calibrationStartTime + PERIOD/2) / PERIOD) % 4;
                SignalType signalType = SignalType(val);
        
                // Handle timing drift (from teensy or Base Stations)
                double n = (double) (startTime-calibrationStartTime)/(PERIOD);
                double difference = n - (long)n;
        
                if (difference < TIME_DRIFT_CORRECTOIN_THRESHOLD) {
                    calibrationStartTime += TIME_DRIFT_CORRECTOIN_CONSTANT;
                } else if (1-TIME_DRIFT_CORRECTOIN_THRESHOLD < difference) {
                    calibrationStartTime -= TIME_DRIFT_CORRECTOIN_CONSTANT;
                } else {
                    if (recalibrateCount++ > RECALIBRATE_SAMPLES) {
AngleReader_send_Transitions_recalibrate(_instance);
AngleReader_send_StatusSender_status(_instance, 11);
} else {
AngleReader_send_StatusSender_status(_instance, 10);
}
                    return;
                }
                if (recalibrateCount != 0) recalibrateCount = 0;
                
f_AngleReader_updateAngles(_instance, signal, signalType, startTimeL2 - startTimeL1, 1);
if (printWhenZero == 0) {
AngleReader_send_AngleSender_allAngles(_instance, signalAngles[0], signalAngles[1], signalAngles[2], signalAngles[3]);
} else {
                    printWhenZero--;
                } 
                
                if (DEBUG && VERBOSE) {
f_AngleReader_printAngleInformation(_instance, durationL1, durationL2);
}
AngleReader_SingalDetectionStrategy_State_event_consumed = 1;
}
}
//End Region SingalDetectionStrategy
//End dsregion SingalDetectionStrategy
//Session list: 
}
void AngleReader_handle_Transitions_startTimeCalibrated(struct AngleReader_Instance *_instance) {
if(!(_instance->active)) return;
//Region SingalDetectionStrategy
uint8_t AngleReader_SingalDetectionStrategy_State_event_consumed = 0;
if (_instance->AngleReader_SingalDetectionStrategy_State == ANGLEREADER_SINGALDETECTIONSTRATEGY_PULSEWIDTHS_STATE) {
if (AngleReader_SingalDetectionStrategy_State_event_consumed == 0 && 1) {
AngleReader_SingalDetectionStrategy_OnExit(ANGLEREADER_SINGALDETECTIONSTRATEGY_PULSEWIDTHS_STATE, _instance);
_instance->AngleReader_SingalDetectionStrategy_State = ANGLEREADER_SINGALDETECTIONSTRATEGY_ARRIVALTIME_STATE;
AngleReader_SingalDetectionStrategy_OnEntry(ANGLEREADER_SINGALDETECTIONSTRATEGY_ARRIVALTIME_STATE, _instance);
AngleReader_SingalDetectionStrategy_State_event_consumed = 1;
}
}
//End Region SingalDetectionStrategy
//End dsregion SingalDetectionStrategy
//Session list: 
}
void AngleReader_handle_Transitions_recalibrate(struct AngleReader_Instance *_instance) {
if(!(_instance->active)) return;
//Region SingalDetectionStrategy
uint8_t AngleReader_SingalDetectionStrategy_State_event_consumed = 0;
if (_instance->AngleReader_SingalDetectionStrategy_State == ANGLEREADER_SINGALDETECTIONSTRATEGY_ARRIVALTIME_STATE) {
if (AngleReader_SingalDetectionStrategy_State_event_consumed == 0 && 1) {
AngleReader_SingalDetectionStrategy_OnExit(ANGLEREADER_SINGALDETECTIONSTRATEGY_ARRIVALTIME_STATE, _instance);
_instance->AngleReader_SingalDetectionStrategy_State = ANGLEREADER_SINGALDETECTIONSTRATEGY_PULSEWIDTHS_STATE;
AngleReader_SingalDetectionStrategy_OnEntry(ANGLEREADER_SINGALDETECTIONSTRATEGY_PULSEWIDTHS_STATE, _instance);
AngleReader_SingalDetectionStrategy_State_event_consumed = 1;
}
}
//End Region SingalDetectionStrategy
//End dsregion SingalDetectionStrategy
//Session list: 
}

// Observers for outgoing messages:
void (*external_AngleReader_send_AngleSender_allAngles_listener)(struct AngleReader_Instance *, double, double, double, double)= 0x0;
void (*AngleReader_send_AngleSender_allAngles_listener)(struct AngleReader_Instance *, double, double, double, double)= 0x0;
void register_external_AngleReader_send_AngleSender_allAngles_listener(void (*_listener)(struct AngleReader_Instance *, double, double, double, double)){
external_AngleReader_send_AngleSender_allAngles_listener = _listener;
}
void register_AngleReader_send_AngleSender_allAngles_listener(void (*_listener)(struct AngleReader_Instance *, double, double, double, double)){
AngleReader_send_AngleSender_allAngles_listener = _listener;
}
void AngleReader_send_AngleSender_allAngles(struct AngleReader_Instance *_instance, double bh, double bv, double ch, double cv){
if (AngleReader_send_AngleSender_allAngles_listener != 0x0) AngleReader_send_AngleSender_allAngles_listener(_instance, bh, bv, ch, cv);
if (external_AngleReader_send_AngleSender_allAngles_listener != 0x0) external_AngleReader_send_AngleSender_allAngles_listener(_instance, bh, bv, ch, cv);
;
}
void (*external_AngleReader_send_StatusSender_status_listener)(struct AngleReader_Instance *, uint8_t)= 0x0;
void (*AngleReader_send_StatusSender_status_listener)(struct AngleReader_Instance *, uint8_t)= 0x0;
void register_external_AngleReader_send_StatusSender_status_listener(void (*_listener)(struct AngleReader_Instance *, uint8_t)){
external_AngleReader_send_StatusSender_status_listener = _listener;
}
void register_AngleReader_send_StatusSender_status_listener(void (*_listener)(struct AngleReader_Instance *, uint8_t)){
AngleReader_send_StatusSender_status_listener = _listener;
}
void AngleReader_send_StatusSender_status(struct AngleReader_Instance *_instance, uint8_t id){
if (AngleReader_send_StatusSender_status_listener != 0x0) AngleReader_send_StatusSender_status_listener(_instance, id);
if (external_AngleReader_send_StatusSender_status_listener != 0x0) external_AngleReader_send_StatusSender_status_listener(_instance, id);
;
}
void (*external_AngleReader_send_Transitions_startTimeCalibrated_listener)(struct AngleReader_Instance *)= 0x0;
void (*AngleReader_send_Transitions_startTimeCalibrated_listener)(struct AngleReader_Instance *)= 0x0;
void register_external_AngleReader_send_Transitions_startTimeCalibrated_listener(void (*_listener)(struct AngleReader_Instance *)){
external_AngleReader_send_Transitions_startTimeCalibrated_listener = _listener;
}
void register_AngleReader_send_Transitions_startTimeCalibrated_listener(void (*_listener)(struct AngleReader_Instance *)){
AngleReader_send_Transitions_startTimeCalibrated_listener = _listener;
}
void AngleReader_send_Transitions_startTimeCalibrated(struct AngleReader_Instance *_instance){
if (AngleReader_send_Transitions_startTimeCalibrated_listener != 0x0) AngleReader_send_Transitions_startTimeCalibrated_listener(_instance);
if (external_AngleReader_send_Transitions_startTimeCalibrated_listener != 0x0) external_AngleReader_send_Transitions_startTimeCalibrated_listener(_instance);
;
}
void (*external_AngleReader_send_Transitions_recalibrate_listener)(struct AngleReader_Instance *)= 0x0;
void (*AngleReader_send_Transitions_recalibrate_listener)(struct AngleReader_Instance *)= 0x0;
void register_external_AngleReader_send_Transitions_recalibrate_listener(void (*_listener)(struct AngleReader_Instance *)){
external_AngleReader_send_Transitions_recalibrate_listener = _listener;
}
void register_AngleReader_send_Transitions_recalibrate_listener(void (*_listener)(struct AngleReader_Instance *)){
AngleReader_send_Transitions_recalibrate_listener = _listener;
}
void AngleReader_send_Transitions_recalibrate(struct AngleReader_Instance *_instance){
if (AngleReader_send_Transitions_recalibrate_listener != 0x0) AngleReader_send_Transitions_recalibrate_listener(_instance);
if (external_AngleReader_send_Transitions_recalibrate_listener != 0x0) external_AngleReader_send_Transitions_recalibrate_listener(_instance);
;
}



