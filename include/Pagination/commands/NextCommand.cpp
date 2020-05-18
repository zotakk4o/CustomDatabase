#include "NextCommand.h"

String NextCommand::toString() const {
	return "next";
}

void NextCommand::execute(Pagination& pagination) const {
	pagination.next();
}