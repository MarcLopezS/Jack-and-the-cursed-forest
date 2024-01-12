#include <iostream>
#include <string>

#include "World.h"
#include "Global.h"
#include "Enemy.h"

World::World()
{
	player = new Player("Jack", "A villager whose dream is looking for some adventures.", CreatureType::PLAYER);

	SetupRooms();
	SetupItems();
	SetupEnemies();
	m_ptrStory = new TextsVideogame();

	m_gameOver = false;
	m_activateBoss = false;
}

World::~World()
{
	//m_ptrCurrentRoom pointer is inside m_rooms, so does not require to specify it
	std::vector<Room*>().swap(m_rooms);//de-allocate the memory taken by the vector 
	delete player;
	delete m_ptrStory;
}

void World::Run()
{
	std::vector<std::string> userCommands;
	std::string input;
	
	m_ptrCurrentRoom->PrintPropertiesRoom();
	HandleStoryText();

	while (!m_gameOver)
	{
		std::cout << std::endl << "What are you going to do now?" << std::endl << ">> ";

		//Get user input
		std::getline(std::cin, input);
		std::cout << std::endl;

		//Split input into separate words
		userCommands = tokenize(input);

		HandleUserInput(userCommands);

		if (m_activateBoss)
			SetupBoss();

		if (m_ptrCurrentRoom->enemy_room != nullptr)
			Combat();

		//GameOver();
		if (!m_gameOver) {
			m_ptrCurrentRoom->PrintPropertiesRoom();
			HandleStoryText();
		}
		
	}

}

void World::Combat()
{
	std::cout << "You found a " << m_ptrCurrentRoom->enemy_room->name << "!" << std::endl;
	std::cout << "You change to combat mode." << std::endl;
	std::cout << std::endl;

	bool iscombatFinished = false, player_turn = true;

	std::vector<std::string> userCommands;
	std::string input;

	while (!iscombatFinished && !m_gameOver)
	{
		PrintCombatStats();

		std::cout << std::endl << "Which combat action are you going to do now?" << std::endl;
		std::cout << ">> ";

		//Get user input
		std::getline(std::cin, input);
		std::cout << std::endl;

		//Split input into separate words
		userCommands = tokenize(input);

		player_turn = HandleUserInputCombat(userCommands);

		if (m_ptrCurrentRoom->enemy_room->current_health_points <= 0)
		{
			//ENEMY DEFEAT
			iscombatFinished = true;
			m_ptrCurrentRoom->enemy_room = nullptr;
		}
		else if (!player_turn)
		{
			//ENEMY ATTACK
			m_ptrCurrentRoom->enemy_room->Attack(player);
			if (player->current_health_points > 0) 
			{
				player_turn = true;
			}
			else 
			{
				iscombatFinished = true;
				std::cout << std::endl << m_ptrCurrentRoom->enemy_room->name << " killed you...." << std::endl;
				m_ptrCurrentRoom->enemy_room->SetHealth();
				if (m_activateBoss)
				{
					m_activateBoss = false;
					RemoveBoss();
				}
				ReturnRoomCheckpoint();
			}
				
		}

	}

}

void World::PrintCombatStats()
{
	std::cout << "----------------------------------- " << std::endl;
	std::cout << std::endl << "COMBAT\t" << m_ptrCurrentRoom->enemy_room->name << std::endl;
	std::cout << std::endl << "Jack HP: " << player->current_health_points << "/" << player->max_health_points << std::endl << std::endl ;
	std::cout << "----------------------------------- " << std::endl << std::endl;
}

void World::SetupRooms()
{
	const size_t nRooms = 22;

	Room* rooms = new Room[nRooms];

	rooms[village].SetupDetailsRoom("Village", "The village where you have been living your entire life.");
	//m_ptrCurrentRoom = &rooms[village];

	rooms[forest_entrance].SetupDetailsRoom("Forest Entrance", "description");
	rooms[forest_greatTree].SetupDetailsRoom("Forest Great Tree", "description");
	rooms[river].SetupDetailsRoom("River", "description");
	rooms[water_Altar].SetupDetailsRoom("Water Altar", "description");
	rooms[spine_territory_1].SetupDetailsRoom("Spine territory zone 1", "description");
	rooms[spine_territory_2].SetupDetailsRoom("Spine territory zone 2", "description");
	rooms[spine_territory_3].SetupDetailsRoom("Spine territory zone 3", "description");
	rooms[spine_territory_4].SetupDetailsRoom("Spine territory zone 4", "description");
	rooms[spine_territory_5].SetupDetailsRoom("Spine territory zone 5", "description");
	rooms[spine_territory_6].SetupDetailsRoom("Spine territory zone 6", "description");
	rooms[spine_territory_7].SetupDetailsRoom("Spine territory zone 7", "description");
	rooms[spine_territory_8].SetupDetailsRoom("Spine territory zone 8", "description");
	rooms[spine_territory_9].SetupDetailsRoom("Spine territory zone 9", "description");
	rooms[spine_territory_10].SetupDetailsRoom("Spine territory zone 10", "description");
	rooms[life_altar].SetupDetailsRoom("Life Altar", "description");
	rooms[mossy_forest].SetupDetailsRoom("Mossy Forest", "description");
	rooms[cave_entrance].SetupDetailsRoom("Cave entrance", "description");
	rooms[mine].SetupDetailsRoom("Mine", "description");
	rooms[mineral_room].SetupDetailsRoom("Mineral Room", "description");
	rooms[warehouse].SetupDetailsRoom("Warehouse", "description");
	rooms[earth_altar].SetupDetailsRoom("Earth altar", "description");

	SetupNeighbors(rooms);

	for (size_t i = 0; i < nRooms; i++)
	{
		m_rooms.push_back(&rooms[i]);
	}

	m_ptrCurrentRoom = m_rooms[village];
	rooms = nullptr;

	delete[] rooms;

}

void World::SetupNeighbors(Room* rooms)
{
	rooms[village].SetNeighbors(&rooms[forest_entrance], nullptr, nullptr, nullptr);
	rooms[forest_entrance].SetNeighbors(&rooms[forest_greatTree], &rooms[village], nullptr, nullptr);
	rooms[forest_greatTree].SetNeighbors(&rooms[spine_territory_1], &rooms[forest_entrance], &rooms[mossy_forest], &rooms[river]);
	rooms[river].SetNeighbors(nullptr, nullptr, &rooms[forest_greatTree], &rooms[water_Altar]);
	rooms[water_Altar].SetNeighbors(nullptr, nullptr, &rooms[river], nullptr);
	rooms[spine_territory_1].SetNeighbors(nullptr, &rooms[forest_greatTree], &rooms[spine_territory_2], nullptr);
	rooms[spine_territory_2].SetNeighbors(&rooms[spine_territory_3], nullptr, nullptr, &rooms[spine_territory_1]);
	rooms[spine_territory_3].SetNeighbors(nullptr, &rooms[spine_territory_2], &rooms[spine_territory_4], nullptr);
	rooms[spine_territory_4].SetNeighbors(&rooms[spine_territory_5], nullptr, nullptr, &rooms[spine_territory_3]);
	rooms[spine_territory_5].SetNeighbors(&rooms[spine_territory_6], &rooms[spine_territory_4], nullptr, nullptr);
	rooms[spine_territory_6].SetNeighbors(nullptr, &rooms[spine_territory_5], nullptr, &rooms[spine_territory_7]);
	rooms[spine_territory_7].SetNeighbors(&rooms[spine_territory_10], nullptr, &rooms[spine_territory_6], &rooms[spine_territory_8]);
	rooms[spine_territory_8].SetNeighbors(nullptr, &rooms[spine_territory_9], &rooms[spine_territory_7], nullptr);
	rooms[spine_territory_9].SetNeighbors(&rooms[spine_territory_8], nullptr, nullptr, nullptr);
	rooms[spine_territory_10].SetNeighbors(&rooms[life_altar], &rooms[spine_territory_7], nullptr, nullptr);
	rooms[life_altar].SetNeighbors(nullptr, &rooms[spine_territory_10], nullptr, nullptr);
	rooms[mossy_forest].SetNeighbors(nullptr, nullptr, &rooms[cave_entrance], &rooms[forest_greatTree]);
	rooms[cave_entrance].SetNeighbors(nullptr, nullptr, &rooms[mine], &rooms[mossy_forest]);
	rooms[mine].SetNeighbors(&rooms[warehouse], &rooms[mineral_room], &rooms[earth_altar], &rooms[cave_entrance]);
	rooms[mineral_room].SetNeighbors(&rooms[mine], nullptr, nullptr, nullptr);
	rooms[warehouse].SetNeighbors(nullptr, &rooms[mine], nullptr, nullptr);
	rooms[earth_altar].SetNeighbors(nullptr, nullptr, nullptr, &rooms[mine]);
}

void World::SetupItems()
{
	Item* potion = new Item(listItems.POTION, "A liquid that helps healing wounds. Restores 75HP.", ItemType::COMMON, false);

	m_rooms[river]->SetupItem(potion);
	m_rooms[spine_territory_6]->SetupItem(potion);
	m_rooms[spine_territory_9]->SetupItem(potion);
	m_rooms[mossy_forest]->SetupItem(potion);
	m_rooms[mine]->SetupItem(potion);

	Item* key = new Item("Mine key", "A key that has a label that says \"Mine\".", ItemType::KEY_ITEM, false);

	m_rooms[warehouse]->SetupItem(key);

	Item* sword = new Item(listItems.SWORD, "A sword found in the great tree.", ItemType::WEAPON, true);
	Item* water_gem = new Item(listItems.WATER_GEM, "A special gem that, according to the legend, has the power to control water.", ItemType::KEY_ITEM, true);
	Item* life_gem = new Item(listItems.LIFE_GEM, "A special gem that, according to the legend, has the power to control life of the living beings.", ItemType::KEY_ITEM, true);
	Item* earth_gem = new Item(listItems.EARTH_GEM, "A special gem that, according to the legend, has the power to control eathrquakes and modify the ecosystem.", ItemType::KEY_ITEM, true);

	Item * gaia_sword = new Item(listItems.GAIA_SWORD, "Sacred sword from legends. According to the stories, it belonged to Gaia, the mother nature.", ItemType::WEAPON, false);
	
	m_rooms[water_Altar]->SetupItem(water_gem);
	m_rooms[life_altar]->SetupItem(life_gem);
	m_rooms[earth_altar]->SetupItem(earth_gem);

	//test
	m_rooms[forest_greatTree]->SetupItem(water_gem);
	m_rooms[forest_greatTree]->SetupItem(life_gem); 
	m_rooms[forest_greatTree]->SetupItem(earth_gem);
	m_rooms[forest_greatTree]->SetupItem(sword);
	m_rooms[forest_greatTree]->SetupItem(potion);
	m_rooms[forest_greatTree]->SetupItem(potion);
	
	m_rooms[forest_greatTree]->SetupItem(gaia_sword);
}

void World::SetupEnemies()
{
	ListItems listItems;

	Item* fangs = new Item(listItems.FANGS, "The fangs of an animal. Very powerful and sharp", ItemType::WEAPON, false);
	Enemy* wolf = new Enemy("Wolf", "A creature borned in the forest. With their powerful fangs can destroy their enemies.", CreatureType::ENEMY, fangs);

	Enemy* snake = new Enemy("Snake", "A creature borned in the forest. With their powerful fangs and large body can cause the death of their enemies.", CreatureType::ENEMY, fangs);

	m_rooms[river]->SetupEnemy(snake);
	m_rooms[spine_territory_3]->SetupEnemy(wolf);
	m_rooms[spine_territory_5]->SetupEnemy(wolf);
	m_rooms[spine_territory_7]->SetupEnemy(snake);
	m_rooms[mineral_room]->SetupEnemy(snake);

}

void World::SetupBoss()
{
	Item* fire_wand = new Item(listItems.FIRE_WAND, "Cursed wand that uses the power from hell thanks to the fire gem.", ItemType::WEAPON, false);

	Enemy* boss = new Enemy("Infernal Witch", "A creature borned from hell. Responsible for the curse of the the forest.", CreatureType::BOSS, fire_wand);

	m_rooms[forest_greatTree]->SetupEnemy(boss);
}

void World::RemoveBoss()
{
	m_rooms[forest_greatTree]->enemy_room = nullptr;
}

/**
 * @brief Identifies which command user requested in non-combat areas.
 *
 * Depending on the command, is required to insert none, one or two words.
 *
 * @param userInput: All the input that the user inserted (COMMAND + word / COMMAND + word + word).
 * @return Returns a boolean to control the turn of the player in combat.
*/
void World::HandleUserInput(const std::vector<std::string>& userInput)
{
	std::string userCommand = toLowerCase(userInput.at(0));
	std::string userParameter = userInput.size() > 1 ? toLowerCase(userInput.at(1)) : "";
	std::string userParameter2 = userInput.size() > 2 ? toLowerCase(userInput.at(2)) : "";
	
	if (m_commands.GO == userCommand)
	{
		bool isGoOK = player->Go(userParameter, m_ptrCurrentRoom);

		if (isGoOK)
			GoDestination(userParameter);
		else
			std::cout << "Invalid or wrong usage command. Please try again." << std::endl;

	}
	else if (m_commands.LOOK_1 == userCommand || m_commands.LOOK_2 == userCommand)
	{
		player->Look(m_ptrCurrentRoom);
	}
	else if (m_commands.TAKE_1 == userCommand || m_commands.TAKE_2 == userCommand)
	{
		player->Take(userParameter, userParameter2, m_ptrCurrentRoom);
	}
	else if (m_commands.DROP_1 == userCommand || m_commands.DROP_2 == userCommand)
	{
		player->Drop(userParameter, userParameter2, m_ptrCurrentRoom);
	}
	else if (m_commands.INVENTORY_1 == userCommand || m_commands.INVENTORY_2 == userCommand)
	{
		player->Inventory();
	}
	else if (m_commands.EQUIP_1 == userCommand || m_commands.EQUIP_2 == userCommand)
	{
		player->Equip();
	}
	else if (m_commands.UNEQUIP_1 == userCommand || m_commands.UNEQUIP_2 == userCommand)
	{
		player->UnEquip();
	}
	else if (m_commands.EXAMINE_1 == userCommand || m_commands.EXAMINE_2 == userCommand)
	{
		player->Examine(userParameter, userParameter2);
	}
	/*else if (m_commands.ATTACK_1 == userCommand || m_commands.ATTACK_2 == userCommand)
	{
		player->Attack(userParameter,m_);
	}*/
	else if (m_commands.LOOT_1 == userCommand || m_commands.LOOT_2 == userCommand)
	{
		player->Loot(userParameter);
	}
	else if (m_commands.HELP_1 == userCommand || m_commands.HELP_2 == userCommand)
	{
		HelpCommand();
	}
	else if (m_commands.QUIT_1 == userCommand || m_commands.QUIT_2 == userCommand)
	{
		GameOver();
	}
	else if (m_commands.USE_1 == userCommand || m_commands.USE_2 == userCommand)
	{
		if(userParameter != "gaia's" && userParameter2 != "sword")
			player->Use(userParameter);
		else
			player->Use("gaia's sword",m_ptrCurrentRoom,m_activateBoss);
	}
	else if (m_commands.COMBINE_1 == userCommand || m_commands.COMBINE_2 == userCommand)
	{
		player->Combine();
	}
	else if (m_commands.STATS_1 == userCommand || m_commands.STATS_2 == userCommand)
	{
		player->Status();
	}
	else
		std::cout << "Invalid or wrong usage command. Please try again." << std::endl;
}

/**
 * @brief Identifies which command user requested in combat. 
 * 
 * Depending on the command, is required to insert none, one or two words.
 * 
 * @param userInput: All the input that the user inserted (COMMAND + word / COMMAND + word + word).
 * @return Returns a boolean to control the turn of the player in combat. 
*/
bool World::HandleUserInputCombat(const std::vector<std::string>& userInput)
{
	bool player_turn = true;
	std::string userCommand = toLowerCase(userInput.at(0));
	std::string userParameter = userInput.size() > 1 ? toLowerCase(userInput.at(1)) : "";
	std::string userParameter2 = userInput.size() > 2 ? toLowerCase(userInput.at(2)) : "";

	if (m_commands.GO == userCommand)
	{
		std::cout << "You can't go anywhere! Your enemy would not let you escape." << std::endl << std::endl;

	}
	else if (m_commands.LOOK_1 == userCommand || m_commands.LOOK_2 == userCommand)
	{
		std::cout << "It's not the time to look around! The enemy is just in front of you." << std::endl << std::endl;
	}
	else if (m_commands.INVENTORY_1 == userCommand || m_commands.INVENTORY_2 == userCommand)
	{
		player->Inventory();
	}
	else if (m_commands.EQUIP_1 == userCommand || m_commands.EQUIP_2 == userCommand)
	{
		player->Equip();
	}
	else if (m_commands.UNEQUIP_1 == userCommand || m_commands.UNEQUIP_2 == userCommand)
	{
		player->UnEquip();
	}
	else if (m_commands.EXAMINE_1 == userCommand || m_commands.EXAMINE_2 == userCommand)
	{
		player->Examine(userParameter, userParameter2);
	}
	else if (m_commands.ATTACK_1 == userCommand || m_commands.ATTACK_2 == userCommand)
	{
		player->Attack(userParameter,m_ptrCurrentRoom->enemy_room);
		player_turn = false;
	}
	else if (m_commands.HELP_1 == userCommand || m_commands.HELP_2 == userCommand)
	{
		HelpCombatCommand();
	}
	else if (m_commands.QUIT_1 == userCommand || m_commands.QUIT_2 == userCommand)
	{
		GameOver();
	}
	else if (m_commands.USE_1 == userCommand || m_commands.USE_2 == userCommand)
	{
		player->Use(userParameter);
		player_turn = false;
	}
	else if (m_commands.STATS_1 == userCommand || m_commands.STATS_2 == userCommand)
	{
		player->Status();
	}
	else
		std::cout << "Invalid or wrong usage command in combat. Please try again." << std::endl;

	return player_turn;
}

void World::HandleStoryText() 
{
	if (m_ptrCurrentRoom == m_rooms[village])
		m_ptrStory->indexStory(0);
	else if (m_ptrCurrentRoom == m_rooms[forest_greatTree])
		m_ptrStory->indexStory(1);
	else if (HandleStoryAllGemsCondition())
		m_ptrStory->indexStory(2);
	else if (m_activateBoss)/*antes de combatir con el boss*/
		m_ptrStory->indexStory(3);
	else if (m_ptrCurrentRoom->enemy_room != nullptr && m_ptrCurrentRoom->enemy_room->current_health_points <= 0
		&& m_ptrCurrentRoom->enemy_room->name == "Infernal Witch")/*despues de matar el boss */
		m_ptrStory->indexStory(4);

}

bool World::HandleStoryAllGemsCondition()
{
	if (player->IsItemInInventory("Earth gem") && player->IsItemInInventory("Life gem") &&
		player->IsItemInInventory("Water gem"))
		return true;
	else if (player->IsItemInInventory("Earth gem") && player->IsItemInInventory("Life gem") &&
		player->IsItemInInventory("Hydrosword"))
		return true;
	else if (player->IsItemInInventory("Earth gem") && player->IsItemInInventory("Vital sword") &&
		player->IsItemInInventory("Water gem"))
		return true;
	else if (player->IsItemInInventory("Geosword") && player->IsItemInInventory("Life gem") &&
		player->IsItemInInventory("Water gem"))
		return true;
	else if (player->IsItemInInventory("Ethereal sword") && player->IsItemInInventory("Water gem"))
		return true;
	else if (player->IsItemInInventory("Muddy sword") && player->IsItemInInventory("Life gem"))
		return true;
	else if (player->IsItemInInventory("Blessed sword") && player->IsItemInInventory("Earth gem"))
		return true;

	return false;
}

void World::HelpCommand() const
{
	std::cout << "\nHere's the list of commands you can use:" << std::endl << std::endl;

	std::cout << toUpperCase(m_commands.GO) << "\t\t Command whose usage is to move through the map. You need to specify a direction. Values: GO (N)ORTH, (S)OUTH, (E)AST, (W)EST." << std::endl;
	std::cout << toUpperCase(m_commands.LOOK_1) << " / " << toUpperCase(m_commands.LOOK_2)
		<< "\t Command whose usage is to describe the available paths that you can go." << std::endl;
	std::cout << toUpperCase(m_commands.TAKE_1) << " / " << toUpperCase(m_commands.TAKE_2)
		<< "\t Command whose usage is to take/grab an item and put it in your inventory." << std::endl;
	std::cout << toUpperCase(m_commands.DROP_1) << " / " << toUpperCase(m_commands.DROP_2)
		<< "\t Command whose usage is to drop the item you specify from the inventory and leave it on the current room." << std::endl;
	std::cout << toUpperCase(m_commands.EXAMINE_1) << " / " << toUpperCase(m_commands.EXAMINE_2)
		<< "\t Command whose usage is to describe the item you specify (if you have it on the inventory or exists in the room)." << std::endl;
	std::cout << toUpperCase(m_commands.EQUIP_1) << " / " << toUpperCase(m_commands.EQUIP_2)
		<< "\t Command whose usage is to equip the item you specify (only specific items can be equiped)." << std::endl;
	std::cout << toUpperCase(m_commands.UNEQUIP_1) << " / " << toUpperCase(m_commands.UNEQUIP_2)
		<< "\t Command whose usage is to unequip the item you specify (only if you have it equiped)." << std::endl;
	std::cout << toUpperCase(m_commands.LOOT_1) << " / " << toUpperCase(m_commands.LOOT_2)
		<< "\t Command whose usage is to put all the items into your inventory." << std::endl;
	std::cout << toUpperCase(m_commands.INVENTORY_1) << " / " << toUpperCase(m_commands.INVENTORY_2)
		<< "\t Command whose usage is to show all items inside the inventory." << std::endl;
	std::cout << toUpperCase(m_commands.COMBINE_1) << " / " << toUpperCase(m_commands.COMBINE_2)
		<< "\t Command whose usage is to show combine menu, to combine 2 items." << std::endl;
	std::cout << toUpperCase(m_commands.STATS_1) << " / " << toUpperCase(m_commands.STATS_2)
		<< "\t Command whose usage is to show the stats of Jack and equiped items." << std::endl;
	std::cout << toUpperCase(m_commands.USE_1) << " / " << toUpperCase(m_commands.USE_2)
		<< "\t Command whose usage is to use the item you specify that is in your inventory." << std::endl;
	std::cout << toUpperCase(m_commands.QUIT_1) << " / " << toUpperCase(m_commands.QUIT_2)
		<< "\t Command whose usage is to close the game." << std::endl;
	std::cout << std::endl;
}

void World::HelpCombatCommand() const
{
	std::cout << "\nHere's the list of commands you can use in combat:" << std::endl << std::endl;

	std::cout << toUpperCase(m_commands.EXAMINE_1) << " / " << toUpperCase(m_commands.EXAMINE_2)
		<< "\t Command whose usage is to describe the item you specify (if you have it on the inventory)." << std::endl;
	std::cout << toUpperCase(m_commands.ATTACK_1) << " / " << toUpperCase(m_commands.ATTACK_2)
		<< "\t Command whose usage is to attack an enemy." << std::endl;
	std::cout << toUpperCase(m_commands.INVENTORY_1) << " / " << toUpperCase(m_commands.INVENTORY_2)
		<< "\t Command whose usage is to show all items inside the inventory." << std::endl;
	std::cout << toUpperCase(m_commands.EQUIP_1) << " / " << toUpperCase(m_commands.EQUIP_2)
		<< "\t Command whose usage is to equip the item you specify (only specific items can be equiped)." << std::endl;
	std::cout << toUpperCase(m_commands.UNEQUIP_1) << " / " << toUpperCase(m_commands.UNEQUIP_2)
		<< "\t Command whose usage is to unequip the item you specify (only if you have it equiped)." << std::endl;
	std::cout << toUpperCase(m_commands.STATS_1) << " / " << toUpperCase(m_commands.STATS_2)
		<< "\t Command whose usage is to show the stats of Jack and equiped items." << std::endl;
	std::cout << toUpperCase(m_commands.USE_1) << " / " << toUpperCase(m_commands.USE_2)
		<< "\t Command whose usage is to use the item you specify that is in your inventory." << std::endl;
	std::cout << toUpperCase(m_commands.QUIT_1) << " / " << toUpperCase(m_commands.QUIT_2)
		<< "\t Command whose usage is to close the game." << std::endl;
	std::cout << std::endl;

}

void World::GameOver()
{
	m_gameOver = true;
}

void World::GoDestination(const std::string& direction)
{
	if (direction == "north" || direction == "n")
	{
		m_ptrCurrentRoom = m_ptrCurrentRoom->ptrNeighbourNorth;
	}
	else if (direction == "south" || direction == "s")
	{
		m_ptrCurrentRoom = m_ptrCurrentRoom->ptrNeighbourSouth;
	}
	else if (direction == "east" || direction == "e")
	{
		m_ptrCurrentRoom = m_ptrCurrentRoom->ptrNeighbourEast;
	}
	else if (direction == "west" || direction == "w")
	{
		m_ptrCurrentRoom = m_ptrCurrentRoom->ptrNeighbourWest;
	}
}

/**
 * @brief Return player to checkpoint room if dies.
*/
void World::ReturnRoomCheckpoint()
{
	m_ptrCurrentRoom = m_rooms[forest_greatTree];
	player->SetHealth();
}