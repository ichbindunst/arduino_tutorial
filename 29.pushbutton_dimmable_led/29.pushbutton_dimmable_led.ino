int buttonPin1 = 2;
int buttonPin2 = 4;
int ledPin = 6;
int buzzPin = 8;

int buttonVal1;
int buttonVal2;

int ledBright = 0;

int delayTime = 1000;

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzPin, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  
  // put your main code here, to run repeatedly:
  buttonVal1 = digitalRead(buttonPin1);
  buttonVal2 = digitalRead(buttonPin2);

  Serial.print("Button 1 = ");
  Serial.print(buttonVal1);
  Serial.print(", Button 2 = ");
  Serial.print(buttonVal2);
  Serial.println();
  delay(delayTime);
  
  if(buttonVal1 == 0){
    ledBright = ledBright + 5;
  }

  if(buttonVal2 == 0){
    ledBright = ledBright - 5;
  }

  if(ledBright > 255){
    ledBright = 255;
    digitalWrite(buzzPin, HIGH);
    delay(delayTime*2);
    Serial.println("Buzz HIGH");
    digitalWrite(buzzPin, LOW);
    delay(delayTime*2);  
  }

  if(ledBright < 0){
    ledBright = 0;
  }
  
  analogWrite(ledPin, ledBright);
  
}


// test
/**
int ledPin = 13;

void setup(){
  pinMode(ledPin, OUTPUT);
}

void loop(){
  digitalWrite(ledPin, HIGH);  
}

**/
