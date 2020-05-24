#ifndef MINIMUMCOMMAND_H
#define MINIMUMCOMMAND_H

#include "BaseClasses/BaseAggregateCommand.h"

class MinimumCommand : public BaseAggregateCommand {
public:
	virtual ~MinimumCommand();
	virtual String toString() const;
	virtual double execute(const Vector<double>&) const;
};

#endif
