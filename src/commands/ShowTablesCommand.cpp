#include "ShowTablesCommand.h"

ShowTablesCommand::~ShowTablesCommand() {};

void ShowTablesCommand::execute(DBFile& dbFile) const {
	dbFile.showTables();
}

String ShowTablesCommand::toString() const {
	return "showtables";
}