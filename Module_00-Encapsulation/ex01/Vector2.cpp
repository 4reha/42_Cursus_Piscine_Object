#include "Vector2.hpp"

Vector2::Vector2(float x, float y) : x(x), y(y) {}

bool Vector2::operator==(const Vector2 &other) const
{
	return x == other.x && y == other.y;
}

Vector2::~Vector2() {}

float Vector2::getX() const { return x; }

float Vector2::getY() const { return y; }
