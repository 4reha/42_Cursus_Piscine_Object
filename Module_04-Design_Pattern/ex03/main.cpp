#include "Course.hpp"
#include "Event.hpp"
#include "Form.hpp"
#include "Person.hpp"
#include "Room.hpp"
#include "Staff.hpp"

int main()
{

	Staff *Dumbledore = StaffList::getInstance()->add(new Headmaster("Dumbledore"));
	Staff *Hagrid = StaffList::getInstance()->add(new Secretary("Hagrid"));
	Staff *McGonagall = StaffList::getInstance()->add(new Professor("McGonagall"));
	Staff *Snape = StaffList::getInstance()->add(new Professor("Snape"));

	Student *Harry = StudentList::getInstance()->add(new Student("Harry"));
	Student *Ron = StudentList::getInstance()->add(new Student("Ron"));
	Student *Hermione = StudentList::getInstance()->add(new Student("Hermione"));

	StaffList::getHeadmaster()->startClasses();
	Harry->joinCourse();

	for (int i = 0; i < 5; i++)
	{
		StaffList::getHeadmaster()->startClasses();
	}

	return 0;
}
