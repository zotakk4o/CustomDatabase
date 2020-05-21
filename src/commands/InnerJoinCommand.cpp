#include "InnerJoinCommand.h"

InnerJoinCommand::~InnerJoinCommand() {}

const unsigned short InnerJoinCommand::getParametersCount() const {
	return 5;
}

bool InnerJoinCommand::isValid(const Vector<String>& keywords) const {
	return this->DBCommandValidator::isValid(keywords) && keywords[1] != keywords[3];
}

void InnerJoinCommand::execute(DBFile& dbFile, const Vector<String>& parameters) const {
	dbFile.innerJoinTables(parameters);
}

String InnerJoinCommand::toString() const {
	return "innerjoin";
}