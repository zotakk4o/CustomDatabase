#include "SaveCommand.h"

bool SaveCommand::isValid(const Vector<String>& keywords) {
	return keywords.getSize() == 1 && keywords[0] == this->toString();
}

void SaveCommand::execute(File& file) {
	file.save();
}

String SaveCommand::toString() {
	return "save";
}