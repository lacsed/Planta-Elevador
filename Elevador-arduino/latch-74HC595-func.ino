void atualizaSaida(){
  digitalWrite(STCP_pin, LOW);
  shiftOut(DS_pin, SHCP_pin, MSBFIRST, _LED[2]);
  shiftOut(DS_pin, SHCP_pin, MSBFIRST, _LED[1]);
  shiftOut(DS_pin, SHCP_pin, MSBFIRST, _LED[0]);
  //return the latch pin high to signal chip that it
  //no longer needs to listen for information
  digitalWrite(STCP_pin, HIGH);//criar funcao com isso aq pra ligar os leds, ao inevs de aux LED 0 LED 1 E LED 2
}

void setupLatch(){
  pinMode(STCP_pin, OUTPUT);
  pinMode(SHCP_pin, OUTPUT);
  pinMode(DS_pin, OUTPUT);

  atualizaSaida(); // Aplica o estado inicial (todos apagados)
}