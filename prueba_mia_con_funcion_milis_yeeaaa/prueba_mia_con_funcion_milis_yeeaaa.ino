#define LED_A 13
#define BOTON 5
#define ON 1
#define OFF 0
#define TRUE 1
#define FALSE 0



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED_A, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  loop_led_A();
//  loop_led_apagar();
}

void loop_led_A()

{
  //misma variable de tiempo utiliza contador arduino
  static long ultimo_cambio = 0;//generanso variable generica de 64bits me permite tener mayo cant N enteros
  static int Estado_LED = OFF;//variableestaticavalorinicial

  long hora = millis();

  if (hora - ultimo_cambio >1000){
      ultimo_cambio = hora;

      if(Estado_LED == OFF){
          digitalWrite(LED_A, HIGH);
          Serial.println(HIGH);
          Estado_LED = HIGH;
      }
      
  }
}
/*
void loop_led_apagar(){
 //misma variable de tiempo utiliza contador arduino
  static long ultimo_cambio = 0;//generanso variable generica de 64bits me permite tener mayo cant N enteros
  static int Estado_LED = OFF;//variableestaticavalorinicial

  long hora = millis();

  if (hora - ultimo_cambio >1000){
      ultimo_cambio = hora;

      if(Estado_LED == ON){
          digitalWrite(LED_A, LOW);
          Serial.println(LOW);
          Estado_LED = LOW;
      }
      
  }
}
*/
