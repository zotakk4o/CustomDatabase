#ifndef UPDATECOMMAND_H
#define UPDATECOMMAND_H

#include "BaseClasses/DBFileCommandParameters.h"

class UpdateCommand : public DBFileCommandParameters {
	protected:
		virtual const unsigned short getParametersCount() const;
	public:
		virtual ~UpdateCommand();
		virtual void execute(DBFile&, const Vector<String>&) const;
		virtual String toString() const;
};

#endif

