#ifndef Player_h
#define Player_h

#include "Creature.h"
#include "Room.h"
#include "Global.h"
#include "Enemy.h"
#include "Combination.h"

class Enemy;

class Player : public Creature
{
public:
	Player(const std::string& name, const std::string& description, CreatureType creature_type);
	~Player();

	bool Go(const std::string& userInput, Room* current_room);
	void Look(Room* currentRoom) const;
	void Take(const std::string& userInput, const std::string& userInput2, Room* currentRoom);
	void Drop(const std::string& userInput,const std::string& userInput2, Room* currentRoom);
	void Inventory() const;
	void Equip();
	void UnEquip();
	void Examine(const std::string& userInput, const std::string& userInput2) const;
	void Attack(const std::string& userInput, Enemy* enemy);
	void Use(const std::string& userInput);
	void Use(const std::string& userInput, Room* currentRoom, bool& activateBoss);
	void Combine();
	void Status() const;
	//void Exit(const std::string& userInput);

	void LootEnemy(Item* enemy_item);
	void SetHealth() override;

	std::vector<Item*> GetInventory();
	bool HandleItemInput(const std::string& itemInput);

	void TakeItemToInventory(bool& item_exist, int posItem, Room* currentRoom);
	bool IsItemInInventory(const std::string& name);
	void DropItemToRoom(bool& item_exist, int posItem, Room* currentRoom);

private:

	const ListItems listItems;
	int strength;

	std::vector<Item*> inventory;
	Item* equipedWeapon;

};


#endif