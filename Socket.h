/*
* Socket class
*/
#ifndef SOCKET_H
#define SOCKET_H

#include <netinet/in.h> // For sockaddr_in

class Socket {
  private:
    int sockfd;
    sockaddr_in sockaddr;
    int connection;

  public:
    bool create();
    bool bind(const int& port);
    bool listen() const;
    int& accept();
    void close() const;
};

#endif
