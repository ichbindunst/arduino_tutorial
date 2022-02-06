// usin joystick to control the spped and direction of DC motor

int enablePin = 5;
int dir1 = 4;
int dir2 = 3;
float motorSpeed;

int switchPin = 2;
int switchVal;

int xValPin = A1;
int xVal;


void setup() {
  // put your setup code here, to run once:

  pinMode(enablePin, OUTPUT);
  pinMode(dir1, OUTPUT);
  pinMode(dir2, OUTPUT);

  pinMode(switchPin, INPUT);
  digitalWrite(switchPin, HIGH);

  pinMode(xValPin, INPUT);

  Serial.begin(9600);

}


void loop() {

  // if the joystick button be pushed, switch is off
  // then the motor will be off
  switchVal = digitalRead(switchPin);
  //Serial.print(switchVal);
  if(switchVal == 1){
    Serial.print("the motor is on, ");
    delay(1000);

    // xVal = 495 as boundry to change the direction
    // the bigger the value |xVal - 495| is, the faster motor rotates
    xVal = analogRead(xValPin);
    Serial.print(" xVal == ");
    Serial.println(xVal);
    delay(1000);
    if(xVal < 495){
      digitalWrite(dir1, HIGH);
      digitalWrite(dir2, LOW);
      motorSpeed = (495.00 - xVal)*255.00/495.00;
      analogWrite(enablePin, motorSpeed);
       
    }
    else if(xVal >= 495){
      digitalWrite(dir1, LOW);
      digitalWrite(dir2, HIGH);
      motorSpeed = (xVal - 495)*255 / 528;
      analogWrite(enablePin, motorSpeed);
    }
  }
  
  else{
    Serial.print("the motor is off, ");
    digitalWrite(dir1, LOW);
    digitalWrite(dir2, LOW);
    analogWrite(enablePin, 0);
    delay(1000);
  }

}
