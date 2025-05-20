//This code is to use with L298n Dual H-bridge motor driver

int in1 = 5; //Input1 is connected to digital pin 5
int in2 = 4; //Input2 is connected to digital pin 4 
int speedPWM = 3; //Remove jumper from EnableA on L298N and connect to pin 10

void setup() {
  pinMode(in1, OUTPUT); //Declaring the pin modes, obviously they're outputs
  pinMode(in2, OUTPUT);
  pinMode(speedPWM, OUTPUT);
}

//Refer to the L298N LOGIC TABLE in the lab handout
//Fill in the *** below with either HIGH or LOW


void TurnForward(int x){
  digitalWrite(in1, ***);
  digitalWrite(in2, ***);
  analogWrite(speedPWM,x);
}

void TurnOFFA(){
  digitalWrite(in1, ***);
  digitalWrite(in2, ***);
  analogWrite(speedPWM,0);
}
void TurnReverse(int x){
  digitalWrite(in1, ***);
  digitalWrite(in2, ***);
  analogWrite(speedPWM,x);
}

void loop() {
  TurnForward(255);  //Sequence: turning on low speed, stop, turning again in high speed and stop
  delay(2000);
  
  TurnOFFA();
  delay(2000);

  TurnReverse(255);  //Sequence: turning on low speed, stop, turning again in high speed and stop
  delay(2000);

  TurnOFFA();
  delay(2000);
}
