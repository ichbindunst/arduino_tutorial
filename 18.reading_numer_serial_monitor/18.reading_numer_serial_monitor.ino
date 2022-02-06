
// example 1 
/**
int myNumber;
String msg = "Please Enter Your Number: ";
String msg2 = "Your Number is: ";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(msg);
  
  // Get the number of bytes (characters) available for reading from the serial port.
  //This is data that’s already arrived and stored in the serial receive buffer (which holds 64 bytes).
  while(Serial.available() == 0){

  }

  // Looks for the next valid integer in the incoming serial.
  myNumber = Serial.parseInt();
  Serial.print(msg2);
  Serial.println(myNumber);

}
*/


// example 2
/**
int numBlink;

int redPin = 13;
int delayTime = 500;


String msg = "How many blinks do you want: ";
String msgs = "Ok, the times it will blink: ";


void setup(){
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
}


void loop(){
  
  Serial.println(msg);

  while(Serial.available() == 0){

  }

  numBlink = Serial.parseInt();

  Serial.print(msgs);
  Serial.println(numBlink);

  for(int j = 0; j < numBlink; j++){
    digitalWrite(redPin, HIGH);
    delay(delayTime); 
    digitalWrite(redPin, LOW);
    delay(delayTime);   
  }


}

**/


// example 3

float radius = 0.00;
String msg = "What is the radius of your circle? ";
float area = 0.00;
String msg2 = "Your circle has area of: ";
float pi = 3.14;

void setup() {
  Serial.begin(9600);
}

void loop (){
  Serial.println(msg);

  while(Serial.available() == 0){

  }

  radius = Serial.parseFloat();
  area = radius * radius * pi;

  Serial.print(msg2);
  Serial.println(area);

}