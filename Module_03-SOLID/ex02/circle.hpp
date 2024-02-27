#pragma once
#include <cmath>
#include "shape.hpp"

class Circle : public Shape
{
public:
	Circle(double radius) : radius_(radius) {}

	double area() const
	{
		return 3.14159265358979323846 * pow(radius_, 2);
	}

	double perimeter() const
	{
		return 2 * 3.14159265358979323846 * radius_;
	}

private:
	double radius_;
};
