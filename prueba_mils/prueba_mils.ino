// constants won’t change. Used here to set a pin number:
const int ledPin = LED_BUILTIN;// the number of the LED pin
// Variables will change:
int ledState = LOW; // ledState used to set the LED
// Generally, you should use «unsigned long» for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0; // will store last time LED was updated
unsigned long currentMillis = 0; // will store current time LED
void setup() {
// set the digital pin as output:
pinMode(ledPin, OUTPUT);
}
void loop() {

currentMillis = millis(); //take the current time

if (currentMillis – previousMillis >= 1000 && ledState==LOW) {
  ledState = HIGH;
  digitalWrite(ledPin, ledState);
// save the last time you blinked the LED
  previousMillis = currentMillis;
}
else if
  {
   (currentMillis – previousMillis >= 1000 && ledState==HIGH);
  }
  ledState = LOW;
  digitalWrite(ledPin, ledState);
// save the last time you blinked the LED
  previousMillis = currentMillis;
  }


}
