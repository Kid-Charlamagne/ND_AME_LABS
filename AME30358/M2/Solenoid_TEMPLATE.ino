//Notre Dame
//Mechatronics
//M2 - Solenoid

int gatePIN = ***;
int solenoidState = 0; //initially the solenoid/MOSFET is OFF

void setup() {
  // put your setup code here, to run once
  pinMode(gatePIN, OUTPUT);


}

void loop() {
  //turn solenoid ON for 3 sec
  solenoidState = ***;
  digitalWrite(gatePIN,solenoidState);
  delay(***);
  
  //turn solenoid OFF for 2 sec
  solenoidState = ***;
  digitalWrite(gatePIN,solenoidState);
  delay(***);

}
