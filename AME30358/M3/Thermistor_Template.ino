//AME30358 - Mechatronics Lab
//M3 - Thermostat

int ThermistorPin = ***;
int Vs;
int dt = 1000;
float t = 0;
float logRS, Rs, T;

/*ENTER R2 AND THERMISTOR CALIBRATION CONSTANTS BELOW */
float A = 0.003361, B = 0.0002568; //Units of 1/K
float R2 = ***; //Units of Ohms

void setup() {
Serial.begin(9600);
}

void loop() {
  t = millis()/1000.0;
  Vs = analogRead(ThermistorPin);
  /* Calulate thermistor resitance from measured voltage */
  Rs = R2 * (1023.0 / (float)Vs - 1.0);
  
  logRS = log(Rs/10000);

   /* Calulate temperature from thermistor resitance */
  T = (1.0 / (A + B*logRS));

  Serial.print(t);
  Serial.print(", "); 
  Serial.println(T);

  
 
  //t = t + dt;
  delay(dt);
}
