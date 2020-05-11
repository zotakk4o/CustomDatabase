#ifndef IDBFILECOMMAND_H
#define IDBFILECOMMAND_H

#include "../../FilesHandlers/DBFile.h"
#include "IDBCommandValidator.h"

class IDBFileCommand : public IDBCommandValidator
{
	public:
		virtual ~IDBFileCommand() {};
		virtual void execute(DBFile&) = 0;
};

#endif
