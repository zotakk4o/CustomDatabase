#include "SaveCommand.h"
#include "../config/FCPConfig.h"
#include "../config/FCPMessages.h"
#include "../config/FCPErrors.h"

SaveCommand::~SaveCommand() {};

void SaveCommand::execute(File& file) {
	if (!file.isOpened()) {
		FCPConfig::consoleLogger.log(FCPErrors::noFileOpened);
		return;
	}

	if (file.save()) {
		FCPConfig::consoleLogger.log(FCPMessages::saveMessage + file.getPath());
	}
}

String SaveCommand::toString() {
	return "save";
}