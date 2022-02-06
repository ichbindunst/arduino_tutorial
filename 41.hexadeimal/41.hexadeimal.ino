// a byte stores an 8-bit unsigned number, from 0 to 255
byte myByte = 0;
byte myByte2 = B00001111;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(myByte, HEX);
  Serial.print("  ");
  Serial.print(myByte2, BIN);
  Serial.print("  ");
  Serial.print(myByte2, DEC);
  Serial.println("  ");
  
  myByte = myByte + 1;
  myByte2 = myByte2 + 1;
  delay(1000);

}
