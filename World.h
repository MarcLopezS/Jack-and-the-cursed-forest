#ifndef World_h
#define World_h

#include <iostream>
#include <vector>

#include "Room.h"


class World
{
public:
	World();
	~World();

	void Run();

	

private:

	void SetupRooms();
	void SetupNeighbors(Room* rooms);
	const int m_n_rooms = 16;
	Room* m_ptrCurrentRoom;
	std::vector<Room*> m_rooms;
	bool m_end;

};



#endif