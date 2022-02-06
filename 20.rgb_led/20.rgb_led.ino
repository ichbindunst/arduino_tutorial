// 4 Pins of RGB LED
// from shortest to longest
// blue green red GND

int redPin = 8;
int greenPin = 9;
int bluePin = 10;

String myColor;
String msg = "What color do you want? ";

void setup() {
  // put your setup code here, to run once:
  pinMode(redPin, HIGH);
  pinMode(greenPin, HIGH);
  pinMode(bluePin, HIGH);

  Serial.begin(9600);
    
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(msg);

  while(Serial.available() == 0 ){}

  myColor = Serial.readString();

  if(myColor == "red"){
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, LOW);
  }
  else if(myColor == "green"){
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, HIGH);
    digitalWrite(bluePin, LOW);  
  }
  else if(myColor == "blue"){
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, HIGH);      
  }
  else if(myColor == "off"){
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, LOW);  
  }
  else if(myColor == "aqua"){
    digitalWrite(redPin, LOW);
    analogWrite(greenPin, 255);
    analogWrite(bluePin, 80);  
  }
  else if(myColor == "yellow"){
    analogWrite(redPin, 255);
    analogWrite(greenPin, 255);
    analogWrite(bluePin, 0);  
  }
  else if(myColor == "white"){
    analogWrite(redPin, 250);
    analogWrite(greenPin, 253);
    analogWrite(bluePin, 255);  
  }
  




  
}
