#ifndef COMMANDVALIDATOR_H
#define COMMANDVALIDATOR_H

#include "include/String.h"

class CommandValidator
{
	protected:
		virtual const unsigned short getParametersCount() const = 0;
	public:
		virtual ~CommandValidator();
		virtual bool isValid(const Vector<String>&);
		virtual String toString() = 0;
};

#endif
