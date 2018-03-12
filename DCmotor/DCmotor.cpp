#include <Arduino.h>
#include "DCmotor.h"

int motorA1;
int motorA2;
int motorB1;
int motorB2;

int speed;

DCmotor::DCmotor(int _motorA1, int _motorA2, int _motorB1, int _motorB2)
{
  speed = 1023;
 
  motorA1 = _motorA1;
  motorA2 = _motorA2;
  motorB1 = _motorB1;
  motorB2 = _motorB2;

  pinMode(motorA1,OUTPUT);
  pinMode(motorA2,OUTPUT);
  pinMode(motorB1,OUTPUT);
  pinMode(motorB2,OUTPUT);
}

void DCmotor::setSpeed(int _speed)
{
  speed = _speed;
}

void DCmotor::startMotorA(int direction)
{
  if(direction == 1)
    {
      digitalWrite(motorA2, 0);
      analogWrite(motorA1, speed); 
    }
  else 
    {
      digitalWrite(motorA1, 0);
      analogWrite(motorA2, speed);
    }
}

void DCmotor::startMotorB(int direction)
{
  if(direction == 1)
    {
      digitalWrite(motorB2, 0);
      analogWrite(motorB1, speed); 
    }
  else 
    {
      digitalWrite(motorB1, 0);
      analogWrite(motorB2, speed);
    }
}

void DCmotor::stopMotorA()
{
  digitalWrite(motorA1, 0);
  digitalWrite(motorA2, 0);
}

void DCmotor::stopMotorB()
{
  digitalWrite(motorB1, 0);
  digitalWrite(motorB2, 0);
}

void DCmotor::stopMotor()
{
  stopMotorA();
  stopMotorB();
}
