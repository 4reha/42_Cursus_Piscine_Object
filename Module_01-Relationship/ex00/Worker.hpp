#pragma once
#include <vector>
#include <iostream>
#include "Position.hpp"
#include "Statistic.hpp"
#include "Tool.hpp"
#include "Shovel.hpp"
#include "Hammer.hpp"

template <typename Tool>
class Workshop;
class WorkshopBase;

class Worker
{
private:
	Position coordinates;
	Statistic stat;
	std::vector<Tool *> tools;
	std::vector<WorkshopBase *> workshops;

public:
	Worker(int x, int y, int z, int level, int exp);

	template <typename ToolType>
	ToolType *getTool()
	{
		for (std::vector<Tool *>::iterator it = tools.begin(); it != tools.end(); ++it)
		{
			if (ToolType *specificTool = dynamic_cast<ToolType *>(*it))
			{
				std::cout << "Worker has the tool" << std::endl;
				return specificTool;
			}
		}
		std::cout << "Worker does not have the tool" << std::endl;
		return nullptr;
	};

	void giveTool(Tool *newTool);

	void takeTool(Tool *tool);

	void useTool(Tool *tool);

	void registerWorkshop(WorkshopBase *workshop);

	void leaveWorkshop(WorkshopBase *workshop);

	void work(WorkshopBase *workshop);
};
