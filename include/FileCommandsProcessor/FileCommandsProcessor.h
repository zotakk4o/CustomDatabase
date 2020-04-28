#ifndef FILECOMMANDSPROCESSOR_H
#define FILECOMMANDSPROCESSOR_H

#include "../../include/String.h"
#include "../../include/File.h"

template<typename T>
class FileCommandsProcessor {
	private:
		static void parseFileCommand(const String&, File&);
	protected:
		static void parseInput();
};

#endif
