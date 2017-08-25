#include "PackageReader.h"
/*****************************************************************************
 * Implementation for type : PackageReader
 *****************************************************************************/


// BEGIN: Code from the c_global annotation PackageReader
        
        // startTimes and durations with matching data at same idex
        uint32_t startTimes [STORED_TIME_STEPS]; // default init to zero in C
        uint32_t durations [STORED_TIME_STEPS];
        
        int identifyedSteps = 0;
        int startCount = 0;
    
// END: Code from the c_global annotation PackageReader

// Declaration of prototypes:
//Prototypes: State Machine
void PackageReader_PackageRead_OnExit(int state, struct PackageReader_Instance *_instance);
//Prototypes: Message Sending
void PackageReader_send_PackageSender_packageDetectedEvent(struct PackageReader_Instance *_instance, uint32_t startTimeL1, uint32_t startTimeL2, uint32_t durationL1, uint32_t durationL2, uint32_t signal);
void PackageReader_send_StatusSender_status(struct PackageReader_Instance *_instance, uint8_t id);
//Prototypes: Function
void f_PackageReader_pulse(struct PackageReader_Instance *_instance, uint32_t startTime, uint32_t duration);
// Declaration of functions:
// Definition of function pulse
void f_PackageReader_pulse(struct PackageReader_Instance *_instance, uint32_t startTime, uint32_t duration) {

        if (DEBUG && VERBOSE) {
            Serial.println("");Serial.print("A");Serial.print(",");Serial.print(startTime/36);Serial.print(",");Serial.print(duration/36);Serial.print(",");
        }
        
        int last = STORED_TIME_STEPS-1;
    
        // Guard against rapid spikes down in the signal
        if (startTime - (startTimes[last] + durations[last]) < MIN_PULSE_SEPARATION) {
            // Do nothing, ignore pulse that comes too close to the end of another.
            // durations[last] = startTime + duration - startTimes[last]; // If wiching to merge peaks
    
        } else {
            
            // We have detected a propper peak
            int last = STORED_TIME_STEPS-1;
    
            // maintain fifo arrays
            for (int i = 0 ; i < last ; i++) {
                startTimes[i] = startTimes[i+1];
                durations[i] = durations[i+1];
            }
    
            startTimes[last] = startTime;
            durations[last] = duration;
    
    
            /*
             * Check for package pattern
             * 
             * Strategy:
             * 1. determine L1 and L2 from separation and duration
             * 2. use this to determine L3 between two pulses
             */ 
    
            if (identifyedSteps > 1) {
                identifyedSteps--;
                return;
            }
    
            // Identify L1 and L2
            if (L12_DURATION_MIN < durations[0] && durations[0] < L12_DURATION_MAX) {                       // identify L1 candidate
    
                if (L12_DURATION_MIN < durations[1] && durations[1] < L12_DURATION_MAX) {                   // identify L2 candidate
    
                    uint32_t L12_separation = startTimes[1] - startTimes[0];
                    if (L12_SEPARATION_MIN < L12_separation && L12_separation < L12_SEPARATION_MAX) {       // verify L1-L2 separation          
    
                        uint32_t L13_separation = startTimes[2] - startTimes[0];
                        if (L13_SEPARATION_MIN < L13_separation && L13_separation < L13_SEPARATION_MAX) {   // verify L1-L3 separation
    
                            uint32_t packageL1 = durations[0];
                            uint32_t packageL2 = durations[1];
                            uint32_t startTimeL1 = startTimes[0];
                            uint32_t startTimeL2 = startTimes[1];
                            
                            /* 
                             * Handle possible reflections
                             * Purpouce:
                             *  - ensure reflection signal do not disturb next package
                             *  - ensure we choose the signal going forward to be the direct signal
                             * Assumption: direct signal-ray is most intense/has longest duration pulse
                             */
                             
                            identifyedSteps = 3;
                            
                            int signalIndex = 2;
                            uint32_t signalDuration = durations[signalIndex];
                            
                            for (int i = identifyedSteps ; i < STORED_TIME_STEPS ; i++) {
                                uint32_t L14_separation = startTimes[i] - startTimes[0];
                                
                                if (L14_separation < MIN_PACKAGE_SEPARATION) {
                                    identifyedSteps++;
                                    
PackageReader_send_StatusSender_status(_instance, 3);

                                    
                                    if (signalDuration < durations[i]) {
                                        signalIndex = i;
                                        signalDuration = durations[i];
                                    }
                                }
                            }
                            
                            uint32_t packageSignal = startTimes[signalIndex] - startTimeL1;
                            
PackageReader_send_PackageSender_packageDetectedEvent(_instance, startTimeL1, startTimeL2, packageL1, packageL2, packageSignal);

                            if (DEBUG && VERBOSE) {
                                Serial.println("");Serial.print("B");Serial.print(",");Serial.print((double) startTimeL1/36,6);Serial.print(",");Serial.print((double) packageL1/36,6);Serial.print(",");Serial.print((double) packageL2/36,6);Serial.print(",");Serial.print((double) packageSignal/36,6);Serial.print(",");Serial.print(identifyedSteps);Serial.print(",");Serial.print((startTimes[identifyedSteps]-startTimeL1)/36);Serial.print(",");
                            }
                        }
                    }
                }
            }
        }
}

// Sessions functionss:


// On Entry Actions:
void PackageReader_PackageRead_OnEntry(int state, struct PackageReader_Instance *_instance) {
switch(state) {
case PACKAGEREADER_PACKAGEREAD_STATE:{
_instance->PackageReader_PackageRead_State = PACKAGEREADER_PACKAGEREAD_IDLE_STATE;
PackageReader_PackageRead_OnEntry(_instance->PackageReader_PackageRead_State, _instance);
break;
}
case PACKAGEREADER_PACKAGEREAD_IDLE_STATE:{
break;
}
default: break;
}
}

// On Exit Actions:
void PackageReader_PackageRead_OnExit(int state, struct PackageReader_Instance *_instance) {
switch(state) {
case PACKAGEREADER_PACKAGEREAD_STATE:{
PackageReader_PackageRead_OnExit(_instance->PackageReader_PackageRead_State, _instance);
break;}
case PACKAGEREADER_PACKAGEREAD_IDLE_STATE:{
break;}
default: break;
}
}

// Event Handlers for incoming messages:
void PackageReader_handle_PulseReceiver_pulseDetectedEvent(struct PackageReader_Instance *_instance, uint32_t start, uint32_t duration) {
if(!(_instance->active)) return;
//Region PackageRead
uint8_t PackageReader_PackageRead_State_event_consumed = 0;
if (_instance->PackageReader_PackageRead_State == PACKAGEREADER_PACKAGEREAD_IDLE_STATE) {
if (PackageReader_PackageRead_State_event_consumed == 0 && 1) {
f_PackageReader_pulse(_instance, start, duration);
PackageReader_PackageRead_State_event_consumed = 1;
}
}
//End Region PackageRead
//End dsregion PackageRead
//Session list: 
}

// Observers for outgoing messages:
void (*external_PackageReader_send_PackageSender_packageDetectedEvent_listener)(struct PackageReader_Instance *, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t)= 0x0;
void (*PackageReader_send_PackageSender_packageDetectedEvent_listener)(struct PackageReader_Instance *, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t)= 0x0;
void register_external_PackageReader_send_PackageSender_packageDetectedEvent_listener(void (*_listener)(struct PackageReader_Instance *, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t)){
external_PackageReader_send_PackageSender_packageDetectedEvent_listener = _listener;
}
void register_PackageReader_send_PackageSender_packageDetectedEvent_listener(void (*_listener)(struct PackageReader_Instance *, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t)){
PackageReader_send_PackageSender_packageDetectedEvent_listener = _listener;
}
void PackageReader_send_PackageSender_packageDetectedEvent(struct PackageReader_Instance *_instance, uint32_t startTimeL1, uint32_t startTimeL2, uint32_t durationL1, uint32_t durationL2, uint32_t signal){
if (PackageReader_send_PackageSender_packageDetectedEvent_listener != 0x0) PackageReader_send_PackageSender_packageDetectedEvent_listener(_instance, startTimeL1, startTimeL2, durationL1, durationL2, signal);
if (external_PackageReader_send_PackageSender_packageDetectedEvent_listener != 0x0) external_PackageReader_send_PackageSender_packageDetectedEvent_listener(_instance, startTimeL1, startTimeL2, durationL1, durationL2, signal);
;
}
void (*external_PackageReader_send_StatusSender_status_listener)(struct PackageReader_Instance *, uint8_t)= 0x0;
void (*PackageReader_send_StatusSender_status_listener)(struct PackageReader_Instance *, uint8_t)= 0x0;
void register_external_PackageReader_send_StatusSender_status_listener(void (*_listener)(struct PackageReader_Instance *, uint8_t)){
external_PackageReader_send_StatusSender_status_listener = _listener;
}
void register_PackageReader_send_StatusSender_status_listener(void (*_listener)(struct PackageReader_Instance *, uint8_t)){
PackageReader_send_StatusSender_status_listener = _listener;
}
void PackageReader_send_StatusSender_status(struct PackageReader_Instance *_instance, uint8_t id){
if (PackageReader_send_StatusSender_status_listener != 0x0) PackageReader_send_StatusSender_status_listener(_instance, id);
if (external_PackageReader_send_StatusSender_status_listener != 0x0) external_PackageReader_send_StatusSender_status_listener(_instance, id);
;
}



