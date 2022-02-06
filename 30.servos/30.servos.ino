#include <Servo.h>

int servoPin = 13;
int servoPos = 0;

String msg;

Servo myServo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  // attach the given pin to the next free channel, sets pinMode, 
  // returns channel number or INVALID_SERVO if failure
  myServo.attach(servoPin);
}

void loop() {
  // put your main code here, to run repeatedly:

  msg = Serial.readString();

  if(msg == "off"){
    // stop the servo
    myServo.detach();
  }

  // go half circle clock and counterclockwise
  for(servoPos = 0; servoPos < 180; servoPos++){
    // if value is < 200 its treated as an angle, otherwise as pulse width in microseconds
    myServo.write(servoPos);   
    delay(15); 
  }

  for(servoPos = 180; servoPos > 0; servoPos--){
    myServo.write(servoPos);
    delay(15);  
  }
  
}
