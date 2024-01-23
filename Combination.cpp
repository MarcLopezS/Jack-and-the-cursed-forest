#include "Combination.h"

Item* CombineItems(Item* item1, Item* item2)
{
	ListItems listItems;

	if (item1->name == listItems.SWORD || item2->name == listItems.SWORD)
	{
		if (item1->name == listItems.WATER_GEM || item2->name == listItems.WATER_GEM)
		{
			return new Item(listItems.HYDROSWORD, "A sword combined with the water gem. It contains magical energy realted with the water element.", ItemType::WEAPON, true);
		}
		else if (item1->name == listItems.LIFE_GEM || item2->name == listItems.LIFE_GEM) 
		{
			return new Item(listItems.VITAL_SWORD, "A sword combined with the life gem. It contains magical energy realted with the life element.", ItemType::WEAPON, true);
		}
		else if (item1->name == listItems.EARTH_GEM || item2->name == listItems.EARTH_GEM)
		{
			return new Item(listItems.GEOSWORD, "A sword combined with the earth gem. It contains magical energy realted with the earth element.", ItemType::WEAPON, true);
		}
	}
	//sword + water gem combinations
	else if (item1->name == listItems.HYDROSWORD || item2->name == listItems.HYDROSWORD)
	{
		if (item1->name == listItems.EARTH_GEM || item2->name == listItems.EARTH_GEM)
		{
			return new Item(listItems.MUDDY_SWORD, "A sword combined with the water gem and earth gem. Its power can create dangeous swamps to trap your enemies.", ItemType::WEAPON, true);
		}
		else if (item1->name == listItems.LIFE_GEM || item2->name == listItems.LIFE_GEM)
		{
			return new Item(listItems.BLESSED_SWORD, "A sword combined with the water gem and life gem. Its power is very effective against undead monsters.", ItemType::WEAPON, true);
		}
	}
	//sword + life gem combinations
	else if (item1->name == listItems.VITAL_SWORD || item2->name == listItems.VITAL_SWORD)
	{
		if (item1->name == listItems.EARTH_GEM || item2->name == listItems.EARTH_GEM)
		{
			return new Item(listItems.ETHEREAL_SWORD, "A sword combined with the life gem and earth gem. Its power can reflect all spells casted from your enemies.", ItemType::WEAPON, true);
		}
		else if (item1->name == listItems.WATER_GEM || item2->name == listItems.WATER_GEM)
		{
			return new Item(listItems.BLESSED_SWORD, "A sword combined with the water gem and life gem. Its power is very effective against undead monsters.", ItemType::WEAPON, true);
		}
	}
	//sword + earth gem combinations
	else if (item1->name == listItems.GEOSWORD || item2->name == listItems.GEOSWORD)
	{
		if (item1->name == listItems.WATER_GEM || item2->name == listItems.WATER_GEM)
		{
			return new Item(listItems.MUDDY_SWORD, "A sword combined with the water gem and earth gem. Its power can create dangeous swamps to trap your enemies.", ItemType::WEAPON, true);
		}
		else if (item1->name == listItems.LIFE_GEM || item2->name == listItems.LIFE_GEM)
		{
			return new Item(listItems.ETHEREAL_SWORD, "A sword combined with the life gem and earth gem. Its power can reflect all spells casted from your enemies.", ItemType::WEAPON, true);
		}
	}
	//sword + all gem 
	else if ((item1->name == listItems.MUDDY_SWORD || item2->name == listItems.MUDDY_SWORD)
			|| (item1->name == listItems.ETHEREAL_SWORD || item2->name == listItems.ETHEREAL_SWORD)
			|| (item1->name == listItems.BLESSED_SWORD || item2->name == listItems.BLESSED_SWORD))
	{
		if ((item1->name == listItems.WATER_GEM || item2->name == listItems.WATER_GEM)
			|| (item1->name == listItems.LIFE_GEM || item2->name == listItems.LIFE_GEM)
			|| (item1->name == listItems.EARTH_GEM || item2->name == listItems.EARTH_GEM))
		{
			return new Item(listItems.GAIA_SWORD, "Sacred sword from legends. According to the stories, it belonged to Gaia, the mother nature.", ItemType::WEAPON, false);
		}	
	}
	
	return new Item("Failed item", "Falied item", ItemType::COMMON,false);

}