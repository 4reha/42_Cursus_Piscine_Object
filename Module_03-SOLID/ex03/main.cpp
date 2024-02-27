#include "employeeManagement.hpp"
#include "hourlyEmployee.hpp"
#include "salariedEmployee.hpp"
int main()
{
	EmployeeManager manager;

	HourlyEmployee::TempWorker tempWorker(10);
	SalariedEmployee::ContractEmployee contractEmployee(15);
	SalariedEmployee::Apprentice apprentice(12, 2);

	manager.addEmployee(&tempWorker);
	manager.addEmployee(&contractEmployee);
	manager.addEmployee(&apprentice);

	contractEmployee.vacation(2);
	contractEmployee.sickness(1);
	manager.executeWorkday();
	manager.calculatePayroll();

	return 0;
}