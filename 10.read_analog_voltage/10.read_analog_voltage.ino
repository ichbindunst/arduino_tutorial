int readPin = A3;
int readVal = 0;
int delayTime = 0;
float Volt = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(readPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  // 10 bits ad converter i.e.
  // actual volt      output value
  //    0 V               0
  //    5 V               1023
  readVal = analogRead(readPin);
  Volt = 5.00 * readVal / 1023.00;
  Serial.println(Volt);
  delay(delayTime);
}


// then open the serial monitor