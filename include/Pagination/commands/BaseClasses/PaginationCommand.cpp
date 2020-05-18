#include "PaginationCommand.h"

PaginationCommand::~PaginationCommand() {}

bool PaginationCommand::isValid(const String& keyword) const {
	return keyword.getLength() && this->toString() == keyword;
}
