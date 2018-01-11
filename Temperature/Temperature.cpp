#include <Arduino.h>
#include <DHT.h>
#include "Temperature.h"

#define DHTTYPE DHT11           // Define type of sensor 

int DHTPIN;             

int val = 0;

DHT dht(DHTPIN, DHTTYPE, 15);   // Initial DHT sensor

Temperature::Temperature(int pin){
  DHTPIN = pin;
  val = pin;
  dht.begin();
}

double Temperature:readTemp(){
  double temp = dht.readTemperature();
  return temp;
}

int getVal(){
  return val;
}	
