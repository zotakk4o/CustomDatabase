#include "TableFile.h"
#include "../config/DCPConfig.h"
#include "../config/DCPMessages.h"
#include "../config/DCPErrors.h"

TableFile::TableFile(const ILogger* _logger, const String& _name, const String& _path) : File(_logger, _path), tableName(_name) {
	if (_path.getLength()) {
		this->open(_path);
	}
};

TableFile::TableFile(const TableFile& other) : File(other), tableName(other.tableName) {};

bool TableFile::open(const String& fileName) {
	if (!this->File::open(fileName)) {
		return false;
	}

	if (!this->data.getLength()) {
		return true;
	}

	Vector<String> tableRows = this->data.split('\n');
	Vector<String> rowData = tableRows[0].split(',');

	for (unsigned int j = 0; j < rowData.getSize(); j++)
	{
		Vector<String> columnData = rowData[j].split(DCPConfig::columnConfigDelimiter);
		if (columnData.getSize() != 2 || columnData[0].getLength() == 0 || DCPConfig::allowedDataTypes.indexOf(columnData[1]) == -1) {
			throw DCPErrors::incorrectTableDataFormatError;
		}
	}

	return true;
}

void TableFile::addColumn(const String& columnName, const String& columnType) {
	Vector<String> lines = this->data.split('\n');
	lines[0] = lines[0] + DCPConfig::fileDelimiter + columnName + DCPConfig::columnConfigDelimiter + columnType;

	for (unsigned int i = 1; i < lines.getSize(); i++)
	{
		lines[i] = lines[i] + DCPConfig::fileDelimiter + DCPConfig::nullValue;
	}

	this->data = String::join(lines, '\n');
}

void TableFile::describe() const {

}

void TableFile::print() const {

}

void TableFile::exportData(const String& fileName) const {
	this->saveAs(fileName);
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