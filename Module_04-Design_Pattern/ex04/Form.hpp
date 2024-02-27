#pragma once


class Person;

enum FormType
{
	CourseFinished,
	NeedMoreClassRoom,
	NeedCourseCreation,
	SubscriptionToCourse,
};

class Form
{
private:
	FormType _formType;
protected:
	bool _isFilled;
	Person *_demandant;
	bool _isSigned;
	bool _isExecuted;

public:
	Form(FormType p_formType);

	virtual void fill(Person *p_demandant) = 0;
	virtual void sign() = 0;
	virtual void execute() = 0;
};

class CourseFinishedForm : public Form
{
private:
public:
	CourseFinishedForm();
	void fill(Person *p_demandant);
	void sign();
	void execute();
};

class NeedMoreClassRoomForm : public Form
{
private:
public:
	NeedMoreClassRoomForm();
	void fill(Person *p_demandant);
	void sign();
	void execute();
};

class NeedCourseCreationForm : public Form
{
private:
public:
	NeedCourseCreationForm();
	void fill(Person *p_demandant);
	void sign();
	void execute();
};

class SubscriptionToCourseForm : public Form
{
private:
public:
	SubscriptionToCourseForm();
	void fill(Person *p_demandant);
	void sign();
	void execute();
};
