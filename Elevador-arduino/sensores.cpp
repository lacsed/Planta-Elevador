#include "include/globals.h"
#include "include/sensores.h"


void atualizarAndarAtual() {
  int andar = verificarAndarAtual(); // retorna 1 a 4

  // Zera todos os andares
  for (int i = 0; i < 4; i++) {
    andarAtual[i] = false;
  }

  // Marca o andar atual como true, se for válido
  if (andar >= 1 && andar <= 4) {
    andarAtual[andar] = true;
  }
}

bool leitordeSensor(int sensor){
  if (analogRead(sensor)> 500){
   return (true);
  } else {
   return(false);
  }
}

int verificarAndarAtual(){
  if(leitordeSensor(S1)){
    return 1;
  }
  if(leitordeSensor(S2)){
    return 2;
  }
  if(leitordeSensor(S3)){
    return 3;
  }
  if(leitordeSensor(S4)){
    return 4;
  }
  evento_andares=true;
  return 0;
}