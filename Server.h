/*
* server class
*/
#ifndef SERVER_H
#define SERVER_H

#include <string>
#include "Router.h"
#include "Socket.h"

using namespace std;

class Server {
  public:
    Server(const int& p);
    void get(const string& path, const string& staticFile) const;
    void listen() noexcept;
    void setupResponseHandler(int& connection) const;

  private:
    const int port;
    std::unique_ptr<Router> router;
		std::shared_ptr<Socket> socket;
		void createConnection() noexcept;
};

#endif
