# 🚧 Projeto Elevador de 4 Andares com Arduino Due

Este projeto implementa um elevador funcional de 4 andares utilizando a plataforma **Arduino Due**. O sistema possui botões para cada andar, LEDs indicadores, um motor para simular o movimento e um display de 7 segmentos que exibe o andar atual.

---

## 🔧 Componentes Utilizados

- Arduino Due
- 10x Botoes + - 10x LEDs indicadores de chamada
- 1x Motor DC 12V + parafuso 40cm
- Driver de motor L298N
- Display de 7 segmentos (com decodificador 74HC595)
- Resistores, jumpers, conectores
- Fonte externa 12

---

## 🧠 Lógica de Funcionamento

- O sistema aguarda chamadas de qualquer andar.
- O elevador se move até o andar solicitado, acendendo os LEDs e atualizando o display de 7 segmentos.
- Se múltiplos andares forem solicitados, as chamadas são atendidas em ordem de prioridade.
- O motor é controlado com base na diferença entre o andar atual e o solicitado.

---

## 📁 Estrutura do Repositório
elevador-arduino-due/
├── README.md
├── LICENSE
├── .gitignore
├── Elevador/
│   ├── elevador.ino
│   ├── display-func.ino
│   ├── motor-func.ino
│   └── botoes-func.ino
├── hardware/
│   ├── esquema_fritzing.fzz
│   └── arduino-due-pinout.png
├── libs/
│   └── biblioteca_display7seg/
├── docs/
│   ├── automato-planta-elevador.png
│   ├── automato-especificacoes-elevador.png
│   └── supervisor-elevador.png
└── test/
    └── simulador_logico.ino (ou testes básicos de botões)


