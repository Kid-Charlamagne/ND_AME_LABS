#include <Servo.h>
#include <Wire.h>

float Speed1 = 1000; //Signal pulse width in microSeconds
float Speed2 = 1000; //Signal pulse width in microSeconds

byte servo1Pin = 9; // signal pin for the ESC.
byte servo2Pin = 8; // signal pin for the ESC.

Servo servo1;
Servo servo2;
int pulse1 = 1200;

void setup() {
  Serial.begin(115200);

  delay(1000);

  servo1.attach(servo1Pin);
  servo2.attach(servo2Pin);
  servo1.writeMicroseconds(900); // send "stop" signal to ESC. Also necessary to arm the ESC.
  servo2.writeMicroseconds(900); // send "stop" signal to ESC. Also necessary to arm the ESC.
  
  delay(2000); // delay to allow the ESC to recognize the stopped signal.
  servo1.writeMicroseconds(1200); // Send signal to ESC.
  servo2.writeMicroseconds(1200); // Send signal to ESC.
}

void loop() {

  Speed1 = 1100;
  Speed2 = 1100;
  
  
  servo1.writeMicroseconds(Speed1); // Send signal to ESC.
  servo2.writeMicroseconds(Speed2); // Send signal to ESC.
  //delay(200);

}
