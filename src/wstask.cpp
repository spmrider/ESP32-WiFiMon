#include "main.h"

#if(WEBSERVER)
void v_wstask( void *pvParameters ) {
  for (;;) {
    server.handleClient();
  }
  vTaskDelete(NULL);
}
#endif
