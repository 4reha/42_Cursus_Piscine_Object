#pragma once
#include <vector>
#include <iostream>
#include "Vector2.hpp"

class Graph
{
private:
	Vector2 size;
	std::vector<Vector2> points;
	std::vector<std::pair<Vector2, Vector2> > lines;

	bool isPointInGraph(const Vector2 &point) const;
	bool arePointsOnSameLine(const Vector2 &p1, const Vector2 &p2, const Vector2 &p3) const;
	bool isRegisteredPoint(const Vector2 &point) const;
	Vector2 stringToPoint(std::string pointString) const;
	std::vector<Vector2> parsePoints(std::string line);

	class InvalidPointException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class OutOfGraphException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

public:
	Graph();
	Graph(Vector2 size);
	Graph(std::string filename);
	~Graph();

	void addPoint(const Vector2 &point);
	void addLine(const Vector2 &point1, const Vector2 &point2);

	void display() const;
	void exportPNG(std::string filename) const;
};
