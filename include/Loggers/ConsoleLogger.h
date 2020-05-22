#ifndef CONSOLELOGGER_H
#define CONSOLELOGGER_H

#include "interfaces/ILogger.h"

class ConsoleLogger : public ILogger {
	private:
		ConsoleLogger();
	public:
		virtual ~ConsoleLogger();
		ConsoleLogger(const ConsoleLogger&) = delete;
		ConsoleLogger& operator=(const ConsoleLogger&) = delete;

		static ConsoleLogger& getInstance();
		virtual void log(const String& data, bool withNewLine = true);
};

#endif

