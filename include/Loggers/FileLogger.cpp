#include "FileLogger.h"
#include <fstream>

FileLogger::~FileLogger() {
	this->file.close();
}

FileLogger::FileLogger(const String& filePath) {
	this->file.open(filePath.getConstChar(), std::fstream::out | std::fstream::app);
}

FileLogger& FileLogger::getInstance(const String& filePath) {
	static FileLogger inst(filePath);
	return inst;
}

void FileLogger::log(const String& data, bool withNewLine) {
	String res = withNewLine? data + '\n' : data;
	this->file.write(res.getConstChar(), res.getLength());
}