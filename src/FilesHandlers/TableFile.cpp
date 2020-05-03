#include "TableFile.h"

TableFile::TableFile(const String& name, const String& path) : File(path) {
	if (name.getLength() == 0) {
		throw;//TODO
	}

	this->tableName = name;
}

TableFile::TableFile(const File& other) : File(other) {}

void TableFile::describe() const {

}

void TableFile::print() const {

}

void TableFile::exportData(const String& fileName) const {

}

void TableFile::rename(const String& newName) {
	if (newName.getLength()) {
		this->tableName = newName;
	}
}

void TableFile::setTableName(const String& name) {
	if (name.getLength()) {
		this->tableName = name;
	}
}

String TableFile::getTableName() const {
	return this->tableName;
}