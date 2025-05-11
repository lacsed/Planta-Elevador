#include <Arduino.h>
#include "latch-74HC595.h"
#include "display7seg.h"
#include "globals.h"

char displayLed[5]{B00000000,//Apagado
                  B00110000,//1
                  B01101101,//2
                  B01111001,//3
                  B00110011//4
                 };

//ACENDER O DISPLAY:

//desligar o display: 
void desligaDisplay(){
  _LED[1] = _LED[1]&~(B00000110);
  _LED[2] = _LED[2]&~(B11111000);
}

void ligarDisplay(int num){

  desligaDisplay();

  /* devido a funcao MSBFIRST os numeros precisaram ter suas posições declaradas ao contrário, logo a posição A que está em B01000000, 
  deverá ter a sua posição invertida, sendo a sua posição referente ao pino do CI.
  A lógica é: comparação entre o valor na string displayLed referente ao número escolhido[1,2,3,4] e o seu posicionamento com o CI e a posição do seu 
  pino tendo como referencia para o deslocamento a sua posição invertida.
  */

  char bitA = (displayLed[num] & B01000000);//posição do vetor comparada com o valor do segmento A do display.
  _LED[1] = _LED[1]|(bitA >> 4);//CI em que esse segmento está posicionado e quantas casas serão deslocadas para atingir o valor final. //=B00000100(valor final)
  char bitB = (displayLed[num] & B00100000);
  _LED[1] = _LED[1]|(bitB >> 4);//=B00000010
  char bitC = (displayLed[num] & B00010000);
  _LED[2] = _LED[2]|(bitC << 2);//=B01000000
  char bitD = (displayLed[num] & B00001000);
  _LED[2] = _LED[2]|(bitD << 4);//=B10000000
  char bitE = (displayLed[num] & B00000100);
  _LED[2] = _LED[2]|(bitE << 2);//=B00010000
  char bitF = (displayLed[num] & B00000010);
  _LED[2] = _LED[2]|(bitF << 4);//=B00100000
  char bitG = (displayLed[num] & B00000001);
  _LED[2] = _LED[2]|(bitG << 3);//=B00001000
  
  
  atualizaSaida();
}