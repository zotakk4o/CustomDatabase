#include "SaveAsCommand.h"
#include "../config/FCPConfig.h"
#include "../config/FCPMessages.h"
#include "../config/FCPErrors.h"

SaveAsCommand::~SaveAsCommand() {};

const unsigned short SaveAsCommand::getParametersCount() const {
	return 2;
}

String SaveAsCommand::toString() {
	return "saveas";
}

void SaveAsCommand::execute(File& file, const Vector<String>& parameters) {
	if (!file.isOpened()) {
		FCPConfig::consoleLogger.log(FCPErrors::noFileOpened);
		return;
	}

	if (file.saveAs(parameters[0])) {
		FCPConfig::consoleLogger.log(FCPMessages::saveAsMessage + parameters[0]);
	}
}