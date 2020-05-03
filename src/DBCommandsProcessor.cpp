#include "DBCommandsProcessor.h"
#include "../include/FileCommandsProcessor/FileCommandsProcessor.cpp"
#include "FilesHandlers//DBFile.h"

void DBCommandsProcessor::parseCommands(const String& command, const File& file) {
	DBFile dbFile = file;
	return;
}

void DBCommandsProcessor::start() {
	DBCommandsProcessor::parseInput();
}