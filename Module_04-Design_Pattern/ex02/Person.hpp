#pragma once
#include <iostream>
#include <map>
#include "Singleton.hpp"

class Room;
class Course;
class Classroom;

class Person
{
protected:
	std::string _name;
	Room *_currentRoom;

public:
	Person(std::string p_name);
	virtual std::string getName();
	Room *room();
};

class Student : public Person
{
private:
	std::map<Course *, int> _subscribedCourse;

public:
	Student(std::string p_name);
	std::map<Course *, int> getSubscribedCourse();
	Course *getFinishedCourse();
	int getCourseAttendance(Course *p_course);
	void attendClass(Classroom *p_classroom);
	void exitClass();
	void subscribeCourse(Course *p_course);
	void graduate(Course *p_course);
};

class StudentList : public Singleton<Student *>
{
public:
	static std::map<Student *, Course *> getGraduatedStudents();
};
