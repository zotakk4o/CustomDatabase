#ifndef FCPCONFIG_H
#define FCPCONFIG_H

#include "../../Vector.h"
#include "../commands/interfaces/ICommand.h"
#include "../commands/interfaces/IFileCommand.h"
#include "../commands/interfaces/IFileCommandParameters.h"
#include "../../Loggers/interfaces/ILogger.h"

class FCPConfig {
	public:
		static const char commandDelimiter;
		static const ILogger& logger;
		static const Vector<ICommand*> commands;
		static const Vector<IFileCommand*> fileCommands;
		static const Vector<IFileCommandParameters*>fileCommandsParameters;
};

#endif
