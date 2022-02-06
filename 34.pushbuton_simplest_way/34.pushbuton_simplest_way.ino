int switchPin = 2;
int switchValue;


void setup() {
  // put your setup code here, to run once:
  pinMode(switchPin, INPUT);
  digitalWrite(switchPin, HIGH);
  Serial.begin(9600);

  
}

void loop() {
  // put your main code here, to run repeatedly:

  switchValue = digitalRead(switchPin);

  Serial.print("Your button is: ");
  Serial.println(switchValue);

  delay(1000);
  
}
