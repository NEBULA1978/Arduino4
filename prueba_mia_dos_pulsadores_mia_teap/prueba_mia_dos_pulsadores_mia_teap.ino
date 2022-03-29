//1_pulsador_enciendo_cda_pulsacion_1_led_diferente_hay_3_y_tres_
int ledA = 14;
int ledV = 15;
int ledR = 16;

int ledB = 17;
int ledC = 18;
int ledD = 19;

int boton = 20;
int boton2 = 21;
int contador = 0;
int contador2 = 0;

int estadoBoton;
int estadoBoton2;
int estadoAnteriorBoton = 0;
int estadoAnteriorBoton2 = 0;


//

//otra forma pulsadores
//bloque1
int PULSADOR = 2;
int LED = 3;
int ESTADO = LOW; 

//bloque2
int PULSADOR2 = 4;
int LED2 = 5;
int ESTADO2 = LOW; 

//bloque3
int PULSADOR3 = 6;
int LED3 = 7;
int ESTADO3 = LOW;
//yee


#define LED_A 8//motor derecho trasero
#define LED_B 9//motor izquierdo trasero
#define LED_C 10

#define BOTON 11
#define BOTON2 12
#define BOTON3 13

#define ON 1
#define OFF 0
#define TRUE 1
#define FALSE 0

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_A, OUTPUT);//motor derecho trasero
  pinMode(LED_B, OUTPUT);//motor izquierdo trasero
  pinMode(LED_C, OUTPUT);//motor derecho delantero
  pinMode(BOTON, INPUT);//por defecto esta asi
  pinMode(BOTON2, INPUT);//por defecto esta asi
  pinMode(BOTON3, INPUT);//por defecto esta asi

  //otra forma pulsadores yee
    //bloque1
  pinMode(PULSADOR, INPUT); // pin 2 entrada
  pinMode(LED, OUTPUT); // pin 3 salida

 //bloque2
  pinMode(PULSADOR2, INPUT); // pin 4 entrada
  pinMode(LED2, OUTPUT); // pin 5 salida

  //bloque3
  pinMode(PULSADOR3, INPUT); // pin 6 entrada
  pinMode(LED3, OUTPUT); // pin 7 salida
  ///yee

  //1_pulsador_enciendo_cda_pulsacion_1_led_diferente_hay_3_y_tres
  pinMode(ledA, OUTPUT);
  pinMode(ledV, OUTPUT);
  pinMode(ledR, OUTPUT);
  pinMode(boton, INPUT);
  
  pinMode(ledB, OUTPUT);
  pinMode(ledC, OUTPUT);
  pinMode(ledD, OUTPUT);
  pinMode(boton2, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  loop_led_a();
  loop_led_b();
  loop_led_c();

  //otra forma pulsadores
  loop1 ();
  loop2 ();
  loop3 ();
  loop4();
}

//otra forma
void loop_led_a()//motor derecho delantero
{
  digitalWrite(LED_A, digitalRead(BOTON));
}

void loop_led_b()//motor derecho delantero
{
  digitalWrite(LED_B, digitalRead(BOTON2));
}

void loop_led_c()
{
  digitalWrite(LED_C, digitalRead(BOTON3));

  {
  //misma variable de tiempo utiliza contador arduino
  static long ultimo_cambio = 0;//generanso variable generica de 64bits me permite tener mayo cant N enteros
  static int Estado_LED = OFF;//variableestaticavalorinicial

  long hora = millis();

  if (hora - ultimo_cambio >1000){
      ultimo_cambio = hora;

      if(Estado_LED == ON){
          digitalWrite(LED_C, LOW);
          Estado_LED = OFF;
      }else{
         digitalWrite(LED_C, HIGH);
         Estado_LED = ON ;
      }
      
  }
}}

//otra forma pulsadores bucle wile antirrebote
void loop1 () {
  while(digitalRead(PULSADOR) == LOW){ } // espero a que el pulsador se presione
  ESTADO = digitalRead(LED);       // leo estado del LED
  digitalWrite(LED, !ESTADO);      // escribo valor contrario
  while (digitalRead (PULSADOR) == HIGH){ } // antirebote
}

//bloque2
void loop2 () {
  while(digitalRead(PULSADOR2) == LOW){ } // espero a que el pulsador se presione
  ESTADO2 = digitalRead(LED2);       // leo estado del LED2
  digitalWrite(LED2, !ESTADO2);      // escribo valor contrario
  while (digitalRead (PULSADOR2) == HIGH){ } // antirebote
}


//bloque3
void loop3 () {
  while(digitalRead(PULSADOR3) == LOW){ } // espero a que el pulsador se presione
  ESTADO3 = digitalRead(LED3);       // leo estado del LED3
  digitalWrite(LED3, !ESTADO3);      // escribo valor contrario
  while (digitalRead (PULSADOR3) == HIGH){ } // antirebote
}

void loop4() {
  estadoBoton2  = digitalRead(boton2);
  if(estadoBoton2 != estadoAnteriorBoton){
    if(estadoBoton2 == LOW){
      contador2++;
      Serial.println(contador2);
      if(contador2 == 1){
        digitalWrite(ledB, HIGH);
        digitalWrite(ledC, LOW);
        digitalWrite(ledD, LOW);
      }
      else if(contador2==2){
        digitalWrite(ledB, LOW);
        digitalWrite(ledC, HIGH);
        digitalWrite(ledD, LOW);
      }
      else if(contador2==3){
        contador = 0;
        digitalWrite(ledB, LOW);
        digitalWrite(ledC, LOW);
        digitalWrite(ledD, HIGH);
      }
      
    }
  }
  estadoAnteriorBoton2 = estadoBoton2;
  delay(50);
}
