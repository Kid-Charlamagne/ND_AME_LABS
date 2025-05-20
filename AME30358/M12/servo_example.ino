// Notre Dame - AME20216 - Lab 1
// A11 - Fly-by-Wire
// Part II - Servo

#include <Servo.h>

Servo myservo;  // create servo object to control a servo

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {

  myservo.writeMicroseconds(***);  //enter a value between 1000 and 2000
  delay(1000);
  
}
