#include "Worker.hpp"
#include "Workshop.hpp"

Worker::Worker(int x, int y, int z, int level, int exp)
{
	coordinates.x = x;
	coordinates.y = y;
	coordinates.z = z;
	stat.level = level;
	stat.exp = exp;

	std::cout << "Worker created" << std::endl;
}

void Worker::giveTool(Tool *newTool)
{
	// Check if the worker already has this tool
	for (std::vector<Tool *>::iterator it = tools.begin(); it != tools.end(); ++it)
	{
		if (*it == newTool)
		{
			std::cout << "Worker already has the tool" << std::endl;
			return;
		}
	}
	// Add the new tool
	tools.push_back(newTool);
	std::cout << "Worker has been given a tool" << std::endl;
}

void Worker::takeTool(Tool *tool)
{
	for (std::vector<Tool *>::iterator it = tools.begin(); it != tools.end(); ++it)
	{
		if (*it == tool)
		{
			// Remove the tool
			tools.erase(it);
			std::cout << "the tool has taken from the worker" << std::endl;

			for (std::vector<WorkshopBase *>::iterator it = workshops.begin(); it != workshops.end(); ++it)
			{
				if (!(*it)->checkTool(this))
					it--;
			}

			return;
		}
	}
	std::cout << "Worker does not have the tool" << std::endl;
}

void Worker::useTool(Tool *tool)
{
	for (std::vector<Tool *>::iterator it = tools.begin(); it != tools.end(); ++it)
	{
		if (*it == tool)
		{
			// Use the tool
			tool->use();
			std::cout << "Worker has used the tool" << std::endl;
			return;
		}
	}
	std::cout << "Worker does not have the tool" << std::endl;
}

void Worker::registerWorkshop(WorkshopBase *workshop)
{
	workshops.push_back(workshop);
	std::cout << "Worker has registered to a workshop" << std::endl;
}

void Worker::leaveWorkshop(WorkshopBase *workshop)
{
	for (std::vector<WorkshopBase *>::iterator it = workshops.begin(); it != workshops.end(); ++it)
	{
		if (*it == workshop)
		{
			workshops.erase(it);
			std::cout << "Worker has left the workshop" << std::endl;
			return;
		}
	}
	std::cout << "Worker has not registered to the workshop" << std::endl;
}

void Worker::work(WorkshopBase *workshop)
{
	for (std::vector<WorkshopBase *>::iterator it = workshops.begin(); it != workshops.end(); ++it)
	{
		if (*it == workshop)
		{
			std::cout << "Worker working in workshop" << std::endl;
			for (std::vector<Tool *>::iterator it = tools.begin(); it != tools.end(); ++it)
				(*it)->use();
			return;
		}
	}
	std::cout << "Worker not registered in the workshop" << std::endl;
}