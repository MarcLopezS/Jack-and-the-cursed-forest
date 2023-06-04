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
void Player::Look(Room* currentRoom) const
{
	if (currentRoom->items_room.size() != 0)
	{
		std::cout << "You have found the following objects: " << std::endl;
		for (auto& item : currentRoom->items_room)
		{
			std::cout << item->name << std::endl;
		}

	}
	else {
		std::cout << "You don't see any objects to be taken nearby." << std::endl;
	}
	std::cout << std::endl;
	currentRoom->OutputNeighbors();
}

void Player::Take(const std::string& userInput, Room* currentRoom)
{
	for (unsigned int i = 0; i < currentRoom->items_room.size(); i++)
	{
		if (toLowerCase(currentRoom->items_room[i]->name) == toLowerCase(userInput)) {
			inventory.push_back(currentRoom->items_room[i]);
			currentRoom->items_room.erase(currentRoom->items_room.begin() + i);
		}
	}
	
}

void Player::Drop(const std::string& userInput, Room* currentRoom)
{
	for (size_t i = 0; i < inventory.size(); i++)
	{
		if (toLowerCase(inventory[i]->name) == toLowerCase(userInput))
		{
			if (inventory[i]->itemGameType == ItemType::COMMON)
			{
				currentRoom->items_room.push_back(inventory[i]);
				inventory.erase(inventory.begin() + i);
			}
			else {
				std::cout << "You cannot drop any weapons or important items! They are so useful for your adventure!" << std::endl;
			}
			
		}
	}
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

void Player::SetHealth()
{
	health_points = 100;
}
