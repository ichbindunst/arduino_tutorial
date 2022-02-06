int potPin = A0;
int redPin = 8;

int potVal = 0;
int delayTime = 1000;

void setup() {
  // put your setup code here, to run once:
  pinMode(potPin, INPUT);
  pinMode(redPin, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  potVal = analogRead(potPin);
  Serial.print("potVal = ");
  Serial.println(potVal);
  delay(delayTime);

  while(potVal > 500){
    digitalWrite(redPin, HIGH);
  }

}
