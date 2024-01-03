#include "TextsVideogame.h"
#include "Global.h"

TextsVideogame::TextsVideogame()
{
	texts_videogame = textFromFileToMap();
	index_story = 0;
}

void TextsVideogame::indexStory() 
{
	switch (index_story)
	{
	case 0:
		introduction();
		break;
	default:
		break;
	}

}

void TextsVideogame::introduction()
{
	std::cout << texts_videogame["introduction"] << std::endl;
	std::cout << texts_videogame["introduction_two"] << std::endl;
}

void TextsVideogame::forest()
{
	std::cout << texts_videogame["forest"] << std::endl;
	std::cout << texts_videogame["forest_two"] << std::endl;
	std::cout << texts_videogame["forest_three"] << std::endl;
	std::cout << texts_videogame["forest_four"] << std::endl;
}

void TextsVideogame::allGems()
{
	std::cout << texts_videogame["all_gems"] << std::endl;
}

void TextsVideogame::boss()
{
	std::cout << texts_videogame["boss"] << std::endl;
	std::cout << texts_videogame["boss_two"] << std::endl;
}

void TextsVideogame::beforeEnding()
{
	std::cout << texts_videogame["before_ending"] << std::endl;
}

void TextsVideogame::ending()
{
	std::cout << texts_videogame["good_ending"] << std::endl;
}