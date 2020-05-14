#include "OpenCommand.h"

OpenCommand::~OpenCommand() {};

String OpenCommand::toString() {
	return "open";
}

const unsigned short OpenCommand::getParametersCount() const {
	return 2;
}

void OpenCommand::execute(File& file, const Vector<String>& parameters) {
	file.open(parameters[0]);
}