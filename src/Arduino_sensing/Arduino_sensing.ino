#include <stdlib.h>
#include <stdint.h>

#include "driverlib/timer.h"
   
#include "wiring_private.h" 

//****************************************************************************************
// Illutron take on Disney style capacitive touch sensor using only passives and Arduino
// Dzl 2012
//****************************************************************************************


//                              10n
// PORT B 5 --[10k]-+-----10mH---+--||-- OBJECT
//               |            |
//              3.3k          |
//               |            V 1N4148 diode
//              GND           |
//                            |
//Analog 0 (PE3) ---+------+--------+
//            |      |
//          100pf   1MOmhm
//            |      |
//           GND    GND



#define SET(x,y) (x |=(1<<y))				//-Bit set/clear macros
#define CLR(x,y) (x &= (~(1<<y)))       		// |
#define CHK(x,y) (x & (1<<y))           		// |
#define TOG(x,y) (x^=(1<<y))            		//-+



#define N 160  //How many frequencies

float results[N];            //-Filtered result buffer
float freq[N];            //-Filtered result buffer
int sizeOfArray = N;

 int maxFrequency = 7000000; //7 mhz
    
   
   

void setup()
{

  // pinMode(9,OUTPUT);        //-Signal generator pin
  // pinMode(8,OUTPUT);        //-Sync (test) pin

  Serial.begin(115200);

  for(int i=0;i<N;i++)      //-Preset results
    results[i]=0;         //-+
}

void loop()
{
  unsigned int d;

  int counter = 0;
  for(unsigned int d=1;d<N;d++)
  {
    int v=analogRead(A0);    //-Read response signal
  
    PWMWrite(PB_5, 255, 128, maxFrequency / d);

    results[d]=results[d]*0.5+(float)(v)*0.5; //Filter results
   
    freq[d] = maxFrequency / d;//d;

    digitalWrite(PB_1, digitalRead(PB_1)^1 ); //toggle 


 //   plot(v,0);              //-Display
 //   plot(results[d],1);
  // delayMicroseconds(1);
  }


//  PlottArray(1,freq,results); 
 
  digitalWrite(PB_0, digitalRead(PB_0)^1 ); //toggle 
//  TOG(PORTB,0);            //-Toggle pin 8 after each sweep (good for scope)
}
   

   
    
 
