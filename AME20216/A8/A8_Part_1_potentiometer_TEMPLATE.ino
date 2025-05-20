/*ENTER PIN NUMBERS FOR POTENTIOMETER AND LED BELOW*/
const int potentiometer = ***;
const int LED = ***;
int POT_output = 0;
int LED_brightness = 0;

void setup() {
  Serial.begin(9600);
  pinMode (LED, OUTPUT);
}

void loop() {
  POT_output = analogRead(potentiometer);
  LED_brightness = map(POT_output,0,1023,0,255);
  analogWrite (LED, LED_brightness);

  Serial.print("Potentiometer reading: ");
  Serial.print(POT_output);
  Serial.print(", LED brightness: ");
  Serial.print(LED_brightness);
  Serial.println();
  delay(100);
}
