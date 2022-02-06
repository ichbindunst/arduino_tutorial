#include <Wire.h>

int reading = 0;

void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  // step1: instruct sensor to read echos
  Wire.beginTransmission(112);  // transmit to device #112(0x70) 0x11100000
  // the address specified in the datasheet is 0xE0
  // but I2C addressing used the high 7 bits, so it's 112, the last bit 0 is write command

  // please check the datasheet, chapter "Änderun"
  Wire.write(0x00);   // every single byte should be send to the command register first
  Wire.write(byte(0x50));   // measure in "inches"
  // use 0x51 in centimeter
  // use 0x52 for ping microseconds
  Wire.endTransmission();

  // step2: waiting for reading to happen
  delay(70);

  // step3: instruct sensor toreturn a particular echo reading
  Wire.beginTransmission(112);  // device address and write bit
  Wire.write(0x02);   // set register pointer to echo register1 0x00000010
  Wire.endTransmission();

  // step4: request reading form sensor
  // receiving data always use Wire.requestFrom
  Wire.requestFrom(112, 2);   // request 2 bytes from peripheral devicce

  // step5. reveive reading from sensor
  if(Wire.available() >= 2){
    reading = Wire.read;
    reading = reading << 8;   // shift 8 bit, spare room for next byte and combine
    reading |= Wire.read();  
    Serial.println(reading);
  }
  delay(250);
}


/*
// The following code changes the address of SRF10
// Please check the datasheet "Änderung der I2C Slave ID"

void changeAddress(byte oldAddress, byte newAddress){
  Wire.beginTransmission(oldAddress);
  Wire.write(byte(0x00));   // every single bytes should be send first to the command register -> register 0
  Wire.write(byte(0xA0));
  Wire.endTransmission();

  Wire.beginTransmission(oldAddress);
  Wire.write(byte(0x00));   // every single bytes should be send first to the command register -> register 0
  Wire.write(byte(0xAA));
  Wire.endTransmission();

  Wire.beginTransmission(oldAddress);
  Wire.write(byte(0x00));   // every single bytes should be send first to the command register -> register 0
  Wire.write(byte(0xA5));
  Wire.endTransmission();

  Wire.beginTransmission(oldAddress);
  Wire.write(byte(0x00));   // every single bytes should be send first to the command register -> register 0
  Wire.write(byte(newAddress));
  Wire.endTransmission();
  
    
}
*/   



 
