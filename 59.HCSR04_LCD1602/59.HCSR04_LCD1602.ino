#include <LiquidCrystal.h>

// hcsr04
int trigPin = 2;
int echoPin = 3;
float pingTravelTime;
float Distance;

// lcd part
int rs = 7;
int en = 8;

int d4 = 9;
int d5 = 10;
int d6 = 11;
int d7 = 12;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // put your setup code here, to run once:

  pinMode(trigPin, HIGH);
  pinMode(echoPin, INPUT);
  
  lcd.begin(16, 2);

}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  pingTravelTime = pulseIn(echoPin, HIGH);
  Distance = pingTravelTime * 340 / 2 / 1000;


  lcd.setCursor(0, 0);
  lcd.print("Distance:(mm) ");
  lcd.setCursor(0, 1);
  lcd.print(Distance);
  delay(1000);

  
}
