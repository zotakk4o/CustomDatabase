#ifndef ADDCOLUMNCOMMAND
#define ADDCOLUMNCOMMAND

#include "BaseClasses/DBFileCommandParameters.h"

class AddColumnCommand : public DBFileCommandParameters {
	protected:
		virtual const unsigned short getParametersCount() const;
	public:
		virtual ~AddColumnCommand();
		virtual bool isValid(const Vector<String>&) const;
		virtual void execute(DBFile&, const Vector<String>&) const;
		virtual String toString() const;
};

#endif
