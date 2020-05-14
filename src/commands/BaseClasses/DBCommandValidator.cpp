#include "DBCommandValidator.h"

DBCommandValidator::~DBCommandValidator() {};

bool DBCommandValidator::isValid(const Vector<String>& keywords) {
	return this->getParametersCount() == keywords.getSize() && this->toString() == keywords[0];
}