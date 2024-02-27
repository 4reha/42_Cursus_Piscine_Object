#pragma once

#include <vector>
#include <string>
#include "Person.hpp"
#include "Course.hpp"
#include "Staff.hpp"


class School
{
private:
	BellEvent _bellEvent;

public : 
	School();
	~School();

	void runDayRoutine();
	void launchClasses();
	void requestRingBell();
	void recruitProfessor(Professor *professor);
	void recruitStudent(Student *student);
	Course *getCourse(std::string p_name);
	std::vector<Student *> getStudents();
	std::vector<Professor *> getProfessors();
	Headmaster getHeadmaster();
	Secretary getSecretary();
	void graduationCeremony();
};