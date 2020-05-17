#include "DBCommandValidator.h"

DBCommandValidator::~DBCommandValidator() {};

bool DBCommandValidator::isValid(const Vector<String>& keywords) const {
	return this->getParametersCount() == keywords.getSize() && this->toString() == keywords[0];
}