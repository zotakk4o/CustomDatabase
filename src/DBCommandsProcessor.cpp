#include "DBCommandsProcessor.h"
#include "../include/FileCommandsProcessor/FileCommandsProcessor.h"
#include "FilesHandlers/DBFile.h"

Vector<String> DBCommandsProcessor::getAllowedExtensions() {
	return {".csv"};
}

void DBCommandsProcessor::parseCommands() {
	String command;
	DBFile dbFile;

	while (true)
	{
		String::getLine(std::cin, command);

		this->parseFileCommand(command, dbFile);

		this->parseDBCommand(command, dbFile);

	}
}

void DBCommandsProcessor::parseDBCommand(const String& command, DBFile& dbFile) {
	return;
}

void DBCommandsProcessor::start() {
	this->parseCommands();
}