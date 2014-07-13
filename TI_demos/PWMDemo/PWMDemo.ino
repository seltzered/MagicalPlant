#include <stdlib.h>
#include <stdint.h>

#include "driverlib/timer.h"
  
#include "wiring_private.h" 
//simple pwm test
//extern void PWMWrite(uint8_t pin, uint32_t analog_res, uint32_t duty, unsigned int freq);

void setup()
{
    
    //
    // Configure TimerA as a half-width one-shot timer, and TimerB as a
    // half-width edge capture counter.
    //
//    TimerConfigure(TIMER0_BASE, (TIMER_CFG_SPLIT_PAIR | TIMER_CFG_A_ONE_SHOT |
//    TIMER_CFG_B_CAP_COUNT));


    //
    // Set the count time for the the one-shot timer (TimerA).    
    //
//    TimerLoadSet(TIMER0_BASE, TIMER_A, 3000);
    //
    // Configure the counter (TimerB) to count both edges.
    //
//    TimerControlEvent(TIMER0_BASE, TIMER_B, TIMER_EVENT_BOTH_EDGES);
    //
    // Enable the timers.
    //
//    TimerEnable(TIMER0_BASE, TIMER_BOTH);


    //ACTUAL CODE!!!1
//    TimerConfigure(TIMER0_BASE, TIMER_CFG_SPLIT_PAIR | TIMER_CFG_A_PWM); //setup the timer as a half-width timer for pwm 

//    GPIOPinTypeTimer(GPIO_PORTA_BASE, 0);

//void PWMWrite(uint8_t pin, uint32_t analog_res, uint32_t duty, unsigned int freq) 
PWMWrite(PB_5, 255, 128, 8000000); ///almost 8mhz, not  quite

//analogWrite(PB_5, 128);


}

void loop()
{
  
}
