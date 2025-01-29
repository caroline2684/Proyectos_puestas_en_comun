#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#define BUZZER 7  // Definir el pin del buzzer
#define SENSOR 8  // Definir el pin del sensor

void setup()
{
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(SENSOR, INPUT);   // Configurar el pin del sensor como entrada
  pinMode(BUZZER, OUTPUT);  // Configurar el buzzer como salida
  digitalWrite(BUZZER, LOW); // Asegurar que el buzzer esté apagado al inicio
}

void loop()
{
  int a = digitalRead(SENSOR); // Leer el estado del sensor
  Serial.println(a);

  if (a == 1) // Si el sensor detecta un objeto
  {
    lcd.setCursor(2, 0);
    lcd.print("ALARM!!!");  // Mostrar "ALARM!!!" en el LCD
    
    // Generar una alarma con el buzzer
    for (int i = 0; i < 5; i++) { // Repetir el sonido 5 veces
      tone(BUZZER, 1000, 200); // Tono de 1000 Hz por 200 ms
      delay(300);              // Pausa de 100 ms entre tonos
      tone(BUZZER, 1500, 200); // Tono de 1500 Hz por 200 ms
      delay(300);              // Pausa de 100 ms entre tonos
    }
    lcd.clear(); // Limpiar la pantalla del LCD
    delay(2000); // Esperar 2 segundos
  }
  else {
    noTone(BUZZER); // Asegurar que el buzzer esté apagado cuando no detecte
  }
}
