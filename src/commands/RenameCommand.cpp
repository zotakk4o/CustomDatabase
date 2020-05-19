#include "RenameCommand.h"

RenameCommand::~RenameCommand() {}

const unsigned short RenameCommand::getParametersCount() const {
	return 3;
}

void RenameCommand::execute(DBFile& dbFile, const Vector<String>& parameters) const {
	dbFile.renameTable(parameters[0], parameters[1]);
}
String RenameCommand::toString() const {
	return "rename";
}