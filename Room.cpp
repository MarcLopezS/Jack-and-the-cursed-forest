#include <iostream>
#include <string>
#include "Room.h"

Room::Room()
{
	SetupRoom();
}

Room::Room(const std::string& name, const std::string& description)
{
	SetupRoom(name, description);
}

Room::~Room()
{
}

void Room::SetupItem(Item item)
{
	items_room.push_back(&item);
}

void Room::SetupItem(std::vector<Item> items)
{
	for (auto& element : items)
	{
		items_room.push_back(&element);
	}
}
void Room::SetupRoom(const std::string& name, const std::string& description)
{
	this->name = name;
	this->description = description;
	ptrNeighbourNorth = nullptr;
	ptrNeighbourSouth = nullptr;
	ptrNeighbourEast = nullptr; 
	ptrNeighbourWest = nullptr;
}

void Room::SetupDetailsRoom(const std::string& name, const std::string& description)
{
	this->name = name;
	this->description = description;
}

void Room::SetNeighbors(Room* ptrNorth, Room* ptrSouth, Room* ptrEast, Room* ptrWest )
{
	ptrNeighbourNorth = ptrNorth;
	ptrNeighbourSouth = ptrSouth;
	ptrNeighbourEast = ptrEast;
	ptrNeighbourWest = ptrWest;
}

void Room::OutputNeighbors()
{
	std::cout << "You see that you can go: ";

	if (ptrNeighbourNorth != nullptr) { std::cout << "North "; }
	if (ptrNeighbourSouth != nullptr) { std::cout << "South "; }
	if (ptrNeighbourEast != nullptr) { std::cout << "East "; }
	if (ptrNeighbourWest != nullptr) { std::cout << "West "; }

	std::cout << std::endl;
}

bool Room::checkDirection(const std::string& direction) 
{
	if ((direction.compare("north") == 0 && ptrNeighbourNorth != nullptr)||
		(direction.compare("south") == 0 && ptrNeighbourSouth != nullptr) ||
		(direction.compare("east") == 0 && ptrNeighbourEast != nullptr) ||
		(direction.compare("west") == 0 && ptrNeighbourWest != nullptr ))
	{
		return true;
	}else{
		return false;
	}
}

void Room::PrintPropertiesRoom() 
{
	std::cout << "----------------------------------- " << std::endl
		<< name << std::endl;
	std::cout << description << std::endl
		<< "----------------------------------- " << std::endl;
}