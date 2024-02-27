#pragma once
#include <iostream>
#include <map>

class Command
{
protected:
	static int lastId;

	int id;
	std::string date;
	std::string client;
	std::map<int, int> articles;

public:
	Command(std::string date, std::string client, std::map<int, int> articles)
			: id(lastId++), date(date), client(client), articles(articles) {}

	virtual double get_total_price()
	{
		double total = 0;
		for (std::map<int, int>::iterator it = articles.begin(); it != articles.end(); ++it)
		{
			total += it->first * it->second;
		}
		return total;
	}
};

int Command::lastId = 0;