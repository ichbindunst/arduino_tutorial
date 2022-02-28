// One EEPROM will be on-chip of arduino integrated
// The EEPROM of arduino UNO has a storage of 1KB = 1024,
// and the corresponding addres is 0 ~ 1023

// EEPROM is one of the standard libraries of Arduino, just like SPI
#include <EEPROM.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  // check demo1
  test1();

  float a = 3.14;   // 'a' is the data you want to store in EEPROM
  float a2 = 0;   // 'a2' is the data you read from EEPROM

  // check demo2
  // EEPROM_write(value, address);
  // '0' is the address of EEPROM
  // the range of address of EEPROM is 0 ~ 1025
  // you can store in whichever address you like
  EEPROM_write(a, 0);   

  Serial.print("float data: ");
  Serial.println(EEPROM_read(a2, 0));


  int b1=2000;
  int b2=0;
  EEPROM_write(b1,0);
  Serial.print("int data:");
  Serial.println(EEPROM_read(b2,0));
  

  long c1=65539;
  long c2=0;
  EEPROM_write(c1,0);
  Serial.print("long data:");
  Serial.println(EEPROM_read(c2,0));


  char d1[50]=__DATE__;
  char d2[50]="0";
  EEPROM_write(d1,0);
  Serial.print("string data:\n            elegoo:");
  Serial.println(EEPROM_read(d2,0));

  
}

void loop() {
  // put your main code here, to run repeatedly:

}
