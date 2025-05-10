  // Definições dos pinos
//PAINEL-INTERNO
#define B1 23 //BOTAO 1 ANDAR
#define B2 22 //BOTAO 2 ANDAR
#define B3 25 //BOTAO 3 ANDAR
#define B4 24 //BOTAO 4 ANDAR

//PAINEL 1º andar
#define B1_PAINEL 27 //(subir
//PAINEL 2º andar
#define B2d_PAINEL 26 //(subir
#define B2s_PAINEL 29 //(descer
//PAINEL 3º andar
#define B3d_PAINEL 31 //(descer
#define B3s_PAINEL 33 //(subir
//PAINEL 4º andar
#define B4_PAINEL 28 //(descer

// Arrays de marcação
bool andarInterno[5] = { false, false, false, false, false };  // [1] = 1º andar, ..., [4] = 4º andar
bool subir[5] = { false, false, false, false, false };                // [1] = subir do 1º, [2] = subir do 2º, [3] = subir do 3º
bool descer[5] = { false, false, false, false , false};        // [4] = descer do 4º, [3] = descer do 3º, [2] = descer do 2º


void setupBotoes(){
  //BOTÕES PAINEL INTERNO:
  pinMode(B1, INPUT);
  pinMode(B2, INPUT);
  pinMode(B3, INPUT);
  pinMode(B4, INPUT);
  
  //BOTÕES PAINEL ANDARES (SUBIR E DESCER): 
  pinMode(B1_PAINEL,INPUT); 
  pinMode(B2s_PAINEL,INPUT); 
  pinMode(B2d_PAINEL,INPUT); 
  pinMode(B3s_PAINEL,INPUT); 
  pinMode(B3d_PAINEL,INPUT); 
  pinMode(B4_PAINEL,INPUT); 
}

void lerBotoes(){
  // Leitura dos botões do painel interno
  if (digitalRead(B1) == HIGH) andarInterno[1] = true;
  if (digitalRead(B2) == HIGH) andarInterno[2] = true;
  if (digitalRead(B3) == HIGH) andarInterno[3] = true;
  if (digitalRead(B4) == HIGH) andarInterno[4] = true;

  // Leitura dos botões de subir
  if (digitalRead(B1_PAINEL) == HIGH) subir[1] = true;       // subir do 1º
  if (digitalRead(B2s_PAINEL) == HIGH) subir[2] = true;      // subir do 2º
  if (digitalRead(B3s_PAINEL) == HIGH) subir[3] = true;      // subir do 3º

  // Leitura dos botões de descer
  if (digitalRead(B4_PAINEL) == HIGH) descer[4] = true;      // descer do 4º
  if (digitalRead(B3d_PAINEL) == HIGH) descer[3] = true;     // descer do 3º
  if (digitalRead(B2d_PAINEL) == HIGH) descer[2] = true;     // descer do 2º

}

void desmarcarChamadaAndar(int andar){
  //acabei de chegar nesse andar, nao preciso mais atender ele
  andarInterno[andar] = false;
  subir[andar] = false;
  descer[andar] = false;

}