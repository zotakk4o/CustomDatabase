#ifndef AVERAGECOMMAND_H
#define AVERAGECOMMAND_H

#include "BaseClasses/BaseAggregateCommand.h"

class AverageCommand : public BaseAggregateCommand {
	public:
		virtual ~AverageCommand();
		virtual String toString() const;
		virtual double execute(const Vector<double>&) const;
};

#endif
