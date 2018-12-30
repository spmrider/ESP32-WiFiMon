/***********************************************************
 This is the main scan task. It scans wireless networks in
 vicinity and publishes to MQTT.
************************************************************/
#include "main.h"

void MQTT_connect();
String translateEncryptionType(wifi_auth_mode_t encryptionType);

void v_scantask( void *pvParameters ) {
  String sensor = ETH.macAddress();

  // AP List
  String topicAplist = MQTT_TOPIC;
  topicAplist += "/aplist";
  Adafruit_MQTT_Publish mqttPublishAplist = Adafruit_MQTT_Publish(&mqtt, topicAplist.c_str());

  // AP Channel Map
  String topicChanmap = MQTT_TOPIC;
  topicChanmap += "/chanmap";
  Adafruit_MQTT_Publish mqttPublishChanmap = Adafruit_MQTT_Publish(&mqtt, topicChanmap.c_str());

  for(;;) {
    // scan aps
    int count = WiFi.scanNetworks(false, true);
    int chanmap[15] = {0};

    if(! mqtt.ping()) {
      Serial.println("MQTT Ping failed!");
      mqtt.disconnect();
      MQTT_connect();
    }

    for(int index = 0; index < count; index++)
    {
      String ssid = (WiFi.SSID(index).length() == 0?"(Hidden SSID)":WiFi.SSID(index));
      String bssid = WiFi.BSSIDstr(index);
      int channel = WiFi.channel(index);
      int rssi = WiFi.RSSI(index);
      chanmap[channel]++;
      String encryption = translateEncryptionType(WiFi.encryptionType(index));
      String message = "{";
      message += "\"sensor\":\"";
      message += sensor;
      message += "\",\n";
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
      // Serial.printf("AP Pub %3i / %3i", index+1, count);
      if(!mqttPublishAplist.publish(message.c_str())) {
        Serial.println("AP List Publish failed!");
        mqtt.disconnect();
        vTaskDelay(500);
        MQTT_connect();
      } else {
        vTaskDelay(100);
      }
      // Serial.println("");
    }

    String chanMapMsg = "{";
    for(int chan=1; chan < 15; chan++) {
      chanMapMsg += "\"c";
      chanMapMsg += chan;
      chanMapMsg += "\":";
      chanMapMsg += chanmap[chan];
      if(chan!=14) {
        chanMapMsg += ",";
      }
    }
    chanMapMsg += "}";
    // Serial.println(chanMapMsg);
    if(!mqttPublishChanmap.publish(chanMapMsg.c_str())) {
      Serial.println("ChanMap Publish failed!");
      mqtt.disconnect();
      vTaskDelay(500);
      MQTT_connect();
    } else {
      vTaskDelay(100);
    }

    // wait predefined ime before next scan
    vTaskDelay(APSCAN_FREQ * 1000);
  }
  vTaskDelete(NULL);
}
