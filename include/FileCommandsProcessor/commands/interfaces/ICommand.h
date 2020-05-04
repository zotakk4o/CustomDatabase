#ifndef ICOMMAND_H
#define ICOMMAND_H

#include "ICommandValidator.h"

class ICommand : public ICommandValidator
{
	public:
		virtual void execute() = 0;
};

#endif
