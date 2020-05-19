#include "SelectCommand.h"
SelectCommand::~SelectCommand() {}

const unsigned short SelectCommand::getParametersCount() const {
	return 4;
}

void SelectCommand::execute(DBFile& dbFile, const Vector<String>& parameters) const {
	dbFile.selectFromTable(parameters);
}

String SelectCommand::toString() const {
	return "select";
}