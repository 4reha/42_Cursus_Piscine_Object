#pragma once
#include <iostream>

class Transmission
{
public:
	void shift_gears_up() { std::cout << "Gear shifted up" << std::endl; }
	void shift_gears_down() { std::cout << "Gear shifted down" << std::endl; }
	void reverse() { std::cout << "Gear shifted to reverse" << std::endl; }
};