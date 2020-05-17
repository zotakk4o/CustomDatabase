#include "AddColumnCommand.h"
#include "../config/DCPConfig.h"
#include "../config/DCPMessages.h"

AddColumnCommand::~AddColumnCommand() {};

const unsigned short AddColumnCommand::getParametersCount() const {
	return 4;
}

bool AddColumnCommand::isValid(const Vector<String>& keywords) const {
	if (!DBFileCommandParameters::isValid(keywords)) {
		return false;
	}

	if (DCPConfig::allowedDataTypes.indexOf(keywords[3]) == -1) {
		DCPConfig::logger.log(DCPMessages::supportedDataTypesMessage + String::join(DCPConfig::allowedDataTypes));
		return false;
	}

	return true;
}

void AddColumnCommand::execute(DBFile& dbFile, const Vector<String>& parameters) const {
	dbFile.addColumnToTable(parameters);
}

String AddColumnCommand::toString() const {
	return "addcolumn";
}

