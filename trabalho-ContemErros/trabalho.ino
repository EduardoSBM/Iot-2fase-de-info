#include <Ultrasonic.h>
#include "DHT.h"

#define DHTPIN 2     
#define DHTTYPE DHT11

const int led_10 = 3;
const int led_20 = 5;
const int led_temp = 6;
const int led_eleV = 11;
const int led_saida = 10;

Ultrasonic pedrinho(12, 13); 
DHT joaozinho(DHTPIN, DHTTYPE);

void setup() {
  joaozinho.begin();
  
  pinMode(led_10,OUTPUT);
  pinMode(led_20,OUTPUT);
  pinMode(led_temp,OUTPUT);
  pinMode(led_eleV,OUTPUT);
  pinMode(led_saida,OUTPUT);
}

void loop() {
 float t = joaozinho.readTemperature();
 int distance = pedrinho.read();

  if ( distance >0){
    digitalWrite(led_eleV, HIGH);
  }
  else {
    digitalWrite(led_eleV, LOW);
  }
  if ( distance < 60 &&  t > 25 && t < 27){
    digitalWrite(led_saida, HIGH);
   }
  else {
    digitalWrite(led_saida, LOW);
  }
  if (t < 25 && distance > 90){
    digitalWrite(led_temp, HIGH);
  }
  else {
    digitalWrite(led_temp, LOW);
  }
  if (distance > 80){
    digitalWrite(led_20, HIGH);
  }
  else{
    digitalWrite(led_20, LOW);
    }
  if (distance > 90){
    digitalWrite(led_10, HIGH);
  }
  else{
    digitalWrite(led_10, LOW);
   }
}

  
