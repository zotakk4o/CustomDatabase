#ifndef FILECOMMANDSPROCESSOR_CPP
#define FILECOMMANDSPROCESSOR_CPP

#include "FileCommandsProcessor.h"
#include "config/FCPConfig.h"
#include "config/Messages.cpp"
#include "config/Errors.cpp"

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