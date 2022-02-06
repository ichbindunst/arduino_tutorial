int voltPin = A3;
int readVal;
float volt = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  readVal = analogRead(voltPin);
  volt = 5.00 * readVal / 1024.00;
  Serial.print("volt = ");
  Serial.println(volt);
  delay(1000);
}
