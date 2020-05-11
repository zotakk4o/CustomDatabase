#ifndef IDBFILECOMMANDPARAMETERS_H
#define IDBFILECOMMANDPARAMETERS_H

#include "../FilesHandlers/DBFile.h"
#include "../../include/Vector.cpp"
#include "ICommandValidator.h"

class IDBFileCommandParameters : public ICommandValidator {
	public:
		virtual ~IDBFileCommandParameters() {};
		virtual void execute(DBFile&, const Vector<String>&) = 0;
};

#endif