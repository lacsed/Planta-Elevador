#include "include/globals.h"
#include "include/leds.h"
#include "include/latch-74HC595.h"


//ligar determinado led
void ligarLed(int led){
 int ci = led/10; //divide o valor definido para descobrir o número do CI.
 int bitled = led - ci*10; //a posição do pino que esse led está localizado.
 _LED[ci-1] = _LED[ci-1]|(1<<bitled);//a sequencia de um vetor[3], varia de 0 a 2, logo será subtraído 1 do valor de ci calculado p/ que ele se encaixe com o vetor.

  atualizaSaida();
}

void desligarLedsDoAndar(int andar){
  if(andar = 1){
    desligarLed(LED_PI_1);
    desligarLed(LED_P1_SOBE);
  }
  if(andar = 2){
    desligarLed(LED_PI_2);
    desligarLed(LED_P2_SOBE);
    desligarLed(LED_P2_DESCE);    
  }
  if(andar = 3){
    desligarLed(LED_PI_3);
    desligarLed(LED_P3_SOBE);
    desligarLed(LED_P3_DESCE); 
  }
  if(andar = 4){
    desligarLed(LED_PI_4);
    desligarLed(LED_P4_DESCE);    
  }
}

//desligar determinado led
void desligarLed(int led){
  int ci = led/10;
  int bitled = led - ci*10;
  _LED[ci-1] = _LED[ci-1]&~(1<<bitled);

  atualizaSaida();
}