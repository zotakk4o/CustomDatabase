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

Vector<unsigned int> TableFile::getRowsIndexesByCriteria(const String& columnName, const String& columnValue, bool notEqualTo) const {
	Vector<String> rows = this->getTableData();
	Vector<unsigned int> res;

	if (!rows.getSize()) {
		this->logger->log(DCPMessages::emptyTableMessage);
		return res;
	}

	int columnIndex = this->getColumnIndex(columnName);

	if (columnIndex == -1) {
		this->logger->log(DCPMessages::noRecordsFoundMessage);
		return res;
	}

	for (unsigned int i = 0; i < rows.getSize(); i++)
	{
		String data = rows[i].split(DCPConfig::fileDelimiter)[columnIndex];
		if (notEqualTo ? data != columnValue : data == columnValue) {
			res.pushBack(i);
		}

	}

	if (!res.getSize()) {
		this->logger->log(DCPMessages::noRecordsFoundMessage);
	}

	return res;
}

void TableFile::select(const String& columnName, const String& columnValue) {
	Vector<unsigned int> rows = this->getRowsIndexesByCriteria(columnName, columnValue);
	
	if (!rows.getSize()) {
		return;
	}

	Vector<String> selected = this->getTableData(rows);

	Pagination tablesList{ *this->logger, selected, DCPConfig::perPageEntries };
}

void TableFile::update(const Vector<String>& parameters) {
	Vector<unsigned int> selected = this->getRowsIndexesByCriteria(parameters[0], parameters[1]);
	
	if (!selected.getSize()) {
		return;
	}

	Vector<String> rows = this->getTableData();

	int targetColumnIndex = this->getColumnIndex(parameters[2]);

	if (targetColumnIndex == -1) {
		this->logger->log(DCPMessages::noRecordsFoundMessage);
		return;
	}

	if (!this->doesMatchColumnType(targetColumnIndex, parameters[3])) {
		this->logger->log(DCPMessages::typeMissmatchMessage);
		throw DCPErrors::updateFailedError;
	}
	

	for (unsigned int i = 0; i < selected.getSize(); i++)
	{
		Vector<String> columns = rows[i].split(DCPConfig::fileDelimiter);
		columns[targetColumnIndex] = parameters[3];
		rows[i] = String::join(columns, DCPConfig::fileDelimiter);
	}

	this->data = String::join(this->getColumnNames(true), DCPConfig::fileDelimiter) 
		+ '\n' 
		+  String::join(rows, '\n')
		+ '\n';
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

void TableFile::count(const String& columnName, const String& columnValue) {
	String match = String::toString(this->getRowsIndexesByCriteria(columnName, columnValue).getSize());
	if (match != '0') {
		this->logger->log(match);
	}
}

void TableFile::insert(const Vector<String>& parameters) {
	Vector<String> cols = this->getColumnNames();
	Vector<String> newRow;

	for (unsigned int i = 0; i < cols.getSize(); i++)
	{
		
		if (i < parameters.getSize()) {
			if (!this->doesMatchColumnType(i, parameters[i])) {
				this->logger->log(DCPMessages::typeMissmatchMessage);
				throw DCPErrors::insertFailedError;
			}

			newRow.pushBack(parameters[i]);
		}
		else {
			newRow.pushBack(DCPConfig::nullValue);
		}
	}

	this->data += String::join(newRow, DCPConfig::fileDelimiter) + '\n';
}

void TableFile::deleteRows(const String& columnName, const String& columnValue) {
	Vector<unsigned int> selected = this->getRowsIndexesByCriteria(columnName, columnValue, true);

	if (!selected.getSize()) {
		return;
	}

	this->data = this->concatData(this->getTableData(selected));

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
	this->setTableName(newName);
}

const Vector<String> TableFile::getColumnNames(bool getWithTypes) const {
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

const Vector<String> TableFile::getTableData(const Vector<unsigned int>& selected) const {
	Vector<String> dataOnly = this->data.split('\n');

	if (dataOnly.getSize() <= 1) {
		return Vector<String>{};
	}

	dataOnly = dataOnly.slice(1, dataOnly.getSize() - 1);

	if (!selected.getSize()) {
		return dataOnly;
	}

	Vector<String> res;

	for (unsigned int i = 0; i < selected.getSize(); i++)
	{
		res.pushBack(dataOnly[selected[i]]);
	}

	return res;
}

void TableFile::setTableName(const String& name) {
	if (!name.getLength()) {
		return;
	}

	this->tableName = name;
}

String TableFile::getColumnType(const unsigned int& index) const {
	return this->getColumnNames(true)[index].split(DCPConfig::columnConfigDelimiter)[1];
}

String TableFile::getTableName() const {
	return this->tableName;
}

int TableFile::getColumnIndex(const String& columnName) const {
	return this->getColumnNames().indexOf(columnName);
}

bool TableFile::doesMatchColumnType(const unsigned int& colIndex, const String& value) const {
	if (value == DCPConfig::nullValue) {
		return true;
	}
	
	String type = this->getColumnType(colIndex);
	int isNumeric = String::isNumeric(value);

	return type == DCPConfig::doubleType && isNumeric == 1
		|| type == DCPConfig::intType && isNumeric == 0
		|| type == DCPConfig::stringType && isNumeric == -1;
	//TODO: separate data types in classes if I have time. SOLID principle is violated rn.
}

String TableFile::concatData(const Vector<String>& data) {
	return String::join(this->getColumnNames(true), DCPConfig::fileDelimiter)
		+ '\n'
		+ String::join(data, '\n')
		+ '\n';
}

TableFile TableFile::innerJoin(const TableFile& first, const TableFile& second, const String& firstColumnName, const String& secondColumnName) {
	String joinedTableName = first.tableName + DCPConfig::columnConfigDelimiter + second.tableName;
	TableFile res{ first.logger, joinedTableName, DCPConfig::defaultFilesLocation + joinedTableName + DCPConfig::tableFileExtension, true };
	int firstTableIndex = first.getColumnIndex(firstColumnName);
	int secondTableIndex = second.getColumnIndex(secondColumnName);

	if (firstTableIndex == -1 || secondTableIndex == -1) {
		return res;
	}

	res.data += String::join(first.getColumnNames(true), DCPConfig::fileDelimiter) + DCPConfig::fileDelimiter;
	Vector<String> secondTableColumns = second.getColumnNames(true);
	unsigned int tableSize = secondTableColumns.getSize();

	//Adding joined table configuration row
	for (unsigned int i = 0; i < tableSize; i++)
	{
		if (i != firstTableIndex) {
			res.data += secondTableColumns[i];

			if (i != tableSize - 1) {
				res.data += DCPConfig::fileDelimiter;
			}
		}
	}

	res.data += '\n';

	//Adding rows
	Vector<String> firstTableData = first.getTableData();
	Vector<String> secondTableData = second.getTableData();
	unsigned int firstTableSize = firstTableData.getSize();
	unsigned int secondTableSize = secondTableData.getSize();
	unsigned int rowSize;

	for (unsigned int i = 0; i < firstTableSize; i++)
	{
		for (unsigned int j = 0; j < secondTableSize; j++)
		{
			Vector<String> secondTableRow = secondTableData[i].split(DCPConfig::fileDelimiter);
			if (firstTableData[i].split(DCPConfig::fileDelimiter)[firstTableIndex] == secondTableRow[secondTableIndex]) {
				res.data += firstTableData[i] + DCPConfig::fileDelimiter;
				rowSize = secondTableRow.getSize();

				for (unsigned int i = 0; i < rowSize; i++)
				{
					if (i != firstTableIndex && i != secondTableIndex) {
						res.data += secondTableRow[i];

						if (i != rowSize - 1) {
							res.data += DCPConfig::fileDelimiter;
						}
					}
				}

				res.data += '\n';
			}
		}
	}

	return res;
}