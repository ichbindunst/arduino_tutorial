/**
  *just like stepmotor, while using DC motor, it draws a lot current than the 
  *arduino can provide, it can not connect to the arduino directly,
  *so a exteral power supply module should be used

  *when using external power supply, you should always make sure that the 
  *current from you external power supply should match your motor controller
  *and DC motor
 
  *L293D is the DC motor control chip

**/

// pin1 from L293D is the Pin to enable DC motor and control the speed
int speedPin = 5;

// two rotate directions 
int dir1 = 4;
int dir2 = 3; 

// speed between 0 - 255
int speedVal = 125;

void setup() {
  // put your setup code here, to run once: 
  pinMode(speedPin, OUTPUT);
  pinMode(dir1, OUTPUT);
  pinMode(dir2, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(dir1, LOW);
  digitalWrite(dir2, HIGH);
  analogWrite(speedPin, speedVal);
}
