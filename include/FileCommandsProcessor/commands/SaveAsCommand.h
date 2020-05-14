#ifndef SAVEASCOMMAND_H
#define SAVEASCOMMAND_H

#include "BaseClasses/FileCommandParameters.h"

class SaveAsCommand : public FileCommandParameters {
	protected:
		virtual const unsigned short getParametersCount() const;
	public:
		virtual ~SaveAsCommand();
		virtual String toString();
		virtual void execute(File&, const Vector<String>&);
};

#endif

