#ifndef EXITCOMMAND_H
#define EXITCOMMAND_H

#include "BaseClasses/Command.h"

class ExitCommand :	public Command {
	public:
		virtual ~ExitCommand();
		virtual void execute();
		virtual String toString();
};
#endif
