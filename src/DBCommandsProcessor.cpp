#include "DBCommandsProcessor.h"
#include "include/FileCommandsProcessor/FileCommandsProcessor.h"
#include "FilesHandlers/DBFile.h"
#include "config/DCPConfig.h"
#include "config/DCPErrors.h"

Vector<String> DBCommandsProcessor::getAllowedExtensions() {
	return DCPConfig::fileExtensions;
}

void DBCommandsProcessor::parseCommands() {
	String command;
	DBFile dbFile{&DCPConfig::fileLogger};

	while (true)
	{
		String::getLine(DCPConfig::inputStream, command);
		try {
			if (!this->parseFileCommand(command, dbFile) && !this->parseDBCommand(command, dbFile)) {
				DCPConfig::consoleLogger.log(DCPErrors::wrongCommandError);
			}
		}
		catch (const String& err) {
			DCPConfig::consoleLogger.log(err);
		}
		
	}
}

bool DBCommandsProcessor::parseDBCommand(const String& command, DBFile& dbFile) {
	Vector<String> keywords = command.split(DCPConfig::commandDelimiter);

	unsigned int dbCommandsSize = DCPConfig::dbCommands.getSize();
	for (unsigned int i = 0; i < dbCommandsSize; i++)
	{
		if (DCPConfig::dbCommands[i]->isValid(keywords)) {
			DCPConfig::dbCommands[i]->execute(dbFile);
			return true;
		}
	}

	if (keywords.getSize() < 2) {
		return false;
	}

	unsigned int dbCommandsParametersSize = DCPConfig::dbCommandsParameters.getSize();
	for (unsigned int i = 0; i < dbCommandsParametersSize; i++) {
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