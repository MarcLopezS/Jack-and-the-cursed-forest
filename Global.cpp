#include "Global.h"
#include <fstream>
#include <string>
#include <map>


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

bool compareNames(Item* item, const std::string& str)
{
	return toLowerCase(item->name) == str;
}

std::map<std::string, std::string> textFromFileToMap()
{
    std::map<std::string, std::string> textVideogame;

    std::ifstream file("./Textos Videojuego/textos_videojuego.txt");

    if (file.is_open()) {
        std::string line;

        while (std::getline(file, line)) {
            
            auto pos_symbol = line.find('=');
            
            if (pos_symbol != std::string::npos) {
                std::string key = line.substr(0, pos_symbol - 1);
                std::string value = line.substr(pos_symbol + 1);

                // remove symbols,spaces from text and proccess breaklines
                value.erase(0, value.find_first_not_of(" \t\r\f\v\";"));
                value.erase(value.find_last_not_of(" \t\r\f\v\";") + 1);
                value = breakLine(value);
                
                textVideogame[key] = value;
            }
        }

        file.close();

        // Ejemplo de uso
        std::cout << "Inicio del juego: " << textVideogame["introduction"] << std::endl;
        std::cout << "Despedida: " << textVideogame["dialogo_despedida"] << std::endl;
    }
    else {
        std::cerr << "Error al abrir el archivo." << std::endl;
    }

    return textVideogame;
}

/**
 * @brief Function whose purpose is to process break lines inside a string when reading a file
 * @param text: the text value which needs to be evaluated. 
 * @return the same value as text, but with the break lines format in the correct format.
*/
std::string breakLine(const std::string& text)
{
    std::string result;

    for (size_t i = 0; i < text.length(); i++)
    {
        if (text[i] == '\\' && i + 1 < text.length() && text[i + 1] == 'n')
        {
            result += '\n';
            ++i; //to skip the \n 
        }
        else {
            result += text[i];
        }
    }

    return result;
}
