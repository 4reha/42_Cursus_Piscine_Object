#pragma once
#include <iostream>
#include "command.hpp"

class PackageReductionDiscountCommand : public Command
{
public:
	PackageReductionDiscountCommand(std::string date, std::string client, std::map<int, int> articles)
			: Command(date, client, articles) {}

	double get_total_price()
	{
		double total = Command::get_total_price();
		if (total > 150)
		{
			total -= 10;
		}
		return total;
	}
};