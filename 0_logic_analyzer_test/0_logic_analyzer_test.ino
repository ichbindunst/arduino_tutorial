int yellowPin = 2;
int greenPin = 3;
int redPin = 4;
int bluePin = 5;

String myColor;

void setup() {
  // put your setup code here, to run once:
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

    while(Serial.available() == 0){
    }

    myColor = Serial.readString();


    
    if(myColor == "red"){
      digitalWrite(redPin, HIGH);
      digitalWrite(greenPin, LOW);
      digitalWrite(yellowPin,LOW);
      digitalWrite(bluePin,LOW);
    }
    if(myColor == "green"){
      digitalWrite(redPin, LOW);
      digitalWrite(greenPin, HIGH);
      digitalWrite(yellowPin,LOW);
      digitalWrite(yellowPin,LOW);
    }
    if(myColor == "yellow"){
      digitalWrite(redPin, LOW);
      digitalWrite(greenPin, LOW);
      digitalWrite(yellowPin, HIGH);
      digitalWrite(yellowPin,LOW);
    }
    
    /**
    if (On == "ok"){
      digitalWrite(yellowPin, HIGH);
      delay(100);
      digitalWrite(yellowPin, LOW);
      delay(100);
    
      digitalWrite(greenPin, HIGH);
      delay(100);
      digitalWrite(greenPin, LOW);
      delay(100);
    
      digitalWrite(redPin, HIGH);
      delay(100);
      digitalWrite(redPin, LOW);
      delay(100);
    
      digitalWrite(bluePin, HIGH);
      delay(100);
      digitalWrite(bluePin, LOW);
      delay(100);
    }
    else{
      digitalWrite(yellowPin, LOW);
      digitalWrite(greenPin, LOW);
      digitalWrite(redPin, LOW);
      digitalWrite(bluePin, LOW);
    }

    Serial.println(On);
    delay(1000);
    **/
    
  
}
