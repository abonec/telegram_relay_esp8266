#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>
void initWifi() {
    WiFiManager wifiManager;
    wifiManager.autoConnect("ML_RELAY");
    printlnDebug("connected");
}