#include "Course.hpp"
#include "Event.hpp"
#include "Form.hpp"
#include "Person.hpp"
#include "Room.hpp"
#include "Staff.hpp"

int main()
{
	StudentList::getInstance()->add(new Student("John"));
	StudentList::getInstance()->add(new Student("Jane"));
	StudentList::getInstance()->add(new Student("Jack"));
	StudentList::getInstance()->add(new Student("Jill"));

	StaffList::getInstance()->add(new Headmaster("Mr. Smith"));
	StaffList::getInstance()->add(new Secretary("Mrs. Smith"));
	StaffList::getInstance()->add(new Professor("Mr. Doe"));
	StaffList::getInstance()->add(new Staff("Mrs. Doe"));

	CourseList::getInstance()->add(new Course("Math"));
	CourseList::getInstance()->add(new Course("Physics"));
	CourseList::getInstance()->add(new Course("Chemistry"));
	CourseList::getInstance()->add(new Course("Biology"));

	RoomList::getInstance()->add(new Classroom());
	RoomList::getInstance()->add(new Classroom());
	RoomList::getInstance()->add(new Classroom());
	RoomList::getInstance()->add(new Classroom());

	for (int i = 3; i >= 0; i--)
	{
		Student *student = StudentList::getInstance()->operator[](i);
		Staff *staff = StaffList::getInstance()->operator[](i);
		Course *course = CourseList::getInstance()->operator[](i);
		Room *room = RoomList::getInstance()->operator[](i);

		std::cout << student->getName() << std::endl;
		std::cout << staff->getName() << std::endl;
		std::cout << course->getName() << std::endl;
		std::cout << room->getID() << std::endl;

		StudentList::getInstance()->remove(student);
		StaffList::getInstance()->remove(staff);
		CourseList::getInstance()->remove(course);
		RoomList::getInstance()->remove(room);

		delete student;
		delete staff;
		delete course;
		delete room;
	}

	return 0;
}
