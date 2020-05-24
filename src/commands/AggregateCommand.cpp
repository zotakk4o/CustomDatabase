#include "AggregateCommand.h"
#include "../config/DCPConfig.h"

AggregateCommand::~AggregateCommand() {}

const unsigned short AggregateCommand::getParametersCount() const {
	return 6;
}

void AggregateCommand::execute(DBFile& dbFile, const Vector<String>& parameters) const {
	DCPConfig::consoleLogger.log(String::toString(dbFile.aggregate(parameters)));
}

String AggregateCommand::toString() const {
	return "aggregate";
}