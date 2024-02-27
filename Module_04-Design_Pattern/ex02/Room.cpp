#include "Room.hpp"
#include "Person.hpp"

long long Room::_lastID = 0;

Room::Room() : ID(_lastID++)
{
}

long long Room::getID()
{
	return ID;
}

bool Room::canEnter(Person *p_person)
{
	return true;
}

void Room::enter(Person *p_person)
{
	_occupants.push_back(p_person);
}

void Room::exit(Person *p_person)
{
	_occupants.erase(std::remove(_occupants.begin(), _occupants.end(), p_person), _occupants.end());
}

void Room::printOccupant()
{
	for (int i = 0; i < _occupants.size(); i++)
	{
		std::cout << _occupants[i]->getName() << std::endl;
	}
}

//

Classroom::Classroom() : _currentCourse(nullptr)
{
}

bool Classroom::canEnter(Person *p_person)
{
	if (!_currentCourse)
		return false;
	return true;
}

void Classroom::assignCourse(Course *p_course)
{
	_currentCourse = p_course;
}

Course *Classroom::getCourse()
{
	return _currentCourse;
}