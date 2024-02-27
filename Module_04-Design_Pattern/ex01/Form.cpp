#include "Form.hpp"
#include <iostream>

Form::Form(FormType p_formType) : _formType(p_formType){};

void CourseFinishedForm::execute()
{
	std::cout << "CourseFinishedForm has executed" << std::endl;
}

void NeedMoreClassRoomForm::execute()
{
	std::cout << "NeedMoreClassRoomForm has executed" << std::endl;
}

void NeedCourseCreationForm::execute()
{
	std::cout << "NeedCourseCreationForm has executed" << std::endl;
}

void SubscriptionToCourseForm::execute()
{
	std::cout << "SubscriptionToCourseForm has executed" << std::endl;
}
