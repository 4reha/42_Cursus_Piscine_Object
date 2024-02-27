#pragma once
#include <iostream>
#include "Person.hpp"
#include "Form.hpp"
#include "Singleton.hpp"

class Course;
class Professor;
enum FormType;

class Staff : public Person
{
private:
public:
	Staff(std::string p_name);
	void sign(Form *p_form);
};

class Headmaster : public Staff
{
private:
	std::vector<Form *> _formToValidate;

	void handleCourseFinishedForm(Student *p_student);
	void handleNeedMoreClassRoomForm(Professor *p_professor);
	void handleNeedCourseCreationForm(Professor *p_professor);
	void handleSubscriptionToCourseForm(Student *p_student);
public:
	Headmaster(std::string p_name);
	void receiveForm(Form *p_form);
	void validateForm(Form *p_form);
	void notify(Person *sender, FormType event);
	void startClasses();

	void ringTheBell(BellEvent *p_bellEvent);
};

class Secretary : public Staff
{
private:
public:
	Secretary(std::string p_name);
	Form *createForm(FormType p_formType);
	void archiveForm();
};

class Professor : public Staff
{
private:
	Course *_currentCourse;

public:
	Professor(std::string p_name);
	// void update(Event _event);
	void assignCourse(Course *p_course);
	void doClass();
	void closeCourse();
};

class StaffList : public Singleton<Staff *>
{
public:
	static Headmaster *getHeadmaster();
	static Secretary *getSecretary();
	static std::vector<Professor *> getProfessors();

};