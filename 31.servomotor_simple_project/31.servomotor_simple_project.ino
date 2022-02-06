#include <Servo.h>

Servo myServo;

int lightVal;
int lightPin = A5;

int angle;
int servoPin = 13;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(A5, INPUT);
  pinMode(servoPi, OUTPUT);
  myServo.attach(servoPin);
  
}

void loop() {
  // put your main code here, to run repeatedly:

  lightVal = analogRead(lightPin);
  Serial.println(lightVal);
  delay(500);

  // here you can give the function with angle and lightVal

  myServo.write(angle);  
  
}
