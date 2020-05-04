#ifndef SAVEASCOMMAND_H
#define SAVEASCOMMAND_H

#include "interfaces/IFileCommandParameters.h"

class SaveAsCommand : public IFileCommandParameters {
	virtual bool isValid(const Vector<String>&);
	virtual String toString();
	virtual void execute(File&, const Vector<String>&);
};

#endif

