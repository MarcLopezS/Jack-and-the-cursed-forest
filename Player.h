#ifndef Player_h
#define Player_h

#include "Creature.h"

class Player : Creature
{
public:
	Player();
	~Player();

	void Go(const std::vector<std::string>& userInput);
	void Look(const std::vector<std::string>& userInput) const;
	void Take(const std::vector<std::string>& userInput);
	void Drop(const std::vector<std::string>& userInput);
	void Inventory() const;
	void Equip(const std::vector<std::string>& userInput);
	void UnEquip(const std::vector<std::string>& userInput);
	void Examine(const std::vector<std::string>& userInput) const;
	void Attack(const std::vector<std::string>& userInput);
	void Loot(const std::vector<std::string>& userInput);
	void Exit(const std::vector<std::string>& userInput);
	


private:

};


#endif