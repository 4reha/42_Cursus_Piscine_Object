#pragma once
#include <iostream>
#include "command.hpp"

class TuesdayDiscountCommand : public Command
{
public:
	TuesdayDiscountCommand(std::string date, std::string client, std::map<int, int> articles)
			: Command(date, client, articles) {}

	double get_total_price()
	{
		double total = Command::get_total_price();
		if (date == "Tuesday")
		{
			total *= 0.9;
		}
		return total;
	}
};