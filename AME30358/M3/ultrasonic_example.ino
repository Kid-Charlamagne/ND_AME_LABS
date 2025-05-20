#include <HCSR04.h>

HCSR04 hc(2, 3); //initialisation class HCSR04 (trig pin , echo pin)
float R;

void setup()
{ Serial.begin(9600); }

void loop()
{
  R = hc.dist();

  //Rangefinder outputs 0 if it does not receive a strong return echo.
  //This usually means the nearest object is > 200 cm away.
  if(R<1){
    R=250;
  }
  
    Serial.println(R); //return current distance (cm) in serial
    delay(60);                   // we suggest to use over 60ms measurement cycle, in order to prevent trigger signal to the echo signal.
}
