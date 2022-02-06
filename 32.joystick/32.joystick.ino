// x direction
int xPin = A0;
// y direction
int yPin = A1;
// switch open and off
int sPin = 2;

int xVal;
int yVal;
int sVal;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  pinMode(sPin, INPUT);
  digitalWrite(sPin, HIGH);

}

void loop() {
  // put your main code here, to run repeatedly:

  xVal = analogRead(xPin);
  yVal = analogRead(yPin);
  sVal = digitalRead(sPin);
  delay(500);

  Serial.print("X value is: ");
  Serial.print(xVal);
  Serial.print(" Y value is: ");
  Serial.print(yVal);
  Serial.print(" Switch state is: ");
  Serial.println(sVal);
  
}
