#include <stdlib.h>
#include <iostream>
#include "ExitCommand.h"
#include "../config/Messages.cpp"

void ExitCommand::execute() {
	std::cout << FCPMessages::exitMessage << std::endl;
	exit(EXIT_SUCCESS);
}

bool ExitCommand::isValid(const Vector<String>& keywords) {
	return keywords.getSize() == 1 && keywords[0] == this->toString();
}

String ExitCommand::toString() {
	return "exit";
}