/*
 * this programm should be excuted with 2 arduino boards
 * this is the writer part, the other please refer to 'periperal_receiver_sketch'
 * this is the master / controller programm
 */

#include <Wire.h>

void setup() {
  // put your setup code here, to run once:
  Wire.begin();   // join the I2C bus
  Serial.begin(9600);
}

byte x = 0;

void loop() {
  // put your main code here, to run repeatedly:
  Wire.beginTransmission(4);  // transmit to device #4

  //Wire.write(value), value: a value to send as a single byte
  Wire.write("x is ");    // Send 5 bytes, ATTENTION, BYTES!!
  Wire.write(x);          // Send one byte
  Wire.endTransmission();

  x++;
  delay(500);
}
