#ifndef Room_h_
#define Room_h_

#include <string>
#include <vector>
#include "Item.h"
class Enemy;

enum locations
{
	village = 0,
	forest_entrance,
	forest_greatTree,
	river,
	water_Altar,
	spine_territory_1,
	spine_territory_2,
	spine_territory_3,
	spine_territory_4,
	spine_territory_5,
	spine_territory_6,
	spine_territory_7,
	spine_territory_8,
	spine_territory_9,
	spine_territory_10,
	life_altar,
	mossy_forest,
	cave_entrance,
	mine,
	mineral_room,
	warehouse,
	earth_altar

};



class Room
{
public:
	Room();
	Room(const std::string& name, const std::string& description);
	~Room();

	void SetupEnemy(Enemy* enemy);
	void SetupRoom(const std::string& name = std::string(), const std::string& description = std::string());
	void SetupDetailsRoom(const std::string& name = std::string(), const std::string& description = std::string());
	void SetupItem(Item* item);
	void SetupItem(std::vector<Item> items);
	void SetNeighbors(Room* neighborNorth, Room* neighborSouth, Room* neighborEast, Room* neighborWest);
	void OutputNeighbors();

	bool checkDirection(const std::string& direction);
	void PrintPropertiesRoom();


	std::string name;
	std::string description;
	Room* ptrNeighbourNorth;
	Room* ptrNeighbourSouth;
	Room* ptrNeighbourEast;
	Room* ptrNeighbourWest;

	std::vector<Item*> items_room;

	Enemy* enemy_room;


};




#endif // Room_h_