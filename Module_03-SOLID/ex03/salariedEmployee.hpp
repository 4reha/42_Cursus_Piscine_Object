#pragma once

#include <iostream>
#include "employee.hpp"

class SalariedEmployee
{
public:
	class ContractEmployee : public Employee
	{
	private:
		int hourlyValue;
		int _unworkedHours;

	public:
		ContractEmployee(int hourlyValue) : hourlyValue(hourlyValue), _unworkedHours(0) {}

		int executeWorkday()
		{
			return (7 - _unworkedHours) > 0 ? (7 - _unworkedHours) : 0;
		}

		int getHourlyValue() const
		{
			return hourlyValue;
		}

		void vacation(double hours)
		{
			_unworkedHours += hours;
		};

		void sickness(double hours)
		{
			_unworkedHours += hours;
		};

		void anyReason(double hours)
		{
			_unworkedHours += hours;
		};
	};

	class Apprentice : public Employee
	{
	private:
		int hourlyValue;
		int schoolHours;

	public:
		Apprentice(int hourlyValue, int schoolHours) : hourlyValue(hourlyValue), schoolHours(schoolHours) {}

		int executeWorkday()
		{
			return 7 - schoolHours;
		}

		int getHourlyValue() const
		{
			return hourlyValue / 2;
		}
	};
};