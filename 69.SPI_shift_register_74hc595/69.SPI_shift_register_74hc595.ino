/**
 * Conect methond
 * |           |16 -> Vcc -> high
 * |           |15 -> QA 
 * |           |14 -> SER(data pin) -> Pin11
 * |           |13 -> OE(low active, output enable) -> Low
 * |           |12 -> RCL(latch pin) -> Pin2
 * |           |11 -> SRCLK(clock pin) -> Pin13
 * |           |10 -> SRCLE(low active, clear) -> high
 * |___________|9
 *    74hc595
 */


/**
 * with SPI to transmit data to fulfill the 8 bit register 74hc595
 * the LEDs will be lighted from the LSB to MSB
 */

 
#include <SPI.h>

int slaveSelect = 2;

// important is that the delay time should be relative small
// otherwise you cant see the result that great
int delayTime = 50;

void setup() {
  pinMode(slaveSelect, OUTPUT);
  SPI.begin();
  SPI.setBitOrder(LSBFIRST);   
}

void loop() {
  for (int i=0; i < 256; i++)        //For loop to set data = 0 then increase it by one for every iteration of the loop, when the counter reaches the condition (256) it will be reset
  {
    digitalWrite(slaveSelect, LOW);            //Write our Slave select low to enable the SHift register to begin listening for data
    SPI.transfer(i);                     //Transfer the 8-bit value of data to shift register, remembering that the least significant bit goes first
    digitalWrite(slaveSelect, HIGH);           //Once the transfer is complete, set the latch back to high to stop the shift register listening for data
    delay(delayTime);                             //Delay
  }
}
