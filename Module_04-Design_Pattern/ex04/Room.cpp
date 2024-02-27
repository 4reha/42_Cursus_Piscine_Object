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

bool Room::isInRoom(Person *p_person)
{
	return std::find(_occupants.begin(), _occupants.end(), p_person) != _occupants.end();
}

int Room::getOccupantCount()
{
	return _occupants.size();
}

bool Room::canEnter(Person *p_person)
{
	return true;
}

void Room::enter(Person *p_person)
{
	std::cout << p_person->getName() << " entered room " << ID << std::endl;
	_occupants.push_back(p_person);
}

void Room::exit(Person *p_person)
{
	std::cout << p_person->getName() << " exited room " << ID << std::endl;
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

//

Classroom *RoomList::getFreeClassroom()
{
	std::vector<Room *> list = getInstance()->getList();
	for (int i = 0; i < list.size(); i++)
	{
		Classroom *classroom = dynamic_cast<Classroom *>(list[i]);
		if (classroom)
		{
			if (classroom->getOccupantCount() == 0)
			{
				return classroom;
			}
		}
	}
	return nullptr;
}