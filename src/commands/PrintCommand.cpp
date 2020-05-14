#include "PrintCommand.h"

PrintCommand::~PrintCommand() {}

void PrintCommand::execute(DBFile& dbFile, const Vector<String>& parameters) {
	dbFile.printTable(parameters[0]);
}

const unsigned short PrintCommand::getParametersCount() const {
	return 2;
}

String PrintCommand::toString() {
	return "print";
}