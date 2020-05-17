#include "DBFile.h"
#include "../config/DCPErrors.h"
#include "../config/DCPConfig.h"

#include<iostream>

DBFile::DBFile(const ILogger* _logger, const String& _path) : File(_logger, _path) {
	if (_path.getLength()) {
		this->open(_path);
	}
};
DBFile::DBFile(const DBFile& other) : File(other), tableFiles(tableFiles) {};

bool DBFile::open(const String& fileName) {

	if (!this->File::open(fileName)) {
		return false;
	}

	if (!this->data.getLength()) {
		return true;
	}

	Vector<String> tableRows = this->data.split('\n');

	for (unsigned int i = 0; i < tableRows.getSize(); i++)
	{
		Vector<String> rowData = tableRows[i].split(DCPConfig::fileDelimiter);

		if (rowData.getSize() != 2) {
			throw DCPErrors::incorrectTableFormatError;
		}

		this->tableFiles.pushBack(TableFile{this->logger, rowData[0], rowData[1]});
	}

	return true;
}

void DBFile::addColumnToTable(const Vector<String>& parameters) {
	this->getTableWithName(parameters[0]).addColumn(parameters[1], parameters[2]);
}

void DBFile::showTables() const {
	for (unsigned int i = 0; i < this->tableFiles.getSize(); i++)
	{
		this->logger->log(String{ (i + 1) + "0" } +". " + this->tableFiles[i].getTableName());
	}
}

void DBFile::importTable(const String& fileName) {
	try
	{
		this->getTableWithName(fileName);
	}
	catch (const String&)
	{
		TableFile newTable{ this->logger, fileName, fileName };
		this->tableFiles.pushBack(newTable);
		newTable.saveAs(DCPConfig::defaultFilesLocation + "test.csv");
		return;
	}

	throw DCPErrors::tableAlreadyExistsError;
}

void DBFile::exportTable(const String& tableName, const String& fileName) const {
	this->getTableWithName(tableName).exportData(fileName);
}

void DBFile::describeTable(const String& tableName) const {
	this->getTableWithName(tableName).describe();
}

void DBFile::printTable(const String& tableName) const {
	this->getTableWithName(tableName).print();
}

void DBFile::renameTable(const String& tableName, const String& newName) {
	this->getTableWithName(tableName).rename(newName);
}

TableFile& DBFile::getTableWithName(const String& tableName) {
	return const_cast<TableFile&>(static_cast<const DBFile&>(*this).getTableWithName(tableName));
}

const TableFile& DBFile::getTableWithName(const String& tableName) const {
	for (unsigned int i = 0; i < this->tableFiles.getSize(); i++)
	{
		if (tableFiles[i].getTableName() == tableName) {
			return tableFiles[i];
		}
	}

	throw DCPErrors::tableNotFoundError;
}