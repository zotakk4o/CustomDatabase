#include "ProductCommand.h"

#include "../../config/DCPConfig.h"

ProductCommand::~ProductCommand() {}

String ProductCommand::toString() const {
	return "product";
}

void ProductCommand::execute(const Vector<double>& parameters) const {
	this->BaseAggregateCommand::execute(parameters);

	double prod = 1;
	unsigned int paramSize = parameters.getSize();

	for (unsigned int i = 0; i < paramSize; i++)
	{
		prod *= parameters[i];
	}

	DCPConfig::logger.log(String::toString(prod));
}