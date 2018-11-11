#include "main.h"

// external
void append_HTML_header();
void append_HTML_footer();
void append_short_HTML_header();
String GetTime();

String translateEncryptionType(wifi_auth_mode_t encryptionType);

void wifiaplist()
{
  append_short_HTML_header();
  webpage += "<br><h2>Time of AP Scan: " + GetTime() + "</h2><br>";

  webpage += "<table border=\"1\" style=\"width:100%\">";
  webpage += "<tr><th>SSID</th><th>BSSID</th><th>Channel</th><th>RSSI</th><th>Encryption</th></tr>";

  int n = WiFi.scanNetworks(false, true);

  if(n != 0) {
    for(int i = 0; i < n; ++i) {
      webpage += "<tr>";

      // webpage += "<td>" + (WiFi.SSID(i).length() == 0?"(Hidden SSID)":WiFi.SSID(i).c_str()) + "</td>";
      webpage += "<td align=\"left\">";
      webpage += (WiFi.SSID(i).length() == 0?"(Hidden SSID)":WiFi.SSID(i));
      webpage += "</td>";

      webpage += "<td align=\"right\">";
      webpage += WiFi.BSSIDstr(i);
      webpage += "</td>";

      webpage += "<td align=\"right\">";
      webpage += WiFi.channel(i);
      webpage += "</td>";

      webpage += "<td align=\"right\">";
      webpage += WiFi.RSSI(i);
      webpage += "</td>";

      webpage += "<td align=\"center\">";
      webpage += translateEncryptionType(WiFi.encryptionType(i));
      webpage += "</td>";

      webpage += "</tr>";
    }
  }
  webpage += "</table>";
  append_HTML_footer();
  server.send(200, "text/html", webpage);
}
