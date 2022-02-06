int latchPin = 11;
int clockPin = 9;
int dataPin = 12;


byte LEDs = 0xFF;
byte offLED = 0x00;

String command;

byte LED1 = 0b00000000;
byte LED2 = 0b01010101;


void setup() {
  // put your setup code here, to run once:

  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);

  Serial.begin(9600);
}


void loop() {
  // put your main code here, to run repeatedly:

  while(Serial.available()==0){}

  command = Serial.readString();

  if(command == "off"){
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, offLED);
    digitalWrite(latchPin, HIGH);
  }
  else{

    for(int i = 0; i < 128; i++){
      // latch pin low, put the data in
      digitalWrite(latchPin, LOW);
      
      // send the data
      // Shifts out a byte of data one bit at a time. 
      // Starts from either the most (i.e. the leftmost) or least (rightmost) significant bit
      // shiftOut(dataPin, clockPin, bitOrder, value)
      shiftOut(dataPin, clockPin, LSBFIRST, LED1);
  
      // set latch pin high to latch the value
      digitalWrite(latchPin, HIGH);

      LED1 = LED1 + 1;
      
      delay(1000);  
    }
    
    



    
  }

}