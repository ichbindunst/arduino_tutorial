int trigPin = 12;
int echoPin = 11;
float pingTravelTime;
float Distance;


void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  /**
  *The basic principle of work:
  *(1) Using IO trigger for at least 10us high level signal,
  *(2) The Module automatically sends eight 40 kHz and detect whether there is a
  *pulse signal back.
  *(3) IF the signal back, through high level , time of high output IO duration is
  *the time from sending ultrasonic to returning.
  *Test distance = (high level time × velocity of sound (340M/S) / 2,
  */
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Reads a pulse (either HIGH or LOW) on a pin. 
  //For example, if value is HIGH, pulseIn() waits for the pin to go from LOW to HIGH
  pingTravelTime = pulseIn(echoPin, HIGH);

  Distance = pingTravelTime * 340.00 / 2 / 1000;
  Serial.print("The distance to the target is: ");
  Serial.print(Distance);
  Serial.println(" mm.");
  delay(1000);
  
}
