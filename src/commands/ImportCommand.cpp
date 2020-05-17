#include "ImportCommand.h"
#include "../config/DCPConfig.h"

ImportCommand::~ImportCommand() {}

const unsigned short ImportCommand::getParametersCount() const {
	return 2;
}

bool ImportCommand::isValid(const Vector<String>& keywords) {
	return DBFileCommandParameters::isValid(keywords) && keywords[1].indexOf(DCPConfig::tableFileExtension) != -1;
}

void ImportCommand::execute(DBFile& dbFile, const Vector<String>& parameters) const {
	dbFile.importTable(parameters[0]);
}

String ImportCommand::toString() const {
	return "import";
}
