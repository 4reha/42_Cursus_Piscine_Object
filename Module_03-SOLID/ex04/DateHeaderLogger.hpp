#pragma once
#include <iostream>
#include <ctime>
#include "HeaderLogger.hpp"

class DateHeaderLogger : public HeaderLogger
{
public:
	DateHeaderLogger(ILogger &logger) : HeaderLogger(logger) {}
	std::string getHeader()
	{
		std::time_t t = std::time(0);
		char mbstr[100];
		std::strftime(mbstr, sizeof(mbstr), "%A %c ", std::localtime(&t));
		return mbstr;
	}
};