#ifndef FILELOGGER_H
#define FILELOGGER_H

#include "interfaces/ILogger.h"
#include <fstream>

class FileLogger : public ILogger {
	private:
		const String filePath;
		std::fstream file;
	public:
		virtual ~FileLogger();
		FileLogger(const String&);
		FileLogger(const FileLogger&) = delete;
		FileLogger& operator=(const FileLogger&) = delete;
	
		virtual void log(const String& data, bool withNewLine = true);
};

#endif
