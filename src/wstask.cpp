#include "main.h"

void v_wstask( void *pvParameters ) {
  for (;;) {
    server.handleClient();
  }
  vTaskDelete(NULL);
}
