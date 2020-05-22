#ifndef DBCOMMANDVALIDATOR_H
#define DBCOMMANDVALIDATOR_H

#include "include/String.h"
#include "include/Vector.cpp"

class DBCommandValidator
{
	protected:
		virtual const unsigned short getParametersCount() const = 0;
	public:
		virtual ~DBCommandValidator();
		virtual bool isValid(const Vector<String>&) const;
		virtual String toString() const = 0;
};

#endif
