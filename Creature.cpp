#include <iostream>
#include "Creature.h"


Creature::Creature()
{
	
}

Creature::Creature(const std::string& name, const std::string& description, CreatureType creature_type)
{
	this->name = name;
	this->description = description;
	this->creature_type = creature_type;
}
Creature::~Creature()
{
}