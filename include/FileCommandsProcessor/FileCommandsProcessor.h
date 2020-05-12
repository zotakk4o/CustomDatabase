#ifndef FILECOMMANDSPROCESSOR_H
#define FILECOMMANDSPROCESSOR_H

#include "../../include/String.h"
#include "../../include/File.h"

class FileCommandsProcessor {
	private:
		bool areExtensionsValid(const Vector<String>&);
	protected:
		virtual Vector<String> getAllowedExtensions() = 0;
		bool parseFileCommand(const String&, File&);
};

#endif
