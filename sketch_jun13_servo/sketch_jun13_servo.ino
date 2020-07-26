#include <Servo.h>

int servoPin01 = 9;
int servoPos = 0;

int servoPin02 = 5;
int servoPos02;

Servo xServo;
Servo yServo;


void setup()
{
  Serial.begin(9600);
  xServo.attach(servoPin01);
  yServo.attach(servoPin02);

}

void loop()
{
  

  for(int i = 0;i < 140;i++)
  {
    servoPos = i;
    xServo.write(servoPos);
    

    for(int j = 0;j < 130;j++)
    {
      servoPos02 = i;
      yServo.write(servoPos02);
    }

    delay(15);
  }


  
  servoPos = 0;
  xServo.write(servoPos);
  delay(500);
  
  servoPos = 45;
  xServo.write(servoPos);
  delay(500);
  
  servoPos = 120;
  xServo.write(servoPos);
  delay(500);

  servoPos = 45;
  xServo.write(servoPos);
  delay(500);

  servoPos = 0;
  xServo.write(servoPos);
  delay(500);
  

}
