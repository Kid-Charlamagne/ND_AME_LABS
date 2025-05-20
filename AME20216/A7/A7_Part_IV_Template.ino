//A7 - Microcontrollers
//Part IV - Avionics Interface

#include <LiquidCrystal.h>

//variable declaration
int pressurePin = A0;
float Vout; //Sensor voltage
float pressure; //pressure (Pa),
float u; //airspeed (m/s)
float rhoA = 1.25; //density of air, kg/m^3

//Replace the *** below with the calibration constants
float a = ***; //units of Pa/Volt
float b = ***; //units of Pa


//                BS  E  D4 D5  D6 D7
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
void setup()
{
  /*lcd.begin(cols, rows)
    lcd: a variable of type LiquidCrystal
    cols: the number of columns that the display has
    rows: the number of rows that the display has 
  */
  lcd.begin(16, 2);
}
void loop()
{
  Vout = analogRead(pressurePin)*5.0/1023.0; //convert the 10-bit integer to a voltage

  pressure = a*Vout+b;  //compute measured stagnation pressure, Pa
  
  u = sqrt(2.0*abs(pressure)/rhoA); //compute measured airspeed, m/s


  // Display Pressure in Pa
  lcd.setCursor(0, 0);
  lcd.print("P =         Pa  ");
  lcd.setCursor(4, 0);
  lcd.print(pressure);

    // Display Airspeed in m/s
  lcd.setCursor(0, 1);
  lcd.print("u =         m/s ");
  lcd.setCursor(4, 1);
  lcd.print(u);

  delay(500);
}
