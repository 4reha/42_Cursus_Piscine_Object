#pragma once
#include <iostream>
#include <fstream>
#include "ILogger.hpp"
#include "IWritableStream.hpp"

class FileLogger : public ILogger
{
private:
	IWritableStream &stream;

public:
	FileLogger(IWritableStream &stream) : stream(stream) {}

	void write(const std::string &message)
	{
		stream.write(message);
	}
};