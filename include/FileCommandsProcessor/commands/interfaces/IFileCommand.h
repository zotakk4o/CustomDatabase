#ifndef IFILECOMMAND_H
#define IFILECOMMAND_H

#include "../../../File.h"
#include "ICommandValidator.h"

class IFileCommand : public ICommandValidator
{
	public:
		virtual void execute(File&) = 0;
};

#endif
