#include <sys/socket.h> // For socket functions
#include <netinet/in.h> // For sockaddr_in
#include <unistd.h> // For read
#include "Socket.h"

bool Socket::create() {
  sockfd = ::socket(AF_INET, SOCK_STREAM, 0);
  return sockfd != -1;
}

bool Socket::bind(int port) {
  sockaddr.sin_family = AF_INET;
  sockaddr.sin_addr.s_addr = INADDR_ANY;

  // htons is necessary to convert a number to network byte order
  sockaddr.sin_port = htons(port);
  return (::bind(sockfd, (struct sockaddr*)&sockaddr, sizeof(sockaddr)) >= 0);
}

bool Socket::listen() {
  return (::listen(sockfd, 10) >= 0);
}

int& Socket::accept() {
  int addrlen = sizeof(sockaddr);
  return ::accept(sockfd, (struct sockaddr *) &sockaddr, (socklen_t*)&addrlen);
}

void Socket::close() {
  ::close(connection);
}
