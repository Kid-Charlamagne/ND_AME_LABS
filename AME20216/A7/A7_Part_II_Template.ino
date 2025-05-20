//A7 - Microcontrollers
//Part II - Analog Pressure Sensor

//variable declaration
int pressurePin = A0;
float Vout; //Sensor voltage
float pressure; //pressure (Pa),
float u; //airspeed (m/s)
float rhoA = 1.25; //density of air, kg/m^3

//Replace the *** below with the calibration constants
float a = ***; //units of Pa/Volt
float b = ***; //units of Pa

void setup()
{
   Serial.begin(9600);
}

void loop()
{
  Vout = analogRead(pressurePin)*5.0/1023.0; //convert the 10-bit integer to a voltage

  pressure = a*Vout+b;  //compute measured stagnation pressure, Pa
  
  u = sqrt(2.0*abs(pressure)/rhoA); //compute measured airspeed, m/s

  // Print pressure and airspeed to the serial monitor
  Serial.print("p = ");
  Serial.print(pressure);
  Serial.print(" Pa,   u = ");
  Serial.print(u);
  Serial.println(" m/s");

  delay(500);
}
