#include "DCPConfig.h"
#include "../commands/ExportCommand.h"
#include "../commands/PrintCommand.h"
#include "../commands/DescribeCommand.h"
#include "../commands/ShowTablesCommand.h"
#include "../commands/ImportCommand.h"
#include "../commands/AddColumnCommand.h"

const String DCPConfig::defaultFilesLocation = "C:\\Users\\zotak\\Desktop\\project\\";

const char DCPConfig::commandDelimiter = ' ';

const char DCPConfig::fileDelimiter = ',';

#ifdef _WIN32
const String DCPConfig::newLineSymbol = "\r\n";
#else
const String DCPConfig::newLineSymbol = "\r\n";
#endif

const char DCPConfig::columnConfigDelimiter = '-';

const String DCPConfig::tableFileExtension = ".csv";

const String DCPConfig::dbFileExtension = ".csv";

const String DCPConfig::nullValue = "NULL";

const Vector<String> DCPConfig::allowedDataTypes{ "INT", "STRING", "DOUBLE" };

const Vector<String> DCPConfig::fileExtensions{ DCPConfig::tableFileExtension }; //In case of different file extensions, add them all.

std::istream& DCPConfig::inputStream = std::cin;

const ILogger& DCPConfig::logger = ConsoleLogger::getInstance();

const Vector<DBFileCommand*> DCPConfig::dbCommands{
	new ShowTablesCommand()
};

const Vector<DBFileCommandParameters*> DCPConfig::dbCommandsParameters{
	new ExportCommand(),
	new PrintCommand(),
	new DescribeCommand(),
	new ImportCommand(),
	new AddColumnCommand()
};