
#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
int tmp36 = A5;
int temperatur;
int posisiA;
int posisiB;
int posisiC = 10;
int posisiD = 0;
int hasil;
int nilai;
//boolean erorHot;
//boolean erorCold;

int tmp[3] = { 4, 5, 6 };
String satuan[3] = { "K", "F", "C" };
int satuanInt = 2;



const int data = A1;
const int latch = A3;
const int clock = A4;



void ledWrite(int led) {
  digitalWrite(latch, 0);
  shiftOut(data, clock, LSBFIRST, led);
  digitalWrite(latch, 1);
}









void startMachine() {
  lcd.setCursor(0, 0);  //16x2 (16 baris kolom2)
  lcd.print("Starting Machine");


  for (int i = 0; i <= 5; i++) {
    delay(1000);
    lcd.setCursor(i, 1);
    lcd.print(".");
  }



  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Machine Started");


  ledWrite(B11111111);
  delay(250);
  ledWrite(B00000000);
  delay(250);
  ledWrite(B11111111);
  delay(250);
  ledWrite(B00000000);
  delay(500);

  lcd.clear();
}
void setup() {
  lcd.begin(16, 2);
  analogWrite(A2, 100);



  pinMode(data, OUTPUT);
  pinMode(latch, OUTPUT);
  pinMode(clock, OUTPUT);



  pinMode(clock, OUTPUT);
  startMachine();
  Serial.begin(9600);
}


void loop() {

  analogWrite(A2, 100);

  int nilai = (analogRead(A5) / 1024.0 * 5.0 - 0.5) * 100;

  for (int i = 0; i <= 2; i++) {
    if (digitalRead(tmp[i]) == 1) {
      satuanInt = i;
      Serial.println(satuanInt);  //menentukan string satuan "K/F/C"
    }
  }



  if ((nilai) < -16)  //1
  {
    ledWrite(B10000000);
  } else {
    if ((nilai) >= -16 && (nilai) < 0)  //2
    {
      ledWrite(B11000000);
    } else {
      if ((nilai) >= 0 && (nilai) < 20)  //3
      {
        ledWrite(B11100000);
      } else {
        if ((nilai) >= 20 && (nilai) < 30)  //4
        {
          ledWrite(B11110000);
        } else {
          if ((nilai) >= 30 && (nilai) < 60)  //5
          {
            ledWrite(B11111000);
          } else {
            if ((nilai) >= 60 && (nilai) < 80)  //6
            {
              ledWrite(B11111100);
            } else {
              if ((nilai) >= 80 && (nilai) < 100)  //7
              {
                ledWrite(B11111110);
              } else {
                if ((nilai) >= 100) {
                  ledWrite(B11111111);
                } else {
                  Serial.println("Bruh the LED is broken, its dead to me");
                }
              }
            }
          }
        }
      }
    }
  }









  if ((satuanInt) == 0)  //kalau satuan nya Kelvin
  {
    hasil = nilai + 273.15;  //formula convert satuan
  } else {
    if ((satuanInt) == 1)  //formula nya Ferenhit
    {
      hasil = (nilai * 9 / 5) + 32;
    } else {
      if ((satuanInt) == 2) {
        hasil = nilai;
      } else {
        Serial.print("Bruh your termometer is broken");
      }
    }
  }


  if ((hasil) > 99) {
    posisiA = 3 + posisiC;
  } else {
    if ((hasil) > 9 && (hasil) < 100) {
      posisiA = 2 + posisiC;
    } else {
      if ((hasil) < 10 && (hasil) >= 0) {
        posisiA = 1 + posisiC;
      } else {
        if ((hasil) < 0 && (hasil) > -10) {
          posisiA = 2 + posisiC;
        } else {
          if ((hasil) < -9) {
            posisiA = 3 + posisiC;
          }
        }
      }
    }
  }
  posisiB = posisiA + 1;
  posisiB < 4;
  posisiB > 0;

  if ((nilai) > 100) {
    lcd.setCursor(0, 0);
    lcd.print("Warning");
    lcd.setCursor(0, 1);
    lcd.print("To Hot");
    tone(A0, 523, 1000);
    delay(500);
    tone(A0, 165, 1000);
    delay(500);
    lcd.clear();
  } else {
    if ((nilai) < -31) {
      lcd.setCursor(0, 0);
      lcd.print("Machine Error");
      lcd.setCursor(0, 1);
      lcd.print("To Cold.");
      tone(A0, 523, 1000);
      delay(500);
      noTone(A0);
      delay(500);
      lcd.clear();
    } else {
      lcd.setCursor(0, 0);
      lcd.print("Current");
      lcd.setCursor(0, 1);
      lcd.print("temperature");
      lcd.setCursor(posisiC, 0);
      lcd.print(hasil);
      lcd.setCursor(posisiA, posisiD);
      lcd.print("'");
      lcd.setCursor(posisiB, posisiD);
      lcd.print(satuan[satuanInt]);
      delay(500);
      lcd.clear();
    }
  }
}
