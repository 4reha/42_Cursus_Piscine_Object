#pragma once
#include <iostream>
#include "Tool.hpp"

class Shovel : public Tool
{
public:
	void use()
	{
		++numberOfUses;
		std::cout << "Using shovel. Number of uses: " << numberOfUses << std::endl;
	}
};
