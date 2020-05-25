#include "DCPConfig.h"
#include "../commands/ExportCommand.h"
#include "../commands/PrintCommand.h"
#include "../commands/DescribeCommand.h"
#include "../commands/ShowTablesCommand.h"
#include "../commands/ImportCommand.h"
#include "../commands/AddColumnCommand.h"
#include "../commands/SelectCommand.h"
#include "../commands/UpdateCommand.h"
#include "../commands/RenameCommand.h"
#include "../commands/CountCommand.h"
#include "../commands/InsertCommand.h"
#include "../commands/DeleteCommand.h"
#include "../commands/InnerJoinCommand.h"
#include "../commands/AggregateCommand.h"
#include "../commands/aggregate/MaximumCommand.h"
#include "../commands/aggregate/MinimumCommand.h"
#include "../commands/aggregate/ProductCommand.h"
#include "../commands/aggregate/SumCommand.h"

const String DCPConfig::defaultFilesLocation = "db-files\\";

const char DCPConfig::commandDelimiter = ' ';

const char DCPConfig::fileDelimiter = ',';

const char DCPConfig::columnConfigDelimiter = '-';

const unsigned short DCPConfig::perPageEntries = 5;

const String DCPConfig::tableFileExtension = ".csv";

const String DCPConfig::dbFileExtension = ".csv";

const String DCPConfig::nullValue = "NULL";

const String DCPConfig::doubleType = "DOUBLE";
const String DCPConfig::stringType = "STRING";
const String DCPConfig::intType = "INT";

const Vector<String> DCPConfig::allowedDataTypes{ doubleType, intType, stringType };

const Vector<String> DCPConfig::fileExtensions{ DCPConfig::tableFileExtension }; //In case of different file extensions, add them all.

std::istream& DCPConfig::inputStream = std::cin;

ConsoleLogger& DCPConfig::consoleLogger = ConsoleLogger::getInstance();
FileLogger DCPConfig::fileLogger{"src/logs/debug_file_commands.log"};

const Vector<DBFileCommand*> DCPConfig::dbCommands{
	new ShowTablesCommand()
};

const Vector<DBFileCommandParameters*> DCPConfig::dbCommandsParameters{
	new ExportCommand(),
	new PrintCommand(),
	new DescribeCommand(),
	new ImportCommand(),
	new AddColumnCommand(),
	new SelectCommand(),
	new UpdateCommand(),
	new RenameCommand(),
	new CountCommand(),
	new InsertCommand(),
	new DeleteCommand(),
	new InnerJoinCommand(),
	new AggregateCommand()
};

const Vector<BaseAggregateCommand*> DCPConfig::aggregateCommands{
	new SumCommand(),
	new ProductCommand(),
	new MaximumCommand(),
	new MinimumCommand()
};

DCPConfig::~DCPConfig() {
	unsigned int dbCommandsSize = DCPConfig::dbCommands.getSize();
	for (unsigned int i = 0; i < dbCommandsSize; i++)
	{
		delete DCPConfig::dbCommands[i];
	}

	unsigned int dbCommandsParametersSize = DCPConfig::dbCommandsParameters.getSize();
	for (unsigned int i = 0; i < dbCommandsParametersSize; i++)
	{
		delete DCPConfig::dbCommandsParameters[i];
	}

	unsigned int aggregateCommandsSize = DCPConfig::aggregateCommands.getSize();
	for (unsigned int i = 0; i < aggregateCommandsSize; i++)
	{
		delete DCPConfig::aggregateCommands[i];
	}
}