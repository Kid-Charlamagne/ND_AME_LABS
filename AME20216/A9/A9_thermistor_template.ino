//AME20216
//A9 - 1st Order Response 
//Part 1 - Response to an impulse

int ThermistorPin = ***; //Enter the pin the thermistor is connected to
int Vs;
int dt = 1000;
float t = 0;
float logRS, Rs, T;

/*ENTER R2 AND THERMISTOR CALIBRATION CONSTANTS BELOW */
float A = 0.003361, B = 0.0002568; //Units of 1/K
float R2 = ***; //Enter the measured value of R2 in units of Ohms

void setup() {
Serial.begin(9600);
}

void loop() {
  t = millis()/1000.0; //time (seconds)
  Vs = analogRead(ThermistorPin); //read in the voltage from the thermistor
  /* Calulate thermistor resitance from measured voltage */
  Rs = R2 * (1023.0 / (float)Vs - 1.0);
  
  logRS = log(Rs/10000);

   /* Calulate temperature from thermistor resitance */
  T = (1.0 / (A + B*logRS)); //temperature (kelvin)

  Serial.print(t); //first column is time
  Serial.print(", "); 
  Serial.println(T); //second column is temperature

  
 
  //t = t + dt;
  delay(dt);
}
