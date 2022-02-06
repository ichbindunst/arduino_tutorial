// example 1
/**
// int myNumb = 0;
int potVal;
int potPin = A5;
int buzzPin = 8;

int delayTime = 2000;

String msg = "Please input your number: ";


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(buzzPin, OUTPUT);
  pinMode(potPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //Serial.println(msg);

  //while(Serial.available() == 0){}

  //myNumb = Serial.parseInt();
  potVal = analogRead(potPin);
  Serial.println(potVal);

  if(potVal > 800){
    digitalWrite(buzzPin, HIGH);
    delay(delayTime); 
    digitalWrite(buzzPin, LOW);
    delay(delayTime); 
  }  

  
}
**/


// example 2: changing tone of an active buzzer
int buzzPin = 8;

int delayTime1 = 1;
int delayTime2 = 2;

void setup(){
  pinMode(buzzPin, OUTPUT);  
}

void loop(){
    
  for(int j = 0; j < 100; j=j+1){
    digitalWrite(buzzPin, HIGH);
    delay(delayTime1);
    digitalWrite(buzzPin, LOW);
    delay(delayTime1);
  }

  for(int j = 0; j < 100; j=j+1){
    digitalWrite(buzzPin, HIGH);
    delay(delayTime2);
    digitalWrite(buzzPin, LOW);
    delay(delayTime2);  
  }
}
