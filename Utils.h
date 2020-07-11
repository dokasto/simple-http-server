/*
* Connection class
*/
#ifndef UTILS_H
#define UTILS_H

std::vector<std::string> splitStringByWhitespace(const std::string& str);
void logger(std::string& data);
std::string readStaticFileContent(std::string& filePath);

#endif
