#include<iostream>
#include "DBFile.h"

DBFile::DBFile(const ILogger* _logger, const String& path) : File(_logger, path) {};
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
		Vector<String> tableData = tableRows[i].split(',');

		if (tableData.getSize() != 2 || tableData[0].getLength() == 0 || tableData[1].getLength() == 0) {
			throw;//TODO
		}

		this->tableFiles.pushBack(TableFile{this->logger, tableData[0], tableData[1] });
	}

	return true;
}

void DBFile::showTables() const {
	for (unsigned int i = 0; i < this->tableFiles.getSize(); i++)
	{
		this->logger->log(String{ (i + 1) + "0" } +". " + this->tableFiles[i].getTableName());
	}
}

void DBFile::importTable(const String& fileName) {
}

void DBFile::exportTable(const String& tableName, const String& fileName) const {
	for (unsigned int i = 0; i < this->tableFiles.getSize(); i++)
	{
		if (tableFiles[i].getTableName() == tableName) {
			tableFiles[i].exportData(fileName);
		}
	}
}

void DBFile::describeTable(const String& tableName) const {
	for (unsigned int i = 0; i < this->tableFiles.getSize(); i++)
	{
		if (tableFiles[i].getTableName() == tableName) {
			tableFiles[i].describe();
		}
	}
}

void DBFile::printTable(const String& tableName) const {
	for (unsigned int i = 0; i < this->tableFiles.getSize(); i++)
	{
		if (tableFiles[i].getTableName() == tableName) {
			tableFiles[i].print();
		}
	}
}

void DBFile::renameTable(const String& tableName, const String& newName) {
	for (unsigned int i = 0; i < this->tableFiles.getSize(); i++)
	{
		if (tableFiles[i].getTableName() == tableName) {
			tableFiles[i].rename(newName);
		}
	}
}