#include "CommandValidator.h"

CommandValidator::~CommandValidator() {};

bool CommandValidator::isValid(const Vector<String>& keywords) {
	return this->getParametersCount() == keywords.getSize() && this->toString() == keywords[0];
}