#include "FileLogger.h"
#include <fstream>
#include <stdexcept>

FileLogger::~FileLogger() {}

FileLogger::FileLogger(const String& _filePath) : filePath(_filePath){
	this->file.open(_filePath.getConstChar(), std::fstream::out | std::fstream::app);
	if (!this->file.is_open()) {
		throw std::invalid_argument((String{ "Could not create a file logger for " } +_filePath + ", could not open the log file.").getConstChar());
	}
	this->file.close();
}

void FileLogger::log(const String& data, bool withNewLine) {
	this->file.open(this->filePath.getConstChar(), std::fstream::out | std::fstream::app);

	if (!this->file.is_open()) {
		throw std::invalid_argument((String{ "Could not open" } + this->filePath).getConstChar());
	}

	String res = withNewLine? data + '\n' : data;
	this->file.write(res.getConstChar(), res.getLength());
	this->file.close();
}