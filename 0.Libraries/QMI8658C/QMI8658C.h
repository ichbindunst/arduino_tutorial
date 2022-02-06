/*
 * @Description: QMI8658C
 * @Author: ELEGOO
 * @Date: 2019-07-10 16:46:17
 * @LastEditTime: 2021-04-14 14:05:33
 * @LastEditors: Changhua
 */

#ifndef _QMI8658C_H_

#define _QMI8658C_H_
#include <Arduino.h>
class QMI8658C
{
public:
  bool QMI8658C_dveInit(void);
  bool QMI8658C_dveGetEulerAngles(float *gyro, float *yaw);
  bool QMI8658C_dveGetEulerAngles(float *yaw);
  void QMI8658C_Check(void);

public:
  int16_t ax, ay, az, gx, gy, gz;
  float pith, roll, yaw;
  unsigned long now, lastTime = 0;
  float dt;      //微分时间
  float agz = 0; //角度变量
  long gzo = 0;  //陀螺仪偏移量
};

/*----------------------------------------------------------------------------------------------
  QMI8658C UI Sensor Configuration Settings and Output Data
*/
///<Configuration Registers>
#define address 0X6B  //device address
#define WHO_AM_I 0X00 //Device identifier
#define CTRL1 0x02    //Serial Interface and Sensor Enable
#define CTRL2 0x03    //Accelerometer Settings
#define CTRL3 0x04    //Gyroscope Settings
#define CTRL4 0X05    //Magnetometer Settings
#define CTRL5 0X06    //Sensor Data Processing Settings
#define CTRL7 0x08    //Enable Sensors and Configure Data Reads
#define CTRL8 0X09    //Reserved – Special Settings

///<Sensor Data Output Registers>
#define AccX_L 0x35
#define AccX_H 0x36
#define AccY_L 0x37
#define AccY_H 0x38
#define AccZ_L 0x39
#define AccZ_H 0x3A
#define TEMP_L 0x33

#define GyrX_L 0x3B
#define GyrX_H 0x3C
#define GyrY_L 0x3D
#define GyrY_H 0x3E
#define GyrZ_L 0x3F
#define GyrZ_H 0x40
int16_t QMI8658C_readBytes(unsigned char tmp);
//extern QMI8658C _QMI8658C;
#endif
