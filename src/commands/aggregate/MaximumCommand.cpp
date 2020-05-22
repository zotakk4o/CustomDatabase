#include "MaximumCommand.h"
#include "../../config/DCPConfig.h"

MaximumCommand::~MaximumCommand() {}

String MaximumCommand::toString() const{
	return "maximum";
}

void MaximumCommand::execute(const Vector<double>& parameters) const {
	this->BaseAggregateCommand::execute(parameters);

	double max = parameters[0];
	unsigned int paramSize = parameters.getSize();

	for (unsigned int i = 1; i < paramSize; i++)
	{
		if (parameters[i] > max) {
			max = parameters[i];
		}
	}

	DCPConfig::logger.log(String::toString(max));
}