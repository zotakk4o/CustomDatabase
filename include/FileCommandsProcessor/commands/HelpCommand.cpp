#include <iostream>
#include "HelpCommand.h"
#include "../config/Messages.cpp"
#include "../config/FCPConfig.h"

void HelpCommand::execute() {
	FCPConfig::logger.log(FCPMessages::helpMessage);
}

bool HelpCommand::isValid(const Vector<String>& keywords) {
	return keywords.getSize() == 1 && this->toString() == keywords[0];
}

String HelpCommand::toString() {
	return "help";
}