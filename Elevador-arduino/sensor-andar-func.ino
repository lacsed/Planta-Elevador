#define S1 A0
#define S2 A1
#define S3 A2
#define S4 A3

bool andarAtual[5] = { false, false, false, false, false }; // [0]=1º andar, ..., [3]=4º andar

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
  if (analogRead(sensor)> 800){
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
  return 0;
}