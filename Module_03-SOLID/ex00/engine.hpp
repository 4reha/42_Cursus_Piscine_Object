#pragma once
#include <iostream>

class Engine
{
	int speed;

public:
	void start() { std::cout << "Engine started" << std::endl; }
	void stop() { std::cout << "Engine stopped" << std::endl; }
	void accelerate(int speed)
	{
		this->speed += speed;
		std::cout << "Engine accelerated: " << this->speed << std::endl;
	}
};