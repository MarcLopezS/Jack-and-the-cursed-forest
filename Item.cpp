#include <iostream>
#include "Item.h"

Item::Item()
{
}

Item::~Item()
{
}

void Item::PrintDetails()
{
	std::cout << "Item name: " << name << std::endl << "Details: " << description << std::endl;
}