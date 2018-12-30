#include "main.h"


void MQTT_connect() {
  int8_t ret;

  if(!mqtt_c.connected()) {
    Serial.println("TCP Connect broken!");
  }

  // Stop if already connected.
  if (mqtt.connected()) {
    Serial.println("-> MQTT already connected...");
    Serial.print("Free HEAP: ");
    Serial.println(ESP.getFreeHeap());
    return;
  }

  Serial.print("Connecting to MQTT... ");

  while ((ret = mqtt.connect()) != 0) { // connect will return 0 for connected
       Serial.println(mqtt.connectErrorString(ret));
       Serial.println("Retrying MQTT connection in 5 seconds...");
       mqtt.disconnect();
       vTaskDelay(5000);  // wait 5 seconds
  }
  Serial.println("MQTT Connected!");
}
