#pragma once
#include <iostream>

class Wheel
{
public:
	void turn_wheel(int angle) { std::cout << "Wheel turned " << angle << " degrees" << std::endl; }
	void straighten_wheels() { std::cout << "Wheels straightened" << std::endl; }
};