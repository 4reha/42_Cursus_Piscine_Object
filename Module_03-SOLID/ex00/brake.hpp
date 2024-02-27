#pragma once
#include <iostream>

class Brake
{
public:
	void apply_force_on_brakes(int force) { std::cout << "Brakes applied with force " << force << std::endl; }
	void apply_emergency_brakes() { std::cout << "Emergency brakes applied" << std::endl; }
};