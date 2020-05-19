#include "UpdateCommand.h"

UpdateCommand::~UpdateCommand() {}

const unsigned short UpdateCommand::getParametersCount() const {
	return 6;
}

void UpdateCommand::execute(DBFile& dbFile, const Vector<String>& parameters) const {
	dbFile.updateTableEntry(parameters);
}
String UpdateCommand::toString() const {
	return "update";
}