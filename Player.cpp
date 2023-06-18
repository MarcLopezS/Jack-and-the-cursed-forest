#include <iostream>
#include "Player.h"


Player::Player(const std::string& name, const std::string& description, CreatureType creature_type)
	: Creature(name, description,creature_type)
{
	SetHealth();
	strength = 20;
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
		if (toLowerCase(item->name) == userInput) 
		{
			item->PrintDetails();
			itemExist = true;
		}	
	}

	if (!itemExist)
		std::cout << "The item you want to examine does not exist or is not in your inventory." << std::endl;
}

void Player::Attack(const std::string& userInput, Enemy* enemy)
{
	int damage_weapon = equipedItems.size() == 1 ? equipedItems.front()->GetValueItem() : 0;
	int critic_rate = 20;
	int control_probability = rand() % 100 + 1; //to control critic probability
	
	int damage_points = ((strength + damage_weapon) + (rand() % 11) - 5);
		enemy->current_health_points -= damage_points;

	if (control_probability <= critic_rate) //damage x2 if enters
	{
			std::cout << "Critic attack! ";
			damage_points *= 2;
	}

	enemy->Damage(this, damage_points);

}

void Player::Loot(const std::string& userInput)
{
}

/*void Player::Exit(const std::string& userInput)
{
}*/

void Player::Use(const std::string& userInput)
{
	auto it = std::find_if(inventory.begin(), inventory.end(), [userInput](Item* item) {
		return compareNames(item, userInput);
		});
	
	if (it != inventory.end())
	{
		//If using item is successful
		if (HandleItemInput(userInput))
		{
			std::cout << "You used a " << (*it)->name << std::endl;
			inventory.erase(it);
		}
	}
	else {
		std::cout << "The item you want to use does not exist or is not in your inventory." << std::endl;
	}
}

void Player::Status() const
{
	std::cout << "HP: " << current_health_points << "/" << max_health_points << std::endl;
	std::cout << "Strength: " << strength << std::endl;
	if (equipedItems.size() != 0)
	{
		std::cout << "Equiped weapon: " << equipedItems.front()->name;
		std::cout << "Weapon attack: " << equipedItems.front()->GetValueItem();
	}
	std::cout << std::endl;
}

void Player::SetHealth()
{
	max_health_points = 100;
	current_health_points = 100;
}

std::vector<Item*> Player::GetInventory()
{
	return inventory;
}

void Player::LootEnemy(Item* enemy_item)
{
	inventory.push_back(enemy_item);
}

/*
 Handle the item specified and, if the operation was not successful, return false
*/
bool Player::HandleItemInput(const std::string& itemInput)
{
	if (listItems.POTION == toLowerCase(itemInput))
	{
		if (current_health_points != max_health_points) 
		{
			current_health_points = (current_health_points + listItems.POTION_VALUE) > max_health_points
				? max_health_points
				: current_health_points + listItems.POTION_VALUE;

			return true;
		}
		else {
			std::cout << "I'm completely healthy! It would be a waste to use a " << listItems.POTION << " now." << std::endl;
		}
	}
	return false;
}
