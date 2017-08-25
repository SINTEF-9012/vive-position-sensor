#include "IntervalTimer.h"

#define CLOCKS_NUMBER 8
#define CLOCKS_PERIOD 1000
void initialize_timer();
void start_timer(uint8_t id, uint16_t period, void (*f)(void));
void timer_cancel(uint8_t id);



/**
 * Timer Clock Used :
 * 0 : BUTTON
 * 1 : SoftButton
 * 2 : Serial In
 * 3 :
 * 4 : Backbone_IRPS
 * 5 : Blinker continuous blink
 * 6 : Blinker return to state color
 * 7 : Blinker timeout printing
 * 
 */
