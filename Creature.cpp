#include <iostream>
#include "Creature.h"


Creature::Creature(const std::string& name, const std::string& description, CreatureType creature_type)
{
	this->name = name;
	this->description = description;
	this->creature_type = creature_type;	
}
Creature::~Creature()
{
}

void Creature::SetHealth()
{
	switch (creature_type)
	{
		case CreatureType::PLAYER:
			max_health_points = 100;
			current_health_points = 20;
			break;
		case CreatureType::ENEMY:
			max_health_points = 50;
			current_health_points = 50;
			break;
		case CreatureType::BOSS:
			max_health_points = 500;
			current_health_points = 500;
			break;
	}
}