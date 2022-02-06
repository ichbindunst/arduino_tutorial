e
/**
 * some points to mention
 * 1. The code below starts out by setting the SCP1000's configuration registers in the setup()
 * In the main loop, it sets the sensor to read in high resolution mode, meaning that 
 * it will return a 19-bit value for the pressure reading, and 16 bits for the temperature
 * 
 * 2. Then it reads the temperature's two bytes, namely 16 bits from the temperature
 * 
 * 3.  Once it's got the temperature, it reads the pressure in two parts. First it reads the highest three bits, then the lower 16 bits. 
 * It combines these two into one single long integer by bit shifting the high bits, 
 * then using a bitwise OR to combine them with the lower 16 bits
 * 
 * 4. The actual reading in degrees Celsius is the 16-bit result divided by 20
 * 
 * 5. The actual pressure in Pascal is the 19-bit result divide by 4.
 * 
 * 
 * Circuit:
 * SCP1000 sensor attached to pins 6, 7, 10 - 13:
 * DRDY: pin 6
 * CSB: pin 7     // SPI chip select
 * MOSI: pin 11
 * MISO: pin 12
 * SCK: pin 13    

. 
 */


#include <SPI.h>


// Sensors's memmory register addressed
const int PRESSURE = 0x1F;  // 3 MSBs of pressure
const int PRESSURE_LSB = 0x20;  // 16 LSBs of pressure
const int TEMPERARTURE = 0x21;  // 16 bit temperature reading

const byte READ = 0b11111100;   // SCP1000's read command
const byte WRITE = 0b00000010;  // SCP1000's write command


// pins used for the conection with the sensor
const int dataReadyPin = 6; //DRDY
const int chipSelectPin = 7;  // CSB

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

  pinMode(dataReadPin, INPUT);
  pinMode(chipSelectPin, OUTPUT):

  // configure SCP1000 for low noise configuration
  writeRegister(0x02, 0x2D);
  writeRegister(0x01, 0x03);
  writeRegister(0x03, 0x03);

  // this is important, give the sensor time to set up
  // different product may have different minimum set up time
  delay(100);

}

void loop() {
  // put your main code here, to run repeatedly:

  // select high resulution mode
  writeRegister(0x03, 0x0A);

  // don't do anything until the data ready pin is high
  if(digitalRead(dataReadyPin) == HIGH){
    
    // read the temperature's two bytes
    int tempData = readRegister(0x21, 2);
    // the actual temp equals to the value of 2-bits temperature divide 20
    float realTemp = (float)tempData / 20.0;
    Serial.print("Temp [c] = ");
    Serial.print(realTemp);

    // then read the highest 3 bits of pressure
    byte pressure_data_high = readRegister(0x1F, 1);
    // check the datasheet, only the lower 3 bits of register 0x1F will be used as the highest 3 bits of pressure
    // 'and 0' to clear the first 5 bits, only the lower 3 bits will be needed
    pressure_data_high = pressure_data_high & 0b00000111;

    // read the lower 16 bits of pressure data
    unsigned int pressure_data_low = readRegister(0x20, 2);
    // combine the higher 3 bits and lower 16 bit into one 19-bits number
    // the actual pressure data equals to the 19-bit pressure data value divide 4
    long pressure = ( (pressure_data_high << 16) | pressure_data_low ) / 4;

    Serial.println("\tPressure [Pa] = " + String(pressure));
    
  }

}


// ATTENTION! the parameter here is BYTE to read, not BIT!
unsigned int readRegister(byte thisRegister, int bytesToRead){
  byte inByte = 0;  // incomming byte from SPI
  unsigned int result = 0;

  Serial.print(thisRegister, BIN);
  Serial.print("\t");

  // only the lower 6 bits of the register will be needed
  // so shift 2 bits left
  thisRegister = thisRegister << 2;
  // and it should combine with the command READ
  // two methods to combine data
  // 'or 0' or 'and 1' bit by bit
  // here using 'and 1'
  byte dataToSend = thisRegister & READ;
  Serial.println(thisRegister, BIN);

  digitalWrite(chipSelectPin, LOW);
  SPI.transfer(dataToSend);
  // response of the that
  result = SPI.transfer(0x00);

  bytesToRead--;
  // if you still have another byte to read
  if(byteToRead > 0){
    // shift the result left 8 bit to spare the place and combine with another byte
    result = result << 8;
    inByte = SPI.transfer(0x00);
    // combine the two bytes
    result = result | inByte;
    bytesToRead--;  
  }
  
  digitalWrite(chipSelectPin, HIGH);

  return (result);
}


void writeRegister(byte thisRegister, byte thisValue){
  // SCP1000 expects only the lower 6 bits of the register address
  // so shift the bits left by two bits
  thisRegister = thisRegister << 2;

  // combine the register address and command into one byte
  // this is specified on the datasheet
  byte dataToSend = thisRegister | WRITE;   // do '0 or' bit by bit can combine data

  SPI.tranfer(dataToSend);  // send register location and WRITE command
  SPI.tranfer(thisValue);   // send value to the aim register

  digitalWrite(chipSelectPin, HIGH);
}
