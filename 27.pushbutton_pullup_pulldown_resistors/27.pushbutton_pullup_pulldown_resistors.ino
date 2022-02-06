
// example 1: button_pullup_pulldown_resistor
/**
int ledPin = 2;
int buttonPin = 12;

int buttonRead;

int delayTime = 500;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonRead = digitalRead(buttonPin);
  Serial.println(buttonRead);
  delay(delayTime);

  if(buttonRead == 0){
    digitalWrite(ledPin, HIGH);
  }
  else if(buttonRead == 1){
    digitalWrite(ledPin, LOW);
  }
}
**/


// example 2. pushbutton as toggle switch
/**
int ledState = 0;
int ledPin = 2;
int buttonPin = 12;

int buttonOld = 0;
int buttonNew;

int delayTime = 100;

void setup(){
  Serial.begin(9600);  
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}


void loop(){
    buttonNew = digitalRead(buttonPin);
    Serial.println(buttonNew);
    
    if(buttonOld==0 && buttonNew==1 ){
       
       if(ledState == 0){
          digitalWrite(ledPin, HIGH); 
          ledState = 1;
       }
       else{
          digitalWrite(ledPin, LOW);
          ledState = 0;
       } 
    }

    buttonOld = buttonNew;
    delay(delayTime);
}
**/
