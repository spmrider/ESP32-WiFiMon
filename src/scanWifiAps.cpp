#include "main.h"

// external functions
String translateEncryptionType(wifi_auth_mode_t encryptionType);

void scanWifiAps() {
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
}
