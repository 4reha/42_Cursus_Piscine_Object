#pragma once
#include <iostream>
#include "Tool.hpp"

class Hammer : public Tool
{
public:
	void use()
	{
		++numberOfUses;
		std::cout << "Using hammer. Number of uses: " << numberOfUses << std::endl;
	}
};
