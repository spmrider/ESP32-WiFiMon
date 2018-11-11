#include "main.h"

void StartTime()
{
  configTime(0, 0, NTP1, NTP2);
  setenv("TZ", "CET-1CEST,M3.5.0/2,M10.5.0/3", 1); // Set for your locale
  delay(200);
}

String GetTime()
{
  struct tm timeinfo;
  while (!getLocalTime(&timeinfo))
  {
    Serial.println("Failed to obtain time");
    StartTime();
  }
  //See http://www.cplusplus.com/reference/ctime/strftime/
  //Serial.println(&timeinfo, "%a %b %d %Y   %H:%M:%S"); // Displays: Saturday, June 24 2017 14:05:49
  char output[50];
  strftime(output, 50, "%Y-%m-%d %H:%M:%S %Z", &timeinfo); // Format needed for Google Charts is "11/12/17 22:01:00"; //dd/mm/yy hh:hh:ss
  return output;
}
