#include <LiquidCrystal.h>

// Configuración del LCD
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Definición de pines
#define FAN_PIN 9
#define LCD_PIN 10
#define LED_COOLING 9
#define LED_COLD 7
#define LED_NORMAL 8
#define TEMP_PIN A1
#define MOTOR_PIN 6
#define PIEZO_PIN 10

// Definición de constantes
const int MAX_TEMP = 50;        // Temperatura máxima tolerada
const int MIN_TEMP = -10;       // Temperatura mínima tolerada
const int COLD_THRESHOLD = 15; // Umbral de temperatura fría
const int HOT_THRESHOLD = 26;  // Umbral de temperatura caliente

// Variables globales
float temp;                     // Variable para almacenar la temperatura
bool fanTurnedOn = false;       // Estado del ventilador
bool piezoSounded = false;      // Estado del piezo

void setup() {
  // Configuración inicial
  pinMode(FAN_PIN, OUTPUT);
  pinMode(LCD_PIN, OUTPUT);
  pinMode(MOTOR_PIN, OUTPUT);
  pinMode(LED_COOLING, OUTPUT);
  pinMode(LED_COLD, OUTPUT);
  pinMode(LED_NORMAL, OUTPUT);
  pinMode(PIEZO_PIN, OUTPUT);

  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Fan: OFF");        // Estado inicial del ventilador
  Serial.begin(9600);           // Comunicación serial
}

void loop() {
  // Lectura de la temperatura desde el TMP36
  temp = readTemperature();

  // Mostrar la temperatura en el LCD y Serial Monitor
  lcd.setCursor(0, 1);
  lcd.print("Temp: ");
  lcd.print(temp, 1);  // Mostrar la temperatura con un decimal
  lcd.print(" C");
  Serial.print("Temp: ");
  Serial.println(temp);

  // Regular la temperatura
  temp_regulator();

  delay(500);  // Pausa para estabilizar las lecturas
}

float readTemperature() {
  // Convertir la lectura analógica en grados Celsius
  int sensorValue = analogRead(TEMP_PIN);
  float voltage = sensorValue * (5.0 / 1024.0);  // Convertir la lectura a voltaje
  float temperature = (voltage - 0.5) * 100.0;  // Convertir voltaje a grados Celsius
  return temperature;
}

void temp_regulator() {
  // Estado de LEDs, ventilador y piezo según la temperatura
  if (temp >= HOT_THRESHOLD) {
    activateCooling();
  } else if (temp <= COLD_THRESHOLD) {
    activateCold();
  } else {
    activateNormal();
  }
}

void activateCooling() {
  // Configuración para temperaturas altas
  lcd.setCursor(5, 0);
  lcd.print("ON ");            // Mostrar estado "ON" en el LCD
  Serial.println("Fan: ON");

  digitalWrite(LED_COOLING, HIGH);  // Enciende LED rojo
  digitalWrite(LED_COLD, LOW);      // Apaga LED azul
  digitalWrite(LED_NORMAL, LOW);    // Apaga LED amarillo
  digitalWrite(MOTOR_PIN, HIGH);    // Enciende el ventilador

  // Activar el piezo solo una vez
  if (!piezoSounded) {
    tone(PIEZO_PIN, 2000, 500);  // Emitir tono de alarma para calor alto
    piezoSounded = true;
  }

  fanTurnedOn = true;
}

void activateCold() {
  // Configuración para temperaturas bajas
  lcd.setCursor(5, 0);
  lcd.print("OFF");            // Mostrar estado "OFF" en el LCD
  Serial.println("Fan: OFF");

  digitalWrite(LED_COOLING, LOW);   // Apaga LED rojo
  digitalWrite(LED_COLD, HIGH);     // Enciende LED azul
  digitalWrite(LED_NORMAL, LOW);    // Apaga LED amarillo
  digitalWrite(MOTOR_PIN, LOW);     // Apaga el ventilador

  // Activar el piezo solo una vez
  if (!piezoSounded) {
    tone(PIEZO_PIN, 500, 500);  // Emitir tono de alarma para frío extremo
    piezoSounded = true;
  }

  fanTurnedOn = false;
}

void activateNormal() {
  // Configuración para temperaturas normales
  lcd.setCursor(5, 0);
  lcd.print("OFF");            // Mostrar estado "OFF" en el LCD
  Serial.println("Fan: OFF");

  digitalWrite(LED_COOLING, LOW);   // Apaga LED rojo
  digitalWrite(LED_COLD, LOW);      // Apaga LED azul
  digitalWrite(LED_NORMAL, HIGH);   // Enciende LED amarillo
  digitalWrite(MOTOR_PIN, LOW);     // Apaga el ventilador

  noTone(PIEZO_PIN);  // Apagar el piezo
  piezoSounded = false;
}
