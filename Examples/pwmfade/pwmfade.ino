#include <PWM.h>


void setup(){
 setPinFrequency(2,6000);
 setPinResolution(2,8);
 
}
 
void loop(){
  // increase the LED brightness
  for(int duty=0;duty<=255;duty++)
  {
    setPWM(2,duty);
    delay(15);
  }
  for(int duty=255;duty>=0;duty--)
  {
    setPWM(2,duty);
    delay(15);
  }
  
  }
