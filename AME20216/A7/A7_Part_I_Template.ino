//A7 - Microcontrollers
//Part I - Digital Flip-Flop

//Replace each *** below with the correct pin numbers
const int  buttonPin = ***;    // the pin for the pushbutton 
const int YELLOWpin = ***;       // the pin for the yellow LED 
const int GREENpin = ***;       // the pin for the green LED

// Variables will change:
int buttonPushCounter = 0;   // counter for the number of button presses
int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button
int colorFlag = 0;          //single bit that determines which color is ON

void setup() {
  // initialize the button pin as a input:
  pinMode(buttonPin,INPUT);
  // initialize the LED pins as an output:
  pinMode(YELLOWpin, OUTPUT);
  pinMode(GREENpin, OUTPUT);
  // initialize serial communication:
  Serial.begin(9600);
}


void loop() {
  // read the pushbutton input pin:
  buttonState = digitalRead(buttonPin);

  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    if (buttonState == HIGH) {
      // if the current state is HIGH then the button went from off to on:
      colorFlag = !colorFlag; //invert colorFlag boolean
      buttonPushCounter++;    // if the state has changed, increment the counter
      Serial.println("on");
      Serial.print("number of button pushes: ");
      Serial.println(buttonPushCounter);
    } else {
      // if the current state is LOW then the button went from on to off:
      Serial.println("off");
    }
    // Delay reading the switch to filter noise (AKA "switch bounce")
    delay(50);
  }
  // save the current state as the last state, for next time through the loop
  lastButtonState = buttonState;

  //Replace each *** below with HIGH or LOW so that it does what the comments say
  if (colorFlag) {
  // turn ON green, turn OFF yellow if colorFlag is HIGH (true)
    digitalWrite(GREENpin, ***);
    digitalWrite(YELLOWpin, ***);
  } 
  else {
  // turn OFF green, turn ON yellow if colorFlag is LOW (false)
    digitalWrite(GREENpin, ***);
    digitalWrite(YELLOWpin, ***);
  }

}
