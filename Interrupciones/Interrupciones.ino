#include <MsTimer2.h>

#define ledPin 13

int ON;

void setup(){
  //Asocia un puerto de entrada de Interrupción con una función
  //attachInterrupt(0,interrupcion1,CHANGE);
  int ON = 0;
  pinMode(ledPin, OUTPUT);
  MsTimer2::set(500,interrupcion1);
  
}

void loop(){
  if(ON == 0) {
    MsTimer2::start();
    ON = 1;
  }
  else {
    
  }
}

void interrupcion1() {
  int estado = digitalRead(ledPin);
  if(estado == HIGH) {
    digitalWrite(ledPin, LOW);
  }
  else {
    digitalWrite(ledPin, HIGH);
  }
}
