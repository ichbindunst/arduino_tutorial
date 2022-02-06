/**
 * this programm will using IR remote sensor and remote controller to conntrol
 * the brightness and color of RGB LED
 * 
 * the brightness of rgb led can be controlled by multiply a factor to all the 
 * thress values of thr rgb led
 * 
 * rValue * brightnessfactor
 * gValue * brightnessfactor
 * bValue * brightnessfactor
 * 
 */

#include <IRremote.h>

// rgb led part
int redPin = 10;
int greenPin = 9;
int bluePin = 8;


// IR part
int irPin = 2;
IRrecv IR(irPin);
decode_results cmd;

String irCmd;
String ledColor;
float rValue = 255;
float gValue = 255;
float bValue = 255;


void setup() {
  // put your setup code here, to run once:

  // rgb led part
  pinMode(redPin, HIGH);
  pinMode(greenPin, HIGH);
  pinMode(bluePin, HIGH);


  // IR part
  IR.enableIRIn();


  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  /**
  // test color
  analogWrite(redPin, 255);
  analogWrite(greenPin, 255);
  analogWrite(bluePin, 255);  
  **/
  
  while(IR.decode(&cmd) == 0){}
  IR.resume();
  delay(1000);

  switch(cmd.value){
    case 0xFFA25D: irCmd = "POWER"; break;
    case 0xFFE21D: irCmd = "FUNC/STOP"; break;
    case 0xFF629D: irCmd = "VOL+"; break;
    case 0xFF22DD: irCmd = "FAST BACK";    break;
    case 0xFF02FD: irCmd = "PAUSE";    break;
    case 0xFFC23D: irCmd = "FAST FORWARD";   break;
    case 0xFFE01F: irCmd = "DOWN";    break;
    case 0xFFA857: irCmd = "VOL-";    break;
    case 0xFF906F: irCmd = "UP";    break;
    case 0xFF9867: irCmd = "EQ";    break;
    case 0xFFB04F: irCmd = "ST/REPT";    break;
    case 0xFF6897: irCmd = "0"; ledColor = "red"; rValue = 255; gValue = 0; bValue = 0;    break;
    case 0xFF30CF: irCmd = "1"; ledColor = "green"; rValue = 0; gValue = 255; bValue = 0;    break;
    case 0xFF18E7: irCmd = "2"; ledColor = "blue"; rValue = 0; gValue = 0; bValue = 255;   break;
    case 0xFF7A85: irCmd = "3"; ledColor = "yellow"; rValue = 255; gValue = 255; bValue = 0;   break;
    case 0xFF10EF: irCmd = "4"; ledColor = "yellow"; rValue = 255; gValue = 255; bValue = 0;   break;
    case 0xFF38C7: irCmd = "5"; ledColor = "yellow"; rValue = 255; gValue = 255; bValue = 0;   break;
    case 0xFF5AA5: irCmd = "6"; ledColor = "yellow"; rValue = 255; gValue = 255; bValue = 0;   break;
    case 0xFF42BD: irCmd = "7"; ledColor = "yellow"; rValue = 255; gValue = 255; bValue = 0;   break;
    case 0xFF4AB5: irCmd = "8"; ledColor = "yellow"; rValue = 255; gValue = 255; bValue = 0;   break;
    case 0xFF52AD: irCmd = "9"; ledColor = "yellow"; rValue = 255; gValue = 255; bValue = 0;   break;
    case 0xFFFFFFFF: irCmd = " REPEAT";break; 
    
  }

  analogWrite(redPin, rValue);
  analogWrite(greenPin, gValue);
  analogWrite(bluePin, bValue);  

  
}
