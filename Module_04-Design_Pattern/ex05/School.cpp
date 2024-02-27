#include "School.hpp"

School::School()
{
	StaffList::getInstance()->add(new Headmaster("Dumbledore"));
	StaffList::getInstance()->add(new Secretary("Hagrid"));

	this->_bellEvent = BellEvent();
}

School::~School() {}

void School::runDayRoutine()
{

	std::cout << "<< =================== >>" << std::endl;
	std::cout << "<< Graduation Ceremony >>" << std::endl;
	std::cout << "<< =================== >>" << std::endl;

	launchClasses();
	std::cout << "recreation break" << std::endl;
	requestRingBell();
	requestRingBell();

	launchClasses();
	std::cout << "lunch time" << std::endl;
	requestRingBell();
	requestRingBell();

	launchClasses();
	std::cout << "recreation break" << std::endl;
	requestRingBell();
	requestRingBell();

	launchClasses();
}

void School::launchClasses()
{
	Headmaster *headmaster = StaffList::getHeadmaster();
	if (headmaster)
	{
		headmaster->startClasses();
	}
}

void School::requestRingBell()
{
	Headmaster *headmaster = StaffList::getHeadmaster();
	if (headmaster)
	{
		headmaster->ringTheBell(&(this->_bellEvent));
	}
}

void School::recruitProfessor(Professor *professor)
{
	StaffList::getInstance()->add(professor);
	this->_bellEvent.attach(professor);
}

void School::recruitStudent(Student *student)
{
	StudentList::getInstance()->add(student);
	this->_bellEvent.attach(student);
	student->joinCourse();
}

Course *School::getCourse(std::string p_name)
{
	for (int i = 0; i < CourseList::getInstance()->getList().size(); i++)
	{
		if (CourseList::getInstance()->getList()[i]->getName() == p_name)
		{
			return CourseList::getInstance()->getList()[i];
		}
	}
	return nullptr;
}

std::vector<Student *> School::getStudents()
{
	return StudentList::getInstance()->getList();
}

std::vector<Professor *> School::getProfessors()
{
	return StaffList::getProfessors();
}

Headmaster School::getHeadmaster()
{
	Headmaster *headmaster = StaffList::getHeadmaster();
	if (headmaster)
		return *headmaster;
	throw "No headmaster found";
}

Secretary School::getSecretary()
{
	Secretary *secretary = StaffList::getSecretary();
	if (secretary)
		return *secretary;
	throw "No secretary found";
}

void School::graduationCeremony()
{

	std::cout << "<< =================== >>" << std::endl;
	std::cout << "<< Graduation Ceremony >>" << std::endl;
	std::cout << "<< =================== >>" << std::endl;

	std::map<Student *, Course *> test = StudentList::getGraduatedStudents();
	for (std::map<Student *, Course *>::iterator it = test.begin(); it != test.end(); it++)
	{
		try
		{
			Headmaster headmaster = getHeadmaster();
			headmaster.notify(it->first, CourseFinished);
		}
		catch (std::string e)
		{
			std::cerr << e << std::endl;
		}
	}
}
