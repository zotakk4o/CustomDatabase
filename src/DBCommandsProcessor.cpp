#include "DBCommandsProcessor.h"
#include "../include/FileCommandsProcessor/FileCommandsProcessor.h"
#include "FilesHandlers/DBFile.h"
#include "config/DCPConfig.h"
#include "config/DCPErrors.h"

Vector<String> DBCommandsProcessor::getAllowedExtensions() {
	return DCPConfig::fileExtensions;
}

void DBCommandsProcessor::parseCommands() {
	String command;
	DBFile dbFile{&DCPConfig::logger};

	while (true)
	{
		
		String::getLine(DCPConfig::inputStream, command);

		if (!this->parseFileCommand(command, dbFile) && !this->parseDBCommand(command, dbFile)) {
			throw DCPErrors::wrongCommandError;
		}
	}
}

bool DBCommandsProcessor::parseDBCommand(const String& command, DBFile& dbFile) {
	Vector<String> keywords = command.split(DCPConfig::commandDelimiter);

	for (unsigned short i = 0; i < DCPConfig::dbCommands.getSize(); i++)
	{
		if (DCPConfig::dbCommands[i]->isValid(keywords)) {
			DCPConfig::dbCommands[i]->execute(dbFile);
			return true;
		}
	}

	if (keywords.getSize() < 2) {
		return false;
	}

	for (unsigned short i = 0; i < DCPConfig::dbCommandsParameters.getSize(); i++) {
		Vector<String> parameters = keywords.slice(1, keywords.getSize() - 1);
		if (DCPConfig::dbCommandsParameters[i]->isValid(keywords)) {
			DCPConfig::dbCommandsParameters[i]->execute(dbFile, parameters);
			return true;
		}
	}

	return false;
}

void DBCommandsProcessor::start() {
	this->parseCommands();
}