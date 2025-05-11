#include "motor.h"

//PONTE H - MOTOR
#define N1 37
#define N2 35
//#define N3 5
//#define N4 6


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
