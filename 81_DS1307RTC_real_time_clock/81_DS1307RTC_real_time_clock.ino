#include <Wire.h>
#include <DS3231.h>

DS3231 clock;
RTCDateTime dt;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  Serial.println("Initialize RTC module");
  clock.begin();

  // Manual (YYYY, MM, DD, HH, II, SS);
  // clock.setDateTime(2022, 02, 14, 20, 55, 00);

  // send sketch compiling time to arduino
  clock.setDateTime(__DATE__, __TIME__);
}

void loop() {
  // put your main code here, to run repeatedly:

  dt = clock.getDateTime();

  Serial.print("Raw Data: ");
  Serial.print(dt.year); Serial.print("-");
  Serial.print(dt.month); Serial.print("-");
  Serial.print(dt.day); Serial.print(" ");
  Serial.print(dt.hour); Serial.print(":");
  Serial.print(dt.minute); Serial.print(":");
  Serial.print(dt.second); Serial.print(" ");
  Serial.println();

  delay(1000);
  

}
