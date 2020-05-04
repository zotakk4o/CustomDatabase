#include "OpenCommand.h"

String OpenCommand::toString() {
	return "open";
}

bool OpenCommand::isValid(const Vector<String>& keywords) {
	return keywords.getSize() == 2 && keywords[0] == this->toString();
}

void OpenCommand::execute(File& file, const Vector<String>& parameters) {
	file.open(parameters[1]);
}