#include <vector>
#include "ILogger.hpp"
#include "FileLogger.hpp"
#include "OstreamLogger.hpp"
#include "DateHeaderLogger.hpp"
#include "ConstantHeaderLogger.hpp"
#include "FileStream.hpp"

int main()
{
	std::vector<ILogger *> loggers;

	FileStream log_txt("log.txt");
	FileStream log_with_date_txt("log_with_date.txt");

	loggers.push_back(new FileLogger(log_txt));
	loggers.push_back(new OstreamLogger(std::cout));
	loggers.push_back(new DateHeaderLogger(*new FileLogger(log_with_date_txt)));
	loggers.push_back(new ConstantHeaderLogger(*new OstreamLogger(std::cout), "[INFO] "));

	std::vector<std::string> messages;
	messages.push_back("Hello");
	messages.push_back("World");
	messages.push_back("!!");

	for (std::vector<std::string>::iterator it = messages.begin(); it != messages.end(); ++it)
	{
		for (std::vector<ILogger *>::iterator loggerIt = loggers.begin(); loggerIt != loggers.end(); ++loggerIt)
		{
			(*loggerIt)->write(*it);
		}
	}

	for (std::vector<ILogger *>::iterator it = loggers.begin(); it != loggers.end(); ++it)
	{
		delete *it;
	}

	return 0;
}