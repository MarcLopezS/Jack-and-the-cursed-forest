#ifndef Creature_h
#define Creature_h

#include<string>
#include <vector>

enum class CreatureType
{
	PLAYER,
	ENEMY,
	BOSS
};

class Creature
{
public:
	
	Creature(const std::string& name, const std::string& description, CreatureType creature_type);
	~Creature();

	virtual void SetHealth();

	int max_health_points;
	int current_health_points;
	std::string name;
	std::string description;
	CreatureType creature_type;

private:

};



#endif //Creature_h
