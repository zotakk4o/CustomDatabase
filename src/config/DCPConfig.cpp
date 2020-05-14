#include "DCPConfig.h"

#include "../commands/ExportCommand.h"
#include "../commands/PrintCommand.h"
#include "../commands/DescribeCommand.h"
#include "../commands/ShowTablesCommand.h"

const char DCPConfig::commandDelimiter = ' ';

const char DCPConfig::fileDelimiter = ',';

std::istream& DCPConfig::inputStream = std::cin;

const ILogger& DCPConfig::logger = ConsoleLogger::getInstance();

const Vector<DBFileCommand*> DCPConfig::dbCommands{
	new ShowTablesCommand()
};

const Vector<DBFileCommandParameters*> DCPConfig::dbCommandsParameters{
	new ExportCommand(),
	new PrintCommand(),
	new DescribeCommand()
};