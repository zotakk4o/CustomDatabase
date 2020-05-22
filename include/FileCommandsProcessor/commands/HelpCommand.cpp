#include "HelpCommand.h"
#include "../config/FCPMessages.h"
#include "../config/FCPConfig.h"

HelpCommand::~HelpCommand() {};

void HelpCommand::execute() {
	FCPConfig::consoleLogger.log(FCPMessages::helpMessage);
}

String HelpCommand::toString() {
	return "help";
}