#include <Arduino.h>
#include <ESP8266WiFi.h>
#include "NETPIE.h"

const char* ssid;
const char* password;

char* APPID;
char* KEY;
char* SECRET;
char* ALIAS;

WiFiClient client;

int timer = 0;
MicroGear microgear(client);

void onFoundgear(char *attribute, uint8_t* msg, unsigned int msglen) {
    Serial.print("Found new member --> ");
    for (int i=0; i<msglen; i++)
        Serial.print((char)msg[i]);
    Serial.println();  
}

void onLostgear(char *attribute, uint8_t* msg, unsigned int msglen) {
    Serial.print("Lost member --> ");
    for (int i=0; i<msglen; i++)
        Serial.print((char)msg[i]);
    Serial.println();
}

void onConnected(char *attribute, uint8_t* msg, unsigned int msglen) {
    Serial.println("Connected to NETPIE...");
    microgear.setAlias(ALIAS);
}

NETPIE::NETPIE(char* _APPID, char* _KEY, char* _SECRET)
{
    Serial.begin(115200);
    
    APPID =  _APPID;
    KEY = _KEY;
    SECRET = _SECRET;

    microgear.on(PRESENT,onFoundgear);   
    microgear.on(ABSENT,onLostgear);   
    microgear.on(CONNECTED,onConnected);
}

void NETPIE::setAlias(char* alias)
{
    ALIAS = alias;
}

void NETPIE::setWIFI(char* _ssid, char* _pwd)
{
    ssid = _ssid;
    password = _pwd;
}

MicroGear NETPIE::getMicrogear()
{
    return microgear;
}

void NETPIE::connectWIFI()
{
    Serial.println("Starting...");
    if (WiFi.begin(ssid, password)) {
        while (WiFi.status() != WL_CONNECTED) {
            delay(500);
            Serial.print(".");
        }
    }

    Serial.println("WiFi connected");  
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());

    microgear.init(KEY,SECRET,ALIAS);
}

void NETPIE::connect()
{
    microgear.connect(APPID);
}

void NETPIE::loopConnect()
{
    if(!microgear.connected())
    {
        Serial.println("connection lost, reconnect...");
    }
    microgear.loop();
}

void NETPIE::send(char* alias, char* message)
{
    microgear.chat(alias, message);
}
