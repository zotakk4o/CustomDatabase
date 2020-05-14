#include "Command.h"

Command::~Command() {}

const unsigned short Command::getParametersCount() const {
	return 1;
}