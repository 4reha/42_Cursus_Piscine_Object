#include "car.hpp"

int main()
{
	Car car;
	car.start();
	car.accelerate(50);
	car.shift_gears_up();
	car.turn_wheel(45);
	car.straighten_wheels();
	car.apply_force_on_brakes(50);
	car.apply_emergency_brakes();
	car.stop();
	return 0;
}