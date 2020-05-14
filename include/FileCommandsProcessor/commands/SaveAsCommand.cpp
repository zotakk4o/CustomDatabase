#include "SaveAsCommand.h"

SaveAsCommand::~SaveAsCommand() {};

const unsigned short SaveAsCommand::getParametersCount() const {
	return 2;
}

String SaveAsCommand::toString() {
	return "saveas";
}

void SaveAsCommand::execute(File& file, const Vector<String>& parameters) {
	file.saveAs(parameters[0]);
}