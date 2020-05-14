#ifndef SHOWTABLES_H
#define SHOWTABLES_H

#include "../config/DCPConfig.h"
#include "BaseClasses/DBFileCommand.h"

class ShowTablesCommand : public DBFileCommand {
	public:
		virtual ~ShowTablesCommand();
		virtual void execute(DBFile&);
		virtual String toString();
};

#endif

