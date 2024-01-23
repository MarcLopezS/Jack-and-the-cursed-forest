#ifndef Enemy_h
#define Enemy_h

#include "Item.h"
#include "Player.h"
class Player;

class Enemy : public Creature
{
public:
	Enemy(const std::string& name, const std::string& description, CreatureType creature_type, Item* enemy_weapon);
	~Enemy();

	void SetHealth() override;
	void Attack(Creature* player);
	void Damage(Player* player,int damage_points);
	void Defeat(Player* player);

	Item* enemy_weapon;
	Item* drop_item;
};


#endif
