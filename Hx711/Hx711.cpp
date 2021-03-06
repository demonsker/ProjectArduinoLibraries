/*
 * Hx711.cpp
 *
 *  Created on: Oct 31, 2012
 *      Author: agu
 */

#include "Hx711.h"

Hx711::Hx711(uint8_t pin_dout, uint8_t pin_slk) :
		_pin_dout(pin_dout), _pin_slk(pin_slk)
{
	pinMode(_pin_slk, OUTPUT);
	pinMode(_pin_dout, INPUT);

	digitalWrite(_pin_slk, HIGH);
	delayMicroseconds(100);
	digitalWrite(_pin_slk, LOW);

	averageValue();
	this->setOffset(averageValue());
	this->setScale();
}

Hx711::~Hx711()
{

}

long Hx711::averageValue(byte times)
{
	long sum = 0;
	for (byte i = 0; i < times; i++)
	{
		sum += getValue();
	}

	return sum / times;
}

long Hx711::getValue()
{
	byte data[3];

	while (digitalRead(_pin_dout))
		;

	for (byte j = 0; j < 3; j++)
	{
		for (byte i = 0; i < 8; i++)
		{
			digitalWrite(_pin_slk, HIGH);
			bitWrite(data[2 - j], 7 - i, digitalRead(_pin_dout));
			digitalWrite(_pin_slk, LOW);
		}
	}

	digitalWrite(_pin_slk, HIGH);
	digitalWrite(_pin_slk, LOW);

	return ((long) data[2] << 16) | ((long) data[1] << 8) | (long) data[0];
}

void Hx711::setOffset(long offset)
{
	_offset = offset;
}

void Hx711::setGramOffset(float offset)
{
	_offset = averageValue() + offset;
}

void Hx711::setScale(float scale)
{
	_scale = scale;
}

long Hx711::getOffset()
{
	return _offset;
}

long Hx711::getAverageValue()
{
	return averageValue();
}

float Hx711::getGram()
{
	long val = averageValue() - _offset;
	return (float) val / _scale;
}
