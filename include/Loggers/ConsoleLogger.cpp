#include "ConsoleLogger.h"
#include<iostream>

ConsoleLogger::ConsoleLogger() {};

const ConsoleLogger& ConsoleLogger::getInstance() {
	static ConsoleLogger inst;
	return inst;
}

void ConsoleLogger::log(const String& data, bool withNewLine) const {
	std::cout << data;

	if (withNewLine) {
		std::cout << std::endl;
	}
}