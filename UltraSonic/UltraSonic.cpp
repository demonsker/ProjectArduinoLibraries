#include <Arduino.h>
#include "UltraSonic.h"

int TRIGGER_PIN;
int ECHO_PIN; 

UltraSonic::UltraSonic(int pin1, int pin2)
{
  ECHO_PIN = pin1;
  TRIGGER_PIN = pin2;
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

double UltraSonic::readDistance()
{
  long duration, distance;
  digitalWrite(TRIGGER_PIN, LOW); 
  delayMicroseconds(2); 
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
  duration = pulseIn(ECHO_PIN, HIGH);
  distance = (duration/2) / 29.1;
  delay(1000);
  return distance;
}
