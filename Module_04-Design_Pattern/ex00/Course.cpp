#include "Course.hpp"

Course::Course(std::string p_name) : _name(p_name), _responsable(nullptr), _numberOfClassToGraduate(10), _maximumNumberOfStudent(10) {}

void Course::assign(Professor *p_professor)
{
	_responsable = p_professor;
}

void Course::subscribe(Student *p_student)
{
	if (_students.size() < _maximumNumberOfStudent)
	{
		_students.push_back(p_student);
	}
	else
	{
		std::cout << "The course is full" << std::endl;
	}
}