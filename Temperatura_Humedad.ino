#include "DHT.h"

#define DHTPIN 2       // Pin donde está conectado el DHT11
#define DHTTYPE DHT11  // Tipo de sensor DHT11
#define BUZZER 8       // Pin del buzzer

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);         // Inicializar comunicación serial
  dht.begin();                // Inicializar DHT11
  pinMode(BUZZER, OUTPUT);    // Configurar el buzzer como salida
  digitalWrite(BUZZER, LOW);  // Asegurar que el buzzer esté apagado al inicio
}

void loop() {
  // ---- LECTURA DEL SENSOR DE HUMEDAD DEL SUELO ----
  int lecturaSuelo = analogRead(A0);  // Leer sensor de humedad del suelo
  Serial.print("Lectura del suelo: ");
  Serial.println(lecturaSuelo);

  if (lecturaSuelo >= 1000) {
    Serial.println(">> EL SENSOR ESTA DESCONECTADO O FUERA DEL SUELO <<");
    tone(BUZZER, 1000, 500);  // Emitir tono de 1000 Hz por 500 ms
  } else if (lecturaSuelo < 1000 && lecturaSuelo >= 600) {
    Serial.println(">> EL SUELO ESTA SECO <<");
    tone(BUZZER, 2000, 500);  // Emitir tono de 2000 Hz por 500 ms
  } else if (lecturaSuelo < 600 && lecturaSuelo >= 400) {
    Serial.println(">> EL SUELO ESTA HUMEDO <<");
    noTone(BUZZER);  // Apagar el buzzer
  } else if (lecturaSuelo < 400) {
    Serial.println(">> EL SENSOR ESTA EN AGUA <<");
    tone(BUZZER, 500, 1000);  // Emitir tono de 500 Hz por 1 segundo
  }

  // ---- LECTURA DEL SENSOR DHT11 ----
  float humedadAire = dht.readHumidity();         // Leer humedad del aire
  float temperaturaAire = dht.readTemperature();  // Leer temperatura del aire

  if (isnan(humedadAire) || isnan(temperaturaAire)) {  // Verificar si hubo error
    Serial.println("Error al leer el sensor DHT11");
  } else {
    Serial.print("Humedad del aire: ");
    Serial.print(humedadAire);
    Serial.print(" %\t");
    Serial.print("Temperatura del aire: ");
    Serial.print(temperaturaAire);
    Serial.println(" °C");

    // ---- INDICACIÓN CON EL BUZZER SEGÚN LA TEMPERATURA ----
    if (temperaturaAire < 20) {
      Serial.println(">> TEMPERATURA BAJA <<");
      tone(BUZZER, 300, 500);  // Emitir tono de 300 Hz por 500 ms
    } else if (temperaturaAire >= 20 && temperaturaAire <= 30) {
      Serial.println(">> TEMPERATURA NORMAL <<");
      noTone(BUZZER);  // Apagar el buzzer
    } else if (temperaturaAire > 30) {
      Serial.println(">> TEMPERATURA ALTA <<");
      tone(BUZZER, 3000, 500);  // Emitir tono de 3000 Hz por 500 ms
    }
  }

  Serial.println("-----------------------------------");
  delay(2000);  // Esperamos 2 segundos antes de la próxima lectura
}
