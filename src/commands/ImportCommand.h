#ifndef IMPORTCOMMAND_H
#define IMPORTCOMMAND_H

#include "BaseClasses/DBFileCommandParameters.h"

class ImportCommand : public DBFileCommandParameters {
	protected:
		virtual const unsigned short getParametersCount() const;
	public:
		virtual ~ImportCommand();
		virtual bool isValid(const Vector<String>&);
		virtual void execute(DBFile&, const Vector<String>&) const;
		virtual String toString() const;
};

#endif

