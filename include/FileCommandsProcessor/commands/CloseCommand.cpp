#include "CloseCommand.h"
#include "../config/FCPMessages.h"
#include "../config/FCPConfig.h"
#include "../config/FCPErrors.h"

CloseCommand::~CloseCommand() {};

String CloseCommand::toString() {
	return "close";
}

void CloseCommand::execute(File& file) {
	if (!file.isOpened()) {
		FCPConfig::consoleLogger.log(FCPErrors::noFileOpened);
		return;
	}
	String filePath = file.getPath();
	if (file.close()) {
		FCPConfig::consoleLogger.log(FCPMessages::closeMessage + filePath);
	}
}