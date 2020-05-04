#include "CloseCommand.h"

bool CloseCommand::isValid(const Vector<String>& keywords) {
	return keywords.getSize() == 1 && keywords[0] == this->toString();
}

String CloseCommand::toString() {
	return "close";
}

void CloseCommand::execute(File& file) {
	file.close();
}