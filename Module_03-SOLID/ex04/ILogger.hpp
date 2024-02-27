#pragma once
#include <iostream>

class ILogger
{
public:
	virtual ~ILogger() {}
	virtual void write(const std::string &message) = 0;
};