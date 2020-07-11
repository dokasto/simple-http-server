/*
* server class
*/
#ifndef SERVER_H
#define SERVER_H

#include <string>
#include "Router.h"

using std::string;

class Server {
  public:
    Server(const int& p);
    void get(const string& path, const string& staticFile);
    void listen();
    void setupResponseHandler(int& connection);

  private:
    int port;
    Router* router;
};

#endif
