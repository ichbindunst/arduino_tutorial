// This file can be found at 
// https://github.com/arduino-libraries/LiquidCrystal/blob/master/src/LiquidCrystal.h

#include <LiquidCrystal.h>

int rs = 7;
int en = 8;

int d4 = 9;
int d5 = 10;
int d6 = 11;
int d7 = 12;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


void setup() {
  // put your setup code here, to run once:

  //  void begin(uint8_t cols, uint8_t rows, uint8_t charsize = LCD_5x8DOTS);
  // lcd1602 can show 2 rows with each rows has 16 characters
  lcd.begin(16, 2);

}

void loop() {
  // put your main code here, to run repeatedly:

  /**
   * if the lcd can not show rationally, try these:
   * 1. check if all the wires are connected correctly
   * 2. check if all the code are wrote correctly
   * 3. change the value of potentialmeter
   * 4. make sure all the wires are tightly connected in the board
   */

  lcd.setCursor(0, 0);
  lcd.print("Hello");
  delay(1000);
  lcd.setCursor(0, 1);
  lcd.print("My name is Yao");
  delay(1000);
  lcd.clear();

}
