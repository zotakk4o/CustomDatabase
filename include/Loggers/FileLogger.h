#ifndef FILELOGGER_H
#define FILELOGGER_H

#include "interfaces/ILogger.h"
#include <fstream>

class FileLogger : public ILogger {
	private:
		std::fstream file;
		FileLogger(const String&);
	public:
		virtual ~FileLogger();
		FileLogger(const FileLogger&) = delete;
		FileLogger& operator=(const FileLogger&) = delete;
	
		static FileLogger& getInstance(const String& = "");
		virtual void log(const String& data, bool withNewLine = true);
};

#endif
