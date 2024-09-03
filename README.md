# semaforo_fotosensor_arduino_
Neste LVP você deve evoluir o código do projeto disponível no Exemplo do Semáforo - C++, no ThinkerCad, com Arduino.   (1) O cenário que deve ser adicionado é o seguinte:  "Ao cair da noite, os semáforos passam para o modo noturno, que consiste em acender continuamente o sinal de Atenção por 2 segundos, apagando por 1 segundo.

# Observações:

Para implementar um semáforo que entra no modo noturno ao cair da noite, você precisará de um sensor de luz para detectar a ausência de luz suficiente. Um sensor apropriado para essa tarefa é o fotossensor (também conhecido como LDR - Light Dependent Resistor ou fotocélula). Vou te mostrar como você pode integrar um sensor de luz ao seu projeto e implementar o modo noturno em C++.

# Componentes necessários:

- Fotossensor (LDR): Para detectar a quantidade de luz.
- Resistor: Para criar um divisor de tensão com o LDR.
- Microcontrolador ou placa Arduino: Para ler o valor do sensor e controlar o semáforo.

# Esquema básico:

- LDR e resistor formam um divisor de tensão.
- A saída do divisor de tensão é conectada a uma entrada analógica do microcontrolador.
- O microcontrolador lê o valor do sensor e decide se o semáforo deve estar em modo noturno ou normal.
