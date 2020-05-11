#ifndef CONSOLELOGGER_H
#define CONSOLELOGGER_H

#include "interfaces/ILogger.h"

class ConsoleLogger : public ILogger {
	private:
		ConsoleLogger() {};
	public:
		static ConsoleLogger& getInstance();
		virtual void log(const String& data, bool withNewLine = true) const;
};

#endif

