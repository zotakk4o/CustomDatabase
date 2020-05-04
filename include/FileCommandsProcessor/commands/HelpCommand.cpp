#include <iostream>
#include "HelpCommand.h"
#include "../config/Messages.cpp"

void HelpCommand::execute() {
	std::cout << FCPMessages::helpMessage;
}

bool HelpCommand::isValid(const Vector<String>& keywords) {
	return keywords.getSize() == 1 && this->toString() == keywords[0];
}

String HelpCommand::toString() {
	return "help";
}