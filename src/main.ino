#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <constants.h>
#include <helpers.h>


#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>

void setup()
{
    Serial.begin(9600);
    Serial.println("loading....");
    pinMode(2, OUTPUT);
    #ifdef WEMOS
    pinMode(RELAY_PIN, OUTPUT);
    #endif
    digitalWrite(2, 0);
    initWifi();
    initPinger();
    initEEPROM();
    loadIp();
    initBot();
    ArduinoOTA.setHostname("esp_relay");
    ArduinoOTA.setPassword(OTA_PASSWORD);
    ArduinoOTA.begin();
}
unsigned long lastPing;
unsigned long lastCheckMessages;
void loop()
{
    ArduinoOTA.handle();
    intervaledPerform(lastCheckMessages, 2000, checkMessages);
    intervaledPerform(lastPing, 10000, intervalPing);
}