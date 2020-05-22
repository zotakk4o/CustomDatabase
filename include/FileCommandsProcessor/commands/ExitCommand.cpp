#include <stdlib.h>
#include "ExitCommand.h"
#include "../config/FCPMessages.h"
#include "../config/FCPConfig.h"

ExitCommand::~ExitCommand() {};

void ExitCommand::execute() {
	FCPConfig::consoleLogger.log(FCPMessages::exitMessage);
	exit(EXIT_SUCCESS);
}

String ExitCommand::toString() {
	return "exit";
}