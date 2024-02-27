#pragma once
#include <iostream>
#include "HeaderLogger.hpp"

class ConstantHeaderLogger : public HeaderLogger
{
	std::string header;

public:
	ConstantHeaderLogger(ILogger &logger, const std::string &header) : HeaderLogger(logger), header(header) {}
	std::string getHeader()
	{
		return header;
	}
};