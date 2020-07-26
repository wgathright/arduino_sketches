#include <Servo.h>

int servoPin01 = 9;
int servoPos;

int servoPin02 = 5;
int servoPos02;

Servo myServo;
Servo myServo02;



void setup()
{
  Serial.begin(9600);
  myServo.attach(servoPin01);
  myServo02.attach(servoPin02);

}

void loop()
{

  Serial.println("What angle for servo 1?");
  while (Serial.available() == 0)
  {
    
  }

  servoPos = Serial.parseInt();
  myServo.write(servoPos);

  Serial.println("What angle for servo 2?");
  while (Serial.available() == 0)
  {
    
  }

  servoPos02 = Serial.parseInt();
  myServo02.write(servoPos02);

  

}
