#include "Form.hpp"
#include "Room.hpp"
#include "Course.hpp"
#include "Person.hpp"
#include "Staff.hpp"
#include <iostream>

Form::Form(FormType p_formType) : _formType(p_formType){};

// CourseFinishedForm

CourseFinishedForm::CourseFinishedForm() : Form(CourseFinished){};

void CourseFinishedForm::fill(Person *p_demandant)
{
	this->_isFilled = true;
	this->_demandant = p_demandant;
	std::cout << "CourseFinishedForm has been filled" << std::endl;
}

void CourseFinishedForm::sign()
{
	if (!this->_isFilled)
	{
		std::cout << "CourseFinishedForm has not been filled" << std::endl;
		return;
	}
	this->_isSigned = true;
	std::cout << "CourseFinishedForm has been signed" << std::endl;
}

void CourseFinishedForm::execute()
{
	if (!this->_isSigned)
	{
		std::cout << "CourseFinishedForm has not been signed" << std::endl;
		return;
	}

	Student *student = dynamic_cast<Student *>(this->_demandant);
	if (student)
	{
		student->graduate(student->getFinishedCourse());
		this->_isExecuted = true;
		std::cout << "CourseFinishedForm has executed" << std::endl;
	}
}

// NeedMoreClassRoomForm

NeedMoreClassRoomForm::NeedMoreClassRoomForm() : Form(NeedMoreClassRoom){};

void NeedMoreClassRoomForm::fill(Person *p_demandant)
{
	this->_isFilled = true;
	this->_demandant = p_demandant;
	std::cout << "NeedMoreClassRoomForm has been filled" << std::endl;
}

void NeedMoreClassRoomForm::sign()
{
	if (!this->_isFilled)
	{
		std::cout << "NeedMoreClassRoomForm has not been filled" << std::endl;
		return;
	}
	this->_isSigned = true;
	std::cout << "NeedMoreClassRoomForm has been signed" << std::endl;
}

void NeedMoreClassRoomForm::execute()
{
	if (!this->_isSigned)
	{
		std::cout << "NeedMoreClassRoomForm has not been signed" << std::endl;
		return;
	}

	RoomList::getInstance()->add(new Classroom());

	this->_isExecuted = true;
	std::cout << "NeedMoreClassRoomForm has executed" << std::endl;
}

// NeedCourseCreationForm

NeedCourseCreationForm::NeedCourseCreationForm() : Form(NeedCourseCreation){};

void NeedCourseCreationForm::fill(Person *p_demandant)
{
	this->_isFilled = true;
	this->_demandant = p_demandant;
	std::cout << "NeedCourseCreationForm has been filled" << std::endl;
}

void NeedCourseCreationForm::sign()
{
	if (!this->_isFilled)
	{
		std::cout << "NeedCourseCreationForm has not been filled" << std::endl;
		return;
	}
	this->_isSigned = true;
	std::cout << "NeedCourseCreationForm has been signed" << std::endl;
}

void NeedCourseCreationForm::execute()
{
	if (!this->_isSigned)
	{
		std::cout << "NeedCourseCreationForm has not been signed" << std::endl;
		return;
	}
	Course *course = CourseList::getUnassignedCourse();
	if (!course)
	{
		const int size = CourseList::getInstance()->getList().size();
		course = CourseList::getInstance()->add(new Course("Course_" + std::to_string(size)));
	}
	Professor *prof = dynamic_cast<Professor *>(this->_demandant);
	if (prof)
	{
		course->assign(prof);
		prof->assignCourse(course);
	}

	this->_isExecuted = true;
	std::cout << "NeedCourseCreationForm has executed" << std::endl;
}

// SubscriptionToCourseForm

SubscriptionToCourseForm::SubscriptionToCourseForm() : Form(SubscriptionToCourse){};

void SubscriptionToCourseForm::fill(Person *p_demandant)
{
	this->_isFilled = true;
	this->_demandant = p_demandant;
	std::cout << "SubscriptionToCourseForm has been filled" << std::endl;
}

void SubscriptionToCourseForm::sign()
{
	if (!this->_isFilled)
	{
		std::cout << "SubscriptionToCourseForm has not been filled" << std::endl;
		return;
	}
	this->_isSigned = true;
	std::cout << "SubscriptionToCourseForm has been signed" << std::endl;
}

void SubscriptionToCourseForm::execute()
{
	if (!this->_isSigned)
	{
		std::cout << "SubscriptionToCourseForm has not been signed" << std::endl;
		return;
	}
	Student *student = dynamic_cast<Student *>(this->_demandant);
	if (student)
	{
		Course *course = CourseList::getFreeCourse();
		if (course)
		{
			student->subscribeCourse(course);
			course->subscribe(student);
		}
	}
	this->_isExecuted = true;
	std::cout << "SubscriptionToCourseForm has executed" << std::endl;
}
