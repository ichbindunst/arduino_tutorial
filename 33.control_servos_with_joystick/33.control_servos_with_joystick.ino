#include <Servo.h>

Servo myServo;

// joystick can control 2 directions 
// but servo only needs a value, without a direction

// 0 - 180 degree, correcponding to 0-1023
// if joystick in the middle, the value would be 511
// on both side the value would be 0 and 1023, which means the servo will rotate for 
// clockwise and counterclockwise 90

// this means that you can control 2 servos 
// but here we only use one direction, that is x direction to control one servo


// x direction
int xPin = A0;

// y direction
//int yPin = A1;

// joystick switch open and off
int sPin = 2;

// servo pin
int servoPin = 10;

int WVx;


int xVal;
// int yVal;
int sVal;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(xPin, INPUT);

  pinMode(sPin, INPUT);

  // set servonPin high
  myServo.attach(servoPin);

  // open the joystick
  digitalWrite(sPin, HIGH);

}

void loop() {
  // put your main code here, to run repeatedly:

  
  xVal = analogRead(xPin);
  WVx = (180./1023.)*xVal;
  
  sVal = digitalRead(sPin);
  delay(500);

  myServo.write(WVx);

  Serial.print("X value is: ");
  Serial.print(xVal);
  Serial.print(" Switch state is: ");
  Serial.println(sVal);
  
}
