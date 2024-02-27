#pragma once
#include <iostream>

class Tool
{
public:
	int numberOfUses;

	Tool() : numberOfUses(0) {}
	virtual void use() = 0;
};