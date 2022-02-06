// usin joystick to control the spped and direction of DC motor

int enablePin = 5;
int dir1 = 4;
int dir2 = 3;
float motorSpeed = 0;

int slowButton = 9;
int slowVal;
int fastButton = 8;
int fastVal;


void setup() {
  // put your setup code here, to run once:

  pinMode(enablePin, OUTPUT);
  pinMode(dir1, OUTPUT);
  //pinMode(dir2, OUTPUT);

  pinMode(slowButton, OUTPUT);
  digitalWrite(slowButton, HIGH);
  pinMode(fastButton, OUTPUT);
  digitalWrite(fastButton, HIGH);

  Serial.begin(9600);

}


void loop() {


  

  slowVal = digitalRead(slowButton);
  fastVal = digitalRead(fastButton);
  
  if(slowVal == 0 && fastVal == 1){
    motorSpeed = motorSpeed - 50;
    if(motorSpeed <= 0){
      motorSpeed = 0;
    }

    Serial.print("go slower? ");
    // if slowVal == 0, which means fast button are beging pushed
    Serial.println(slowVal);
    if(slowVal == 0){
      Serial.println("yes");  
    }
  }

  
  if(fastVal == 0 && slowVal == 1){
    motorSpeed = motorSpeed + 50;
    if(motorSpeed >= 255){
      motorSpeed = 255;
    }

    Serial.print("go faster? ");
    // if fastVal == 0, which means the fast button are beging pushed
    Serial.println(slowVal);
    if(slowVal == 0){
      Serial.println("yes");
    }
  }

  else{
    Serial.print("the motor runs at speed ");
    Serial.println(motorSpeed);  
  }

  digitalWrite(dir1, HIGH);
  analogWrite(enablePin, motorSpeed);
  
  delay(1000);

  
 

}
