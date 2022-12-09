int distancia1= 2;  
int distancia2= 3;
int distancia3 = 4;
int presion_E = 5;
int presion_PI = 6;
int presion_PD = 7;
int presion_EB = 9;
int alarma = 8;

char uno = 'A';
char dos = 'B';
char tres = 'C';
char cuatro = 'D';
char cinco = 'E';
char seis = 'F';
char siete = 'G';

void setup() 
{
  
pinMode(distancia1,INPUT);
pinMode(distancia2,INPUT);
pinMode(distancia3,INPUT);
pinMode(presion_E, INPUT);
pinMode(presion_PI, INPUT);
pinMode(presion_PD, INPUT);
pinMode(presion_EB, INPUT);

pinMode(alarma, OUTPUT);

Serial.begin(9600);

digitalWrite(alarma, HIGH);
delay(80);
digitalWrite(alarma, LOW);

//Bienvenido
Serial.write(uno);

}  

void loop() 
{
  
int valor1 = 0;
int valor2 = 0;
int valor3 = 0;
int valor_E = 0;
int valor_PI = 0;
int valor_PD = 0;
int valor_EB = 0;

valor_PI = digitalRead(presion_PI);
valor_PD = digitalRead(presion_PD);
  
  digitalWrite(alarma, LOW);

  valor_PI = digitalRead(presion_PI);
  valor_PD = digitalRead(presion_PD);

  valor1 = digitalRead(distancia1);
  valor2 = digitalRead(distancia2);
  valor3 = digitalRead(distancia3);
  valor_E = digitalRead(presion_E);
  valor_EB = digitalRead(presion_EB);
  
  if(Serial.read() == 'Z') // Esto se puede quitar ya que los mismos sensores de distancia, apagan la alarma
  {
    digitalWrite(alarma, LOW);
  }
  
 if(valor1 == LOW && valor2 == LOW && valor3 == LOW) //&& valor_E == LOW && valor_EB == LOW) //Primera mala postura
  { 
    digitalWrite(alarma, HIGH);
    Serial.write(dos);
  }
  else if (valor1 == HIGH && valor2 == HIGH && valor3 == LOW) //&& valor_EB == LOW ) //Segunda mala postura
  {
    digitalWrite(alarma, HIGH);
    Serial.write(tres);
  }
  else if (valor1 == LOW && valor2 == LOW && valor3== HIGH) //&& valor_E == LOW && valor_EB == HIGH ) //Tercera mala postura
  {
    digitalWrite(alarma, HIGH);
    Serial.write(cuatro);
  }
  else if (valor1 == HIGH && valor2 == HIGH && valor3== HIGH) //&& valor_E == HIGH && valor_EB == HIGH) //Postura correcta
  {
    digitalWrite(alarma, LOW);
    Serial.write(cinco);
  }
  else //Otra mala postura
  {
    digitalWrite(alarma, HIGH);
    Serial.write(seis);
  }

delay(800);

////No hay nadie sentado
//digitalWrite(alarma, LOW);
//Serial.write(siete);

delay(800);

}
