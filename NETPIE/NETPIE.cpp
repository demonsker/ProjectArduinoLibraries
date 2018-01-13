#include <Arduino.h>
#include <ESP8266WiFi.h>
#include "NETPIE.h"

const char* ssid     = "Your ASUS";
const char* password = "0874847756";

char* APPID  = "HappyPigsty";
char* KEY    = "zw0HnvDcL9VY4qA";
char* SECRET = "BDiOw4Twn98leHH6ATHDkV7fD";
char* ALIAS  = "TestBoard";

WiFiClient client;

int timer = 0;
MicroGear microgear(client);

NETPIE::NETPIE()
{

}

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

void NETPIE::initialize()
{
    Serial.begin(115200);
  
    microgear.on(PRESENT,onFoundgear);   
    microgear.on(ABSENT,onLostgear);   
    microgear.on(CONNECTED,onConnected);
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
    microgear.loop();
}
