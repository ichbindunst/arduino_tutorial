/*
 * this programm should be excuted with 2 arduino boards
 * this is the reader part, the other please refer to 'periperal_sender_sketch'
 * this is the master / controller programm
 */

#include <Wire.h>

void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  /*
   * Wire.requestFrom(address, quantity);
   * address: te 7-bit address of device, 
   * ATTENTION; in I2C, the device address is the first 7bits of the original reigster address
   * there will be one bit left to show 'read' or 'write' command
   * quantity: the number of bytes to request
   * ATTENTION: here is BYTE! not BIT!
   */
  Wire.requestFrom(8, 6); // requst 6 bytes from peripheral device on the I2C bus #8

  while(Wire.available()){
    // Wire.read() returns the next byte received
    char c = Wire.read();   // receive a byte as character
    Serial.print(c);
  }
  delay(500);
}
