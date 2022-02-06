#include <Wire.h>

void setup() {
  // put your setup code here, to run once:
  Wire.begin();
}

byte val = 0;

void loop() {
  // put your main code here, to run repeatedly:

  // please refer to datasheet I2C controller programming write part
  Wire.beginTransmission(44); // transmit to device #44(0x2c)
                              // this devie is specified in datasheet
                              // 0b0010110x, x -> AD0, allows a maximum of two AD5171 to be addressed
  Wire.write(byte(0x00));     // send instruction byte, according to datasheet, this par should not be cared
  Wire.write(val);            // send potentiometer value
  Wire.endTransmission();

  val++;
  if(val == 64){  // if reached 64th position (max)
                  // AD5171 is a 64-Position OTP Digital Potentiometer
    val = 0;
  }
  delay(500);  
}
