#ifndef Item_h
#define Item_h

#include <string>

enum class ItemType
{
	COMMON = 0,
	WEAPON,
	KEY_ITEM
};

struct ListItems
{
	public:
		std::string WATER_GEM = "Water gem";
		std::string LIFE_GEM = "Life gem"; 
		std::string EARTH_GEM = "Earth gem";

		std::string MINE_KEY = "Mine key";

		std::string POTION = "Potion";
		
		int POTION_VALUE = 75;

		std::string FANGS = "Fangs";
		int FANG_VALUE = 20;
		
		std::string FIRE_WAND = "Fire wand";
		int WAND_VALUE = 30;

		std::string SWORD = "Sword";
		int SWORD_VALUE = 20;

		std::string HYDROSWORD = "Hydrosword";
		int HYDROSWORD_VALUE = 25;

		std::string VITAL_SWORD = "Vital sword";
		int VITAL_SWORD_VALUE = 25;

		std::string GEOSWORD = "Geosword";
		int GEO_SWORD_VALUE = 25;

		std::string BLESSED_SWORD = "Blessed sword";
		int BLESSED_SWORD_VALUE = 30;

		std::string MUDDY_SWORD = "Muddy sword";
		int  MUDDY_SWORD_VALUE = 30;

		std::string ETHEREAL_SWORD = "Ethereal sword";
		int ETHEREAL_SWORD_VALUE = 30;

		std::string GAIA_SWORD = "Gaia's sword";
		int GAIA_SWORD_VALUE = 50;
};

class Item
{
public:
	Item(const std::string& name, const std::string& description, ItemType itemType, bool isCombinable);
	~Item();

	void PrintDetails();
	int GetValueItem();
	void ClassifyItemValue();
	void ClassifyWeaponValue();

	ItemType itemGameType;
	ListItems listItems;
	
	std::string name;
	std::string description;
	
	bool isCombinable;

private:

	//int m_min_value;
	//int m_max_value;
	int value_item; 
};

#endif //Item_h