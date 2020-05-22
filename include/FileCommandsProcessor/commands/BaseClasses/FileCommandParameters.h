#ifndef FILECOMMANDPARAMETERS_H
#define FILECOMMANDPARAMETERS_H

#include "include/File.h"
#include "include/Vector.cpp"
#include "CommandValidator.h"

class FileCommandParameters : public CommandValidator {
	public:
		virtual ~FileCommandParameters();
		virtual void execute(File&, const Vector<String>&) = 0;
};

#endif