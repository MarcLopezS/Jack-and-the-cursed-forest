#include "Global.h"


std::vector<std::string> tokenize(const std::string& userInput)
{
	std::vector<std::string> arguments;
	
	std::stringstream ss(userInput);

	std::string temp_str;

	while(std::getline(ss, temp_str,' '))
	{
		arguments.push_back(temp_str);
	}

	return arguments;
}

std::string toLowerCase(std::string str)
{
	std::transform(str.begin(), str.end(),str.begin(),::tolower);
	return str;
}

std::string toUpperCase(std::string str)
{
	std::transform(str.begin(), str.end(), str.begin(), ::toupper);
	return str;
}