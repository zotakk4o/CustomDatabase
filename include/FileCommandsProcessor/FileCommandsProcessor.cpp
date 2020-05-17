#ifndef FILECOMMANDSPROCESSOR_CPP
#define FILECOMMANDSPROCESSOR_CPP

#include "FileCommandsProcessor.h"
#include "config/FCPConfig.h"
#include "config/FCPMessages.h"
#include "config/FCPErrors.h"

FileCommandsProcessor::~FileCommandsProcessor() {};

bool FileCommandsProcessor::areExtensionsValid(const Vector<String>& filePaths) {
	for (unsigned short i = 0; i < filePaths.getSize(); i++)
	{
		unsigned short extensionIndex = filePaths[i].getLength() - filePaths[i].reverse().indexOf('.') - 1;
		String extension = filePaths[i].substring(extensionIndex, filePaths[i].getLength() - extensionIndex);

		if (this->getAllowedExtensions().indexOf(extension) == -1) {
			FCPConfig::logger.log(FCPMessages::wrongFileFormatMessage);
			return false;
		}
	}

	return true;
}

bool FileCommandsProcessor::parseFileCommand(const String& command, File& file) {
	Vector<String> keywords = command.split(FCPConfig::commandDelimiter);
	bool wasCommandExecuted = false;

	for (unsigned short i = 0; i < FCPConfig::fileCommandsParameters.getSize(); i++) {
		Vector<String> parameters = keywords.slice(1, keywords.getSize() - 1);
		if (FCPConfig::fileCommandsParameters[i]->isValid(keywords) && this->areExtensionsValid(parameters)) {
			FCPConfig::fileCommandsParameters[i]->execute(file, parameters);
			wasCommandExecuted = true;
			break;
		}
	}

	if (!file.isOpened()) {
		throw FCPErrors::noFileOpened;
	}

	for (unsigned short i = 0; i < FCPConfig::commands.getSize(); i++)
	{
		if (FCPConfig::commands[i]->isValid(keywords)) {
			FCPConfig::commands[i]->execute();
			wasCommandExecuted = true;
			break;
		}
	}

	for (unsigned short i = 0; i < FCPConfig::fileCommands.getSize(); i++)
	{
		if (FCPConfig::fileCommands[i]->isValid(keywords)) {
			FCPConfig::fileCommands[i]->execute(file);
			wasCommandExecuted = true;
			break;
		}
	}

	return wasCommandExecuted;
}


#endif