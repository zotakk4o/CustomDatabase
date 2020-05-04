#include "DBCommandsProcessor.h"
#include "../include/FileCommandsProcessor/FileCommandsProcessor.h"
#include "FilesHandlers/DBFile.h"

void DBCommandsProcessor::parseCommands() {
	String command;
	DBFile dbFile;

	while (true)
	{
		String::getLine(std::cin, command);
		DBCommandsProcessor::parseFileCommand(command, dbFile);
		DBCommandsProcessor::parseDBCommand(command, dbFile);

	}
}

void DBCommandsProcessor::parseDBCommand(const String& command, DBFile& dbFile) {
	return;
}

void DBCommandsProcessor::start() {
	DBCommandsProcessor::parseCommands();
}