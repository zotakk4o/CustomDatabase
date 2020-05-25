#include "FCPConfig.h"

#include "../commands/CloseCommand.h"
#include "../commands/ExitCommand.h"
#include "../commands/HelpCommand.h"
#include "../commands/OpenCommand.h"
#include "../commands/SaveAsCommand.h"
#include "../commands/SaveCommand.h"

#include "include/Loggers/ConsoleLogger.h"

const char FCPConfig::commandDelimiter = ' ';

ConsoleLogger& FCPConfig::consoleLogger = ConsoleLogger::getInstance();

const Vector<Command*> FCPConfig::commands{
	new HelpCommand(),
	new ExitCommand()
};

const Vector<FileCommand*> FCPConfig::fileCommands{
	new CloseCommand(),
	new SaveCommand(),
};

const Vector<FileCommandParameters*> FCPConfig::fileCommandsParameters{
	new SaveAsCommand(),
	new OpenCommand()
};

FCPConfig::~FCPConfig() {
	unsigned int commandsSize = FCPConfig::commands.getSize();
	for (unsigned int i = 0; i < commandsSize; i++)
	{
		delete FCPConfig::commands[i];
	}

	unsigned int fileCommandsSize = FCPConfig::fileCommands.getSize();
	for (unsigned int i = 0; i < fileCommandsSize; i++)
	{
		delete FCPConfig::fileCommands[i];
	}

	unsigned int fileCommandsParametersSize = FCPConfig::fileCommandsParameters.getSize();
	for (unsigned int i = 0; i < fileCommandsParametersSize; i++)
	{
		delete FCPConfig::fileCommandsParameters[i];
	}
}