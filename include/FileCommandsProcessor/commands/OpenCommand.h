#ifndef OPENCOMMAND_H
#define OPENCOMMAND_H

#include "interfaces/IFileCommandParameters.h"

class OpenCommand : public IFileCommandParameters {
	public:
		virtual bool isValid(const Vector<String>&);
		virtual void execute(File&, const Vector<String>&);
		virtual String toString();
};

#endif

