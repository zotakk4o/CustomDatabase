#ifndef DBCOMMANDSPROCESSOR_H
#define DBCOMMANDSPROCESSOR_H

#include "FilesHandlers/DBFile.h"
#include "include/String.h"
#include "include/FileCommandsProcessor/FileCommandsProcessor.h"

class DBCommandsProcessor : private FileCommandsProcessor {
	protected:
		virtual Vector<String> getAllowedExtensions();
		void parseCommands();
		bool parseDBCommand(const String&, DBFile&);
	public:
		void start();
};

#endif 
