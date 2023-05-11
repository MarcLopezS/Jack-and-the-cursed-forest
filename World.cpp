#include <iostream>
#include <string>

#include "World.h"

World::World()
	: m_ptrCurrentRoom(nullptr)
{
	SetupRooms();
}

World::~World()
{

}

void World::Run()
{
	
}

void World::SetupRooms()
{
	const size_t nRooms = 22;

	Room* rooms = new Room[nRooms];
	//Room room;

	//room = new Room[];
	/*room.SetupRoom("Village", "The village where you have lived your entire life");
	m_rooms.push_back(&room);
	*/
	rooms[village].SetupRoom("Village", "The village where you have lived your entire life");
	rooms[forest_entrance].SetupRoom("Forest Entrance", "description");
	rooms[forest_greatTree].SetupRoom("Forest Great Tree", "description");
	rooms[river].SetupRoom("River", "description");
	rooms[water_Altar].SetupRoom("Water Altar", "description");
	rooms[spine_territory_1].SetupRoom("Spine territory zone 1", "description");
	rooms[spine_territory_2].SetupRoom("Spine territory zone 2", "description");
	rooms[spine_territory_3].SetupRoom("Spine territory zone 3", "description");
	rooms[spine_territory_4].SetupRoom("Spine territory zone 4", "description");
	rooms[spine_territory_5].SetupRoom("Spine territory zone 5", "description");
	rooms[spine_territory_6].SetupRoom("Spine territory zone 6", "description");
	rooms[spine_territory_7].SetupRoom("Spine territory zone 7", "description");
	rooms[spine_territory_8].SetupRoom("Spine territory zone 8", "description");
	rooms[spine_territory_9].SetupRoom("Spine territory zone 9", "description");
	rooms[spine_territory_10].SetupRoom("Spine territory zone 10", "description");
	rooms[life_altar].SetupRoom("Life Altar", "description");
	rooms[mossy_forest].SetupRoom("Mossy Forest", "description");
	rooms[cave_entrance].SetupRoom("Cave entrance", "description");
	rooms[mine].SetupRoom("Mine", "description");
	rooms[mineral_room].SetupRoom("Mineral Room", "description");
	rooms[warehouse].SetupRoom("Warehouse", "description");
	rooms[earth_altar].SetupRoom("Earth altar", "description");

	for (size_t i = 0; i < nRooms; i++)
	{
		m_rooms.push_back(&rooms[i]);

		m_rooms.back()->PrintPropertiesRoom();
	}
	
	
	delete[] rooms;

}

void World::SetupNeighbors(Room* rooms)
{
	rooms[village].SetNeighbors(&rooms[forest_entrance], nullptr, nullptr, nullptr);
	rooms[forest_entrance].SetNeighbors(&rooms[forest_greatTree], &rooms[village], nullptr, nullptr);
	rooms[forest_greatTree].SetNeighbors(&rooms[spine_territory_1], &rooms[forest_entrance], &rooms[mossy_forest], &rooms[river]);
	rooms[river].SetNeighbors(nullptr, nullptr, &rooms[forest_greatTree], &rooms[water_Altar]);
	rooms[water_Altar].SetNeighbors(nullptr, nullptr, &rooms[river], nullptr);
	rooms[spine_territory_1].SetNeighbors(nullptr, &rooms[forest_greatTree], &rooms[spine_territory_2], nullptr);
	rooms[spine_territory_2].SetNeighbors(&rooms[spine_territory_3], nullptr, nullptr, &rooms[spine_territory_1]);
	rooms[spine_territory_3].SetNeighbors(nullptr, &rooms[spine_territory_2], &rooms[spine_territory_4], nullptr);
	rooms[spine_territory_4].SetNeighbors(&rooms[spine_territory_5], nullptr, nullptr, &rooms[spine_territory_3]);
	rooms[spine_territory_5].SetNeighbors(&rooms[spine_territory_6], &rooms[spine_territory_4], nullptr, nullptr);
	rooms[spine_territory_6].SetNeighbors(nullptr, &rooms[spine_territory_5], nullptr, &rooms[spine_territory_7]);
	rooms[spine_territory_7].SetNeighbors(&rooms[spine_territory_10], nullptr, &rooms[spine_territory_6], &rooms[spine_territory_8]);
	rooms[spine_territory_8].SetNeighbors(nullptr, &rooms[spine_territory_9], &rooms[spine_territory_7], nullptr);
	rooms[spine_territory_9].SetNeighbors(&rooms[spine_territory_8], nullptr, nullptr, nullptr);
	rooms[spine_territory_10].SetNeighbors(&rooms[life_altar], &rooms[spine_territory_7], nullptr, nullptr);
	rooms[life_altar].SetNeighbors(nullptr, &rooms[spine_territory_10], nullptr, nullptr);
	rooms[mossy_forest].SetNeighbors(nullptr, nullptr, &rooms[cave_entrance], &rooms[forest_greatTree]);
	rooms[cave_entrance].SetNeighbors(nullptr, nullptr, &rooms[mine], &rooms[mossy_forest]);
	rooms[mine].SetNeighbors(&rooms[warehouse], &rooms[mineral_room], &rooms[earth_altar], &rooms[cave_entrance]);
	rooms[mineral_room].SetNeighbors(&rooms[mine], nullptr, nullptr, nullptr);
	rooms[warehouse].SetNeighbors(nullptr, &rooms[mine], nullptr, nullptr);
	rooms[earth_altar].SetNeighbors(nullptr, nullptr, nullptr, &rooms[mine]);
}