// MPU6050 can be as a accelerometer, gyro, magnetomete and altimeter
// in gy-521 can also be used to measure temperature


#include <Wire.h>

// check datasheet 6.4
const int MPU_addr = 0x68;  // I2C address of MPU-6050
int16_t AcX, AcY, AcZ, Temp, GyX, GyY, GyZ;

void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  Wire.beginTransmission(MPU_addr);

  // check MPU6050 register map page 8
  Wire.write(0x6B);   // PWR_MGMT_1 register

  // check MPU6050 register map page40
  Wire.write(0);  // set to zero to wake up MPU-6050 and clear up all the settings before
  Wire.endTransmission(true);   // true: tranmission finished  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  // the register accelerometer, gyro and temperature are all read-only
  Wire.beginTransmission(MPU_addr);
  // ACCEL_XOUT_H, accelerometer measurement
  // starting with register 0x38 (register 59)
  Wire.write(0x3B);   // check register map 4.17
  Wire.endTransmission(false);  // restart transmission -> Wire.beginTransmission(MPU_addr);

  // request 14 bit. 6 bits Acceleration, 2 Bits temperature, 6 bits gyroscope
  Wire.requestFrom(MPU_addr, 14, true); // true: stop sending message after the request, false: restart
  
  AcX=Wire.read()<<8|Wire.read(); // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)
  AcY=Wire.read()<<8|Wire.read();  // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
  AcZ=Wire.read()<<8|Wire.read();  // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
  Temp=Wire.read()<<8|Wire.read();  // 0x41 (TEMP_OUT_H) & 0x42 (TEMP_OUT_L), check register map 4.18
  GyX=Wire.read()<<8|Wire.read();  // 0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L)
  GyY=Wire.read()<<8|Wire.read();  // 0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L)
  GyZ=Wire.read()<<8|Wire.read();  // 0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L), check register map 4.19

  Serial.print("AcX = "); Serial.print(AcX);
  Serial.print(" | AcY = "); Serial.println(AcY);
  Serial.print(" | AcZ = "); Serial.print(AcZ);
  Serial.print(" | Tmp = "); Serial.print(Temp/340.00+36.53);  // check register map 4.18
  Serial.print(" | GyX = "); Serial.print(GyX);
  Serial.print(" | GyY = "); Serial.println(GyY);
  Serial.print(" | GyZ = "); Serial.println(GyZ);
  delay(1000);

}
