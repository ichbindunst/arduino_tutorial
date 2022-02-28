// PIR sensor -> Passive Infrarot Sensor
// Passive infrared (PIR) sensors use a pair of pyroelectric sensors to detect heat energy in the surrounding environment. 

// ATTENTION!! The device requires nearly a minute to iitialize!

int ledPin = 13; // if it's detected, LED light up
int pirPin = 7;  // HC-S501 input pin

int pirValue;   // feedback of detection


void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(pirPin, INPUT);
  digitalWrite(ledPin, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  pirValue = digitalRead(pirPin);
  digitalWrite(ledPin, pirValue);
}
