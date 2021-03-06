#ifndef TOOLS_H
#define TOOLS_H

#include <string>

std::string & tolower(std::string & s);
std::string & toupper(std::string & s);
std::string & firstUpper(std::string & s);
std::string & tolower(const std::string & s);
std::string & toupper(const std::string & s);
std::string & firstUpper(const std::string & s);

std::string & time_tToString(time_t & t);

#endif

