#include "DeleteCommand.h"

DeleteCommand::~DeleteCommand() {}

const unsigned short DeleteCommand::getParametersCount() const {
	return 4;
}


void DeleteCommand::execute(DBFile& dbFile, const Vector<String>& parameters) const {
	dbFile.deleteFromTable(parameters);
}

String DeleteCommand::toString() const {
	return "delete";
}