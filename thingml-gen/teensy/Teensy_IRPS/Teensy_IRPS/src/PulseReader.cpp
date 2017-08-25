#include "PulseReader.h"
/*****************************************************************************
 * Implementation for type : PulseReader
 *****************************************************************************/


// BEGIN: Code from the c_global annotation PulseReader

        volatile uint32_t ftm0_cnt_long;
        extern struct PulseReader_Instance pulseReader_var;
        bool STOP = false;
    
// END: Code from the c_global annotation PulseReader

// Declaration of prototypes:
//Prototypes: State Machine
void PulseReader_PulseRead_OnExit(int state, struct PulseReader_Instance *_instance);
//Prototypes: Message Sending
void PulseReader_send_PulseSender_pulseDetectedEvent(struct PulseReader_Instance *_instance, uint32_t start, uint32_t duration);
void PulseReader_send_OverflowNotifier_timerOverflow(struct PulseReader_Instance *_instance);
void PulseReader_send_Transitions_pulseDetected(struct PulseReader_Instance *_instance, uint32_t start, uint32_t duration);
//Prototypes: Function
void initialize_();
void ftm0_isr(void);
// Declaration of functions:
// Definition of function initialize
void initialize_() {

    	/* --- Setup the analog comparator (CMP1) --- */
    	SIM_SCGC4 |= SIM_SCGC4_CMP;
    	CMP1_CR1 = 0x00;
    	CMP1_CR0 = 0x00;

    	PORTC_PCR3 = 0x0000; // PC3 alternative 0
    	PORTC_PCR4 = 0x0600; // PC4 alternative 6

    	CMP1_MUXCR = 0x0F; // Positive input 1 - Negative input DAC
    	CMP1_DACCR = 0xD2; // Enable DAC - Vref = Vin1 - DAC voltage 18/64 * Vin = 1.48V
    	// The filter will add a delay to the captured pulses, but should not matter as it is the relative time which makes the difference
    	CMP1_FPR = 0x01; // Set filter period (of bus clock)
    	CMP1_CR0 = 0x73; // Filter 7 samples - 30mV hysteresis
    	CMP1_CR1 = 0x13; // Filtered output - Output enable - Comparator enable

    	/* --- Setup the flex-timer to count pulse lengths --- */
    	SIM_SCGC6 |= SIM_SCGC6_FTM0;
    	FTM0_SC = 0x00;

    	PORTD_PCR4 = 0x0400; // PD4 alternative 4

    	FTM0_CNTIN = 0x00; // Set counter to 0
    	FTM0_MOD = 0xFFFF; // Set to free running mode
    	FTM0_MODE=0x05; // Set FTMEN bit

    	FTM0_C4SC = 0x14; // Capture rising edge - and continuous capture - on channel 4
    	FTM0_C5SC = 0x48; // Capture falling edge - and enable interrupt - on channel 5
    	FTM0_COMBINE = 0x00040000; // Enable dual capture mode on channel 4+5

    	FTM0_STATUS = 0x00; // Clear any old interrupts
    	NVIC_ENABLE_IRQ(IRQ_FTM0); // Enable interrupts for FTM0

    	ftm0_cnt_long = 0; // We can count to 32-bits if we do it manually
    	FTM0_SC |= 0x40; // Interrupt on overflow

    	FTM0_SC |= 0x08; // Set FTM0 clock to system clock
    	FTM0_COMBINE |= 0x00080000; // Set DECAP2 to start capture
}
// Definition of function interruptServiceRoutine
void ftm0_isr(void) {
// Counter overflow
    	if (FTM0_SC & 0x80) {
    		ftm0_cnt_long += 0x10000; // Increment long counter
    		FTM0_SC &= ~0x80; // Reset flag

            if (ftm0_cnt_long == 0x00000000) {
                // Adjust calibrationStartTime to account for timer overflow.
                PulseReader_send_OverflowNotifier_timerOverflow(&pulseReader_var);
            }
    	}

        // Falling edge interrupt
    	if (FTM0_STATUS & 0x20) {
    		// Read values and prepare FTM0 for new capture
    		uint32_t rise = FTM0_C4V;
    		uint32_t fall = FTM0_C5V;
    		FTM0_STATUS = 0;

    		// Calculate when the events occurred
    		uint32_t pulse_time, pulse_width;
    		if (rise < fall) {
    			// All in one FTM0 counter cycle
    			pulse_time  = ftm0_cnt_long + rise;
    			pulse_width = fall - rise;
    		} else {
    			// The FTM0 counter overflowed in the middle of the captured pulse
    			pulse_time  = ftm0_cnt_long + rise - 0x10000;
    			pulse_width = 0xFFFF - rise + fall;
    		}

    		if (!STOP) PulseReader_send_Transitions_pulseDetected(&pulseReader_var, pulse_time, pulse_width);
        }
}

// Sessions functionss:


// On Entry Actions:
void PulseReader_PulseRead_OnEntry(int state, struct PulseReader_Instance *_instance) {
switch(state) {
case PULSEREADER_PULSEREAD_STATE:{
_instance->PulseReader_PulseRead_State = PULSEREADER_PULSEREAD_IDLE_STATE;
initialize_();
PulseReader_PulseRead_OnEntry(_instance->PulseReader_PulseRead_State, _instance);
break;
}
case PULSEREADER_PULSEREAD_IDLE_STATE:{
break;
}
default: break;
}
}

// On Exit Actions:
void PulseReader_PulseRead_OnExit(int state, struct PulseReader_Instance *_instance) {
switch(state) {
case PULSEREADER_PULSEREAD_STATE:{
PulseReader_PulseRead_OnExit(_instance->PulseReader_PulseRead_State, _instance);
break;}
case PULSEREADER_PULSEREAD_IDLE_STATE:{
break;}
default: break;
}
}

// Event Handlers for incoming messages:
void PulseReader_handle_Transitions_pulseDetected(struct PulseReader_Instance *_instance, uint32_t start, uint32_t duration) {
if(!(_instance->active)) return;
//Region PulseRead
uint8_t PulseReader_PulseRead_State_event_consumed = 0;
if (_instance->PulseReader_PulseRead_State == PULSEREADER_PULSEREAD_IDLE_STATE) {
if (PulseReader_PulseRead_State_event_consumed == 0 && 1) {
PulseReader_send_PulseSender_pulseDetectedEvent(_instance, start, duration);
PulseReader_PulseRead_State_event_consumed = 1;
}
}
//End Region PulseRead
//End dsregion PulseRead
//Session list: 
}

// Observers for outgoing messages:
void (*external_PulseReader_send_PulseSender_pulseDetectedEvent_listener)(struct PulseReader_Instance *, uint32_t, uint32_t)= 0x0;
void (*PulseReader_send_PulseSender_pulseDetectedEvent_listener)(struct PulseReader_Instance *, uint32_t, uint32_t)= 0x0;
void register_external_PulseReader_send_PulseSender_pulseDetectedEvent_listener(void (*_listener)(struct PulseReader_Instance *, uint32_t, uint32_t)){
external_PulseReader_send_PulseSender_pulseDetectedEvent_listener = _listener;
}
void register_PulseReader_send_PulseSender_pulseDetectedEvent_listener(void (*_listener)(struct PulseReader_Instance *, uint32_t, uint32_t)){
PulseReader_send_PulseSender_pulseDetectedEvent_listener = _listener;
}
void PulseReader_send_PulseSender_pulseDetectedEvent(struct PulseReader_Instance *_instance, uint32_t start, uint32_t duration){
if (PulseReader_send_PulseSender_pulseDetectedEvent_listener != 0x0) PulseReader_send_PulseSender_pulseDetectedEvent_listener(_instance, start, duration);
if (external_PulseReader_send_PulseSender_pulseDetectedEvent_listener != 0x0) external_PulseReader_send_PulseSender_pulseDetectedEvent_listener(_instance, start, duration);
;
}
void (*external_PulseReader_send_OverflowNotifier_timerOverflow_listener)(struct PulseReader_Instance *)= 0x0;
void (*PulseReader_send_OverflowNotifier_timerOverflow_listener)(struct PulseReader_Instance *)= 0x0;
void register_external_PulseReader_send_OverflowNotifier_timerOverflow_listener(void (*_listener)(struct PulseReader_Instance *)){
external_PulseReader_send_OverflowNotifier_timerOverflow_listener = _listener;
}
void register_PulseReader_send_OverflowNotifier_timerOverflow_listener(void (*_listener)(struct PulseReader_Instance *)){
PulseReader_send_OverflowNotifier_timerOverflow_listener = _listener;
}
void PulseReader_send_OverflowNotifier_timerOverflow(struct PulseReader_Instance *_instance){
if (PulseReader_send_OverflowNotifier_timerOverflow_listener != 0x0) PulseReader_send_OverflowNotifier_timerOverflow_listener(_instance);
if (external_PulseReader_send_OverflowNotifier_timerOverflow_listener != 0x0) external_PulseReader_send_OverflowNotifier_timerOverflow_listener(_instance);
;
}
void (*external_PulseReader_send_Transitions_pulseDetected_listener)(struct PulseReader_Instance *, uint32_t, uint32_t)= 0x0;
void (*PulseReader_send_Transitions_pulseDetected_listener)(struct PulseReader_Instance *, uint32_t, uint32_t)= 0x0;
void register_external_PulseReader_send_Transitions_pulseDetected_listener(void (*_listener)(struct PulseReader_Instance *, uint32_t, uint32_t)){
external_PulseReader_send_Transitions_pulseDetected_listener = _listener;
}
void register_PulseReader_send_Transitions_pulseDetected_listener(void (*_listener)(struct PulseReader_Instance *, uint32_t, uint32_t)){
PulseReader_send_Transitions_pulseDetected_listener = _listener;
}
void PulseReader_send_Transitions_pulseDetected(struct PulseReader_Instance *_instance, uint32_t start, uint32_t duration){
if (PulseReader_send_Transitions_pulseDetected_listener != 0x0) PulseReader_send_Transitions_pulseDetected_listener(_instance, start, duration);
if (external_PulseReader_send_Transitions_pulseDetected_listener != 0x0) external_PulseReader_send_Transitions_pulseDetected_listener(_instance, start, duration);
;
}



