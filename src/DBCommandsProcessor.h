#ifndef DBCOMMANDSPROCESSOR_H
#define DBCOMMANDSPROCESSOR_H

#include "../include/File.h"
#include "../include/String.h"
#include "../include/FileCommandsProcessor/FileCommandsProcessor.h"

class DBCommandsProcessor : private FileCommandsProcessor<DBCommandsProcessor>{
	public:
		static void parseCommands(const String&, const File&);
		static void start();
};

#endif 
