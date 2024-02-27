#pragma once
#include <iostream>
#include "ILogger.hpp"

class OstreamLogger : public ILogger
{
	std::ostream &out;

public:
	OstreamLogger(std::ostream &out) : out(out) {}
	void write(const std::string &message)
	{
		out << message << std::endl;
	}
};