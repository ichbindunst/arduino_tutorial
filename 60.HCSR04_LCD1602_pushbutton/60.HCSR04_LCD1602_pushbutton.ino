
#include <LiquidCrystal.h>

// hcsr04
int trigPin = 2;
int echoPin = 3;
float pingTravelTime;
float Distance;

// lcd part
int rs = 7;
int en = 8;

// pushbutton 
int buttonPin = A0;
int buttonVal;

int d4 = 9;
int d5 = 10;
int d6 = 11;
int d7 = 12;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // put your setup code here, to run once:

  pinMode(trigPin, HIGH);
  pinMode(echoPin, INPUT);
  
  pinMode(buttonPin, INPUT);
  digitalWrite(buttonPin, HIGH);
  Serial.begin(9600);
  
  lcd.begin(16, 2);

}

void loop() {
  // put your main code here, to run repeatedly:
  
  lcd.setCursor(0, 0);
  lcd.print("Place the Target");
  lcd.setCursor(0, 1);
  lcd.print("Press to Measure");

  buttonVal = digitalRead(buttonPin);
  while(buttonVal == 1){
    // press the button to change the buttonVal = 0
    // jump out of this loop and go on to excute the programm
    buttonVal = digitalRead(buttonPin);  
  }
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);---------------
  digitalWrite(trigPin, LOW);

  pingTravelTime = pulseIn(echoPin, HIGH);
  Distance = pingTravelTime * 340 / 2 / 1000;

  // clear the displays before showing the distance
  lcd.clear();
  
  lcd.setCursor(0, 0);
  lcd.print("Distance:(mm) ");
  lcd.setCursor(0, 1);
  lcd.print(Distance);
  delay(5000);


}
