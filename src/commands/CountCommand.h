#ifndef COUNTCOMMAND_H
#define COUNTCOMMAND_H

#include "BaseClasses/DBFileCommandParameters.h"

class CountCommand : public DBFileCommandParameters {
	protected:
		virtual const unsigned short getParametersCount() const;
	public:
		virtual ~CountCommand();
		virtual void execute(DBFile&, const Vector<String>&) const;
		virtual String toString() const;
};

#endif


