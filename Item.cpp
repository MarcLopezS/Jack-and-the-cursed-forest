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
	switch (itemGameType)
	{
	case ItemType::COMMON:
		value_item = listItems.POTION_VALUE;
		break;
	case ItemType::WEAPON:
		value_item = 20;
		break;
	default:
		value_item = 0;
		break;
	}
}