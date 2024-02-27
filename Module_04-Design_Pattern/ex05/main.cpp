#include "School.hpp"

int main()
{
	School school = School();

	school.recruitProfessor(new Professor("Snape"));
	school.recruitProfessor(new Professor("McGonagall"));

	school.recruitStudent(new Student("Harry"));
	school.recruitStudent(new Student("Hermione"));
	school.recruitStudent(new Student("Ron"));

	school.runDayRoutine();
	
	school.graduationCeremony();

	return 0;
}
