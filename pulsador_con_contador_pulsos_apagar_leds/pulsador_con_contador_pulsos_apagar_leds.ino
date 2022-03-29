//bloque1
int led = 13;
int led2 = 12;
int led3 = 11;
int led4 = 10;
int boton = 2;
int contador=0;
int estadoAnterior = 0;

//bloque2
int led5 = 20;
int led6 = 19;
int led7 = 18;
int led8 = 17;
int boton2 = 16;
int contador2=0;
int estadoAnterior2 = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  //bloque1
  pinMode(led,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(boton,INPUT);

    //bloque1
  pinMode(led5,OUTPUT);
  pinMode(led6,OUTPUT);
  pinMode(led7,OUTPUT);
  pinMode(led8,OUTPUT);
  pinMode(boton2,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  loop1();
  loop2();
}

void loop1() {
  // bloque1
  int lectura = digitalRead(boton);
  if(lectura!=estadoAnterior){
    if(lectura==HIGH)
    {
      contador++;
      Serial.println(contador);
    }
  }
  estadoAnterior=lectura;

  if(contador==1)
  {
    digitalWrite(led,HIGH);
    
  }
  if(contador==2)
  {
    digitalWrite(led,LOW);
    digitalWrite(led2,HIGH);
    //contador=0;
  }

    if(contador==3)
  {
    digitalWrite(led3,HIGH);
    digitalWrite(led2,LOW);
    
  }

    if(contador==4)
  {
    digitalWrite(led3,LOW);
    digitalWrite(led4,HIGH);
    
  }

    if(contador==5)
  {
    digitalWrite(led,HIGH);
    digitalWrite(led4,LOW);
    
  }

      if(contador==6)
  {
    digitalWrite(led,LOW);
    digitalWrite(led4,LOW);
    contador=0;
  }
}

void loop2() {
  // bloque2
  int lectura2 = digitalRead(boton2);
  if(lectura2!=estadoAnterior2){
    if(lectura2==HIGH)
    {
      contador2++;
      Serial.println(contador2);
    }
  }
  estadoAnterior2=lectura2;

  if(contador2==1)
  {
    digitalWrite(led5,HIGH);
    
  }
  if(contador2==2)
  {
    digitalWrite(led5,LOW);
    digitalWrite(led6,HIGH);
    //contador=0;
  }

    if(contador2==3)
  {
    digitalWrite(led7,HIGH);
    digitalWrite(led6,LOW);
    
  }

    if(contador2==4)
  {
    digitalWrite(led7,LOW);
    digitalWrite(led8,HIGH);
    
  }

    if(contador2==5)
  {
    digitalWrite(led5,HIGH);
    digitalWrite(led8,LOW);
    
  }

      if(contador2==6)
  {
    digitalWrite(led5,LOW);
    digitalWrite(led8,LOW);
    contador2=0;
  }
}
