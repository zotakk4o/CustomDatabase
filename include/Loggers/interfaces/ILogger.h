#ifndef ILOGGER_H
#define ILOGGER_H

#include "../../String.h"

class ILogger
{
	public:
		virtual ~ILogger() {};
		virtual void log(const String&, bool = true) const = 0;
};

#endif

