// Notre Dame - AME20216 - Lab 1
// A11 - Fly-by-Wire
// Part I - Analog Joystick

int joystickPin = ***;  // replace *** with the pin number
int joystickPos = 0;

void setup() {
  // initialize serial communication:
  Serial.begin(9600);
}

void loop() {
  joystickPos = analogRead(joystickPin); //read the analog joystick voltage
  Serial.println(joystickPos);
  
  delay(200);

}
