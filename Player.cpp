#include <iostream>
#include "Player.h"


Player::Player(const std::string& name, const std::string& description, CreatureType creature_type)
	: Creature(name, description,creature_type)
{
	SetHealth();
	strength = 5;
	equipedWeapon = nullptr;
}

Player::~Player()
{
}

/*
* Check if userInput is a valid direction to use the function GoDestination() in World class.
*/
bool Player::Go(const std::string& userInput, Room* current_room)
{
	bool inputExist = false;

	if ((userInput == "north" || userInput == "n") && current_room->ptrNeighbourNorth != nullptr)
		inputExist = true;

	else if ((userInput == "south" || userInput == "s") && current_room->ptrNeighbourSouth != nullptr)
		inputExist = true;
	
	else if ((userInput == "east" || userInput == "e") && current_room->ptrNeighbourEast != nullptr)
		inputExist = true;
	
	else if ((userInput == "west" || userInput == "w") && current_room->ptrNeighbourWest != nullptr)
		inputExist = true;

	return inputExist;
}

void Player::Look(Room* currentRoom) const
{
	std::cout << currentRoom->description << std::endl << std::endl;
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
	std::cout << std::endl;
}

void Player::Take(const std::string& userInput, const std::string& userInput2, Room* currentRoom)
{
	bool item_exist = false;
	std::vector<std::string> aux_vector;

	for (unsigned int i = 0; i < currentRoom->items_room.size(); i++)
	{
		auto itemsRoom = currentRoom->items_room;

		aux_vector = tokenize(itemsRoom[i]->name);

		if (aux_vector.size() > 1 && userInput2 != "")
		{
			if (toLowerCase(aux_vector[0]) == toLowerCase(userInput) && toLowerCase(aux_vector[1]) == toLowerCase(userInput2))
				TakeItemToInventory(item_exist,i,currentRoom);

		}else if (userInput2 == "" && toLowerCase(itemsRoom[i]->name) == toLowerCase(userInput)) 
			TakeItemToInventory(item_exist, i, currentRoom);
		
	}
		
	if(!item_exist)
		std::cout << "There is no items here or not with the specified name! Put a correct item name if exist and try again." << std::endl;
	
	std::cout << std::endl;
}

void Player::Drop(const std::string& userInput, const std::string& userInput2, Room* currentRoom)
{
	bool item_exist = false;
	std::vector<std::string> aux_vector;

	for (size_t i = 0; i < inventory.size(); i++)
	{
		aux_vector = tokenize(inventory[i]->name);

		if (toLowerCase(inventory[i]->name) == toLowerCase(userInput) && userInput2 == "")
		{
			if (inventory[i]->itemGameType == ItemType::COMMON)
				DropItemToRoom(item_exist, i, currentRoom);

			else
				std::cout << "You cannot drop any weapons or important items! They are so useful for your adventure!" << std::endl;
			
		}
		else if (aux_vector.size() > 1 && userInput2 != "") {
			
			if (toLowerCase(aux_vector[0]) == toLowerCase(userInput) && toLowerCase(aux_vector[1]) == toLowerCase(userInput2))
				DropItemToRoom(item_exist, i, currentRoom);

		}
	}
	if (!item_exist)
		std::cout << "There is no items with the specified name in your inventory! Put a correct item name if exist and try again." << std::endl;

	std::cout << std::endl;
}

void Player::Inventory() const
{
	std::cout << "Inventory: " << std::endl;

	for (auto& item : inventory)
	{
		std::cout << item->name << std::endl;
	}
	std::cout << std::endl;
}

void Player::Equip()
{
	bool itemEquipped = false;

	for (size_t i = 0; i < inventory.size(); i++)
	{
		if ( inventory[i]->itemGameType == ItemType::WEAPON)
		{
			equipedWeapon = inventory[i];
			itemEquipped = true;
			std::cout << "You equipped " << inventory[i]->name << "." << std::endl;
			inventory.erase(inventory.begin() + i);

		}
	}

	if (!itemEquipped)
		std::cout << "You don't have any weapon to equip..." << std::endl;

	std::cout << std::endl;
}

void Player::UnEquip()
{
	if (equipedWeapon != nullptr)
	{
		inventory.push_back(equipedWeapon);
		std::cout << "You unequipped " << equipedWeapon->name << "." << std::endl;
		equipedWeapon = nullptr;
	}
	else 
	{
		std::cout << "You already have nothing equipped..." << std::endl;
	}

	std::cout << std::endl;
}

void Player::Examine(const std::string& userInput, const std::string& userInput2) const
{
	bool itemExist = false;
	std::vector<std::string> auxVector;
	
	for (auto& item : inventory)
	{
		auxVector = tokenize(toLowerCase(item->name));
		if (auxVector.size() > 1)
		{
			if (auxVector[0] == userInput && auxVector[1] == userInput2)
			{
				item->PrintDetails();
				itemExist = true;
			}
		}
		else if(auxVector.size() == 1 && auxVector[0] == userInput)
		{
			item->PrintDetails();
			itemExist = true;
		}	
	}

	if (!itemExist)
		std::cout << "The item you want to examine does not exist or is not in your inventory." << std::endl;

	std::cout << std::endl;
}

void Player::Attack(const std::string& userInput, Enemy* enemy)
{
	int damage_weapon = equipedWeapon != nullptr ? equipedWeapon->GetValueItem() : 0;
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
	std::cout << std::endl;
}

/**
 * @brief Special Command that activates the boss enemy if conditions are met.
 * @param userInput: name of the item sended by user.
 * @param currentRoom: room where the player is.
 * @param activateBoss: FALSE by default. TRUE if conditions are met.
*/
void Player::Use(const std::string& userInput, Room* currentRoom, bool& activateBoss)
{
	auto it = std::find_if(inventory.begin(), inventory.end(), [userInput](Item* item) {
		return compareNames(item, userInput);
		});

	
	if ((it != inventory.end() && (*it)->name == "Gaia's sword") || equipedWeapon->name == "Gaia's sword")
	{
		if (currentRoom->name == "Forest Great Tree")
			activateBoss = true;
		else 
			std::cout << "Gaia's sword requires to be used in Forest Great Tree. It is pointless trying to use it here!" << std::endl;
	}
	else {
		std::cout << "The item you want to use does not exist or is not in your inventory." << std::endl;
	}
	std::cout << std::endl;
}

void Player::Combine()
{
	std::string input1, input2, nameAux;

	std::cout << "Specify the first object you want to make a combination: " << std::endl;
	std::getline(std::cin, input1);
	std::cout << std::endl << std::endl;

	std::cout << "Specify the second object you want to make a combination: " << std::endl;
	std::getline(std::cin, input2);
	std::cout << std::endl << std::endl;

	std::vector<Item*> combItemsContainer;

	if (tokenize(input1) != tokenize(input2))
	{
		for (size_t i = 0; i < inventory.size(); i++)
		{
			if ( ((toLowerCase(inventory[i]->name) == toLowerCase(input1)) && inventory[i]->isCombinable) ||
				((toLowerCase(inventory[i]->name) == toLowerCase(input2)) && inventory[i]->isCombinable))
			{
				nameAux = inventory[i]->name;
				//Check if item exist inside vector combItemsContainer to avoid duplicates
				auto it = std::find_if(combItemsContainer.begin(), combItemsContainer.end(),
					[&](const Item* item) {
						return item != nullptr && item->name == nameAux;
					});

				if (it == combItemsContainer.end())
					combItemsContainer.push_back(inventory[i]);
			}
		}
		
		if (combItemsContainer.size() == 2)
		{
			Item* resultCombination = CombineItems(combItemsContainer[0], combItemsContainer[1]);
			
			if (resultCombination->name != "Failed item") 
			{
				inventory.push_back(resultCombination);

				std::cout << "Combination successful! You obtain " << resultCombination->name  << "!" << std::endl;
				std::cout << "You put " << resultCombination->name << " in your inventory." << std::endl << std::endl;

				auto itItem1 = std::find_if(inventory.begin(), inventory.end(), [input1](Item* item) {
					return compareNames(item, input1);
					});

				if (itItem1 != inventory.end())
					inventory.erase(itItem1);

				auto itItem2 = std::find_if(inventory.begin(), inventory.end(), [input2](Item* item) {
					return compareNames(item, input2);
					});

				if (itItem2 != inventory.end())
					inventory.erase(itItem2);
			}
			else {
				std::cout << "You cannot combine those items. Select two different ones and try again." << std::endl;
			}
			
		}
		else {
			std::cout << "One or all the specified items are not in your inventory. If the item is a weapon, make sure to unequip it." << std::endl;
		}
	}
	else {
		std::cout << "You cannot combine two equal items! Select two different items and try again." << std::endl;

	}

	std::cout << std::endl;
}

void Player::Status() const
{
	std::cout << "HP: " << current_health_points << "/" << max_health_points << std::endl;
	std::cout << "Strength: " << strength << std::endl;
	if (equipedWeapon != nullptr)
	{
		std::cout << "Equiped weapon: " << equipedWeapon->name << std::endl;
		std::cout << "Weapon attack: " << equipedWeapon->GetValueItem() << std::endl;
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
	if (toLowerCase(listItems.POTION) == toLowerCase(itemInput))
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

void Player::DropItemToRoom(bool& item_exist, int posItem, Room* currentRoom)
{
	std::cout << "You dropped " << inventory[posItem]->name << " on the floor." << std::endl;
	currentRoom->items_room.push_back(inventory[posItem]);
	inventory.erase(inventory.begin() + posItem);
	item_exist = true;
}

void Player::TakeItemToInventory(bool& item_exist, int posItem, Room* currentRoom)
{
	std::cout << "You take " << currentRoom->items_room[posItem]->name << ". You put the item in your inventory." << std::endl;
	inventory.push_back(currentRoom->items_room[posItem]);
	currentRoom->items_room.erase(currentRoom->items_room.begin() + posItem);
	item_exist = true;
}

/**
 * @brief Check if item with specified name is in the inventory
 * @param nameItem 
 * @return true/false
*/
bool Player::IsItemInInventory(const std::string& nameItem)
{
	for (auto item : inventory)
	{
		if (item->name == nameItem)
			return true;
	}

	return false;
}