int voltPin = A3;
int readVal = 0;
float volt = 0.00;

// LED part
int ledPin = 8;


int delayTime = 1000;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  // LED part
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  readVal = analogRead(voltPin);
  volt = 5.00 * readVal / 1024.00;
  Serial.print("Potentiometer Voltage is ");
  Serial.println(volt);

  if(volt > 1.50){
    digitalWrite(ledPin, HIGH);
  }
  else{
    digitalWrite(ledPin, LOW);
  }
  delay(delayTime);

}
