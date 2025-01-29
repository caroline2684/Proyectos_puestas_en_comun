// Define los pines
const int ldrPin = A0;  // Pin donde está conectado el LDR (analógico)
const int ledPin = 9;   // Pin donde está conectado el LED (digital)

// Define el umbral de luz
int umbralLuz = 500;    // Ajusta este valor según tus necesidades

void setup() {
  pinMode(ledPin, OUTPUT);  // Configura el pin del LED como salida
  Serial.begin(9600);       // Inicia la comunicación serie para monitorear los valores
}

void loop() {
  // Lee el valor del LDR
  int valorLuz = analogRead(ldrPin);
  
  // Imprime el valor leído (opcional, para monitoreo en el Monitor Serie)
  Serial.println(valorLuz);
  
  // Compara el valor de luz con el umbral
  if (valorLuz < umbralLuz) {
    digitalWrite(ledPin, HIGH); // Enciende el LED si hay poca luz
  } else {
    digitalWrite(ledPin, LOW);  // Apaga el LED si hay suficiente luz
  }
  
  delay(100); // Pausa para evitar lecturas muy rápidas
}
