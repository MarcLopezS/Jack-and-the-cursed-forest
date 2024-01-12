#ifndef Globals_h
#define Globals_h

#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>

#include "Item.h"


std::vector<std::string> tokenize(const std::string& userInput);

std::string toLowerCase(std::string str);
std::string toUpperCase(std::string str);
bool compareNames(Item* item, const std::string& str);

std::map<std::string, std::string> textFromFileToMap();
std::map<std::string, bool> copyKeysFromMap(const std::map<std::string, std::string>& mapWithKeys);
std::string breakLine(const std::string& texto);

#endif
