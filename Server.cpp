#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wexceptions"

#include <unistd.h> // For read
#include <iostream> // For cout
#include <string>
#include <vector>
#include "Server.h"
#include "Router.h"
#include "Socket.h"
#include "Utils.h"

using namespace std;

Server::Server(const int& p) : port(move(p)) {
  router = unique_ptr<Router>(new Router());
}

void Server::get(const string& path, const string& staticFile) const {
  this->router->setHTTPGet(path, staticFile);
}

void Server::listen() const noexcept {
  unique_ptr<Socket> socket(new Socket());

  if(!socket->create()) {
    throw runtime_error("Failed to create socket");
  }

  if(!socket->bind(port)) {
    throw runtime_error("Failed to bind to port: " + to_string(port));
    socket->close();
  }

  if(!socket->listen()) {
    throw runtime_error("Failed to start listener");
  }

  while(1) {
    cout << "Waiting for new connection" << endl;
    int& connection = socket->accept();

    if (connection < 0) {
      throw runtime_error("Unable to accept connection: " + to_string(connection));
    }

    this->setupResponseHandler(connection);
    socket->close();
  }
}

void Server::setupResponseHandler(int& connection) const {
  char buffer[3000];
  ::read(connection, buffer, 3000);
  string bufferString = buffer;
  logger(bufferString);
  string response = this->router->createResponse(bufferString);
  ::send(connection, response.c_str(), response.size(), 0);
}

#pragma GCC diagnostic pop