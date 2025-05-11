#ifndef DISPLAY_H
#define DISPLAY_H

//Número a ser aceso no Display: 
// 1: posições que precisam ser acesas para formar o número desejado. 
// 0: a posição ocupada por esse segmento é apagada.
char displayLed[5]{B00000000,//Apagado
                  B00110000,//1
                  B01101101,//2
                  B01111001,//3
                  B00110011//4
                 };


void desligaDisplay();

void ligarDisplay(int num);

#endif
