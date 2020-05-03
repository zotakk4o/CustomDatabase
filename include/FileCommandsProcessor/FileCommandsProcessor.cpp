#ifndef FILECOMMANDSPROCESSOR_C
#define FILECOMMANDSPROCESSOR_C

#include "FileCommandsProcessor.h"
#include "config/Config.cpp"
#include "config/Messages.cpp"
#include "config/Errors.cpp"
#include "../File.h"
#include <iostream>
#include <stdlib.h>
#include <exception>

template<typename T>
void FileCommandsProcessor<T>::parseFileCommand(const String& command, File& file) {
	Vector<String> keywords;
	keywords = command.split(' ');

	if (FCPConfig::filesCommandsKeywords.indexOf(keywords[0]) == -1) {
		throw FCPErrors::wrongCommandError;
	}

	if (!file.isOpened() && keywords[0] != "open" && keywords[0] != "help" && keywords[0] != "exit") {
		throw FCPErrors::noFileOpened;
	}

	if (keywords[0] == "open") {
		if (keywords.getSize() != 2) {
			throw FCPErrors::noFilenameArgumentError;
		}

		file.open(keywords[1]);
	}
	else if (keywords[0] == "close") {
		file.close();
	}
	else if (keywords[0] == "exit") {
		std::cout << FCPMessages::exitMessage << std::endl;
		exit(EXIT_SUCCESS);
	}
	else if (keywords[0] == "save") {
		file.save();
	}
	else if (keywords[0] == "saveas") {
		if (keywords.getSize() != 2) {
			throw FCPErrors::noFilenameArgumentError;
		}
		file.saveAs(keywords[1]);
	}
	else if (keywords[0] == "help") {
		std::cout << FCPMessages::helpMessage;
	}
}

template<typename T>
void FileCommandsProcessor<T>::parseInput() {
	String command;
	File file;
	bool isDBFileOpened = false;

	std::cout << FCPMessages::helpMessage;

	while (true)
	{
		String::getLine(std::cin, command);
		FileCommandsProcessor::parseFileCommand(command, file);

		T::parseCommands(command, file);
	}

}



#endif