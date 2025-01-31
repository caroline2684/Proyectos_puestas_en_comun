
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup() {  //inicializar durante 2s
  lcd.begin(16, 2);
  lcd.print("INICIALIZANDO");
  delay(500);
  lcd.print(".");
  delay(500);
  lcd.print(".");
  delay(500);
  lcd.print(".");
  delay(500);
  lcd.print(".");
  delay(500);
}
void loop() {
  int sensorValue = analogRead(A0);
  double dV = sensorValue;
  double le = (dV / 670) * 100;  // Ajuste basado en el valor máximo real en Tinkercad
  int level = le;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("LIGHT LEVEL:");
  lcd.print(level);
  lcd.print("%");
  lcd.setCursor(0, 1);

  if ((level >= 0) && (level <= 15)) {
    lcd.print("VERY DARK");
  } else if ((level > 15) && (level <= 30)) {
    lcd.print("DARK");
  } else if ((level > 30) && (level <= 60)) {
    lcd.print("BRIGHT");
  } else {
    lcd.print("VERY BRIGHT");
  }

  delay(500);
}