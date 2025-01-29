// Pines de los LEDs
const int ledRojo = 1;
const int ledAmarillo = 2;
const int ledVerde = 3;

// Pines del buzzer
const int buzzer = 5;

// Pines del pulsador
const int pulsador = 4;

// Pines del display de 7 segmentos
const int segA = 7;
const int segB = 6;
const int segC = 12;
const int segD = 10;
const int segE = 11;
const int segF = 9;
const int segG = 8;
const int segDP = 13; // Punto decimal (opcional)

// Segmentos para números del display (ánodo común)
const byte numeros[10][8] = {
  {HIGH, HIGH, HIGH, HIGH, HIGH, LOW, HIGH, LOW}, // 0
  {LOW, HIGH, HIGH, LOW, LOW, LOW, LOW, LOW},    // 1
  {HIGH, HIGH, LOW, HIGH, HIGH, HIGH, LOW, LOW}, // 2
  {HIGH, HIGH, HIGH, HIGH, LOW, HIGH, LOW, LOW}, // 3
  {LOW, HIGH, HIGH, LOW, LOW, HIGH, HIGH, LOW},  // 4
  {HIGH, LOW, HIGH, HIGH, LOW, HIGH, HIGH, LOW}, // 5
  {HIGH, LOW, HIGH, HIGH, HIGH, HIGH, HIGH, LOW},// 6
  {HIGH, HIGH, HIGH, LOW, LOW, LOW, LOW, LOW},   // 7
  {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW},// 8
  {HIGH, HIGH, HIGH, HIGH, LOW, HIGH, HIGH, LOW} // 9
};


// Variable para el pulsador
bool botonPresionado = false;

// Función para mostrar un número en el display
void mostrarNumero(int numero) {
  if (numero > 9) {     // Apagar display si el número es mayor a 9
    digitalWrite(segA, LOW);
    digitalWrite(segB, LOW);
    digitalWrite(segC, LOW);
    digitalWrite(segD, LOW);
    digitalWrite(segE, LOW);
    digitalWrite(segF, LOW);
    digitalWrite(segG, LOW);
    digitalWrite(segDP, LOW);
  } else {              // Mostrar número en el display
    digitalWrite(segA, numeros[numero][0]);
    digitalWrite(segB, numeros[numero][1]);
    digitalWrite(segC, numeros[numero][2]);
    digitalWrite(segD, numeros[numero][3]);
    digitalWrite(segE, numeros[numero][4]);
    digitalWrite(segF, numeros[numero][5]);
    digitalWrite(segG, numeros[numero][6]);
    digitalWrite(segDP, numeros[numero][7]);
  }
}

// Función para realizar la cuenta regresiva en el display
void cuentaRegresiva(int segundos) {
  for (int i = segundos; i >= 0; i--) {
    mostrarNumero(i);   // Mostrar el número en el display
    delay(1000);        // Esperar un segundo
  }
  mostrarNumero(10);    // Apagar el display
}

void setup() {
  // Configuración de pines para LEDs
  pinMode(ledRojo, OUTPUT);
  pinMode(ledAmarillo, OUTPUT);
  pinMode(ledVerde, OUTPUT);

  // Configuración del buzzer
  pinMode(buzzer, OUTPUT);

  // Configuración del pulsador
  pinMode(pulsador, INPUT_PULLUP);

  // Configuración de pines del display
  pinMode(segA, OUTPUT);
  pinMode(segB, OUTPUT);
  pinMode(segC, OUTPUT);
  pinMode(segD, OUTPUT);
  pinMode(segE, OUTPUT);
  pinMode(segF, OUTPUT);
  pinMode(segG, OUTPUT);
  pinMode(segDP, OUTPUT);

  // Estado inicial
  digitalWrite(ledRojo, HIGH); // Inicia en rojo
  mostrarNumero(10);           // Apagar el display
}

void loop() {
  // Leer el estado del pulsador
  if (digitalRead(pulsador) == LOW && !botonPresionado) {
    botonPresionado = true; // Activar el semáforo solo al presionar el botón
  }

  if (botonPresionado) {
    // Ciclo del semáforo
    // Verde
    digitalWrite(ledRojo, LOW);
    digitalWrite(ledVerde, HIGH);
    tone(buzzer, 1000, 500); // Sonido al cambiar al verde
    cuentaRegresiva(5);
    noTone(buzzer);          // Detener sonido

    // Amarillo
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarillo, HIGH);
    tone(buzzer, 500, 500);  // Sonido al cambiar al amarillo
    cuentaRegresiva(2);
    noTone(buzzer);          // Detener sonido

    // Rojo
    digitalWrite(ledAmarillo, LOW);
    digitalWrite(ledRojo, HIGH);
    tone(buzzer, 1500, 500); // Sonido al cambiar al rojo
    cuentaRegresiva(5);
    noTone(buzzer);          // Detener sonido

    botonPresionado = false; // Reiniciar estado del botón
  }
}
