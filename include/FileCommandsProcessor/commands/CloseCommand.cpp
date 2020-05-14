#include "CloseCommand.h"

CloseCommand::~CloseCommand() {};

String CloseCommand::toString() {
	return "close";
}

void CloseCommand::execute(File& file) {
	file.close();
}