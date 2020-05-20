#ifndef AGGREGATECOMMAND_H
#define AGGREGATECOMMAND_H

#include "BaseClasses/DBFileCommandParameters.h"

class AggregateCommand : public DBFileCommandParameters {
	protected:
		virtual const unsigned short getParametersCount() const;
	public:
		virtual ~AggregateCommand();
		virtual void execute(DBFile&, const Vector<String>&) const;
		virtual String toString() const;
};

#endif

