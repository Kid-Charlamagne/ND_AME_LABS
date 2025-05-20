#include <Servo.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>

/* Set the delay between fresh samples */
uint16_t BNO055_SAMPLERATE_DELAY_MS = 100;

float theta1 = 0;
float theta2 = 0;
float theta3 = 0;
float omega1 = 0;
float omega2 = 0;
float omega3 = 0;

// Check I2C device address and correct line below (by default address is 0x29 or 0x28)
//                                   id, address
Adafruit_BNO055 bno = Adafruit_BNO055(55, 0x28);

void setup() {
  Serial.begin(115200);
  Serial.println("Orientation Sensor Test"); Serial.println("");

  /* Initialise the sensor */
  if (!bno.begin())
  {
    /* There was a problem detecting the BNO055 ... check your connections */
    Serial.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
    while (1);
  }

  delay(1000);
}

void loop() {
   
   //Get Euler angles (pitch, roll, yaw) in degrees
   imu::Vector<3> euler1 = bno.getVector(Adafruit_BNO055::VECTOR_EULER);
   theta1 = euler1.x();
   theta2 = euler1.y();
   theta3 = euler1.z();

   //Get measured angular speed (turn rate) vector in degrees/sec
   imu::Vector<3> euler2 = bno.getVector(Adafruit_BNO055::VECTOR_GYROSCOPE);
   omega1 = euler2.x();
   omega2 = euler2.y();
   omega3 = euler2.z();

  Serial.print(theta1);
  Serial.print(", ");
  Serial.print(theta2);
  Serial.print(", ");
  Serial.print(theta3);
  Serial.print(", ");
  Serial.print(omega1);
  Serial.print(", ");
  Serial.print(omega2);  
  Serial.print(", ");
  Serial.println(omega3);

  delay(200);

}
