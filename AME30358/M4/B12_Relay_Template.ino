//AME20217 - Lab II
//B12 - Hyrdraulic System

//Fill in the *** below with the digital I/O pin numbers 
const int pumpPIN = ***;     // the number of the pump relay (IN1)
const int solenoidPIN =  ***;      // the number of the solenoid relay (IN2)


void setup() {
  // initialize the pump pin as an output:
  pinMode(pumpPIN, OUTPUT);
  // initialize the solenoid pin as an output:
  pinMode(solenoidPIN, OUTPUT);
}

void loop() {

  //PUMP - Close valve, turn on pump
  digitalWrite(solenoidPIN, LOW); 
  digitalWrite(pumpPIN, HIGH);
  // Enter PUMP TIME below (in milliseconds)
  delay(2000);

  //PAUSE - Close valve, turn off pump
  digitalWrite(solenoidPIN, LOW);
  digitalWrite(pumpPIN, LOW);
  // Enter QUIESCENT PAUSE TIME below (in milliseconds)
  delay(1000);

  //DRAIN - Open valve, turn off pump
  digitalWrite(solenoidPIN, HIGH);
  digitalWrite(pumpPIN, LOW);
  // Enter DRAIN TIME below (in milliseconds)
  delay(2000);

  //PAUSE - Close valve, turn off pump
  digitalWrite(solenoidPIN, LOW);
  digitalWrite(pumpPIN, LOW);
  // Enter QUIESCENT PAUSE TIME below (in milliseconds)
  delay(1000);

}
