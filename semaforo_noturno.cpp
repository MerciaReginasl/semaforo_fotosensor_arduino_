// Definição dos pinos dos LEDs
const int ledVerde = 2;
const int ledAmarelo = 3;
const int ledVermelho = 4;

// Definição do pino do LDR
const int pinoLDR = A0;

// Limiares e tempos
const int limiarNoturno = 512; // Ajuste conforme necessário
const int intervaloVerde = 3000; // Tempo em ms para o LED verde
const int intervaloAmarelo = 1000; // Tempo em ms para o LED amarelo
const int intervaloVermelho = 3000; // Tempo em ms para o LED vermelho
const int intervaloNoturno = 2000; // Tempo em ms para o LED amarelo no modo noturno
const int intervaloDesligado = 1000; // Tempo em ms para o LED amarelo apagado no modo noturno

void setup() {
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int valorLDR = analogRead(pinoLDR);
  Serial.println(valorLDR); // Monitorar valor LDR no Serial Monitor

  if (valorLDR < limiarNoturno) {
    // Modo Noturno
    acenderModoNoturno();
  } else {
    // Modo Normal
    acenderModoNormal();
  }
}

void acenderModoNoturno() {
  unsigned long tempoAtual;
  unsigned long tempoAnterior = millis();

  while (true) {
    tempoAtual = millis();
    if (tempoAtual - tempoAnterior >= intervaloNoturno) {
      digitalWrite(ledAmarelo, HIGH); // Sinal de Atenção
      delay(intervaloNoturno); // 2 segundos
      digitalWrite(ledAmarelo, LOW);
      delay(intervaloDesligado); // 1 segundo
      tempoAnterior = tempoAtual; // Atualiza o tempo para o próximo ciclo
    }
  }
}

void acenderModoNormal() {
  digitalWrite(ledVerde, HIGH);  // Verde aceso
  delay(intervaloVerde);        // 3 segundos
  digitalWrite(ledVerde, LOW);   // Verde apagado

  digitalWrite(ledAmarelo, HIGH); // Amarelo aceso
  delay(intervaloAmarelo);        // 1 segundo
  digitalWrite(ledAmarelo, LOW);  // Amarelo apagado

  digitalWrite(ledVermelho, HIGH); // Vermelho aceso
  delay(intervaloVermelho);        // 3 segundos
  digitalWrite(ledVermelho, LOW);  // Vermelho apagado
}
