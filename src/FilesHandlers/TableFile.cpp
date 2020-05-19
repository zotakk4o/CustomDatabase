#include "TableFile.h"
#include "../config/DCPConfig.h"
#include "../config/DCPMessages.h"
#include "../config/DCPErrors.h"
#include "../../include/Pagination/Pagination.h"

TableFile::TableFile(const ILogger* _logger, const String& _name, const String& _path, bool openOnCreation) : File(_logger, _path), tableName(_name) {
	if (openOnCreation) {
		this->open(_path);
	}
};

TableFile::TableFile(const TableFile& other) : File(other), tableName(other.tableName) {};

bool TableFile::open(const String& fileName) {
	String filePath = fileName.getLength() == 0 ? this->path : fileName;

	if (!this->File::open(filePath)) {
		return false;
	}

	if (!this->data.getLength()) {
		return true;
	}

	Vector<String> tableRows = this->data.split('\n');
	Vector<String> rowData = tableRows[0].split(DCPConfig::fileDelimiter);

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
	if (this->getColumnNames().indexOf(columnName) != -1) {
		this->logger->log(DCPMessages::columnAlreadyExistsMessage);
		return;
	}

	Vector<String> lines = this->data.split('\n');

	if (lines.getSize() == 0) {
		lines.pushBack(columnName + DCPConfig::columnConfigDelimiter + columnType);
	}
	else {
		lines[0] = lines[0] + DCPConfig::fileDelimiter + columnName + DCPConfig::columnConfigDelimiter + columnType;

		for (unsigned int i = 1; i < lines.getSize(); i++)
		{
			lines[i] = lines[i] + DCPConfig::fileDelimiter + DCPConfig::nullValue;
		}
	}

	this->data = String::join(lines, '\n') + '\n';
}

void TableFile::describe() {
	const Vector<String>& fields = this->getColumnNames(true);
	for (unsigned short i = 0; i < fields.getSize(); i++)
	{
		this->logger->log(fields[i]);
	}
}

void TableFile::print() {
	Vector<String> rows = this->getTableData();

	if (!rows.getSize()) {
		this->logger->log(DCPMessages::emptyTableMessage);
		return;
	}

	Pagination tablesList{*this->logger, rows, DCPConfig::perPageEntries};
}

void TableFile::exportData(const String& fileName) {
	this->saveAs(fileName);
}

void TableFile::rename(const String& newName) {
	if (newName.getLength()) {
		this->tableName = newName;
	}
}

const Vector<String> TableFile::getColumnNames(bool getWithTypes) {
	Vector<String> res;

	if (this->data.getLength() == 0) {
		return res;
	}

	Vector<String> withTypes = this->data.split('\n')[0].split(DCPConfig::fileDelimiter);

	if (getWithTypes) {
		return withTypes;
	}

	for (unsigned short i = 0; i < withTypes.getSize(); i++)
	{
		res.pushBack(withTypes[i].split('-')[0]);
	}

	return res;
}

const Vector<String> TableFile::getTableData() {
	Vector<String> dataOnly = this->data.split('\n');
	return dataOnly.getSize() <= 1 ? Vector<String>{} : dataOnly.slice(1, dataOnly.getSize() - 1);
}

void TableFile::setTableName(const String& name) {
	if (name.getLength()) {
		this->tableName = name;
	}
}

String TableFile::getTableName() const {
	return this->tableName;
}