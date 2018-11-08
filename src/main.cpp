#include "main.h"

// external functions
void scanWifiAps();

// setup basic things
void setup() {
  Serial.begin(115200);

  WiFi.mode(WIFI_STA);
  WiFi.disconnect();

  delay(100);

  Serial.println("WiFi Mon init done...");
}

// main loop
void loop() {
  scanWifiAps();
  delay(5000);
}
