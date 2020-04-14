#include "CommandsProcessor.h"
#include <iostream>
#include "../config/Config.cpp"


bool CommandsProcessor::wasKeywordFound(const String& keyword) {
	return  Config::commandsKeywords.indexOf(keyword) != -1;
}

void CommandsProcessor::parseInput() {
}

void CommandsProcessor::start() {
	std::cout << Config::welcomeMessage;
	std::cout << Config::helpMessage;

	CommandsProcessor::parseInput();
}
		
