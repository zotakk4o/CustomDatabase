#include "ShowTablesCommand.h"

ShowTablesCommand::~ShowTablesCommand() {};

void ShowTablesCommand::execute(DBFile& dbFile) {
	dbFile.showTables();
}

String ShowTablesCommand::toString() {
	return "showtables";
}