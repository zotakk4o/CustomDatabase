#include "ExportCommand.h"

ExportCommand::~ExportCommand() {};
void ExportCommand::execute(DBFile& dbFile, const Vector<String>& parameters) {
	dbFile.exportTable(parameters[0], parameters[1]);
}

const unsigned short ExportCommand::getParametersCount() const {
	return 3;
}

String ExportCommand::toString() {
	return "export";
}