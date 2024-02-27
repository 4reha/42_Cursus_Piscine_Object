#pragma once
#include <iostream>
#include <vector>
#include "Singleton.hpp"

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
	std::string getName();
	Room *room();
};

class Student : public Person
{
private:
	std::vector<Course *> _subscribedCourse;

public:
	Student(std::string p_name);
	void attendClass(Classroom *p_classroom);
	void exitClass();
	void graduate(Course *p_course);
};

class StudentList : public Singleton<Student *>
{
};
