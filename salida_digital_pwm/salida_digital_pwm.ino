//pwm
int ledPrueba = 9;
void setup() {
  // put your setup code here, to run once:
  pinMode(ledPrueba,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(ledPrueba,0);
  delay(1000);
    analogWrite(ledPrueba,65);
  delay(1000);
    analogWrite(ledPrueba,127);
  delay(1000);
    analogWrite(ledPrueba,255);
  delay(1000);
}
