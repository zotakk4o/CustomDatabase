#ifndef IFILECOMMANDPARAMETERS_H
#define IFILECOMMANDPARAMETERS_H

#include "../../../File.h"
#include "../../../Vector.cpp"
#include "ICommandValidator.h"

class IFileCommandParameters : public ICommandValidator {
	public:
		virtual ~IFileCommandParameters() {};
		virtual void execute(File&, const Vector<String>&) = 0;
};

#endif