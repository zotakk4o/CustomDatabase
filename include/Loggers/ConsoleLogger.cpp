#include "ConsoleLogger.h"
#include<iostream>

ConsoleLogger::ConsoleLogger() {}

ConsoleLogger::~ConsoleLogger() {}

ConsoleLogger& ConsoleLogger::getInstance() {
	static ConsoleLogger inst;
	return inst;
}

void ConsoleLogger::log(const String& data, bool withNewLine) {
	std::cout << data;

	if (withNewLine) {
		std::cout << std::endl;
	}
}