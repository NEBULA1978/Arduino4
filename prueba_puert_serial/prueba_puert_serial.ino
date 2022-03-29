void setup () {
     Serial.begin(9600);
     while(!Serial) { ; }
}
void loop () {
     if( Serial.available()> 0) {
          int letras = Serial.available();    
          char palabra[letras];
          for(int x=0; x<letras; x++) palabra[x]= Serial.read();
         
          for(int i=0; i<letras; i++) palabra[i] -= 32; //Cambio de minúsculas a mayúsculas
         
          Serial.print(palabra);
     }
     delay(20);
}
