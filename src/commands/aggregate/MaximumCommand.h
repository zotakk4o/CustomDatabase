#ifndef MAXIMUMCOMMAND_H
#define MAXIMUMCOMMAND_H

#include "BaseClasses/BaseAggregateCommand.h"

class MaximumCommand : public BaseAggregateCommand {
	public:
		virtual ~MaximumCommand();
		virtual String toString() const;
		virtual double execute(const Vector<double>&) const;
};

#endif
