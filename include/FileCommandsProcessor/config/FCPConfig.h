#ifndef FCPCONFIG_H
#define FCPCONFIG_H

#include "../../Vector.h"
#include "../commands/BaseClasses/Command.h"
#include "../commands/BaseClasses/FileCommand.h"
#include "../commands/BaseClasses/FileCommandParameters.h"
#include "../../Loggers/interfaces/ILogger.h"

class FCPConfig {
	public:
		static const char commandDelimiter;
		static const ILogger& logger;
		static const Vector<Command*> commands;
		static const Vector<FileCommand*> fileCommands;
		static const Vector<FileCommandParameters*>fileCommandsParameters;
};

#endif
