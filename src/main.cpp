#include <ESP8266WiFi.h>          //https://github.com/esp8266/Arduino

//needed for library
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>         //https://github.com/tzapu/WiFiManager
#include <NTPClient.h>
// #include <Blynk.h>
#include <BlynkSimpleEsp8266.h>
// OTA Includes
#include <ArduinoOTA.h>

#include <ESP8266mDNS.h>

WiFiClient espClient;

MDNS_NAME = "LedDriver1"

void setup()
{
        Serial.begin(9600);
    //WiFiManager
    //Local intialization. Once its business is done, there is no need to keep it around
    WiFiManager wifiManager;
    //reset saved settings
    //wifiManager.resetSettings();
    
    //set custom ip for portal
    //wifiManager.setAPStaticIPConfig(IPAddress(10,0,1,1), IPAddress(10,0,1,1), IPAddress(255,255,255,0));

    //fetches ssid and pass from eeprom and tries to connect
    //if it does not connect it starts an access point with the specified name
    //here  "AutoConnectAP"
    //and goes into a blocking loop awaiting configuration
    wifiManager.autoConnect(MDNS_NAME);
    //or use this for auto generated name ESP + ChipID
    //wifiManager.autoConnect();

    //if you get here you have connected to the WiFi
    Serial.println("connected...yeey :)");


    Serial.println("Starting OS");
    ArduinoOTA.onStart([]()
                       { Serial.println("OTA Starts"); });

    ArduinoOTA.onProgress([](unsigned int progress, unsigned int total)
                          { Serial.println("progress / (total / 100)"); });

    ArduinoOTA.onEnd([]()
                     { Serial.println("OTA Finished"); });

                     
}

void loop()
{
    ArduinoOTA.handle();
}