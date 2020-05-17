#ifndef PRINTCOMMAND_H
#define PRINTCOMMAND_H

#include "BaseClasses/DBFileCommandParameters.h"

class PrintCommand : public DBFileCommandParameters {
	protected:
		virtual const unsigned short getParametersCount() const;
	public:
		virtual ~PrintCommand();
		virtual void execute(DBFile&, const Vector<String>&) const;
		virtual String toString() const;
};

#endif