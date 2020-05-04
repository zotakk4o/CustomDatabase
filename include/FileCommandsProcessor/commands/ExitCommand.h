#ifndef EXITCOMMAND_H
#define EXITCOMMAND_H

#include "interfaces/ICommand.h"

class ExitCommand :	public ICommand {
	public:
		virtual void execute();
		virtual bool isValid(const Vector<String>&);
		virtual String toString();
};
#endif
