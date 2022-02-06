int buzzPin = 8;
int potPin = A5;

int potVal = 0;
int toneVal = 0;

// you can control the tone of buzzer by changing the delaytime
//int buzzTime = 5;


String msg = "Please give the order: go or off";
String order;

void setup() {
  // put your setup code here, to run once:
  pinMode(buzzPin, OUTPUT);
  pinMode(potPin, INPUT);

  //Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  //Serial.println(msg);

  //while(Serial.available()== 0){}
  
  //order = Serial.readString();

  //Serial.print("you said ");
  //Serial.println(order);

  potVal = analogRead(potPin);
  toneVal = (9940./1023.)*potVal + 60;

  //if(order == "go"){
    digitalWrite(buzzPin, HIGH);
    delayMicroseconds(toneVal);
    //delay(buzzTime);
    digitalWrite(buzzPin, LOW);
    delayMicroseconds(toneVal);
    //delay(buzzTime);
  //}

  //if (order == "off"){
    //digitalWrite(buzzPin, LOW);  
  //}
  
}
