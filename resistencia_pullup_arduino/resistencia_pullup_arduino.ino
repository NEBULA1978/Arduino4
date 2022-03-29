
programación:
int pulsador=7;
int led_rojo=3;
int led_verde=2;
int estado=0;

void setup() {
  pinMode(pulsador, INPUT_PULLUP);
  pinMode(led_rojo, OUTPUT);
  pinMode(led_verde, OUTPUT);

}

void loop() {
  
  estado = digitalRead(pulsador);
  
  if (estado == HIGH) {
    digitalWrite(led_rojo, HIGH);
    digitalWrite(led_verde, LOW);
  } else {
    digitalWrite(led_rojo, LOW);
    digitalWrite(led_verde, HIGH);
  }
}
