#include "include/controle-movimento.h"
#include "include/globals.h"
#include "include/sensores.h"

enum Movimento {
  SUBIR = 0,
  DESCER = 1,
  PARAR = 2,
  ERRO = -1
};

// indica a direção atual do elevador
extern bool subindo; // true: subindo, false: descendo 

extern bool abrirPorta; // true: subindo, false: descendo 

int decidirMovimento() {
  int andarAtualElevador = 0;
  
  //Serial.print("[");
  for (int i = 1; i <= 4; i++) {
    //Serial.print((andarInterno[i] || subir[i] || descer[i]));

    if(andarAtual[i]){
      andarAtualElevador = i;
    }
  }
  //Serial.println("]");

  if (andarAtualElevador == 0) {
    //Serial.println("Elevador: posição desconhecida.");
    return ERRO;
  }

  // Verificar chamadas acima
  bool temChamadaAcima = false;
  for (int i = andarAtualElevador + 1; i <= 4; i++) {
    if (andarInterno[i] || subir[i] || descer[i]) {
      temChamadaAcima = true;
      break;
    }
  }

  // Verificar chamadas abaixo
  bool temChamadaAbaixo = false;
  for (int i = andarAtualElevador - 1; i >= 1; i--) {
    if (andarInterno[i] || subir[i] || descer[i]) {
      temChamadaAbaixo = true;
      break;
    }
  }

  // Decisão baseada nas chamadas e direção atual
  if (temChamadaAcima && temChamadaAbaixo) {
    //Serial.print("Chamadas em ambas as direções. Continuar subindo? ");
    //Serial.println(subindo ? "SIM" : "NÃO");
    return subindo ? SUBIR : DESCER;
  } else if (temChamadaAcima) {
    //Serial.println("Elevador deve SUBIR");
    return SUBIR;
  } else if (temChamadaAbaixo) {
    //Serial.println("Elevador deve DESCER");
    return DESCER;
  } else {
    //Serial.println("Elevador deve PARAR");
    return PARAR;
  }
}

bool pararNoAndarAtual() { // true , false

  // Descobre em que andar está
  int andarAtualElevador = verificarAndarAtual();

  if (andarAtualElevador == 0) {
   // Serial.Println("Posição do elevador desconhecida.");
    return false;
  }

  bool chamada = false;

  // Verifica chamada no painel interno
  if (andarInterno[andarAtualElevador]) chamada = true;

  if(subindo){
    // Verifica chamada de subida, se tiver, para
    if (subir[andarAtualElevador]) chamada = true;
  }
  else{
    // Verifica chamada de descida (se não for o 1º andar)
    if (descer[andarAtualElevador]) chamada = true;
  }

  if(decidirMovimento() == 2){
    //Serial.println(" to parado nesse andar pq nao tem nenhuma chamada ativa ");
    if (subir[andarAtualElevador] || descer[andarAtualElevador] ) chamada = true;
  }
    // Resposta
    if (chamada) {
        //Serial.println("Parar no andar para atender a chamada ");
        // Serial.Print(andarAtualElevador);
        // Serial.Println(" para atender chamada.");
        return true;
    } else {
        // Serial.Print("Nenhuma chamada no andar ");
        // Serial.Print(andarAtualElevador);
        // Serial.Println(". Continuar movimento.");
        return false;
    }
}
