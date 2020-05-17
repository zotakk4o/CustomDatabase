#include "ExportCommand.h"
#include "../config/DCPConfig.h"


ExportCommand::~ExportCommand() {};

bool ExportCommand::isValid(const Vector<String>& keywords) const {
	return DBFileCommandParameters::isValid(keywords) && keywords[2].indexOf(DCPConfig::tableFileExtension) != -1;
}

void ExportCommand::execute(DBFile& dbFile, const Vector<String>& parameters) const {
	dbFile.exportTable(parameters[0], parameters[1]);
}

const unsigned short ExportCommand::getParametersCount() const {
	return 3;
}

String ExportCommand::toString() const {
	return "export";
}