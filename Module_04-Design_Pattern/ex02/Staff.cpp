#include "Staff.hpp"
#include "Form.hpp"

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

void Headmaster::validateForm()
{
	for (int i = 0; i < _formToValidate.size(); i++)
	{
		_formToValidate[i]->execute();
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