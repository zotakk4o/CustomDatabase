#include "FCPConfig.h"

#include "../commands/CloseCommand.h"
#include "../commands/ExitCommand.h"
#include "../commands/HelpCommand.h"
#include "../commands/OpenCommand.h"
#include "../commands/SaveAsCommand.h"
#include "../commands/SaveCommand.h"

#include "../../Loggers/ConsoleLogger.h"

const char FCPConfig::commandDelimiter = ' ';

const ILogger& FCPConfig::logger = ConsoleLogger::getInstance();

const Vector<Command*> FCPConfig::commands{
	new HelpCommand(),
	new ExitCommand()
};

const Vector<FileCommand*> FCPConfig::fileCommands{
	new CloseCommand{},
	new SaveCommand{},
};

const Vector<FileCommandParameters*> FCPConfig::fileCommandsParameters{
	new SaveAsCommand{},
	new OpenCommand{}
};