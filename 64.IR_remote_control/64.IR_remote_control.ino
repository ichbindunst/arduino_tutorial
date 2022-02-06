#include <IRremote.h>

int IRpin = 9;

// initiate the receiving IR
IRrecv IR(IRpin);
// results returned from the decoder
decode_results cmd;


void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);

  IR.enableIRIn();
  
}

void loop() {
  // put your main code here, to run repeatedly:
  while(IR.decode(&cmd) == 0){}

  // press the button, serial monitor will show the cmd.value 
  Serial.println(cmd.value, HEX);
  delay(1000);

  IR.resume();

  // till now, 
  // press the remote controller and the value should be should in the serial monitor
  // *****************************

  // how to use the remote controller to control something
  switch(cmd.value)
    {
    case 0xFFA25D: Serial.println("POWER"); break;
    case 0xFFE21D: Serial.println("FUNC/STOP"); break;
    case 0xFF629D: Serial.println("VOL+"); break;
    case 0xFF22DD: Serial.println("FAST BACK");    break;
    case 0xFF02FD: Serial.println("PAUSE");    break;
    case 0xFFC23D: Serial.println("FAST FORWARD");   break;
    case 0xFFE01F: Serial.println("DOWN");    break;
    case 0xFFA857: Serial.println("VOL-");    break;
    case 0xFF906F: Serial.println("UP");    break;
    case 0xFF9867: Serial.println("EQ");    break;
    case 0xFFB04F: Serial.println("ST/REPT");    break;
    case 0xFF6897: Serial.println("0");    break;
    case 0xFF30CF: Serial.println("1");    break;
    case 0xFF18E7: Serial.println("2");    break;
    case 0xFF7A85: Serial.println("3");    break;
    case 0xFF10EF: Serial.println("4");    break;
    case 0xFF38C7: Serial.println("5");    break;
    case 0xFF5AA5: Serial.println("6");    break;
    case 0xFF42BD: Serial.println("7");    break;
    case 0xFF4AB5: Serial.println("8");    break;
    case 0xFF52AD: Serial.println("9");    break;
    case 0xFFFFFFFF: Serial.println(" REPEAT");break;  
    default: 
      Serial.println(" other button   ");
  
   }
   
}
