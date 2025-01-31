#include "pitches.h" // Librería para definir las frecuencias de las notas

const int sensorPin = 9;  // Pin del sensor FC-51
const int ledRojo = 12;   // Pin del LED rojo
const int ledVerde = 13;  // Pin del LED verde
const int buzzerPin = 8;  // Pin del buzzer

// Notas de La Pantera Rosa (tema principal)
int melody[] = {
    NOTE_DS4, 0, NOTE_E4, NOTE_F4, 0, NOTE_G4, 0, NOTE_DS4,
    0, NOTE_E4, NOTE_F4, 0, NOTE_G4, 0, NOTE_C5, 0,
    NOTE_B4, 0, NOTE_E4, NOTE_G4, NOTE_B4, NOTE_AS4, 0, NOTE_A4,
    0, NOTE_G4, NOTE_E4, NOTE_D4, 0
};

// Duraciones correspondientes (4 = negra, 8 = corchea, etc.)
int noteDurations[] = {
    8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 2
};

void setup() {
  Serial.begin(9600);          // Iniciar comunicación serial
  pinMode(sensorPin, INPUT);   // Configurar sensor como entrada
  pinMode(ledRojo, OUTPUT);    // Configurar LED rojo como salida
  pinMode(ledVerde, OUTPUT);   // Configurar LED verde como salida
  pinMode(buzzerPin, OUTPUT);  // Configurar buzzer como salida
}

void playMelody() {
  // Reproducir La Pantera Rosa
  for (int thisNote = 0; thisNote < sizeof(melody)/sizeof(melody[0]); thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(buzzerPin, melody[thisNote], noteDuration);
    delay(noteDuration * 1.30);  // Pausa entre notas
    noTone(buzzerPin);           // Apagar el buzzer entre notas
  }
}

void loop() {
  int sensorValue = digitalRead(sensorPin);  // Leer valor del sensor

  // Si el sensor detecta luz reflejada (objeto detectado):
  if (sensorValue == HIGH) {
    Serial.println("Objeto detectado (Color claro)");
    digitalWrite(ledVerde, HIGH);  // Encender LED verde
    digitalWrite(ledRojo, LOW);    // Apagar LED rojo
  }
  // Si no hay objeto detectado:
  else {
    Serial.println("No se detectó objeto (Color oscuro)");
    digitalWrite(ledVerde, LOW);   // Apagar LED verde
    digitalWrite(ledRojo, HIGH);   // Encender LED rojo
    playMelody();                  // Reproducir la melodía
  }

  delay(500);  // Pequeño retardo para estabilidad
}