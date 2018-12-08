#define _GLOBALS_CPP
#include "main.h"
#undef _GLOBALS_CPP

String webpage = ""; // General purpose variable to hold HTML code

String siteheading    = "WiFiMon";               // Site's Main Title
String sitetitle      = "ESP32-PoE WiFi Monitor";       // Appears on the tabe of a Web Browser
String yourfootnote   = "ESP32 WiFi Monitor https://github.com/spmrider/ESP32-WiFiMon"; // A foot note e.g. "My Web Site"
String siteversion    = "v1.0";  // Version of your Website

bool eth_connected = false; // Ethernet connectivity status

ESP32WebServer server(80);
