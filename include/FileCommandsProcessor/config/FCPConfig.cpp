#include "FCPConfig.h"

#include "../commands/CloseCommand.h"
#include "../commands/ExitCommand.h"
#include "../commands/HelpCommand.h"
#include "../commands/OpenCommand.h"
#include "../commands/SaveAsCommand.h"
#include "../commands/SaveCommand.h"
#include "../commands/interfaces/ICommand.h"
#include "../commands/interfaces/IFileCommand.h"
#include "../commands/interfaces/IFileCommandParameters.h"
#include "../../Loggers/ConsoleLogger.h"

const char FCPConfig::commandDelimiter = ' ';

const ILogger& FCPConfig::logger = ConsoleLogger::getInstance();

const Vector<ICommand*> FCPConfig::commands{
	new HelpCommand(),
	new ExitCommand()
};

const Vector<IFileCommand*> FCPConfig::fileCommands{
	new CloseCommand{},
	new SaveCommand{},
};

const Vector<IFileCommandParameters*> FCPConfig::fileCommandsParameters{
	new SaveAsCommand{},
	new OpenCommand{}
};