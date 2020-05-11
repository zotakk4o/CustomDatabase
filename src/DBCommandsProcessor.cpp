#include "DBCommandsProcessor.h"
#include "../include/FileCommandsProcessor/FileCommandsProcessor.h"
#include "FilesHandlers/DBFile.h"
#include "config/DCPConfig.h"

Vector<String> DBCommandsProcessor::getAllowedExtensions() {
	return {".csv"};
}

void DBCommandsProcessor::parseCommands() {
	String command;
	DBFile dbFile;

	while (true)
	{
		String::getLine(DCPConfig::inputStream, command);

		this->parseFileCommand(command, dbFile);

		this->parseDBCommand(command, dbFile);

	}
}

void DBCommandsProcessor::parseDBCommand(const String& command, DBFile& dbFile) {
	Vector<String> keywords = command.split(DCPConfig::commandDelimiter);

	for (unsigned short i = 0; i < DCPConfig::dbCommands.getSize(); i++)
	{
		if (DCPConfig::dbCommands[i]->isValid(keywords)) {
			DCPConfig::dbCommands[i]->execute(dbFile);
			return;
		}
	}

	for (unsigned short i = 0; i < DCPConfig::dbCommandsParameters.getSize(); i++) {
		Vector<String> parameters = keywords.slice(1, keywords.getSize() - 1);
		if (DCPConfig::dbCommandsParameters[i]->isValid(keywords)) {
			DCPConfig::dbCommandsParameters[i]->execute(dbFile, parameters);
			return;
		}
	}
}

void DBCommandsProcessor::start() {
	this->parseCommands();
}