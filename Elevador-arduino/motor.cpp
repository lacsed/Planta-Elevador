#include "include/motor.h"
#include "include/globals.h"
#include "include/sensors.h"

void setupMotor(){
    pinMode(N1, OUTPUT);
    pinMode(N2, OUTPUT);
    while(verificarAndarAtual() != 1){
      ligarMotor(1);
    }
    pararMotor();
}
//parar o motor:
void pararMotor(){
  digitalWrite(N1, HIGH);
  digitalWrite(N2, HIGH);
}

void ligarMotor(int num){ //0 subir ,  1 descer

  if(num){
      digitalWrite(N1, HIGH);//sentido horario
      digitalWrite(N2, LOW);
  }else{
      digitalWrite(N1, LOW);
      digitalWrite(N2, HIGH);//girar no sentido anti-horario
  }
}
