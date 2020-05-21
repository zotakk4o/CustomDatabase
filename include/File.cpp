#include<iostream>
#include<new>
#include "File.h"

File::~File() {};

File::File(const ILogger* _logger, const String& _path) : logger(_logger), data(""), path(_path), opened(false) {};

File::File(const File& other) : logger(other.logger), data(other.data), path(other.path), opened(other.opened) {};

bool File::open(const String& fileName) {
	if (this->opened) {
		this->logger->log(String{ "Could not open \"" } + fileName + "\". Another file has been opened for processing.");
		return false;
	}

	std::fstream fs;
	fs.open(fileName.getConstChar(), std::fstream::in);
	fs.seekg(0, fs.beg);

	if (!fs.is_open()) {
		fs.open(fileName.getConstChar(), std::fstream::out);

		if (fs.is_open()) {
			this->logger->log(String{ "Successfully opened \"" } +fileName + "\".");
			fs.close();
			this->path = fileName;
			this->opened = true;
			return true;
		}

		this->logger->log(String{ "\"" } +fileName + "\" could not be opened due to an error.");
		return false;
	}

	String line;

	while (String::getLine(fs, line)) {
		this->data += line + '\n';
	}

	fs.close();
	this->opened = true;
	this->path = fileName;

	this->logger->log(String{ "Successfully opened \"" } + fileName + "\".");

	return true;
}


bool File::save() {
	return this->saveData(this->path);
}

bool File::saveAs(const String& filename) {
	return this->saveData(filename);
}

bool File::saveData(const String& filename) {
	if (!this->opened) {
		this->logger->log(String{ "Could not save \"" } +filename + "\". The file has not been opened for processing.");
		return false;
	}

	std::fstream fs;
	fs.open(filename.getConstChar(), std::fstream::out | std::fstream::trunc);

	if (!fs.is_open()) {
		this->logger->log(String{ "Data could not be saved in \"" } + filename + "\".");
		fs.close();
		return false;
	}

	fs.write(this->data.getConstChar(), this->data.getLength());
	if (!fs.good()) {
		fs.close();
		return false;
	}

	fs.close();

	this->logger->log(String{ "Successfully saved \"" } +filename + "\".");
	
	return true;
}

bool File::close() {
	if (!this->opened) {
		this->logger->log("No file has been opened for processing.");
		return false;
	}

	this->logger->log(String{ "Successfully closed \"" } + this->path + "\"");

	this->data = "";
	this->path = "";
	this->opened = false;

	return true;
}

String File::getFileName(const String& path, bool withExtension) {
	char dirSeparator = '/';

	#ifdef _WIN32
		dirSeparator = '\\';
	#endif

	String reversedPath = path.reverse();

	unsigned short lastSeparatorIndex = path.getLength() - reversedPath.indexOf(dirSeparator);
	unsigned short extensionIndex = path.getLength() - reversedPath.indexOf('.') - 1;

	if (lastSeparatorIndex > path.getLength()) {
		lastSeparatorIndex = 0;
	}

	if (!withExtension) {
		return path.substring(lastSeparatorIndex, extensionIndex - lastSeparatorIndex);
	}

	return path.substring(lastSeparatorIndex, path.getLength() - lastSeparatorIndex);
}

void File::setData(const String& newData) {
	this->data = newData;
}

String File::getData() const {
	return this->data;
}

String File::getPath() const {
	return this->path;
}

bool File::isOpened() const {
	return this->opened;
}