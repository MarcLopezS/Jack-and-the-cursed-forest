#ifndef Item_h
#define Item_h

#include <string>

enum ItemType
{
	COMMON = 0,
	WEAPON
};

class Item
{
public:
	Item();
	~Item();

	void PrintDetails();

	ItemType itemGameType;
	std::string name;
	std::string description;

private:

};

#endif //Item_h