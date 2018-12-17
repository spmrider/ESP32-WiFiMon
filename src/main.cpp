#include "main.h"

// external functions
void scanWifiAps();
void EthEvent(WiFiEvent_t event);

void homepage();
void wifiaplist();
void handleNotFound();
void v_wstask(void *pvParameters);
void v_scantask(void *pvParameters);
void StartTime();

// create some tasks for handling different jobs
void starttasks() {
  BaseType_t xReturned;
  TaskHandle_t xHandle = NULL;

  /* Webserver Task */
  xReturned = xTaskCreate(
                    v_wstask,       /* Function that implements the task. */
                    "webserver",          /* Text name for the task. */
                    STACK_SIZE,      /* Stack size in words, not bytes. */
                    ( void * ) 1,    /* Parameter passed into the task. */
                    tskIDLE_PRIORITY,/* Priority at which the task is created. */
                    &xHandle );      /* Used to pass out the created task's handle. */
  if( xReturned == pdPASS ) {
    Serial.println("... Webserver");
  } else {
    Serial.println("... Webserver FAILED!");
  }

  /* Scan and publish task */
  xReturned = xTaskCreate(
                    v_scantask,       /* Function that implements the task. */
                    "ap_scan_and_pub",          /* Text name for the task. */
                    STACK_SIZE,      /* Stack size in words, not bytes. */
                    ( void * ) 1,    /* Parameter passed into the task. */
                    tskIDLE_PRIORITY,/* Priority at which the task is created. */
                    &xHandle );      /* Used to pass out the created task's handle. */
  if( xReturned == pdPASS ) {
    Serial.println("... ap_scan_and_pub");
  } else {
    Serial.println("... ap_scan_and_pub FAILED!");
  }
}

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

  Serial.print("Waiting for successful ETH connect ");
  while( !eth_connected ) {
    Serial.write('.');
    delay(500);
  }
  Serial.println("");

  Serial.print("ETH MAC: ");
  Serial.print(ETH.macAddress());
  Serial.print(", IPv4: ");
  Serial.print(ETH.localIP());
  if (ETH.fullDuplex()) {
    Serial.print(", FULL_DUPLEX");
  }
  Serial.print(", ");
  Serial.print(ETH.linkSpeed());
  Serial.println("Mbps");

  Serial.println("Setting time...");
  StartTime();

  delay(1000);

  Serial.println("Starting tasks ...");
  starttasks();
  Serial.println("WiFi Mon init done...");
}

// main loop
void loop() {
    vTaskDelay(1000);
   // server.handleClient();
}
