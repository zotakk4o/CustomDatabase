#include "InsertCommand.h"

InsertCommand::~InsertCommand() {}

const unsigned short InsertCommand::getParametersCount() const {
	return 2;
}

bool InsertCommand::isValid(const Vector<String>& keywords) const {
	return keywords.getSize() >= this->getParametersCount() && keywords[0] == this->toString();
}

void InsertCommand::execute(DBFile& dbFile, const Vector<String>& parameters) const {
	dbFile.insertRow(parameters);
}

String InsertCommand::toString() const {
	return "insert";
}