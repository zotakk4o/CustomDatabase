#ifndef FILECOMMANDSPROCESSOR_CPP
#define FILECOMMANDSPROCESSOR_CPP

#include "FileCommandsProcessor.h"
#include "config/Config.cpp"
#include "config/Messages.cpp"
#include "config/Errors.cpp"
#include <iostream>

bool FileCommandsProcessor::areExtensionsValid(const Vector<String>& filePaths) {
	for (unsigned short i = 0; i < filePaths.getSize(); i++)
	{
		unsigned short extensionIndex = filePaths[i].reverse().indexOf('.');
		String extension = filePaths[i].substring(extensionIndex, filePaths[i].getLength() - extensionIndex);

		if (this->getAllowedExtensions().indexOf(extension) == -1) {
			std::cout << FCPMessages::wrongFileFormatMessage;
			return false;
		}
	}

	return true;
}

void FileCommandsProcessor::parseFileCommand(const String& command, File& file) {
	Vector<String> keywords = command.split(FCPConfig::commandDelimiter);

	for (unsigned short i = 0; i < FCPConfig::commands.getSize(); i++)
	{
		if (FCPConfig::commands[i]->isValid(keywords)) {
			FCPConfig::commands[i]->execute();
			return;
		}
	}

	for (unsigned short i = 0; i < FCPConfig::fileCommands.getSize(); i++)
	{
		if (FCPConfig::fileCommands[i]->isValid(keywords)) {
			FCPConfig::fileCommands[i]->execute(file);
			return;
		}
	}

	for (unsigned short i = 0; i < FCPConfig::fileCommandsParameters.getSize(); i++) {
		Vector<String> parameters = keywords.slice(1, keywords.getSize() - 1);
		if (FCPConfig::fileCommandsParameters[i]->isValid(keywords) && this->areExtensionsValid(parameters)) {
			FCPConfig::fileCommandsParameters[i]->execute(file, parameters);
			return;
		}
	}
}


#endif