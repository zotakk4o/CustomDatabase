#ifndef DCPCONFIG_H
#define DCPCONFIG_H

#include "../../include/String.h"
#include "../../include/Vector.cpp"
#include "../interfaces/IDBFileCommand.h"
#include "../interfaces/IDBFileCommandParameters.h"
#include "../../include/Loggers/ConsoleLogger.h"
#include <iostream>

class DCPConfig {
	public:
		static const char commandDelimiter;
		static const char fileDelimiter;
		static std::istream& inputStream;
		static const ILogger& logger;
		static const Vector<IDBFileCommand*> dbCommands;
		static const Vector<IDBFileCommandParameters*> dbCommandsParameters;
};
 
#endif