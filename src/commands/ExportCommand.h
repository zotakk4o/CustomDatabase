#ifndef EXPORTCOMMAND_H
#define EXPORTCOMMAND_H

#include "BaseClasses/DBFileCommandParameters.h"

class ExportCommand : public DBFileCommandParameters {
	protected:
		virtual const unsigned short getParametersCount() const;
	public:
		virtual ~ExportCommand();
		virtual void execute(DBFile&, const Vector<String>&);
		virtual String toString();
};

#endif

