#ifndef TextsVideogame_h_
#define TextsVideogame_h_

#include <string>
#include <map>



class TextsVideogame
{
public:
	TextsVideogame();

	void indexStory();

	void introduction();
	void forest();
	void allGems();
	void boss();
	void beforeEnding();
	void ending();

	std::map<std::string, std::string> texts_videogame;

private:
	int index_story;
	
};

#endif

