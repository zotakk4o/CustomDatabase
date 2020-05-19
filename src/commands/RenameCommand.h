#ifndef RENAMECOMMAND_H
#define RENAMECOMMAND_H

#include "BaseClasses/DBFileCommandParameters.h"

class RenameCommand : public DBFileCommandParameters {
	protected:
		virtual const unsigned short getParametersCount() const;
	public:
		virtual ~RenameCommand();
		virtual void execute(DBFile&, const Vector<String>&) const;
		virtual String toString() const;
};

#endif 
