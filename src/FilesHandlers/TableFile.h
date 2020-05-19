#ifndef TABLEFILE_H
#define TABLEFILE_H

#include "../../include/File.h"
#include "../../include/String.h"

class TableFile : public File {
	private:
		String tableName;

		String getColumnType(const unsigned int&) const;
		int getColumnIndex(const String&) const;
		Vector<unsigned int> getRowsIndexesByCriteria(const String&, const String&);
	public:
		TableFile(const ILogger* = nullptr, const String& = "", const String& = "", bool = false);
		TableFile(const TableFile&);

		virtual bool open(const String& = "");

		void describe();
		void print();
		void exportData(const String&);
		void rename(const String&);
		void addColumn(const String&, const String&);
		void select(const String&, const String&);
		void update(const Vector<String>&);

		void setTableName(const String&);
		const Vector<String> getColumnNames(bool = false) const;
		const Vector<String> getTableData(const Vector<unsigned int>& = {}) const;
		const String& getTableName() const;
};

#endif