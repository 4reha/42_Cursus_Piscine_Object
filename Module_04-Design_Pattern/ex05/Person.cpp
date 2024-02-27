#include "Person.hpp"
#include "Room.hpp"
#include "Course.hpp"
#include "Staff.hpp"

Person::Person(std::string p_name) : _name(p_name), _currentRoom(nullptr){};

Room *Person::room()
{
	return _currentRoom;
}

std::string Person::getName()
{
	return _name;
}

void Person::update(Event _event)
{
	if (_event == RingBell)
	{
		std::cout << _name << " has been notified with RingBell" << std::endl;
		if (this->_currentRoom->isInRoom(this))
		{
			this->_currentRoom->exit(this);
		}
		else
		{
			this->_currentRoom->enter(this);
		}
	}
}

//

Student::Student(std::string p_name) : Person(p_name){};

std::map<Course *, int> Student::getSubscribedCourse()
{
	return _subscribedCourse;
}

Course *Student::getFinishedCourse()
{
	std::map<Course *, int>::iterator it = _subscribedCourse.begin();
	while (it != _subscribedCourse.end())
	{
		if (it->second >= it->first->getNumberOfClassToGraduate())
		{
			return it->first;
		}
		it++;
	}
	return nullptr;
}

int Student::getCourseAttendance(Course *p_course)
{

	if (_subscribedCourse.find(p_course) == _subscribedCourse.end())
		return 0;

	return _subscribedCourse[p_course];
}

void Student::attendClass(Classroom *p_classroom)
{
	_currentRoom = p_classroom;
	p_classroom->enter(this);
	_subscribedCourse[p_classroom->getCourse()]++;
}

void Student::exitClass()
{
	if (_currentRoom)
	{
		_currentRoom->exit(this);
	}
	_currentRoom = nullptr;
}

void Student::subscribeCourse(Course *p_course)
{
	if (_subscribedCourse.find(p_course) == _subscribedCourse.end())
		_subscribedCourse[p_course] = 0;
}

void Student::joinCourse()
{
	Headmaster *headmaster = StaffList::getHeadmaster();
	if (headmaster)
		headmaster->notify(this, SubscriptionToCourse);
}

void Student::graduate(Course *p_course)
{
	if (_subscribedCourse[p_course] >= p_course->getNumberOfClassToGraduate())
	{
		_subscribedCourse.erase(p_course);
		p_course->unsubscribe(this);
		std::cout << _name << " has graduated from " << p_course->getName() << std::endl;
	}
}

//

std::map<Student *, Course *> StudentList::getGraduatedStudents()
{
	std::map<Student *, Course *> graduatedStudents;
	for (int i = 0; i < _list.size(); i++)
	{
		std::map<Course *, int> courses = _list[i]->getSubscribedCourse();
		std::map<Course *, int>::iterator it = courses.begin();
		while (it != courses.end())
		{
			if (it->second >= it->first->getNumberOfClassToGraduate())
			{
				graduatedStudents[_list[i]] = it->first;
				// break;
			}
			it++;
		}
	}
	return graduatedStudents;
}