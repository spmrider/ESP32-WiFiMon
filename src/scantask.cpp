/***********************************************************
 This is the main scan task. It scans wireless networks in
 vicinity and publishes to MQTT.
************************************************************/

#include "main.h"

void v_scantask( void *pvParameters ) {
  // scan aps

  // publish values

  // wait predefined ime before next scan
  vTaskDelay(APSCAN_FREQ * 1000);
}
