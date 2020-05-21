#include "MinimumCommand.h"
#include "../../config/DCPConfig.h"

MinimumCommand::~MinimumCommand() {}

String MinimumCommand::toString() const {
	return "minimum";
}

void MinimumCommand::execute(const Vector<double>& parameters) const {
	this->BaseAggregateCommand::execute(parameters);

	double min = parameters[0];
	unsigned int paramSize = parameters.getSize();

	for (unsigned int i = 1; i < paramSize; i++)
	{
		if (parameters[i] < min) {
			min = parameters[i];
		}
	}

	DCPConfig::logger.log(String::toString(min));
}