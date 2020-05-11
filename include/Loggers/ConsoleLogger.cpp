#include "ConsoleLogger.h"
#include<iostream>

ConsoleLogger ConsoleLogger::logger;

ConsoleLogger ConsoleLogger::getInstance() {
	return ConsoleLogger::logger;
}

void ConsoleLogger::log(const String& data, bool withNewLine) const {
	std::cout << data;

	if (withNewLine) {
		std::cout << std::endl;
	}
}
