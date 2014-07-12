#include <stdlib.h>
#include <stdint.h>

#include "driverlib/timer.h"
   
//simple pwm test


void setup()
{
    
    //
    // Configure TimerA as a half-width one-shot timer, and TimerB as a
    // half-width edge capture counter.
    //
    TimerConfigure(TIMER0_BASE, (TIMER_CFG_SPLIT_PAIR | TIMER_CFG_A_ONE_SHOT |
    TIMER_CFG_B_CAP_COUNT));
    //
    // Set the count time for the the one-shot timer (TimerA).
    //
    TimerLoadSet(TIMER0_BASE, TIMER_A, 3000);
    //
    // Configure the counter (TimerB) to count both edges.
    //
    TimerControlEvent(TIMER0_BASE, TIMER_B, TIMER_EVENT_BOTH_EDGES);
    //
    // Enable the timers.
    //
    TimerEnable(TIMER0_BASE, TIMER_BOTH);


}
