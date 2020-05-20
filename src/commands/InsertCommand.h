#ifndef INSERTCOMMAND_H
#define INSERTCOMMAND_H

#include "BaseClasses/DBFileCommandParameters.h"

class InsertCommand : public DBFileCommandParameters {
	protected:
		virtual const unsigned short getParametersCount() const;
	public:
		virtual ~InsertCommand();
		virtual bool isValid(const Vector<String>&) const;
		virtual void execute(DBFile&, const Vector<String>&) const;
		virtual String toString() const;
};

#endif

