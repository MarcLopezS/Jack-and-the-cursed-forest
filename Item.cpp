#include <iostream>
#include "Item.h"

Item::Item(const std::string& name, const std::string& description, ItemType itemType, bool combinable)
{
	this->name = name;
	this->description = description;
	itemGameType = itemType;
	this->isCombinable = isCombinable;
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