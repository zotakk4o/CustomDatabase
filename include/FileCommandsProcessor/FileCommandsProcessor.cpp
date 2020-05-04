#ifndef FILECOMMANDSPROCESSOR_CPP
#define FILECOMMANDSPROCESSOR_CPP

#include "FileCommandsProcessor.h"
#include "config/Config.cpp"
#include "config/Messages.cpp"
#include "config/Errors.cpp"
#include <iostream>

void FileCommandsProcessor::parseFileCommand(const String& command, File& file) {
	Vector<String> keywords = command.split(FCPConfig::commandDelimiter);

	for (unsigned short i = 0; i < FCPConfig::commands.getSize(); i++)
	{
		if (FCPConfig::commands[i]->isValid(keywords)) {
			FCPConfig::commands[i]->execute();
		}
	}

	for (unsigned short i = 0; i < FCPConfig::fileCommands.getSize(); i++)
	{
		if (FCPConfig::fileCommands[i]->isValid(keywords)) {
			FCPConfig::fileCommands[i]->execute(file);
		}
	}

	for (unsigned short i = 0; i < FCPConfig::fileCommandsParameters.getSize(); i++) {
		if (FCPConfig::fileCommandsParameters[i]->isValid(keywords)) {
			FCPConfig::fileCommandsParameters[i]->execute(
				file, 
				command
				.substring(keywords[0].getLength() - 1, command.getLength() - keywords[0].getLength())
				.split(FCPConfig::commandDelimiter)
			);
		}
	}
}


#endif