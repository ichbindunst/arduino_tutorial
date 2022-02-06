int tiltPin = 2;
int tiltVal;

int greenPin = 13;
int yellowPin = 12;

void setup() {
  // put your setup code here, to run once:
  pinMode(tiltPin, INPUT);
  digitalWrite(tiltPin, HIGH);

  pinMode(greenPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {

  tiltVal = digitalRead(tiltPin);
  
  Serial.println(tiltVal);
  delay(1000);

  if(tiltVal == 1){
    digitalWrite(greenPin, HIGH);
    digitalWrite(yellowPin, LOW);    
  }
  else{
    digitalWrite(yellowPin, HIGH);
    digitalWrite(greenPin, LOW);  
  }
  
}
