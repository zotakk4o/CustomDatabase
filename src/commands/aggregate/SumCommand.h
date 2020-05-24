#ifndef SUMCOMMAND_H
#define SUMCOMMAND_H

#include "BaseClasses/BaseAggregateCommand.h"

class SumCommand : public BaseAggregateCommand {
public:
	virtual ~SumCommand();
	virtual String toString() const;
	virtual double execute(const Vector<double>&) const;
};

#endif
