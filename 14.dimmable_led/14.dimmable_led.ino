int voltPin = A3;
int readVal = 0;
float ledBrightness = 0.00;

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
  // read the value from potetiometer
  readVal = analogRead(voltPin);
  ledBrightness = (5.00 * readVal / 1024.00) * 255 / 5;
  Serial.print("LED Brightness is ");
  Serial.println(ledBrightness);

  analogWrite(ledPin, ledBrightness);
  
  delay(delayTime);

}
