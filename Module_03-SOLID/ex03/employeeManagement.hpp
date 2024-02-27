#pragma once
#include <vector>
#include "employee.hpp"

class EmployeeManager
{
private:
	std::vector<Employee *> employees;

public:
	void addEmployee(Employee *employee)
	{
		if (std::find(employees.begin(), employees.end(), employee) == employees.end())
			employees.push_back(employee);
	}
	void removeEmployee(Employee *employee)
	{
		employees.erase(std::find(employees.begin(), employees.end(), employee));
	}
	void executeWorkday()
	{
		for (std::vector<Employee *>::iterator it = employees.begin(); it != employees.end(); ++it)
		{
			(*it)->executeWorkday();
		}
	}
	void calculatePayroll()
	{
		for (std::vector<Employee *>::iterator it = employees.begin(); it != employees.end(); ++it)
		{
			std::cout << (*it)->executeWorkday() * (*it)->getHourlyValue() * 30 << std::endl;
		}
	}
};
