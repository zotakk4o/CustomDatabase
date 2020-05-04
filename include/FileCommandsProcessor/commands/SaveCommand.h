#ifndef SAVECOMMAND_H
#define SAVECOMMAND_H

#include "interfaces/IFileCommand.h"

class SaveCommand : public IFileCommand {
	virtual bool isValid(const Vector<String>&);
	virtual void execute(File&);
	virtual String toString();
};
#endif
