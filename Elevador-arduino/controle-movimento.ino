int decidirMovimento() { //subir 0 , descer 1, nada,parar 2
  int andar = -1;
  for (int i = 0; i < 4; i++) {
    if (andarAtual[i]) {
      andar = i;
      break;
    }
  }

  if (andar == -1) {
    Serial.println("Elevador: posição desconhecida.");
    return;
  }

  // Verificar chamadas acima
  bool temChamadaAcima = false;
  for (int i = andar + 1; i < 4; i++) {
    if (andarInterno[i]) {
      temChamadaAcima = true;
      break;
    }
    if (i < 3 && subir[i]) {
      temChamadaAcima = true;
      break;
    }
    if (i > 0 && descer[i - 1]) {
      temChamadaAcima = true;
      break;
    }
  }

  // Verificar chamadas abaixo
  bool temChamadaAbaixo = false;
  for (int i = andar - 1; i >= 0; i--) {
    if (andarInterno[i]) {
      temChamadaAbaixo = true;
      break;
    }
    if (i < 3 && subir[i]) {
      temChamadaAbaixo = true;
      break;
    }
    if (i > 0 && descer[i - 1]) {
      temChamadaAbaixo = true;
      break;
    }
  }

  if (temChamadaAcima) {
    Serial.println("Elevador deve SUBIR");
    return 0;
  } else if (temChamadaAbaixo) {
    Serial.println("Elevador deve DESCER");
    return 1;
  } else {
    Serial.println("Elevador deve PARAR");
    return 2;
  }
}

bool pararNoAndarAtual() { // true , false 
  int andar = -1;

  // Descobre em que andar está
  for (int i = 0; i <= 4; i++) {
    if (andarAtual[i]) {
      andar = i;
      break;
    }
  }

  if (andar == -1) {
    Serial.println("Posição do elevador desconhecida.");
    return;
  }

  bool chamada = false;

  // Verifica chamada no painel interno
  if (andarInterno[andar]) chamada = true;

  // Verifica chamada de subida (se não for o 4º andar)
  if (andar < 4 && subir[andar]) chamada = true;

  // Verifica chamada de descida (se não for o 1º andar)
  if (andar > 1 && descer[andar - 1]) chamada = true;

  // Resposta
  if (chamada) {
    Serial.print("Parar no andar ");
    Serial.print(andar);
    Serial.println(" para atender chamada.");
    return true;
  } else {
    Serial.print("Nenhuma chamada no andar ");
    Serial.print(andar);
    Serial.println(". Continuar movimento.");
    return false;
  }
}
