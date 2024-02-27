#include "Course.hpp"
#include "Person.hpp"

Course::Course(std::string p_name) : _name(p_name), _responsable(nullptr), _numberOfClassToGraduate(3), _maximumNumberOfStudent(3) {}

std::string Course::getName()
{
	return _name;
}

int Course::getNumberOfClassToGraduate()
{
	return _numberOfClassToGraduate;
}

int Course::getMaximumNumberOfStudent()
{
	return _maximumNumberOfStudent;
}

Professor *Course::getResponsable()
{
	return _responsable;
}

std::vector<Student *> Course::getStudents()
{
	return _students;
}

void Course::assign(Professor *p_professor)
{
	_responsable = p_professor;
}

void Course::subscribe(Student *p_student)
{
	if (_students.size() < _maximumNumberOfStudent)
	{
		if (std::find(_students.begin(), _students.end(), p_student) == _students.end())
			_students.push_back(p_student);
	}
	else
		std::cout << "The course is full" << std::endl;
}

void Course::unsubscribe(Student *p_student)
{
	_students.erase(std::remove(_students.begin(), _students.end(), p_student), _students.end());
}

//

Course *CourseList::getFreeCourse()
{
	std::vector<Course *> list = getInstance()->getList();
	for (int i = 0; i < list.size(); i++)
	{
		if (list[i]->getStudents().size() < list[i]->getMaximumNumberOfStudent())
		{
			return list[i];
		}
	}
	return nullptr;
}

Course *CourseList::getUnassignedCourse()
{
	std::vector<Course *> list = getInstance()->getList();
	for (int i = 0; i < list.size(); i++)
	{
		if (!list[i]->getResponsable())
		{
			return list[i];
		}
	}
	return nullptr;
}