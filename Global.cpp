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