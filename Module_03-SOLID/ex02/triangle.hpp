#pragma once
#include <cmath>
#include "shape.hpp"

class Triangle : public Shape
{
public:
	Triangle(double base, double height) : base_(base), height_(height) {}

	double area() const
	{
		return 0.5 * base_ * height_;
	}

	double perimeter() const
	{
		return base_ + 2 * sqrt(pow(height_, 2) + pow(base_ / 2, 2));
	}

private:
	double base_;
	double height_;
};
