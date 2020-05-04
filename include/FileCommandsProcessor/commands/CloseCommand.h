#ifndef CLOSECOMMAND_H
#define CLOSECOMMAND_H

#include "interfaces/IFileCommand.h"

class CloseCommand : public IFileCommand {
	virtual bool isValid(const Vector<String>&);
	virtual String toString();
	virtual void execute(File&);
};

#endif
