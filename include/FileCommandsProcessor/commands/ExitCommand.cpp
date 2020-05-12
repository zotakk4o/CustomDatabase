#include <stdlib.h>
#include <iostream>
#include "ExitCommand.h"
#include "../config/FCPMessages.h"
#include "../config/FCPConfig.h"

void ExitCommand::execute() {
	FCPConfig::logger.log(FCPMessages::exitMessage);
	exit(EXIT_SUCCESS);
}

bool ExitCommand::isValid(const Vector<String>& keywords) {
	return keywords.getSize() == 1 && keywords[0] == this->toString();
}

String ExitCommand::toString() {
	return "exit";
}