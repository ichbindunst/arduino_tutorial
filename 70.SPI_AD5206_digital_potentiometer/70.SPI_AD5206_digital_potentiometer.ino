/*


  Digital Pot Control


  This example controls an Analog Devices AD5206 digital potentiometer.


  The AD5206 has 6 potentiometer channels. Each channel's pins are labeled


  A - connect this to voltage


  W - this is the pot's wiper, which changes when you set it


  B - connect this to ground.


 The AD5206 is SPI-compatible,and to command it, you send two bytes,


 one with the channel number (0 - 5) and one with the resistance value for the


 channel (0 - 255).


 The circuit:


  * All A pins  of AD5206 connected to +5V


  * All B pins of AD5206 connected to ground


  * An LED and a 220-ohm resisor in series connected from each W pin to ground


  * CS - to digital pin 10  (SS pin)


  * SDI - to digital pin 11 (MOSI pin)


  * CLK - to digital pin 13 (SCK pin)


 created 10 Aug 2010


 by Tom Igoe


 Thanks to Heather Dewey-Hagborg for the original tutorial, 2005


*/

#include <SPI.h>

  // cause pin10 on the arduion is the SPI SS channel
  // and this Pin10 on the arduion will connect to pin4 of the AD5206, which is the ihp chip select input pin, low active
  // so set the chip select pin at Pin10 of arduino
const int chipSelectPin = 10;

void setup() {
  // put your setup code here, to run once:

  pinMode(chipSelectPin, OUTPUT);

  SPI.begin();

}

void loop() {
  // put your main code here, to run repeatedly:

  // go through the six channels of the digital pot
  for(int channel = 0; channel < 6; chanel++){
    // change the potentio level on this channel from min to max
    for(int level = 0; level < 255; level++){
      digitalPotWrite(channel, level); 
      delay(10);  
    } 

    delay(100);

    // change the potentio level on this channel from max to min
    for(int level = 0; level < 255; level++){
      digitalPotWrite(channel, 255 - level);
      delay(10);  
    }
  }    

}

void digitalPotWrite(int address, int value){
  // take the SS pin low to select the chip
  digitalWrite(chipSelectPin, LOW);
  delay(100);

  // send in the address and value via spi  
  SPI.transfer(address);
  SPI.transfer(value);
  delay(100);

  // take the SS pin high to de-select the chip
  digitalWrite(chipSelectPin, HIGH);

}
