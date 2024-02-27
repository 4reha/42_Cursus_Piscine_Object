#pragma once
#include "shape.hpp"

class Rectangle : public Shape
{
public:
	Rectangle(double width, double height) : width_(width), height_(height) {}

	double area() const
	{
		return width_ * height_;
	}

	double perimeter() const
	{
		return 2 * (width_ + height_);
	}

private:
	double width_;
	double height_;
};
