#ifndef ROUTER_H
#define ROUTER_H

#include <string>
#include <unordered_map>

using std::string;

class Router {
  public:
    void setHTTPGet(const string& path, const string& staticFile);
    string createResponse(string& requestStr);

  private:
    std::unordered_map<string, string> HTTP_GET_FilePath;
};

#endif
