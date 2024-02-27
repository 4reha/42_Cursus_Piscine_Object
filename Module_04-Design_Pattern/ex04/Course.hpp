#pragma once
#include <iostream>
#include <vector>
#include "Singleton.hpp"

class Professor;
class Student;

class Course
{
private:
	std::string _name;
	Professor *_responsable;
	std::vector<Student *> _students;
	int _numberOfClassToGraduate;
	int _maximumNumberOfStudent;

public:
	Course(std::string p_name);
	std::string getName();

	int getNumberOfClassToGraduate();
	int getMaximumNumberOfStudent();
	std::vector<Student *> getStudents();
	Professor *getResponsable();

	void assign(Professor *p_professor);
	void subscribe(Student *p_student);
	void unsubscribe(Student *p_student);
};

class CourseList : public Singleton<Course *>
{
public:
	static Course *getFreeCourse();
	static Course *getUnassignedCourse();
};