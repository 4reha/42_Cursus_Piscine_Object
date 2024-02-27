#include "Graph.hpp"

int main()
{
	try
	{
		Graph graph0 = Graph(Vector2(20, 20));
		graph0.addPoint(Vector2(15, 8));
		graph0.addPoint(Vector2(19, 7));
		graph0.addPoint(Vector2(2, 7));
		graph0.addPoint(Vector2(0, 3));
		graph0.addPoint(Vector2(14, 1));
		graph0.addPoint(Vector2(19, 16));
		graph0.addPoint(Vector2(5, 15));

		graph0.display();
		graph0.exportPNG("graph0");

		Graph graph1 = Graph("graph.txt");
		graph1.exportPNG("graph");

		Graph graph2(Vector2(100, 200));
		graph2.addLine(Vector2(0, 0), Vector2(10, 20));
		graph2.addLine(Vector2(0, 20), Vector2(10, 0));
		graph2.addLine(Vector2(0, 0), Vector2(100, 0));
		graph2.addLine(Vector2(0, 20), Vector2(10, 20));
		graph2.exportPNG("graph2");

	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
