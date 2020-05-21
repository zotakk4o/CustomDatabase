#include "BaseAggregateCommand.h"
#include "../../../config/DCPMessages.h"

BaseAggregateCommand::~BaseAggregateCommand() {}

bool BaseAggregateCommand::isValid(const String& keyword) const {
	return this->toString() == keyword;
}

void BaseAggregateCommand::execute(const Vector<double>& params) const {
	if (!params.getSize()) {
		throw DCPMessages::emptyAggregateOperands + this->toString();
	}
}