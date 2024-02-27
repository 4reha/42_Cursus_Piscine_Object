#pragma once
#include <vector>
#include <iostream>

class Vector2
{
private:
	float x, y;

public:
	Vector2(float x = 0, float y = 0);
	~Vector2();

	float getX() const;
	float getY() const;

	bool operator==(const Vector2 &other) const;
};