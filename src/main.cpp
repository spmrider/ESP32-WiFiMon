#include <Arduino.h>
#include "WiFi.h"

String translateEncryptionType(wifi_auth_mode_t encryptionType) {
  switch (encryptionType) {
    case (WIFI_AUTH_OPEN):
      return "Open";
    case (WIFI_AUTH_WEP):
      return "WEP";
    case (WIFI_AUTH_WPA_PSK):
      return "WPA_PSK";
    case (WIFI_AUTH_WPA2_PSK):
      return "WPA2_PSK";
    case (WIFI_AUTH_WPA_WPA2_PSK):
      return "WPA_WPA2_PSK";
    case (WIFI_AUTH_WPA2_ENTERPRISE):
      return "WPA2_ENTERPRISE";
    case (WIFI_AUTH_MAX):
      return "MAX";
    default:
      return "Unknown";
  }
}

void setup() {
  Serial.begin(115200);

  WiFi.mode(WIFI_STA);
  WiFi.disconnect();

  delay(100);

  Serial.println("WiFi Mon init done...");
}

void loop() {
  Serial.print("Scan start ... ");
  int n = WiFi.scanNetworks(false, true);
  Serial.printf("done (%i)\n", n);

  if(n != 0) {
    for(int i = 0; i < n; ++i) {
      Serial.printf("%2i: B: %s R: %4i C: %3i ENC: %16s SSID: %s\n", i+1, WiFi.BSSIDstr(i).c_str(), WiFi.RSSI(i), \
      WiFi.channel(i), translateEncryptionType(WiFi.encryptionType(i)).c_str(), \
      (WiFi.SSID(i).length() == 0?"(Hidden SSID)":WiFi.SSID(i).c_str()) \
      );
      delay(10);
    }
  }
  Serial.println("");
  delay(5000);
}
