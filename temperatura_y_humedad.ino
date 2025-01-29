//se incluye la libreria de la pantalla LCD
#include <LiquidCrystal.h>
//  se definen pines del sensor de temperatura
#define pin_sensor A0  // definir una constante
#define pin_sensorhu A1
#define pin_buzzer 8
#define pulsador 12

//configurar las conexiones entre la LCD y el arduino
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);  // (RS,e,D4,D5,D6,D7)

// definir variables de proposito general

int cont = 0;
int lectura;  // definir una variable entera
float temp;
float humedad;
float pin_sensor_temp = A0;
float pin_sensor_humedad = A1;
float lectura_temp;
float lectura_humedad;
int frecuencia;
int duracion;
int pinR = 9;
int pinG = 11;
int pinB = 10;


void setup() {
  lcd.begin(16, 2);  // inicializar la comunicacion con la pantalla

  pinMode(pin_sensor_temp, INPUT);     // configurar el sensor como entrada
  pinMode(pin_sensor_humedad, INPUT);  // configura el sensor como entrada
  pinMode(pulsador, INPUT);

  lcd.setCursor(0, 0);
  lcd.print("humedad");  // imprimir un mensaje en la pantalla
  lcd.setCursor(5, 1);
  lcd.print("sistema de temperatura");
  delay(3000);


  lcd.clear();
  pinMode(pinR, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(pinB, OUTPUT);
}

void loop() {
  if (digitalRead(pulsador) == 1) {  // al presionar se da una preciptacion de lluvia y se imprime el mensaje en la panatalla
    lcd.clear();                     // se limpia la panatalla y se muestra el aviso de peligro
    lcd.setCursor(0, 0);
    lcd.print("peligro de");
    lcd.setCursor(0, 1);
    lcd.print("lluvia");
  }


  lectura_temp = analogRead(pin_sensor_temp);
  temp = (lectura_temp * (500.0 / 1024.) - 50);

  lectura_humedad = analogRead(pin_sensor_humedad);
  humedad = map(lectura_humedad, 6, 679, 0, 100);
  if (digitalRead(pulsador) == 0) {
    if (temp < 35 || humedad < 40 && pulsador == 0) {

      lcd.setCursor(0, 0);
      lcd.print("temp: ");
      lcd.setCursor(6, 0);  // ubicar el cursor en la columna 0, fila 6
      lcd.print(temp);      // imprimir la variable contador

      lcd.setCursor(0, 1);
      lcd.print("humedad:  ");
      lcd.setCursor(10, 1);  // ubicar el cursor en la columna 0
      lcd.print(humedad);    // imprimir la variable contador
      analogWrite(pinR, 255);
      analogWrite(pinB, 255);
      analogWrite(pinG, 255);


      if (temp > 35 && temp < 40 || humedad > 75 && humedad < 85) {
        frecuencia = 700;
        duracion = 2000;
        tone(pin_buzzer, frecuencia, duracion);

        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("aviso");
        lcd.setCursor(1, 1);      // ubicar el cursor en la columna 0, fila 6
        lcd.print("daño menor");  // imprimir la variable contador
        delay(2000);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("temp: ");
        lcd.setCursor(6, 0);  // ubicar el cursor en la columna 0, fila 6
        lcd.print(temp);      // imprimir la variable contador
        lcd.setCursor(0, 1);
        lcd.print("humedad:  ");
        lcd.setCursor(10, 1);  // ubicar el cursor en la columna 0
        lcd.print(humedad);    // imprimir la variable
        delay(4000);
        lcd.clear();

        analogWrite(pinR, 255);
        analogWrite(pinB, 100);
        analogWrite(pinG, 150);

      } else {
        digitalWrite(pin_buzzer, LOW);
        analogWrite(pinR, 0);
        analogWrite(pinB, 0);
        analogWrite(pinG, 0);
      }
      if (temp > 41 && temp < 45 || humedad > 86 && humedad < 95) {
        frecuencia = 700;
        duracion = 2000;
        tone(pin_buzzer, frecuencia, duracion);
        analogWrite(pinR, 0);
        analogWrite(pinB, 255);  //led RGB se coloca en color amarillo piña
        analogWrite(pinG, 255);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("CUIDADO POSIBLE  ");
        lcd.setCursor(1, 1);   // ubicar el cursor en la columna 0
        lcd.print("PELIGRO");  // imprimir la variable contador
        delay(4000);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("temp: ");
        lcd.setCursor(6, 0);  // ubicar el cursor en la columna 0, fila 6
        lcd.print(temp);      // imprimir la variable contador

        lcd.setCursor(0, 1);
        lcd.print("humedad:  ");
        lcd.setCursor(10, 1);  // ubicar el cursor en la columna 0
        lcd.print(humedad);    // imprimir la variable contador
        delay(2000);

      } else {
        digitalWrite(pin_buzzer, LOW);
        analogWrite(pinR, 0);
        analogWrite(pinB, 0);
        analogWrite(pinG, 0);
      }

      if (temp > 46 && temp < 50 || humedad > 95 && humedad < 100) {
        frecuencia = 700;
        duracion = 2000;
        tone(pin_buzzer, frecuencia, duracion);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("ADVERTENCIA ");
        lcd.setCursor(1, 1);          // ubicar el cursor en la columna 0, fila 6
        lcd.print("DAÑO INMINENTE");  // imprimir la variable contador


        analogWrite(pinR, 0);
        analogWrite(pinB, 0);
        analogWrite(pinG, 255);  // led Rbg se pone de color rojo
        delay(500);
        analogWrite(pinR, 255);  // led RBG se pone de color azul
        analogWrite(pinB, 0);
        analogWrite(pinG, 0);
      } else {
        digitalWrite(pin_buzzer, LOW);
        analogWrite(pinR, 0);
        analogWrite(pinB, 0);
        analogWrite(pinG, 0);
      }
    }
  }
}