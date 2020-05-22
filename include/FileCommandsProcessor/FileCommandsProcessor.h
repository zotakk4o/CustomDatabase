#ifndef FILECOMMANDSPROCESSOR_H
#define FILECOMMANDSPROCESSOR_H

#include "include/String.h"
#include "include/File.h"

class FileCommandsProcessor {
	protected:
		bool areExtensionsValid(const Vector<String>&);
		virtual Vector<String> getAllowedExtensions() = 0;
		bool parseFileCommand(const String&, File&);
	public:
		virtual ~FileCommandsProcessor();
};

#endif
