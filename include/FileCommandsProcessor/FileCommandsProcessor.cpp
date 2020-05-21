#ifndef FILECOMMANDSPROCESSOR_CPP
#define FILECOMMANDSPROCESSOR_CPP

#include "FileCommandsProcessor.h"
#include "config/FCPConfig.h"
#include "config/FCPMessages.h"
#include "config/FCPErrors.h"

FileCommandsProcessor::~FileCommandsProcessor() {};

bool FileCommandsProcessor::areExtensionsValid(const Vector<String>& filePaths) {
	unsigned int filePathsSize = filePaths.getSize();
	for (unsigned int i = 0; i < filePathsSize; i++)
	{
		unsigned short extensionIndex = filePaths[i].getLength() - filePaths[i].reverse().indexOf('.') - 1;
		String extension = filePaths[i].substring(extensionIndex, filePaths[i].getLength() - extensionIndex);

		if (this->getAllowedExtensions().indexOf(extension) == -1) {
			throw FCPErrors::wrongFileFormatError;
			return false;
		}
	}

	return true;
}

bool FileCommandsProcessor::parseFileCommand(const String& command, File& file) {
	Vector<String> keywords = command.split(FCPConfig::commandDelimiter);
	unsigned int commandsSize = FCPConfig::commands.getSize();

	for (unsigned int i = 0; i < commandsSize; i++)
	{
		if (FCPConfig::commands[i]->isValid(keywords)) {
			FCPConfig::commands[i]->execute();
			return true;
		}
	}

	unsigned int fileCommandsSize = FCPConfig::fileCommands.getSize();
	for (unsigned int i = 0; i < fileCommandsSize; i++)
	{
		if (FCPConfig::fileCommands[i]->isValid(keywords)) {
			FCPConfig::fileCommands[i]->execute(file);
			return true;
		}
	}

	unsigned int fileCommandsParametersSize = FCPConfig::fileCommandsParameters.getSize();
	if (keywords.getSize() >= 2) {
		for (unsigned int i = 0; i < fileCommandsParametersSize; i++) {
			Vector<String> parameters = keywords.slice(1, keywords.getSize() - 1);
			if (FCPConfig::fileCommandsParameters[i]->isValid(keywords) && this->areExtensionsValid(parameters)) {
				FCPConfig::fileCommandsParameters[i]->execute(file, parameters);
				return true;
			}
		}
	}

	if (!file.isOpened()) {
		throw FCPErrors::noFileOpened;
	}

	return false;
}


#endif