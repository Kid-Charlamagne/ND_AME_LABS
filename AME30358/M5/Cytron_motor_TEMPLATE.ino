 //This code is for use with Cytron Motor Driver Board


int dirPIN = 2; //motor direction pin
int pwmPIN = 3; //motor PWM pin

void setup() {
  pinMode(dirPIN, OUTPUT); //Declaring the GPIO pins to be outputs
  pinMode(pwmPIN, OUTPUT);
}

void TurnForward(int x){  \\Turn forward with a PWM power x, where 255 is the maximum power
  digitalWrite(dirPIN, LOW);
  analogWrite(pwmPIN,x);
}

void TurnOFFA(){  \\Stop the motor from spinning
  digitalWrite(dirPIN, LOW);
  analogWrite(pwmPIN,0);
}

//Write a function TurnReverse(int x) that turns it in the opposite direction.

void loop() {
  //Replace with code to make it turn one direction for 4 seconds, then 
  //the opposite direction for 4 seconds.  Then repeat.
  TurnForward(30);    

}
