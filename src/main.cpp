#include "main.h"

// external functions
void scanWifiAps();
void EthEvent(WiFiEvent_t event);

void homepage();
void wifiaplist();
void handleNotFound();
void v_wstask(void *pvParameters);
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

  delay(100);

  Serial.println("Setting time...");
  StartTime();
  Serial.println("Starting tasks ...");
  starttasks();
  Serial.println("WiFi Mon init done...");
}

// main loop
void loop() {
    vTaskDelay(1000);
   // server.handleClient();
}
