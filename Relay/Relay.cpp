#include <Arduino.h>
#include "Relay.h"

int downTemperature;
int cleaning;

void Relay::initialize(int _downTemperature, int _cleaning)
{
	downTemperature = _downTemperature;
	cleaning = _cleaning;

	pinMode(downTemperature, OUTPUT);
	pinMode(cleaning, OUTPUT);
}

void Relay::startDownTemperature()
{
  digitalWrite(downTemperature, LOW);
}

void Relay::startCleaning()
{
  digitalWrite(cleaning, LOW);
}

void Relay::stopTemperature()
{
  digitalWrite(downTemperature, HIGH);
}

void Relay::stopCleaning()
{
  digitalWrite(cleaning, HIGH);
}

void Relay::stopAllPin()
{
  digitalWrite(downTemperature, HIGH);
  digitalWrite(cleaning, HIGH);
}
