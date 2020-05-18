#include "PrevCommand.h"

String PrevCommand::toString() const {
	return "prev";
}

void PrevCommand::execute(Pagination& pagination) const {
	pagination.prev();
}