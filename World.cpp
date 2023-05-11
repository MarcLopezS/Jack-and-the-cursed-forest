#include <iostream>
#include <string>

#include "World.h"

World::World()
{
	SetupRooms();
	
	m_end = false;
}

World::~World()
{
	 m_rooms.clear();
}

void World::Run()
{
	std::string userInput;

	while(!m_end)
	{
		m_ptrCurrentRoom->PrintPropertiesRoom();

		std::cout << "what are you going to do now?" << std::endl;
		std::getline(std::cin, userInput);
		m_end = true;
	}
	
}

void World::SetupRooms()
{
	const size_t nRooms = 22;

	Room* rooms = new Room[nRooms];
	
	rooms[village].SetupDetailsRoom("Village", "The village where you have been living your entire life");
	m_ptrCurrentRoom = &rooms[village];

	rooms[forest_entrance].SetupDetailsRoom("Forest Entrance", "description");
	rooms[forest_greatTree].SetupDetailsRoom("Forest Great Tree", "description");
	rooms[river].SetupDetailsRoom("River", "description");
	rooms[water_Altar].SetupDetailsRoom("Water Altar", "description");
	rooms[spine_territory_1].SetupDetailsRoom("Spine territory zone 1", "description");
	rooms[spine_territory_2].SetupDetailsRoom("Spine territory zone 2", "description");
	rooms[spine_territory_3].SetupDetailsRoom("Spine territory zone 3", "description");
	rooms[spine_territory_4].SetupDetailsRoom("Spine territory zone 4", "description");
	rooms[spine_territory_5].SetupDetailsRoom("Spine territory zone 5", "description");
	rooms[spine_territory_6].SetupDetailsRoom("Spine territory zone 6", "description");
	rooms[spine_territory_7].SetupDetailsRoom("Spine territory zone 7", "description");
	rooms[spine_territory_8].SetupDetailsRoom("Spine territory zone 8", "description");
	rooms[spine_territory_9].SetupDetailsRoom("Spine territory zone 9", "description");
	rooms[spine_territory_10].SetupDetailsRoom("Spine territory zone 10", "description");
	rooms[life_altar].SetupDetailsRoom("Life Altar", "description");
	rooms[mossy_forest].SetupDetailsRoom("Mossy Forest", "description");
	rooms[cave_entrance].SetupDetailsRoom("Cave entrance", "description");
	rooms[mine].SetupDetailsRoom("Mine", "description");
	rooms[mineral_room].SetupDetailsRoom("Mineral Room", "description");
	rooms[warehouse].SetupDetailsRoom("Warehouse", "description");
	rooms[earth_altar].SetupDetailsRoom("Earth altar", "description");

	SetupNeighbors(rooms);

	for (size_t i = 0; i < nRooms; i++)
	{
		m_rooms.push_back(&rooms[i]);
	}
	
	rooms = nullptr;

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