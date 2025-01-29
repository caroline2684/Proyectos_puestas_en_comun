#include <LiquidCrystal.h>            //llamamos a la librería de la pantalla LCD
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);  //definimos los pines en los cuales va conectada la LCD

int lectura = 0;
int lecturaSoil = 0;
int temperatura = 0.0;

int bomba = 12;

void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  pinMode(bomba, OUTPUT);
}

void loop() {
  lectura = analogRead(1);
  temperatura = (lectura * (500.0 / 1023.0)) - 50.0;  // para tmp36
  //temperatura = (5.0 * tempC * 100.0)/1024.0; // descomentar para lm35

  lecturaSoil = analogRead(2);
  int valorMapeado = map(lecturaSoil, 0, 1024, 0, 100);

  char strT[10];
  sprintf(strT, "%03d", temperatura);
  String str2t = String(strT);
  String cadena1 = "T: " + str2t + " C";

  char str[10];
  sprintf(str, "%03d", valorMapeado);
  String str2 = String(str);
  String cadena2 = "H: " + str2 + " %";
  lcd.setCursor(0, 0);
  lcd.print(cadena1);
  lcd.setCursor(0, 1);
  lcd.print(cadena2);

  if (valorMapeado < 50) {
    digitalWrite(bomba, HIGH);
  } else {
    digitalWrite(bomba, LOW);
  }
}
