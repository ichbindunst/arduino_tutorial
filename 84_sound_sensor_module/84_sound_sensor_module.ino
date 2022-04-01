/*
  LED1 should be lit, showing power. LED2 indicates sound input, and the sensitivity is adjusted by potentiometer.
  There is a tiny screw on the blue potentiometer block that you can use for adjustment. Turning that
  clockwise lowers the potentiometer value, while counter-clockwise raises the potentiometer value.
  Use the potentiometer to adjust the Sound Sensor sensitivity. Turn the potentiometer
  several rotations until you see the LED2 blink. if you are also watching Serial Monitor (inital adjustment), or, Serial Plotter (the latter is prefererd for observation).
*/

// when you speak, led13 should be on

int sensorAnalogPin = A0;
int sensorDigitalPin = 3;
int analogValue = 0;
int digitalValue;
int Led13 = 13;         // Define LED port; this is the LED built in to the Arduino (labled L)
                        // When D0 from the Sound Sensor (connnected to pin 7 on the
                        // Arduino) sends High (voltage present), L will light up. In practice, you
                        // should see LED13 on the Arduino blink when LED2 on the Sensor is 100% lit.
                        

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(sensorDigitalPin, INPUT);
  pinMode(Led13, OUTPUT);

  
}

void loop() {
  // put your main code here, to run repeatedly:

  analogValue = analogRead(sensorAnalogPin);
  digitalValue = digitalRead(sensorDigitalPin);
  Serial.print("analog value is: ");
  Serial.println(analogValue);

  if(digitalValue == HIGH){
    digitalWrite(Led13, HIGH);
  }
  else{
    digitalWrite(Led13, LOW);
  }

  delay(200);
  

}
