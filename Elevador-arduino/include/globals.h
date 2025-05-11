#ifndef GLOBALS_H
#define GLOBALS_H

#include <Arduino.h>

// Definições dos pinos
//PAINEL-INTERNO
#define B1 23 //BOTAO 1 ANDAR
#define B2 22 //BOTAO 2 ANDAR
#define B3 25 //BOTAO 3 ANDAR
#define B4 24 //BOTAO 4 ANDAR

//PAINEL 1º andar
#define B1_PAINEL 27 //subir
//PAINEL 2º andar
#define B2d_PAINEL 26 //subir
#define B2s_PAINEL 29 //descer
//PAINEL 3º andar
#define B3d_PAINEL 31 //descer
#define B3s_PAINEL 33 //subir
//PAINEL 4º andar
#define B4_PAINEL 28 //descer

//PAINEL-INTERNO
#define LED_PI_4 23 //valor do ci+bit
#define LED_PI_3 24// Numero composto por CI e Pino no CI, exemplo: CI=2 e PINO=Q4, LED=24;
#define LED_PI_2 25
#define LED_PI_1 26

// Painel dos Andares 
#define LED_P1_SOBE 27
#define LED_P2_DESCE 11
#define LED_P2_SOBE 12
#define LED_P3_DESCE 13
#define LED_P3_SOBE 14
#define LED_P4_DESCE 15

//led porta aberta
#define LED_PORTA_ABERTA 8
#define LED_PORTA_FECHADA 9

// TODO definir esse pino 
#define BUZZER_PIN 7  

//PONTE H - MOTOR
#define N1 37
#define N2 35
//#define N3 5
//#define N4 6

// sensor dos andares 
#define S1 A0
#define S2 A1
#define S3 A2
#define S4 A3

extern int STCP_pin;
extern int SHCP_pin;
extern int DS_pin;

//Número a ser aceso no Display: 
// 1: posições que precisam ser acesas para formar o número desejado. 
// 0: a posição ocupada por esse segmento é apagada.
extern char displayLed[5];
extern byte _LED[3];

//vetores de chamada dos botoes 
extern bool andarInterno[5];
extern bool subir[5];
extern bool descer[5];

//vetor para marcar andar atual mesmo se sair do sensor
extern bool andarAtual[5];
extern unsigned long portaAbertaTimerStart;

// indica a direção atual do elevador
extern bool subindo; // true: subindo, false: descendo 

// vai pra true quando parar a porta, para habilitar  o evento "abrir"
extern bool abrirPorta; 

#endif