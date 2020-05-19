#ifndef TABLEFILE_H
#define TABLEFILE_H

#include "../../include/File.h"
#include "../../include/String.h"

class TableFile : public File {
	private:
		String tableName;
	public:
		TableFile(const ILogger* = nullptr, const String& = "", const String& = "", bool = false);
		TableFile(const TableFile&);

		virtual bool open(const String& = "");

		void describe();
		void print();
		void exportData(const String&);
		void rename(const String&);
		void addColumn(const String&, const String&);

		void setTableName(const String&);
		const Vector<String> getColumnNames(bool = false);
		const Vector<String> getTableData();
		String getTableName() const;
};

#endif