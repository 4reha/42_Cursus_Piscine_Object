#include "Room.hpp"

long long Room::_lastID = 0;

Room::Room() : ID(_lastID++)
{
}

long long Room::getID()
{
	return ID;
}

Classroom::Classroom() : _currentRoom(nullptr)
{
}