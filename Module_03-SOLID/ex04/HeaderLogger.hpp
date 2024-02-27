#pragma once
#include <iostream>
#include "ILogger.hpp"

class HeaderLogger : public ILogger
{
	ILogger &logger;

public:
	HeaderLogger(ILogger &logger) : logger(logger) {}
	void write(const std::string &message)
	{
		logger.write(getHeader() + message);
	}
	virtual std::string getHeader() = 0;
};