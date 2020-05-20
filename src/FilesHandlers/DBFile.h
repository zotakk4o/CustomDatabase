#ifndef DBFILE_H
#define DBFILE_H

#include "../../include/File.h"
#include "TableFile.h"
#include "../../include/String.h"
#include "../../include/Vector.cpp"

class DBFile : public File {
	private:
		Vector<TableFile> tableFiles;

		TableFile& getTableWithName(const String&, bool = true);
		virtual bool saveData(const String&);
	public:
		DBFile(const ILogger* = nullptr, const String& = "");
		DBFile(const DBFile&);

		virtual bool open(const String&);
		virtual bool close();
		void addColumnToTable(const Vector<String>&);
		void selectFromTable(const Vector<String>&);
		void countRowsFromTable(const Vector<String>&);
		void insertRow(const Vector<String>&);
		void updateTableEntry(const Vector<String>&);
		void showTables();
		void importTable(const String&);
		void exportTable(const String&, const String&);
		void describeTable(const String&);
		void printTable(const String&);
		void renameTable(const String&, const String&);
};

#endif
