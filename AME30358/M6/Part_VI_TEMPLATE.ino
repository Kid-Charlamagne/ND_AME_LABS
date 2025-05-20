// Notre Dame AME
// Stepper motor driver
// NEMA 17 stepper has 200 pulses per revolution

//FILL IN THE ***s BELOW

int enablePin = 7;
int dirPin = 8;
int pulPin = 9;
int leftLimPIN = ***;
int rightLimPIN = ***;

int pulseCount = 0;
int dir = 0; //0 for left, 1 for right

float d = ***; //measured distance between limit switches, cm 
float x;  //position, cm
float a; //calibration constand, pulses/cm


void setup() {                
  Serial.begin(9600); // open the serial port at 9600 bps:
   
  pinMode(dirPin, OUTPUT); //pin that controls direction    
  pinMode(pulPin, OUTPUT); //pin that pulses for each step
  pinMode(enablePin, OUTPUT); //pin that enables driver...
  //set to LOW to shut off & conserve energy when not in use

  pinMode(leftLimPIN, INPUT); //read left limit switch
  pinMode(rightLimPIN, INPUT); //read right limit switch
  
  digitalWrite(dirPin, dir);
  digitalWrite(pulPin, LOW);
  digitalWrite(enablePin, HIGH);
}

void loop() { 
  
  //FIRST MOVE TO THE LEFT LIMIT
  
  dir = ***;  //fill in with HIGH or LOW
  digitalWrite(dirPin, dir);
  
  while(***){ //what condition causes it to exit this loop (stop moving left)?
  digitalWrite(pulPin, HIGH);
  delayMicroseconds(700);         
  digitalWrite(pulPin, LOW); 
  delayMicroseconds(700);
  pulseCount++;

  }


  //NEXT MOVE TO THE RIGHT LIMIT, COUNT NUMBER OF PULSES TO GO DISTANCE d
  
  dir = ***; //change direction after hitting left limit switch
  digitalWrite(dirPin, dir); //turn back to go right
  pulseCount = 0; //begin new count of pulses
  
  while(***){  //what condition causes it to exit this loop (stop moving right)?
    digitalWrite(pulPin, HIGH);
    delayMicroseconds(700);    
    digitalWrite(pulPin, LOW); 
    delayMicroseconds(700);
    pulseCount++;
  }

    a = ***; //enter formula to compute calibration const, pulses/cm
    x = d;
    dir = ***; //change direction, fill in with HIGH or LOW
    digitalWrite(dirPin, dir); //turn back to go left 

  //GO TO THE CENTRAL HOME POSITION AT x = 20cm
  while(x > 20){
    digitalWrite(pulPin, HIGH);
    delayMicroseconds(700);     
    digitalWrite(pulPin, LOW); 
    delayMicroseconds(700);
    pulseCount--;
    x = float(pulseCount)/a; //use calibration constant to compute position in cm
  }

  digitalWrite(enablePin, LOW); //disable to save energy, avoid overheating
  
  Serial.print(x);
  Serial.println(" cm");
  Serial.print("calibration const. a = ");
  Serial.print(a);
  Serial.println(" pulses/cm");

  //INFINITE LOOP
  while(1){
    //sit and do nothing, forever
  }
            
}
