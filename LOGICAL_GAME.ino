#include <LiquidCrystal.h>
#include <Keypad.h>
int a = 0, b = 0, c = 0, d = 0, sum, score = 0;
int saved = 0, var = 0;
int stats = 1;  // 1-7 statement
char key;
int C1 = 0, C2 = 0, C3 = 0, F1 = 0, F2 = 0, F3 = 0;
char pad[4][4] = {
  { '1', '2', '3', 'A' },
  { '4', '5', '6', 'B' },
  { '7', '8', '9', 'C' },
  { '*', '0', '#', 'D' }
};
byte pinRows[4] = { 9, 8, 7, 6 };
byte pinColumnas[4] = { 5, 4, 3, 2 };
Keypad keypad = Keypad(makeKeymap(pad), pinRows, pinColumnas, 4, 4);
LiquidCrystal lcd(A3, A4, 13, 12, 11, 10);

void setup() {
  pinMode(A2, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A0, OUTPUT);
  lcd.begin(16, 2);
  lcd.print("Wellcome");
  lcd.setCursor(0, 1);
  delay(500);
  lcd.print("Enjoy the game");
  delay(1000);
  lcd.clear();
}

void fail() {  //incorrect answer
  digitalWrite(A2, HIGH);
  lcd.setCursor(0, 1);
  lcd.print("Incorrect");
  lcd.setCursor(8, 0);
  lcd.print("       ");
  tone(A5, 500, 100);
  delay(500);
  digitalWrite(A2, LOW);
  lcd.setCursor(0, 1);
  lcd.print("           ");
}

void win() {  //correct answer
  digitalWrite(A0, HIGH);
  lcd.setCursor(0, 1);
  lcd.print("Correct");
  tone(A5, 900, 50);
  delay(1000);
  digitalWrite(A0, LOW);
  lcd.clear();
}

void loop() {
  char key = keypad.getKey();
  switch (stats) {
    case 1:
      if (key == '*') {
        lcd.clear();
        stats = 6;
      }
      if (key == '#') {
        lcd.clear();
        stats = 7;
      }

      if (!key) {
        lcd.setCursor(0, 0);
        lcd.print("Press A B C or D");
        lcd.setCursor(0, 1);
        lcd.print("Score: ");
        lcd.print(score);
      }

      if (key == 'A') {
        lcd.clear();
        C1 = random(100, 500);
        C2 = random(0, 400);
        stats = 2;
      }

      if (key == 'B') {
        lcd.clear();
        C1 = random(500, 900);
        C2 = random(-400, -100);
        stats = 3;
      }
      if (key == 'C') {
        lcd.clear();
        C1 = random(9, 23);
        C2 = random(1, 40);
        stats = 4;
      }
      if (key == 'D') {
        lcd.clear();
        C1 = random(10, 900);
        C2 = random(1, 10);
        stats = 5;
        lcd.setCursor(0, 0);
        lcd.print("Enter the");
        lcd.setCursor(0, 1);
        lcd.print("integer part");
        delay(1000);
        lcd.clear();
      }
      break;

    case 2:
      if (!key) {
        lcd.setCursor(0, 0);
        lcd.print(C1);
        lcd.print("+");
        lcd.print(C2);
        lcd.print("=");
        lcd.setCursor(0, 1);
        sum = C1 + C2;
        F3 = sum % 10;
        sum /= 10;
        F2 = sum % 10;
        sum /= 10;
        F1 = sum % 10;
      }
      if (key == '*') {
        lcd.setCursor(8 + var, 0);
        lcd.print(" ");
        if (var > 0) var--;
      } else {
        if (key && !saved && var != 3) {
          lcd.setCursor(8 + var, 0);
          lcd.print(key);
          key = key - 48;
          var++;
          switch (var) {
            case 1: a = key; break;
            case 2: b = key; break;
            case 3: c = key; break;
          }
        }
        if (key == '#' && var == 3) {
          saved = 1;
          if (a == F1 && b == F2 && c == F3) {
            stats = 1;
            var = 0;
            saved = 0;
            score++;
            win();
            break;
          }
        }
        if (saved) {
          fail();
          score--;
          saved = 0;
          var = 0;
        }
        break;

        case 3:
          if (!key) {
            lcd.setCursor(0, 0);
            lcd.print(C1);
            lcd.print(C2);
            lcd.print("=");
            lcd.setCursor(0, 1);
            sum = C1 + C2;
            F3 = sum % 10;
            sum /= 10;
            F2 = sum % 10;
            sum /= 10;
            F1 = sum % 10;
          }
          if (key == '*') {
            lcd.setCursor(8 + var, 0);
            lcd.print(" ");
            if (var > 0) var--;
          } else {
            if (key && !saved && var != 3) {
              lcd.setCursor(8 + var, 0);
              lcd.print(key);
              key = key - 48;
              var++;
              switch (var) {
                case 1: a = key; break;
                case 2: b = key; break;
                case 3: c = key; break;
              }
            }
            if (key == '#' && var == 3) {
              saved = 1;
              if (a == F1 && b == F2 && c == F3) {
                stats = 1;
                score++;
                var = 0;
                saved = 0;
                win();
                break;
              }
            }
            if (saved) {
              fail();
              score--;
              saved = 0;
              var = 0;
            }
            break;

            case 4:
              if (!key) {
                lcd.setCursor(0, 0);
                lcd.print(C1);
                lcd.print(" * ");
                lcd.print(C2);
                lcd.print("=");
                lcd.setCursor(0, 1);
                sum = C1 * C2;
                F3 = sum % 10;
                sum /= 10;
                F2 = sum % 10;
                sum /= 10;
                F1 = sum % 10;
              }
              if (key == '*') {
                lcd.setCursor(8 + var, 0);
                lcd.print(" ");
                if (var > 0) var--;
              } else {
                if (key && !saved && var != 3) {
                  lcd.setCursor(8 + var, 0);
                  lcd.print(key);
                  key = key - 48;
                  var++;
                  switch (var) {
                    case 1: a = key; break;
                    case 2: b = key; break;
                    case 3: c = key; break;
                  }
                }
                if (key == '#' && var == 3) {
                  saved = 1;
                  if (a == F1 && b == F2 && c == F3) {
                    stats = 1;
                    var = 0;
                    saved = 0;
                    score++;
                    win();
                    break;
                  }
                }
                if (saved) {
                  fail();
                  score--;
                  saved = 0;
                  var = 0;
                }
                break;

                case 5:
                  if (!key) {
                    lcd.setCursor(0, 0);
                    lcd.print(C1);
                    lcd.print(" / ");
                    lcd.print(C2);
                    lcd.print("=");
                    lcd.setCursor(0, 1);
                    sum = C1 / C2;
                    F3 = sum % 10;
                    sum /= 10;
                    F2 = sum % 10;
                    sum /= 10;
                    F1 = sum % 10;
                  }
                  if (key == '*') {
                    lcd.setCursor(8 + var, 0);
                    lcd.print(" ");
                    if (var > 0) var--;
                  } else {
                    if (key && !saved && var != 3) {
                      lcd.setCursor(8 + var, 0);
                      lcd.print(key);
                      key = key - 48;
                      var++;
                      switch (var) {
                        case 1: a = key; break;
                        case 2: b = key; break;
                        case 3: c = key; break;
                      }
                    }
                    if (key == '#' && var == 3) {
                      saved = 1;
                      if (a == F1 && b == F2 && c == F3) {
                        stats = 1;
                        var = 0;
                        saved = 0;
                        score++;
                        win();
                        break;
                      }
                    }
                    if (saved) {
                      fail();
                      score--;
                      saved = 0;
                      var = 0;
                    }
                    break;

                    case 6:
                      lcd.setCursor(0, 0);
                      lcd.print("A-Summation");
                      lcd.setCursor(0, 1);
                      lcd.print("B-Subtraction");
                      if (key == '*') {
                        lcd.clear();
                        stats = 1;
                      }
                      break;

                    case 7:
                      lcd.setCursor(0, 0);
                      lcd.print("C-Multiplication");
                      lcd.setCursor(0, 1);
                      lcd.print("D-Division");
                      if (key == '#') {
                        lcd.clear();
                        stats = 1;
                      }
                      break;
                  }
              }
          }
      }
  }
}
