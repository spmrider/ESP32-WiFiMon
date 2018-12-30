#define _GLOBALS_CPP
#include "main.h"
#undef _GLOBALS_CPP

bool eth_connected = false; // Ethernet connectivity status

#if(WEBSERVER)
String webpage = ""; // General purpose variable to hold HTML code
String siteheading    = "WiFiMon";               // Site's Main Title
String sitetitle      = "ESP32-PoE WiFi Monitor";       // Appears on the tabe of a Web Browser
String yourfootnote   = "ESP32 WiFi Monitor https://github.com/spmrider/ESP32-WiFiMon"; // A foot note e.g. "My Web Site"
String siteversion    = "v1.0";  // Version of your Website

ESP32WebServer server(80);
#endif

#ifdef MQTT_SSL
WiFiClientSecure mqtt_c;
#else
WiFiClient mqtt_c;
#endif

Adafruit_MQTT_Client mqtt(&mqtt_c, MQTT_SERVER, MQTT_PORT, MQTT_USER, MQTT_PASS);
