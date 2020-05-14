#ifndef COMMAND_H
#define COMMAND_H

#include "CommandValidator.h"

class Command : public CommandValidator
{
	protected:
		virtual const unsigned short getParametersCount() const;
	public:
		virtual ~Command();
		virtual void execute() = 0;
};

#endif
