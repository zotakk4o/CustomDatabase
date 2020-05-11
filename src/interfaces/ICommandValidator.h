#ifndef ICOMMANDVALIDATOR_H
#define ICOMMANDVALIDATOR_H

#include "../../include/String.h"

class ICommandValidator
{
	public:
		virtual ~ICommandValidator() {};
		virtual bool isValid(const Vector<String>&) = 0;
		virtual String toString() = 0;
};

#endif
