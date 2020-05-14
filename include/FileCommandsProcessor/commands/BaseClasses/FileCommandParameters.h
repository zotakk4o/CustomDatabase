#ifndef FILECOMMANDPARAMETERS_H
#define FILECOMMANDPARAMETERS_H

#include "../../../File.h"
#include "../../../Vector.cpp"
#include "CommandValidator.h"

class FileCommandParameters : public CommandValidator {
	public:
		virtual ~FileCommandParameters();
		virtual void execute(File&, const Vector<String>&) = 0;
};

#endif