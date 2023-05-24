#include <iostream>
#include "Creature.h"


Creature::Creature(const std::string& name, const std::string& description, CreatureType creature_type)
{
	this->name = name;
	this->description = description;
	this->creature_type = creature_type;
	SetHealth();
	
}
Creature::~Creature()
{
}

void Creature::SetHealth() 
{
	switch (creature_type)
	{
		case CreatureType::PLAYER:
			health_points = 100;
			break;
		case CreatureType::ENEMY:
			health_points = 50;
			break;
		case CreatureType::BOSS:
			health_points = 500;
			break;
	}
}