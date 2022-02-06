/*
 * this programm should be excuted with 2 arduino boards
 * this is the receiver part, the other please refer to 'controller_writer_sketch'
 * this is the slave programm
 */

#include <Wire.h>

void setup() {
  // put your setup code here, to run once:
  Wire.begin(4);  // join I2C bus with address #4

  // registe a function to be called when a slave device receives a transmission form a master
  // receiveEvent: function to be called when receive a transmission
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(100);
}

void receiveEvent(int howMany){

  // Wire.available() returns the number of BYTES available for reading
  while(Wire.available() > 1){
     char c = Wire.read();
     Serial.print(c);
  }

  int x = Wire.read();
  Serial.println(x)M
}
