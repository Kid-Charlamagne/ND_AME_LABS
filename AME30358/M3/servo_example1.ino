#include <Servo.h>

Servo myservo;  // create servo object to control a servo

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {

  myservo.write(***);  //turn the servo to a certain angle
  delay(1000);
  
}
