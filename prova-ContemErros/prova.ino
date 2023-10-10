#include <Servo.h>
#include <Ultrasonic.h>
#define reset 13
#define grande 12
#define pequena 11
#define emergencia 10
#define led 7

int est = 1;
int aux;
int cp = 0;
int cg = 0;
int ct;

Ultrasonic ultrasonic(9, 8);
int distance;

Servo se;
Servo sc;  

void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  pinMode(reset, INPUT_PULLUP);
  pinMode(grande, INPUT_PULLUP);
  pinMode(pequena, INPUT_PULLUP);
  pinMode(emergencia, INPUT_PULLUP);
  se.attach(3);
  sc.attach(5);
  se.write(0);
  sc.write(90);
  delay(1000);
}

void loop() {
  byte bte = digitalRead(emergencia);
  digitalWrite(led, LOW);
  if (bte == HIGH) {
    est = 1;
  }

      
  while (est == 1) {
  byte bte = digitalRead(emergencia);
  
  if (bte == LOW) {
    est = 0;
  }
  digitalWrite(led, HIGH);

  distance = ultrasonic.read();
  se.write(90);  
  distance = 45-distance;
  
  distance = ultrasonic.read();

  if (distance >=1 && distance <=15){
    sc.write(120);
      
    byte btp = digitalRead(pequena);
  
    if (btp == LOW) {
      Serial.println("Button is pressed");
      aux = 1;
      if (aux == 1){
      cp = cp+1;
      aux = 0;
      se.write(0);
      sc.write(90);
    }         
   }
  
  }
  if (distance>15 && distance<=30){
    sc.write(60);
    
    byte btg = digitalRead(grande);
    
    if (btg == LOW) {
      Serial.println("Button is pressed");
      aux = 1;
      if (aux == 1){
      cg = cp+1;
      aux = 0;
      se.write(0);
      sc.write(90);
    }         
   }
  }
  ct = cp+cg;
 Serial.println("------------");
 Serial.print("caixas armazenadas : ");
 Serial.println(ct);
 Serial.print("Caixas pequenas : ");
 Serial.println(cp);
 Serial.print("Caixas grandes : ");
 Serial.println(cg);
 Serial.println("------------");

  byte btr = digitalRead(reset);
  
  if (btr == LOW) {
      Serial.println("Button is pressed");
      cp = 0;
      cg = 0;
  }        

   Serial.println(distance);
   delay(500);     
  }
  
 
}
