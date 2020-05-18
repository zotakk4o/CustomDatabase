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

		void describe() const;
		void print() const;
		void exportData(const String&) const;
		void rename(const String&);
		void addColumn(const String&, const String&);

		void setTableName(const String&);
		String getTableName() const;
};

#endif