#include "SaveAsCommand.h"

bool SaveAsCommand::isValid(const Vector<String>& keywords) {
	return keywords.getSize() == 2 && keywords[0] == this->toString();
}
String SaveAsCommand::toString() {
	return "saveas";
}

void SaveAsCommand::execute(File& file, const Vector<String>& parameters) {
	file.saveAs(parameters[0]);
}