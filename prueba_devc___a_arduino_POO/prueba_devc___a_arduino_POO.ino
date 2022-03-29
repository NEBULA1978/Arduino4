/*Ejercicio 1: Construya una clase llamada Rectangulo que tenga los siguientes
atributos: largo y ancho, y los siguientes metodos: perimetro() y area()*/
class rectangulo{
  private: //Atributos
    float largo,ancho;
  public: //Metodos
    rectangulo(float,float); //Constructor
    void perimetro();
    void area();
};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  rectangulo::perimetro();
  rectangulo::area();
}
void rectangulo::perimetro(){
  float _perimetro;
  
  _perimetro = (2*largo) + (2*ancho);
  
  Serial.println("El perimetro es: "_perimetro);
}

void rectangulo::area(){
  float _area;
  
  _area = largo * ancho;
  
  Serial.println("El area es: "_area);  
}

void loop() {
  // put your main code here, to run repeatedly:
  Rectangulo r1(11,7);//instanciar una clase es una copia objeto
  
  r1.perimetro();
  r1.area();
  
  system("pause");
  return 0;
}
