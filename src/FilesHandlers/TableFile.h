#ifndef TABLEFILE_H
#define TABLEFILE_H

#include "include/File.h"
#include "include/String.h"

class TableFile : public File {
	private:
		String tableName;

		String getColumnType(const unsigned int&) const;
		int getColumnIndex(const String&) const;
		bool doesMatchColumnType(const unsigned int&, const String&) const;
		Vector<unsigned int> getRowsIndexesByCriteria(const String&, const String&, bool = false) const;
		String concatData(const Vector<String>&);
	public:
		TableFile(ILogger* = nullptr, const String& = "", const String& = "", bool = false);
		TableFile(const TableFile&);

		virtual bool open(const String& = "");

		void describe();
		void print();
		void exportData(const String&);
		void rename(const String&);
		void addColumn(const String&, const String&);
		void insert(const Vector<String>&);
		void select(const String&, const String&);
		void update(const Vector<String>&);
		void count(const String&, const String&);
		void deleteRows(const String&, const String&);
		void aggregate(const Vector<String>&);

		static TableFile innerJoin(const TableFile&, const TableFile&, const String&, const String&);

		void setTableName(const String&);
		const Vector<String> getColumnNames(bool = false) const;
		const Vector<String> getTableData(const Vector<unsigned int>& = {}) const;
		String getTableName() const;
};

#endif