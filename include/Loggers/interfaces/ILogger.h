#ifndef ILOGGER_H
#define ILOGGER_H

#include "include/String.h"

class ILogger
{
	public:
		virtual ~ILogger() {};
		virtual void log(const String&, bool = true) = 0;
};

#endif

