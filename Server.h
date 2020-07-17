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
    void get(const string& path, const string& staticFile) const;
    void listen() const noexcept;
    void setupResponseHandler(int& connection) const;

  private:
    const int port;
    std::unique_ptr<Router> router;
};

#endif
