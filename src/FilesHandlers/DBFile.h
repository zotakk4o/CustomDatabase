#ifndef DBFILE_H
#define DBFILE_H

#include "../../include/File.h"
#include "TableFile.h"
#include "../../include/String.h"
#include "../../include/Vector.cpp"

class DBFile : public File {
	private:
		Vector<TableFile> tableFiles;
	public:
		DBFile(const ILogger* = nullptr, const String& = "");
		DBFile(const DBFile&);

		virtual bool open(const String&);

		void showTables() const;
		void importTable(const String&);
		void exportTable(const String&, const String&) const;
		void describeTable(const String&) const;
		void printTable(const String&) const;
		void renameTable(const String&, const String&);
};

#endif
