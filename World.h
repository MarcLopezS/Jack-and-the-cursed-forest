#ifndef World_h
#define World_h

#include <iostream>
#include <vector>

#include "Room.h"
#include "Player.h"
#include "TextsVideogame.h"

struct actions_command
{
	std::string LOOK_1 = "look";
	std::string LOOK_2 = "l";
	std::string GO = "go";
	std::string TAKE_1 = "take";
	std::string TAKE_2 = "pick";
	std::string DROP_1 = "drop";
	std::string DROP_2 = "put";
	std::string EQUIP_1 = "equip";
	std::string EQUIP_2 = "eq";
	std::string UNEQUIP_1 = "unequip";
	std::string UNEQUIP_2 = "uneq";
	std::string EXAMINE_1 = "examine";
	std::string EXAMINE_2 = "ex";
	std::string ATTACK_1 = "attack";
	std::string ATTACK_2 = "at";
	std::string LOOT_1 = "loot";
	std::string LOOT_2 = "lt";
	std::string INVENTORY_1 = "inventory";
	std::string INVENTORY_2 = "i";
	std::string STATS_1 = "stats";
	std::string STATS_2 = "st";
	std::string HELP_1 = "help";
	std::string HELP_2 = "h";
	std::string QUIT_1 = "quit";
	std::string QUIT_2 = "q";
	std::string USE_1 = "use";
	std::string USE_2 = "u";
	std::string COMBINE_1 = "combine";
	std::string COMBINE_2 = "c";

};

class World
{
public:
	World();
	~World();

	void Run();
	void Combat();
	void HandleUserInput(const std::vector<std::string>& userInput);
	bool HandleUserInputCombat(const std::vector<std::string>& userInput);
	void HandleStoryText();
	bool HandleStoryAllGemsCondition();
	void HelpCommand() const;
	void HelpCombatCommand() const;
	void GameOver();
	void GoDestination(const std::string& direction);
	void PrintCombatStats();

	Player* player;
	ListItems listItems;

private:

	void SetupRooms();
	void SetupNeighbors(Room* rooms);
	void SetupItems();
	void SetupEnemies();
	void SetupBoss();
	void RemoveBoss();
	void ReturnRoomCheckpoint();

	const int m_n_rooms = 16;

	Room* m_ptrCurrentRoom;
	TextsVideogame* m_ptrStory;

	std::vector<Room*> m_rooms;

	const actions_command m_commands;

	bool m_gameOver;
	bool m_activateBoss;


};



#endif