#ifndef PAGINATIONCOMMAND_H
#define PAGINATIONCOMMAND_H

#include "include/String.h"
#include "../../Pagination.h"

class PaginationCommand {
	public:
		virtual bool isValid(const String&) const;
		virtual String toString() const = 0;
		virtual void execute(Pagination&) const = 0;
		virtual ~PaginationCommand();	
};

#endif

