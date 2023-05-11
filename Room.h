#ifndef Room_h_
#define Room_h_

#include <string>

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
	
	void SetupRoom(const std::string& name = std::string(), const std::string& description = std::string());
	void SetNeighbors(Room* neighborNorth, Room* neighborSouth, Room* neighborEast, Room* neighborWest);
	void OutputNeighbors();

	void PrintPropertiesRoom();


	std::string m_name;
	std::string m_description;
	Room* ptrNeighbourNorth;
	Room* ptrNeighbourSouth;
	Room* ptrNeighbourEast;
	Room* ptrNeighbourWest;


};




#endif // Room_h_