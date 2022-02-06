// before use, download the DHT sensor library into the arduino preference directory

#include <DHT.h>

#define Type DHT11

int sensePin = 2;

DHT HT(sensePin, Type);

float humidity;
float tempC;
float tempF;



void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  HT.begin();
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:

  humidity = HT.readHumidity();  

  tempC = HT.readTemperature();
  tempF = HT.readTemperature(true);

  Serial.print("Humidity (%): ");
  Serial.print(humidity);
  Serial.print(" Temperature C: ");
  Serial.print(tempC);
  Serial.print(" C ");
  Serial.print(tempF);
  Serial.println(" F ");
  delay(1000);

}
