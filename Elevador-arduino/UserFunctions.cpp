#include "Automaton.h"

void setupPin()
{
}

// This function will be called every Arduino loop, put here something that you want to repeat always
void doEveryLoop(){
/*
    Example of reading events through the Serial port

    if (!Serial.available())
    {
        return;
    }

    String input = Serial.readStringUntil('\n');
    input.trim();

    int actualEvent = input.toInt();

*/
}

// This set of functions should be implemented in a way to handle the controllable events of the system
bool EventControllable_subir(){
	return false;
}

bool EventControllable_parar(){
	return false;
}

bool EventControllable_descer(){
	return false;
}

bool EventControllable_abrir_porta(){
	return false;
}




// This set of functions should be implemented in a way to handle the uncontrollable events of the system
bool EventUncontrollable_s_1(){
  return leitordeSensor(S1);
}

bool EventUncontrollable_s_2(){
  return leitordeSensor(S2);
}

bool EventUncontrollable_s_3(){
  return leitordeSensor(S3);
}

bool EventUncontrollable_s_4(){
  return leitordeSensor(S4);
}

bool EventUncontrollable_fechar_porta(){
{
  // Se o contador ainda não foi iniciado, não deve fechar a porta
  if (portaAbertaTimerStart == 0) {
	return false;
}

  // Calcula o tempo decorrido
  unsigned long tempoDecorrido = millis() - portaAbertaTimerStart;

  // Verifica se passou de 10 segundos
  if (tempoDecorrido > 10000) {
    return true;
  } else {
    return false;
  }
}

// Here the expected actions should be implemented in each state of the system 
void StateActionAutomaton0_MotorState0()
{
	Serial.println("A0S0");
 	delay(500);
}

void StateActionAutomaton0_MotorState1()
{
	Serial.println("A0S1");
 	delay(500);
}

void StateActionAutomaton0_MotorState2()
{
	Serial.println("A0S2");
 	delay(500);
}

void StateActionAutomaton1_AndaresState0()
{
	Serial.println("A1S0");
 	delay(500);
}

void StateActionAutomaton1_AndaresState1()
{
	Serial.println("A1S1");
 	delay(500);
}

void StateActionAutomaton1_AndaresState2()
{
	Serial.println("A1S2");
 	delay(500);
}

void StateActionAutomaton1_AndaresState3()
{
	Serial.println("A1S3");
 	delay(500);
}

void StateActionAutomaton2_PortaState0()
{
	Serial.println("A2S0");
 	delay(500);
}

void StateActionAutomaton2_PortaState1()
{
	Serial.println("A2S1");
 	delay(500);
}

