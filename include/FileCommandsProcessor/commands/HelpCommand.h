#ifndef HELPCOMMAND_H
#define HELPCOMMAND_H

#include "interfaces/ICommand.h"

class HelpCommand : public ICommand {
	virtual void execute();
	virtual bool isValid(const Vector<String>&);
	virtual String toString();
};

#endif