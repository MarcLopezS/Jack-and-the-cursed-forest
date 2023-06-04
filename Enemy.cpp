#include "Enemy.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Enemy::Enemy(const std::string& name, const std::string& description, CreatureType creature_type, Item* enemy_weapon)
	: Creature(name, description, creature_type)
{
	SetHealth();
	this->enemy_weapon = enemy_weapon;
}

Enemy::~Enemy()
{
}

void Enemy::SetHealth()
{
	//Seed value
	srand((unsigned)time(NULL));

	if(creature_type == CreatureType::BOSS)
	{
		health_points = 500;
	}
	else {
		//enemies with health between 30-50 points
		health_points = 30 + (rand() % 21);
	}
}

void Enemy::Attack(Creature* player)
{
	//Seed value
	srand((unsigned)time(NULL));

	//random damage with limit +5/-5 to the original value weapon
	int damage_points = enemy_weapon->GetValueItem() + (rand() % 11) - 5;

	player->health_points -= damage_points;

	std::cout << name << " attacked you. You take " << damage_points << " damage points." << std::endl;

}