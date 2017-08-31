#include <ESP8266Ping.h>
#include <EEPROM.h>
void printlnDebug(String str)
{
    if (DEBUG)
    {
        Serial.println(str);
    }
}
void printDebug(String str)
{
    if (DEBUG)
    {
        Serial.print(str);
    }
}
void printlnDebug(IPAddress string)
{
    if (DEBUG)
    {
        Serial.print(string);
    }
}
void toggleRelay(bool relayState)
{
    if (relayState)
    {
        //enable
        const byte miBufferON[] = {0xA0, 0x01, 0x01, 0xA2};
        Serial.write(miBufferON, sizeof(miBufferON));
    }
    else
    {
        //disable
        const byte miBufferOFF[] = {0xA0, 0x01, 0x00, 0xA1};
        Serial.write(miBufferOFF, sizeof(miBufferOFF));
    }
}

void turnML()
{
    toggleRelay(true);
    delay(200);
    toggleRelay(false);
}

void intervaledPerform(unsigned long &lastPerform, unsigned long threshold, void (*f)())
{
    unsigned long currMillis = millis();
    unsigned long interval = currMillis - lastPerform;
    if (interval < threshold)
    {
        return;
    }
    lastPerform = currMillis;
    (*f)();
}

void initEEPROM()
{
    EEPROM.begin(512);
}
int startAddr = 500;
void saveIp(int ip[4])
{
    for (int i = 0; i < 4; i++)
    {
        EEPROM.write(startAddr + i, ip[i]);
    }
    EEPROM.commit();
    loadIp();
}

void loadIp()
{
    int parts[4];
    for (int i = 0; i < 4; i++)
    {
        parts[i] = EEPROM.read(startAddr + i);
        Serial.println("output");
        Serial.print(parts[i]);
        Serial.println("close");
    }
    mlIp = IPAddress(parts[0], parts[1], parts[2], parts[3]);
    sendMessage(GROUIP, mlIp.toString());
}