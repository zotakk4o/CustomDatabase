#include<iostream>
#include<new>
#include "File.h"

#define NO_FREE_MEM_ERR "Error: No free memory!"

File::~File() {};

File::File(const ILogger* _logger, const String& path) : logger(_logger), data(""), path(path), opened(false) {};

File::File(const File& other) : logger(other.logger), data(other.data), path(other.path), opened(other.opened) {};

bool File::open(const String& fileName) {
	if (this->opened) {
		return false;
	}

	std::fstream fs;
	fs.open(fileName.getConstChar(), std::fstream::in | std::fstream::ate);

	if (!fs.is_open()) {
		fs.open(fileName.getConstChar(), std::fstream::out);

		if (fs.is_open()) {
			this->logger->log(String{ "Successfully opened \"" } + fileName + "\".");
			fs.close();
			this->opened = true;
			return true;
		}

		this->logger->log(String{ "\"" } +fileName + "\" could not be opened due to an error.");
		return false;
	}

	unsigned int length = fs.tellg();
	fs.seekg(0, std::fstream::beg);

	char* res = new (std::nothrow) char[length + 1];

	if (res == nullptr) {
		fs.close();
		throw NO_FREE_MEM_ERR;
	}

	fs.read(res, length);

	if (fs.fail() || fs.bad()) {
		delete[] res;
		fs.close();
		return false;
	}

	res[length] = '\0';
	this->data = res;
	delete[] res;

	fs.close();
	this->opened = true;

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
	this->opened = false;

	this->logger->log(String{ "Successfully saved \"" } +filename + "\".");
	
	return true;
}

bool File::close() {
	if (!this->opened) {
		return false;
	}

	this->data = "";
	this->path = "";
	this->opened = false;

	return true;
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