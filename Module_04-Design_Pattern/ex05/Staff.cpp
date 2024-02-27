#include "Staff.hpp"
#include "Form.hpp"
#include "Room.hpp"
#include "Course.hpp"

Staff::Staff(std::string p_name) : Person(p_name){};

void Staff::sign(Form *p_form)
{
	p_form->sign();
}

//

Headmaster::Headmaster(std::string p_name) : Staff(p_name){};

void Headmaster::receiveForm(Form *p_form)
{
	_formToValidate.push_back(p_form);
}

void Headmaster::validateForm(Form *p_form)
{
	p_form->execute();
}

void Headmaster::notify(Person *sender, FormType event)
{
	switch (event)
	{
	case CourseFinished:
		this->handleCourseFinishedForm(dynamic_cast<Student *>(sender));
		break;
	case NeedMoreClassRoom:
		this->handleNeedMoreClassRoomForm(dynamic_cast<Professor *>(sender));
		break;
	case NeedCourseCreation:
		this->handleNeedCourseCreationForm(dynamic_cast<Professor *>(sender));
		break;
	case SubscriptionToCourse:
		this->handleSubscriptionToCourseForm(dynamic_cast<Student *>(sender));
		break;
	}
}

void Headmaster::ringTheBell(BellEvent *p_bellEvent)
{
	p_bellEvent->bell();
}

void Headmaster::handleCourseFinishedForm(Student *p_student)
{
	if (p_student)
	{
		std::cout << "Headmaster received a CourseFinishedForm from " << p_student->getName() << std::endl;
		Secretary *secretary = StaffList::getSecretary();
		if (secretary)
		{
			Form *form = secretary->createForm(CourseFinished);
			this->receiveForm(form);
			form->fill(p_student);
			this->sign(form);
			this->validateForm(form);
		}
	}
}

void Headmaster::handleNeedMoreClassRoomForm(Professor *p_professor)
{
	if (p_professor)
	{
		std::cout << "Headmaster received a NeedMoreClassRoomForm from " << p_professor->getName() << std::endl;
		Secretary *secretary = StaffList::getSecretary();
		if (secretary)
		{
			Form *form = secretary->createForm(NeedMoreClassRoom);
			this->receiveForm(form);
			form->fill(p_professor);
			this->sign(form);
			this->validateForm(form);
		}
	}
}

void Headmaster::handleNeedCourseCreationForm(Professor *p_professor)
{
	if (p_professor)
	{
		std::cout << "Headmaster received a NeedCourseCreationForm from " << p_professor->getName() << std::endl;
		Secretary *secretary = StaffList::getSecretary();
		if (secretary)
		{
			Form *form = secretary->createForm(NeedCourseCreation);
			this->receiveForm(form);
			form->fill(p_professor);
			this->sign(form);
			this->validateForm(form);
		}
	}
}

void Headmaster::handleSubscriptionToCourseForm(Student *p_student)
{
	if (p_student)
	{
		std::cout << "Headmaster received a SubscriptionToCourseForm from " << p_student->getName() << std::endl;
		Secretary *secretary = StaffList::getSecretary();
		if (secretary)
		{
			Form *form = secretary->createForm(SubscriptionToCourse);
			this->receiveForm(form);
			form->fill(p_student);
			this->sign(form);
			this->validateForm(form);
		}
	}
}

void Headmaster::startClasses()
{
	for (int i = 0; i < StaffList::getInstance()->getList().size(); i++)
	{
		Professor *prof = dynamic_cast<Professor *>(StaffList::getInstance()->getList()[i]);
		if (prof)
		{
			prof->doClass();
		}
	}
}

//

Secretary::Secretary(std::string p_name) : Staff(p_name){};

Form *Secretary::createForm(FormType p_formType)
{
	switch (p_formType)
	{
	case CourseFinished:
		return new CourseFinishedForm();
	case NeedMoreClassRoom:
		return new NeedMoreClassRoomForm();
	case NeedCourseCreation:
		return new NeedCourseCreationForm();
	case SubscriptionToCourse:
		return new SubscriptionToCourseForm();
	default:
		return nullptr;
	}
}

//

Professor::Professor(std::string p_name) : Staff(p_name){};

void Professor::assignCourse(Course *p_course)
{
	_currentCourse = p_course;
}

void Professor::doClass()
{
	Headmaster *headmaster = StaffList::getHeadmaster();
	if (!_currentCourse)
	{
		if (headmaster)
			headmaster->notify(this, NeedCourseCreation);
	}
	if (!this->_currentRoom)
	{
		if (!RoomList::getFreeClassroom())
		{
			if (headmaster)
				headmaster->notify(this, NeedMoreClassRoom);
		}
		this->_currentRoom = RoomList::getFreeClassroom();
	}
	if (this->_currentRoom)
	{
		Classroom *classroom = dynamic_cast<Classroom *>(this->_currentRoom);
		classroom->enter(this);
		classroom->assignCourse(_currentCourse);
		for (int i = 0; i < _currentCourse->getStudents().size(); i++)
		{
			_currentCourse->getStudents()[i]->attendClass(classroom);
		}
	}
}

//

Headmaster *StaffList::getHeadmaster()
{
	const std::vector<Staff *> staffList = getInstance()->getList();
	for (int i = 0; i < staffList.size(); i++)
	{
		Headmaster *headmaster = dynamic_cast<Headmaster *>(staffList[i]);
		if (headmaster)
			return headmaster;
	}
	std::cout << "no headmaster has found" << std::endl;
	return nullptr;
}

Secretary *StaffList::getSecretary()
{
	const std::vector<Staff *> staffList = getInstance()->getList();
	for (int i = 0; i < staffList.size(); i++)
	{
		Secretary *secretary = dynamic_cast<Secretary *>(staffList[i]);
		if (secretary)
			return secretary;
	}
	std::cout << "no secretary has found" << std::endl;
	return nullptr;
}

std::vector<Professor *> StaffList::getProfessors()
{
	std::vector<Professor *> professors;
	const std::vector<Staff *> staffList = getInstance()->getList();
	for (int i = 0; i < staffList.size(); i++)
	{
		Professor *professor = dynamic_cast<Professor *>(staffList[i]);
		if (professor)
			professors.push_back(professor);
	}
	return professors;
}