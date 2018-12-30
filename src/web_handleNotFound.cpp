
#include "main.h"

#if(WEBSERVER)
void handleNotFound()
{
  String message = "The request entered could not be found, please try again with a different option\n";
  server.send(404, "text/plain", message);
}
#endif
