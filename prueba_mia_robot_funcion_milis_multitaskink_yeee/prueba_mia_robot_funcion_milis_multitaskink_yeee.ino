#define LED_A 9//motor derecho trasero
#define LED_B 8//motor izquierdo trasero
#define LED_C 7//motor derecho delantero
#define LED_D 6//motor izquierdo delantero
#define BOTON 5
#define BOTON2 10
#define BOTON3 11
#define BOTON4 12
#define ON 1
#define OFF 0
#define TRUE 1
#define FALSE 0

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_A, OUTPUT);//motor derecho trasero
  pinMode(LED_B, OUTPUT);//motor izquierdo trasero
  pinMode(LED_C, OUTPUT);//motor derecho delantero
  pinMode(LED_D, OUTPUT);//motor izquierdo delantero

  pinMode(BOTON, INPUT);//por defecto esta asi
  pinMode(BOTON2, INPUT);//por defecto esta asi
  pinMode(BOTON3, INPUT);//por defecto esta asi
  pinMode(BOTON4, INPUT);//por defecto esta asi
}

void loop() {
  // put your main code here, to run repeatedly:
  loop_led_A();//motor derecho trasero
  loop_led_B();//motor izquierdo trasero
  loop_led_C();//motor derecho delantero
  loop_led_D();//motor izquierdo delantero
}

void loop_led_A()//motor derecho trasero
{
  //misma variable de tiempo utiliza contador arduino
  static long ultimo_cambio = 0;//generanso variable generica de 64bits me permite tener mayo cant N enteros
  static int Estado_LED = OFF;//variableestaticavalorinicial

  long hora = millis();

  if (hora - ultimo_cambio >100){
      ultimo_cambio = hora;

      if(Estado_LED == ON){
          digitalWrite(LED_A, LOW);
          Estado_LED = OFF;
      }else{
         digitalWrite(LED_A, HIGH);
         Estado_LED = ON ;
      }
      
  }
}

void loop_led_B()//motor izquierdo trasero
{
  static long ultimo_cambio = 0;//generanso variable generica de 64bits me permite tener mayo cant N enteros
  static int Estado_LED = OFF;

  long hora = millis();//que hora actual

  if (hora - ultimo_cambio >250){//hora actualmenos horaultimo cambio es mayor a 1segundo
      ultimo_cambio = hora;

      Estado_LED = !Estado_LED;//si era 1 pasa a 0 
      digitalWrite(LED_B, Estado_LED);

    //  if(Estado_LED == ON){
    //      digitalWrite(LED_B, LOW);
    //      Estado_LED = OFF;
    //  }else{
   //      digitalWrite(LED_B, HIGH);
    //     Estado_LED = ON ;
   //   }
      
      }
}

void loop_led_C()//motor derecho delantero
{
  digitalWrite(LED_C, digitalRead(BOTON));
}

void loop_led_D()//motor izquierdo delantero
{
  digitalWrite(LED_D, digitalRead(BOTON2));
  
}
