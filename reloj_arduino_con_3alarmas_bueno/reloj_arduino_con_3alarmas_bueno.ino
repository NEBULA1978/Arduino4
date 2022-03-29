unsigned long tiempoactual = 0;
unsigned long tiempoactual2 = 0;

long mitiempo;
long inicio;
long final;

long mitiempo2;
long inicio2;
long final2;

long mitiempo3;
long inicio3;
long final3;

long mitiempo4;
long inicio4;
long final4;

long mitiempo5;
long inicio5;
long final5;

int lecturaboton_old = 1;

int hour = 14;
int minute = 28;
int second = 25;

int encendido[] = {14, 28, 30};
int apagado[] = {14, 28, 40};

int encendido2[] = {14, 28, 45};
int apagado2[] = {14, 28, 50};


int encendido3[] = {14, 28, 55};
int apagado3[] = {14, 29, 00};

int encendido4[] = {14, 29, 05};
int apagado4[] = {14, 29, 15};

int encendido5[] = {14, 29, 25};
int apagado5[] = {14, 29, 45};

void setup() {
    Serial.begin(9600);
    pinMode(A5, OUTPUT);
    pinMode(13, OUTPUT);
    pinMode(6, INPUT_PULLUP);

    inicio = encendido[0]*100000 + encendido[1]*1000 + encendido[2]*10;
    final = apagado[0]*100000 + apagado[1]*1000 + apagado[2]*10;

    inicio2 = encendido2[0]*100000 + encendido2[1]*1000 + encendido2[2]*10;
    final2 = apagado2[0]*100000 + apagado2[1]*1000 + apagado2[2]*10;

    inicio3 = encendido3[0]*100000 + encendido3[1]*1000 + encendido3[2]*10;
    final3 = apagado3[0]*100000 + apagado3[1]*1000 + apagado3[2]*10;

    inicio4 = encendido4[0]*100000 + encendido4[1]*1000 + encendido4[2]*10;
    final4 = apagado4[0]*100000 + apagado4[1]*1000 + apagado4[2]*10;

    inicio5 = encendido5[0]*100000 + encendido5[1]*1000 + encendido5[2]*10;
    final5 = apagado5[0]*100000 + apagado5[1]*1000 + apagado5[2]*10;
}


void loop() {
    loop1();
    loop2();
    loop3();
    loop4();
    loop5();
}

//para encender led y apagar o encender con HIGH
void parpadeo(){
  int lecturaled = digitalRead(A5);
  digitalWrite(A5, !lecturaled);
}

//para hacer reloj
void tiempo(){
    second++;
    if(second == 60){
        second = 0;
        minute++;
    }
  
    if(minute == 60){
        minute = 0;
        hour++;
    }
  
    if(hour == 24){
      hour = 0;
    }
  
    Serial.print(hour);
    Serial.print(":");
    Serial.print(minute);
    Serial.print(":");
    Serial.println(second);
}

//funcion del loop
void loop1() {
    int lecturaboton = digitalRead(6);

    if(lecturaboton != lecturaboton_old){
        if(lecturaboton == 0){
            int lecturaled13 = digitalRead(13);
            digitalWrite(13, !lecturaled13);
        }
    }

    lecturaboton_old = lecturaboton;

    if(millis() >= tiempoactual + 1000){
        tiempoactual = millis();
        tiempo(); 
    }


    mitiempo = hour*100000 + minute*1000 + second*10;
    //Serial.println(mitiempo);

    bool minimo = mitiempo > inicio;
    bool maximo = mitiempo < final;
    
    if( minimo && maximo ){
        if(millis() >= tiempoactual2 + 100){
            tiempoactual2 = millis();
            Serial.println("LED!");
            parpadeo();
        }
    }else{
        digitalWrite(A5, 0);
    }
}

//segunda alarma

//funcion del loop
void loop2() {
    int lecturaboton = digitalRead(6);

    if(lecturaboton != lecturaboton_old){
        if(lecturaboton == 0){
            int lecturaled13 = digitalRead(13);
            digitalWrite(13, !lecturaled13);
        }
    }

    lecturaboton_old = lecturaboton;

    if(millis() >= tiempoactual + 1000){
        tiempoactual = millis();
        tiempo(); 
    }


    mitiempo2 = hour*100000 + minute*1000 + second*10;
    //Serial.println(mitiempo2);

    bool minimo2 = mitiempo2 > inicio2;
    bool maximo2 = mitiempo2 < final2;
    
    if( minimo2 && maximo2 ){
        if(millis() >= tiempoactual2 + 100){
            tiempoactual2 = millis();
            Serial.println("LED!");
            parpadeo2();
        }
    }else{
        digitalWrite(A5, 0);
    }
}

//para parpadeo y reloj2
//para encender led y apagar o encender con HIGH
void parpadeo2(){
  int lecturaled = digitalRead(A5);
  digitalWrite(A5, !lecturaled);
}

//para hacer reloj2
void tiempo2(){
    second++;
    if(second == 60){
        second = 0;
        minute++;
    }
  
    if(minute == 60){
        minute = 0;
        hour++;
    }
  
    if(hour == 24){
      hour = 0;
    }
  
    Serial.print(hour);
    Serial.print(":");
    Serial.print(minute);
    Serial.print(":");
    Serial.println(second);
}

// tercera alarma loop3

//funcion del loop
void loop3() {
    int lecturaboton = digitalRead(6);

    if(lecturaboton != lecturaboton_old){
        if(lecturaboton == 0){
            int lecturaled13 = digitalRead(13);
            digitalWrite(13, !lecturaled13);
        }
    }

    lecturaboton_old = lecturaboton;

    if(millis() >= tiempoactual + 1000){
        tiempoactual = millis();
        tiempo(); 
    }


    mitiempo3 = hour*100000 + minute*1000 + second*10;
    //Serial.println(mitiempo);

    bool minimo3 = mitiempo3 > inicio3;
    bool maximo3 = mitiempo3 < final3;
    
    if( minimo3 && maximo3 ){
        if(millis() >= tiempoactual2 + 100){
            tiempoactual2 = millis();
            Serial.println("LED!");
            parpadeo3();
        }
    }else{
        digitalWrite(A5, 0);
    }
}

//funcion tiempo3 y parpadeo
//para parpadeo y reloj
//para encender led y apagar o encender con HIGH
void parpadeo3(){
  int lecturaled = digitalRead(A5);
  digitalWrite(A5, !lecturaled);
}

//para hacer reloj3
void tiempo3(){
    second++;
    if(second == 60){
        second = 0;
        minute++;
    }
  
    if(minute == 60){
        minute = 0;
        hour++;
    }
  
    if(hour == 24){
      hour = 0;
    }
  
    Serial.print(hour);
    Serial.print(":");
    Serial.print(minute);
    Serial.print(":");
    Serial.println(second);
}


//funcion del loop4
void loop4() {
    int lecturaboton = digitalRead(6);

    if(lecturaboton != lecturaboton_old){
        if(lecturaboton == 0){
            int lecturaled13 = digitalRead(13);
            digitalWrite(13, !lecturaled13);
        }
    }

    lecturaboton_old = lecturaboton;

    if(millis() >= tiempoactual + 1000){
        tiempoactual = millis();
        tiempo(); 
    }


    mitiempo4 = hour*100000 + minute*1000 + second*10;
    //Serial.println(mitiempo);

    bool minimo4 = mitiempo4 > inicio4;
    bool maximo4 = mitiempo4 < final4;
    
    if( minimo4 && maximo4 ){
        if(millis() >= tiempoactual2 + 100){
            tiempoactual2 = millis();
            Serial.println("LED!");
            parpadeo4();
        }
    }else{
        digitalWrite(A5, 0);
    }
}


//funcion tiempo4 y parpadeo
//para parpadeo y reloj
//para encender led y apagar o encender con HIGH
void parpadeo4(){
  int lecturaled = digitalRead(A5);
  digitalWrite(A5, !lecturaled);
}

//para hacer reloj
void tiempo4(){
    second++;
    if(second == 60){
        second = 0;
        minute++;
    }
  
    if(minute == 60){
        minute = 0;
        hour++;
    }
  
    if(hour == 24){
      hour = 0;
    }
  
    Serial.print(hour);
    Serial.print(":");
    Serial.print(minute);
    Serial.print(":");
    Serial.println(second);
}

//para encender led y apagar o encender con HIGH
void parpadeo5(){
  int lecturaled = digitalRead(A5);
  digitalWrite(A5, !lecturaled);
}



//funcion del loop5
void loop5() {
    int lecturaboton = digitalRead(6);

    if(lecturaboton != lecturaboton_old){
        if(lecturaboton == 0){
            int lecturaled13 = digitalRead(13);
            digitalWrite(13, !lecturaled13);
        }
    }

    lecturaboton_old = lecturaboton;

    if(millis() >= tiempoactual + 1000){
        tiempoactual = millis();
        tiempo(); 
    }


    mitiempo5 = hour*100000 + minute*1000 + second*10;
    //Serial.println(mitiempo);

    bool minimo5 = mitiempo5 > inicio5;
    bool maximo5 = mitiempo5 < final5;
    
    if( minimo5 && maximo5 ){
        if(millis() >= tiempoactual2 + 100){
            tiempoactual2 = millis();
            Serial.println("LED!");
            parpadeo4();
        }
    }else{
        digitalWrite(A5, 0);
    }
}

//para hacer reloj
void tiempo5(){
    second++;
    if(second == 60){
        second = 0;
        minute++;
    }
  
    if(minute == 60){
        minute = 0;
        hour++;
    }
  
    if(hour == 24){
      hour = 0;
    }
  
    Serial.print(hour);
    Serial.print(":");
    Serial.print(minute);
    Serial.print(":");
    Serial.println(second);
}
