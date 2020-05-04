#ifndef DBCOMMANDSPROCESSOR_H
#define DBCOMMANDSPROCESSOR_H

#include "FilesHandlers/DBFile.h"
#include "../include/String.h"
#include "../include/FileCommandsProcessor/FileCommandsProcessor.h"

class DBCommandsProcessor : private FileCommandsProcessor {
	private:
		static void parseCommands();
		static void parseDBCommand(const String&, DBFile&);
	public:
		static void start();
};

#endif 
