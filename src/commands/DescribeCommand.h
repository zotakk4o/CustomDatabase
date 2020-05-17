#ifndef DESCRIBECOMMAND_H
#define DESCRIBECOMMAND_H

#include "BaseClasses/DBFileCommandParameters.h"

class DescribeCommand : public DBFileCommandParameters {
	protected:
		virtual const unsigned short getParametersCount() const;
	public:
		virtual ~DescribeCommand();
		virtual void execute(DBFile&, const Vector<String>&) const;
		virtual String toString() const;
};

#endif