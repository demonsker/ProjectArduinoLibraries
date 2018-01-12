#include <Servo.h> 
#include <Arduino.h>
#include "ServoMotor.h"

Servo servo1;
Servo servo2;   

ServoMotor::ServoMotor(int Pin1, int Pin2)
{
  servo1.attach(Pin1); 
  servo2.attach(Pin2);
}

void ServoMotor::startLiftUp()
{   
  servo1.write(180); 
  servo2.write(180);
}

void ServoMotor::startLiftDown()
{   
  servo1.write(0); 
  servo2.write(0);
}

void ServoMotor::ChangeDegree(int degree)
{
  servo1.write(degree);
}

void ServoMotor::openFood(int servo)
{
  if(servo == 1)
  {
    servo1.write(180);
  }
  else if(servo == 2)
  {
    servo2.write(180);
  }
}

void ServoMotor::closeFood(int servo)
{
  if(servo == 1)
  {
    servo1.write(0);
  }
  else if(servo == 2)
  {
    servo2.write(0);
  }
}
