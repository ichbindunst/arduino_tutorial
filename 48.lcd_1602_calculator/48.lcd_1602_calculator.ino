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

float firstNum;
float secondNum;
float answer;

String op;

void setup() {
  // put your setup code here, to run once:

  //  void begin(uint8_t cols, uint8_t rows, uint8_t charsize = LCD_5x8DOTS);
  // lcd1602 can show 2 rows with each rows has 16 characters
  lcd.begin(16, 2);

  Serial.begin(9600);  

}

void loop() {
  // put your main code here, to run repeatedly:

  lcd.setCursor(0, 0);
  lcd.print("Input First Number: ");
  while(Serial.available()==0){}
  firstNum = Serial.parseFloat();
  lcd.setCursor(0, 1);
  lcd.print(firstNum);
  delay(1000);
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Input Second Number: ");
  while(Serial.available()==0){}
  secondNum = Serial.parseFloat();
  lcd.setCursor(0, 1);
  lcd.print(secondNum);
  delay(1000);
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Give your operator");
  while(Serial.available()==0){}
  op = Serial.readString();
  lcd.setCursor(0, 1);
  lcd.print(op);
  
  if(op == "+"){
    answer = firstNum + secondNum;
  }
  else if(op == "-"){
    answer = firstNum - secondNum;
  }
  if(op == "*"){
    answer = firstNum * secondNum;
  }
  if(op == "/"){
    answer = firstNum / secondNum;
  }
  
  delay(1000);
  lcd.clear();
  
  lcd.setCursor(0, 1);
  lcd.print(firstNum);
  lcd.print(op);
  lcd.print(secondNum);
  lcd.print(" = ");
  lcd.print(answer);
  delay(5000);

  lcd.clear();

}
