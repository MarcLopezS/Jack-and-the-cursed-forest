#ifndef Creature_h
#define Creature_h

#include<string>
#include <vector>

enum CreatureType
{
	PLAYER,
	ENEMY,
	BOSS
};

class Creature
{
public:
	Creature();
	Creature(const std::string& name, const std::string& description, CreatureType creature_type);
	~Creature();

	int health_points;
	std::string name;
	std::string description;
	CreatureType creature_type;

private:

};



#endif //Creature_h
