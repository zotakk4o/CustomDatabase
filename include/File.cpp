#include<iostream>
#include<new>
#include "File.h"

#define NO_FREE_MEM_ERR "Error: No free memory!"

bool File::open(const String& filename) {
	std::fstream fs;
	fs.open(filename.getConstChar(), std::fstream::in | std::fstream::ate);

	if (!fs.is_open()) {
		fs.open(filename.getConstChar(), std::fstream::out);

		if (fs.is_open()) {
			std::cout << "Successfully opened \"" << filename << "\"." << std::endl;
			fs.close();
			this->opened = true;
			return true;
		}

		std::cout << "\"" << filename << "\" could not be opened due to an error." << std::endl;
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

	std::cout << "Successfully opened \"" << filename << "\"." << std::endl;

	return true;
}


bool File::save() noexcept {
	return this->saveData(this->name);
}

bool File::saveAs(const String& filename) {
	return this->saveData(filename);
}

bool File::saveData(const String& filename) {
	std::fstream fs;
	fs.open(filename.getConstChar(), std::fstream::out | std::fstream::trunc);

	if (!fs.is_open()) {
		std::cout << "Data could not be saved in \"" << filename << "\"." << std::endl;
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

	std::cout << "Successfully saved \"" << filename << "\"." << std::endl;
	
	return true;
}

void File::close() {
	this->data = "";
	this->name = "";
	this->opened = false;
}

void File::setData(const String& newData) {
	this->data = newData;
}

String File::getData() const {
	return this->data;
}

String File::getName() const {
	return this->name;
}

bool File::isOpened() const {
	return this->opened;
}