#include "src/DBCommandsProcessor.h"
#include "src/config/DCPConfig.h"
#include "include/Loggers/FileLogger.h"

int main() {
	DBCommandsProcessor processor;
	processor.start();

	return 0;
}