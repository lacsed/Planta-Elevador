#include "globals.h"

bool andarAtual[5] = { false, false, false, false, false };
int STCP_pin = 32;
int SHCP_pin = 30;
int DS_pin = 34;
byte _LED[3] = {0x00, 0x00, 0x00};
bool andarInterno[5] = { false, false, false, false, false };
bool subir[5] = { false, false, false, false, false };
bool descer[5] = { false, false, false, false , false };
unsigned long portaAbertaTimerStart = 0;
