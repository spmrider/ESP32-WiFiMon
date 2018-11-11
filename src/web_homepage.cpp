#include "main.h"

// external
void append_HTML_header();
void append_HTML_footer();
String GetTime();

void homepage()
{
  append_HTML_header();
  webpage += "<P class='style2'>ESP32 WiFi Monitor</p><br>";
  webpage += "<p class='style2'>";
  webpage += "Homepage for ESP32-PoE WiFi Monitor";
  webpage += "</p><br>";
  webpage += "<p>This page was displayed on : " + GetTime() + " Hr</p>";
  String Uptime = (String(millis() / 1000 / 60 / 60)) + ":";
  Uptime += (((millis() / 1000 / 60 % 60) < 10) ? "0" + String(millis() / 1000 / 60 % 60) : String(millis() / 1000 / 60 % 60)) + ":";
  Uptime += ((millis() / 1000 % 60) < 10) ? "0" + String(millis() / 1000 % 60) : String(millis() / 1000 % 60);
  webpage += "<p>Uptime: " + Uptime + "</p>";
  append_HTML_footer();
  server.send(200, "text/html", webpage);
}
