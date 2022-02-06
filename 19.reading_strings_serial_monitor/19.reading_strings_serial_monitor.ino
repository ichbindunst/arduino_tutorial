// make sure the seriel monitor has changed into "no line ending" before test


// example 1
/**
String myName;
String msg = "What is your name ";
String msg2 = "Hello ";
String msg3 = ", Welcome to Arduino! ";


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(msg); 

  while(Serial.available() == 0){

  }

  myName = Serial.readString();
  Serial.print(msg2);
  Serial.print(myName);
  Serial.print(msg3);
  Serial.println();


}
**/


// example 2

int redPin = 13;
int greenPin = 12;
int yellowPin = 11;

int delayTime(500);

String myColor;
String msg = "What color LED";
String errMsg = "You should give red, green or yellow";
String msg2 = "The color you choose: ";

void setup(){
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);

  Serial.begin(9600);
}


void loop(){

  Serial.println(msg);

  while(Serial.available() == 0){

  }

  myColor = Serial.readString();

  Serial.print(msg2);
  Serial.println(myColor);

  if(myColor == "red"){
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, LOW);
    digitalWrite(yellowPin,LOW);
  }
  if(myColor == "green"){
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, HIGH);
    digitalWrite(yellowPin,LOW);
  }
  if(myColor == "yellow"){
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(yellowPin, HIGH);
  }
}
