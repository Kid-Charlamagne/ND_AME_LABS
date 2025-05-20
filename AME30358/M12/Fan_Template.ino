//AME40453 - Automation and Controls Lab
//C8 - PLC Thermostat

int fanPIN = ***;
int fanState = 0;

void setup() {
  // put your setup code here, to run once
  pinMode(fanPIN, OUTPUT);


}

void loop() {
  //turn fan ON for 3 sec
  fanState = ***;
  digitalWrite(fanPIN,fanState);
  delay(***);
  
  //turn fan OFF for 3 sec
  fanState = ***;
  digitalWrite(fanPIN,fanState);
  delay(***);

}
