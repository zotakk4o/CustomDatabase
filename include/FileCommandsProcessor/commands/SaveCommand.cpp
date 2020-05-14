#include "SaveCommand.h"

SaveCommand::~SaveCommand() {};

void SaveCommand::execute(File& file) {
	file.save();
}

String SaveCommand::toString() {
	return "save";
}