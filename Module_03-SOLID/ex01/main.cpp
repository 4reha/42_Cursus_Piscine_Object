#include <iostream>
#include "tuesdayDiscount.hpp"
#include "packageReductionDiscount.hpp"

int main()
{
	std::map<int, int> articles;
	articles.insert(std::pair<int, int>(5, 10));
	articles.insert(std::pair<int, int>(5, 20));
	articles.insert(std::pair<int, int>(5, 30));
	articles.insert(std::pair<int, int>(5, 40));
	Command command("Monday", "client1", articles);
	TuesdayDiscountCommand tuesdayCommand("Tuesday", "client2", articles);
	PackageReductionDiscountCommand packageCommand("Wednesday", "client3", articles);

	std::cout << "Command total price: " << command.get_total_price() << std::endl;
	std::cout << "Tuesday Command total price: " << tuesdayCommand.get_total_price() << std::endl;
	std::cout << "Package Command total price: " << packageCommand.get_total_price() << std::endl;

	return 0;
}