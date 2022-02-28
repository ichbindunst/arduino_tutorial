// if you just wanna show something once
// do it in the 'void setup(){}' part

void test1(void){
  char company[7] = {"elegoo"};
  char company2[7] = {"0"};

  for(int i = 0; i < 6; i++){

    // EEPROM.write(address, value);
    // address: the location to write to, starting form 0(int)
    // value: the value to write, from 0 to 255 (byte)

    // write the data in company[i] to the address i
    // write the value byte by byte
    // attention, the address of integrated EEPROM on arduino UNO is 0 ~ 1024
    // each number means one byte
    EEPROM.write(i, company[i]);
  }

  for(int i = 0; i < 6; i++){
    // EEPROM.read(address)
    // return the value stored in that location
    // read the data at the address i of EEPROM
    company2[i] = EEPROM.read(i);
  }

  Serial.print("company: ");
  Serial.println(company2);
  Serial.println("***************************************");
}
