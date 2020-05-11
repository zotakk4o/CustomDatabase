#include "DCPConfig.h"

const char DCPConfig::commandDelimiter = ' ';

const char DCPConfig::fileDelimiter = ',';

std::istream& DCPConfig::inputStream = std::cin;

const ILogger& DCPConfig::logger = ConsoleLogger::getInstance();

const Vector<IDBFileCommand*> DCPConfig::dbCommands;

const Vector<IDBFileCommandParameters*> DCPConfig::dbCommandsParameters;
