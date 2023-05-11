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

void Room::SetupRoom(const std::string& name, const std::string& description)
{
	this->m_name = name;
	this->m_description = description;
	ptrNeighbourNorth = nullptr;
	ptrNeighbourSouth = nullptr;
	ptrNeighbourEast = nullptr; 
	ptrNeighbourWest = nullptr;
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

	if (ptrNeighbourNorth == nullptr) { std::cout << "North"; }
	if (ptrNeighbourSouth == nullptr) { std::cout << "South"; }
	if (ptrNeighbourEast == nullptr) { std::cout << "East"; }
	if (ptrNeighbourWest == nullptr) { std::cout << "West"; }

	std::cout << std::endl;
}

void Room::PrintPropertiesRoom() 
{
	std::cout << "Name of the room: " << m_name << std::endl;
	std::cout << "Description: " << m_description << std::endl;
}