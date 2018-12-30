#ifndef _GLOBALS_H
#define _GLOBALS_H

#if(WEBSERVER)
extern String webpage;
extern String siteheading;
extern String sitetitle;
extern String siteversion;
extern String yourfootnote;

extern ESP32WebServer server;
#endif

extern Adafruit_MQTT_Client mqtt;

extern bool eth_connected;

#ifdef MQTT_SSL
extern WiFiClientSecure mqtt_c;
#else
extern WiFiClient mqtt_c;
#endif

#endif
