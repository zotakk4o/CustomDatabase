#ifndef INNERJOINCOMMAND
#define INNERJOINCOMMAND

#include "BaseClasses/DBFileCommandParameters.h"

class InnerJoinCommand : public DBFileCommandParameters {
	protected:
		virtual const unsigned short getParametersCount() const;
	public:
		virtual ~InnerJoinCommand();
		virtual bool isValid(const Vector<String>&) const;
		virtual void execute(DBFile&, const Vector<String>&) const;
		virtual String toString() const;
};

#endif

