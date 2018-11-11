#include "main.h"

// external functions
void scanWifiAps();
void EthEvent(WiFiEvent_t event);

void homepage();
void wifiaplist();
void handleNotFound();

// Webserver basics
// ESP32WebServer server(80); // Start server on port 80

// setup basic things
void setup() {
  Serial.begin(115200);

  // Start Ethernet
  WiFi.onEvent(EthEvent);
  ETH.begin();

  // Prepare ESP32WebServer
  server.on("/", homepage);
  server.on("/aps", wifiaplist);
  server.onNotFound(handleNotFound);

  // Setup WiFi for scanning
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();

  delay(100);

  Serial.println("WiFi Mon init done...");
}

// main loop
void loop() {
   server.handleClient();
}
