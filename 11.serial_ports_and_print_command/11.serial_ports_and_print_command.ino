// the baud rate of EDI and serial port has to be the same
// print will not change the line automatically
// println will change the line automatically

int j = 1;
int waitTime = 750;
String myString = "j =  ";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  Serial.print(myString);
  Serial.println(j);
  
  j = j + 1;
  delay(waitTime);

}
