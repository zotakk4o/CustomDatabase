#include "DescribeCommand.h"

DescribeCommand::~DescribeCommand() {}

void DescribeCommand::execute(DBFile& dbFile, const Vector<String>& parameters) const {
	dbFile.describeTable(parameters[0]);
}

const unsigned short DescribeCommand::getParametersCount() const {
	return 2;
}

String DescribeCommand::toString() const {
	return "describe";
}