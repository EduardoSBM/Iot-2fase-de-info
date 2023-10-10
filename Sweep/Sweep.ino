#include <Servo.h>
Servo myservo;  
int poten = A0;
int valor;

void setup() {
  myservo.attach(10);  
  Serial.begin(9600);
}

void loop() {
  valor = analogRead(poten);
  valor = map(valor, 0, 1023, 0, 180);
 // valor = map(valor, 0, 1023, 90, 60);// para pequena
  //valor = map(valor, 0, 1023, 90, 120);//para grande
  myservo.write(valor); 
  Serial.println(valor);
  delay(15);
}
