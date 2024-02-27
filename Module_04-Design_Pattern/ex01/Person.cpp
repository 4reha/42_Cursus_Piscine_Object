#include "Person.hpp"

Person::Person(std::string p_name) : _name(p_name), _currentRoom(nullptr){};

Room *Person::room()
{
	return _currentRoom;
}

std::string Person::getName()
{
	return _name;
}


Student::Student(std::string p_name) : Person(p_name){};

