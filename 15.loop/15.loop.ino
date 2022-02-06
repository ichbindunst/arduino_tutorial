int yellowPin = 6;
int redPin = 9;

int yellowDelay = 1000;
int redDelay = 1000;

void setup() {
  // put your setup code here, to run once:
  pinMode(yellowPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  for(int i = 0; i < 5; i++){
    Serial.println(i);  
    delay(200);

    digitalWrite(yellowPin, HIGH);
    delay(yellowDelay);
    digitalWrite(yellowPin, LOW);
    delay(yellowDelay);

    digitalWrite(redPin, HIGH);
    delay(redDelay);
    digitalWrite(redPin, LOW);
    delay(redDelay);
    
  }
  
  Serial.println();
}
