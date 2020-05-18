#ifndef DBFILE_H
#define DBFILE_H

#include "../../include/File.h"
#include "TableFile.h"
#include "../../include/String.h"
#include "../../include/Vector.cpp"

class DBFile : public File {
	private:
		Vector<TableFile> tableFiles;

		TableFile& getTableWithName(const String&);
	public:
		DBFile(const ILogger* = nullptr, const String& = "");
		DBFile(const DBFile&);

		virtual bool open(const String&);

		void addColumnToTable(const Vector<String>&);
		void showTables();
		void importTable(const String&);
		void exportTable(const String&, const String&);
		void describeTable(const String&);
		void printTable(const String&);
		void renameTable(const String&, const String&);
};

#endif
