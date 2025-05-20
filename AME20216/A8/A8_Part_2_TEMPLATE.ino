int ThermistorPin = A0;
int Vs;
int dt = 1000;
int t = 0;
float logRS, Rs, T;

/*ENTER R2 AND THERMISTOR CALIBRATION CONSTANTS BELOW */
float A = ***, B = ***; //Units of 1/K
float R2 = ***; //Units of Ohms

void setup() {
Serial.begin(9600);
}

void loop() {
  
  Vs = analogRead(ThermistorPin);
  /* Calulate thermistor resitance from measured voltage */
  Rs = R2 * (1023.0 / (float)Vs - 1.0);
  
  logRS = log(Rs/10000);

   /* Calulate temperature from thermistor resitance */
  T = (1.0 / (A + B*logRS));

  Serial.print("time(ms): "); 
  Serial.println(t);
  
  Serial.print("Analog A0: "); 
  Serial.println(Vs);
  
  Serial.print("Resistance: "); 
  Serial.print(Rs); 
  Serial.println("Ohms");

  Serial.print("Temperature: "); 
  Serial.println(T);
  Serial.println("\n"); 

 
  t = t + dt;
  delay(dt);
}
