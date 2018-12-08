/***********************************************************
 This is the main scan task. It scans wireless networks in
 vicinity and publishes to MQTT.
************************************************************/
#include "main.h"
void MQTT_connect();
String translateEncryptionType(wifi_auth_mode_t encryptionType);
void v_scantask( void *pvParameters ) {
String topic = MQTT_TOPIC;
topic += "/";
topic += ETH.macAddress();
  Adafruit_MQTT_Publish mqttPublish = Adafruit_MQTT_Publish(&mqtt, topic.c_str());
  for(;;) {
    MQTT_connect();
    // scan aps
    int count = WiFi.scanNetworks(false, true);
    for(int index = 0; index < count; index++)
    {
      String ssid = (WiFi.SSID(index).length() == 0?"(Hidden SSID)":WiFi.SSID(index));
      String bssid = WiFi.BSSIDstr(index);
      int channel = WiFi.channel(index);
      int rssi = WiFi.RSSI(index);
      String encryption = translateEncryptionType(WiFi.encryptionType(index));
      String message = "{";
      message += "\"ssid\":\"";
      message += ssid;
      message += "\",\n";
      message += "\"bssid\":\"";
      message += bssid;
      message += "\",\n";
      message += "\"channel\":";
      message += channel;
      message += ",\n";
      message += "\"rssi\":";
      message += rssi;
      message += ",\n";
      message += "\"encryption\":\"";
      message += encryption;
      message += "\"}";
      // publish values
      mqttPublish.publish(message.c_str());
      // Serial.println(message);
    }
    // wait predefined ime before next scan
    vTaskDelay(APSCAN_FREQ * 1000);
  }
  vTaskDelete(NULL);
}
