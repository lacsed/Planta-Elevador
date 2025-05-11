#include "Automaton.h"
#include "motor.h"


//leds
int STCP_pin = 32;
int SHCP_pin = 30;
int DS_pin = 34;
byte _LED[3] = {0x00, 0x00, 0x00}; // todos os LEDs desligados

#define BUZZER_PIN 7  // ou qualquer pino que você esteja usando

unsigned long portaAbertaTimerStart = 0; // 0 indica "ainda não iniciado"

void setupPin()
{
  setupLatch(); 
  setupBotoes(); 
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);
}

// This function will be called every Arduino loop, put here something that you want to repeat always
void doEveryLoop(){ //--------------- TODO
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
bool EventControllable_subir(){ //--------------- TODO
	return false;
}

bool EventControllable_parar(){
	return pararNoAndarAtual();
}

bool EventControllable_descer(){ //--------------- TODO
	return false;
}

bool EventControllable_abrir_porta(){ //--------------- TODO
  // quando chega no andar solicitado eu tenho que abrir a porta 
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
void StateActionAutomaton0_MotorState0() //parado
{
  pararMotor();
  int andar = verificarAndarAtual();
  desmarcarChamadaAndar(andar);
	Serial.println("A0S0: Parado");
 	delay(500);
}

void StateActionAutomaton0_MotorState1() //subindo
{
  ligarMotor(0);
	Serial.println("A0S1: Subindo");
 	delay(500);
}

void StateActionAutomaton0_MotorState2() // descendo 
{
  ligarMotor(1);
	Serial.println("A0S2: Descendo");
 	delay(500);
}

void StateActionAutomaton1_AndaresState0() //Andar 1
{
  ligarDisplay(1);
	Serial.println("A1S0");
 	delay(500);
}

void StateActionAutomaton1_AndaresState1() //Andar 2
{
  ligarDisplay(2);
	Serial.println("A1S1");
 	delay(500);
}

void StateActionAutomaton1_AndaresState2() //Andar 3
{
  ligarDisplay(3);
	Serial.println("A1S2");
 	delay(500);
}

void StateActionAutomaton1_AndaresState3() //Andar 4
{
  ligarDisplay(4);
	Serial.println("A1S3");
 	delay(500);
}

void StateActionAutomaton2_PortaState0() // Porta fechada --------------- TOFIX pins leds da porta
{ 
   if (portaAbertaTimerStart != 0) {
    digitalWrite(BUZZER_PIN, HIGH);
    delay(1000);  // duração do bipe
    portaAbertaTimerStart = 0;
    // Apagar LED de porta aberta
    digitalWrite(LED_PORTA_ABERTA, LOW);
  }  

  // Acender LED de porta fechada
  digitalWrite(LED_PORTA_FECHADA, HIGH);

	Serial.println("A2S0");
 	delay(500);
}

void StateActionAutomaton2_PortaState1() //porta aberta --------------- TOFIX pins leds da porta
{
  // Inicia contador se ainda não tiver sido iniciado
  if (portaAbertaTimerStart == 0) {
    portaAbertaTimerStart = millis();

    // Apagar LED de porta fechada
    digitalWrite(LED_PORTA_FECHADA, LOW);
    Serial.println("Contador de porta aberta iniciado.");
  }
  
  // Acender LED de porta aberta
  digitalWrite(LED_PORTA_ABERTA, HIGH);

	Serial.println("A2S1");
 	delay(500);
}

