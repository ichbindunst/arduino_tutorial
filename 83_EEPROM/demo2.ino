// EEPROM.write ad EEPROM.read can oly operate single byte data like char, byte type data
// if the incoming data (such as int, float etc.) is larger than 1 byte, it will be truncated
// so when the data is larger than 1B, it needs to be read and written byte by byte

// write value to the address byte by byte
template<typename T>
void EEPROM_write(T data1, int address){
  
  union data{
    T my_type;
    // attention, in union you have to specifie the length of array
    // which means you can't use
    // char charbuf[]
    char charbuf[32];
  } data2;     // name union data as data2

  // this is the typical use method of union
  // same data, but with 2 names to distinguish
  data2.my_type = data1;

  for(int i = address; i < sizeof(data1); i++){
    EEPROM.write(i, data2.charbuf[i]);
  }
}


// read value byte by byte
template<typename T>
T EEPROM_read(T data, int address){
  
  union data{
    T my_type;
    char charbuf[32];  
  } data2;

  for(int i = address; i < sizeof(T); i++){
    data2.charbuf[i] = EEPROM.read(i);
  }

  return data2.my_type;
}
