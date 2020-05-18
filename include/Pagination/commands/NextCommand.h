#ifndef NEXTCOMMAND_H
#define NEXTCOMMAND_H

#include "BaseClasses/PaginationCommand.h"

class NextCommand :public PaginationCommand {
	public:
		virtual String toString() const;
		virtual void execute(Pagination&) const;
};

#endif

