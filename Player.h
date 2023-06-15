#ifndef Player_h
#define Player_h

#include "Creature.h"
#include "Item.h"
#include "Room.h"
#include "Global.h"

class Player : public Creature
{
public:
	Player(const std::string& name, const std::string& description, CreatureType creature_type);
	~Player();

	bool Go(const std::string& userInput);
	void Look(Room* currentRoom) const;
	void Take(const std::string& userInput, Room* currentRoom);
	void Drop(const std::string& userInput, Room* currentRoom);
	void Inventory() const;
	void Equip(const std::string& userInput);
	void UnEquip(const std::string& userInput);
	void Examine(const std::string& userInput) const;
	void Attack(const std::string& userInput);
	void Loot(const std::string& userInput);
	void Use(const std::string& userInput);
	void Status() const;
	//void Exit(const std::string& userInput);

	void SetHealth() override;

	std::vector<Item*> GetInventory();
	bool HandleItemInput(const std::string& itemInput);
	


private:
	const ListItems listItems;

	std::vector<Item*> inventory;
	std::vector<Item*> equipedItems;

};


#endif