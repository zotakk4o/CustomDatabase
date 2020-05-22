#include "SumCommand.h"

#include "../../config/DCPConfig.h"

SumCommand::~SumCommand() {}

String SumCommand::toString() const {
	return "sum";
}

void SumCommand::execute(const Vector<double>& parameters) const {
	this->BaseAggregateCommand::execute(parameters);

	double sum = 0;
	unsigned int paramSize = parameters.getSize();

	for (unsigned int i = 0; i < paramSize; i++)
	{
		sum += parameters[i];
	}

	DCPConfig::consoleLogger.log(String::toString(sum));
}