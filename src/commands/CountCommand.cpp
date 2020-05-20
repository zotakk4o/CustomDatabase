#include "CountCommand.h"

CountCommand::~CountCommand() {}

const unsigned short CountCommand::getParametersCount() const {
	return 4;
}

void CountCommand::execute(DBFile& dbFile, const Vector<String>& parameters) const {
	dbFile.countRowsFromTable(parameters);
}

String CountCommand::toString() const {
	return "count";
}