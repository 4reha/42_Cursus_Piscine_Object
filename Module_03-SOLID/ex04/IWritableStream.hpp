#pragma once
#include <iostream>

class IWritableStream
{
public:
	virtual void write(const std::string &message) = 0;
};