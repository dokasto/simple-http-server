#include <sys/socket.h> // For socket functions
#include <netinet/in.h> // For sockaddr_in
#include <cstdlib> // For exit() and EXIT_FAILURE
#include <iostream> // For cout
#include <unistd.h> // For read
#include "Socket.h"
#include "Server.h"

int main() {

  const int port = 8080;
  Server* server = new Server(port);
  server->get("/", "index.html");
  server->listen();
  return 0;
}
