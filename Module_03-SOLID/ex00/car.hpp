#pragma once
#include <iostream>
#include "engine.hpp"
#include "transmission.hpp"
#include "wheel.hpp"
#include "brake.hpp"

class Car
{
private:
	Engine engine;
	Transmission transmission;
	Wheel wheel;
	Brake brake;

public:
	void start() { engine.start(); }
	void stop()
	{
		engine.stop();
		brake.apply_force_on_brakes(100);
	}
	void accelerate(int speed) { engine.accelerate(speed); };
	void shift_gears_up() { transmission.shift_gears_up(); }
	void shift_gears_down() { transmission.shift_gears_down(); }
	void reverse() { transmission.reverse(); }
	void turn_wheel(int angle) { wheel.turn_wheel(angle); }
	void straighten_wheels() { wheel.straighten_wheels(); }
	void apply_force_on_brakes(int force) { brake.apply_force_on_brakes(force); }
	void apply_emergency_brakes() { brake.apply_emergency_brakes(); }
};