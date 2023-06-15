#ifndef Globals_h
#define Globals_h

#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

#include "Item.h"


std::vector<std::string> tokenize(const std::string& userInput);

std::string toLowerCase(std::string str);
std::string toUpperCase(std::string str);
bool compareNames(Item* item, const std::string& str);

#endif
