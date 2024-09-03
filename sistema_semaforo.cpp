// Definição dos pinos
const int ldrPin = A0; // Pino analógico conectado ao LDR
const int redPin = 9;  // Pino digital conectado ao LED vermelho
const int yellowPin = 10; // Pino digital conectado ao LED amarelo
const int greenPin = 11; // Pino digital conectado ao LED verde

// Valores de limiar
const int threshold = 512; // Valor de limiar para luz (ajustar conforme necessidade)

// Intervalos de tempo
const unsigned long nightModeDuration = 2000; // 2 segundos
const unsigned long offDuration = 1000; // 1 segundo

// Variáveis de tempo
unsigned long previousMillis = 0;
bool nightMode = false;

void setup() {
  // Inicialização dos pinos
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  
  // Configuração inicial dos LEDs
  digitalWrite(redPin, LOW);
  digitalWrite(yellowPin, LOW);
  digitalWrite(greenPin, HIGH); // O semáforo inicia em verde
}

void loop() {
  int ldrValue = analogRead(ldrPin); // Leitura do valor do LDR
  
  // Verifica se está escuro o suficiente para entrar no modo noturno
  if (ldrValue < threshold) {
    nightMode = true;
  } else {
    nightMode = false;
  }

  unsigned long currentMillis = millis();

  if (nightMode) {
    // Modo Noturno: Atenção por 2 segundos, apagado por 1 segundo
    if (currentMillis - previousMillis >= (nightModeDuration + offDuration)) {
      previousMillis = currentMillis;
    } else if (currentMillis - previousMillis < nightModeDuration) {
      // Acende o LED de Atenção (Amarelo)
      digitalWrite(yellowPin, HIGH);
      digitalWrite(redPin, LOW);
      digitalWrite(greenPin, LOW);
    } else {
      // Apaga o LED de Atenção
      digitalWrite(yellowPin, LOW);
      digitalWrite(redPin, LOW);
      digitalWrite(greenPin, LOW);
    }
  } else {
    // Modo Normal
    digitalWrite(yellowPin, LOW);
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, HIGH); // Sinal verde contínuo no modo normal
  }
}
