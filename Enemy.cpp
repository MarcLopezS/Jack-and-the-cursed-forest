#include "Enemy.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Enemy::Enemy(const std::string& name, const std::string& description, CreatureType creature_type, Item* enemy_weapon)
	: Creature(name, description, creature_type)
{
	SetHealth();
	this->enemy_weapon = enemy_weapon;

	if (creature_type == CreatureType::ENEMY)
	{
		drop_item = new Item("Potion", "A liquid that helps healing wounds.", ItemType::COMMON, false);
	}
	else if(creature_type == CreatureType::BOSS){
		drop_item = new Item("Fire Gem", "A special gem that, according to the legend, has the power to control fire. It is said that was created by the Devil itself.", ItemType::KEY_ITEM, true);
	}
}

Enemy::~Enemy()
{
	delete drop_item;
}

void Enemy::SetHealth()
{
	//Seed value
	srand((unsigned)time(NULL));

	if(creature_type == CreatureType::BOSS)
	{
		max_health_points = 500;
		current_health_points = 500;
	}
	else {
		//enemies with health between 30-50 points
		max_health_points = 30 + (rand() % 21);
		current_health_points = max_health_points;
	}
}

void Enemy::Attack(Creature* player)
{
	//Seed value
	srand((unsigned)time(NULL));

	//random damage with limit +5/-5 to the original value weapon
	int damage_points = enemy_weapon->GetValueItem() + (rand() % 11) - 5;

	player->current_health_points -= damage_points;

	std::cout << name << " attacked you. You take " << damage_points << " damage points." << std::endl;

}

void Enemy::Damage(Player* player, int damage_points)
{
	current_health_points -= damage_points;

	std::cout << name << " received " << damage_points << " damage points.\n" << std::endl;

	if(current_health_points <= 0)
	{
		Defeat(player);
	}
}

void Enemy::Defeat(Player* player)
{
	//Seed value
	srand((unsigned)time(NULL));

	std::cout << "You defeated " << name << "!" << std::endl;

	//Boss 100% drop prob. Common enemy 15%
	int drop_probability = creature_type == CreatureType::ENEMY ? 15 : 100;

	int random_number = rand() % 100 + 1;
		
	if (random_number <= drop_probability)
	{
		std::cout << name << " dropped a " << drop_item->name  << "." << std::endl;
		//inventory.push_back(currentRoom->items_room[i]);
		player->GetInventory().push_back(drop_item);
		drop_item = nullptr;
	}
	
}