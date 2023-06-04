#ifndef Enemy_h
#define Enemy_h

#include "Item.h"
#include "Creature.h"

class Enemy : Creature
{
public:
	Enemy(const std::string& name, const std::string& description, CreatureType creature_type, Item* enemy_weapon);
	~Enemy();

	void SetHealth() override;
	void Attack(Creature* player);

	Item* enemy_weapon;
};


#endif
