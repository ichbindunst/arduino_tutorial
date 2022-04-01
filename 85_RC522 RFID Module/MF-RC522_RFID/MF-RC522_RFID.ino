// This program shows how to set the UID on a UID changeable MIFARE card
// using the MIFARE card and transponser to the signal reveiver, it will show  different IDs on the monitor
// UID: Unique Identification Numbers
// RFID: Radio Frequence Identification
// RC522 github library: https://github.com/miguelbalboa/rfid/blob/master/src/MFRC522.h


#include <SPI.h>
#include "MFRC522.h"

#define SS_PIN 10
#define RST_PIN 7

MFRC522 rfid(SS_PIN, RST_PIN);   // instance of the class

// ??????????useless??
MFRC522::MIFARE_Key key;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();  // init R522
}

void loop() {
  // put your main code here, to run repeatedly:

  //reset the loop if no new ccard present on the sensor/reader. 
  // This saves the entire process when idle
  if(!rfid.PICC_IsNewCardPresent()){
    return ;
  }

  // verifz if the NUID has bee readed
  if(!rfid.PICC_ReadCardSerial()){
    return ;
  }

  MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);

  Serial.print("RFID Tag UID: ");
  // create a function printHex
  printHex(rfid.uid.uidByte, rfid.uid.size);
  Serial.println(" ");

  // halt PICC
  rfid.PICC_HaltA();
}


// routie to dump a byte array as hex values to Serial
void printHex(byte *buffer, byte bufferSize){
  for(byte i = 0; i < bufferSize; i++){
    Serial.print(buffer[i] < 0x10 ? "0" : " ");
    Serial.print(buffer[i], HEX);
  }
}
