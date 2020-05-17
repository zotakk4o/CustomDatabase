#ifndef EXPORTCOMMAND_H
#define EXPORTCOMMAND_H

#include "BaseClasses/DBFileCommandParameters.h"

class ExportCommand : public DBFileCommandParameters {
	protected:
		virtual const unsigned short getParametersCount() const;
	public:
		virtual ~ExportCommand();
		virtual bool isValid(const Vector<String>&) const;
		virtual void execute(DBFile&, const Vector<String>&) const;
		virtual String toString() const;
};

#endif

