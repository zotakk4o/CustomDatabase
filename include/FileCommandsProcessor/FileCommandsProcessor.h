#ifndef FILECOMMANDSPROCESSOR_H
#define FILECOMMANDSPROCESSOR_H

#include "../../include/String.h"
#include "../../include/File.h"

class FileCommandsProcessor {
	protected:
		static void parseFileCommand(const String&, File&);
};

#endif
