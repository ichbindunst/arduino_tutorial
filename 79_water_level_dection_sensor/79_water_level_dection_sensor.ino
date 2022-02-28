// the sensor will sense the water level
// output to A0

int sensingPin = A0;
int historyValue = 0;

// strong the value
char printBuffer[128];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  
  int value = analogRead(sensingPin);

  // if the water level changes, change the history value of it
  // set the condition when change value
  // if the water level dont change, the value will not change!!!
  if( ((historyValue>=value) && (historyValue - value >10)) || ((historyValue < value) && ((value - historyValue) > 10))){
    // convert binary numbers in 'sensingPin' and value into strings
    // store the whole string in printBuffer
    
    //sprintf(printBuffer, "Binary value %d means the level is %d\n", sensingPin, value);
    //Serial.print(printBuffer);
    
    Serial.println(value);
    historyValue = value;
  }

  delay(500);
}
