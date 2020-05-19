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

bool DBFile::saveData(const String& fileName) {
	if (!this->File::saveData(fileName)) {
		return false;
	}

	for (unsigned short i = 0; i < this->tableFiles.getSize(); i++)
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

	for (unsigned short i = 0; i < this->tableFiles.getSize(); i++)
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

void DBFile::selectFromTable(const Vector<String>& parameters) {
	this->getTableWithName(parameters[2]).select(parameters[0], parameters[1]);
}

void DBFile::updateTableEntry(const Vector<String>& parameters) {
	this->getTableWithName(parameters[0]).update(parameters.slice(1, parameters.getSize() - 1));
}

void DBFile::showTables() {
	for (unsigned int i = 0; i < this->tableFiles.getSize(); i++)
	{
		this->logger->log(String::toString(i + 1) + ". " + this->tableFiles[i].getTableName());
	}
}

void DBFile::importTable(const String& fileName) {
	try
	{
		this->getTableWithName(DBFile::getFileName(fileName, false), false);
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
	try {
		this->getTableWithName(newName, false);
		this->logger->log(DCPErrors::tableAlreadyExistsError);
	} catch (const String&) {
		this->data = "";
		for (unsigned int i = 0; i < this->tableFiles.getSize(); i++)
		{
			if (this->tableFiles[i].getTableName() == tableName) {
				this->data += newName;
			}
			else {
				this->data += tableName;
			}

			this->data = this->data + DCPConfig::fileDelimiter + this->tableFiles[i].getPath() + '\n';
		}
	}
}

TableFile& DBFile::getTableWithName(const String& tableName, bool shallOpen) {
	for (unsigned int i = 0; i < this->tableFiles.getSize(); i++)
	{
		if (this->tableFiles[i].getTableName() == tableName) {
			if (shallOpen && !this->tableFiles[i].isOpened()) {
				this->tableFiles[i].open();
			}
			return this->tableFiles[i];
		}
	}

	throw DCPErrors::tableNotFoundError;
}