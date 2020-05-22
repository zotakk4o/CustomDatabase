#include "FileLogger.h"
#include <fstream>
#include <stdexcept>

FileLogger::~FileLogger() {
	this->file.close();
}

FileLogger::FileLogger(const String& filePath) {
	this->file.open(filePath.getConstChar(), std::fstream::out | std::fstream::app);
	if (!this->file.is_open()) {
		throw std::invalid_argument((String{ "Could not create a file logger for " } + filePath + ", could not open the log file.").getConstChar());
	}
}

void FileLogger::log(const String& data, bool withNewLine) {
	String res = withNewLine? data + '\n' : data;
	this->file.write(res.getConstChar(), res.getLength());
}