#include "DBCommandsProcessor.h"
#include "../include/FileCommandsProcessor/FileCommandsProcessor.cpp"

void DBCommandsProcessor::parseCommands(const String&, File&) {
	return;
}

void DBCommandsProcessor::start() {
	DBCommandsProcessor::parseInput();
}