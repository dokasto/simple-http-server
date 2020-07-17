#include "Server.h"

int main() {
  const int port = 8080;
  std::unique_ptr<Server> server(new Server(port));
  server->get("/", "index.html");
  server->listen();
  return 0;
}
