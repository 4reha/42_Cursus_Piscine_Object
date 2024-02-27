#pragma once
#include <iostream>
#include <fstream>
#include "IWritableStream.hpp"

class FileStream : public IWritableStream
{
private:
	std::ofstream file;

public:
	FileStream(const std::string &filename) : file(filename.c_str()) {}

	void write(const std::string &message)
	{
		if (file.is_open())
			file << message << std::endl;
	}
};