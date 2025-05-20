#include <Servo.h>

Servo myservo;  // create servo object to control a servo

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  
  for (int i=0; i<180; i++){
    myservo.write(i);                  // sets the servo position according to the scaled value
    delay(25);                           // waits for the servo to get there
  }
  myservo.write(0);
  delay(2000);
  
}
