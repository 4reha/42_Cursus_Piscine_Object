#pragma once
#include <iostream>
#include <vector>

class Room;
class Course;
class Classroom;

class Person
{
private:
	std::string _name;
	Room *_currentRoom;

public:
	Person(std::string p_name);
	Room *room();
};

class Student : public Person
{
private:
	std::vector<Course *> _subscribedCourse;

public:
	void attendClass(Classroom *p_classroom);
	void exitClass();
	void graduate(Course *p_course);
};
