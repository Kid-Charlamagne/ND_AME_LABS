//AME20216
//A9 - 1st Order Response 
//Part II - Response to an Oscillating Heat Source

#define PI 3.1415926535897932384626433832795

int ThermistorPin = A0;
int HeaterPin = 3;
int Vs;
int dt = 500;
float t = 0;
float logRS, Rs, T;

float f = 0.015; //Driving Freq. (Hz)
float w = 2*PI*f; //Driving Freq. (rad/s)
float Vh = 11.0;  //heater voltage, V
float Rh = 22.0;  //Heater Resistance, Ohms
float Q, PWM; //Heater Power, PWM


/*ENTER R2 AND THERMISTOR CALIBRATION CONSTANTS BELOW */
float A = 0.003361, B = 0.0002568; //Units of 1/K
float R2 = 4650; //Units of Ohms

void setup() {
  Serial.begin(9600);
  pinMode(HeaterPin, OUTPUT); //Declare heater pin to be an output
}

void loop() {
  t = millis()/1000.0; //time (seconds)
  
  PWM = 127+127*sin(w*t); //PWM duty cycle (0 - 255)
  Q = Vh*Vh/Rh*PWM/255;  //Heater power based on duty cycle (watts)
  
  analogWrite(HeaterPin,PWM); //Output a PWM signal from the HeaterPin
  Vs = analogRead(ThermistorPin); //Read the analog voltage from the thermistor
  
  /* Calulate thermistor resitance from measured voltage */
  Rs = R2 * (1023.0 / (float)Vs - 1.0); 
  logRS = log(Rs/10000);
   /* Calulate temperature from thermistor resitance */
  T = (1.0 / (A + B*logRS));

  Serial.print(t);
  Serial.print(", "); 
  Serial.print(PWM);
  Serial.print(", "); 
  Serial.print(Q);
  Serial.print(", "); 
  Serial.println(T);

  delay(dt);
}
