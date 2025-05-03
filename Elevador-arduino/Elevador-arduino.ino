//PONTE H - MOTOR
#define N1 37
#define N2 35
//#define N3 5
//#define N4 6

//Motor e leds
int STCP_pin = 32;
int SHCP_pin = 30;
int DS_pin = 34;
byte _LED[3] = {0x00, 0x00, 0x00}; // todos os LEDs desligados

void setup() {
  setupLatch();  
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