#include "TextsVideogame.h"
#include "Global.h"

TextsVideogame::TextsVideogame()
{
	texts_videogame = textFromFileToMap();
	text_status = copyKeysFromMap(texts_videogame);
	m_current_index = 0;
}

void TextsVideogame::indexStory(int index) 
{
	m_current_index = index;

	switch (m_current_index)
	{
	case 0:
		introduction();
		break;
	case 1:
		forest();
		break;
	case 2:
		allGems();
		break;
	case 3:
		boss();
		break;
	case 4:
		beforeEnding();
		ending();
		break;
	default:
		break;
	}

}

void TextsVideogame::introduction()
{
	if (!text_status["introduction"])
	{
		std::cout << texts_videogame["introduction"] << std::endl;
		std::cout << texts_videogame["introduction_two"] << std::endl;
		text_status["introduction"] = true;
	}
}

void TextsVideogame::forest()
{
	if (!text_status["forest"])
	{
		std::cout << texts_videogame["forest"] << std::endl;
		std::cout << texts_videogame["forest_two"] << std::endl;
		std::cout << texts_videogame["forest_three"] << std::endl;
		std::cout << texts_videogame["forest_four"] << std::endl;
		text_status["forest"] = true;
	}
	
}

void TextsVideogame::allGems()
{
	if (!text_status["all_gems"])
	{
		std::cout << texts_videogame["all_gems"] << std::endl;
		text_status["all_gems"] = true;
	}
}

void TextsVideogame::boss()
{
	if (!text_status["boss"])
	{
		std::cout << texts_videogame["boss"] << std::endl;
		std::cout << texts_videogame["boss_two"] << std::endl;
		text_status["boss"] = true;
	}
}

void TextsVideogame::beforeEnding()
{
	std::cout << texts_videogame["before_ending"] << std::endl;
}

void TextsVideogame::ending()
{
	std::cout << texts_videogame["good_ending"] << std::endl;
}