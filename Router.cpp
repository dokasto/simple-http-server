/*
* Router class
*/

#include <string>
#include <vector>
#include "Router.h"
#include "Utils.h"

using std::string;
using std::vector;

void Router::setHTTPGet(const string& path, const string& staticFile) {
  HTTP_GET_FilePath[path] = staticFile;
}

string Router::createResponse(string& requestStr) {
  vector<string> tokens = splitStringByWhitespace(requestStr);
  string responseFilePath = "404.html";
  string HTTPVerb = tokens[0];
  string requestPath = (tokens[1] == "") ? "/" : tokens[1] ;

  if (HTTPVerb == "GET" && HTTP_GET_FilePath.count(requestPath) > 0) {
    responseFilePath = HTTP_GET_FilePath[requestPath];
  }

  const string fileContent = readStaticFileContent(responseFilePath);
  string response = "HTTP/1.1 200 OK\nContent-Type: text/html\nContent-Length: ";
  response.append(std::to_string(fileContent.length()));
  response.append("\n\n");
  response.append(fileContent);
  logger(response);
  return response;
}
