#pragma once

#include <iostream>
#include "employee.hpp"

class HourlyEmployee
{
public:
	class TempWorker : public Employee
	{
	private:
		int hourlyValue;
		int registeredHours;

	public:
		TempWorker(int hourlyValue) : hourlyValue(hourlyValue) {}

		int executeWorkday() 
		{
			work();
			return 7;
		}

		void work()
		{
			registeredHours += 7;
		}

		void work(int hours)
		{
			registeredHours += hours;
		}

		int getHourlyValue() const 
		{
			return hourlyValue;
		}
	};
};