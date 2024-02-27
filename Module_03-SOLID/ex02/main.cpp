#include <iostream>
#include "rectangle.hpp"
#include "triangle.hpp"
#include "circle.hpp"

void printArea(Shape *shape)
{
	std::cout << "Area: " << shape->area() << std::endl;
}

void printPerimeter(Shape *shape)
{
	std::cout << "Perimeter: " << shape->perimeter() << std::endl;
}

int main()
{
	Rectangle rectangle(5.0, 4.0);
	Triangle triangle(5.0, 4.0);
	Circle circle(5.0);

	printArea(&rectangle);
	printPerimeter(&rectangle);

	printArea(&triangle);
	printPerimeter(&triangle);

	printArea(&circle);
	printPerimeter(&circle);

	return 0;
}