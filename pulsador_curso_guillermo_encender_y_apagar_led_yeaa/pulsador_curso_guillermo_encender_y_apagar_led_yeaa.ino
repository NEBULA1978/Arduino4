#define pinPulsador 2

void setup() {
  // put your setup code here, to run once:
  pinMode(pinPulsador, INPUT);
  pinMode(13, OUTPUT);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  if (digitalRead(pinPulsador))
  {
    digitalWrite(13, HIGH);
  }
  else
    digitalWrite(13, LOW);
}
