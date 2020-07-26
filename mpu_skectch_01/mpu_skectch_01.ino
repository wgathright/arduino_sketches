#include <Wire.h>
#include <Servo.h>

long accelX, accelY, accelZ;
float gForceX, gForceY, gForceZ;

long gyroX, gyroY, gyroZ;
float rotX, rotY, rotZ;

////////////////////////////////
int servoPin01 = 9;
int servoPos = 0;

int servoPin02 = 5;
int servoPos02;

Servo xServo;
Servo yServo;



void setup()
{
  Serial.begin(9600);
  Wire.begin();
  setupMPU();

  xServo.attach(servoPin01);
  yServo.attach(servoPin02);
  xServo.write(0);

}

void loop()
{
  recordAccelRegisters();
  recordGyroRegisters();
  printData();
  xServo.write(rotX);
  delay(500);
  xServo.write(0);
  
}

void setupMPU()
{
  Wire.beginTransmission(0b1101000); // I2C address
  Wire.write(0x6B); // access the 6B register
  Wire.write(0b00000000); // set SLEEP register to 0
  Wire.endTransmission();

  Wire.beginTransmission(0b1101000); //
  Wire.write(0x1B); // access 1B - Gyroscope configuration
  Wire.write(0x00000000); // sets gyro to full scale +/- 250 degrees
  Wire.endTransmission();

  Wire.beginTransmission(0b1101000);
  Wire.write(0x1C); //access the 1C register - Accelerometer config
  Wire.write(0b00000000); // setting the accel to +/- 2g
  Wire.endTransmission();
}


void recordAccelRegisters()
{
  Wire.beginTransmission(0b1101000);
  Wire.write(0x3B); // starting register for accel readings
  Wire.endTransmission();
  Wire.requestFrom(0b1101000,6); // request acce lregister 3B - 40
  while(Wire.available() < 6);
  accelX = Wire.read()<<8|Wire.read();
  accelY = Wire.read()<<8|Wire.read();
  accelZ = Wire.read()<<8|Wire.read();
  processAccelData();
  
}

void processAccelData()
{
  gForceX = accelX / 16384.0;
  gForceY = accelY / 16384.0;
  gForceZ = accelZ / 16384.0;
}


void recordGyroRegisters()
{
  Wire.beginTransmission(0b1101000);
  Wire.write(0x43);
  Wire.endTransmission();
  Wire.requestFrom(0b1101000,6);
  while(Wire.available() < 6);
  gyroX = Wire.read()<<8|Wire.read();
  gyroY = Wire.read()<<8|Wire.read();
  gyroZ = Wire.read()<<8|Wire.read();
  processGyroData();
}

void processGyroData()
{
  rotX = gyroX / 131.0;
  rotY = gyroY / 131.0;
  rotZ = gyroZ / 131.0;
}

void printData()
{
  Serial.print(" Gyro (deg)");
  Serial.print(" X=");
  Serial.print(rotX);
  Serial.print(" Y=");
  Serial.print(rotY);
  Serial.print(" Z=");
  Serial.print(rotZ);
  Serial.print(" #### ");
  Serial.print(" Accel (g)");
  Serial.print(" X=");
  Serial.print(gForceX);
  Serial.print(" Y=");
  Serial.print(gForceY);
  Serial.print(" Z=");
  Serial.print(gForceZ); 
  Serial.println();
}
