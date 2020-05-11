#include "TableFile.h"

TableFile::TableFile(const ILogger* _logger, const String& name, const String& path) : File(_logger, path), tableName(name) {};

TableFile::TableFile(const TableFile& other) : File(other), tableName(other.tableName) {};

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