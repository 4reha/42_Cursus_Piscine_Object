#pragma once
#include <iostream>
#include "Worker.hpp"

class WorkshopBase
{
public:
	WorkshopBase(){};
	~WorkshopBase(){};
	virtual bool checkTool(Worker *worker) = 0;
	virtual void registerWorker(Worker *worker) = 0;
	virtual void releaseWorker(Worker *worker) = 0;
	virtual void executeWorkDay() = 0;
};

template <typename RequiredTool>
class Workshop : public WorkshopBase
{
private:
	std::vector<Worker *> workers;

public:
	Workshop()
	{
		std::cout << "Workshop created" << std::endl;
	};
	~Workshop(){};

	bool checkTool(Worker *worker)
	{
		// Check if the worker has the required tool
		if (worker->getTool<RequiredTool>() == nullptr)
		{
			std::cout << "Worker does not have the required tool." << std::endl;
			releaseWorker(worker);
			return false;
		}
		return true;
	}

	void registerWorker(Worker *worker)
	{
		// Check if the worker has the required tool
		if (worker->getTool<RequiredTool>() == nullptr)
		{
			std::cout << "Worker does not have the required tool." << std::endl;
			return;
		}

		// Check if the worker is already registered at this workshop
		for (std::vector<Worker *>::iterator it = workers.begin(); it != workers.end(); ++it)
		{
			if (*it == worker)
			{
				std::cout << "Worker is already registered at this workshop." << std::endl;
				return;
			}
		}

		workers.push_back(worker);
		worker->registerWorkshop(this);
	}

	void releaseWorker(Worker *worker)
	{
		for (std::vector<Worker *>::iterator it = workers.begin(); it != workers.end(); ++it)
		{
			if (*it == worker)
			{
				workers.erase(it);
				worker->leaveWorkshop(this);
				std::cout << "Workshop released Worker" << std::endl;
				return;
			}
		}
		std::cout << "Worker is not registered at this workshop." << std::endl;
	}

	void executeWorkDay()
	{
		for (std::vector<Worker *>::iterator it = workers.begin(); it != workers.end(); ++it)
		{
			(*it)->work(this);
		}
	}
};