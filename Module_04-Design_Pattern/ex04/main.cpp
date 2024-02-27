#include <ctime>
#include "Course.hpp"
#include "Event.hpp"
#include "Form.hpp"
#include "Person.hpp"
#include "Room.hpp"
#include "Staff.hpp"

void pause(int dur)
{
	int temp = time(NULL) + dur;
	while (temp > time(NULL))
		;
}

int main()
{
	BellEvent bellEvent = BellEvent();

	Staff *Dumbledore = StaffList::getInstance()->add(new Headmaster("Dumbledore"));
	Staff *Hagrid = StaffList::getInstance()->add(new Secretary("Hagrid"));
	Staff *McGonagall = StaffList::getInstance()->add(new Professor("McGonagall"));
	// Staff *Snape = StaffList::getInstance()->add(new Professor("Snape"));

	Student *Harry = StudentList::getInstance()->add(new Student("Harry"));

	StaffList::getHeadmaster()->notify(McGonagall, NeedMoreClassRoom);
	StaffList::getHeadmaster()->notify(McGonagall, NeedCourseCreation);
	Harry->joinCourse();


	bellEvent.attach(McGonagall);
	// // bellEvent.attach(Snape);
	bellEvent.attach(Harry);

	StaffList::getHeadmaster()->startClasses();

	for (int i = 0; i < 5; i++)
	{
		std::cout << "====" << std::endl;
		pause(10);
		StaffList::getHeadmaster()->ringTheBell(&bellEvent);
	}

	return 0;
}
