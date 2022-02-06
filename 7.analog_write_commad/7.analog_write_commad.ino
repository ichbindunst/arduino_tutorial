// 0            255
// 0 Volts      5 Volts

int redPin = 11;

void setup() {
  // put your setup code here, to run once:
  pinMode(11, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0; i < 255; i ++){
    analogWrite(redPin, i);
    delay(100);
  }
  

}
