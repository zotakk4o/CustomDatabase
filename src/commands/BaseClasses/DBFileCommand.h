#ifndef DBFILECOMMAND_H
#define DBFILECOMMAND_H

#include "../../FilesHandlers/DBFile.h"
#include "DBCommandValidator.h"

class DBFileCommand : public DBCommandValidator
{
	protected:
		virtual const unsigned short getParametersCount() const;
	public:
		virtual ~DBFileCommand();
		virtual void execute(DBFile&) = 0;
};

#endif
