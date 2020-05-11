#ifndef IDBFILECOMMANDPARAMETERS_H
#define IDBFILECOMMANDPARAMETERS_H

#include "../../FilesHandlers/DBFile.h"
#include "../../../include/Vector.cpp"
#include "IDBCommandValidator.h"

class IDBFileCommandParameters : public IDBCommandValidator {
	public:
		virtual ~IDBFileCommandParameters();
		virtual void execute(DBFile&, const Vector<String>&) = 0;
};

#endif