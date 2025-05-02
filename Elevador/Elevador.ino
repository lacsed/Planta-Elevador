

#include <Drive.h>
#include <Stepper.h>
#include <AccelStepper.h>

int STCP_pin = 32;
int SHCP_pin = 30;
int DS_pin = 34;

//PONTE H - MOTOR
#define N1 37
#define N2 35
//#define N3 5
//#define N4 6


void setup() {
  //MOTOR INTERNO E SENSORES
  
  pinMode(STCP_pin, OUTPUT);
  pinMode(SHCP_pin, OUTPUT);
  pinMode(DS_pin, OUTPUT);
}

void loop() {
  ligarDisplay(1);
  delay(2000);
  ligarDisplay(2);
  delay(2000);
  ligarDisplay(3);
  delay(2000);
  ligarDisplay(4);
  delay(2000);
}