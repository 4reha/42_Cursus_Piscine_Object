#pragma once
#include <iostream>
#include <vector>
#include "Singleton.hpp"

class Person;
class Course;
class Form;

class Room
{
private:
	static long long _lastID;
	long long ID;
	std::vector<Person *> _occupants;

public:
	Room();
	long long getID();
	virtual bool canEnter(Person *);
	void enter(Person *);
	void exit(Person *);
	int getOccupantCount();
	bool isInRoom(Person *);

	void printOccupant();
};

class Classroom : public Room
{
private:
	Course *_currentCourse;

public:
	Classroom();
	bool canEnter(Person *);
	void assignCourse(Course *p_course);
	Course *getCourse();
};

class SecretarialOffice : public Room
{
private:
	std::vector<Form *> _archivedForms;
public:
};

class HeadmasterOffice : public Room
{
private:
public:
};

class StaffRestRoom : public Room
{
private:
public:
};

class Courtyard : public Room
{
private:
public:
};

class RoomList : public Singleton<Room *>
{
	public:
	static Classroom *getFreeClassroom();
};