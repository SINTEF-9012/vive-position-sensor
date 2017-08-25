#include "Timer.h"

typedef struct clock{
  int      tick;   // current count-down - clock is sleeping if 0
  void (*f)(void);    // event triggered when count-down reaches 0
} Clock_t;

bool init = false;

Clock_t clocks[CLOCKS_NUMBER];
IntervalTimer clocker = IntervalTimer();

void clock_tick(Clock_t *clk);
void update_timers();

void initialize_timer(){
  if(init) return;
  init = true;
  for (uint8_t i = 0; i < CLOCKS_NUMBER; i++) {
    clocks[i].tick = 0;
  }
  clocker.begin(&update_timers, CLOCKS_PERIOD);
}

// Period in milliseconds
void start_timer(uint8_t id, uint16_t period, void (*f)(void)){
  if(id < CLOCKS_NUMBER){
    clocks[id].tick = period;
    clocks[id].f = f;
  }
}

void clock_tick(Clock_t *clk){
  if(clk->tick == 0) return;

  clk->tick--;
  if(clk->tick == 0) {
    clk->f();
  }
}

void update_timers(){
  for(uint8_t i=0; i<CLOCKS_NUMBER ; i++)clock_tick(&clocks[i]);
  clocker.begin(&update_timers, CLOCKS_PERIOD);
}
void timer_cancel(uint8_t id){
  if(id < CLOCKS_NUMBER) clocks[id].tick = 0;
}
