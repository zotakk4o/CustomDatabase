#ifndef OPENCOMMAND_H
#define OPENCOMMAND_H

#include "BaseClasses/FileCommandParameters.h"

class OpenCommand : public FileCommandParameters {
	protected:
		virtual const unsigned short getParametersCount() const;
	public:
		virtual ~OpenCommand();
		virtual void execute(File&, const Vector<String>&);
		virtual String toString();
};

#endif

