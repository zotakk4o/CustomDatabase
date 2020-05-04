#ifndef FCP_CONFIG_CPP
#define FCP_CONFIG_CPP

#include "../../String.h"
#include "../../Vector.cpp"

#include "../commands/CloseCommand.h"
#include "../commands/ExitCommand.h"
#include "../commands/HelpCommand.h"
#include "../commands/OpenCommand.h"
#include "../commands/SaveAsCommand.h"
#include "../commands/SaveCommand.h"
#include "../commands/interfaces/ICommand.h"
#include "../commands/interfaces/IFileCommand.h"
#include "../commands/interfaces/IFileCommandParameters.h"

namespace FCPConfig {
	const char commandDelimiter = ' ';

	const Vector<ICommand*> commands{
		new HelpCommand(),
		new ExitCommand()
	};

	const Vector<IFileCommand*> fileCommands{
		new CloseCommand{},
		new SaveCommand{},
	};

	const Vector<IFileCommandParameters*> fileCommandsParameters{
		new SaveAsCommand{},
		new OpenCommand{}
	};
};

#endif