#ifndef Item_h
#define Item_h

#include <string>

enum ItemType
{
	COMMON = 0,
	WEAPON,
	KEY_ITEM
};

class Item
{
public:
	Item(const std::string& name, const std::string& description, ItemType itemType, bool isCombinable);
	~Item();

	void PrintDetails();
	void CombineItems(Item combinableItem, const std::string& newName, const std::string& newDescription);

	
	ItemType itemGameType;
	
	std::string name;
	std::string description;
	
	bool isCombinable;

private:


};

#endif //Item_h