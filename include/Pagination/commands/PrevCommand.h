#ifndef PREVCOMMAND_H
#define PREVCOMMAND_H

#include "BaseClasses/PaginationCommand.h"

class PrevCommand : public PaginationCommand {
	public:
		virtual String toString() const;
		virtual void execute(Pagination&) const;
};

#endif

