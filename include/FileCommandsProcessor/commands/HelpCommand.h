#ifndef HELPCOMMAND_H
#define HELPCOMMAND_H

#include "BaseClasses/Command.h"

class HelpCommand : public Command {
	public:
		virtual ~HelpCommand();
		virtual void execute();
		virtual String toString();
};

#endif