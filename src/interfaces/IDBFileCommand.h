#ifndef IDBFILECOMMAND_H
#define IDBFILECOMMAND_H

#include "../FilesHandlers/DBFile.h"
#include "ICommandValidator.h"

class IDBFileCommand : public ICommandValidator
{
	public:
		virtual ~IDBFileCommand() {};
		virtual void execute(DBFile&) = 0;
};

#endif
