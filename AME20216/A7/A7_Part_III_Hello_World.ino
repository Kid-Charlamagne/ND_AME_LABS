//A7 - Microcontrollers
//Part III - Hello World!

#include <LiquidCrystal.h>
int tempPin = 0;
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
 
  // Display Hello World! on top
  // set the cursor to column 0, line 0
  // (note: line 0 is the first row, since counting begins with 0):
  lcd.setCursor(0, 0);
  lcd.print("Hello World!    ");
  
  // Leave bottom row blank
  lcd.setCursor(0, 1);
  lcd.print("                ");
  
  delay(2000);
  
  // Display "Here come" on top
  lcd.setCursor(0, 0);
  lcd.print("Here come       ");
  
  // Display "the Irish!" on bottom
  lcd.setCursor(0, 1);
  lcd.print("the Irish!      ");
  delay(2000);
}
