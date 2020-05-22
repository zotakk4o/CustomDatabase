#include "OpenCommand.h"
#include "../config/FCPConfig.h"
#include "../config/FCPMessages.h"
#include "../config/FCPErrors.h"

OpenCommand::~OpenCommand() {};

String OpenCommand::toString() {
	return "open";
}

const unsigned short OpenCommand::getParametersCount() const {
	return 2;
}

void OpenCommand::execute(File& file, const Vector<String>& parameters) {
	if (file.isOpened()) {
		FCPConfig::consoleLogger.log(FCPErrors::couldNotOpenFileError);
		return;
	}

	if (file.open(parameters[0])) {
		FCPConfig::consoleLogger.log(FCPMessages::openMessage + parameters[0]);
	}
}