int led1 = 13;
int led2 = 12;
int led3 = 11;
int led4 = 10;
int led5 = 9;
int led6 = 8;
int led7 = 7;
int led8 = 6;
int Pulsadors1 = 5;
int Pulsadors2 = 4;
int Pulsadors3 = 3;
int Pulsadors4 = 2;
int Pulsadors5 = 1;
bool ValorPulsadors1, ValorPulsadors2, ValorPulsadors3, ValorPulsadors4, ValorPulsadors5 = 0;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(led8, OUTPUT);
  pinMode(Pulsadors1, INPUT);
  pinMode(Pulsadors2, INPUT);
  pinMode(Pulsadors3, INPUT);
  pinMode(Pulsadors4, INPUT);
  pinMode(Pulsadors5, INPUT);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
  digitalWrite(led6, LOW);
  digitalWrite(led7, LOW);
  digitalWrite(led8, LOW);
}

void loop() {
  ValorPulsadors1 = digitalRead(Pulsadors1);
  if (ValorPulsadors1 == HIGH)  //Condicion
  {
    digitalWrite(led1, HIGH);  //Secuencia 1
    delay(100);
    digitalWrite(led2, HIGH);
    delay(100);
    digitalWrite(led3, HIGH);
    delay(100);
    digitalWrite(led4, HIGH);
    delay(100);
    digitalWrite(led5, HIGH);
    delay(100);
    digitalWrite(led6, HIGH);
    delay(100);
    digitalWrite(led7, HIGH);
    delay(100);
    digitalWrite(led8, HIGH);
  } else  //Si no se cumple la condicion
  {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
    digitalWrite(led6, LOW);
    digitalWrite(led7, LOW);
    digitalWrite(led8, LOW);
  }
  ValorPulsadors2 = digitalRead(Pulsadors2);
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
  digitalWrite(led5, HIGH);
  digitalWrite(led6, HIGH);
  digitalWrite(led7, HIGH);
  digitalWrite(led8, HIGH);
  if (ValorPulsadors2 == HIGH)  //Condicion
  {
    digitalWrite(led8, LOW);  //Secuencia 2
    delay(100);
    digitalWrite(led7, LOW);
    delay(100);
    digitalWrite(led6, LOW);
    delay(100);
    digitalWrite(led5, LOW);
    delay(100);
    digitalWrite(led4, LOW);
    delay(100);
    digitalWrite(led3, LOW);
    delay(100);
    digitalWrite(led2, LOW);
    delay(100);
    digitalWrite(led1, LOW);
  } else  //Si no se cumple la condicion
  {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
    digitalWrite(led6, LOW);
    digitalWrite(led7, LOW);
    digitalWrite(led8, LOW);
  }
  ValorPulsadors3 = digitalRead(Pulsadors3);
  if (ValorPulsadors3 == HIGH)  //Condicion
  {
    digitalWrite(led4, HIGH);  //Secuencia 3
    digitalWrite(led5, HIGH);
    delay(100);
    digitalWrite(led3, HIGH);
    digitalWrite(led6, HIGH);
    delay(100);
    digitalWrite(led2, HIGH);
    digitalWrite(led7, HIGH);
    delay(100);
    digitalWrite(led1, HIGH);
    digitalWrite(led8, HIGH);
  } else  //Si no se cumple la condicion
  {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
    digitalWrite(led6, LOW);
    digitalWrite(led7, LOW);
    digitalWrite(led8, LOW);
  }
  ValorPulsadors4 = digitalRead(Pulsadors4);
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
  digitalWrite(led5, HIGH);
  digitalWrite(led6, HIGH);
  digitalWrite(led7, HIGH);
  digitalWrite(led8, HIGH);
  if (ValorPulsadors4 == HIGH)  //Condicion
  {
    digitalWrite(led8, LOW);  //Secuencia 4
    digitalWrite(led1, LOW);
    delay(100);
    digitalWrite(led7, LOW);
    digitalWrite(led2, LOW);
    delay(100);
    digitalWrite(led6, LOW);
    digitalWrite(led3, LOW);
    delay(100);
    digitalWrite(led5, LOW);
    digitalWrite(led4, LOW);
  } else  //Si no se cumple la condicion
  {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
    digitalWrite(led6, LOW);
    digitalWrite(led7, LOW);
    digitalWrite(led8, LOW);
  }
  ValorPulsadors5 = digitalRead(Pulsadors5);
  if (ValorPulsadors5 == HIGH)  //Condicion
  {
    digitalWrite(led1, HIGH);  //Secuencia 5
    digitalWrite(led8, HIGH);
    delay(100);
    digitalWrite(led2, HIGH);
    digitalWrite(led7, HIGH);
    delay(100);
    digitalWrite(led3, HIGH);
    digitalWrite(led6, HIGH);
    delay(100);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, HIGH);
  } else  //Si no se cumple la condicion
  {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
    digitalWrite(led6, LOW);
    digitalWrite(led7, LOW);
    digitalWrite(led8, LOW);
  }
}