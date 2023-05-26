#include <iostream>
#include "Player.h"


Player::Player(const std::string& name, const std::string& description, CreatureType creature_type)
	: Creature(name, description,creature_type)
{

}

Player::~Player()
{
}

/*
* We check if userInput is a valid direction to use the function GoDestination() in World class.
*/
bool Player::Go(const std::string& userInput)
{
	bool inputExist = false;

	if (userInput == "north" || userInput == "n")
	{
		inputExist = true;
	}
	else if (userInput == "south" || userInput == "s")
	{
		inputExist = true;
	}
	else if (userInput == "east" || userInput == "e")
	{
		inputExist = true;
	}
	else if (userInput == "west" || userInput == "w")
	{
		inputExist = true;
	}

	return inputExist;
}
void Player::Look(const std::string& userInput, Room* currentRoom) const
{
}

void Player::Take(const std::string& userInput)
{
}

void Player::Drop(const std::string& userInput)
{
}


void Player::Inventory() const
{
	std::cout << "Inventory: " << std::endl;

	for (auto& item : inventory)
	{
		std::cout << item->name << std::endl;
	}
}

void Player::Equip(const std::string& userInput)
{
}

void Player::UnEquip(const std::string& userInput)
{
}

void Player::Examine(const std::string& userInput) const
{
	bool itemExist = false;
	
	for (auto& item : inventory)
	{
		if (item->name == userInput) 
		{
			item->PrintDetails();
			itemExist = true;
		}	
	}

	if (!itemExist)
		std::cout << "The item you want to examine does not exist or is not in your inventory." << std::endl;
}

void Player::Attack(const std::string& userInput)
{
}

void Player::Loot(const std::string& userInput)
{
}

/*void Player::Exit(const std::string& userInput)
{
}*/
