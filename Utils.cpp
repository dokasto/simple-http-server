#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream> // For cout
#include <mutex>
#include "Utils.h"

std::vector<std::string> splitStringByWhitespace(const std::string& str) {
  std::string buffer;
  std::stringstream ss(str);
  std::vector<std::string> tokens;
  while(ss >> buffer) {
    tokens.push_back(buffer);
  }
  return tokens;
}

void logger(std::string& data) {
  std::cout << data << std::endl;
}

std::string readStaticFileContent(std::string& filePath) {
	// lock file with mutex
	std::mutex mutex;
	std::lock_guard<std::mutex> lock(mutex);
	
  std::ifstream file;
  std::string staticFilePath = "./static/";
  staticFilePath.append(filePath);

  file.open(staticFilePath);
  std::string line;
  std::string content;

  while(getline(file, line)) {
    logger(line);
    content.append(line);
  }

  return content;
}
