/***********************************************************
 This is the main scan task. It scans wireless networks in
 vicinity and publishes to MQTT.
************************************************************/

#include "main.h"

void MQTT_connect();

void v_scantask( void *pvParameters ) {
  int n = 0;

  for(;;) {
    // scan aps
    n = WiFi.scanNetworks(false, true);

    // publish values
    MQTT_connect();
    if(n != 0) {
      for(int i = 0; i < n; ++i) {

      }
    // wait predefined ime before next scan
    vTaskDelay(APSCAN_FREQ * 1000);
    }
  }
  vTaskDelete(NULL);
}
