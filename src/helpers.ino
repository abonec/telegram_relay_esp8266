#include <ESP8266Ping.h>
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