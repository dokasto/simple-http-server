#include "Server.h"

int main() {

  const int port = 8080;
  Server* server = new Server(port);
  server->get("/", "index.html");
  server->listen();
  return 0;
}
