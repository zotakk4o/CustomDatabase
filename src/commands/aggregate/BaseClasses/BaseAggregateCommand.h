#ifndef BASEAGGREGATECOMMAND_H
#define BASEAGGREGATECOMMAND_H

#include "include/String.h"

class BaseAggregateCommand
{
	public:
		virtual ~BaseAggregateCommand();
		virtual bool isValid(const String&) const;
		virtual String toString() const = 0;
		virtual void execute(const Vector<double>&) const;
};

#endif
