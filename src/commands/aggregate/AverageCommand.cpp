#include "AverageCommand.h"

AverageCommand::~AverageCommand() {}

String AverageCommand::toString() const {
	return "average";
}
double AverageCommand::execute(const Vector<double>& parameters) const {
	this->BaseAggregateCommand::execute(parameters);

	double sum = 0;
	unsigned int paramSize = parameters.getSize();

	for (unsigned int i = 0; i < paramSize; i++)
	{
		sum += parameters[i];
	}

	return sum / paramSize;
}