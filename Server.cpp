#include <unistd.h> // For read
#include <iostream> // For cout
#include <string>
#include <vector>
#include "Server.h"
#include "Router.h"
#include "Socket.h"
#include "Utils.h"

using std::string;
using std::cout;
using std::endl;

Server::Server(const int& p) {
  port = p;
  this->router = new Router();
}

void Server::get(const string& path, const string& staticFile) {
  this->router->setHTTPGet(path, staticFile);
}

void Server::listen() {
  Socket* socket = new Socket();

  if(!socket->create()) {
    cout << "Failed to create socket" << endl;
  }

  if(!socket->bind(port)) {
    cout << "Failed to bind to port: " << port << endl;
    socket->close();
  }

  if(!socket->listen()) {
    cout << "Failed to create socket" << endl;
  }

  while(1) {
    cout << "Waiting for new connection" << endl;
    int& connection = socket->accept();

    if (connection < 0) {
      cout << "Unable to accept connection: " << connection << endl;
    }

    this->setupResponseHandler(connection);

    socket->close();
  }
}

void Server::setupResponseHandler(int& connection) {
  char buffer[3000];
  ::read(connection, buffer, 3000);
  string bufferString = buffer;
  logger(bufferString);
  string response = this->router->createResponse(bufferString);
  ::send(connection, response.c_str(), response.size(), 0);
}
