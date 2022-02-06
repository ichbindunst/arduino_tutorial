/*
 * this programm should be excuted with 2 arduino boards
 * this is the sender part, the other please refer to 'controller_reader_sketch'
 * this is the slave programm
 */

#include <Wire.h>

void setup() {
  // put your setup code here, to run once:
  Wire.begin(8);  // join the I2C bus with address #8
  
  // registe a function to be called when a master request shows
  // requestEvent: the function to be called, takes no parameters and returns nothing
  // e.g. void requestEvet()
  Wire.onRequest(requestEvent);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(100);
}

void requestEvent(){

  // Wire.write(string)
  // string: a string to send as a series of bytes
  // ATTENTION! Here is BYTE! not BIT!
  Wire.write("hello ");   // respond with message of 6 bytes
  // as expected by master
}
