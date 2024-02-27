#pragma once

#include <iostream>

class Employee
{
public:
	virtual int executeWorkday() = 0;
	virtual int getHourlyValue() const = 0;
};
 