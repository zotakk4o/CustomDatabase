#include <stdlib.h>
#include <iostream>
#include "ExitCommand.h"
#include "../config/FCPMessages.h"
#include "../config/FCPConfig.h"

ExitCommand::~ExitCommand() {};

void ExitCommand::execute() {
	FCPConfig::logger.log(FCPMessages::exitMessage);
	exit(EXIT_SUCCESS);
}

String ExitCommand::toString() {
	return "exit";
}