#include "Graph.hpp"
#include <fstream>
#include <sstream>

Graph::Graph() : size(Vector2(5, 5)) {}

Graph::Graph(Vector2 size) : size(size) {}

Graph::Graph(std::string filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		throw std::exception();
	std::string line;
	char lineCount = 0;
	while (std::getline(file, line, '\n'))
	{
		if (line.empty())
			continue;
		std::vector<Vector2> points = parsePoints(line);
		if (lineCount == 0)
		{
			size = points[0];
			++lineCount;
		}
		else
		{
			if (points.size() == 1)
				addPoint(points[0]);
			else if (points.size() == 2)
				addLine(points[0], points[1]);
			else
				throw InvalidPointException();
		}
	}
	file.close();
}

Graph::~Graph() {}

std::vector<Vector2> Graph::parsePoints(std::string line)
{
	std::stringstream ss(line);
	std::vector<Vector2> points;
	std::string point;
	while (std::getline(ss, point, ' '))
	{
		points.push_back(stringToPoint(point));
	}
	return points;
}

void Graph::addPoint(const Vector2 &point)
{
	if (!isPointInGraph(point))
		throw OutOfGraphException();
	points.push_back(point);
}

void Graph::addLine(const Vector2 &point1, const Vector2 &point2)
{
	if (!isPointInGraph(point1) || !isPointInGraph(point2))
		throw OutOfGraphException();
	lines.push_back(std::pair<Vector2, Vector2>(point1, point2));
}

void Graph::display() const
{
	for (int y = size.getY(); y >= 0; --y)
	{
		std::cout << y << ' ';
		for (int x = 0; x <= size.getX(); ++x)
		{
			if (isRegisteredPoint(Vector2(x, y)))
				std::cout << "X ";
			else
				std::cout << ". ";
		}
		std::cout << '\n';
	}
	std::cout << "  ";
	for (int i = 0; i <= size.getX(); ++i)
	{
		std::cout << i << ' ';
	}
}

void Graph::exportPNG(std::string filename) const
{
	filename += ".png";
	std::ofstream file(filename.c_str());
	if (!file.is_open())
		throw std::exception();
	file << "P3 ";
	file << this->size.getX()+1 << " " << this->size.getY()+1 << " 255" << std::endl;
	for (int i = size.getY(); i >= 0; i--)
	{
		for (int j = 0; j < this->size.getX()+1; j++)
		{
			if (this->isRegisteredPoint(Vector2(j, i)))
			{
				file << "0 0 0";
			}
			else
			{
				file << "255 255 255";
			}
			if (j != this->size.getX())
				file << " ";
		}
		file << std::endl;
	}

	file.close();
}

// private methods

bool Graph::isPointInGraph(const Vector2 &point) const
{
	return point.getX() >= 0 && point.getX() <= size.getX() && point.getY() >= 0 && point.getY() <= size.getY();
}

bool Graph::arePointsOnSameLine(const Vector2 &p1, const Vector2 &p2, const Vector2 &p3) const
{
	return ((int)p2.getY() - (int)p1.getY()) * ((int)p3.getX() - (int)p2.getX()) == ((int)p3.getY() - (int)p2.getY()) * ((int)p2.getX() - (int)p1.getX());
}

bool Graph::isRegisteredPoint(const Vector2 &point) const
{
	for (std::vector<Vector2>::const_iterator it = points.begin(); it != points.end(); ++it)
	{
		if ((int)it->getX() == point.getX() && (int)it->getY() == point.getY())
			return true;
	}
	for (std::vector<std::pair<Vector2, Vector2> >::const_iterator it = lines.begin(); it != lines.end(); ++it)
	{
		if (arePointsOnSameLine(it->first, it->second, point))
			return true;
	}

	return false;
}

Vector2 Graph::stringToPoint(std::string pointString) const
{
	std::stringstream ss(pointString);
	std::string x, y;
	std::getline(ss, x, ',');
	std::getline(ss, y);
	int i = -1;
	while (x[++i] != '\0')
		if (!std::isdigit(x[i]) && x[i] != '.')
			throw InvalidPointException();

	i = -1;
	while (y[++i] != '\0')
		if (!std::isdigit(y[i]) && y[i] != '.')
			throw InvalidPointException();

	return Vector2(std::stof(x), std::stof(y));
}

const char *Graph::InvalidPointException::what() const throw()
{
	return "Invalid point";
}

const char *Graph::OutOfGraphException::what() const throw()
{
	return "Point out of graph";
}
