// Notre Dame AME
// Stepper motor driver
// NEMA 17 stepper has 200 pulses per revolution

int enablePin = 7;
int dirPin = 8;
int pulPin = 9;
int pulseCount = 0;
int dir = 0;

void setup() {                
  Serial.begin(9600); // open the serial port at 9600 bps:
   
  pinMode(dirPin, OUTPUT); //pin that controls direction    
  pinMode(pulPin, OUTPUT); //pin that pulses for each step
  pinMode(enablePin, OUTPUT); //pin that enables driver...
  //set to LOW to shut off & conserve energy when not in use
  
  digitalWrite(dirPin, dir);
  digitalWrite(pulPin, LOW);
  digitalWrite(enablePin, HIGH);
}

void loop() {
  digitalWrite(pulPin, HIGH);
  delayMicroseconds(600);
  //delay(1);          
  digitalWrite(pulPin, LOW); 
  //delay(1);
  delayMicroseconds(600);
  pulseCount++;

  Serial.println(pulseCount);

  if(pulseCount % 201 == 1){
    dir = !dir;
    digitalWrite(dirPin, dir);
  }
            
}
