//AME30358 - Mechatronics Labs
//M3 - Thermostat

int fanPIN = ***;
int fanState = 0;

void setup() {
  // put your setup code here, to run once
  pinMode(fanPIN, OUTPUT);


}

void loop() {
  //turn fan ON for 5 sec
  fanState = ***;
  digitalWrite(fanPIN,fanState);
  delay(5000);
  
  //turn fan OFF for 5 sec
  fanState = ***;
  digitalWrite(fanPIN,fanState);
  delay(5000);

}
