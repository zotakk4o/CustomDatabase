#include "DBFile.h"
#include "../config/DCPErrors.h"
#include "../config/DCPConfig.h"
#include "../config/DCPMessages.h"

#include<iostream>

DBFile::DBFile(ILogger* _logger, const String& _path) : File(_logger, _path) {};

DBFile::DBFile(const DBFile& other) : File(other), tableFiles(other.tableFiles) {};

bool DBFile::open(const String& fileName) {

	if (!this->File::open(fileName)) {
		return false;
	}

	if (!this->data.getLength()) {
		return true;
	}

	Vector<String> tableRows = this->data.split('\n');
	unsigned int tableRowsSize = tableRows.getSize();
	for (unsigned int i = 0; i < tableRowsSize; i++)
	{
		Vector<String> rowData = tableRows[i].split(DCPConfig::fileDelimiter);

		if (rowData.getSize() != 2) {
			throw DCPErrors::incorrectTableFormatError; 
		}

		this->tableFiles.pushBack(TableFile{this->logger, rowData[0], rowData[1]});
	}

	return true;
}

bool DBFile::saveData(const String& fileName) {
	if (!this->File::saveData(fileName)) {
		return false;
	}

	unsigned int filesSize = this->tableFiles.getSize();
	for (unsigned int i = 0; i < filesSize; i++)
	{
		if (this->tableFiles[i].isOpened()) {
			if (!this->tableFiles[i].save()) {
				return false;
			}
		}
	}

	return true;
}

bool DBFile::close() {
	if (!this->File::close()) {
		return false;
	}

	unsigned int filesSize = this->tableFiles.getSize();
	for (unsigned int i = 0; i < filesSize; i++)
	{
		if (this->tableFiles[i].isOpened()) {
			if (!this->tableFiles[i].close()) {
				return false;
			}
		}
	}

	return true;
}

void DBFile::addColumnToTable(const Vector<String>& parameters) {
	this->getTableWithName(parameters[0]).addColumn(parameters[1], parameters[2]);
}

Vector<String> DBFile::selectFromTable(const Vector<String>& parameters) {
	return this->getTableWithName(parameters[2]).select(parameters[0], parameters[1]);
}

void DBFile::updateTableEntry(const Vector<String>& parameters) {
	this->getTableWithName(parameters[0]).update(parameters.slice(1, parameters.getSize() - 1));
}

void DBFile::showTables() {
	unsigned int filesSize = this->tableFiles.getSize();
	for (unsigned int i = 0; i < filesSize; i++)
	{
		this->logger->log(String::toString(i + 1) + ". " + this->tableFiles[i].getTableName());
	}
}

void DBFile::countRowsFromTable(const Vector<String>& parameters) {
	this->getTableWithName(parameters[0]).count(parameters[1], parameters[2]);
}

void DBFile::importTable(const String& fileName) {

	if (this->doesTableExist(DBFile::getFileName(fileName, false))) {
		throw DCPErrors::tableAlreadyExistsError;
	}

	String tableName = DBFile::getFileName(fileName, false);
	String newPath = DCPConfig::defaultFilesLocation + tableName + DCPConfig::tableFileExtension;
	TableFile newTable{ this->logger, tableName, fileName, true };

	this->tableFiles.pushBack(TableFile{ this->logger, tableName, newPath, true });
	this->addTableToData(newTable);
}

void DBFile::exportTable(const String& tableName, const String& fileName) {
	this->getTableWithName(tableName).exportData(fileName);
}

void DBFile::describeTable(const String& tableName) {
	this->getTableWithName(tableName).describe();
}

void DBFile::innerJoinTables(const Vector<String>& parameters) {
	if (this->doesTableExist(parameters[0] + DCPConfig::columnConfigDelimiter + parameters[2])
		|| this->doesTableExist(parameters[2] + DCPConfig::columnConfigDelimiter + parameters[0])) 
	{
		throw DCPErrors::tableAlreadyExistsError;
	}

	TableFile& first = this->getTableWithName(parameters[0]);
	TableFile& second = this->getTableWithName(parameters[2]);

	TableFile newTable = TableFile::innerJoin(first, second, parameters[1], parameters[3]);
	this->tableFiles.pushBack(newTable);
	this->addTableToData(newTable);
	this->logger->log(DCPMessages::innerJoinSuccessMessage + newTable.getTableName());
}

void DBFile::deleteFromTable(const Vector<String>& parameters) {
	this->getTableWithName(parameters[0]).deleteRows(parameters[1], parameters[2]);
}

void DBFile::printTable(const String& tableName) {
	this->getTableWithName(tableName).print();
}

void DBFile::insertRow(const Vector<String>& parameters) {
	this->getTableWithName(parameters[0]).insert(parameters.slice(1, parameters.getSize() - 1));
}

void DBFile::aggregate(const Vector<String>& parameters) {
	this->getTableWithName(parameters[0]).aggregate(parameters.slice(1, parameters.getSize() - 1));
}

void DBFile::renameTable(const String& tableName, const String& newName) {
	if (this->doesTableExist(newName)) {
		throw DCPErrors::tableAlreadyExistsError;
	}

	this->data = "";
	unsigned int filesSize = this->tableFiles.getSize();
	for (unsigned int i = 0; i < filesSize; i++)
	{
		if (this->tableFiles[i].getTableName() == tableName) {
			this->tableFiles[i].rename(newName);
			this->data += newName;
		}
		else {
			this->data += tableName;
		}

		this->data = this->data + DCPConfig::fileDelimiter + this->tableFiles[i].getPath() + '\n';
	}
}

TableFile& DBFile::getTableWithName(const String& tableName) {
	unsigned int filesSize = this->tableFiles.getSize();
	for (unsigned int i = 0; i < filesSize; i++)
	{
		if (this->tableFiles[i].getTableName() == tableName) {
			if (!this->tableFiles[i].isOpened()) {
				this->tableFiles[i].open();
			}
			return this->tableFiles[i];
		}
	}

	throw DCPErrors::tableNotFoundError;
}

bool DBFile::doesTableExist(const String& tableName) const {
	unsigned int filesSize = this->tableFiles.getSize();
	for (unsigned int i = 0; i < filesSize; i++)
	{
		if (this->tableFiles[i].getTableName() == tableName) {
			return true;
		}
	}

	return false;
}

void DBFile::addTableToData(const TableFile& table) {
	this->data += table.getTableName() + DCPConfig::fileDelimiter + table.getPath() + '\n';
}

