#ifndef DBFILECOMMANDPARAMETERS_H
#define DBFILECOMMANDPARAMETERS_H

#include "../../FilesHandlers/DBFile.h"
#include "include/Vector.cpp"
#include "DBCommandValidator.h"

class DBFileCommandParameters : public DBCommandValidator {
	public:
		virtual ~DBFileCommandParameters();
		virtual void execute(DBFile&, const Vector<String>&) const = 0;
};

#endif