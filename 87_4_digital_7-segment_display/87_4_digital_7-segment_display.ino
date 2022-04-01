// in principle, we can only enable one digital 7 segment at once (check internal circuit)
// but with the persistence of vision, we can see multiple digital 7 segments at once
// with the delay of 5 ms

// article of this 4 digital 7-segment display: 5643A
// Dx (x = 1, 2, 3, 4) of used segment should keep low
// here use all four segments

// 74HC595 shift register will be used in this programm
/**
 * Conect methond
 * |           |16 -> Vcc -> high
 * |           |15 -> QA 
 * |           |14 -> SER(data pin) -> Pin8
 * |           |13 -> OE(low active, output enable) -> Low
 * |           |12 -> RCL(latch pin) -> Pin9
 * |           |11 -> SRCLK(clock pin) -> Pin10
 * |           |10 -> SRCLE(low active, clear) -> high
 * |___________|9
 *    74hc595
 */


// connection 
/*
 * A -- Q0
 * B -- Q1
 * C -- Q2
 * D -- Q3
 * E -- Q4
 * F -- Q5
 * G -- Q6
 * D1, D2, D3, D4 -- 220 Ohm -- GND
 * DP -- Q7
 * DP: decimal point of display
 */

 
int latch = 9;
int clockPin = 10;
int data = 8;

unsigned char table[]=
{0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c
,0x39,0x5e,0x79,0x71,0x00};//Display digital data

void setup() {
  // put your setup code here, to run once:
  pinMode(latch, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(data, OUTPUT);
}

/*   The most common method of using 74CH595
 *   latch->LOW : Begin transmitting signals.
 *   shiftOut(dataPin, clockPin, bitOrder, value)
 *   dataPin: the pin on which to output each bit. Allowed data types: int.
 *   clockPin: the pin to toggle once the dataPin has been set to the correct value. Allowed data types: int.
 *   bitOrder: which order to shift out the bits; either MSBFIRST or LSBFIRST. (Most Significant Bit First, or, Least Significant Bit First).
 *   value: the data to shift out. Allowed data types: byte. 
 *   latch->HIch : The end of the transmission signal.
*/

void loop() {
  // put your main code here, to run repeatedly:
  Display(1);
  delay(500);
  Display(2);
  delay(500);
  Display(3);
  delay(500);
  Display(4);
  delay(500);
  Display(5);
  delay(500);
  Display(6);
  delay(500);
  Display(7);
  delay(500);
  Display(8);
  delay(500);
  Display(9);
  delay(500);
  Display(10);
  delay(500);
  Display(11);
  delay(500);
  Display(12);
  delay(500);
  Display(13);
  delay(500);
  Display(14);
  delay(500);
  Display(15);
  delay(500); 
}

void Display(unsigned char num){

  digitalWrite(latch, LOW);
  shiftOut(data, clockPin, MSBFIRST, table[num]);
  digitalWrite(latch, HIGH);
}
