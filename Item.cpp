#include <iostream>
#include "Item.h"

Item::Item(const std::string& name, const std::string& description, ItemType itemType, bool combinable)
{
	this->name = name;
	this->description = description;
	itemGameType = itemType;
	this->isCombinable = isCombinable;
	ClassifyItemValue();
}

Item::~Item()
{
}

void Item::PrintDetails()
{
	std::cout << "Item name: " << name << std::endl << "Details: " << description << std::endl;
}

void Item::CombineItems(Item combinableItem, const std::string& newName, const std::string& newDescription)
{

}

int Item::GetValueItem()
{
	return value_item;
}

void Item::ClassifyItemValue()
{
	if (itemGameType == ItemType::WEAPON)
	{
		ClassifyWeaponValue();
	}
	else {

		switch (itemGameType)
		{
		case ItemType::COMMON:
			value_item = listItems.POTION_VALUE;
			break;
		default:
			value_item = 0;
			break;
		}
	}
	
}

void Item::ClassifyWeaponValue()
{
	if (name == listItems.SWORD) value_item = listItems.SWORD_VALUE;
	if (name == listItems.HYDROSWORD) value_item = listItems.HYDROSWORD_VALUE;
	if (name == listItems.VITAL_SWORD) value_item = listItems.VITAL_SWORD_VALUE;
	if (name == listItems.GEO_SWORD) value_item = listItems.GEO_SWORD_VALUE;
	if (name == listItems.BLESSED_SWORD) value_item = listItems.BLESSED_SWORD_VALUE;
	if (name == listItems.MUDDY_SWORD) value_item = listItems.MUDDY_SWORD_VALUE;
	if (name == listItems.ETHEREAL_SWORD) value_item = listItems.ETHEREAL_SWORD_VALUE;
	if (name == listItems.GAIA_SWORD) value_item = listItems.GAIA_SWORD_VALUE;
	if (name == listItems.FANGS) value_item = listItems.FANG_VALUE;
}