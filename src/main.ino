#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <constants.h>
#include <helpers.h>

void setup()
{
    Serial.begin(9600);
    pinMode(2, OUTPUT);
    digitalWrite(2, 0);
    initWifi();
    initBot();
    initPinger();
}
unsigned long lastPing;
unsigned long lastCheckMessages;
void loop()
{
    intervaledPerform(lastCheckMessages, 2000, checkMessages);
    intervaledPerform(lastPing, 10000, intervalPing);
}