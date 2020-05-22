#ifndef DCPCONFIG_H
#define DCPCONFIG_H

#include "include/String.h"
#include "include/Vector.cpp"
#include "../commands/BaseClasses/DBFileCommand.h"
#include "../commands/BaseClasses/DBFileCommandParameters.h"
#include "../commands/aggregate/BaseClasses/BaseAggregateCommand.h"
#include "include/Loggers/ConsoleLogger.h"
#include "include/Loggers/FileLogger.h"

#include <iostream>

class DCPConfig {
	public:
		static const char commandDelimiter;
		static const char fileDelimiter;
		static const char columnConfigDelimiter;
		static const unsigned short perPageEntries;
		static const String doubleType;
		static const String stringType;
		static const String intType;
		static const String defaultFilesLocation;
		static const String tableFileExtension;
		static const String dbFileExtension;
		static const String nullValue;
		static const Vector<String> fileExtensions;
		static const Vector<String> allowedDataTypes;
		static std::istream& inputStream;
		static ConsoleLogger& consoleLogger;
		static FileLogger& fileLogger;
		static const Vector<DBFileCommand*> dbCommands;
		static const Vector<DBFileCommandParameters*> dbCommandsParameters;
		static const Vector<BaseAggregateCommand*> aggregateCommands;
};
 
#endif