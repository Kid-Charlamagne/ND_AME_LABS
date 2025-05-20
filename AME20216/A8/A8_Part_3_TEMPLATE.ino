/*
A8 - Part III Template
Fill in the '***' below.

*/

// Enter the digital pin numbers that the Red and Green LEDs are connected to
const int REDledPin = ***;       // pin that the Red LED is attached to
const int GREENledPin = ***;       // pin that the Green LED is attached to


int ThermistorPin = A0;
int Vs;
int dt = 1000;
int t = 0;
float logRS, Rs, T;

/*ENTER R2 AND THERMISTOR CALIBRATION CONSTANTS BELOW */
float A = ***, B = ***; //Units of 1/K
float R2 = ***; //Units of Ohms

void setup() {
  // initialize the LED pin as an output:
  pinMode(REDledPin, OUTPUT);
  pinMode(GREENledPin, OUTPUT);
  // initialize serial communications:
  Serial.begin(9600);
}

void loop() {
  Vs = analogRead(ThermistorPin);
  /* Calulate thermistor resitance from measured voltage */
  Rs = R2 * (1023.0 / (float)Vs - 1.0);
  
  logRS = log(Rs/10000);

   /* Calulate temperature from thermistor resitance */
  T = (1.0 / (A + B*logRS));


  // if the temperature T > 302K, light up the Red, turn off the Green
  // if the temperature T < 302K, light up the Green, turn off the Red
  if (T > ***) {  // enter the threshold temperature
    digitalWrite(REDledPin, ***); //enter a value of HIGH or LOW
    digitalWrite(GREENledPin, ***); //enter a value of HIGH or LOW
  } else {
    digitalWrite(REDledPin, ***); //enter a value of HIGH or LOW
    digitalWrite(GREENledPin, ***); //enter a value of HIGH or LOW
  }
  
  t = t + dt;
  delay(dt);

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

}

