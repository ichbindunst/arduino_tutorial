#include <LedControl.h>

// pin12 is connected to the dataIn
// pin11 is connected to CS
// pin10 is connected to CLK

// LedControl(int dataPin, int clkPin, int csPin, int numDevices=1);
LedControl lc = LedControl(12, 10, 11, 1);

unsigned long delaytime1 = 500;
unsigned long delaytime2 = 50;

void setup() {
  // put your setup code here, to run once:

  // set the shutdown mode for the device
  // void shutdown(int addr, bool status);
  // the MAX72xx is in power-savig mode on startup, we have to wake it up 
  // set to false for normal operation, if true then the device goes into power-down mode
  lc.shutdown(0, false);

  lc.setIntensity(0, 8);
  lc.clearDisplay(0);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  
  writeArduinoOnMatrix();
  rows();
  columns();
  single();
}

// show the 'a' 'r' 'd' 'u' 'i' 'n' 'o'
void writeArduinoOnMatrix() {
  /* here is the data for the characters */
  // binary code, all 128 charaters, 1 means light, 0 means dont light
  byte a[5]={B01111110,B10001000,B10001000,B10001000,B01111110};
  byte r[5]={B00010000,B00100000,B00100000,B00010000,B00111110};
  byte d[5]={B11111110,B00010010,B00100010,B00100010,B00011100};
  byte u[5]={B00111110,B00000100,B00000010,B00000010,B00111100};
  byte i[5]={B00000000,B00000010,B10111110,B00100010,B00000000};
  byte n[5]={B00011110,B00100000,B00100000,B00010000,B00111110};
  byte o[5]={B00011100,B00100010,B00100010,B00100010,B00011100};

  /* now display them one by one with a small delay */
  // address, row, byte value
  lc.setRow(0,0,a[0]);
  lc.setRow(0,1,a[1]);
  lc.setRow(0,2,a[2]);
  lc.setRow(0,3,a[3]);
  lc.setRow(0,4,a[4]);
  delay(delaytime1);
  lc.setRow(0,0,r[0]);
  lc.setRow(0,1,r[1]);
  lc.setRow(0,2,r[2]);
  lc.setRow(0,3,r[3]);
  lc.setRow(0,4,r[4]);
  delay(delaytime1);
  lc.setRow(0,0,d[0]);
  lc.setRow(0,1,d[1]);
  lc.setRow(0,2,d[2]);
  lc.setRow(0,3,d[3]);
  lc.setRow(0,4,d[4]);
  delay(delaytime1);
  lc.setRow(0,0,u[0]);
  lc.setRow(0,1,u[1]);
  lc.setRow(0,2,u[2]);
  lc.setRow(0,3,u[3]);
  lc.setRow(0,4,u[4]);
  delay(delaytime1);
  lc.setRow(0,0,i[0]);
  lc.setRow(0,1,i[1]);
  lc.setRow(0,2,i[2]);
  lc.setRow(0,3,i[3]);
  lc.setRow(0,4,i[4]);
  delay(delaytime1);
  lc.setRow(0,0,n[0]);
  lc.setRow(0,1,n[1]);
  lc.setRow(0,2,n[2]);
  lc.setRow(0,3,n[3]);
  lc.setRow(0,4,n[4]);
  delay(delaytime1);
  lc.setRow(0,0,o[0]);
  lc.setRow(0,1,o[1]);
  lc.setRow(0,2,o[2]);
  lc.setRow(0,3,o[3]);
  lc.setRow(0,4,o[4]);
  delay(delaytime1);
  lc.setRow(0,0,0);
  lc.setRow(0,1,0);
  lc.setRow(0,2,0);
  lc.setRow(0,3,0);
  lc.setRow(0,4,0);
  delay(delaytime1);
}


// this function lights up some leds in a row
void rows(){

  // LED at B10100000 will blink
  for(int row = 0; row < 8; row++){
    delay(delaytime2);
    lc.setRow(0, row, B10100000);
    delay(delaytime2);
    lc.setRow(0, row, B00000000);
    for(int i = 0; i < row; i++){
      delay(delaytime2);
      lc.setRow(0, row, B10100000);
      delay(delaytime2);
      lc.setRow(0, row, B00000000);
    }
  }
}


// this function lights up some leds in column
void columns(){
  for(int col = 0; col < 8; col++){
    delay(delaytime2);
    lc.setColumn(0, col, B10100000);
    delay(delaytime2);
    lc.setColumn(0, col, B00000000);
    for(int i = 0; i < col; i++){
      delay(delaytime2);
      lc.setColumn(0, col, B10100000);
      delay(delaytime2);
      lc.setColumn(0, col, B00000000);
    }
  }
}

// this function will light up every LED on the matrix
void single(){
  for(int row = 0; row < 8; row++){
    for(int col = 0; col < 8; col++){
      delay(delaytime2);
      lc.setLed(0, row, col, true);
      delay(delaytime2);
      
    }
  }  
}
