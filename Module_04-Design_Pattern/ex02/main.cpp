#include "Course.hpp"
#include "Event.hpp"
#include "Form.hpp"
#include "Person.hpp"
#include "Room.hpp"
#include "Staff.hpp"

int main()
{
	Headmaster *headmaster = new Headmaster("Mr. Headmaster");
	Secretary *secretary = new Secretary("Mrs. Secretary");
	Professor *professor = new Professor("Mr. Professor");
	Student *student = new Student("Student");

	Form *needMoreClassRoomForm = secretary->createForm(NeedMoreClassRoom);
	Form *needCourseCreationForm = secretary->createForm(NeedCourseCreation);
	Form *courseFinishedForm = secretary->createForm(CourseFinished);

	headmaster->receiveForm(needMoreClassRoomForm);
	headmaster->receiveForm(needCourseCreationForm);
	headmaster->receiveForm(courseFinishedForm);

	headmaster->sign(needMoreClassRoomForm);
	needMoreClassRoomForm->fill(professor);
	needCourseCreationForm->fill(professor);
	courseFinishedForm->fill(student);

	headmaster->sign(needMoreClassRoomForm);
	headmaster->sign(needCourseCreationForm);
	
	headmaster->validateForm();


	return 0;
}
