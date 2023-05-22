#ifndef Player_h
#define Player_h

#include "Creature.h"
#include "Item.h"

class Player : Creature
{
public:
	Player();
	~Player();

	void Go(const std::string& userInput);
	void Look(const std::string& userInput) const;
	void Take(const std::string& userInput);
	void Drop(const std::string& userInput);
	void Inventory() const;
	void Equip(const std::string& userInput);
	void UnEquip(const std::string& userInput);
	void Examine(const std::string& userInput) const;
	void Attack(const std::string& userInput);
	void Loot(const std::string& userInput);
	//void Exit(const std::string& userInput);
	


private:
	
	std::vector<Item> invetory;

};


#endif