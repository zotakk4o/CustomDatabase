#include "DBFile.h"
#include "../config/DCPErrors.h"
#include "../config/DCPConfig.h"

#include<iostream>

DBFile::DBFile(const ILogger* _logger, const String& _path) : File(_logger, _path) {};

DBFile::DBFile(const DBFile& other) : File(other), tableFiles(other.tableFiles) {};

bool DBFile::open(const String& fileName) {

	if (!this->File::open(fileName)) {
		return false;
	}

	if (!this->data.getLength()) {
		return true;
	}

	Vector<String> tableRows = this->data.split(DCPConfig::newLineSymbol);

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

void DBFile::showTables() {
	for (unsigned int i = 0; i < this->tableFiles.getSize(); i++)
	{
		this->logger->log(String{ (i + 1) + "0" } +". " + this->tableFiles[i].getTableName());
	}
}

void DBFile::importTable(const String& fileName) {
	try
	{
		this->getTableWithName(DBFile::getFileName(fileName, false));
	}
	catch (const String&)
	{
		String tableName = DBFile::getFileName(fileName, false);
		String newPath = DCPConfig::defaultFilesLocation + tableName + DCPConfig::tableFileExtension;
		TableFile newTable{ this->logger, tableName, fileName, true };
		
		this->tableFiles.pushBack(TableFile{this->logger, tableName, newPath});

		newTable.saveAs(newPath);
	
		this->data += newTable.getTableName() + DCPConfig::fileDelimiter + newPath + '\n';

		this->save();
		return;
	}

	throw DCPErrors::tableAlreadyExistsError;
}

void DBFile::exportTable(const String& tableName, const String& fileName) {
	this->getTableWithName(tableName).exportData(fileName);
}

void DBFile::describeTable(const String& tableName) {
	this->getTableWithName(tableName).describe();
}

void DBFile::printTable(const String& tableName) {
	this->getTableWithName(tableName).print();
}

void DBFile::renameTable(const String& tableName, const String& newName) {
	this->getTableWithName(tableName).rename(newName);
}

TableFile& DBFile::getTableWithName(const String& tableName) {
	for (unsigned int i = 0; i < this->tableFiles.getSize(); i++)
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