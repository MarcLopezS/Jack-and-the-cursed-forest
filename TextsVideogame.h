#ifndef TextsVideogame_h_
#define TextsVideogame_h_

#include <string>
#include <map>



class TextsVideogame
{
public:
	TextsVideogame();

	void indexStory(int index);

	void introduction();
	void forest();
	void mine();
	void allGems();
	void boss();
	void beforeEnding();
	void ending();

	std::map<std::string, std::string> texts_videogame;
	std::map<std::string, bool> text_status;

private:
	int m_current_index;
	
};

#endif

